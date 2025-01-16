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

constexpr int contactArraySize = 8;

class PhoneBook
{
private:
	Contact	contacts[contactArraySize];
	int		contactCount;
	bool	executeInputLoop;
	bool	skipCommand;
public:
	PhoneBook(void);
	~PhoneBook(void);
void	add();
void	addContact(Contact);
int		getContactCount(void);
bool	getExecuteInputLoop(void);
void	setExecuteInputLoop(bool);
void	setContactCount(int);
void	setSkipCommand(bool);
bool	checkSkipCommand();
void	search();
void	exit();
};

#endif

