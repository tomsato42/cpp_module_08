#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

#include <vector>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T> {
public:
    MutantStack() {
    };

    ~MutantStack() {
    };

    MutantStack(const MutantStack &other) {
        this->operator=(other);
    };

    MutantStack &operator=(const MutantStack &other) {
        if (this != &other) {
            std::stack<T>::operator=(other);
        }
        return *this;
    };

    typedef typename std::stack<T>::container_type container_type;

    typedef typename container_type::iterator iterator;
    typedef typename container_type::const_iterator const_iterator;

    iterator begin() { return this->c.begin(); }
    const_iterator begin() const { return this->c.begin(); }
    iterator end() { return this->c.end(); }
    const_iterator end() const { return this->c.end(); }

private:
};

#endif // MUTANTSTACK_H
