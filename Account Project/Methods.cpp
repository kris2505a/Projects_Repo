//
// Created by krrri on 8/6/2024.
//

#include "Methods.h"

#include "Account.h"
#include "Methods.h"
#include <iostream>
#include <memory>


#include "Accounts.h"


void Methods::createAccount(){
    //account variables
    std::string name, signature;
    DOB dateOfBirth{};
    Address address;
    char gender;
    int age, pin;
    int mobile_num;
    int accountNumber;
    double amount;

    std::cout << "Name: ";
    std::cin >> name;
    std::cout << "Date of Birth: " << std::endl;
    std::cout << "    Date: ";
    std::cin >> dateOfBirth.dd;
    std::cout << "    Month: ";
    std::cin >> dateOfBirth.mm;
    std::cout << "    Year: ";
    std::cin >> dateOfBirth.yy;
    std::cout << "Age: ";
    std::cin >> age;
    std::cout << "Gender (m/f): ";
    std::cin >> gender;
    std::cout << "Address: " << std::endl;
    std::cout << "    Building Number: ";
    std::cin >> address.buildingNumber;
    std::cout << "    Street: ";
    std::cin >> address.street;
    std::cout << "    City: ";
    std::cin >> address.city;
    std::cout << "    State: ";
    std::cin >> address.state;
    std::cout << "    Pincode: ";
    std::cin >> address.pincode;
    std::cout << "Mobile: ";
    std::cin >> mobile_num;
    std::cout << "Enter Account Number: ";
    std::cin >> accountNumber;
    std::cout << "Account Pin: ";
    std::cin >> pin;
    std::cout << "Inital Deposit: ";
    std::cin >> amount;
    std::cout << "Signature: ";
    std::cin >> signature;

    //std::unique_ptr<Account> tmp = std::make_unique<>();
    auto *tmp = new Account();
    tmp->setData(name, dateOfBirth, address, gender, age, mobile_num,
        accountNumber, amount, pin, signature);
    AccountList.push_back(tmp);
}

void Methods::display() {
    int accNum;
    std::cout << "Enter Account Number: ";
    std::cin >> accNum;
    Account *current {nullptr};
    for(auto *acc : AccountList){
        if(acc->accountNumber == accNum){
            current = acc;
            break;
        }
    }
    if(current == nullptr){
        std::cout << "Account Not Found!" << std::endl;
        return;
    }
    int usrPin;
    std::cout << "Enter pin: ";
    std::cin >> usrPin;
    if(current->verifyPin(usrPin)){
        std::cout << std::endl << std::endl;
        std::cout << "----------------------------------------------------------" << std::endl;
        std::cout << *current << std::endl;
    }

    else
        std::cout << "Wrong Pin! Try again." << std::endl;

    current = nullptr;
}


void Methods::deposit() {
    double amount;
    int accNum;
    std::cout << "Enter Account Number: ";
    std::cin >> accNum;
    Account *current = nullptr;
    for(auto *acc : AccountList) {
        if(acc->accountNumber == accNum) {
            current = acc;
            break;
        }
    }
    if(current == nullptr) {
        std::cout << "Account Not Found!" << std::endl;
        return;
    }

    std::cout << "Enter the amount to deposit: ";
    std::cin >> amount;
    if(current->deposit(amount))
        std::cout << "Deposited successfully!" << std::endl;
    else
        std::cout << "Deposit Failed!" << std::endl;
    current = nullptr;

}

void Methods::withDraw() {
    int accNum;
    std::cout << "Enter Account Number: ";
    std::cin >> accNum;
    Account *current {nullptr};
    for(auto *acc : AccountList){
        if(acc->accountNumber == accNum){
            current = acc;
            break;
        }
    }
    if(current == nullptr){
        std::cout << "Account Not Found!" << std::endl;
        return;
    }
    int usrPin;
    std::cout << "Enter pin: ";
    std::cin >> usrPin;
    if(!current->verifyPin(usrPin)) {
        std::cout << "Wrong Pin" << std::endl;
        return;
    }
    else {
        double amount;
        std::cout << "Enter the amount to withdraw: ";
        std::cin >> amount;
        if(current->withdraw(amount)) {
            std::cout << "Withdraw Successful! " << std::endl;
        }
        else {
            std::cout << "Insufficient Balance!" << std::endl;
        }
    }
}

