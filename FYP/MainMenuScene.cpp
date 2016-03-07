#include "MainMenuScene.h"

bool MainMenuScene::instanceFlag = false;
MainMenuScene* MainMenuScene::instance = NULL;

MainMenuScene* MainMenuScene::GetInstance()
{
	if (!instanceFlag)
	{
		instance = new MainMenuScene();
		instanceFlag = true;
		return instance;
	}
	else
	{
		return instance;
	}
}

void MainMenuScene::Init()
{
	if (!m_font.loadFromFile("Assets/Fonts/VINERITC.TTF")) {
		//handle error
	}
	m_menu[0].setFont(m_font);
	m_menu[0].setColor(sf::Color::Cyan);
	m_menu[0].setString("Play");
	m_menu[0].setPosition(sf::Vector2f(100 / 2, 400 / (NUM_OF_ELEMENTS + 1) * 1));

	m_menu[1].setFont(m_font);
	m_menu[1].setColor(sf::Color::White);
	m_menu[1].setString("Settings");
	m_menu[1].setPosition(sf::Vector2f(100 / 2, 400 / (NUM_OF_ELEMENTS + 1) * 2));

	m_menu[2].setFont(m_font);
	m_menu[2].setColor(sf::Color::White);
	m_menu[2].setString("Exit");
	m_menu[2].setPosition(sf::Vector2f(100 / 2, 400 / (NUM_OF_ELEMENTS + 1) * 3));

	m_selectedItemIndex = 0;
}

void MainMenuScene::Update()
{
	if (InputManager::GetInstance()->IsKeyReleased(sf::Keyboard::W) || InputManager::GetInstance()->IsKeyReleased(sf::Keyboard::Up))
	{
		MoveUp();
	}
	else if (InputManager::GetInstance()->IsKeyReleased(sf::Keyboard::S) || InputManager::GetInstance()->IsKeyReleased(sf::Keyboard::Down))
	{
		MoveDown();
	}

	if (InputManager::GetInstance()->IsKeyReleased(sf::Keyboard::Return) || InputManager::GetInstance()->IsKeyReleased(sf::Keyboard::Space))
	{
		switch (GetPressedItem())
		{
		case 0:
			cout << "PLAY PRESSED" << endl;
			//SceneManager::GetInstance()->set("GAME");
			break;
		case 1:
			cout << "SETTINGS PRESSED" << endl;
			//SceneManager::GetInstance()->set("MAINMENU");
			break;
		case 2:
			cout << "EXIT PRESSED" << endl;
			//SceneManager::GetInstance()->set("MAINMENU");
			break;
		}
	}
}

void MainMenuScene::Draw(sf::RenderWindow &win)
{
	for (int i = 0; i < NUM_OF_ELEMENTS; i++) {
		win.draw(m_menu[i]);
	}
}

void MainMenuScene::MoveUp()
{
	if (m_selectedItemIndex - 1 >= 0) {
		m_menu[m_selectedItemIndex].setColor(sf::Color::White);
		m_selectedItemIndex--;
		m_menu[m_selectedItemIndex].setColor(sf::Color::Cyan);
	}
}

void MainMenuScene::MoveDown()
{
	if (m_selectedItemIndex + 1 < NUM_OF_ELEMENTS) {
		m_menu[m_selectedItemIndex].setColor(sf::Color::White);
		m_selectedItemIndex++;
		m_menu[m_selectedItemIndex].setColor(sf::Color::Cyan);
	}
}

int MainMenuScene::GetPressedItem() { return m_selectedItemIndex; }