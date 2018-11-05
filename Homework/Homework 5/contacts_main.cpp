#include "contact.h"
#include<iostream>
#include<string>
#include<map>

std::map<std::string, contact> contactsMap;

std::ostream& operator<<(std::ostream& stream, contact &c)
{
	stream << "Name: " << c.firstName << " " << c.lastName << "\n";
	stream << "Phone Number: " << c.phone << "\n";
	stream << "E-mail: " << c.email << "\n";
	return stream;
}

std::istream& operator>>(std::istream& stream, contact &c)
{
	std::cout << "first name: ";
	stream >> c.firstName;
	std::cout << "last name: ";
	stream >> c.lastName;
	std::cout << "phone number: ";
	stream >> c.phone;
	std::cout << "e-mail: ";
	stream >> c.email;
	return stream;
}

void list()
{
	if (contactsMap.size() == 0) {
		std::cout << "no contacts \n";
		return;
	}

	for (auto &it : contactsMap)
	{
		std::cout << it.second.lastName << ", " << it.second.firstName << "\n";
	}
	//loop through contacts map and print all
}

void add(std::string first, std::string last, std::string phone, std::string email)
{
	contactsMap[first + last] = contact(first, last, phone, email);
}

void add(contact c)
{
	contactsMap[c.firstName + c.lastName] = c;
}

void remove(std::string first, std::string last)
{
	std::map<std::string, contact>::iterator it;

	it = contactsMap.find(first + last);
	if (it != contactsMap.end()) {
		contactsMap.erase(it);
		std::cout << "removed " << first << " " << last << "\n";
		return;
	}
	else
	{
		"contact not found \n";
	}

}

void find(std::string first, std::string last)
{
	std::map<std::string, contact>::iterator it;

	it = contactsMap.find(first + last);
	if (it != contactsMap.end()) {
		std::cout << it->second;
	}

	else
	{
		std::cout << "contact not found \n";
	}

}

std::string getEmail()
{
    std::cout << "e-mail: ";
	std::string r;
	std::cin >> r;
    return r;
}

std::string getPhoneNumber()
{
    std::cout << "phone number: ";
	std::string r;
	std::cin >> r;
	return r;
}

std::string getLastName()
{
    std::cout << "last name: ";
	std::string r;
	std::cin >> r;
	return r;
}

std::string getFirstName()
{
    std::cout << "first name: ";
	std::string r;
	std::cin >> r;
	return r;
}

int main()
{
    std::string cmd;
    do {
        if (cmd == "exit"){
            break;
        } 
        else if (cmd == "list"){
            list();
            // List contacts in the manager
        } 
        else if (cmd == "add"){
			contact c;
			std::cin >> c;
			add(c);
            // Add a contact to the manager
        } 
        else if (cmd == "remove"){
			std::string f, l;
			f = getFirstName();
			l = getLastName();
			remove(f, l);
            // Remove a contact from the manager
        } 
        else if (cmd == "find"){
			std::string f, l;
			f = getFirstName();
			l = getLastName();
            find(f, l);
            // Find a contact in the manager
        }
        // Print a terminal prompt so the user knows // we're waiting for their input
        std::cout << "> ";
    } 
    while (std::cin >> cmd);

    return 0; 
}