#include "PhoneBook.hpp"

void	PhoneBook::setExecuteInputLoop(bool value)
{
	executeInputLoop = value;
}

void PhoneBook::add()
{
	std::cout << "In phonebook add\n";
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
	contactCount = 0;
	setExecuteInputLoop(true);
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
