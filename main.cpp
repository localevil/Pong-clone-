//Main file
#include "Pong.h"

int main()
{
	int width = 1366;
	//Инициализация основного класса
	CMain *cmain = new CMain(width, width/16*9);

	//Запуск основного цикла
	cmain->exec();
	
	//Отчистка памяти    
	delete cmain;

	return 0;
}

