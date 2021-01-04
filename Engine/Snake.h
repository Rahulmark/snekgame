#pragma once
#include "Board.h"

class Snake
{
private:
	class Segments
	{
	public:
		void InitHead(const Location& loc);
		void InitBody();
		void Follow(Segments& next);
		void MoveBy(const Location& delta_loc);
		
		void Draw(Board& Brd) const;
	private:
		Location loc;
		Color c;
	};
public:
	Snake(const Location& loc);
	void MoveBy(const Location& delta_loc);
	void Grow();
	void Draw(Board& Brd) const;
	
	
private:
	static constexpr Color HeadColor = Colors::Yellow;
	static constexpr Color BodyColor = Colors::Green;
	static constexpr int nSegmentMax = 100;
	Segments segments[nSegmentMax];
	int nSegments = 1;
};