#include "Contact.hpp"

void printPrompt(std::string &prompt)
{
	std::cout << "Please fill in " + prompt + ": ";
}
void printEmptyPrompt(std::string &prompt)
{
	std::cout << "No empty fields allowed, please provide " + prompt + ": ";
}

std::string Contact::getInput(std::string prompt)
{
	std::string input;

	printPrompt(prompt);
	getline(std::cin, input);
	// add get cin error handeling
	while (input.empty())
	{
		printEmptyPrompt(prompt);
		getline(std::cin, input);
		// add get cin error handeling
	}
	return (input);
}

void Contact::setFirstName()
{
	firstName = getInput("first name");
}
void Contact::setLastName()
{

	lastName = getInput("last name");
}
void Contact::setNickName()
{

	nickName = getInput("nick name");
}
void Contact::setPhoneNumber()
{

	phoneNumber = getInput("phone number");
}
void Contact::setDarkestSecret()
{

	darkestSecret = getInput("darkest secret");
}

std::string Contact::getFirstName()
{
	return (firstName);
}
std::string Contact::getLastName()
{
	return (lastName);
}
std::string Contact::getNickName()
{
	return (nickName);
}
std::string Contact::getPhoneNumber()
{
	return (phoneNumber);
}
std::string Contact::getDarkestSecret()
{
	return (darkestSecret);
}

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}