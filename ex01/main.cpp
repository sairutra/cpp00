#include "PhoneBook.hpp"
#include "Utils.hpp"

Commands	getCommand(std::string input)
{
	if (input == addToken)
		return (Commands::ADD);
	else if (input == searchToken)
		return (Commands::SEARCH);
	else if (input == exitToken)
		return (Commands::EXIT);
	return (Commands::UNSPECIFIED);
}

void	executeExitCommand(PhoneBook &phonebook)
{
	printRowSeperator();
	phonebook.exit();
	printRowSeperator();
}
void	executeSearchCommand(PhoneBook &phonebook)
{
	printRowSeperator();
	phonebook.search();
	printRowSeperator();
}

void	executeAddCommand(PhoneBook &phonebook)
{
	printRowSeperator();
	phonebook.add();
	printRowSeperator();
}

void	executeCommand(PhoneBook &phonebook, Commands command)
{
	if (!phonebook.getExecuteInputLoop())
		return ; 
	else if (phonebook.checkSkipCommand())
		return ;
	else if (command == Commands::ADD)
		executeAddCommand(phonebook);
	else if (command == Commands::SEARCH)
		executeSearchCommand(phonebook);
	else if (command == Commands::EXIT)
		executeExitCommand(phonebook);
}

void	getInputLine(PhoneBook &phonebook, std::string &input)
{
	getline(std::cin, input);
	if (cinEofFail())
		phonebook.setExecuteInputLoop(false);
	if (cinFail())
		phonebook.setSkipCommand(true);
}

int	main (void)
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
