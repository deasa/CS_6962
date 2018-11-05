#include<string>
#include<iostream>
#include "contact.h"

contact::contact(std::string first, std::string last, std::string phone, std::string email)
{
    this->firstName = first;
    this->lastName = last;
    this->phone = phone;
    this->email = email;
}

contact::contact()
{
}

contact::~contact()
{
}

