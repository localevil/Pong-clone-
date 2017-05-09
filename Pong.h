//Main class
#include "libs.h"
#include "Controller.h"

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
