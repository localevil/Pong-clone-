//Создание текстур
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

class CImage
{
	private:
	SDL_Renderer *m_renderer;
	SDL_Rect m_image_rect;
	SDL_Surface* m_surface;
	public:

	CImage(int x, int y, int width, int height, SDL_Renderer *renderer);
	~CImage();

	void draw();
	
	int getX() const;
	int getY() const;
	
	void setX(int x);
	void setY(int x);
};
