// David Garcia
// Main Source File
// Final Assignment OOP
// v1.0

#pragma once
class Utility
{
public:
	// Public Class Member Functions or Methods
	bool Login();
	void GameMenu();
	void Welcome();

private:
	// Private Class Data Members
	int m_choice;
	int m_fight;
};

class Hero
{
public:
	// Public Class Data Members
	int m_HealthPoints = 1000;
	int m_Experience = 0;
	int m_Silver = 0;
	int m_Level = 1;
	int m_Attack = 50;

	// Public Class Member Functions or Methods
	void SetHealthPoints(int& rHeroHP, int& rEnemyAttk);
	int GetHealthPoints() const;

	void SetExperience(int& rHeroXP, int& rEnemyXPWorth);
	int GetExperience() const;

	void SetLevelUp();
	int GetLevelUp();

	void Stats();
	void Death();
	void Reborn();

private:
};

class Enemy
{
public:
	// Public Class Data Members
	int m_TrollHealthPoints = 300;
	int m_TrollSilverDrop = 50;
	int m_TrollExperienceWorth = 25;
	int m_TrollAttack = 15;

	int m_TrollArmyHealthPoints = 10000;
	int m_TrollArmySilverDrop = 5000;
	int m_TrollArmyExperienceWorth = 2500;
	int m_TrollArmyAttack = 1500;

	// Public Class Member Functions or Methods
	void SetHealthPoints(int* EnemyHP_ptr, int* HeroAttk_ptr);
	int GetHealthPoints(int* EnemyHP_ptr) const;

private:
};

class Battles
{
public:
	// Public Class Member Functions or Methods
	void TrollBattle();
	void EpicTrollArmyBattle();

private:
};

class Inventory
{
public:
	// Public Class Data Members
	int m_choice;

	// Public Class Member Functions or Methods
	void MarketMenu();
	void Items();

private:
};
