//Инициализация SDL классов
#include <SDL2/SDL.h>

class CSDL_Setup
{
    private:

    SDL_Window		*m_window;
    SDL_Renderer	*m_renderer;
    SDL_Event		*m_mainEvent;

    public:

    CSDL_Setup(int screan_width, int screan_height);
    ~CSDL_Setup();

    void begin();

    void end();

	SDL_Window *getWindow() const;
    SDL_Event *getMainEvent() const;
    SDL_Renderer *getRenderer() const;


};
