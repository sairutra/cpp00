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
	// put this in constructor of contact
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
	// immediately put this in array of contacts: contacts[index] = Contact();
	contact = createContact();
	if (contact.getAbortProgram())
	{
		setExecuteInputLoop(false);
		return ;
	}
	addContact(contact);
	std::cout << contacts[0].getFirstName()<< std::endl;
	setContactCount(getContactCount() + 1);
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
