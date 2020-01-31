#include <iostream>
#include <utility>
#include <tuple>

#define ERROR 1
#define SUCCESS 0

template <typename T1, typename T2, typename T3>
class my_wrapper {
public:
    T1 _t1;
    T2 _t2;
    T3 _t3;
    my_wrapper(T1 t1, T2 t2, T3 t3)
        :_t1(t1), _t2(t2), _t3(t3)
    {}
};

/* This function enables using new approach before C++17 */
template <typename T1, typename T2, typename T3>
my_wrapper<T1, T2, T3> make_wrapper(T1 t1, T2 t2, T3 t3) {
    return {t1, t2, t3};
}

int main(void) {
    /* constructor can automatically define type */
    std::pair my_pair (123, "asd");
    std::tuple my_tuple (123, 12.3, "asd");

    /* Old way of creating object of class my_wrapper */
    my_wrapper<int, const char*, double> wrapper {1, "asd", 23.4};

    /* New way of creating object of class my_wrapper */
    my_wrapper wrapper1 {1, "asd", 23.4};

    /* Using helper function to achieve similar behaviour as above before C++17 */
    auto wrapper2 (make_wrapper(1, "asd", 23.4));
    std::cout << "Old as new: " << wrapper2._t1 << " " << wrapper2._t2 << " " << wrapper2._t3 << "\n";

    return SUCCESS;
}
