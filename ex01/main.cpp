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

void executeCommand(PhoneBook &phonebook, Commands command)
{
	if (!phonebook.getExecuteInputLoop())
		return ; 
	else if (phonebook.checkSkipCommand())
		return ;
	else if (command == Commands::ADD)
		phonebook.add();
	else if (command == Commands::SEARCH)
		phonebook.search();
	else if (command == Commands::EXIT)
		phonebook.exit();
}

void	cinErrorHandling(PhoneBook &phonebook)
{
	if (std::cin.eof())
		phonebook.setExecuteInputLoop(false);
	else if (std::cin.fail())
	{
		std::cerr << "cin failure, try to input again\n";
		//clear fail state of cin
		std::cin.clear();
		// ignore rest of user input, skip till end of line
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		phonebook.setSkipCommand(true);
	}
}

void	getInputLine(PhoneBook &phonebook, std::string &input)
{
	getline(std::cin, input);
	cinErrorHandling(phonebook);
}

// REFERENCE: https://stackoverflow.com/questions/545907/what-is-the-best-way-to-do-input-validation-in-c-with-cin
int main (void)
{
	std::string input;
	PhoneBook phonebook;
	Contact contact;

	while (phonebook.getExecuteInputLoop())
	{
		printPrompt();
		getInputLine(phonebook, input);
		executeCommand(phonebook, getCommand(input));
	}
	return (0);
}
