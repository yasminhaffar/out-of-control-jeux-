#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_rotozoom.h>
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
int input(robottt* rob,int i,int *continuer)
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
                i=0;
                rob->positionrobot.x +=50;
                rob->positionrobot.y-=50;
                i++;

                break; 
                case SDLK_RIGHT :
i=0;
                                rob->positionrobot.x +=50;
i++;
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
printf("fonction i= %d \n",i); 
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

void display_perso(SDL_Surface *ecran,robottt rob,int i,SDL_Rect positiond)
{
SDL_BlitSurface(rob.robot[i],NULL,ecran,&rob.positionrobot);
}
void Load_robot(robottt *rob,char Dir[100])
{ FILE* f=fopen(Dir,"rb");
robottt tmp;
fread(&tmp,sizeof(robottt),1,f);
rob->positionrobot=tmp.positionrobot;
/*C->Direction=tmp.Direction;
C->State=tmp.State;
C->Score=tmp.Score;
C->Health=tmp.Health;
C->iframe=tmp.iframe;
C->zoom=tmp.zoom;*/
fclose(f);
}

void Load_Map(image *img,char Dir[100])
{ FILE* f=fopen(Dir,"rb");
image tmp;
fread(&tmp,sizeof(image),1,f);
img->positiond=tmp.positiond;
img->positionc=tmp.positionc;

sprintf(Dir,"map.png");
printf("%s",Dir);
img->back=IMG_Load(Dir);
/*M->Background_Map=zoomSurface(M->Background_Map,0.45,0.45,0);
sprintf(Dir,"./src/Image/Mask/Level%d/image000.png",M->Num_Map);
M->Mask_Map=IMG_Load(Dir);
M->Mask_Map=zoomSurface(M->Mask_Map,0.45,0.45,0);*/

fclose(f);
}

void Load(robottt *rob, image *img, char Dir[100])
{
char tmp_Dir[100];
sprintf(tmp_Dir,"%s/robottt.bin",Dir);
Load_robot(rob,tmp_Dir);
sprintf(tmp_Dir,"%s/image.bin",Dir);
Load_Map(img,tmp_Dir);
}




void Save_robottt(robottt C,char Dir[100])
{ FILE* f=fopen(Dir,"wb");
fwrite(&C,sizeof(robottt),1,f);
fclose(f);
}

void Save_image(image M,char Dir[100])
{ FILE* f=fopen(Dir,"wb");
fwrite(&M,sizeof(image),1,f);
fclose(f);
}



void Save(robottt C, image M, char Dir[100])
{
char tmp_Dir[100];
sprintf(tmp_Dir,"%s/robottt.bin",Dir);
Save_robottt(C,tmp_Dir);
sprintf(tmp_Dir,"%s/image.bin",Dir);
Save_image(M,tmp_Dir);
}
void Init_Save_Menu(save *S)
{
S->Background_Save=IMG_Load("./src/Image/Save/Background.png");
S->Save_Lum=IMG_Load("./src/Image/Save/Lum.png");
S->Rect_Save.x=200;
S->Rect_Save.y=100;

S->Save_Opt[0].y=254;
S->Save_Opt[0].x=335;

printf("\nSave_O_0_x: %d | Save_O_0_y: %d \n",S->Save_Opt[0].x,S->Save_Opt[0].y);
S->Save_Opt[1].y=254;
S->Save_Opt[1].x=475;

S->Mouse_Pos_y=0;
S->Mouse_Pos_x=0;
S->PS=-1;
S->PSP=-1;
}

int SaveFNCTN(save* S,SDL_Surface* Screen,int* continuer,SDL_Event *event)
{
int PHASE=2;
SDL_BlitSurface(S->Background_Save,NULL,Screen,&S->Rect_Save);
    {
      if ( event->type == SDL_QUIT )  {  (*continuer)= 0;  }

      if ( event->type == SDL_KEYDOWN ) // Bouttons
      {
	switch(event->key.keysym.sym)
	{
        case SDLK_ESCAPE :
	 { PHASE = 1; break; }
	case SDLK_LEFT:
		{ if (S->PS>0) S->PS--;
		  else if (S->PS == -1) S->PS=0;

		  break;
		}
	case SDLK_RIGHT :
		{ if ((S->PS < 1)&&(S->PS>=0)) S->PS++;
		  else if (S->PS == -1) S->PS=1;
		  break;
		}
	case SDLK_RETURN :
		{
		  if(S->PS!=-1) {if (S->PS==0) PHASE=11; else PHASE=6;}
		  break;
		}
	case SDLK_KP_ENTER :
		{
		  if(S->PS!=-1) {if (S->PS==0) PHASE=11; else PHASE=6;}
		  break;
		}	
	}
      }
	else if (event->type==SDL_MOUSEMOTION) // MOUSE
{
      SDL_GetMouseState(&S->Mouse_Pos_x, &S->Mouse_Pos_y);

     if ( S->Mouse_Pos_y >= S->Save_Opt[0].y && S->Mouse_Pos_y <= S->Save_Opt[0].y+50)
     {
          if (S->Mouse_Pos_x >= S->Save_Opt[0].x && S->Mouse_Pos_x < S->Save_Opt[0].x+50) {
                 S->PS=0;
          }
          else if (S->Mouse_Pos_x >= S->Save_Opt[1].x && S->Mouse_Pos_x < S->Save_Opt[1].x+50)
          {
		 S->PS=1;
          }
	  else S->PS=-1;
     }
          else S->PS=-1;
}
}
if(S->PS!=-1)
	if(SDL_MOUSEBUTTONDOWN)
		if(event->type==SDL_MOUSEBUTTONDOWN && event->button.button== SDL_BUTTON_LEFT)
			{
			if (S->PS==0) PHASE=11;
			else PHASE=6;
			}
		 if (S->PS!=-1) SDL_BlitSurface(S->Save_Lum,NULL,Screen,&S->Save_Opt[S->PS]);

//---------------------------------------------------------------------------------------------------/
S->PSP=S->PS;
SDL_Flip(Screen);
return PHASE;
}
//-----------------------LOAD---------------------

void Init_Load_Menu(save *S)
{
S->Background_Save=IMG_Load("./src/Image/Save/BackgroundLoad.png");
S->Save_Lum=IMG_Load("./src/Image/Save/Lum.png");
S->Rect_Save.x=200;
S->Rect_Save.y=100;

S->Save_Opt[0].y=254;
S->Save_Opt[0].x=335;

printf("\nSave_O_0_x: %d | Save_O_0_y: %d \n",S->Save_Opt[0].x,S->Save_Opt[0].y);
S->Save_Opt[1].y=254;
S->Save_Opt[1].x=475;

S->Mouse_Pos_y=0;
S->Mouse_Pos_x=0;
S->PS=-1;
S->PSP=-1;
}

int LoadFNCTN(save* S,SDL_Surface* Screen,int* continuer,SDL_Event *event)
{
int PHASE=13;
SDL_BlitSurface(S->Background_Save,NULL,Screen,&S->Rect_Save);
    {
      if ( event->type == SDL_QUIT )  {  (*continuer)= 0;  }

      if ( event->type == SDL_KEYDOWN ) // Bouttons
      {
	switch(event->key.keysym.sym)
	{
        case SDLK_ESCAPE :
	 { PHASE = 6; break; }
	case SDLK_LEFT:
		{ if (S->PS>0) S->PS--;
		  else if (S->PS == -1) S->PS=0;

		  break;
		}
	case SDLK_RIGHT :
		{ if ((S->PS < 1)&&(S->PS>=0)) S->PS++;
		  else if (S->PS == -1) S->PS=1;
		  break;
		}
	case SDLK_RETURN :
		{
		  if(S->PS!=-1) {if (S->PS==0) PHASE=12; else PHASE=1;}
		  break;
		}
	case SDLK_KP_ENTER :
		{
		  if(S->PS!=-1) {if (S->PS==0) PHASE=12; else PHASE=1;}
		  break;
		}	
	}
      }
	else if (event->type==SDL_MOUSEMOTION) // MOUSE
{
      SDL_GetMouseState(&S->Mouse_Pos_x, &S->Mouse_Pos_y);

     if ( S->Mouse_Pos_y >= S->Save_Opt[0].y && S->Mouse_Pos_y <= S->Save_Opt[0].y+50)
     {
          if (S->Mouse_Pos_x >= S->Save_Opt[0].x && S->Mouse_Pos_x < S->Save_Opt[0].x+50) {
                 S->PS=0;
          }
          else if (S->Mouse_Pos_x >= S->Save_Opt[1].x && S->Mouse_Pos_x < S->Save_Opt[1].x+50)
          {
		 S->PS=1;
          }
	  else S->PS=-1;
     }
          else S->PS=-1;
}
}
if(S->PS!=-1)
	if(SDL_MOUSEBUTTONDOWN)
		if(event->type==SDL_MOUSEBUTTONDOWN && event->button.button== SDL_BUTTON_LEFT)
			{
			if (S->PS==0) PHASE=12;
			else PHASE=1;
			}
		 if (S->PS!=-1) SDL_BlitSurface(S->Save_Lum,NULL,Screen,&S->Save_Opt[S->PS]);

//---------------------------------------------------------------------------------------------------/
S->PSP=S->PS;
SDL_Flip(Screen);
return PHASE;
}




 







