#include<string>

class contact
{
private:
    std::string lastName;
    std::string firstName;
    std::string phone;
    std::string email;
public:
    contact(std::string first, std::string last, std::string phone, std::string email);
    contact();
    ~contact();
    operator<<(contact &c);
};


