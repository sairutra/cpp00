#ifndef PHONEBOOK_HPP
#	define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact	contacts[8];
	int		contactCount;
public:
	PhoneBook(void);
	~PhoneBook(void);
void	add();
int		getContactCount(void);
void	search();
void	exit();
};

#endif

