// Assignment: C++ Pointers
// Life Support System Override
// By David Garcia
// v1.0.0

// # Is a preprocessor directive and runs before the compiler does
#include <iostream> // #include tells the preprocessor to include the contents of another file. Gives access to cout, cin, endl
#include <random> // This header introduces random number generation facilities
#include <windows.h> // SetConsoleTextAttribute function to change color

// This way saves time but gives you access to all elements
using namespace std; // This using directive gives direct access to the elements of the std namespace

void lifeSupportSystemStatus();
int oxygenSupplyStatus();
int nitrogenSupplyStatus();
void auto_o2Fix(int* o2_ptr);
void auto_n2Fix(int* n2_ptr);

int main() // function called main
{
	string username; // Strings are objects that represent sequences of characters
	string password;
	bool success; // bool data type that indicates true or false

	// SetConsoleTextAttribute changes the attribute for new characters that you write to the console, but doesn't affect existing contents of the console
	// GetStdHandle function provides a mechanism for retrieving the standard input (STDIN), standard output (STDOUT), and standard error (STDERR) handles associated with a process.
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);

	while (success = true) //while loop that will cycle through if the bool success is true from correct user input
	{

		cout << "\n\tLife Support System Override\n"; // new line and tab
		cout << "\nUsername:"; // The cout object, together with the << operator, is used to output values/print text:
		cin >> username; // a predefined variable that reads data from the keyboard with the extraction operator
		cout << "Password:";
		cin >> password;

		if ((username == "ISS") && (password == "NASA")) // if statement that uses a logical AND for both username and password
		{
			cout << "\nWelcome Scientist to the ISS LSS override";
			success = true;
		}

		else // error handling
		{
			cout << "\nWrong user name or password.";
			break;
		}

		do
		{
			lifeSupportSystemStatus(); // main program sequence
		} while (true);

	}
	return 0; // returns 0 if program has no issues
}

void lifeSupportSystemStatus()
{
	int usrChoice; // userChoice integer created for switch

	cout << "\nChoose which Life Supply System to check."
		<< "\n1 - Oxygen"
		<< "\n2 - Nitrogen\n";
	cin >> usrChoice;

	switch (usrChoice)
	{
	case 1:
	{
		int o2 = oxygenSupplyStatus(); // Created int o2 and assigned it return value of oxygenSupplyStatus()
		int* o2_ptr = &o2; // Created o2 pointer and assigned it to memory address of o2

		if ((*o2_ptr) != 22) // If the o2 pointer is not equal to 22 then perform auto correction
		{
			cout << "\nWarning the Oxygen level is " << *o2_ptr << "%, which isn't nominal."
				<< "\n\nPerforming Auto correction sequence...";

			auto_o2Fix(o2_ptr);
			break;
		}
		else
		{
			cout << "\nThe Oxygen level is " << *o2_ptr << "%, which is nominal." << endl;
			break;
		}
	}
	case 2:
	{
		{
			int n2 = nitrogenSupplyStatus(); // Created int n2 and assigned it return value of nitrogenSupplyStatus()
			int* n2_ptr = &n2; // Created n2 pointer and assigned it to memory address of n2

			if ((*n2_ptr) != 78) // If the N2 pointer is not equal to 22 then perform auto correction
			{
				cout << "\nWarning the N2 level is " << *n2_ptr << "%, which isn't nominal."
					<< "\n\nPerforming Auto correction sequence...";

				auto_n2Fix(n2_ptr);
				break;
			}
			else
			{
				cout << "\nThe N2 level is " << *n2_ptr << "%, which is nominal." << endl;
				break;
			}
		}
	default:
		cout << "\nInvalid choice." << endl;
		break;
	}
	}
}

int oxygenSupplyStatus()
{
	random_device randomNumber; // C++11 non-deterministic random number generator using hardware entropy source
	mt19937 gen(randomNumber()); // 32-bit Mersenne Twister algorithim by Matsumoto and Nishimura, 1998
	uniform_int_distribution<> dis(17, 27); // Produces integer values evenly distributed across a range of 17 - 27
	// Nominal oxygen is 22%
	return dis(gen);
}

int nitrogenSupplyStatus()
{
	random_device randomNumber; // C++11 non-deterministic random number generator using hardware entropy source
	mt19937 gen(randomNumber()); // 32-bit Mersenne Twister algorithim by Matsumoto and Nishimura, 1998
	uniform_int_distribution<> dis(73, 83); // Produces integer values evenly distributed across a range of 1 - 6
	// Nominal nitrogen is 78%
	return dis(gen);
}

void auto_o2Fix(int* o2_ptr) // function is used to change the O2 pointer value
{
	*o2_ptr = 22;
	cout << "\nThe Oxygen level has been adjusted to " << *o2_ptr << "%, which is nominal." << endl;
}

void auto_n2Fix(int* n2_ptr) // function is used to change the N2 pointer value
{
	*n2_ptr = 78;
	cout << "\nThe N2 level has been adjusted to " << *n2_ptr << "%, which is nominal." << endl;
}