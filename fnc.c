#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "fnc.h"

image init_img(char nomimage[100],int x,int y)
{
image img;
img.back=IMG_Load(nomimage);//load image
img.positiond.x=x;//position x de bg
img.positiond.y=y;//position y de bg
img.positionc.x=0;
img.positionc.y=0;
img.positionc.h=700;
img.positionc.w=900;
return img;
}
void init_splitscreen(image* I1,image *I2,int screenw)
{
int int_screenw=screenw/2;
I1->positionc.w=int_screenw;
I2->positionc.w=int_screenw;
I2->positiond.x=int_screenw;
}

void display(SDL_Surface *ecran,image img)
{
SDL_BlitSurface(img.back,&img.positionc,ecran,&img.positiond);//afficher l image
}
int input(robottt* rob,image* img,int i,int *continuer, int *var)
{
SDL_Event event;
SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
            continuer = 0;
            break;
            case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
                break; 
                case SDLK_a :
if(rob->positionrobot.x<400)
{
 rob->positionrobot.x +=50;
                rob->positionrobot.y-=50;

}
i++;


  if (rob->positionrobot.x>=400)
            {

img->positionc.x+=20;
if (img->positionc.x+img->positionc.w>=img->back->w-20)
img->positionc.x=0;

}



(*var)=(*var)+10; 

if((*var)>=3000)
{
(*var)=0;
img->positionc.x=0;
rob->positionrobot.x=50;
}
return i; 
        
   


               //i=0;
               // rob->positionrobot.x +=50;
               // rob->positionrobot.y-=50;
                //i++;

                break; 
                case SDLK_p :
i=scrolling(rob,img,i,var);
                
                break; 
                case SDLK_r :
                
                break; 
                case SDLK_UP:
          i=0;
     

                rob->positionrobot.y-=50;
                i++;
                break;
           }
        }
return i;
}

int input1(robottt* rob,image* img,int i,int *continuer, int *var)
{
SDL_Event event;
SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
            continuer = 0;
            break;
            case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
                break; 
                case SDLK_a :
if(rob->positionrobot.x<200)
{
 rob->positionrobot.x +=50;
                rob->positionrobot.y-=50;

}
i++;


  if (rob->positionrobot.x>=200)
            {

img->positionc.x+=20;
if (img->positionc.x+img->positionc.w>=img->back->w-20)
img->positionc.x=0;

}



(*var)=(*var)+10; 

if((*var)>=3000)
{
(*var)=0;
img->positionc.x=0;
rob->positionrobot.x=50;
}
return i; 
        
   


               //i=0;
               // rob->positionrobot.x +=50;
               // rob->positionrobot.y-=50;
                //i++;

                break; 
                case SDLK_p :
i=scrolling1(rob,img,i,var);
                
                break; 
                case SDLK_r :
                
                break; 
                case SDLK_UP:
          i=0;
     

                rob->positionrobot.y-=50;
                i++;
                break;
           }
        }
return i;
}

int input2(robottt* rob,image* img,int i,int *continuer, int *var)
{
SDL_Event event;
SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
            continuer = 0;
            break;
            case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
                break; 
                case SDLK_a :
if(rob->positionrobot.x<800)
{
 rob->positionrobot.x +=50;
                rob->positionrobot.y-=50;

}
i++;


  if (rob->positionrobot.x>=800)
            {

img->positionc.x+=20;
if (img->positionc.x+img->positionc.w>=img->back->w-20)
img->positionc.x=0;

}



(*var)=(*var)+10; 

if((*var)>=3000)
{
(*var)=0;
img->positionc.x=0;
rob->positionrobot.x=50;
}
return i; 
        
   


               //i=0;
               // rob->positionrobot.x +=50;
               // rob->positionrobot.y-=50;
                //i++;

                break; 
                case SDLK_m :
i=scrolling2(rob,img,i,var);
                
                break; 
                case SDLK_r :
                
                break; 
                case SDLK_UP:
          i=0;
     

                rob->positionrobot.y-=50;
                i++;
                break;
           }
        }
return i;
}

robottt init_perso()
{

    robottt rob;

    rob.robot[0] = IMG_Load("1.png");

    rob.robot[1] = IMG_Load("2.png");

    rob.robot[2] = IMG_Load("3.png");

    rob.robot[3] = IMG_Load("4.png");

    rob.robot[4] = IMG_Load("3.png");

    rob.robot[5] = IMG_Load("2.png");

    rob.robot[6] = IMG_Load("1.png");

    rob.robot[7] = IMG_Load("2.png");

    rob.robot[8] = IMG_Load("3.png");

      rob.positionrobot.x = 0;
    rob.positionrobot.y = 400; 

  return rob;

}  

void display_perso(SDL_Surface *ecran,robottt rob,int i,SDL_Rect positionrobot)
{
SDL_BlitSurface(rob.robot[i],NULL,ecran,&positionrobot);
}
int scrolling (robottt *rob,image *img,int i,int *var)
{
if(rob->positionrobot.x<400)
{
rob->positionrobot.x+=10; 

}
i++;


  if (rob->positionrobot.x>=400)
            {

img->positionc.x+=20;
if (img->positionc.x+img->positionc.w>=img->back->w-20)
img->positionc.x=0;

}



(*var)=(*var)+10; 

if((*var)>=3000)
{
(*var)=0;
img->positionc.x=0;
rob->positionrobot.x=0;
}
        
   
return i; 

}
int scrolling1 (robottt *rob,image *img,int i,int *var)
{
if(rob->positionrobot.x<200)
{
rob->positionrobot.x+=10; 

}
i++;


  if (rob->positionrobot.x>=200)
            {

img->positionc.x+=20;
if (img->positionc.x+img->positionc.w>=img->back->w-20)
img->positionc.x=0;

}



(*var)=(*var)+10; 

if((*var)>=3000)
{
(*var)=0;
img->positionc.x=0;
rob->positionrobot.x=0;
}
        
   
return i; 

}

int scrolling2 (robottt *rob,image *img,int i,int *var)
{
if(rob->positionrobot.x<600)
{
rob->positionrobot.x+=10; 

}
i++;


  if (rob->positionrobot.x>=600)
            {

img->positionc.x+=20;
if (img->positionc.x+img->positionc.w>=img->back->w-20)
img->positionc.x=0;

}



(*var)=(*var)+10; 

if((*var)>=3000)
{
(*var)=0;
img->positionc.x=0;
rob->positionrobot.x=0;
}
        
   
return i; 

}






