#include "Background.h"
#include "TextureManager.h"

Background::Background()
{
	TextureManager::Instance().load("../Assets/textures/Background.png", "Background");

	auto size = TextureManager::Instance().getTextureSize("Background");
	setWidth(size.x);
	setHeight(size.y);
	
	setType(BACKGROUND);
}

Background::~Background()
= default;

void Background::draw()
{
	// alias for x and y
	const auto x = getTransform()->position.x;
	const auto y = getTransform()->position.y;

	// draw the starship
	TextureManager::Instance().draw("Background", x, y, 0, 255, true);
}

void Background::update()
{
}

void Background::clean()
{
}

