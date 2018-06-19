//Функции основного класса
#include "Pong.h"
#include <iostream>
#include <cmath>

CMain::CMain(int screenWidth, int screenHeight) : 
		m_screenWidth(screenWidth), 
		m_screenHeight(screenHeight),
		m_speed(3)
{ 
	csdl_setup = new CSDL_Setup(m_screenWidth, m_screenHeight);
	
	boll = new CImage(m_screenWidth/2-12.5, m_screenHeight/2-12.5, 25, 25, csdl_setup->getRenderer());
	
	rightPlayer = new CImage(10, m_screenHeight/2-50, 25, 100, csdl_setup->getRenderer());
}

void setWayToBoll(int* dx, int* dy, float* speed)
{
		int angle = 0;
		srand(time(NULL));
		angle = rand() % 360;
		*dx = *speed * std::cos(angle);
		*dy = *speed * std::sin(angle);
		if(*dx == 0)
			*dx = 1;
}
//Главный цикл
void CMain::exec()
{
	setWayToBoll(&m_dx, &m_dy, &m_speed);

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
					if(rightPlayer->getY() < m_screenHeight - 100)
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
				m_speed += 0.1;
				setWayToBoll(&m_dx, &m_dy, &m_speed);
			}

			if(boll->getY() < 5 || boll->getY() > m_screenHeight - 5)  
			{
				m_dy = -m_dy;
			}

			if(abs(boll->getY() - rightPlayer->getY()) < 70 && boll->getX() < 30)
			{
				m_dx = -m_dx;
			}

			boll->setX(boll->getX()+m_dx);
			boll->setY(boll->getY()+m_dy);
			
			rightPlayer->draw();

			boll->draw();
	
			//Отрисовка поля
			csdl_setup->end();
			SDL_Delay(5);
		}

	}

}

CMain::~CMain()
{  
    delete csdl_setup;
}

