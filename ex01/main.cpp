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
	if (phonebook.getExecuteInputLoop())
		printRowSeperator();
}
void	executeSearchCommand(PhoneBook &phonebook)
{
	printRowSeperator();
	phonebook.search();
	if (phonebook.getExecuteInputLoop())
		printRowSeperator();
}

void	executeAddCommand(PhoneBook &phonebook)
{
	printRowSeperator();
	phonebook.add();
	if (phonebook.getExecuteInputLoop())
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
	if (isCinFailure())
	{
		phonebook.setExecuteInputLoop(false);
		phonebook.setSkipCommand(true);
	}
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
