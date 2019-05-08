#ifndef FNC_H_
#define FNC_H_

typedef struct image
{ 
	SDL_Rect positiond;
        
SDL_Rect positionc;
SDL_Surface* back;
           // Position mta3 background
}image;

typedef struct robottt

{

	SDL_Surface *robot[9];
        SDL_Rect positionrobot;

}robottt;

image init_img(char nomimage[100],int x,int y);
void display(SDL_Surface *ecran,image img);
robottt init_perso();
void display_perso(SDL_Surface *ecran,robottt rob,int i,SDL_Rect positionrobot);
void playmusic();
int input(robottt* rob,image* img,int i,int *continuer, int *var);







#endif
