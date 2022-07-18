// David Garcia
// Main Source File
// Final Assignment OOP
// v1.0

// # Is a preprocessor directive and runs before the compiler does
#include <iostream> // #include tells the preprocessor to include the contents of another file. Gives access to cout, cin, endl
#include <string> // Easier way to access strings
#include <random> // This header introduces random number generation facilities
#include <stdlib.h> // Used for exit() function to terminate program successfully or in failure
#include "game.h" // Additional source file

using namespace std;

int main()
{
	Utility rpg; // Instance of Class Utility

	rpg.Login(); // Accessing Login method from Utility Class
	rpg.Welcome();

	while (true) // Main Game Loop
	{
		rpg.GameMenu();
	}
	return 0;
}
