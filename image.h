//Создание текстур
#include "libs.h"

class CImage
{
    private:

    SDL_Texture *image;
    SDL_Rect image_rect;

    SDL_Renderer *ren;

    public:

    CImage(std::string passed_file, int x, int y, int width, int height, SDL_Renderer *renderer);
    ~CImage();

    void draw();

};
