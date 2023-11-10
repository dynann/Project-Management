#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include<string>
#include<fstream>
#include<ctime>
#include<time.h>
#include<cstdlib>
#include<random>

#include "mainMenu.h"
#include "score.h"
std::uniform_int_distribution<int>axis(11,39);
std::uniform_int_distribution<int>ordinate(6,34);
std::random_device z;
   
int direction = 2;
int num = 1;
float chrono = 0;
float delay = 0.1;


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
  int x;
  int y;
  
}snake[200];


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
     delay -= 0.002;
      bjj.x = axis(z);
      bjj.y = ordinate(z);
     for(int i = 0; i<200; i++)
     {
      if((bjj.x ==snake[i].x)&&(bjj.y==snake[i].y))
       {
         
        
         
         bjj.x = axis(z);
        bjj.y = ordinate(z);
         
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
   back.loadFromFile("C:/Users/Dinann/Downloads/BACkground.png");

   sf::RectangleShape re(sf::Vector2f(vx,vy));
   re.setTexture(&back);
   int return_score;
   std::string data = "C:/Users/Dinann/OneDrive/Desktop/la - Copy (2) - Copy/high_score.txt";
   sf::Font font;
   sf::Text text;
   sf::Text text1;
   sf::Font font2;
   if(!font2.loadFromFile("C:/Users/Dinann/OneDrive/Desktop/emptypageDEMO.otf"))
   {
    std::cout<<"error"<<std::endl;
   }
   sf::Font font1;
   if(!font1.loadFromFile("C:/Users/Dinann/OneDrive/Desktop/emptypageDEMO.otf")){
    std::cout<<"error"<<std::endl;
   }
   if(!font.loadFromFile("C:/Users/Dinann/OneDrive/Desktop/emptypageDEMO.otf"))
    {
       
    }
   sf::Text snakeGame;
   text.setFont(font);
   text.setString("      Highest Score : ");
   text.setCharacterSize(25);
   text.setFillColor(sf::Color::Black); 
   text.setPosition(vx/2, vy/2);
  //  text.setOutlineColor(sf::Color::Black);
  //  text.setOutlineThickness(2);
   text.setPosition(500,7);
   text1.setFont(font);
   text1.setPosition(vx/2 - 100, 50);
   text1.setString("Current Score : 0");
   text1.setCharacterSize(25);
   text1.setFillColor(sf::Color::Black);
  //  text1.setOutlineColor(sf::Color::Black);
  //  text1.setOutlineThickness(2);
   snakeGame.setPosition(470,180);
   snakeGame.setFillColor(sf::Color::Black);
   snakeGame.setFont(font1);
   snakeGame.setString("Snake Game");
   snakeGame.setCharacterSize(70);
  //  snakeGame.setFillColor(sf::Color::Yellow);
  //  snakeGame.setOutlineColor(sf::Color::Black);
  //  snakeGame.setOutlineThickness(2);
  //snake head
   //text
   sf::Texture Text1;
   Text1.loadFromFile("C:/Users/Dinann/Downloads/Untitled design (3).png");
   
  //grass
  sf::RectangleShape Shape(sf::Vector2f(450,450));
  Shape.setTexture(&Text1);
  Shape.setPosition(380,20);
  
  sf::Texture Text2;
   Text2.loadFromFile("C:/Users/Dinann/Downloads/Add a heading.png");
   
  //grass
  sf::RectangleShape Shape1(sf::Vector2f(225,225));
  Shape1.setTexture(&Text2);
  Shape1.setPosition(520,360);
  sf::RectangleShape Shape2(sf::Vector2f(225,225));
  Shape2.setTexture(&Text2);
  Shape2.setPosition(520,530);
  
  
 sf::RectangleShape Shape3(sf::Vector2f(500,500));
  Shape3.setTexture(&Text1);
  Shape3.setPosition(380,-60);  
  

  sf::Texture Text3;
   Text3.loadFromFile("C:/Users/Dinann/Downloads/bb.png");

  sf::RectangleShape Shape4(sf::Vector2f(290,290));
  Shape4.setTexture(&Text3);
  Shape4.setPosition(485,330);  

  sf::RectangleShape Shape5(sf::Vector2f(290,290));
  Shape5.setTexture(&Text3);
  Shape5.setPosition(485,525);




  
  sf::Texture grass;
  grass.loadFromFile("C:/Users/Dinann/Downloads/grass.png");
  
  
   sf::Text Score_text;
   Score_text.setFont(font1);
   Score_text.setPosition(430, 110);
   Score_text.setString("YOU ARE DEAD");
   Score_text.setFillColor(sf::Color::Black);
   Score_text.setCharacterSize(70);
   sf::Text Score_text1;
   Score_text1.setFont(font);
   Score_text1.setPosition(550, 220);
   //snake texturesha
   sf::Texture snakeTexture;
   snakeTexture.loadFromFile("C:/Users/Dinann/Downloads/Untitled design (13).png");
   Score_text1.setFillColor(sf::Color::Black);
   Score_text1.setCharacterSize(40);
   

   sf::RectangleShape bsnake(sf::Vector2f(size,size));
   bsnake.setTexture(&snakeTexture);
   
  //  bsnake.setFillColor(sf::Color(255, 235, 59));
  //  bsnake.setOutlineColor(sf::Color::Black);
  //  bsnake.setOutlineThickness(2);

  //snake tail 
  sf::Texture sTail;
  sTail.loadFromFile("C:/Users/Dinann/Downloads/snakehead W direction (3).png");
  sf::RectangleShape btail(sf::Vector2f(24,24));
  btail.setTexture(&sTail);
   
   sf::RectangleShape bfood(sf::Vector2f(25,25));
  //  bfood.setFillColor(sf::Color(46, 204, 113));
  //  bfood.setOutlineColor(sf::Color(97, 97, 97));
  //  bfood.setOutlineThickness(3);
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
   
  
   sf::Texture background;
   background.loadFromFile("C:/Users/Dinann/Downloads/BACkground.png");
  //  rec.setTexture(&background);
  rec.setTexture(&background);
  sf::Texture background_score;
  background_score.loadFromFile("C:/Users/Dinann/Downloads/bb1 (1).png");
  sf::RectangleShape shape;
  shape.setSize(sf::Vector2f(300,300));
  shape.setPosition(vx/2 - 170,-110);
  shape.setTexture(&background_score);
  sf::RectangleShape square(sf::Vector2f(size,size));
  square.setFillColor(sf::Color(255, 235, 59));
  sf::Texture Background1;
  Background1.loadFromFile("C:/Users/Dinann/Downloads/BACkground.png");
  sf::RectangleShape shape1(sf::Vector2f(vx,vy));
  shape1.setPosition(0,0);
  shape1.setTexture(&Background1);
  sf::RectangleShape wall(sf::Vector2f(24.5*32,size));
  wall.setFillColor(sf::Color::Green);
  sf::RectangleShape wall1(sf::Vector2f(25.1*30,size));
  wall.setFillColor(sf::Color::Green);
  sf::RectangleShape wall2(sf::Vector2f(size,25.7*31));
  wall.setFillColor(sf::Color::Green);
  sf::RectangleShape wall3(sf::Vector2f(size,25.7*31));
  wall.setFillColor(sf::Color::Green);
  sf::RectangleShape Wall(sf::Vector2f(820,831));
  sf::Texture WallTex;
  WallTex.loadFromFile("C:/Users/Dinann/Downloads/grass2.png");
  Wall.setTexture(&WallTex);
  Wall.setPosition(vx/5.5,vy/11.7);
  sf::Text Pause;
  Pause.setFont(font1);
  Pause.setFillColor(sf::Color::Red);
  Pause.setCharacterSize(70);
  Pause.setString("Pause!");
  Pause.setPosition(vx/2 - 50, vy/2 - 25);
  snake[0].x = 12;
  snake[0].y = 10;
  sf::Texture apple;
  apple.loadFromFile("C:/Users/Dinann/Downloads/Untitled design (12).png");
  bfood.setTexture(&apple);


  sf::SoundBuffer effect;
  effect.loadFromFile("C:/Users/Dinann/Downloads/Menu Game Button Click Sound Effect.mp3");  
  sf::Sound soundEffect;
 

   bool GameOver = false; 
   bool process = false;
   bool Game_start = false;
   window.setFramerateLimit(144);
    Menu menu(window.getSize().x, window.getSize().y);
    Score list(window.getSize().x, window.getSize().y);
      
   
      bjj.x = axis(z);
      bjj.y = ordinate(z);
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
         case sf::Event::TextEntered:
              if(ve.text.unicode<128)
              {
                
               char a;
            
                a = ve.text.unicode;
                std::cout<<"text entered "<< a << '\n';
                //rec.setPosition(a,a);
                if(a == 'p')
                {
                  Game_start = true;
                  process = false;
                }
                else if(a=='c')
                {
                  Game_start = false;
                  process = true;
                }
                break;
              }
			  case sf::Event::Closed:
				window.close();

				break;
        

			}
        
        
      }
       
      window.clear();
      window.draw(re);
      window.draw(Shape);
      window.draw(Shape1);
      window.draw(Shape2);
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
          
       window.clear();
          
         
         for(int i = 0 ; i < vertical_line; i++)
          {
              for(int j = 0; j < horizontal_line; j++){
                rec.setPosition(j*size, i*size);
                window.draw(rec);
              }
              
          }
          
          
          window.draw(Wall);
          window.draw(shape);
       
             for(int i = 0; i < num ; i++)
                {
               
                      
                     bsnake.setPosition(snake[i].x * size, snake[i].y * size);
                     window.draw(bsnake);
               }
       
         
         
            wall.setPosition(9.37 * size,3.7*size);
            wall1.setPosition(10.3*size, 35.3*size);
            wall2.setPosition(9.7*size, 4.7*size);
            wall3.setPosition(40.3*size,4.7*size);
            
            
         

         
          
          
          window.draw(bfood);
          

          

      
      bfood.setPosition(bjj.x*25, bjj.y*25);
      
     
      
      window.draw(text);
      window.draw(text1);
  
      
      if(bsnake.getGlobalBounds().intersects(wall.getGlobalBounds()))
     {
          Score_text1.setString("Score : " + std::to_string(dscore));
          file.open("C:/Users/Dinann/OneDrive/Desktop/la - Copy (2) - Copy/user_score.txt", std::ios_base::app);
          file<<"score : "<<dscore<<"\n";
          return_score = check_high_score(data, dscore);
          file1.open(data);
          text.setString()
          file1<<return_score; 
          text.setString()
          file.close();
          file1.close();
          dscore = 0;
          text1.setString("Current Score : " + std::to_string(dscore));
          
          num = 1;
          snake[0].x = 25;
          snake[0].y = 20;
          window.clear();
          bsnake.setPosition(snake[0].x * size, snake[0].y * size);
          delay = 0.1;
          process = false;
          GameOver = true;
     }
     if(bsnake.getGlobalBounds().intersects(wall1.getGlobalBounds()))
     {
          Score_text1.setString("Score : " + std::to_string(dscore));
          file.open("C:/Users/Dinann/OneDrive/Desktop/la - Copy (2) - Copy/user_score.txt", std::ios_base::app);
          file<<"score : "<<dscore<<"\n";
          return_score = check_high_score(data, dscore);
          file1.open(data);
          file1<<return_score;
          file.close();
          file1.close();
          dscore = 0;
          text1.setString("Current Score : " + std::to_string(dscore));
          num = 1;
          snake[0].x = 25;
          snake[0].y = 20;
          window.clear();
          bsnake.setPosition(snake[0].x * size, snake[0].y * size);
          delay = 0.1;
          process = false;
          GameOver = true;
     }
     if(bsnake.getGlobalBounds().intersects(wall2.getGlobalBounds()))
     {
            Score_text1.setString("Score : " + std::to_string(dscore));
          file.open("C:/Users/Dinann/OneDrive/Desktop/la - Copy (2) - Copy/user_score.txt", std::ios_base::app);
          file<<"score : "<<dscore<<"\n";
          return_score = check_high_score(data, dscore);
          file1.open(data);
          file1<<return_score;
          file.close();
          file1.close();
          dscore = 0;
          text1.setString("Current Score : " + std::to_string(dscore));
          num = 1;
          snake[0].x = 25;
          snake[0].y = 20;
          window.clear();
          bsnake.setPosition(snake[0].x * size, snake[0].y * size);
          delay = 0.1;
          process = false;
          GameOver = true;
     }
     if(bsnake.getGlobalBounds().intersects(wall3.getGlobalBounds()))
     {
            Score_text1.setString("Score : " + std::to_string(dscore));
          file.open("C:/Users/Dinann/OneDrive/Desktop/la - Copy (2) - Copy/user_score.txt", std::ios_base::app);
          file<<"score : "<<dscore<<"\n";
          return_score = check_high_score(data, dscore);
          file1.open(data);
          file1<<return_score;
          file.close();
          file1.close();
          dscore = 0;
          text1.setString("Current Score : " + std::to_string(dscore));
          num = 1;
          delay = 0.1;
          snake[0].x = 25;
          snake[0].y = 20;
          window.clear();
          bsnake.setPosition(snake[0].x * size, snake[0].y * size);
          
          process = false;
          GameOver = true;
     }
      for(int i = 4; i<200; i++)
      {
        if((snake[0].x == snake[i].x) && (snake[0].y == snake[i].y) && snake[i].x != 0 && snake[i].y != 0)
        {
          for (int j = 0; j < 200; j++){
           snake[j].x = 0;
           snake[j].y = 0;
          }

          std::cout<<snake[i].x<<std::endl;
          std::cout<<snake[i].y<<std::endl;
          Score_text1.setString("Score : " + std::to_string(dscore));
          file.open("C:/Users/Dinann/OneDrive/Desktop/la - Copy (2) - Copy/user_score.txt", std::ios_base::app);
          file<<"score : "<<dscore<<"\n";
          return_score = check_high_score(data, dscore);
          file1.open(data);
          file1<<return_score;
          file.close();
          file1.close();
          dscore = 0;
          text1.setString("Current Score : " + std::to_string(dscore));
          delay = 0.1;
          num = 1;
          snake[0].x = 25;
          snake[0].y = 20;
          window.clear();
          bsnake.setPosition(snake[0].x * size, snake[0].y * size);
          process = false;
          GameOver = true;
            

        }
        
      }
    }
    if(Game_start==true)
     {
      
       window.clear();
        for(int i = 0 ; i < vertical_line; i++)
          {
              for(int j = 0; j < horizontal_line; j++)
              {
                rec.setPosition(j*size, i*size);
                window.draw(rec);
              }
              
          }
          window.draw(Wall);
           window.draw(shape);

         for(int i = 0; i < num ; i++)
          {
              bsnake.setPosition(snake[i].x * size, snake[i].y * size);
              window.draw(bsnake);
          }

          
        
          window.draw(bfood);
          
          

         
      bfood.setPosition(bjj.x*size, bjj.y*size);
      
     
      
     
     
      window.draw(text);
      window.draw(text1);
    
      window.draw(Pause);    
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
      window.draw(shape1);
      window.draw(Shape3);
      window.draw(Shape4);
      window.draw(Shape5);
      window.draw(Score_text1);
      window.draw(Score_text);
     
      list.draw(window);
      
      
      
    }
   
      window.display();
      
    }
 
  

 
   
  return 0;
}