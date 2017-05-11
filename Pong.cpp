//Функции основного класса
#include "Pong.h"

CMain::CMain(int screen_width, int screen_height)
{ 
	csdl_setup = new CSDL_Setup(screen_width, screen_height);
	
	boll = new CImage("boll.png", screen_width/2-12.5, screen_height/2-12.5, 25, 25, csdl_setup->getRenderer());
	
	rightPlayer = new CImage("Player.png", 10, screen_height/2-50, 50, 100, csdl_setup->getRenderer()); 

	dx = 1;
	dy = 1;	

	timeCheck = SDL_GetTicks();
}

//Главный цикл
void CMain::mainLoop()
{
	while(dx == dy || dx == 0 || dy ==0 || dx == -dy)
	{	
		srand(time(NULL));
		dx = (-2) + rand() % 4;
		dy = (-2) + rand() % 4;
		std::cout << dx << ' ' << dy<<std::endl;
	}
	    while(!quit && csdl_setup->getMainEvent()->type != SDL_QUIT)
	    {   
		//Проверка событий и отчистка рендера
       		csdl_setup->begin(); 	
		if(timeCheck+1000 < SDL_GetTicks())
		{
			if(boll->getX() < 0 || boll->getX() > 575)
			{
				dx = -dx;
			}

			if(boll->getY() < 0 || boll->getY() > 575)  
			{
				dy = -dy;
			}
			boll->setX(boll->getX()+dx);
			boll->setY(boll->getY()+dy);
			
			rightPlayer->draw();

			boll->draw();	
	
			//Отрисовка поля
       			csdl_setup->end();
		}

	}	    

}

CMain::~CMain()
{  
    delete csdl_setup;
}

