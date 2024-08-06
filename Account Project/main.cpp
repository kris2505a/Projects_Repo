#include <iostream>
#include "Methods.h"

int main(){


    int choice;

    do{
        std::cout << "1. Create " << std::endl;
        std::cout << "2. Deposit" << std::endl;
        std::cout << "3. withdraw" << std::endl;
        std::cout << "4. view Account" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << std::endl << "Enter your choice: ";
        std::cin >> choice;

        switch(choice){
            case 1:
                Methods::createAccount();
            break;

            case 2:
                Methods::deposit();
            break;

            case 3:
                Methods::withDraw();
            break;

            case 4:
                Methods::display();
            break;

            case 5:
                break;

            default:
                std::cout << "Invalid Input!" << std::endl;
        }
    }
    while(choice != 5);
}
