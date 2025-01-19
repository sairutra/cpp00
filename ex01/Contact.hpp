

#ifndef CONTACT_HPP
#	define CONTACT_HPP

#include <iostream>

constexpr char indexColumn[] = "index";
constexpr char firstNameColumn[] = "first name";
constexpr char lastNameColumn[] = "last name";
constexpr char nickNameColumn[] = "nick name";
constexpr char phoneNumberColumn[] = "phone number";
constexpr char darkestSecretColumn[] = "darkest secret";
constexpr char emptyFieldMessage[] = "No empty fields allowed";
constexpr char inputSeperator[] = ":";
constexpr int  inputColumnWidth = 25;

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
