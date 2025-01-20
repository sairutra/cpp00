#ifndef PHONEBOOK_HPP
#	define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>
#include <limits>

enum class Commands
{
	UNSPECIFIED,
	ADD,
	SEARCH,
	EXIT,
};

constexpr int contactArraySize = 8;
constexpr int columnWidth = 10;
constexpr int maxColumnDisplaySize = 10;
constexpr int contactStartingCountNumber = 1;
constexpr char columnSeperator[] = "|";
constexpr char rowSeperator = '-';
constexpr char truncateCharacter[] = ".";
constexpr char addToken[] = "ADD";
constexpr char searchToken[] = "SEARCH";
constexpr char exitToken[] = "EXIT";

class PhoneBook
{
private:
	Contact	contacts[contactArraySize];
	int		contactCount;
	bool	executeInputLoop;
	bool	skipCommand;
	void	displayContacts();
public:
		PhoneBook(void);
		~PhoneBook(void);
	void	add();
	void	addContact(Contact &contact);
	bool	checkSkipCommand();
	bool	checkNoContacts();
	void	exit();
	int		getContactCount(void) const;
	bool	getExecuteInputLoop(void) const;
	int		getContactIndex(void) const;
	void	resetContactCount(void);
	void	setContactCount(int);
	void	setSkipCommand(bool);
	void	setExecuteInputLoop(bool);
	void	search();
};

#endif

