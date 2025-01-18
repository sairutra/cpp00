

#ifndef CONTACT_HPP
#	define CONTACT_HPP

#include <iostream>

class Contact
{
private:
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string phoneNumber;
	std::string darkestSecret;
	bool		abortProgram;
public:
	Contact();
	~Contact();
	void setFirstName();
	void setLastName();
	void setNickName();
	void setPhoneNumber();
	void setDarkestSecret();
	void	setAbortProgram(bool);
	std::string getFirstName();
	std::string getLastName();
	std::string getNickName();
	std::string getPhoneNumber();
	std::string getDarkestSecret();
	std::string getInput(std::string);
	bool	getAbortProgram();
};


#endif
