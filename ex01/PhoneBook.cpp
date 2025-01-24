#include "PhoneBook.hpp"
#include "Utils.hpp"

bool	PhoneBook::checkSkipCommand()
{
	if (skipCommand)
		return (true);
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

std::string truncateString(const std::string &field)
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
	printRowSeperator();
}

void	printNoContactMessage()
{
	std::cout << NoContactsMessage << std::endl;
}

void	printContactNotFound()
{
	std::cout << contactNotFoundMessage << std::endl;
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

bool	isDigits(const std::string &string)
{
	return (string.find_first_not_of("0123456789") == std::string::npos);
}

int	PhoneBook::tryConvertString(const std::string &string)
{
	int index;
	try
	{
		index = std::stoi(string);
	}
	catch(const std::exception& e)
	{
		return (SearchIndexException());
	}
	return (index);
}

int	PhoneBook::getSearchIndex()
{
	int	index;
	std::string input;
	
	if (isCinFailure())
	{
		setExecuteInputLoop(false);
		return (0);
	}
	input = getInput(searchInputIndexMessage);
	if (!isDigits(input))
		return (SearchIndexException());
	index = tryConvertString(input);
	return (index);
}

int	PhoneBook::SearchIndexException()
{
	if (!getExecuteInputLoop())
		std::cerr << searchIndexExceptionMessage << std::endl;
	return (getSearchIndex());
}

bool	checkIndexValidity(int	index)
{
	if ((index >= 0) && (index < contactArraySize))
		return (true);
	return (false);
}

void	printRow(const std::string key, const std::string &value)
{
	std::cout	<< std::left << std::setw(printRowWidth) 
				<< key	<< inputSeperator
				<< value << std::endl; 
}

void	PhoneBook::displayContactAt(int index)
{
	if (!contacts[index].getInitialized())
	{
		printContactNotFound();
		return ;
	}
	printRowSeperator();
	if (contacts[index].getInitialized())
	{
		printRow(indexColumn, std::to_string(index));
		printRow(firstNameColumn, contacts[index].getFirstName());
		printRow(lastNameColumn, contacts[index].getLastName());
		printRow(phoneNumberColumn, contacts[index].getPhoneNumber());
		printRow(darkestSecretColumn, contacts[index].getDarkestSecret());
	}
}

void	PhoneBook::search()
{
	int	index;

	if (checkNoContacts())
		return ;
	displayContacts();
	index = getSearchIndex();
	if (getExecuteInputLoop())
	{
		if (checkIndexValidity(index))
			displayContactAt(index);
		else
			printContactNotFound();
	}
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
