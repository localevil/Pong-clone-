//Функции основного класса
#include "Pong.h"
#include <iostream>

CMain::CMain(int screenWidth, int screenHeight) : m_screenWidth(screenWidth - 150), m_screenHeight(screenHeight - 150)
{ 
	csdl_setup = new CSDL_Setup(m_screenWidth, m_screenHeight);
	
	boll = new CImage(m_screenWidth/2-12.5, m_screenHeight/2-12.5, 25, 25, csdl_setup->getRenderer());
	
	rightPlayer = new CImage(10, m_screenHeight/2-50, 25, 100, csdl_setup->getRenderer());

	dx = 1;
	dy = 1;	
}
void setWayToBoll(int dx, int dy)
{
		srand(time(NULL));
		dx = (-2) + rand() % 4;
		dy = (-2) + rand() % 4;
}
//Главный цикл
void CMain::exec()
{
	setWayToBoll(dx, dy);

	while(!quit && csdl_setup->getMainEvent()->type != SDL_QUIT)
	{
		//Проверка событий и отчистка рендера
		if(csdl_setup->getMainEvent()->type == SDL_KEYDOWN)
		{
			switch (csdl_setup->getMainEvent()->key.keysym.sym)
			{
				case SDLK_ESCAPE:
				{
					quit = true;
					break;
				}
				case SDLK_UP:
				{
					if(rightPlayer->getY() > 0)
					{
						rightPlayer->setY(rightPlayer->getY()-5);
						break;
					}
				}
				case SDLK_DOWN:
				{
					if(rightPlayer->getY() < m_screenHeight)
					{
						rightPlayer->setY(rightPlayer->getY()+5);
						break;
					}
				}
			}
		}

		csdl_setup->begin();

		if(timeCheck + 1000 != SDL_GetTicks())
		{
			if(boll->getX() < 5 || boll->getX() > m_screenWidth)
			{
				boll->setX(m_screenWidth/2-12.5);
				boll->setY(m_screenHeight/2-12.5);
				setWayToBoll(dx, dy);
			}

			if(boll->getY() < 5 || boll->getY() > m_screenHeight)  
			{
				dy = -dy;
			}

			if(abs(boll->getY() - rightPlayer->getY()) < 50 && boll->getX() < 25)
			{
				dx = -dx;
				dy = -dy;
			}

			boll->setX(boll->getX()+dx);
			boll->setY(boll->getY()+dy);
			
			rightPlayer->draw();

			boll->draw();
	
			//Отрисовка поля
			csdl_setup->end();
			SDL_Delay(3);
		}

	}

}

CMain::~CMain()
{  
    delete csdl_setup;
}

