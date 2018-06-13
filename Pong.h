//Main class
#include "SDL_Setup.h"
#include "image.h"

class CMain
{
	private:
		//Переменная выхода
		bool quit;
		int m_screenWidth;
		int m_screenHeight;
		
		CImage *boll;	    
		
		CImage *rightPlayer;
		
	    CSDL_Setup *csdl_setup;
	
		double dx;
		double dy; 

	  float timeCheck; 

	public:
		CMain(int screen_width, int screen_height);
		~CMain();

		void exec();
};
