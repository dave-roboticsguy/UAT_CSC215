// A little adventure with C++

// # Is a preprocessor directive and runs before the compiler does
#include <iostream> // #include tells the preprocessor to include the contents of another file. Gives access to cout, cin, endl
#include <string> // Easier way to access strings
#include <random> // This header introduces random number generation facilities
#include <stdlib.h> // Used for exit() function to terminate program successfully or in failure

// This way saves time but gives you access to all elements
using namespace std; // This using directive gives direct access to the elements of the std namespace

// prototypes are a declaration of a function
// C++ does not require prototypes, but can be good practice for:
// Better organization, prevents errors from reorganization, allows for default arguments that are always used
bool login();
void securityPrompt(bool success);
string welcome();
void choice(string name);
int path();
void switchMenu();
void knight();
void samurai();
void pirate();

const string ENDING = "Game Over, "; // constant global string for game ending scenarios

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

bool login()
{
	string username; // Strings are objects that represent sequences of characters
	string password; // Strings are objects that represent sequences of characters
	bool flag;

	// do loop, keeps asking user for login information until correct
	do {
		cout << "Please login.\n"
			<< "Username: ";
		// // A standard library function that is used to read a string or a line from an input stream.
		getline(cin, username); // Takes userinput and assigns it to "username"
		if (username == "Dave") // username must equal "Dave"
		{
			cout << "Password: ";
			getline(cin, password);
			if (password != "Pass") // Error handling
			{
				cout << "Wrong Password, please try again." << endl;
			}
		}
		else
		{
			cout << "Wrong Username, please try again." << endl; // Error handling
		}
	} while (password != "Pass");
	return flag = true; // If login is successful, return flag true
}

void securityPrompt(bool success)
{
	cout << "\nLogin attempt was flagged as "
		<< success << endl; // 1 is used to represent true
}

string welcome()
{
	string adventureName;
	cout << "\n\tWelcome to my C++ adventure!\n" // new line and tab
		<< "Choose your Hero name.\n";
	getline(cin, adventureName);
	cout << "\n"
		<< adventureName
		<< ", your epic adventure now begins!\n" << endl;

	return adventureName;
}

void choice(string name)
{
	cout << "\n"
		<< name
		<< ", choose your Destiny.\n" << endl;
}

int path()
{
	int destiny;

	cout << "\n1 - Knight\n";
	cout << "2 - Samurai\n";
	cout << "3 - Pirate\n\n";
	cout << "Enter a number: ";
	cin >> destiny;

	// I created this to stop infinite loop if anything other than 1 - 3 is chosen.
	if (destiny == 1 || destiny == 2 || destiny == 3) // Checks that (1 or 2 or 3) is chosen
	{
		return destiny;
	}
	else
	{
		cout << "\nInvalid choice.\n";
		// This means abnormal termination of the program, some error or interrupt has occured, same as exit(1)
		exit(EXIT_FAILURE); // Also, exit(0) means EXIT_SUCCESS
	}
}

void switchMenu() // Switch statement that takes the user input choice from path() and assigns it to num
{
	int num = path();
	switch (num)
	{
	case 1:
	{
		knight(); // Knight adventure
		break;
	}

	case 2:
	{
		samurai(); // Samurai adventure
		break;
	}
	case 3:
	{
		pirate(); // Pirate adventure
		break;
	}
	// I dont need default, I perform error handling in path().
	// Also default is not required, execution will just continue, depends on your program
	}

}

void knight()
{
	char adventureChoice;

	cout << "\nYou have chosen to be a knight.\n"
		<< "Welcome to the land known as Northumbria.\n"
		<< "There is a strangely dressed women. Do you approach her?\n"
		<< "Y for yes, N for no\n";
	cin >> adventureChoice;

	if (adventureChoice == 'Y') // equal to operator
	{
		cout << "\nYou ask the women who she is and she replies, \"I AM THE GREAT ISABELLA.\"\n" // escape for quotes within string
			<< "You gaze into her eyes and fall madly in love with her.\n"
			<< ENDING
			<< "lover boy.\n";
	}
	else if (adventureChoice == 'N')
	{
		cout << "\nYou do not approach her and get your head sliced off by an incoming horseman.\n"
			<< ENDING
			<< "you suck at adventure games.\n";
	}
	else
	{
		cout << "\nInvalid choice.\n";
	}
}

void samurai()
{
	char adventureChoice;

	cout << "\nYou have chosen to be a samurai.\n"
		<< "Welcome to the land known as Kyoto.\n"
		<< "Their is another samurai charging at you. Do you attack them?\n"
		<< "Y for yes, N for no\n";
	cin >> adventureChoice;

	if (adventureChoice == 'Y')
	{
		cout << "\nYou parry his attack and your riposte slices his throat open and he dies choking on his own blood.\n"
			<< ENDING
			<< "your name will be remembered throughout history.\n";
	}
	else if (adventureChoice == 'N')
	{
		cout << "\nYou run away in fear and he slices your back and you fall over and die a dishonorable death.\n"
			<< ENDING
			<< "coward!\n";
	}
	else
	{
		cout << "\nInvalid choice.\n";
	}
}

void pirate()
{
	char adventureChoice;

	cout << "\nYou have chosen to be a pirate.\n"
		<< "You have a drink in one hand and a pipe in the other.\n"
		<< "You take a sip and set the drink down on the gambling table inside the ship.\n"
		<< "You take a puff from your pipe, pick up the dice and throw it on the table.\n";

	// Below random generator is sourced from:
	// https://en.cppreference.com/w/cpp/numeric/random
	// https://stackoverflow.com/questions/4926622/how-to-generate-different-random-numbers-in-a-loop-in-c

	random_device randomNumber; // C++11 non-deterministic random number generator using hardware entropy source
	mt19937 gen(randomNumber()); // 32-bit Mersenne Twister algorithim by Matsumoto and Nishimura, 1998
	uniform_int_distribution<> dis(1, 6); // Produces integer values evenly distributed across a range of 1 - 6

	int die1 = dis(gen); // Generates the random number from the distribution of 1 - 6
	int die2 = dis(gen);

	cout << "\nYou rolled a " << die1 << die2 << endl; // outputs die1 and die 2 randomly generated values from distribution of 1 - 6

	if ((die1 == 1) && (die2 == 1)) // Logcal AND comparison, you win with snake eyes
	{
		cout << "\nYou win the beautiful slave girl and the chest of gold.\n"
			<< ENDING
			<< "you love the pirate life.\n";
	}
	else
	{
		cout << "\nYou shoot yourself in the head for losing everything.\n"
			<< ENDING
			<< "life as a pirate sucks.\n";
	}
}