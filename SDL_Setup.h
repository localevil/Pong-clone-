//Инициализация SDL классов
#include "libs.h"

class CSDL_Setup
{
    private:

    SDL_Window *window;
    SDL_Renderer *renderer;

    SDL_Event *mainEvent;

    public:

    CSDL_Setup(int screan_width, int screan_height);
    ~CSDL_Setup();

    void begin();

    void end();

    SDL_Event *getMainEvent();

    SDL_Renderer *getRenderer();


};
