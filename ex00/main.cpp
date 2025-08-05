#include "easyfind.h"
#include <iostream>
#include <vector>
#include <list>
#include <map>

int main() {
    std::vector<int> vec(5);
    for (int i = 0; i < 5; i++) {
        vec[i] = i;
    }
    std::list<int> lst(0);
    for (int i = 0; i < 5; i++) {
        lst.push_back(i);
    }

    std::cout << "vec find 3:" << easyfind(vec, 3) << std::endl;
    std::cout << "vec find 5:" << easyfind(vec, 5) << std::endl; // should return -1
    std::cout << "lst find 3:" << easyfind(lst, 3) << std::endl;
    std::cout << "lst find 5:" << easyfind(lst, 5) << std::endl; // should return -1
}
