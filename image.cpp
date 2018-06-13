//Функции класса текстур
#include "image.h"
#include <iostream>

CImage::CImage(int x, int y, int width, int height, SDL_Renderer *renderer) : m_renderer(renderer)
    {
	//Предоставление свойств изображению
        m_image_rect.x = x;
        m_image_rect.y = y;
        m_image_rect.h = height;
        m_image_rect.w = width;
    }
//Копирование изображения в рендер
void CImage::draw()
{	
	SDL_RenderFillRect(m_renderer, &m_image_rect);
}

void CImage::setX(int x)
{
	m_image_rect.x = x;
}

void CImage::setY(int y)
{
	m_image_rect.y = y;
}

int CImage::getX() const
{
	return m_image_rect.x;
}
int CImage::getY() const
{
	return m_image_rect.y;
}
CImage::~CImage()
{
}
