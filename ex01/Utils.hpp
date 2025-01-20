
#ifndef UTILS_HPP
#	define UTILS_HPP

#include "PhoneBook.hpp"

constexpr int rowSeperatorWidth = 44;

void		printRowSeperator(void);
void		printPrompt(void);
bool		checkCinEofFail(void);
bool		checkCinFail(void);
bool		isCinFailure(void);
std::string	getInput(std::string);

#endif

