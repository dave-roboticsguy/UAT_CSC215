#include <iostream> // #include tells the preprocessor to include the contents of another file. Gives access to cout, cin, endl
#include <string> // Easier way to access strings
#include <random> // This header introduces random number generation facilities
#include <vector> // Includes dynamic container
#include <stdlib.h> // Used for exit() function to terminate program successfully or in failure
#include "game.h"

// This way saves time but gives you access to all elements
using namespace std; // This using directive gives direct access to the elements of the std namespace

// Instances of Classes
Hero Hero_1;
Enemy Troll_1;
Enemy TrollArmy;
Battles TrollBattle_1;
Inventory RPGInventory;

// Vector Dynamic Container with iterator and const interator
vector<string> inventory;
vector<string>::iterator invDisplayIter;
vector<string>::const_iterator invDisplayIterConst;

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
		<< "\n2: Epic Troll Army Battle"
		<< "\n3: Check Stats"
		<< "\n4: Market"
		<< "\n5: Inventory"
		<< "\n6: Reborn"
		<< "\n7: Quit Game\n";
	cout << "\nChoose number" << endl;

	cin >> m_choice;
	switch (m_choice)
	{
	case 1:
	{
		cout << "\nYou spot a nasty looking troll in the forest. Do you fight?"
			<< "\n1: Yes"
			<< "\n2: No\n";

		cin >> m_fight;
		if (m_fight == 1)
		{
			TrollBattle_1.TrollBattle();
		}
		else if (m_fight == 2)
		{
			cout << "\nYou turn your back to the troll and run away."
				<< "\nBut you slip on a rock and the troll stabs you in your neck."
				<< "\nYou die a coward's death and lose everything.\n";
			Hero_1.Death();
		}
		else
		{
			cout << "Invalid Choice." << endl;
		}
		break;
	}
	case 2:
	{
		cout << "\nYou find an army of 100 blood thirsty trolls. Do you fight?"
			<< "\n1: Yes"
			<< "\n2: No\n";

		cin >> m_fight;
		if (m_fight == 1)
		{
			TrollBattle_1.EpicTrollArmyBattle();
		}
		else if (m_fight == 2)
		{
			cout << "\nYou run away in fear for your life."
				<< "\nA troll scout spots you and throws his spear through your chest."
				<< "\nYou fall on the ground and bleed out slowly.\n";
			Hero_1.Death();
		}
		else
		{
			cout << "Invalid Choice." << endl;
		}
		break;
	}
	case 3:
	{
		Hero_1.Stats();
		break;
	}
	case 4:
	{
		RPGInventory.MarketMenu();
		break;
	}
	case 5:
	{
		RPGInventory.Items();
		break;
	}
	case 6:
	{
		Hero_1.Reborn();
		break;
	}
	case 7:
	{
		// Quitting the game
		exit(EXIT_FAILURE); // Also, exit(0) means EXIT_SUCCESS
	}
	default:
		cout << "Invalid Choice." << endl;
		cin.clear(); // clears input state and error flag
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // skips to the next new line
		break;
	}

}

// Take referenced memory data from Hero HP and Enemy Attack to Calc Remaining Hero HP
void Hero::SetHealthPoints(int& rHeroHP, int& rEnemyAttk)
{
	rHeroHP -= rEnemyAttk;
}

int Hero::GetHealthPoints() const
{
	return Hero_1.m_HealthPoints;
}

// Take referenced memory data from Hero XP and Enemy XP Worth to Calc latest Hero XP
void Hero::SetExperience(int& rHeroXP, int& rEnemyXPWorth)
{
	rHeroXP += rEnemyXPWorth;
}

int Hero::GetExperience() const
{
	return Hero_1.m_Experience;
}

// I use this after defeating a creature to check gathered Hero XP, if it's greater than threshold I lvl up.
void Hero::SetLevelUp()
{
	if (Hero_1.m_Experience >= 100)
	{
		Hero_1.m_Level++;
		Hero_1.m_Experience = 0;
		Hero_1.m_HealthPoints += 50;
		Hero_1.m_Attack += 10;
	}
}

int Hero::GetLevelUp()
{
	return Hero_1.m_Level;
}

// Just displaying stat info
void Hero::Stats()
{
	cout << "Your are level " << Hero_1.GetLevelUp() << endl;
	cout << "Your Health Points are " << Hero_1.GetHealthPoints() << endl;
	cout << "You have " << Hero_1.m_Silver << " Silver." << endl;
	cout << "You have " << Hero_1.GetExperience() << " Experience." << endl;
}

// When hero dies I wipe all Hero Data Members and clear inventory
void Hero::Death()
{
	Hero_1.m_HealthPoints = 0;
	Hero_1.m_Experience = 0;
	Hero_1.m_Silver = 0;
	Hero_1.m_Level = 0;
	inventory.clear(); // clear() function is used to remove all the elements of the vector container, thus making it size 0.
	cout << "\nYou are Dead, you must be Reborn!" << endl;
}

// After Death, Hero must be reborn starting at lvl 1 (Hardcore Mode)
void Hero::Reborn()
{
	Hero_1.m_HealthPoints = 1000;
	Hero_1.m_Experience = 0;
	Hero_1.m_Silver = 0;
	Hero_1.m_Level = 1;

	cout << "\nYou have been reborn." << endl;
}

// Take in pointer memory data to calculate remaining Enemy HP.
void Enemy::SetHealthPoints(int* EnemyHP_ptr, int* HeroAttk_ptr)
{
	*EnemyHP_ptr -= *HeroAttk_ptr;
}

int Enemy::GetHealthPoints(int* EnemyHP_ptr) const
{
	return *EnemyHP_ptr;
}

// Single Troll Enemy Battle
void Battles::TrollBattle()
{
	int* TrollHP_ptr = &Troll_1.m_TrollHealthPoints;
	int* HeroAttk_ptr = &Hero_1.m_Attack;
	do
	{
		Hero_1.SetHealthPoints(Hero_1.m_HealthPoints, Troll_1.m_TrollAttack);
		Troll_1.SetHealthPoints(TrollHP_ptr, HeroAttk_ptr);

	} while (Hero_1.m_HealthPoints > 0 && Troll_1.m_TrollHealthPoints > 0);

	if (Hero_1.m_HealthPoints > 0)
	{
		cout << "You Decimate the Troll with your whirlwind attack and chop it's head off." << endl;

		Hero_1.SetExperience(Hero_1.m_Experience, Troll_1.m_TrollExperienceWorth);
		Hero_1.SetLevelUp();

		Hero_1.m_Silver += Troll_1.m_TrollSilverDrop;

		cout << "You have " << Hero_1.GetHealthPoints() << " Health Points." << endl;
		cout << "Your XP is " << Hero_1.GetExperience() << endl;
		cout << "Your level is " << Hero_1.GetLevelUp() << endl;
		cout << "Your silver is " << Hero_1.m_Silver << endl;
	}
	else
	{
		cout << "You suck at adventure games...You let a weak level 1 troll beat you?" << endl;
		Hero_1.Death();
	}
}

// Epic Troll Army Battle of 100 Trolls
void Battles::EpicTrollArmyBattle()
{
	int* TrollArmyHP_ptr = &TrollArmy.m_TrollArmyHealthPoints;
	int* HeroAttk_ptr = &Hero_1.m_Attack;

	do
	{
		Hero_1.SetHealthPoints(Hero_1.m_HealthPoints, TrollArmy.m_TrollArmyAttack);
		TrollArmy.SetHealthPoints(TrollArmyHP_ptr, HeroAttk_ptr);

	} while (Hero_1.m_HealthPoints > 0 && TrollArmy.m_TrollArmyHealthPoints > 0); // If Hero or Enemy reaches 0, then battle loop ends.

	if (Hero_1.m_HealthPoints > 0)
	{
		cout << "You go into Berserker Mode and defeat all 100 Trolls." << endl;
		Hero_1.SetExperience(Hero_1.m_Experience, TrollArmy.m_TrollArmyExperienceWorth);
		Hero_1.SetLevelUp();
		cout << "You have " << Hero_1.GetHealthPoints() << " Health Points." << endl;
		cout << "Your XP is " << Hero_1.GetExperience() << endl;
		cout << "Your level is " << Hero_1.GetLevelUp() << endl;
	}
	else
	{
		cout << "After a few minutes your stamina is drained, "
			<< "\nyou become overwhelmed, and get chopped into pieces by the mighty Troll Army." << endl;
		Hero_1.Death();
	}
}

// Grand Bazaar, which includes menu and ability to add items to inventory using vector functions
void Inventory::MarketMenu()
{
	cout << "\nWelcome to the Grand Bazaar!!"
		<< "\nChoose your item and pay with silver.\n"
		<< "\nYou have " << Hero_1.m_Silver << "silver."
		<< "\n#: Cost	 Name"
		<< "\n1: (2500s) Great Sword"
		<< "\n2: (2100s) Battle Axe"
		<< "\n3: (2000s) Spear"
		<< "\n4: (1500s) Shield"
		<< "\n5: (800s)  Helmet"
		<< "\n6: (750s)  Armor"
		<< "\n7: (500s)  Boots"
		<< "\n8: (100s)  Healing Potion"
		<< "\n8: Exit Market Menu";

	cout << "\n\nChoose item: " << endl;
	cin >> m_choice;
	if (m_choice == 1)
	{
		if (Hero_1.m_Silver >= 2500)
		{
			inventory.push_back("Great Sword");
			Hero_1.m_Silver = Hero_1.m_Silver - 2500;

			cout << "\nYou have purchased a Great Sword." << endl;
		}
		else
		{
			cout << "\nYou don't have enough silver."
				<< "\nGo slay some monsters\n!";
		}
	}
	else if (m_choice == 2)
	{
		if (Hero_1.m_Silver >= 2100)
		{
			inventory.push_back("Battle Axe");
			Hero_1.m_Silver = Hero_1.m_Silver - 2100;

			cout << "\nYou have purchased a Battle Axe." << endl;
		}
		else
		{
			cout << "\nYou don't have enough silver."
				<< "\nGo slay some monsters\n!";
		}
	}
	else if (m_choice == 3)
	{
		if (Hero_1.m_Silver >= 2000)
		{
			inventory.push_back("Spear");
			Hero_1.m_Silver = Hero_1.m_Silver - 2000;

			cout << "\nYou have purchased a Spear." << endl;
		}
		else
		{
			cout << "\nYou don't have enough silver."
				<< "\nGo slay some monsters\n!";
		}
	}
	else if (m_choice == 4)
	{
		if (Hero_1.m_Silver >= 1500)
		{
			inventory.push_back("Shield");
			Hero_1.m_Silver = Hero_1.m_Silver - 1500;

			cout << "\nYou have purchased a Shield." << endl;
		}
		else
		{
			cout << "\nYou don't have enough silver."
				<< "\nGo slay some monsters\n!";
		}
	}
	else if (m_choice == 5)
	{
		if (Hero_1.m_Silver >= 800)
		{
			inventory.push_back("Helmet");
			Hero_1.m_Silver = Hero_1.m_Silver - 800;

			cout << "\nYou have purchased a Helmet." << endl;
		}
		else
		{
			cout << "\nYou don't have enough silver."
				<< "\nGo slay some monsters\n!";
		}
	}
	else if (m_choice == 6)
	{
		if (Hero_1.m_Silver >= 750)
		{
			inventory.push_back("Armor");
			Hero_1.m_Silver = Hero_1.m_Silver - 750;

			cout << "\nYou have purchased Armor." << endl;
		}
		else
		{
			cout << "\nYou don't have enough silver."
				<< "\nGo slay some monsters\n!";
		}
	}
	else if (m_choice == 7)
	{
		if (Hero_1.m_Silver >= 500)
		{
			inventory.push_back("Boots");
			Hero_1.m_Silver = Hero_1.m_Silver - 500;

			cout << "\n You have purchased Boots." << endl;
		}
		else
		{
			cout << "\nYou don't have enough silver."
				<< "\nGo slay some monsters\n!";
		}
	}
	else if (m_choice == 8)
	{
		if (Hero_1.m_Silver >= 100)
		{
			Hero_1.m_HealthPoints = Hero_1.m_HealthPoints + 100;
			Hero_1.m_Silver = Hero_1.m_Silver - 100;

			cout << "\n You healed 100 Health Points." << endl;
		}
		else
		{
			cout << "\nYou don't have enough silver."
				<< "\nGo slay some monsters\n!";
		}
	}

	else
	{
		cout << "Invalid Choice." << endl;
	}
}

// Basic Inventory display using FOR LOOP with iterators
void Inventory::Items()
{
	cout << "\nYour items:\n";
	for (invDisplayIterConst = inventory.begin(); invDisplayIterConst != inventory.end(); ++invDisplayIterConst)
	{
		cout << *invDisplayIterConst << endl;
	}
}