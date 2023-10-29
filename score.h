

#pragma once
#include<SFML/Graphics.hpp>
#define NUMBER 2
class Score
{
public:
    Score(float width, float height);
    ~Score();
    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int GetItemSelected() {return selectedItemIndex;}
    private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text list[NUMBER];

private:

};

