#include "mainMenu.h"


Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("C:/Users/Dinann/OneDrive/Desktop/emptypageDEMO.otf"))
	{
		
	}
	

	menu[0].setFont(font);
	menu[0].setColor(sf::Color::Red);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(600, height / (MAX_NUMBER_OF_ITEMS + 1) * 1.3));
	menu[0].setCharacterSize(50);
       
	menu[1].setFont(font);
	menu[1].setColor(sf::Color::Black);
	menu[1].setString("Exit");
	menu[1].setPosition(sf::Vector2f(600, height / (MAX_NUMBER_OF_ITEMS + 1) * 1.8));
	menu[1].setCharacterSize(50);
	
	// texture.loadFromFile("C:/Users/Dinann/Downloads/Untitled design (2).png");
	// BackGround.setTexture(&texture);
	selectedItemIndex = 0;

	
}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
	// window.draw(BackGround);
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setColor(sf::Color::Black);
		selectedItemIndex--;
		menu[selectedItemIndex].setColor(sf::Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setColor(sf::Color::Black);
		selectedItemIndex++;
		menu[selectedItemIndex].setColor(sf::Color::Red);
	}
}