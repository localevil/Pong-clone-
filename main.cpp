//Main file
#include "libs.h"
#include "CrossAndCircle.h"

int main()
{
	//Инициализация основного класса
	CMain *cmain = new CMain();

	//Запуск основного цикла
  	cmain->mainLoop();
	
	//Отчистка памяти    
	delete cmain;

    return 0;
}

