//Функции основного класса
#include "CrossAndCircle.h"

CMain::CMain()
{ 
	turn = true;
	
	csdl_setup = new CSDL_Setup();
   
	contr = new CController();

	init_arr();

}
//Главный цикл
void CMain::mainLoop()
{
    while(!quit && csdl_setup->getMainEvent()->type != SDL_QUIT)
    {   
	//Проверка событий и отчистка рендера
        csdl_setup->begin(); 
	
	//Проверка ивента мыши
	if(SDL_WaitEventTimeout(csdl_setup->getMainEvent(),200))
	{
        if(csdl_setup->getMainEvent()->type == SDL_MOUSEBUTTONUP)
        {
            if(csdl_setup->getMainEvent()->button.button == SDL_BUTTON_LEFT)
            {	
		
		//Получение позиции мыши
                SDL_GetMouseState(&mouse_x, &mouse_y);

		//Переключятел очереди хода
		if(turn)
		{	
			turn = false;
			contr->drawPosition(fild_arr, csdl_setup,mouse_x, mouse_y, "cross.png", 1);
		}
		else
		{
			turn = true;
			contr->drawPosition(fild_arr, csdl_setup, mouse_x, mouse_y, "curcle.png", 2);
		}
		}   
        }
	}

		contr->CheckWinner(quit);	

		//Заполнение масива поля
            	draw_arr();
            	
		//Отрисовка поля
        	csdl_setup->end();

    }

}
//Инициализация масива игрового поля
void CMain::init_arr()
{
    int pos_X = 0;
    for(int i = 0; i < 3; i++)
    {
        int pos_Y = 0;
        for(int j = 0; j < 3; j++)
        {    
            fild_arr[i][j]= new CImage("fild1.png", pos_X, pos_Y, 150, 150, csdl_setup->getRenderer());        
            pos_Y +=150;
        }
        pos_X +=150;
    }
}

//заполнение масива игрового поля
void CMain::draw_arr()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {    
            fild_arr[i][j] -> draw();
        }
    }
}

CMain::~CMain()
{  
      	delete contr;	
    delete csdl_setup;
}

