//Функции инициализации SDL классов
#include "SDL_Setup.h"

CSDL_Setup::CSDL_Setup(int screan_width, int screan_height )
{
	//Инициализация всех SDL класоов
    SDL_Init(SDL_INIT_EVERYTHING);
	//Создание игрового окна
     window = SDL_CreateWindow("Pong", 0,0,screan_width,screan_height, SDL_WINDOW_SHOWN);
	//Проверка наличия окна
    if(window == nullptr)
    {
        std::cout << "SDL_CreateWindow Error" << SDL_GetError() << std::endl;
    }
   	//Создание рендера
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    	//Проверка наличия рендера
    if(renderer == nullptr)
    {
        std::cout << "SDL_CreateRenderer Error" << SDL_GetError() << std::endl;
    }
	//Создание переменной события
    mainEvent= new SDL_Event();
}

//Проверка событий и отчистка рендера
void CSDL_Setup::begin()
{
    SDL_PollEvent(mainEvent);
    SDL_RenderClear(renderer);
}
//Отрисовка поля
void CSDL_Setup::end()
{
    SDL_RenderPresent(renderer);
}

//Вывод события из класса
SDL_Event *CSDL_Setup::getMainEvent()
{
    return mainEvent;
}

//Вывод ренера из класса
SDL_Renderer *CSDL_Setup::getRenderer()
{
    return renderer;
}

CSDL_Setup::~CSDL_Setup()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    delete mainEvent;
}
