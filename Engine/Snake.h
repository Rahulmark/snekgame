#pragma once
#include "Board.h"
#include "Location.h"
#include <random>

class Snake
{
private:
	class Segment
	{
	public:
		void InitHead(const Location& in_loc);
		void InitBody(Color c);
		void Follow(const Segment& next);
		void MoveBy(const Location& delta_loc);
		void Draw(Board& brd) const;
		const Location& GetLocation() const;

	private:
		Location loc;
		Color c;
		
	};
public:
	Snake(const Location& loc);
	void MoveBy(const Location& delta_loc);
	Location GetHeadLocation(const Location& delta_loc) const;
	void Grow();
	void Draw(Board& brd) const;
	bool IsInTileExceptEnd(const Location& target)const;
	bool IsInTile(const Location& target)const;


private:
	
	static constexpr Color headColor = Colors::Blue;
	static constexpr int nSegmentsMax = 100;
	Segment segments[nSegmentsMax];
	int nSegments = 1;
};