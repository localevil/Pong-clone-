//Функции основного класса
#include "CrossAndCircle.h"

CMain::CMain()
{ 
	csdl_setup = new CSDL_Setup();

}

//Главный цикл
void CMain::mainLoop()
{
    while(!quit && csdl_setup->getMainEvent()->type != SDL_QUIT)
    {   
	//Проверка событий и отчистка рендера
        csdl_setup->begin(); 
	
		
	//Отрисовка поля
       	csdl_setup->end();

    }

}
CMain::~CMain()
{  
    delete csdl_setup;
}

