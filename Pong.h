//Main class
#include "libs.h"
#include "SDL_Setup.h"
class CMain
{
    private:
	    //Переменная выхода
	    bool quit; 
		

	    CSDL_Setup *csdl_setup;


    	    
    	    
   
    public:
	    CMain();
    	    ~CMain();
    	    
	    void mainLoop();
    	    
};
