//Main class
#include "SDL_Setup.h"
#include "image.h"

class CMain
{
	private:
		bool quit;
		int m_screenWidth;
		int m_screenHeight;
		
		CImage *boll;	    
		
		CImage *rightPlayer;
		
	    CSDL_Setup *csdl_setup;
	
		int m_dx;
		int m_dy; 
		float m_speed;

		float timeCheck; 

	public:
		CMain(int screen_width, int screen_height);
		~CMain();

		void exec();
};
