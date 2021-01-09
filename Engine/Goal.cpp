#include "Goal.h"

Goal::Goal(std::mt19937 rng, Board & Brd, Snake & snake)
{
	Respawn(rng, Brd, snake);
}

void Goal::Respawn(std::mt19937 rng, Board & Brd, Snake & snake)
{
	std::uniform_int_distribution<int> xDist(0, Brd.GetGridWidth() - 1);
	std::uniform_int_distribution<int> yDist(0, Brd.GetGridHeight() - 1);
	Location newloc;
	do {
		newloc.x = xDist(rng);
		newloc.y = yDist(rng);
		
	} while (snake.IsInTile(newloc));
	loc = newloc;
	;
}

void Goal::Draw(Board & Brd)
{
	Brd.DrawCell(loc, c);
	++score;
}

const Location & Goal::GetLocation() const
{
	return loc;
}

int Goal::GetScore()
{
	return score;
}
