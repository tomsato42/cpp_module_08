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

    void push(const T &value) {
        m_stack.insert(m_stack.begin(),value);
        std::stack<T>::push(value);
    }

    void pop() {
        if (!m_stack.empty()) {
            m_stack.erase(m_stack.begin());
            std::stack<T>::pop();
        }
    }

    typedef typename std::vector<T>::iterator iterator;
    typedef typename std::vector<T>::const_iterator const_iterator;

    iterator begin() { return m_stack.begin(); }
    const_iterator begin() const { return m_stack.begin(); }
    iterator end() { return m_stack.end(); }
    const_iterator end() const { return m_stack.end(); }

private:
    std::vector<T> m_stack;
};

#endif // MUTANTSTACK_H
