#include "StartScene.h"
#include <algorithm>
#include "Game.h"
#include "glm/gtx/string_cast.hpp"
#include "EventManager.h"

StartScene::StartScene()
{
	StartScene::start();
}

StartScene::~StartScene()
= default;

void StartScene::draw()
{
	drawDisplayList();
}

void StartScene::update()
{
	updateDisplayList();
}

void StartScene::clean()
{
	removeAllChildren();
}

void StartScene::handleEvents()
{
	EventManager::Instance().update();

	// Keyboard Events
	if (EventManager::Instance().isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance().quit();
	}

	if (EventManager::Instance().isKeyDown(SDL_SCANCODE_1))
	{
		TheGame::Instance().changeSceneState(PLAY_SCENE);
	}
}

void StartScene::start()
{
	/*m_Background = new Background();
	m_Background->getTransform()->position = glm::vec2(400.0f, 300.0f);
	addChild(m_Background);*/
	const SDL_Color blue = { 0, 0, 255, 255 };
	const SDL_Color red = { 255, 0, 0, 255 };
	const SDL_Color green = { 0, 255, 0, 255 };
	m_pStartLabel = new Label("START SCENE", "Consolas", 80, blue, glm::vec2(400.0f, 40.0f));
	m_pStartLabel->setParent(this);
	addChild(m_pStartLabel);

	/*m_pInstructionsLabel = new Label("Press 1 to Play", "Consolas", 40, blue, glm::vec2(400.0f, 120.0f));
	m_pInstructionsLabel->setParent(this);
	addChild(m_pInstructionsLabel);*/

	m_pInstructionsLabel = new Label("Roham Ali 101344253", "Consolas", 40, green, glm::vec2(400.0f, 100.0f));
	m_pInstructionsLabel->setParent(this);
	addChild(m_pInstructionsLabel);

	m_pInstructionsLabel = new Label("Kenneth Rodriguez 101345891", "Consolas", 40, red, glm::vec2(400.0f, 150.0f));
	m_pInstructionsLabel->setParent(this);
	addChild(m_pInstructionsLabel);

	
	
	// Start Button
	m_pStartButton = new Button();
	m_pStartButton->getTransform()->position = glm::vec2(400.0f, 400.0f);

	m_pStartButton->addEventListener(CLICK, [&]()-> void
		{
			m_pStartButton->setActive(false);
			TheGame::Instance().changeSceneState(PLAY_SCENE);
		});

	m_pStartButton->addEventListener(MOUSE_OVER, [&]()->void
		{
			m_pStartButton->setAlpha(128);
		});

	m_pStartButton->addEventListener(MOUSE_OUT, [&]()->void
		{
			m_pStartButton->setAlpha(255);
		});
	addChild(m_pStartButton);

	ImGuiWindowFrame::Instance().setDefaultGUIFunction();
}

