#include <iostream>
#include "arrayClass.hpp"

int main()
{
    int size = 5;
    array a(size);
    a[3] = 2;
    for (int i = 0; i < size; i++) {
        std::cout << a[i] <<" ";
    }
    std::cout << std::endl;
    int k = 10;
    a.resize(k);
    for (int i = 0; i < k; i++) {
        std::cout << a[i] <<" ";
    }
    std::cout << std::endl;
    array b(size);
    if (a == b) {
        std::cout << "true" <<std::endl;
    } else {
        std::cout << "false" << std::endl;
        }
a.print_array();
a.insert(3,5,4);
std::cout << "insert :" << std::endl;
a.print_array();
a.erase(3);
std::cout << "Call erase :" << std::endl;
a.print_array();
a.pop_back();
std::cout << "Call pop_back :" << std::endl;
a.print_array();
a.push_back(23);
std::cout << "Call push_backc :" << std::endl;
a.print_array();
}
