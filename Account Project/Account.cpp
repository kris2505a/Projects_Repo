#include "Account.h"
#include <iostream>

//constructor
void Account::setData(std::string &name_var, DOB &dob_var, Address &address_var, char &gender_var, int &age_var,
  int &mobile_var, int &accNum_var, double &balance_var, int &pin_var, std::string &signature_var) {
    name = name_var;
    dateOfBirth = dob_var;
    address = address_var;
    gender = gender_var;
    age = age_var;
    mobile = mobile_var;
    accountNumber = accNum_var;
    balance = balance_var;
    pin = pin_var;
    signature = signature_var;
}




bool Account::deposit(double &amount){
    if(isBlocked)
        return false;
    balance += amount;
    return true;
}

bool Account::withdraw(double &amount){
    if(isBlocked)
        return false;
    if(amount > balance)
        return false;
    balance -= amount;
    return true;
}

std::ostream &operator << (std::ostream &ostr, Account &source){
    ostr << "Name: " << source.name << std::endl;
    ostr << "Address: " << source.address.printAddress() << std::endl;
    ostr << "Date of Birth: " << source.dateOfBirth.printDateOfBirth() << std::endl;
    ostr << "Gender " << source.gender << std::endl;
    ostr << "Mobile: " << source.mobile << std::endl;
    ostr << "Account Number: " << source.accountNumber << std::endl;
    ostr << "Balance: " << source.balance;
    return ostr;
}

std::string DOB::printDateOfBirth() const{
    return (std::to_string(dd) + "-" + std::to_string(mm) + "-" + std::to_string(yy));
}

std::string Address::printAddress() const{
    std::string addr;
    addr = (buildingNumber + ", " + street + ",\n" + city + ", " + state + ",\n" + std::to_string(pincode));
    return addr;
}

bool Account::verifyPin(int &usrPin) const{
    return usrPin == this->pin;
}