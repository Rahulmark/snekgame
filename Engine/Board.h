#include "Graphics.h"
#include "Location.h"

class Board
{
public:
	Board(Graphics& gfx);
	void DrawCell(const Location& loc, Color c);
	int GetGridWidth();
	int GetGridHeight();
private:
	static constexpr int dimension = 20;
	static constexpr int width = 25;
	static constexpr int height = 25;
	Graphics& gfx;
};
