/* PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)
 * You need to define the required function in the part instructed here below.
 * Avoid making any unnecessary changes, particularly the ones you don't understand.
 * The different pieces should be defined using an array - uncomment the following code once you are done creating the array.
 * TIP: Understand thoroughly before getting started with coding.
 * */

//---Piece Starts to Fall When Game Starts---//
#include<iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
float reset(int &level,float &delay);
using namespace sf;
using namespace std;
void fallingPiece(float& timer, float& delay ,int &colorNum){
    if (timer>delay){
        for (int i=0;i<4;i++){

            point_2[i][0]=point_1[i][0];
            point_2[i][1]=point_1[i][1];
            point_1[i][1]+=1;                   //How much units downward

        }

        if (!anamoly()){
        	for(int i=0;i<4;i++){
        		gameGrid[point_2[i][1]][point_2[i][0]]=colorNum;
        		
        		}
        	
            	colorNum=1+rand()%7;
    	        int n=rand()%7;
        	    //--- Un-Comment this Part When You Make BLOCKS array---//
        	    
        	        for (int i=0;i<4;i++){
        	            point_1[i][0] = BLOCKS[n][i] % 2;
        	            point_1[i][1] = BLOCKS[n][i] / 2;
        	        }
        	        
            
        }
        timer=0;
    }
 
}
			

/////////////////////////////////////////////
///*** START CODING YOUR FUNTIONS HERE ***///

int colorbomb(float& timer, float& delay ,int &colorNum,bool &bombbool,int&var)  //For the movement of  color bomb
{
	if (timer>delay){
        for (int i=0;i<1;i++){

            point_2[i][0]=point_1[i][0];
            point_2[i][1]=point_1[i][1];
            point_1[i][1]+=1;                   //How much units downward

        }

        if (!anamoly()){
        	
        	if(gameGrid[point_2[0][1]-1][point_2[0][0]]==colorNum || gameGrid[point_2[0][1]-1][point_2[0][0]-1]==colorNum || gameGrid[point_2[0][1]-1][point_2[0][0]+1]==colorNum)
        	{
        		for (int i=0; i<M; i++){
            			for (int j=0; j<N; j++){
          
               			 gameGrid[i][j]=0;
        		}
        		}
        		var+=200;
        	}
        	
            	colorNum=1+rand()%7;
    	        int n=rand()%7;
        	    //--- Un-Comment this Part When You Make BLOCKS array---//
        	    
        	        for (int i=0;i<4;i++){
        	            point_1[i][0] = BLOCKS[n][i] % 2;
        	            point_1[i][1] = BLOCKS[n][i] / 2;
        	        }
            
        }
        timer=0;
    
    }
    
	return 0;

}
bool game_end()  // checks weather the blocks have over flowed the container
{
  bool end= false;
  for(int i=0; i < N;i++)
  {   
    if(gameGrid[0][i] != 0)
    {
      end = true;
    }
  }
  return end;
}

float softdrop(int &level, float &delay)  //for the soft drop of block
{

	for(int i=0;i<4;i++)
	{	
	if(point_1[i][1]&&(gameGrid[point_1[i][1]][1]!=0))
	{
	return 0.03;
	}
	else
	{
	reset(level,delay);
	return delay;
	}
	}
	
	return delay;
	
}
float reset(int &level,float &delay)  //after every increment in delay this will reset values 
{
		bool select=false;
				if (level==1)   
           			  	{ delay=0.5;
           			  	
           			  	select=true;}         
       		 
             			else if (level==2)           
                    			{delay=0.45;
                    							
                   			select=true;} 
                                             
                	        else if (level==3) 
                    		{	delay=0.4 ; 
                    			                     
                    			 select=true;} 
                    				
                		else if (level==4)    
          				{delay=0.35;      
          				
          				select=true;} 
          			else if (level==5)    
          				{delay=0.3;    
          				
          				select=true;} 
          			else if (level==6)    
          				{delay=0.25;     
          				 
          				 select=true;} 
          			else if (level==7)    
          				{delay=0.2;   
          				
          				 select=true;} 
          			else if (level==8)    
          				 {delay=0.15;   
          				 
          				 select=true;} 
          			else if (level==9)    
          				 {delay=0.1;    
          				 
          				 select=true;}

	return delay;

}
void movement(int &delta_x)  //will controll movement on x plane
{
	for(int i=0;i<4;i++)
	{
		point_2[i][0]=point_1[i][0];
		point_2[i][1]=point_1[i][1];
		point_1[i][0]+=delta_x;
	
	}
	if(!anamoly())
        {
        	for(int i=0;i<4; i++)
        	{
		   point_1[i][0]=point_2[i][0];
		   point_1[i][1]=point_2[i][1];
			
		}
        }


}
bool line_clearing(int&score)   //clears line if it is filled
{

		static int line1;
		int line=0;
		int full = 19;
                for(int i =19; i > 0; i--)
                {
                   
  		   int complete=0;
	           for(int j = 0; j < 10; j++)
         	    {
				if(gameGrid[i][j] != 0)               //checks weather line is full or not
				complete++;
				gameGrid[full][j] = gameGrid[i][j];   //after line clear moves the blocks down
		    }
		    if(complete < 10)
		    {
			full--;
		    }
		    else if(complete>=10)
		    {line+=1 ;
                    std::cout<<"\nGame paused and line ="<<line<<std::endl;}
                 
		}
		switch(line)    // scoring convention 
		{
			case 1:
				score+=10;
				//sound.play();
				break;
			case 2:
				score+=30;
				//sound.play();
				break;
			case 3:
				score+=60;
				//sound.play();
				break;
			case 4:
				score+=100;
				//sound.play();
				break;
				
			default:
				return 0;
		
		}
		line1+=line;
		//line=0;
		if(line1>0)
		std::cout<<"\nGame paused and total line ="<<line1<<std::endl;
		return 1;
		

}
bool rotation()   //for the rotation of cordinates
{
	int cordinate_x=point_1[1][0];
	int cordinate_y=point_1[1][1];
	
	for(int i=0;i<4;i++)
	{
		int temp_x,temp_y;
		temp_x = point_1[i][1] - cordinate_y;
		temp_y = point_1[i][0]- cordinate_x;
		point_1[i][0] = cordinate_x - temp_x;
		point_1[i][1] = cordinate_y + temp_y;		
	
	}
	if(!anamoly())
        {
        	for(int i=0;i<4; i++)
        	{
		   point_1[i][0]=point_2[i][0];
		   point_1[i][1]=point_2[i][1];
			
		}
        }

	return 0;


}
/*void ghost_block()    // for the shadow of falling piece
{
	bool falling=1;
	unsigned char move=0;
	while(falling)
	{
		move++;
		for(int i=0;i<4;i++)
		{
			if(M==move+point_1[i][1])
			{
				falling=0;
				break;
			}
			if(0>move+point_1[i][1])
			{
				continue;
			}
			else if(0<BLOCKS[point_1[i][0]][move+point_1[i][1]])
			{
				falling=0;
				break;
				
			}		
	
		}
	
	}
	for(int i=0;i<4;i++)
	{
	ghost_1[i][1]+=point_1[i][1]+move-1;
	ghost_1[i][1]+=point_1[i][1]+move-1;

	}	
}*/
int soundmenu()  //sound menu
{

return 0;

}
int levelmenu(int &level, float &delay)   //level menu
{
	Texture obj41;
	
	int time=0,timer=0;
	obj41.loadFromFile("tetrisimg.jpg");
        Sprite menubg(obj41);
	RenderWindow window_level(VideoMode(1920,1200),"TETRIS");
	Clock clock1;
	int size=window_level.getSize().y/5;
	const int size1=size;
	Font font;
	if(font.loadFromFile("Animal Silence.otf"))
	cout<<"\nCould not open font."<<endl;
	Text text,textlevel;
	
	text.setFont(font);
	text.setFillColor(Color::Green);
	text.setCharacterSize(80);
	text.setString("TETRIS LEVEL-SELECT");
	text.setPosition(window_level.getSize().x/4,10.f);
	
			textlevel.setFont(font);
			textlevel.setFillColor(Color::Red);
			textlevel.setCharacterSize(40);
			textlevel.setString("Press any key from\"1-9\" to select level:");
			size=size1+size;
			textlevel.setPosition(0.f,size);
			
	while(window_level.isOpen())
			{
			 float time1 = clock1.getElapsedTime().asSeconds();
			 bool select=false;
      			  clock1.restart();
      			  timer+=time;
      			  Event a;
      			  	while(window_level.pollEvent(a))
				{if (a.type == Event::Closed)                  
                      	 	 window_level.close();
                      	 	
                        	if (a.type == Event::KeyPressed) 
                        	{             
             			if (Keyboard::isKeyPressed(Keyboard::Num1))   
           			  	{ delay=0.5;
           			  	level=1;
           			  	select=true;}         
       		 
             			else if (a.key.code == Keyboard::Num2)           
                    			{delay=0.45;
                    			level=2;				
                   			select=true;} 
                                             
                	        else if (a.key.code == Keyboard::Num3) 
                    		{	delay=0.4 ; 
                    			level=3;                      
                    			 select=true;} 
                    				
                		else if (a.key.code == Keyboard::Num4)    
          				{delay=0.35;      
          				level=4;
          				select=true;} 
          			else if (a.key.code == Keyboard::Num5)    
          				{delay=0.3;    
          				level=5;
          				select=true;} 
          			else if (a.key.code == Keyboard::Num6)    
          				{delay=0.25;     
          				 level=6;
          				 select=true;} 
          			else if (a.key.code == Keyboard::Num7)    
          				{delay=0.2;   
          				 level=7;
          				 select=true;} 
          			else if (a.key.code == Keyboard::Num8)    
          				 {delay=0.15;   
          				 level=8;
          				 select=true;} 
          			else if (a.key.code == Keyboard::Num9)    
          				 {delay=0.1;    
          				 level=9;
          				 select=true;}                     
                        	
                               }
                               
			       } 
                      	 	 
				window_level.clear(Color::Black);
			
       				window_level.draw(menubg);
       				window_level.draw(text);
       				window_level.draw(textlevel);
       				window_level.display();
       				if(select)
       				window_level.close();
       				
       				
       			}
       		//return 0;
	
return 0;
}
int highscoremenu(int &score)   //high score ftn
{
	RenderWindow window_high(VideoMode(1920,1200),"TETRIS");
		Clock clock1;
		fstream myfile("highscore.txt", ios::app);
		int size=window_high.getSize().y/5;
		int timer1;
		const int size1=size;
		Texture obj4;
		obj4.loadFromFile("tetrisimg.jpg");
    		Sprite menubg(obj4);
		Font font;
		if(font.loadFromFile("Animal Silence.otf"))
		cout<<"\nCould not open font."<<endl;
		Text text,textsound,textlevel,textrestart,textscore;
		
		text.setFont(font);
		text.setFillColor(Color::Green);
		text.setCharacterSize(80);
		text.setString("TETRIS  HIGH SCORE");
		text.setPosition(window_high.getSize().x/4,10.f);
		
		
		
		while(window_high.isOpen())
		{
		float time1 = clock1.getElapsedTime().asSeconds();
      		clock1.restart();
  		  timer1+=time1;
		Event a;
		while(window_high.pollEvent(a))
		{if (a.type == Event::Closed)                   //If cross/close is clicked/pressed/for menu
                      	  window_high.close();
		 if (a.type == sf::Event::TextEntered)
		{
 		 if (a.text.unicode < 128)
 		 {
 		 if(myfile.good())
		{
       		 myfile << char(a.text.unicode);
       		 
       		 }
       		 
		}
		}
		window_high.clear(Color::Black);
			
       			window_high.draw(menubg);
       			window_high.draw(text);
       			//window_high.draw(textsound);
       			//window_high.draw(textlevel);
       			//window_high.draw(textscore);
       			//window_high.draw(textrestart);
       			//window_menu.draw(sprite);
       			window_high.display();
		}
		}
		
		
		myfile <<  score << "\n";
		
	
return 0;
}
int restart() //restart ftn resets the values if user decides to play again mid game
{
return 0;
}

bool menu(float timer1,Sprite &menubg, int &level ,float &delay,int&score)  //main menu ftn which controls differet windows
{
			RenderWindow window_menu(VideoMode(1920,1200),"TETRIS");
			Clock clock1;
			int size=window_menu.getSize().y/5;
			const int size1=size;
			Font font;
			if(font.loadFromFile("Animal Silence.otf"))
			cout<<"\nCould not open font."<<endl;
			Text text,textsound,textlevel,textrestart,textscore;
			
			text.setFont(font);
			text.setFillColor(Color::Green);
			text.setCharacterSize(80);
			text.setString("TETRIS  MAIN  MENU");
			text.setPosition(window_menu.getSize().x/4,10.f);
			
			textsound.setFont(font);
			textsound.setFillColor(Color::Red);
			textsound.setCharacterSize(40);
			textsound.setString("Press \"S\" for Sound");
			textsound.setPosition(0.f,size1);

			textlevel.setFont(font);
			textlevel.setFillColor(Color::Red);
			textlevel.setCharacterSize(40);
			textlevel.setString("Press \"L\" for Level");
			size=size1+size;
			textlevel.setPosition(0.f,size);
			
			textscore.setFont(font);
			textscore.setFillColor(Color::Red);
			textscore.setCharacterSize(40);
			textscore.setString("Press \"H\" for High Score");
			size=size1+size;
			textscore.setPosition(0.f,size);
			
			textrestart.setFont(font);
			textrestart.setFillColor(Color::Red);
			textrestart.setCharacterSize(40);
			textrestart.setString("Press \"R\" for Restart");
			size=size1+size;
			textrestart.setPosition(0.f,size);

			while(window_menu.isOpen())
			{
			 float time1 = clock1.getElapsedTime().asSeconds();
      			  clock1.restart();
      			  timer1+=time1;

			Event a;
			while(window_menu.pollEvent(a))
			{if (a.type == Event::Closed)                   //If cross/close is clicked/pressed/for menu
                      	  window_menu.close();
                        	if (a.type == Event::KeyPressed) 
                        	{             
             			//if (Keyboard::isKeyPressed(Keyboard::S))   
           			  //	 soundmenu();          // opens sound control
       				
       		 
             			   if (a.key.code == Keyboard::L)           
                    			levelmenu(level,delay);				// opens level menu
                   
                                             
                			else if (a.key.code == Keyboard::H) 
                    				highscoremenu(score) ;                        //opens highscore menu
                    				
                    				
                				else if (a.key.code == Keyboard::R)    
          					          restart();     //opens restart function                      
                        	
                               }
      			} 
			window_menu.clear(Color::Black);
			
       			window_menu.draw(menubg);
       			window_menu.draw(text);
       			window_menu.draw(textsound);
       			window_menu.draw(textlevel);
       			window_menu.draw(textscore);
       			window_menu.draw(textrestart);
       			//window_menu.draw(sprite);
       			window_menu.display();
       			}
       			return false;
}
///*** YOUR FUNCTIONS END HERE ***///
/////////////////////////////////////





