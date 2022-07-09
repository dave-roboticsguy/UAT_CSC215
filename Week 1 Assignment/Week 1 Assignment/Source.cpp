// A little adventure with C++

// # Is a preprocessor directive and runs before the compiler does
#include <iostream> // #include tells the preprocessor to include the contents of another file. Gives access to cout, cin, endl
#include <string> // Easier way to access strings
// #include <cstdlib>
// #include <ctime>
#include <random> // This header introduces random number generation facilities

// This way saves time but gives you access to all elements
using namespace std; // This using directive gives direct access to the elements of the std namespace

int main() // function called main
{
	string username; // Strings are objects that represent sequences of characters
	string password; // Strings are objects that represent sequences of characters
	bool success; // bool data type that indicates true or false
	int destiny; // stores integer whole numbers
	char choice; // stores single characters

	while (success = true) //while loop that will cycle through if the bool success is true from correct user input
	{

		cout << "\n\tWelcome to my C++ adventure!\n"; // new line and tab
		cout << "\nUsername:"; // The cout object, together with the << operator, is used to output values/print text:
		cin >> username; // a predefined variable that reads data from the keyboard with the extraction operator
		cout << "Password:";
		cin >> password;

		if ((username == "Dave") && (password == "Pass")) // if statement that uses a logical AND for both username and password
		{
			cout << "\nHello Adventurer!";
			success = true;
		}

		else // error handling
		{
			cout << "\nWrong user name or password.";
			break;
		}

		do
		{
			cout << "\nChoose your Destiny!\n\n";
			cout << "1 - Knight\n";
			cout << "2 - Samurai\n";
			cout << "3 - Pirate\n\n";

			cout << "Destiny:";
			cin >> destiny;

			switch (destiny) // case statement that works off user input
			{
			case 1: // The Knight Adventure
				cout << "You have chosen to be a knight.\n"
					<< "Welcome to the land known as Northumbria.\n"
					<< "There is a strangely dressed women. Do you approach her?\n"
					<< "Y for yes, N for no\n";
				cin >> choice;
				if (choice == 'Y') // equal to operator
				{
					cout << "You ask the women who she is and she replies, \"I AM THE GREAT ISABELLA.\"\n" // escape for quotes within string
						<< "You gaze into her eyes and fall madly in love with her.\n"
						<< "Game Over, lover boy.\n";
					break;
				}

				else if (choice == 'N')
				{
					cout << "You do not approach her and get your head sliced off by an incoming horseman.\n"
						<< "Game Over, you suck at adventure games.\n";
					break;
				}
				else
				{
					cout << "Invalid choice.\n";
					break;
				}

			case 2: //The Samurai adventure
				cout << "You have chosen to be a samurai.\n"
					<< "Welcome to the land known as Kyoto.\n"
					<< "Their is another samurai charging at you. Do you attack them?\n"
					<< "Y for yes, N for no\n";
				cin >> choice;
				if (choice == 'Y')
				{
					cout << "You parry his attack and your riposte slices his throat open and he dies choking on his own blood.\n"
						<< "Game Over, your name will be remembered throughout history.\n";
					break;
				}

				else if (choice == 'N')
				{
					cout << "You run away in fear and he slices your back and you fall over and die a dishonorable death.\n"
						<< "Game Over, coward!\n";
					break;
				}

				else
				{
					cout << "Invalid choice.\n";
					break;
				}

			case 3: //The Pirate Adventure
			{
				cout << "You have chosen to be a pirate.\n"
					<< "You have a drink in one hand and a pipe in the other.\n"
					<< "You take a sip and set the drink down on the gambling table inside the ship.\n"
					<< "You take a puff from your pipe, pick up the dice and throw it on the table.\n";

				// OBSOLETE
				// Was a bad idea to put my variables within the switch statement, found this on stackoverflow
				// The book didnt have local scope in case statement examples
				// So I made all the variables local scope with {}

				//srand((unsigned int)time(NULL)); //generates random seed, based on current time
				//srand(static_cast<unsigned int>(time(0))); //seed random number generator
				//int randomNumber = rand(); //generate random number
				//int die1 = (randomNumber % 6) + 1; // get a number between 1 and 6 // modulo 6 give remainder of 5 and below so add 1 to get 6.
				//int die2 = (randomNumber % 6) + 1; // get a number between 1 and 6

				// I got the above code from the book and watching some youtube video tutorials. However, both die1 & die 2 would get the same values since it was using the same clock value.
				// So I decided to research a better way to seed my random number generator besides the clock.
				// I also found that you need to use unsigned int or the software gets messed up with 64 and 32 bit.

				// Below random generator is sourced from:
				// https://en.cppreference.com/w/cpp/numeric/random
				// https://stackoverflow.com/questions/4926622/how-to-generate-different-random-numbers-in-a-loop-in-c

				random_device randomNumber; // C++11 non-deterministic random number generator using hardware entropy source
				mt19937 gen(randomNumber()); // 32-bit Mersenne Twister algorithim by Matsumoto and Nishimura, 1998
				uniform_int_distribution<> dis(1, 6); // Produces integer values evenly distributed across a range of 1 - 6

				int die1 = dis(gen); // Generates the random number from the distribution of 1 - 6
				int die2 = dis(gen);

				cout << "You rolled a " << die1 << die2 << endl; // outputs die1 and die 2 randomly generated values from distribution of 1 - 6

				if ((die1 == 1) && (die2 == 1)) // Logcal AND comparison, you win with snake eyes
				{
					cout << "You win the beautiful slave girl and the chest of gold.\n"
						<< "Game over, you love the pirate life.\n";
					break;
				}
				else
				{
					cout << "You shoot yourself in the head for losing everything.\n"
						<< "Game over, life as a pirate sucks.\n";
					break;
				}

			}

			// I was going into infinite loop here so I had to do more research and found solution in stack overflow
			// sourced from: https://stackoverflow.com/questions/54138233/switch-statement-stuck-in-an-infinite-loop-when-using-the-default-case-c
			// https://stackoverflow.com/questions/5131647/why-would-we-call-cin-clear-and-cin-ignore-after-reading-input
			default: // error handling for case statement
				cout << "Invalid choice.\n";
				cin.clear(); // clears input state and error flag
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // skips to the next new line
			}

		} while (true);

	}
	return 0; // returns 0 if program has no issues
}