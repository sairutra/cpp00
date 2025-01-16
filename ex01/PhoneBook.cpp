#include "PhoneBook.hpp"

bool	PhoneBook::checkSkipCommand()
{
	if (skipCommand)
	{
		skipCommand = false;
		return (true);
	}
	return (false);
}

void	PhoneBook::setSkipCommand(bool value)
{
	skipCommand = value;
}

void	PhoneBook::setContactCount(int value)
{
	contactCount = value;
}

void	PhoneBook::setExecuteInputLoop(bool value)
{
	executeInputLoop = value;
}

Contact createContact(void)
{
	Contact contact;

	contact.setFirstName();
	contact.setLastName();
	contact.setNickName();
	contact.setPhoneNumber();
	contact.setDarkestSecret();
	return (contact);
}

void PhoneBook::addContact(Contact contact)
{
	int	contactIndex;

	contactIndex = getContactCount();
	if (contactIndex > contactArraySize)
		setContactCount(1);
	contacts[contactIndex] = contact;
}

void PhoneBook::add()
{
	Contact contact;

	contact = createContact();
	addContact(contact);
}

void PhoneBook::search()
{

	std::cout << "In phonebook search\n";
}

void PhoneBook::exit()
{
	setExecuteInputLoop(false);
}

PhoneBook::PhoneBook(void)
{
	setContactCount(1);
	setExecuteInputLoop(true);
	setSkipCommand(false);
}
PhoneBook::~PhoneBook(void)
{
}

int PhoneBook::getContactCount(void)
{
	return (contactCount);
}

bool	PhoneBook::getExecuteInputLoop(void)
{
	return (executeInputLoop);
}
