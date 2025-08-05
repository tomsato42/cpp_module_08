#ifndef EASYFIND_H
#define EASYFIND_H
#include <algorithm>

template<typename T>
int easyfind(T & container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        return -1;
    }
    return std::distance(container.begin(), it);
}
#endif // EASYFIND_H
