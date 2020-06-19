#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED



void play();
void credits();
int settings(Mix_Chunk *music,int m);
void cursor_img(SDL_Surface*screen , SDL_Rect posbackground);
int menu();
void animate(char*text);
void timer(SDL_Surface *ecran,SDL_Rect position,int *s,int*h,int*m);









#endif // HEADER_H_INCLUDED
