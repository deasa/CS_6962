#include<contact.cpp>
#include<string>

std::string getEmail()
{
    std::cout << "e-mail: ";
    return std::cin;
}

std::string getPhoneNumber()
{
    std::cout << "phone number: ";
    return std::cin;
}

std::string getLastName()
{
    std::cout << "last name: ";
    return std::cin;
}

std::string getFirstName()
{
    std::cout << "first name: ";
    return std::cin;
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
            add(getFirstName(), getLastName(), getPhoneNumber(), getEmail())
            // Add a contact to the manager
        } 
        else if (cmd == "remove"){
            remove(getFirstName(), getLastName())
            // Remove a contact from the manager
        } 
        else if (cmd == "find"){
            find(getFirstName(), getLastName());
            // Find a contact in the manager
        }
        // Print a terminal prompt so the user knows // we're waiting for their input
        std::cout << "> ";
    } 
    while (std::cin >> cmd);

    return 0; 
}