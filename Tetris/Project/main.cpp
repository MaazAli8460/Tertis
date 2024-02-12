/* PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)
 * You don't need to change anything in the driver code/main function except the part(s) where instructed.
 * You are expected to define your functionalities in the "functionality.h" header and call them here in the instructed part(s).
 * The game is started with a small box, you need to create other possible in "pieces.h" file in form of array.
    E.g., Syntax for 2 pieces, each having four coordinates -> int Pieces[2][4];
 * Load the images into the textures objects from img directory.
 * Don't make any changes to the "utils.h" header file except for changing the coordinate of screen or global variables of the game.
 * SUGGESTION: If you want to make changes in "utils.h", do it once you complete rest of the functionalities.
 * TIP: You can study SFML for drawing scenes, sprites and window.
 * */
#include<iostream>
#include<fstream>
#include <sstream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include "utils.h"
#include "pieces.h"
#include "functionality.h"
using namespace sf;
int main(){


    srand(time(0));
    Texture obj1, obj2, obj3, obj4;
    
    
    
    obj4.loadFromFile("tetrisimg.jpg");
    Sprite menubg(obj4);
   
    RenderWindow window(VideoMode(320, 480), title);
    
    obj3.loadFromFile("img/frame.png");
    obj1.loadFromFile("img/tiles.png");  
    obj2.loadFromFile("img/background.png");
    /*
        Load "frames.png","tiles.png" and "background.png" for Texture objects
    */
    Sprite bomb(obj1), sprite(obj1), background(obj2), frame(obj3);
    float timer=0;
    int level=1;
    float delay=0;
    int score=0;
    bool gamestate=false;
    menu(timer,menubg,level,delay,score);			//menu ftn
    Music music;						//creates music file to be played
    if(!music.openFromFile("Tetris.ogg"))
    std::cout<<"\nError";
    music.setLoop(true);
    music.play();
    
    sf::  SoundBuffer buffer;
    if(!buffer.loadFromFile("se_game_match.wav"))
    std::cout<<"\nError"<<std::endl;
    sf::Sound sound;
    sound.setBuffer(buffer);
    	
    int delta_x=0, colorNum=1;
    int var=10;		
    bool lineclear=0,rotate=0;//for rotation and line clear
    bool bombbool=false;// make case for bomb
    Clock clock;
   // sf::Text text1;
    while (window.isOpen()){
    	
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer+=time;
        
       // if(score>=var)
        //{
        
	//bombbool =true;
	//}
	//else
	//bombbool= false;
	
        //---Event Listening Part---//
        Event e,a;
        while (window.pollEvent(e) ){                     //Event is occurring - until the game is in running state
            if (e.type == Event::Closed)               	 //If cross/close is clicked/pressed
                window.close();
                                            		 //Opened window disposes
            if (e.type == Event::KeyPressed && bombbool==false) {             //If any other key (not cross) is pressed
             if (Keyboard::isKeyPressed(Keyboard::Down))   //Just another way to detect key presses without event listener
            { //delay=softdrop(level, delay);
             delay=0.05;  //If DOWN key is pressed, goes to soft drop 
       		}
       		 
               else if (e.key.code == Keyboard::Up)        //Check if the other key pressed is UP key
                    {rotate = true;
                    }                        		   //Rotation gets on
                else if (e.key.code == Keyboard::Left)     //Check if the other key pressed is LEFT key
                    delta_x = -1;                          //Change in X-Axis - Negative
                else if (e.key.code == Keyboard::Right)    //Check if the other key pressed is RIGHT key
                    delta_x = 1;                           //Change in X-Axis - Positive
		else if(e.key.code == Keyboard ::H)	   //opens the menu window
		{
			bool choice=true;
			choice=menu(timer,menubg,level,delay,score);	   //menu function
		}
		else if (Keyboard::isKeyPressed(Keyboard::Space)) //When space is pressed delay is 0 and the sprite falls down
         	{

         	delay=0.0001;
         	}
            }
        }
         
        
   
        
        
       
          
        ///////////////////////////////////////////////
        ///*** START CALLING YOUR FUNCTIONS HERE ***///
        if(bombbool==false)
        fallingPiece(timer, delay,colorNum);                 //Example: fallingPiece() function is called here
	else
	bombbool=colorbomb(timer,delay ,colorNum,bombbool,var);//when bomb will be true will run the bomb ftn
	lineclear=line_clearing(score);//clears line
	if(lineclear) //when line clears will return true
	sound.play(); //when lineclear bool true sound will play
	movement(delta_x);//move blocks
	if(rotate)
	rotate=rotation();//get rotation of blocks
	gamestate=game_end();//to check if the game is teriminated or not after the blocks are filled
	
        ///*** YOUR CALLING STATEMENTS END HERE ***///
        //////////////////////////////////////////////
	
	
        window.clear(Color::Black);
        window.draw(background);
        if(bombbool==false)//to check if bomb is falling or not. if not regular flow will ocurr
        {
        for (int i=0; i<M; i++){
            for (int j=0; j<N; j++){
          
                if (gameGrid[i][j]==0)
                    continue;
                sprite.setTextureRect(IntRect(gameGrid[i][j]*18,0,18,18));
                sprite.setPosition(j*18,i*18);
                sprite.move(28,31); //offset
                window.draw(sprite);
            }
        }
        for (int i=0; i<4; i++){
            sprite.setTextureRect(IntRect(colorNum*18,0,18,18));
            sprite.setPosition(point_1[i][0]*18,point_1[i][1]*18);
            sprite.move(28,31);
            window.draw(sprite);
          }
          }
         else
         {
         for (int i=0; i<M; i++){
            for (int j=0; j<N; j++){
          
                if (gameGrid[i][j]==0)
                    continue;
                bomb.setTextureRect(IntRect(gameGrid[i][j]*18,0,18,18));
                bomb.setPosition(j*18,i*18);
                bomb.move(28,31); //offset
                window.draw(bomb);
            }
        }
        {
            bomb.setTextureRect(IntRect(colorNum*18,0,18,18));
            bomb.setPosition(point_1[0][0]*18,point_1[0][1]*18);
            bomb.move(28,31);
            window.draw(bomb);
         }
        }
        
	
        //---The Final on Which Everything is Drawn Over is Loaded---//
        window.draw(frame);
        Text text1,text2;
	Font font;
	if(font.loadFromFile("Animal Silence.otf"))
	cout<<"\nCould not open font."<<endl;
	text1.setFont(font);
	text1.setFillColor(Color::Red);
	text1.setCharacterSize(20);
	text1.setString("SCORE:");
	text1.setPosition(240.f,window.getSize().y/3);
	int ysize=window.getSize().y/3;	
        
        text2.setFont(font);
	text2.setFillColor(Color::Red);
	text2.setCharacterSize(20);
	std::stringstream ss;  // #include <sstream>
        ss << score;
        text2.setString( ss.str().c_str() );

	text2.setPosition(240.f,ysize+20);
        //---The Window that now Contains the Frame is Displayed---//
        window.draw(text2);
        window.draw(text1);
        window.display();
        
        
         delta_x=0;
          time = 0;
         reset(level,delay);
         // timer=0;
         // clock=0;
         if(!anamoly() || gamestate )
        {						
		window.close();
        }
    }
    
    RenderWindow game_over(VideoMode(320, 480), "GAME OVER");
    Text text1,text2;
	Font font;
	if(font.loadFromFile("Animal Silence.otf"))
	cout<<"\nCould not open font."<<endl;
	text1.setFont(font);
	text1.setFillColor(Color::Red);
	text1.setCharacterSize(30);
	text1.setString("GAME OVER");
	text1.setPosition(window.getSize().x/3,10.f);
	int ysize=window.getSize().y/3;
	
	
    	Clock clock1;
    	while(game_over.isOpen())
			{
			
			 float time1 = clock1.getElapsedTime().asSeconds();
			 bool select=false;
      			  clock1.restart();
      			 // timer+=time;
      			  Event a;
      			  	while(game_over.pollEvent(a))
				{if (a.type == Event::Closed)                  
                      	 	 game_over.close();
                      	 	
                        	}
    				
    				game_over.clear(Color::Black);
        			game_over.draw(menubg);
    				game_over.draw(text1);
    				//game_over.draw(text2);
    				game_over.display();
    				//if(gamecontrol)
    				//game_over.close();
    				//else
    				//game_over.close();
    			}
    

    
	
    return 0;
}
