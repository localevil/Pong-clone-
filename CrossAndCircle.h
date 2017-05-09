//Main class
#include "libs.h"
#include "Controller.h"

class CMain
{
    private:
	    //Переменная выхода
	    bool quit; 
	    
	    //Пременные позиции мыши
	    int mouse_x = 0;
	    int mouse_y = 0;
		
		CController *contr;	

	    CSDL_Setup *csdl_setup;

	    CImage *fild;
	    CImage *fild_arr [3] [3];

    	    
    	    
	    //Переменная очереди
	    bool turn;
   
    public:
	    CMain();
    	    ~CMain();
    	    
	    void mainLoop();
    	    
	    void init_arr();
	    void draw_arr();
	    	    
};
