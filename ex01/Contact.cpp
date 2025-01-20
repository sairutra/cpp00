#include "Contact.hpp"
#include "Utils.hpp"

void Contact::setFirstName()
{
	firstName = getInput(firstNameColumn);
	if (isCinFailure())
		setAbortProgram(true);
}
void Contact::setLastName()
{
	lastName = getInput(lastNameColumn);
	if (isCinFailure())
		setAbortProgram(true);
}
void Contact::setNickName()
{
	nickName = getInput(nickNameColumn);
	if (isCinFailure())
		setAbortProgram(true);
}
void Contact::setPhoneNumber()
{
	phoneNumber = getInput(phoneNumberColumn);
	if (isCinFailure())
		setAbortProgram(true);
}
void Contact::setDarkestSecret()
{
	darkestSecret = getInput(darkestSecretColumn);
	if (isCinFailure())
		setAbortProgram(true);
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