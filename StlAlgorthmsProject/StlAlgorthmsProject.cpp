#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>

template <typename T>
void ContainerInit(T& cont, int size)
{
    for (int i{}; i < size; i++)
        cont.push_back(rand() % 100);
}

template <typename T>
void ContainerPrint(T cont)
{
    std::for_each(cont.begin(), cont.end(), [](auto item)
        {
            std::cout << item << " ";
        });
    std::cout << "\n";
}

template <typename T>
void ContainerPrintN(T cont, int count)
{
    std::for_each_n(cont.begin(), count, [](auto item)
        {
            std::cout << item << " ";
        });
    std::cout << "\n";
}

int main()
{
    srand(time(nullptr));

    std::vector<int> v;
    ContainerInit(v, 10);
    ContainerPrint(v);

    std::list<int> lst;
    ContainerInit(lst, 10);
    ContainerPrintN(lst, 5);
}
