#pragma once
class Utility
{
public:
	bool Login();
	void GameMenu();

private:
	int m_choice;
	int m_fight;
};

class Hero
{
public:
	int m_HealthPoints = 1000;
	int m_Experience = 0;
	int m_Silver = 0;
	int m_Level = 1 ;
	int m_Attack = 50;

	void SetHealthPoints(int& rHeroHP, int& rEnemyAttk);
	int GetHealthPoints() const;

	void SetExperience(int& xp);
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
	int m_HealthPoints = 100;
	int m_SilverDrop = 50;
	int m_ExperienceWorth = 25;
	int m_Attack = 10;

	void SetHealthPoints(int* EnemyHP_ptr);
	int GetHealthPoints() const;
private:
};

class Battles
{
public:
	void TrollBattle();
	void EpicTrollArmyBattle();
};

class Inventory
{
public:
	int m_choice;

	void MarketMenu();
	void Items();
private:
};
