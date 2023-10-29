#include "score.h"

Score::Score(float width, float height)
{
    if(!font.loadFromFile("C:/Users/Dinann/Desktop/Cakadidi (DEMO).ttf"))
    {
       //handle
    }
    list[0].setFont(font);
    list[0].setColor(sf::Color::Red);
    list[0].setString("Play Again");
    list[0].setPosition(sf::Vector2f(540, height / (NUMBER + 1) * 1));
    list[0].setCharacterSize(50);

    list[1].setFont(font);
    list[1].setColor(sf::Color::White);
    list[1].setString("Exit");
    list[1].setPosition(sf::Vector2f(600, height / (NUMBER + 1) * 1.5));
    list[1].setCharacterSize(50);
    selectedItemIndex = 0;
}

Score::~Score()
{

}
void Score::draw(sf::RenderWindow &window)
{
       for(int i = 0; i<NUMBER; i++)
        {
           window.draw(list[i]);
        }
}
void Score::MoveUp()
{
     if (selectedItemIndex - 1 >= 0)
	{
		list[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex--;
		list[selectedItemIndex].setColor(sf::Color::Red);
	}
}

void Score::MoveDown()
{
  if (selectedItemIndex + 1 < NUMBER)
	{
		list[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex++;
		list[selectedItemIndex].setColor(sf::Color::Red);
	}
}
