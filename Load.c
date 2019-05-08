/**
*@file Load.c
*/

#include "Header/Header.h"

/**
*@brief load character
*@param C character , Dir compteur
*/

void Load_robot(robottt *rob,char Dir[100])
{ FILE* f=fopen(Dir,"rb");
robottt tmp;
fread(&tmp,sizeof(Character),1,f);
rob->Rect_positionrobot=tmp.Rect_positionrobot;
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
image img;
fread(&tmp,sizeof(Map),1,f);
img->Rect_positiond=tmp.Rect_positiond;
img->Rect_positionc=tmp.Rect_positionc;
img->Num_Map=tmp.Num;
sprintf(Dir,"./src/Image/Maps/Level%d/image000.png",img->Num);
printf("%s",Dir);
img->back=IMG_Load(Dir);
/*M->Background_Map=zoomSurface(M->Background_Map,0.45,0.45,0);
sprintf(Dir,"./src/Image/Mask/Level%d/image000.png",M->Num_Map);
M->Mask_Map=IMG_Load(Dir);
M->Mask_Map=zoomSurface(M->Mask_Map,0.45,0.45,0);
*/
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

