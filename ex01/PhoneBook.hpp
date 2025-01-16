#ifndef PHONEBOOK_HPP
#	define PHONEBOOK_HPP

#include "Contact.hpp"
#include <limits>
// https://stackoverflow.com/questions/545907/what-is-the-best-way-to-do-input-validation-in-c-with-cin
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
	bool	skipCommand;
public:
	PhoneBook(void);
	~PhoneBook(void);
void	add();
int		getContactCount(void);
bool	getExecuteInputLoop(void);
void	setExecuteInputLoop(bool);
void	setSkipCommand(bool);
bool	checkSkipCommand();
void	search();
void	exit();
};

#endif

