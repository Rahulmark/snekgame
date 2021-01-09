#pragma once
#include"Snake.h"
#include<random>
class Goal 
{
public:
	Goal(std::mt19937 rng, Board& Brd, Snake& snake);
	void Respawn(std::mt19937 rng, Board& Brd, Snake& snake);
	void Draw(Board& Brd);
	const Location& GetLocation()const;
	int GetScore();
private:
	static constexpr Color c = Colors::Red;
	Location loc;
	int score = 1;
};