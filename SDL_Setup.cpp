//Функции инициализации SDL классов
#include "SDL_Setup.h"
#include <iostream>

CSDL_Setup::CSDL_Setup(int screan_width, int screan_height )
{
	//Инициализация всех SDL класоов
    SDL_Init(SDL_INIT_EVERYTHING);
	//Создание игрового окна
     m_window = SDL_CreateWindow("Pong", 0,0,screan_width,screan_height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN);
	//Проверка наличия окна
    if(m_window == nullptr)
    {
        std::cout << "SDL_CreateWindow Error" << SDL_GetError() << std::endl;
    }
   	//Создание рендера
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
    	//Проверка наличия рендера
    if(m_renderer == nullptr)
    {
        std::cout << "SDL_CreateRenderer Error" << SDL_GetError() << std::endl;
    }
	//Создание переменной события
    m_mainEvent= new SDL_Event();
}

//Проверка событий и отчистка рендера
void CSDL_Setup::begin()
{
	SDL_PollEvent(m_mainEvent);
	SDL_RenderClear(m_renderer);
	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 225);
}
//Отрисовка поля
void CSDL_Setup::end()
{
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 0);
	SDL_RenderPresent(m_renderer);
}

SDL_Window *CSDL_Setup::getWindow() const
{
	return m_window;
}

//Вывод события из класса
SDL_Event *CSDL_Setup::getMainEvent() const
{
    return m_mainEvent;
}

//Вывод ренера из класса
SDL_Renderer *CSDL_Setup::getRenderer() const
{
    return m_renderer;
}

CSDL_Setup::~CSDL_Setup()
{
    SDL_DestroyWindow(m_window);
    SDL_DestroyRenderer(m_renderer);
    delete m_mainEvent;
}
