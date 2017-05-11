//Main class
#include "libs.h"
#include "SDL_Setup.h"
#include "image.h"

class CMain
{
    private:
	    //Переменная выхода
	    bool quit;
		
		CImage *boll;	    
		
		CImage *rightPlayer;
		
	    CSDL_Setup *csdl_setup;
	    
	    int dx;
	   int dy; 
    	   
	  float timeCheck; 
   
    public:
	    CMain(int screen_width, int screen_height);
    	    ~CMain();
    	    
	    void mainLoop();
    	    
};
