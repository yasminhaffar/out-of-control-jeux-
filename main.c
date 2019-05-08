#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "fnc.h"
void  main(SDL_Surface *ecran)
{
    robottt rob,rob2;
    SDL_Event event;
    int continuer=1,i=0,i2=0;
int var;
var=0;


    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO); //initialisation
    ecran=SDL_SetVideoMode(900, 700, 32,SDL_HWSURFACE);//afficher la fenetre


   

    image img2,img;
    rob=init_perso();
    rob2=init_perso();
    rob2.positionrobot.x=600;
    img=init_img("map3.png",0,0);
    img2=init_img("map3.png",0,0);
    init_splitscreen(&img,&img2,900);
    


    SDL_EnableKeyRepeat(100,100); /*Activation de la répétition des touches  100 ms */

    while (continuer)
    {
i=input1(&rob,&img,i,&continuer,&var);
i2=input2(&rob2,&img2,i2,&continuer,&var);//
           
            if (i==4)
            {
            i=0;
            }
            if (i2==4)
            {
            i2=0;
            }
             SDL_Delay(100);
             display(ecran,img);
	     display(ecran,img2);
            display_perso(ecran,rob,i,rob.positionrobot);
	    display_perso(ecran,rob2,i2,rob2.positionrobot);
             SDL_Flip(ecran);


 


         if (rob.positionrobot.y<400)//fixation jump
         rob.positionrobot.y=400;
   }

}







