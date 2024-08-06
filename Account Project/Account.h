//
// Created by krrri on 8/6/2024.
//

#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>

struct DOB{
    int dd, mm, yy;
    std::string printDateOfBirth() const;
};

struct Address{
    std::string buildingNumber, street, city, state;
    int pincode;
    std::string printAddress() const;
};



class Account {
    friend std::ostream &operator << (std::ostream &ostr, Account &source);

private:
    std::string name;
    std::string signature;
    DOB dateOfBirth;
    Address address;
    char gender;
    int age;
    int pin;
    int mobile;

protected:
    double balance{0.f};

public:
    int accountNumber;
    bool isBlocked {false};
    bool deposit(double &amount);
    bool withdraw(double &amount);
    void setData(
        std::string &name_var,
        DOB &dob_var,
        Address &address_var,
        char &gender_var,
        int &age_var,
        int &mobile_var,
        int &accNum_var,
        double &balance_var,
        int &pin_var,
        std::string &signature_var
    );
    bool verifyPin(int &usrPin) const;
};



#endif //ACCOUNT_H
