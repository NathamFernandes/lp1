#include <iostream>

int main () {
    void* test = (char*) 'a';
    std::cout << test;

    std::cin >> test;

    std::cout << test;

    return 0;
}