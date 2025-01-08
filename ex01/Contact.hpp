

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
public:
	Contact(/* args */);
	~Contact();
	void setFirstName();
	void setLastName();
	void setNickName();
	void setPhoneNumber();
	void setDarkestSecret();
};


#endif
