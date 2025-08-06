#include <iostream>
#include <list>

#include "MutantStack.h"
#include <stack>

int main()
{
    {
        MutantStack<int> mstack;
        mstack.push(5); // 5
        mstack.push(17); // 5, 17
        std::cout << mstack.top() << std::endl;
        mstack.pop(); // 5
        std::cout << mstack.size() << std::endl;
        mstack.push(3); // 5, 3
        mstack.push(5); // 5, 3, 5
        mstack.push(737); // 5, 3, 5, 737
        //[...]
        mstack.push(0); // 5, 3, 5, 737, 0
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        std::cout << "MutantStack contents:" << std::endl;
        while (it != ite) {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }
    std::cout << "-----------------------------------------" << std::endl;
    {
        std::list<int> mstack;
        mstack.push_back(5); // 5
        mstack.push_back(17); // 5, 17
        std::cout << mstack.back() << std::endl;
        mstack.pop_back(); // 5
        std::cout << mstack.size() << std::endl;
        mstack.push_back(3); // 5, 3
        mstack.push_back(5); // 5, 3, 5
        mstack.push_back(737); // 5, 3, 5, 737
        //[...]
        mstack.push_back(0); // 5, 3, 5, 737, 0
        std::list<int>::reverse_iterator it = mstack.rbegin();
        std::list<int>::reverse_iterator ite = mstack.rend();
        ++it;
        --it;
        std::cout << "MutantStack contents:" << std::endl;
        while (it != ite) {
            std::cout << *it << std::endl;
            ++it;
        }
    }
    std::cout << "-----------------------------------------" << std::endl;
    return 0;
}
