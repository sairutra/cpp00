#include "Utils.hpp"

void	printRowSeperator(void)
{
	std::cout	<< std::string(44, rowSeperator) << std::endl;
}

void	printPrompt()
{
	std::cout << "Enter a command : ADD - SEARCH - EXIT\n";
}

bool	cinEofFail(void)
{
	if (std::cin.eof())
		return (true);
	return (false);
}

void printCinFailure(void)
{
	std::cerr << "cin failure, try to input again\n";
}

bool	cinFail(void)
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
