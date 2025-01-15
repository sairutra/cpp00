#include "PhoneBook.hpp"

void	printPrompt()
{
	std::cout << "Enter a command : ADD - SEARCH - EXIT\n";
}

Commands getCommand(std::string input)
{
	if (input == "ADD")
		return (Commands::ADD);
	else if (input == "SEARCH")
		return (Commands::SEARCH);
	else if (input == "EXIT")
		return (Commands::EXIT);
	return (Commands::UNSPECIFIED);
}

void executeCommand(PhoneBook phonebook, Commands command)
{
	if (command == Commands::ADD)
		phonebook.add();
	else if (command == Commands::SEARCH)
		phonebook.search();
	else if (command == Commands::EXIT)
		phonebook.exit();
}

// check this source : https://stackoverflow.com/questions/545907/what-is-the-best-way-to-do-input-validation-in-c-with-cin

int main (void)
{
	std::string input;
	PhoneBook phonebook;

	while (true)
	{
		printPrompt();
		getline(std::cin, input);
		executeCommand(phonebook, getCommand(input));
		if (phonebook.getExitProgram())
			break;
	}
	return (0);
}
