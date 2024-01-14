#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <cmath>
#include <iomanip>

#include "User.h"

template <typename T>
void ContainerInit(T& cont, int size)
{
    /*for (int i{}; i < size; i++)
        cont.push_back(rand() % 100);*/
    cont.resize(size);
    int n = 1;
    std::generate(cont.begin(), cont.end(), [&n]()
        {
            //return rand() % 100;
            return ++n * n;
        });
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
void ContainerPrintPtr(T cont)
{
    std::for_each(cont.begin(), cont.end(), [](auto item)
        {
            std::cout << *item << "\n";
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

void IntAlgorithm()
{
    std::vector<int> v;
    ContainerInit(v, 10);
    std::cout << "Vector:\n";
    ContainerPrint(v);

    /*std::list<int> lst;
    ContainerInit(lst, 10);
    std::cout << "List:\n";
    ContainerPrintN(lst, lst.size());*/

    auto allOf = std::all_of(v.begin(), v.end(), [](auto item)
        {
            //return item > 0;
            return item % 2 == 0;
        });
    std::cout << std::boolalpha << allOf << "\n";

    auto anyOf = std::any_of(v.begin(), v.end(), [](auto item)
        {
            //return item > 0;
            return item % 2 == 0;
        });
    std::cout << std::boolalpha << anyOf << "\n";

    auto noneOf = std::none_of(v.begin(), v.end(), [](auto item)
        {
            return item < 0;
            //return item % 2 == 0;
        });
    std::cout << std::boolalpha << noneOf << "\n";

    std::cout << "Input key: ";
    int key;
    std::cin >> key;

    auto itFind = std::find(v.begin(), v.end(), key);
    if (itFind != v.end())
        std::cout << *itFind << "\n";
    else
        std::cout << "Not found\n";

    auto itFindIf = std::find_if(v.begin(), v.end(), [](auto item)
        {
            return item % 2 == 0;
        });
    if (itFindIf != v.end())
        std::cout << *itFindIf << "\n";
    else
        std::cout << "Not found\n";

    auto itFindIfNot = std::find_if_not(v.begin(), v.end(), [](auto item)
        {
            return item % 2 == 0;
        });
    if (itFindIfNot != v.end())
        std::cout << *itFindIfNot << "\n";
    else
        std::cout << "Not found\n";

    std::vector<int> v1{ 1, 2, 3, 4, 5 };
    std::vector<int> v2{ 7, 8, 4, 9, 5 };

    auto itFindFirstOf = std::find_first_of(v1.begin(), v1.end(),
        v2.begin(), v2.end());
    std::cout << *itFindFirstOf << "\n";

    std::cout << std::count_if(v.begin(), v.end(), [](auto item)
        {
            return item % 2 == 0;
        }) << "\n";

    /*std::copy_if(v1.begin(), v1.end(), v.begin() + 2, [](auto item)
        {
            return item & 1;
        });*/
    std::move(v1.begin(), v1.end(), v.begin() + 2);
    ContainerPrint(v);
    ContainerPrint(v1);

    std::transform(v1.begin(), v1.end(), v2.begin(), [](auto item)
        {
            return item * item;
        });
    ContainerPrint(v1);
    ContainerPrint(v2);
}

void UserAlgorithm()
{
    std::vector<User*> users;
    users.push_back(new User("Leo", 38));
    users.push_back(new User("Jim", 19));
    users.push_back(new User("Tom", 26));
    users.push_back(new User("Bob", 32));
    users.push_back(new User("Kim", 21));
    users.push_back(new User("Sam", 45));
    users.push_back(new User("Joe", 29));

    ContainerPrintPtr(users);

    auto allOf = std::all_of(users.begin(), users.end(), [](User* item)
        {
            return item->Age() > 20;
        });
    std::cout << std::boolalpha << allOf << "\n";

    /*auto find = std::find(users.begin(), users.end(), users.begin() + 3);
    if (find != users.end())
        std::cout << std::boolalpha << *find << "\n";
    else
        std::cout << "Not found\n";*/

    auto findIf = std::find_if(users.begin(), users.end(), [](User* item) 
        {
            //return item->Name() == "Tom";
            return item->Age() > 40;
        });
    if (findIf != users.end())
        std::cout << **findIf << "\n";
    else
        std::cout << "Not found\n";
}

int main()
{
    srand(time(nullptr));

    IntAlgorithm();
    //UserAlgorithm();
}
