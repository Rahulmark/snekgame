#include "Snake.h"

Snake::Snake(const Location& loc)
{
	segments[0].InitHead(loc);
}

void Snake::MoveBy(const Location& delta_loc)
{
	for (int i = nSegments - 1;i > 0;i--)
	{
		segments[i].Follow(segments[i - 1]);
	}
	segments[0].MoveBy(delta_loc);

}

void Snake::Grow()
{
	if (nSegments < nSegmentMax)
	{
		nSegments++;
	}
}

void Snake::Draw(Board& Brd) const
{
 	for (int i = 0;i < nSegments;++i)
	{
		segments[i].Draw(Brd);
	}
}



void Snake::Segments::InitHead(const Location& in_loc)
{
	loc = in_loc;
	Color c = HeadColor;
}

void Snake::Segments::InitBody()
{
	Color c = BodyColor;
}

void Snake::Segments::Follow(Segments& next)
{
	loc = next.loc;
}

void Snake::Segments::MoveBy(const Location& delta_loc)
{
	loc.Add(delta_loc);
}

void Snake::Segments::Draw(Board& Brd) const
{
	Brd.DrawCell(loc, c);
}
