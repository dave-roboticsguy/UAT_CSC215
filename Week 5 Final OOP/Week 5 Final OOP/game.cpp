#include <iostream> // #include tells the preprocessor to include the contents of another file. Gives access to cout, cin, endl
#include <string> // Easier way to access strings
#include <random> // This header introduces random number generation facilities
#include <stdlib.h> // Used for exit() function to terminate program successfully or in failure
#include "game.h"

using namespace std;

Enemy Troll_1;
Hero Hero_1;
Battles TrollBattle_1;

bool Utility::Login()
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

void Utility::GameMenu()
{
	cout << "\nGame Menu\n"
		<< "\n1: Troll Battle"
		<< "\n2: Check Stats"
		<< "\n3: Market"
		<< "\n4: Quit\n";
	cout << "\nChoose number" << endl;

	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		cout << "\nYou spot a nasty looking troll in the forest. Do you fight?"
			<< "\n1: Yes"
			<< "\n2: No\n";

		cin >> fight;
		if (fight == 1)
		{
			TrollBattle_1.TrollBattle();
		}
		else if (fight == 2)
		{
			cout << "\nYou turn your back to the troll and run away."
				<< "\nBut you slip on a rock and the troll stabs you in your neck."
				<< "\nYou die a coward's death.\n";
		}

	}
	case 2:
	{


	}
	case 3:
	{

	}
	case 4:
	{
		break;
	}
	default:
		break;
	}

}

void Hero::SetHealthPoints(int& hp)
{
	hp = Hero_1.m_HealthPoints - Troll_1.m_Attack;
}

int Hero::GetHealthPoints() const
{
	return Hero_1.m_HealthPoints;
}

void Hero::SetExperience(int& xp)
{
	xp = Hero_1.m_Experience + Troll_1.m_ExperienceWorth;
}

int Hero::GetExperience() const
{
	return Hero_1.m_Experience;
}

void Hero::SetLevelUp()
{
	if (Hero_1.m_Experience >= 100)
	{
		Hero_1.m_Level++;
		Hero_1.m_Experience = 0;
	}
}

int Hero::GetLevelUp()
{
	return Hero_1.m_Level;
}

void Enemy::SetHealthPoints(int* hp_ptr)
{
	*hp_ptr = Troll_1.m_HealthPoints - Hero_1.m_Attack;
}

int Enemy::GetHealthPoints() const
{
	return Troll_1.m_HealthPoints;
}

void Battles::TrollBattle()
{
	int* TrollHP_ptr = &Troll_1.m_HealthPoints;
	do
	{
		Hero_1.SetHealthPoints(Hero_1.m_HealthPoints);
		Troll_1.SetHealthPoints(TrollHP_ptr);

	} while (Hero_1.m_HealthPoints > 0 && Troll_1.m_HealthPoints > 0);

	if (Hero_1.m_HealthPoints > 0)
	{
		cout << "You Decimate the Troll with your whirlwind attack and chop it's head off." << endl;
		Hero_1.SetExperience(Hero_1.m_Experience);
		Hero_1.SetLevelUp();
		cout << "You have " << Hero_1.GetHealthPoints() << " Health Points." << endl;
		cout << "Your XP is " << Hero_1.GetExperience() << endl;
		cout << "Your level is " << Hero_1.GetLevelUp() << endl;

	}
	else
	{
		cout << "You suck at adventure games...You let a weak level 1 troll beat you?" << endl;
	}

}
