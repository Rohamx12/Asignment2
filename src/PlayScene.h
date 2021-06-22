#pragma once
#ifndef __PLAY_SCENE__
#define __PLAY_SCENE__

#include "Heuristic.h"
#include "Mine.h"
#include "Scene.h"
#include "StarShip.h"
#include "Target.h"
#include "Tile.h"
#include "Background.h"
#include "CollisionManager.h"
#include "ship.h"

class PlayScene : public Scene
{
public:
	PlayScene();
	~PlayScene();

	// Scene LifeCycle Functions
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;
	
	void m_moveShip();
	
private:
	// IMGUI Function
	void GUI_Function();
	std::string m_guiTitle;
	Label* m_pStartLabe2{};
	glm::vec2 m_mousePosition;

	// Game Objects
	Target* m_pTarget;
	StarShip* m_pStarShip;
	Background* m_Background;
	
	// mines
	int m_mineNum = 8;
	std::vector<Mine* > m_pMines;
	void m_buildMines();
	void m_eraseMines();
	void m_spawnMines();

	
	void moveStarShip() const;
	
	// UI Controls
	bool m_bToggleGrid;
	
	// Pathfinding Objects and Functions
	
	std::vector<Tile*> m_pGrid; // Grid of Tile pointers
	bool m_isGridEnabled;
	
	void m_buildGrid();
	void m_computeTileCosts();

	//TODO:
	void m_findShortestPath();
	void m_displayPathList();
	
	 void m_moveShipAlongPath();
	
	 Tile* min_tile; // temp Tile pointer - initialized as nullptr
	
	int m_spawnObject(NavigationObject* object);
	void m_spawnStarShip();
	void m_spawnTarget();
	
	Ship* m_pShip{};
	int moveCounter;

	bool m_shipIsMoving;
	
	void m_setGridEnabled(bool state);
	bool m_getGridEnabled() const;

	// convenience functions
	Tile* m_getTile(int col, int row);
	Tile* m_getTile(glm::vec2 grid_position);
	void m_resetGrid();

	

	

	// heuristic
	Heuristic m_currentHeuristic;

	// potential data structures
	 std::vector<Tile*> m_pOpenList;
	 std::vector<Tile*> m_pClosedList;
	 std::vector<Tile*> m_pPathList;
	 std::vector<Tile* > neighbour_list;
};

#endif /* defined (__PLAY_SCENE__) */