#include <iostream>
#include <utility>
#include <vector>

#define ERROR 1
#define SUCCESS 0

/*
 * Let's assume that T is
 * std::vector<U>. We want to add U x to every element
 * in _val. Otherwise simple addition will do the work.
 */
template <typename T>
class addable {
private:
    T _val;
public:
    addable(T val): _val{val} {}
    template <typename U>
    T add(U x) {
		/* 
		 * This condition will be check only in compile time.
		 * If false it's block of code will not be produced.
		 * std::is_same<A, B>::value = std::is_same_v<A, B>
		 * Above instruction is true when A and B are same type
		 */
        if constexpr (std::is_same_v<T, std::vector<U>>) {
			auto copy (_val);
			for (auto &n : copy) {
				n += x;
			}
			return copy;
		} else {
			return _val + x;
		}
	}
};

/*
 * Before C++17 above class 
 * will look as follows:
 */
template <typename T>
class addable_old {
private:
	T _val;
public:
	addable_old(T val) : _val{val} {}

template <typename U>
	std::enable_if_t<!std::is_same<T, std::vector<U>>::value, T>
	add(U x) const {
		return _val + x;
	}
template <typename U>
	std::enable_if_t<std::is_same<T, std::vector<U>>::value, std::vector<U>>
	add(U x) const {
		auto copy (_val);
		for (auto &n : copy)
			n += x;
		
		return copy;
	}
};

/*
 * Above code works becasue of SFINAE (substitution failure is not an error)
 * std::enable_if<condition, type_A> if condition is true expression is of type type_A
 * Compiler will generate only one function according to what we need
 */

/* Helper function */
template <typename T>
void print_vec_el(const std::vector<T> &e) {
	for (const auto &el : e)
		std::cout << el << "\t";
}

int main(void) {
    std::cout << addable<int>{1}.add(2) << "\n";
	std::cout << addable<float>{1.0}.add(2) << "\n";
	std::cout << addable<std::string>{"Pat"}.add("ryk") << "\n";

	std::vector<int> v {1, 2, 3};
	auto res = addable<std::vector<int>>{v}.add(10);
	print_vec_el(res);

	std::vector<std::string> sv {"a", "b", "c"};
	auto res2 = addable<std::vector<std::string>>{sv}.add(std::string{"z"});
	print_vec_el(res2);

	return SUCCESS;
}
