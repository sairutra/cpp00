#include "PhoneBook.hpp"
#include "Utils.hpp"

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

void	PhoneBook::resetContactCount(void)
{
	if (getContactCount() > contactArraySize)
		setContactCount(contactStartingCountNumber);
}

void	PhoneBook::addContact(Contact &contact)
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
	if (!contact.getAbortProgram())
		contact.setInitialized(true);
	setContactCount(getContactCount() + 1);
}

void	PhoneBook::add()
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
	std::cout	<< std::right << std::setw(columnWidth)
				<< indexColumn << columnSeperator;
	std::cout	<< std::right << std::setw(columnWidth)
				<< firstNameColumn << columnSeperator;
	std::cout	<< std::right << std::setw(columnWidth)
				<< lastNameColumn << columnSeperator;
	std::cout	<< std::right << std::setw(columnWidth)
				<< nickNameColumn << columnSeperator << std::endl;
}

std::string truncateString(std::string &field)
{
	if (field.length() > columnWidth)
		return (field.substr(0, columnWidth - 1) + truncateCharacter);
	return (field);
}

void printColumn(std::string field)
{
	std::cout	<< std::right << std::setw(columnWidth) 
				<< truncateString(field) << columnSeperator; 
}

void	PhoneBook::displayContacts()
{
	displayColumns();
	for (int i = 0; i < contactArraySize; i++)
	{
		if (contacts[i].getInitialized())
		{
			std::cout.width(columnWidth); std::cout << std::right << i << columnSeperator;
			printColumn(contacts[i].getFirstName());
			printColumn(contacts[i].getLastName());
			printColumn(contacts[i].getNickName());
			std::cout << std::endl;
		}
	}
}

void	printNoContactMessage()
{
	std::cout << "There are no contacts to display." << std::endl;
}

bool	PhoneBook::checkNoContacts()
{
	if (getContactCount() == contactStartingCountNumber && 
	!contacts[contactStartingCountNumber - 1].getInitialized())
	{
		printNoContactMessage();
		return (true);
	}
	return (false);
}

void	PhoneBook::search()
{
	if (checkNoContacts())
		return ;
	displayContacts();
	// get index for search
	// index failure handeling
}

void	PhoneBook::exit()
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

int	PhoneBook::getContactCount(void) const
{
	return (contactCount);
}

int	PhoneBook::getContactIndex(void) const 
{
	return (contactCount - 1);
}

bool	PhoneBook::getExecuteInputLoop(void) const 
{
	return (executeInputLoop);
}
