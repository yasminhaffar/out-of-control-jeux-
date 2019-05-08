#ifndef FNC_H_
#define FNC_H_

typedef struct image
{ 
	SDL_Rect positiond;
	SDL_Rect positionc;
        SDL_Surface* back;
SDL_Surface* Num;
           // Position mta3 background
}image;

typedef struct robottt

{

	SDL_Surface *robot[9];
        SDL_Rect positionrobot;

}robottt;
typedef struct 
{
SDL_Surface* Background_Save;
SDL_Surface* Save_Lum;
SDL_Rect Rect_Save;
SDL_Rect Save_Opt[2];
int Mouse_Pos_y;
int Mouse_Pos_x;
int PS;
int PSP;
}save;

image init_img(char nomimage[100],int x,int y);
void display(SDL_Surface *ecran,image img);
robottt init_perso();
void display_perso(SDL_Surface *ecran,robottt rob,int i,SDL_Rect positionrobot);
void playmusic();
int input(robottt *rob,int i,int *continuer);
int scrolling (robottt *rob,image *img,int i,int *pos);
void Save_robottt(robottt C,char Dir[100]);
void Save_image(image M,char Dir[100]);
void Save(robottt C, image M, char Dir[100]);
void Init_Save_Menu(save *S);
int SaveFNCTN(save* S,SDL_Surface* Screen,int* continuer,SDL_Event *event);
void Load_robot(robottt *rob,char Dir[100]);
void Load_Map(image *img,char Dir[100]);
void Load(robottt *rob, image *img, char Dir[100]);
void Init_Load_Menu(save *S);
int LoadFNCTN(save* S,SDL_Surface* Screen,int* continuer,SDL_Event *event);








#endif
