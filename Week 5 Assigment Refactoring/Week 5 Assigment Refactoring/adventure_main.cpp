// David Garcia
// Main Source File
// A little adventure with C++
// v1.0

// # Is a preprocessor directive and runs before the compiler does
#include <iostream> // #include tells the preprocessor to include the contents of another file. Gives access to cout, cin, endl
#include <string> // Easier way to access strings
#include <random> // This header introduces random number generation facilities
#include <stdlib.h> // Used for exit() function to terminate program successfully or in failure
#include "adventure.h" // Additional source file

// This way saves time but gives you access to all elements
using namespace std; // This using directive gives direct access to the elements of the std namespace

string welcome();
void choice(string name);

int main() // function called main
{
	string heroName;
	bool success;
	success = login(); // If login is successful, return flag true
	securityPrompt(success); // Take true flag and display prompt
	heroName = welcome(); // Runs welcome function and gets name from user input and assigns it to "heroName" string
	choice(heroName); // Passes heroName argument into choice function

	while (true) // Once logged in, I keep game running with this loop
	{
		switchMenu();
	}
}