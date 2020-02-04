#include <iostream>
#include <vector>

int main() {
    const size_t container_size {1000};
    std::vector<int> v (container_size, 123);

    try {
        std::cout << "Out of range element value: " << v[container_size + 10] << '\n';
    } catch (const std::out_of_range &e) {
        std::cout << "Ops, out of range: " << e.what() << "\n";
    }

    return 0;
}
