#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_rotozoom.h>
#include "fnc.h"

// ;
void  main(SDL_Surface *ecran)
{
char Dir[100]; 
strcpy(Dir,"./Save");
    robottt rob,rob2;
    SDL_Event event;
    save sv,ld;
//image tmp;
    int continuer=1,i=0, PHASE=13;
int var;
var=0; 




    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO); //initialisation
    ecran=SDL_SetVideoMode(900, 700, 32,SDL_HWSURFACE);//afficher la fenetre


    image img2,img;
    rob=init_perso();
    rob2=init_perso();
    //rob2.positionrobot.x=600;
    img=init_img("map.png",0,0);
    //img2=init_img("map.png",0,0);
    //init_splitscreen(&img,&img2,900);
    Init_Save_Menu(&sv);
    Init_Load_Menu(&ld);
    SDL_EnableKeyRepeat(100,100); /*Activation de la répétition des touches  100 ms */

    while (continuer)
    {	printf("\nPHASE %d\n",PHASE);
	    SDL_PollEvent(&event);
		
	switch (PHASE)
{
case 1:

		if(event.type==SDL_QUIT)
			continuer=0;
	
	    if (event.key.keysym.sym==SDLK_s)
			PHASE=2;
            i=input(&rob,i,&continuer);
//i--;
i=input(&rob2,i,&continuer);
            //printf("main i= %d \n",i);
            if (i==4)
            {
            i=0;
            }
             SDL_Delay(100);
             display(ecran,img);
	     //display(ecran,img2);
             display_perso(ecran,rob,i,rob.positionrobot);
	     
	     //display_perso(ecran,rob2,i,rob2.positionrobot);
             SDL_Flip(ecran);

       
         
if(rob.positionrobot.x<200)
{
rob.positionrobot.x+=10; 

}
i++;


  if (rob.positionrobot.x>=200)
            {

img.positionc.x+=20;
if (img.positionc.x+img.positionc.w>=img.back->w-20)
img.positionc.x=0;

}
/*
if(rob2.positionrobot.x<700)
{
rob2.positionrobot.x+=10; 

}
i++;


  if (rob2.positionrobot.x>=700)
            {

img2.positionc.x+=20;
if (img2.positionc.x+img2.positionc.w>=img2.back->w-20)
img2.positionc.x=0;

}
*/
var=var+10; 

if(var>=2000)
{
var=0;
img.positionc.x=0;
rob.positionrobot.x=0;
}

         if (rob.positionrobot.y<400)//fixation jump
         rob.positionrobot.y=400;
	 break;
case 2:
PHASE=SaveFNCTN(&sv,ecran,&continuer,&event);
break;
case 11:
//insert save here

Save(rob, img, Dir);

PHASE=6;
break;
case 6:
//insert Main Menu function here
//Load(&rob, &img, Dir);

//
continuer=0;
break;
case 13:
//LOAD MENU//
PHASE=LoadFNCTN(&ld,ecran,&continuer,&event);
break;
case 12:
Load(&rob,&img,Dir);
PHASE=1;
break;
}







}
}
 

