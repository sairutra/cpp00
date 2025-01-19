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

void PhoneBook::setContactIndex(void)
{
	if (getContactCount() > contactArraySize)
		setContactCount(1);
}

void PhoneBook::addContact(Contact &contact)
{
	if (!contact.getAbortProgram())
		contact.setFirstName();
	if (!contact.getAbortProgram())
		contact.setLastName();
	if (!contact.getAbortProgram())
		contact.setNickName();
	if (!contact.getAbortProgram())
		contact.setPhoneNumber();
	if (!contact.getAbortProgram())
		contact.setDarkestSecret();
}

void PhoneBook::add()
{
	int	currentContactCount;
	int	contactIndex;

	currentContactCount = getContactCount();
	setContactIndex();
	contactIndex = (currentContactCount - 1);
	addContact(contacts[contactIndex]);
	if (contacts[contactIndex].getAbortProgram())
	{
		setExecuteInputLoop(false);
		return ;
	}
	if (currentContactCount < contactArraySize)
		setContactCount(currentContactCount + 1);
}

void PhoneBook::displayContacts()
{
	for (int i = 0; i < (contactCount - 1); i++)
	{
		std::cout<< "index: " << i;
		std::cout<< contacts[i].getFirstName();
		std::cout<< " ";
		std::cout<< contacts[i].getLastName();
		std::cout<< " ";
		std::cout<< contacts[i].getNickName();
		std::cout<< "\n";
	}
}

void PhoneBook::search()
{
	// display contacts
	displayContacts();
	// get index for search
	// index failure handeling
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
