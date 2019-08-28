#include "Block.h"
#include <random>
void Block::InitBlock(float _height)
{
	height = _height;
}

void Block::DrawBlockUp(Graphics & gfx)
{
	const int x_int = (int)x;
	const int y_int = (int)y;
	if (x + width > Graphics::ScreenWidth)
	{
		int widthTemp = Graphics::ScreenWidth;
		gfx.DrawRect(x_int, y_int, widthTemp, height, Colors::Green);
	}
	else
	{
		gfx.DrawRectDim(x_int, y_int, width, height, Colors::Green);
	}
}

void Block::DrawBlockDown(Graphics & gfx)
{
	const int x_int = (int)x;
	const int y_int = (int)y;
	y = height;
	
	if (x + width > Graphics::ScreenWidth)
	{
		int widthTemp = Graphics::ScreenWidth;
		gfx.DrawRect(x_int, y_int, widthTemp, Graphics::ScreenHeight, Colors::Green);
	}
	else
	{
		gfx.DrawRect(x_int, y_int, x+width, Graphics::ScreenHeight, Colors::Green);
	}
}

void Block::MoveBlock()
{
	x -= blockMove;
}

void Block::BlockClamp()
{
	if (x <= 0.0f)
	{
		x = 0.0f;
		width -= blockMove;
	}
	if (width <= 0.0f)
	{
		width = initWidth;
		x = Graphics::ScreenWidth;
		Block::~Block();
		//regenerate = true;
	}
}

bool Block::CollusionDetect(Bird bird)
{
	int blockHeight = y + height;
	int blockWidth = x + width;

	return
		bird.BirdXSize() >= x &&
		bird.GetBirdX()  <  blockWidth &&
		bird.BirdYSize() >= y &&
		bird.GetBirdY()  <  blockHeight;
}

bool Block::GetRegenerate()
{
	return regenerate;
}

void Block::DeniedRegenerate()
{
	regenerate = false;
}

float Block::getBlockWidth()
{
	return width;
}

float Block::GetX()
{
	return x;
}

Block::~Block()
{
	regenerate = true;
	x = Graphics::ScreenWidth;
}
