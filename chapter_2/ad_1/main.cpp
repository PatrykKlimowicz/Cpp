#include <iostream>
#include <vector>
#include <algorithm>


int main(void) {
    std::vector<int> v{1, 2, 3, 2, 5, 2, 6, 2, 4, 8};
    
    /* 
     * After this operation v{1, 3, 5, 6, 4, 8, 6, *2*, 4, 8}
     * this special two - *2* - is our new_end
     */
    const auto new_end (std::remove(std::begin(v), std::end(v), 2));
    /*
     * This operation will delete unwanted elements pernamently
     */
    v.erase(new_end, std::end(v));

    for (const auto &i : v) {
        std::cout << i << ", ";
    }
    std::cout << "\n";

    const auto odd ([](int i) { return i % 2 != 0; });
    v.erase(std::remove_if(std::begin(v), std::end(v), odd), std::end(v));
    /*
     * Use the minimum of memory for our needs
     */
    v.shrink_to_fit();

    for (const auto &i : v) {
        std::cout << i << ", ";
    }
    std::cout << "\n";

    return 0;
}
