#include "Contact.hpp"
#include "Utils.hpp"

void printPrompt(std::string &prompt)
{
	std::cout.width(inputColumnWidth); std::cout << std::left << prompt; 
	std::cout << inputSeperator; 
}
void printEmptyPrompt(std::string &prompt)
{
	std::cout << emptyFieldMessage << std::endl;
	printPrompt(prompt);
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
	firstName = getInput(firstNameColumn);
}
void Contact::setLastName()
{

	lastName = getInput(lastNameColumn);
}
void Contact::setNickName()
{

	nickName = getInput(nickNameColumn);
}
void Contact::setPhoneNumber()
{

	phoneNumber = getInput(phoneNumberColumn);
}
void Contact::setDarkestSecret()
{

	darkestSecret = getInput(darkestSecretColumn);
}

void Contact::setAbortProgram(bool value)
{
	abortProgram = value;
}

void Contact::setInitialized(bool value)
{
	initialized = value;
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

bool Contact::getInitialized()
{
	return (initialized);
}

Contact::Contact(void)
{
	initialized = false;
	abortProgram = false;
}

Contact::~Contact(void)
{
}