#include <iostream>
#include "deque.h"

using std::cout, std::cin, std::endl;

int main()
{
    auto test = deque<int>();
    test.push_back(2);
    cout << test.getSize() << endl;
    test.push_back(3);
    test.push_back(4);
    test.push_front(2);
    for (auto i = test.begin(); i != test.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
    test.push_front(1);
    test.push_front(0);
    test.push_front(-1);
    test.push_front(-2);
    for (auto i = test.begin(); i != test.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
    test.pop_back();
    test.pop_back();
    test.pop_back();
    test.pop_back();
    test.pop_front();
    for (auto i = test.rbegin(); i != test.rend(); i--)
    {
        cout << *i << " ";
    }
    cout << endl;
    return 0;
}
