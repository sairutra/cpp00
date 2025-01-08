#include "PhoneBook.hpp"

int main (void)
{
	std::string command;

	while (true)
	{
		std::cout << "Enter a command : ADD - SEARCH - EXIT\n";
		getline(std::cin, command);
		std::cout << command + "\n";
	}
	// get input from terminal
	// parse input
	// get input again
	return (0);
}
