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

void PhoneBook::resetContactCount(void)
{
	if (getContactCount() > contactArraySize)
		setContactCount(contactStartingCountNumber);
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
	int	contactIndex;

	resetContactCount();
	contactIndex = getContactIndex();
	addContact(contacts[contactIndex]);
	if (contacts[contactIndex].getAbortProgram())
	{
		setExecuteInputLoop(false);
		return ;
	}
}
void displayColumns(void)
{
	std::cout.width(columnWidth); std::cout << std::right << indexColumn << columnSeperator;
	std::cout.width(columnWidth); std::cout << std::right << firstNameColumn << columnSeperator;
	std::cout.width(columnWidth); std::cout << std::right << lastNameColumn << columnSeperator;
	std::cout.width(columnWidth); std::cout << std::right << nickNameColumn << std::endl;
}

void PhoneBook::displayContacts()
{
	int	contactIndex;

	contactIndex = getContactIndex();
	displayColumns();
	for (int i = 0; i < contactIndex; i++)
	{
		// std::cout<< contacts[i].getFirstName();
		// std::cout<< " ";
		// std::cout<< contacts[i].getLastName();
		// std::cout<< " ";
		// std::cout<< contacts[i].getNickName();
		// std::cout<< "\n";
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
	setContactCount(contactStartingCountNumber);
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

int PhoneBook::getContactIndex(void)
{
	return (contactCount - 1);
}

bool	PhoneBook::getExecuteInputLoop(void)
{
	return (executeInputLoop);
}
