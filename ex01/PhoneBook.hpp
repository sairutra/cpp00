#ifndef PHONEBOOK_HPP
#	define PHONEBOOK_HPP

#include "Contact.hpp"

enum class Commands
{
	UNSPECIFIED,
	ADD,
	SEARCH,
	EXIT,
};

class PhoneBook
{
private:
	Contact	contacts[8];
	int		contactCount;
	bool	executeInputLoop;
public:
	PhoneBook(void);
	~PhoneBook(void);
void	add();
int		getContactCount(void);
bool	getExecuteInputLoop(void);
void	setExecuteInputLoop(bool);
void	search();
void	exit();
};

#endif

