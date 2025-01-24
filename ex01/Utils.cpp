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

void printEmptyPrompt(void)
{
	std::cout << emptyFieldMessage << std::endl;
}
bool	isCinFailure(void)
{
	if (checkCinFail() || checkCinEofFail())
		return (true);
	return (false);
}

void	printIsNotPrintable(void)
{
	std::cout << isNotPrintableMessage << std::endl;
}

bool	isPrintableString(std::string string)
{
	for (char c: string)
	{
		if (!std::isprint(c))
		{
			printIsNotPrintable();
			return (false);
		}
	}
	return (true);
}

std::string getInput(std::string prompt)
{
	std::string input;

	while (input.empty())
	{
		printInputPrompt(prompt);
		getline(std::cin, input);
		if (isCinFailure())
			return (input);
		if (input.empty())
			printEmptyPrompt();
		if (!isPrintableString(input))
			input.clear();
	}
	return (input);
}

std::string trim(const std::string& str)
{
	size_t first;
	size_t last;
	
	first = str.find_first_not_of(' ');
	if (std::string::npos == first)
		first = 0;
	last = str.find_last_not_of(' ');
	return (str.substr(first, (last - first + 1)));
}