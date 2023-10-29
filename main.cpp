#include<SFML/Graphics.hpp>
#include<iostream>
#include<string>
#include<fstream>
#include<ctime>
#include<time.h>
#include "mainMenu.h"
#include "score.h"
int direction = 1;
int num = 2;
float chrono = 0;
float delay = 0.1;
// class Score_Show
// {
//    private:
//     sf::Text text;
//     sf::Font font;
//     public:
//     Score_Show(sf::Text t, sf::Font f)
//     {
//        text = t;
//        font = f;
//     }
// };

// bool check_system(int a)
// {
//      if(a==1)
//       {
//         return a;
//       }
//      else
//       {
//         return 2;
//       }
// }

int check_high_score(std::string data_score, int user_score)
{
    std::ifstream file1;
    file1.open(data_score);
    std::string data;
    while(file1.is_open())
     {
       while(file1>>data)
        {
               int a;
               a = std::stoi(data);
                if(user_score<a)
                 {
                     std::cout<<"your score : "<<user_score<<"\n";
                     std::cout<<"previous hight score : "<<a<<"\n";
                     return a;
                    
                 }
                 else if(user_score>a) 
                  {
                     std::cout<<"your high score : "<<user_score<<"\n";
                     std::cout<<"previous high score : "<<a<<"\n";
                     return user_score;
                     
                  }
        }
     } 
  file1.close();
}

struct food{
   int x;
   int y;

}bjj;
struct  snake
{
  float x;
  float y;
  
}snake[100];



bool check_system()
{
    for(int i = 4; i<200; i++)
     {
        if(snake[0].x==snake[i].x&&snake[0].y==snake[i].y)
         {
          return 1;
         }
         else
         {
          return 0;
         }
     }
   
       

} 
int display_score()
{
    
}
int display(int dscore,sf::RenderWindow& window)
{
  
  int score = 0;
  for(int i = num; i > 0; --i)
  {
     snake[i].x = snake[i - 1].x;
     snake[i].y = snake[i - 1].y;

  }
  if(direction==0)
  {
    snake[0].y += 1;
     
  }
  else if(direction==1)
  {
    snake[0].x -= 1;
    
  }
  else if(direction==2)
  {
    snake[0].x += 1;
    
  }
  else if(direction==3)
  {
    snake[0].y -= 1;
    
  }
  if((snake[0].x == bjj.x)&&(snake[0].y == bjj.y))
   {
     num++;
     dscore++;
     delay -= 0.001;
     bjj.x = rand() % 50;
     bjj.y = rand() % 40;
     for(int i = 0; i<200; i++)
     {
      if((bjj.x ==snake[i].x)&&(bjj.y==snake[i].y))
       {
         bjj.x = rand() % 50;
         bjj.y = rand() % 40;
       }
       
     }
     
     
   }

return dscore;
}


int main()
{
   
   int b;
   int dscore = 0;
   int d_score = 0;
   float size = 25;
   int vx = size*50;
   int vy = size*40;
   int vertical_line = 40;
   int horizontal_line = 50;
   sf::Clock clock;
   
   sf::Texture back;
   back.loadFromFile("C:/Users/Dinann/Desktop/bg2sdad.png");

   sf::RectangleShape re(sf::Vector2f(vx,vy));
   re.setTexture(&back);
   int return_score;
   std::string data = "C:/Users/Dinann/Desktop/la/user_high_score.txt";
   sf::Font font;
   sf::Text text;
   sf::Text text1;
   sf::Font font2;
   if(!font2.loadFromFile("C:/Users/Dinann/Downloads/VCR_OSD_MONO_1.001.ttf"))
   {
    std::cout<<"error"<<std::endl;
   }
   sf::Font font1;
   if(!font1.loadFromFile("C:/Users/Dinann/Desktop/Cakadidi (DEMO).ttf")){
    std::cout<<"error"<<std::endl;
   }
   if(!font.loadFromFile("C:/Users/Dinann/Desktop/la/coding/Geomatrix Medium.otf"))
    {
       
    }
   sf::Text snakeGame;
   text.setFont(font);
   text.setString("      Highest Score : ");
   text.setCharacterSize(25);
   text.setFillColor(sf::Color::Black); 
  //  text.setOutlineColor(sf::Color::Black);
  //  text.setOutlineThickness(2);
   text.setPosition(5,7);
   text1.setFont(font);
   text1.setPosition(45,47);
   text1.setString("Current Score : 0");
   text1.setCharacterSize(25);
   text1.setFillColor(sf::Color::Black);
  //  text1.setOutlineColor(sf::Color::Black);
  //  text1.setOutlineThickness(2);
   snakeGame.setPosition(470,180);
   snakeGame.setFillColor(sf::Color::White);
   snakeGame.setFont(font1);
   snakeGame.setString("Snake Game");
   snakeGame.setCharacterSize(70);
  //  snakeGame.setFillColor(sf::Color::Yellow);
  //  snakeGame.setOutlineColor(sf::Color::Black);
  //  snakeGame.setOutlineThickness(2);
   sf::Text Score_text;
   Score_text.setFont(font1);
   Score_text.setPosition(450, 110);
   Score_text.setString("YOU ARE DEAD");
   Score_text.setFillColor(sf::Color(40, 180, 99 ));
   Score_text.setCharacterSize(70);
   sf::Text Score_text1;
   Score_text1.setFont(font);
   Score_text1.setPosition(550, 220);

   Score_text1.setFillColor(sf::Color(40, 180, 99 ));
   Score_text1.setCharacterSize(40);
   sf::RectangleShape bsnake(sf::Vector2f(size,size));
   bsnake.setFillColor(sf::Color(255, 235, 59));
   bsnake.setOutlineColor(sf::Color::Black);
   bsnake.setOutlineThickness(2);
   sf::RectangleShape bfood(sf::Vector2f(size,size));
   bfood.setFillColor(sf::Color(46, 204, 113));
   bfood.setOutlineColor(sf::Color(97, 97, 97));
   bfood.setOutlineThickness(3);
  //  int k = food.x = rand() % vx;
  //  int l = food.y = rand() % vy;
   float increase = 20.0;
   std::srand(time(NULL));
   std::ifstream readf;       
   std::string numeber;
   readf.open(data);
    while(std::getline(readf, numeber))
     {
      text.setString(text.getString() + numeber);
     }
     readf.close();
   std::ofstream file;
   std::ofstream file1;
   int a;
   int score1 = 0;
   sf::RectangleShape sh(sf::Vector2f(15,15));
   sh.setFillColor(sf::Color::Yellow);
   sh.setOutlineColor(sf::Color::Black);
   sh.setOutlineThickness(1);
   sh.setPosition(20,30);
   sf::RenderWindow window(sf::VideoMode(vx, vy), "Snake Game", sf::Style::Close | sf::Style::Resize);
   sf::RectangleShape rec(sf::Vector2f(size,size));

   
   sf::RectangleShape food(sf::Vector2f(vx,vy));
   food.setFillColor(sf::Color::Cyan);
   rec.setFillColor(sf::Color(23, 32, 42));
   rec.setOutlineColor(sf::Color::Black);
   rec.setOutlineThickness(3);
  
   sf::Texture background;
   background.loadFromFile("C:/Users/Dinann/Desktop/la/coding/bg.png");
  //  rec.setTexture(&background);
  sf::Texture background_score;
  background_score.loadFromFile("C:/Users/Dinann/Desktop/b3.jpg");
  sf::RectangleShape shape;
  shape.setSize(sf::Vector2f(240,120));
  shape.setPosition(30,-20);
  shape.setTexture(&background_score);
  sf::RectangleShape square(sf::Vector2f(size,size));
  square.setFillColor(sf::Color(255, 235, 59));
  sf::Texture Background1;
  Background1.loadFromFile("C:/Users/Dinann/Desktop/Untitled-1.png");
  sf::RectangleShape shape1(sf::Vector2f(vx,vy));
  shape1.setPosition(0,0);
  shape1.setTexture(&Background1);
   bool GameOver = false; 
   bool process = false;
   bool Game_start = false;
   window.setFramerateLimit(144);
    Menu menu(window.getSize().x, window.getSize().y);
    Score list(window.getSize().x, window.getSize().y);
    
   
      bjj.x = rand() % 20;
      bjj.y = rand() % 20;
while(window.isOpen())
    {
      
      float time =  clock.getElapsedTime().asSeconds();
      clock.restart();
      chrono += time;
      sf::Event ve;
 
      while(window.pollEvent(ve))
      {
          
      
	
			switch (ve.type)
			{
			case sf::Event::KeyReleased:
				switch (ve.key.code)
				{
				case sf::Keyboard::Up:
					menu.MoveUp();
					break;

				case sf::Keyboard::Down:
					menu.MoveDown();
					break;

				case sf::Keyboard::Return:
					switch (menu.GetPressedItem())
					{
					case 0:
						std::cout << "Play button has been pressed" << std::endl;
                       process = true;
						break;
					case 1:
                      window.close();
						break;
					}

					break;
				}

				break;
			  case sf::Event::Closed:
				window.close();

				break;
        

			}
        
        
      }
       
      window.clear();
      window.draw(re);
      window.draw(snakeGame);
      menu.draw(window);
     
    
        // if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        // {
        //  sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        //  rec.setPosition((float)mousePos.x, (float)mousePos.y);
        // }


    if(process==true)
    {


      if(direction==1)
      {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
             {
                direction = 3;
             }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
             {
                direction = 0;
             }


      }
       else if(direction==2)
      {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
             {
                direction = 3;
             }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
             {
                direction = 0;
             }


      }
       else if(direction==0)
      {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
             {
                direction = 1;
             }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
             {
                direction = 2;
             }


      }
       else if(direction==3)
      {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
             {
                direction = 1;
             }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
             {
                direction = 2;
             }


      }
      
         if(chrono > delay)
         {
           chrono = 0 ;
           score1 = display(d_score, window);
           if(score1==1)
           {
            dscore++;
            text1.setString("Current Score : " + std::to_string(dscore));
           }
          //  GameOver = check_system();
          //  if(GameOver==true)
          //   {
          //     process = false;
          //   }
          //   else
          //   {
          //     process = true;
          //   }
           
           
            
          
         }
          
        //   window.clear();
          
         
         for(int i = 0 ; i < vertical_line; i++)
          {
              for(int j = 0; j < horizontal_line; j++){
                rec.setPosition(j*size, i*size);
                window.draw(rec);
              }
              
          }
          
         for(int i = 0; i < num ; i++)
          {
              bsnake.setPosition(snake[i].x * size, snake[i].y * size);
              window.draw(bsnake);
          }
        
          window.draw(bfood);
          window.draw(shape);
         
      bfood.setPosition(bjj.x*size, bjj.y*size);
      
     
      
      window.draw(text);
      window.draw(text1);
      for(int i = 4; i<200; i++)
    {
      if((snake[0].x == snake[i].x) && (snake[0].y == snake[i].y))
       {
         Score_text1.setString("Score : " + std::to_string(dscore));
         file.open("data.txt", std::ios_base::app);
         file<<"score : "<<dscore<<"\n";
         return_score = check_high_score(data, dscore);
         file1.open(data);
         file1<<return_score;
         file.close();
         file1.close();
         dscore = 0;
         text1.setString("Current Score : " + std::to_string(dscore));
         
             
         num = 2;
         snake[0].x = 10;
         snake[0].y = 10;
         window.clear();
         bsnake.setPosition(snake[0].x * size, snake[0].y * size);
         
         process = false;
         GameOver = true;
          

       }
      }
    }
    
     if(GameOver==true)
      {
        if(ve.type==sf::Event::KeyReleased)
         {
           if(ve.key.code==sf::Keyboard::Up)
            {
              list.MoveUp();
            }
           else if(ve.key.code==sf::Keyboard::Down)
             {
              list.MoveDown();
             }
            else if(ve.key.code==sf::Keyboard::Return)
             {
                if(list.GetItemSelected() == 0)
                 {
                    std::cout<<"hello"<<std::endl;
                    process = true;
                    GameOver = false;
                 }
                 else if(list.GetItemSelected()==1)
                 {
                   std::cout<<"buu"<<std::endl;
                 }
             }
          }
          else if(ve.type==sf::Event::Closed)
           {
            window.close();
           }
		
      window.clear();
      window.draw(Score_text1);
      window.draw(Score_text);
      list.draw(window);
      
    }
   
   
      window.display();
      
    }
 
  

 
   
  return 0;
}