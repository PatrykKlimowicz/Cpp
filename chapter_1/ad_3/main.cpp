#include <iostream>
#include <vector>

#define ERROR 1
#define SUCCESS 0

int main(void) {
    /*
     * Using eplicit type during declaration 
     */
    int x1 = 1; // x1 equal to 1
    int x2 (1); // x2 equal to 1
    int x3 {1}; // x3 equal to 1
    std::vector<int> v1 {1, 2, 3}; // vector of three elements 
    std::vector<int> v2 = {1, 2, 3}; // same as above
    std::vector<int> v3 (11, 2); // vector of 11 elemets each equal to 2, 

    /*
     * Using auto during declaration 
     */
    auto v {1}; // v is integer, in C++11 it was std::initializer_list<int>
    // auto w {1, 2}; // error, during direct initialization only one element is legal
    auto x = {1}; // x is std::initializer_list<int>
    auto y = {1, 2}; // same as above
    // auto z = {1, 2, 3.0}; // auto error, cannot define type of element z

    return SUCCESS;
}