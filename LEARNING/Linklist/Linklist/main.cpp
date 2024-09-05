#include <iostream>
#include "IteratorBase.h"
#include "Linklist.h"
#include "Item.h"

int main() {
    Item item1("one");
    Item item2("two");
    Item item3("three");
    Item item4("four");
    Item item5("five");
    Item item6("six");

    Linklist<Item> list;
    list.push_back(item1);
    list.push_back(item2);
    list.push_back(item3);
    list.push_back(item4);
    list.push_back(item5);
    list.push_back(item6);

    IteratorBase<Item>* it = list.createIterator();

    while (it->hasNext()) {
        std::cout << "value: " << it->next().getName() << "\n";
    }

    std::cout << "\n";

    DoubleLinklist<Item> doubleLinklist;
    doubleLinklist.push_back(item1);
    doubleLinklist.push_back(item2);
    doubleLinklist.push_back(item3);
    doubleLinklist.push_back(item4);
    doubleLinklist.push_back(item5);
    doubleLinklist.push_back(item6);

    IteratorBase<Item>* it2 = doubleLinklist.createIterator();

    while (it2->hasPrev()) {
        std::cout << "value: " << it2->prev().getName() << "\n";
    }
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
