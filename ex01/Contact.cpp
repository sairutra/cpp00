#include "Contact.hpp"
#include "Utils.hpp"

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
	while (!getAbortProgram() && input.empty())
	{
		getline(std::cin, input);
		if (cinFail() || cinEofFail())
		{
			setAbortProgram(true);
			return (input);
		}
		if (input.empty())
			printEmptyPrompt(prompt);
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

void Contact::setAbortProgram(bool value)
{
	abortProgram = value;
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

bool Contact::getAbortProgram()
{
	return (abortProgram);
}

Contact::Contact(void)
{
	abortProgram = false;
}

Contact::~Contact(void)
{
}