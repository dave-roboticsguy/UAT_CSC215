// Using References to Hack and Bankrupting the Terrorists
// By David Garcia
// v1.0.0

// # Is a preprocessor directive and runs before the compiler does
#include <iostream> // #include tells the preprocessor to include the contents of another file. Gives access to cout, cin, endl
#include <string> // Easier way to access strings
#include <chrono> // time
#include <thread> // sleep_for
#include <windows.h> // SetConsoleTextAttribute function to change color


// This way saves time but gives you access to all elements
using namespace std; // This using directive gives direct access to the elements of the std namespace
using namespace chrono;
using namespace this_thread;

int& displayChoice();
void menu();
void normalTransaction(double a, double b);
void swappedTransaction(double& a, double& b);
void slowBurnCurrencyVirus(double& a);

int main() // function called main
{
	string username; // Strings are objects that represent sequences of characters
	string password;
	bool success; // bool data type that indicates true or false

	// SetConsoleTextAttribute changes the attribute for new characters that you write to the console, but doesn't affect existing contents of the console
	// GetStdHandle function provides a mechanism for retrieving the standard input (STDIN), standard output (STDOUT), and standard error (STDERR) handles associated with a process.

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);

	while (success = true) //while loop that will cycle through if the bool success is true from correct user input
	{

		cout << "\n\tCIA Bank Account Hack Program\n"; // new line and tab
		cout << "\nUsername:"; // The cout object, together with the << operator, is used to output values/print text:
		cin >> username; // a predefined variable that reads data from the keyboard with the extraction operator
		cout << "Password:";
		cin >> password;

		if ((username == "Bond") && (password == "007")) // if statement that uses a logical AND for both username and password
		{
			cout << "\nWelcome Mr. Bond, please choose what action you wish to take.";
			success = true;
		}

		else // error handling
		{
			cout << "\nWrong user name or password.";
			break;
		}

		do
		{
			menu();
		} while (true);

	}
	return 0; // returns 0 if program has no issues
}

int& displayChoice()
{
	int choice;

	cout << "\n\n1 - Normal Balance Check.\n";
	cout << "2 - Swap Hack Transaction.\n";
	cout << "3 - Burn The Money!\n\n";
	cout << "Enter a number: ";
	cin >> choice;

	// I created this to stop infinite loop if anything other than 1 - 3 is chosen.
	if (choice == 1 || choice == 2 || choice == 3) // Checks that (1 or 2 or 3) is chosen
	{
		return choice;
	}
	else
	{
		cout << "\nInvalid choice.\n";
		// This means abnormal termination of the program, some error or interrupt has occured, same as exit(1)
		exit(EXIT_FAILURE); // Also, exit(0) means EXIT_SUCCESS
	}
}


void menu() // Switch statement that takes the user input choice from path() and assigns it to num
{
	int& refChoice = displayChoice(); // Just taking the reference of original choice and assigning it to refChoice, not really needed
	double joesCoffeShopAccount = 10000.00;
	double bankOfTerror = 10000000.00;

	// I kept on getting bank of terror in scientific notation
	// Sourced from: https://www.tutorialspoint.com/How-do-I-print-a-double-value-with-full-precision-using-cout-in-Cplusplus
	typedef numeric_limits< double > dbl; // This removes scientific notation and adds fixed precision

	switch (refChoice)
	{
	case 1:
	{
		normalTransaction(joesCoffeShopAccount, bankOfTerror);
		cout << "\nJoe's Coffee Shop Account: $"
			<< fixed << joesCoffeShopAccount
			<< "\n\nBank of Terror's Account: $"
			<< fixed << bankOfTerror;
		break;
	}

	case 2:
	{
		swappedTransaction(joesCoffeShopAccount, bankOfTerror);
		cout << "\nJoe's Coffee Shop Account: $"
			<< fixed << joesCoffeShopAccount
			<< "\n\nBank of Terror's Account: $"
			<< fixed << bankOfTerror;
		break;
	}
	case 3:
	{
		cout << "\nInjected Virus, it will now deplete $100,000 from Terrorist account every second."
			<< "\nPsychological Warfare.\n\n";

		slowBurnCurrencyVirus(bankOfTerror);
		cout << "\nJoe's Coffee Shop Account: $"
			<< fixed << joesCoffeShopAccount
			<< "\n\nBank of Terror's Account: $"
			<< fixed << bankOfTerror;
		break;
	}
	// I dont need default, I perform error handling in path().
	// Also default is not required, execution will just continue, depends on your program
	}

}

// New copy is created but its local and doesnt reference original memory (Joes or Bank of Terror)
void normalTransaction(double a, double b)
{
	double holder = a;
	a = b;
	b = holder;
}

// The & makes the parameter here a reference back to original value
// Any changes made here will be made directly to memory of original value (Joes or Bank of Terror)
void swappedTransaction(double& a, double& b)
{
	double rHolder = a; // rHolder is needed to create a copy of **double& a** first so it doesnt get overwrote later.
	a = b; // Assigns a to b, so the memory slot for a which is the same as joesCoffeShopAccount is now swapped with bankOfTerror
	b = rHolder; // Assigns b to original a value.
}

// I use the reference memory of Bank of Terror and use a for loop to slowly deplete their funds
// The Virus will subtract $100000 every second from terrorist funds and totally deplete funds
void slowBurnCurrencyVirus(double& a)
{
	for (int i = 0; i < 10000000; i++)
	{
		a -= 100000.00; // subtraction assignment
		sleep_for(milliseconds(1000)); // Blocks execution of the calling thread during the span of time specified
		cout << fixed << a << endl;
	}
}