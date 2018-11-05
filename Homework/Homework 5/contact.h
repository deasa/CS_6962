#ifndef CONTACT_H
#define CONTACT_H
#include<string>

class contact
{
private:
public:
	std::string lastName;
	std::string firstName;
	std::string phone;
	std::string email;
    contact(std::string first, std::string last, std::string phone, std::string email);
    contact();
    ~contact();
};

#endif
