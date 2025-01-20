#include "Utils.hpp"

void	printRowSeperator(void)
{
	std::cout << std::string(rowSeperatorWidth, rowSeperator) << std::endl;
}

void	printPrompt()
{
	std::cout << "Enter a command : ADD - SEARCH - EXIT\n";
}

bool	checkCinEofFail(void)
{
	if (std::cin.eof())
		return (true);
	return (false);
}

bool	checkCinFail(void)
{
	if (std::cin.fail())
	{
		//clear fail state of cin
		std::cin.clear();
		// ignore rest of user input, skip till end of line
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return (true);
	}
	return (false);
}

void printInputPrompt(std::string &prompt)
{
	std::cout.width(inputColumnWidth); std::cout << std::left << prompt; 
	std::cout << inputSeperator; 
}

void printEmptyPrompt(std::string &prompt)
{
	std::cout << emptyFieldMessage << std::endl;
	printInputPrompt(prompt);
}
bool	isCinFailure(void)
{
	if (checkCinFail() || checkCinEofFail())
		return (true);
	return (false);
}

std::string getInput(std::string prompt)
{
	std::string input;

	printInputPrompt(prompt);
	while (input.empty())
	{
		getline(std::cin, input);
		if (isCinFailure())
			return (input);
		if (input.empty())
			printEmptyPrompt(prompt);
	}
	return (input);
}