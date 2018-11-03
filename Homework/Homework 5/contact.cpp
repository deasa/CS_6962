#include<string>
#include<map>
#include<contact.h>

std::map<std::string, contact> contactsMap;

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

contact::operator<<(contact &c)
{
    std::cout << "Name: " << c.firstName << " " << c.lastName << "\n";
    std::cout << "Phone Number: " << c.phone << "\n";
    std::cout << "E-mail: " << c.email << "\n";
}

void list()
{
    if (contactsMap.size() == 0) {
        std::cout << "no contacts \n";
        return;
    }
    
    for(auto &it : contactsMap)
    {
        std::cout << it.second().lastName << ", " << it.second().firstName "\n";
    }
    //loop through contacts map and print all
}

void add(std::string first, std::string last, std::string phone, std::string email)
{
    contactsMap[first + last] = contact(first, last, phone, email);
}

void remove(std::string first, std::string last)
{
    std::map<std::string, contact>::iterator it;

    it = contactsMap.find(first, last);
    if (it != contactsMap.end()) {
        contactsMap.erase(it);
        std::cout << "removed " << first << " " << last;
    }
    
}

void find(std::string first, std::string last)
{
    std::map<std::string, contact>::iterator it;

    it = contactsMap.find(first, last);
    if (it != contactsMap.end()){
        std::cout << it.second();
    }
    
    else
    {
        std::cout << "contact not found \n";
    }
    
}