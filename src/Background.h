#pragma once
#ifndef __BACKGROUND__
#define __BACKGROUND__
#include "NavigationObject.h"

class Background : public NavigationObject
{
public:
	// Constructor
	Background();

	// Destructor
	~Background();

	// Life Cycle functions Inherited from DisplayObject
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
private:
};

#endif /* defined (__MINE__) */
