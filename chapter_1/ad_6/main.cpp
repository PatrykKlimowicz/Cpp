#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <set>

#define ERROR 1
#define SUCCESS 0

template <typename T>
void print_vec_el(const std::vector<T> &e) {
	for (const auto &el : e)
		std::cout << el << "\t";
    std::cout << "\n";
}

template <typename ... Ts>
auto sum(Ts ... ts) {
    /*
     * below is right fold, expands to (((1 + 2) + 3) + 4) + 5
     * in case of left fold it looks like: 1 + (2 + (3 + (4 + 5)))
     */
    return (ts + ...);
}

template <typename ... Ts>
auto sum_2(Ts ... ts) {
    /*
     * below is right fold with initial value
     * it is called BINARY FOLDS
     */
    return (ts + ... + 0);
}

/*
 * Helper function which tells whether some range
 * contains at least one element we provided
 */
template <typename T, typename ... Ts>
auto matches(const T& range, Ts ... ts) {
    return (std::count(std::begin(range), std::end(range), ts) + ...);
}

/*
 * Insert an arbitrary number into a std::set
 */
template <typename T, typename ... Ts>
bool insert_all(T &set, Ts ... ts) {
    return (set.insert(ts).second && ...);
}

/*
 * Check if all parameters are within range
 */
template <typename T, typename ... Ts>
bool within(T min, T max, Ts ... ts) {
    return ((min <= ts && ts <= max) && ...);
}

/*
 * Add multiple elements to vector
 */
template <typename T, typename ... Ts>
void push_all(std::vector<T> &v, Ts ... ts) {
    (v.push_back(ts), ...);
}

int main(void) {
    std::cout << "Sum of 1, 2, 3, 4, 5, 6: " << sum(1, 2, 3, 4, 5, 6) << "\n";
    std::cout << "string Pat, ryk, , Klim, owicz gives: " << 
                 sum(std::string{"Pat"}, std::string{"ryk"}, std::string{" "},
                     std::string{"Klim"}, std::string{"owicz"})
              << "\n";

    std::cout << "Right binary fold without parameters: " << sum_2() << "\n";

    std::vector v {1, 2, 3, 4, 5};
    std::cout << matches(v, 1, 2, 3) << "\n";
    std::cout << matches(v, 10, 20, 3) << "\n";
    std::cout << matches("asdcgsagthv", 'a', 'f', 't') << "\n";

    if (std::set<int> s{1, 2, 3, 4}; insert_all(s, 0, 6, 7, 8))
        std::cout << "Insertion succeed!\n";
    
    if (std::set<int> s{1, 2, 3, 4}; insert_all(s, 1, 6, 7, 8))
        std::cout << "Insertion succeed!\n";
    else
        std::cout << "Insertion failed!\n";
    
    std::cout << within(10, 20, 1, 15, 30) << "\n"; // --> false
    std::cout << within(5.0, 5.5, 5.1, 5.2, 5.3) << "\n";// --> true

    print_vec_el(v);
    push_all(v, 123, 124, 125, 126);
    print_vec_el(v);

    return SUCCESS;
}
