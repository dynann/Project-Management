#include "score.h"

Score::Score(float width, float height)
{
    if(!font.loadFromFile("C:/Users/Dinann/OneDrive/Desktop/emptypageDEMO.otf"))
    {
    
    }
    list[0].setFont(font);
    list[0].setColor(sf::Color::Red);
    list[0].setString("Play Again");
    list[0].setPosition(sf::Vector2f(540, height / (NUMBER + 1) * 1.3));
    list[0].setCharacterSize(50);

    list[1].setFont(font);
    list[1].setColor(sf::Color::Black);
    list[1].setString("Exit");
    list[1].setPosition(sf::Vector2f(580, height / (NUMBER + 1) * 1.9));
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
		list[selectedItemIndex].setColor(sf::Color::Black);
		selectedItemIndex--;
		list[selectedItemIndex].setColor(sf::Color::Red);
	}
}

void Score::MoveDown()
{
  if (selectedItemIndex + 1 < NUMBER)
	{
		list[selectedItemIndex].setColor(sf::Color::Black);
		selectedItemIndex++;
		list[selectedItemIndex].setColor(sf::Color::Red);
	}
}
