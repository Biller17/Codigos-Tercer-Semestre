/*
   Gilberto Echeverria

   Test of the Double Linked List data structure
*/

#include <iostream>
#include "DoubleLinkedList.h"

// Function prototypes
void user_menu();

int main()
{
    std::cout << "TEST OF DOUBLE LISTS" << std::endl;
    user_menu();

    return 0;
}

void user_menu()
{
    char option = 'a';
    int value;
    bool found;
    DoubleLinkedList<int> double_list;

    while (option != 'q')
    {
        std::cout << "Main menu:" << std::endl;
        std::cout << "\ta. Insert item" << std::endl;
        std::cout << "\tb. Search for item" << std::endl;
        std::cout << "\tc. Print list" << std::endl;
        std::cout << "\td. Print current item" << std::endl;
        std::cout << "\tq. Quit the program" << std::endl;
        std::cout << "Select an option: ";
        std::cin >> option;

        if (option == 'a')
        {
            std::cout << "Enter value to insert: ";
            std::cin >> value;
            double_list.insertOrdered(value);
        }
        else if (option == 'b')
        {
            found = false;
            std::cout << "Enter value to search for: ";
            std::cin >> value;
            found = double_list.searchFor(value);
            if (found)
            {
                std::cout << "Item found in the list" << std::endl;
            }
            else
            {
                std::cout << "No such item in the list" << std::endl;
            }
        }
        else if (option == 'c')
        {
            double_list.printList();
        }
        else if (option == 'd')
        {
            std::cout << double_list.getCurrent()->getData() << std::endl;
        }
        else if (option == 'q')
        {
            std::cout << "Good bye!" << std::endl;
        }
        else
        {
            std::cout << "Invalid option. Try again ..." << std::endl;
        }
    }
}
