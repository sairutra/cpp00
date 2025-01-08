#include <iostream>

void printToUpper(std::string string)
{
	for (long unsigned int i = 0; i < string.length(); i++)
	{
		int upper = toupper(string[i]);
		char c = static_cast<char>(upper);
		std::cout << c;
	}
}
int main (int argc, char *argv[])
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < argc; i++)
		{
			printToUpper(argv[i]);
		}
	}
	std::cout << "\n";
	return (0);
}
