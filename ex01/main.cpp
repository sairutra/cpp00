#include "PhoneBook.hpp"
#include "Utils.hpp"

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

void	getInputLine(PhoneBook &phonebook, std::string &input)
{
	getline(std::cin, input);
	if (cinEofFail())
		phonebook.setExecuteInputLoop(false);
	if (cinFail())
		phonebook.setSkipCommand(true);
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
