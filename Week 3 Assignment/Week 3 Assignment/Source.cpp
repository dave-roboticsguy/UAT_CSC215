// A little adventure with C++

// # Is a preprocessor directive and runs before the compiler does
// #include tells the preprocessor to include the contents of another file
#include <iostream> // Gives access to cout, cin, endl
#include <vector> // Inlcude dynamic array
#include <string> // Easier way to access strings
#include <random> // This header introduces random number generation facilities
#include <stdlib.h> // Used for exit() function to terminate program successfully or in failure
#include <windows.h> // SetConsoleTextAttribute function to change color

// This way saves time but gives you access to all elements
using namespace std; // This using directive gives direct access to the elements of the std namespace

// prototypes are a declaration of a function
// C++ does not require prototypes, but can be good practice for:
// Better organization, prevents errors from reorganization, allows for default arguments that are always used
void welcome();
void gameLoop();
string codeWords();
string jumbleString(string toJumble);

const int MAX_WRONG = 3; //Global constant, Max # of incorrect guesses allowed

int main() // main function
{
	welcome(); // welcome function
	gameLoop(); // loop to run my game
	return 0;
}

void welcome()
{
	// SetConsoleTextAttribute changes the attribute for new characters that you write to the console, but doesn't affect existing contents of the console
	// GetStdHandle function provides a mechanism for retrieving the standard input (STDIN), standard output (STDOUT), and standard error (STDERR) handles associated with a process.
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "\tWelcome Agent to the Code Breaker Training Simulation!\n" // new line and tab
		<< "\nWe need your help in decrypting the enemy intel.\n"
		<< "You only have 3 chances before this program self destructs.\n"
		<< "Godspeed!\n\n";
}

void gameLoop()
{
	int wrong = 0;
	string userGuess;

	string toJumble = codeWords(); // I take return value of codeWords() and assign it to toJumble
	const string RANDOMWORD = toJumble; // I create a copy of the toJumble to use later to compare against user input
	const string ENCRYPTEDWORD = jumbleString(toJumble);// I take the encryped word from jumbleString() and assign it to ENCRYPTEDWORD
	cout << "Encrypted Word: " << ENCRYPTEDWORD << "\n";

	// LOGICAL AND Comparison
	while ((wrong < MAX_WRONG) && (userGuess != RANDOMWORD)) // I check both the retry attempts is < 3 and that the user hasn't guessed the word
	{
		cout << "\n\nYou have " << (MAX_WRONG - wrong) // Show amount of retrys left
			<< " chances left."
			<< "\nEnter your guess" << endl;
		cin >> userGuess;

		// toupper sourced from https://en.cppreference.com/w/cpp/algorithm/transform
		// The following code uses transform to convert a string in place to uppercase using the std::toupper function and 
		// then transforms each char to its ordinal value:
		transform(userGuess.begin(), userGuess.end(), userGuess.begin(), ::toupper);
		if (userGuess == RANDOMWORD) // Use this to break out of while loop
		{
			// nothing needed in here :)
		}
		else
		{
			cout << "Wrong, " << userGuess << " isn't correct." << endl;
			++wrong; // increments counter for wrong integer.
		}
	}
	if (wrong == MAX_WRONG) // Logical equal to operator, if the counter reaches the max wrong, mission is a failure
	{
		cout << "\nYou failed the mission!"
			<< "\nThis program will now self destruct." << endl;
		exit(EXIT_FAILURE); // Terminates the program with a failure code
	}
	else
	{
		cout << "\nMission Success!" << endl;
	}
	cout << "\nThe word was " << RANDOMWORD << endl;
}

string codeWords()
{
	string randWord; //declare randWord as string
	// Vector is a dynamic array
	vector<string>codeWords; // push_back inserts the string to the end each time
	codeWords.push_back("ALPHA");
	codeWords.push_back("BRAVO");
	codeWords.push_back("CHARLIE");
	codeWords.push_back("DELTA");
	codeWords.push_back("ECHO");
	codeWords.push_back("FOXTROT");
	codeWords.push_back("GOLF");
	codeWords.push_back("HOTEL");
	codeWords.push_back("INDIA");
	codeWords.push_back("JULIETT");

	static mt19937 gen(random_device{}()); // 32-bit Mersenne Twister algorithm by Matsumoto and Nishimura, 1998
	shuffle(codeWords.begin(), codeWords.end(), gen); // Use algo to shuffle the whole array, begin() is start point and end() is endpoint
	randWord = codeWords[0]; // I take the first word from the shuffled array and assign it to randWord

	// This was so easy but took me forever to come up with this.
	// I spend several hours trying to get the struct function to work so i can pass both the word and hint into the vector.
	// I was unsuccessful in getting the struct to work but realized I can just use the first letter of my word as hint.
	cout << randWord.front() << " is your hint\n" << endl;

	return randWord;
}

string jumbleString(string toJumble)
{
	// I have been using this from previous week 1 and week 2 assignments, great algo for random
	static mt19937 gen(random_device{}());
	shuffle(toJumble.begin(), toJumble.end(), gen);

	return toJumble;
}