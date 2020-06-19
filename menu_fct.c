#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_mixer.h>
#include"SDL/SDL_image.h"
#include<SDL/SDL_ttf.h>
#include "menu_fct.h"

int settings(Mix_Chunk *music,int m)
{
  SDL_Surface*screen_s=NULL;

  SDL_Surface*cursor=NULL;
  SDL_Event e;
  SDL_Rect poscursor;
  SDL_Surface*image1=NULL;
  SDL_Surface*on=NULL;
  SDL_Surface*off=NULL;
  SDL_Rect poson;
  SDL_Rect posoff;
  SDL_Rect posbackground1;

  Mix_Music *BS;
  int f=0;





  int x=0,y=0;
  if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
  {
      printf("unable to set audio: %s",Mix_GetError());
  }

  BS=Mix_LoadMUS("button_click.mp3");
        cursor=IMG_Load("cursor.png");

  if(SDL_BUTTON_LEFT)
  {
    if(m==1)
    {
    on=IMG_Load("on.png");
    }
    else if(m==0)
    {
      on=IMG_Load("off.png");
    }
    if(on==NULL)
    {
        printf("unable to load play: %s\n",SDL_GetError());
    }
    poson.x=150;
    poson.y=600;
    poson.w=200;
    poson.h=100;
    off=IMG_Load("off.png");
    if(off==NULL)
    {
        printf("unable to load play: %s\n",SDL_GetError());
    }
    posoff.x=700;
    posoff.y=600;
    posoff.w=200;
    posoff.h=100;

      int sett=1;
      SDL_Init(SDL_INIT_VIDEO);
      screen_s=SDL_SetVideoMode(1000,1000,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
      if(!screen_s)
      {
          printf("unable to set 600*400 video: %s\n",SDL_GetError());
      }
      image1=IMG_Load("set.png");
      if(image1==NULL)
      {
          printf("unable to set prison background2: %s\n",SDL_GetError());
      }
      posbackground1.x=0;
      posbackground1.y=0;
      posbackground1.w=1000;
      posbackground1.h=1000;
      while(sett)
      {

          SDL_BlitSurface(image1,&posbackground1,screen_s,NULL);
          SDL_BlitSurface(off,&posbackground1,screen_s,&posoff);
          SDL_BlitSurface(on,&posbackground1,screen_s,&poson);
          SDL_BlitSurface(cursor,&posbackground1,screen_s,&poscursor);
          SDL_Flip(screen_s);
          while(SDL_PollEvent(&e))
          {
              switch(e.type)
              {
              case SDL_QUIT:
              {

                  sett=0;
                  break;
              }
              case SDL_KEYDOWN:
              {
                  if(e.key.keysym.sym==SDLK_ESCAPE)
                  {
                      sett=0;
                  }
                else if(e.key.keysym.sym==SDLK_m)
                      {
                        if(m==1)
                        {
                            on=IMG_Load("off.png");
                            Mix_VolumeChunk(music,0);
                            m=0;
                        }
                        else if(m==0)
                        {
                            on=IMG_Load("on.png");
                            Mix_VolumeChunk(music,128);
                            m=1;
                        }
                      }
                  break;
              }
              case SDL_MOUSEMOTION:
              {
                  x=e.motion.x;
                  y=e.motion.y;
                  poscursor.x=x;
                  poscursor.y=y;
                  if((x>150)&&(x<300)&&(y>600)&&(y<680))
                  {
                      Mix_PlayMusic(BS,0);
                  }

                  break;
              }
              case SDL_MOUSEBUTTONDOWN:
              {
                  if((x>150)&&(x<300)&&(y>600)&&(y<680))
                  {

                      if(SDL_BUTTON_LEFT)
                      {
                          if(m==1)
                          {
                              on=IMG_Load("off.png");
                              Mix_VolumeChunk(music,0);
                              m=0;
                          }
                          else if(m==0)
                          {
                              on=IMG_Load("on.png");
                              Mix_VolumeChunk(music,128);
                              m=1;
                          }





                      }
                  }
                  if((x>700)&&(x<850)&&(y>600)&&(y<680))
                  {
                      if(SDL_BUTTON_LEFT)
                      {
                          if(f==0)
                          {
                              off=IMG_Load("on.png");
                              f=1;
                              SDL_WM_ToggleFullScreen(screen_s);
                          }
                          else if(f==1)
                          {
                              off=IMG_Load("off.png");
                              f=0;
                          }
                      }

                  }

              }
              }
SDL_Flip(screen_s);
          }
      }
      SDL_FreeSurface(screen_s);
      SDL_FreeSurface(cursor);
      SDL_FreeSurface(image1);
      SDL_FreeSurface(on);
      SDL_FreeSurface(off);
  }
  return m;
}

void credits()
{
  SDL_Surface*screen_c=NULL;
  SDL_Surface*cursor=NULL;
  SDL_Event z;
  SDL_Rect poscursor;
  int x=0,y=0;

  SDL_Surface*credit_list=NULL;
  SDL_Rect poscredit;
  credit_list=IMG_Load("creditlist.png");
    if(credit_list==NULL)
    {
        printf("unable to load play: %s\n",SDL_GetError());
    }
    poscredit.x=0;
    poscredit.y=0;
    poscredit.w=credit_list->w;
    poscredit.h=credit_list->h;
        cursor=IMG_Load("cursor.png");
  if(SDL_BUTTON_LEFT)
  {
      int c=1;
      SDL_Init(SDL_INIT_VIDEO);
      screen_c=SDL_SetVideoMode(1000,1000,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
      if(!screen_c)
      {
          printf("unable to set 1000*1000 video: %s\n",SDL_GetError());
      }

      while(c)
      {
        if(poscredit.y!=4000)
        {
        poscredit.y++;
        }

          SDL_FillRect(screen_c,0,SDL_MapRGB(screen_c->format,255,0,0));
          SDL_BlitSurface(credit_list,&poscredit,screen_c,NULL);
          SDL_BlitSurface(cursor,NULL,screen_c,&poscursor);
          SDL_Flip(screen_c);
          while(SDL_PollEvent(&z))
          {


              switch(z.type)
              {
              case SDL_QUIT:
              {

                  c=0;
                  break;
              }
              case SDL_KEYDOWN:
              {
                  if(z.key.keysym.sym==SDLK_ESCAPE)
                  {
                      c=0;
                  }
                  break;
              }
              case SDL_MOUSEMOTION:
              {
                  x=z.motion.x;
                  y=z.motion.y;
                  poscursor.x=x;
                  poscursor.y=y;



                  break;
              }

              }

          }


      }
      SDL_FreeSurface(screen_c);
      SDL_FreeSurface(cursor);
      SDL_FreeSurface(credit_list);
  }

}


void play()
{
  SDL_Surface*screen_p=NULL;
  SDL_Surface*cursor=NULL;
  SDL_Event a,event;
  SDL_Rect poscursor;
  int keep=1;
  SDL_Surface*play_mode=NULL;
  SDL_Rect posmode;
  SDL_Surface*down_arrow=NULL;
  SDL_Rect posarrow_d;
  play_mode=IMG_Load("play mode.png");
    if(play_mode==NULL)
    {
        printf("unable to load play: %s\n",SDL_GetError());
    }
    posmode.x=300;
    posmode.y=300;
    posmode.w=200;
    posmode.h=100;
    down_arrow=IMG_Load("down arrow.png");
      if(down_arrow==NULL)
      {
          printf("unable to load play: %s\n",SDL_GetError());
      }
     posarrow_d.x=348;
     posarrow_d.y=352;
     posarrow_d.w=200;
     posarrow_d.h=100;

     SDL_Surface *texte = NULL;

     TTF_Font*police=NULL;
     SDL_Color couleurNoire = {0, 0, 0}, couleurBlanche = {255, 255, 255};
     int continuer = 1;
     int tempsActuel = 0, tempsPrecedent = 0, seconde = 0;
     char *temps; /* Tableau de char suffisamment grand */
     int l=0;
     SDL_Rect position;
     int mi=0,h=0,s=0;

     temps=malloc(2*sizeof(char));

     TTF_Init();


     SDL_WM_SetCaption("Gestion du texte avec SDL_ttf", NULL);

     /* Chargement de la police */
     police = TTF_OpenFont("text.ttf", 50);

     /* Initialisation du temps et du texte */
     tempsActuel = SDL_GetTicks();
     sprintf(temps, "%d:%d:%d",h,mi,s);
     texte = TTF_RenderText_Blended(police, temps, couleurBlanche);
     position.x = 910;
     position.y = 0;



  int x=0,y=0;
  if(SDL_BUTTON_LEFT)
  {

      int p=1;
      cursor=IMG_Load("cursor.png");
      SDL_Init(SDL_INIT_VIDEO);
      screen_p=SDL_SetVideoMode(1000,1000,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
      if(!screen_p)
      {
          printf("unable to set 1000*1000 video: %s\n",SDL_GetError());

      }
      while(p)
      {
          SDL_FillRect(screen_p,0,SDL_MapRGB(screen_p->format,0,0,0));
          SDL_BlitSurface(play_mode,NULL,screen_p,&posmode);
          SDL_BlitSurface(down_arrow,NULL,screen_p,&posarrow_d);
          SDL_BlitSurface(cursor,NULL,screen_p,&poscursor);


          tempsActuel = SDL_GetTicks();
          if (tempsActuel - tempsPrecedent >= 1000) /* Si 100 ms au moins se sont écoulées */
          {
              s+= 1;  /* On rajoute 100 ms au compteur */
              if(s%60==0)
              {
                mi+=1;
                s=0;
                if(mi%60==0)
                {
                  h+=1;
                  mi=0;
                  s=0;
                }
              }


              sprintf(temps, "%d:%d:%d",h,mi,s); /* On écrit dans la chaîne "temps" le nouveau temps */
              l=strlen(temps);
              temps=realloc(temps,sizeof(char)*l);
              SDL_FreeSurface(texte); /* On supprime la surface précédente */
              texte = TTF_RenderText_Blended(police, temps, couleurBlanche); /* On écrit la chaîne temps dans la SDL_Surface */
              tempsPrecedent = tempsActuel; /* On met à jour le tempsPrecedent */

          }




          SDL_BlitSurface(texte, NULL, screen_p, &position); /* Blit du texte */
SDL_Flip(screen_p);
          while(SDL_PollEvent(&a))
          {
              switch(a.type)
              {
              case SDL_QUIT:
              {

                  p=0;
                  break;
              }
              case SDL_KEYDOWN:
              {
                  if(a.key.keysym.sym==SDLK_ESCAPE)
                  {
                      p=0;
                  }
                  else if(a.key.keysym.sym==SDLK_RIGHT)
                  {
                      if(posarrow_d.x<=610)
                      {
                        posarrow_d.x+=132;

                      }
                  }
                  else if(a.key.keysym.sym==SDLK_LEFT)
                  {
                      if(posarrow_d.x>352)
                      {
                        posarrow_d.x-=132;

                      }
                  }
                  break;
              }
              case SDL_MOUSEMOTION:
              {
                  x=a.motion.x;
                  y=a.motion.y;
                  poscursor.x=x;
                  poscursor.y=y;
                  if((x>447)&&(x<557)&&(y>426)&&(y<480))
                  {
                     posarrow_d.x=484;
                  }
                  else if((x>579)&&(x<689)&&(y>426)&&(y<480))
                  {
                     posarrow_d.x=613;
                  }
                  else if((x>311)&&(x<421)&&(y>426)&&(y<480))
                  {
                     posarrow_d.x=352;
                  }
                  break;
              }
              SDL_Flip(screen_p);
              }

          }
      }
      SDL_FreeSurface(screen_p);
      SDL_FreeSurface(cursor);
      SDL_FreeSurface(play_mode);
      SDL_FreeSurface(down_arrow);
      SDL_FreeSurface(texte);
  }
}





int menu()
{


  TTF_Font*police=NULL;
  SDL_Surface*screen=NULL;
  SDL_Surface*text=NULL;
  SDL_Surface*image=NULL;
  SDL_Surface*imageb=NULL;
  SDL_Surface*money=NULL;
  SDL_Surface*imageb1=NULL;
  SDL_Surface*imageP=NULL;
  SDL_Surface*image1=NULL;
  SDL_Surface*menu=NULL;
  SDL_Surface*arrow=NULL;
  SDL_Surface*cursor=NULL;
  SDL_Event event,e,a,z;
  SDL_Rect poscursor;
  SDL_Rect posbackground;
  SDL_Rect posmoney;
  SDL_Rect posbackgroundb;
  SDL_Rect posbackgroundb1;
  SDL_Rect posbackground1;
  SDL_Rect posbackground2;
  SDL_Rect posmenu;
  SDL_Rect posarrow;
  SDL_Rect postext;
  SDL_Rect poson;
  SDL_Rect posoff;
  Mix_Chunk *music;
  Mix_Music *BS;
  char p;
  int keep=1;
  int m=1,f=0;
  int x=0,y=0;

    if(TTF_Init()==-1)
    {
        printf("unable to initilize TTF_Init %s \n",TTF_GetError());
    }
    police=TTF_OpenFont("text.ttf",70);
    SDL_Color black= {255,0,255};
    text=TTF_RenderText_Blended(police,"THE END JUSTIFIES THE MEANS",black);
    postext.x=200;
    postext.y=60;
    postext.w=text->w;
    postext.h=text->h;
    if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
    {
        printf("unable to set audio: %s",Mix_GetError());
    }
    music=Mix_LoadWAV("sound.wav");
    Mix_AllocateChannels(16);
    Mix_VolumeChunk(music,128);
    Mix_PlayChannel(1,music,-1);
    BS=Mix_LoadMUS("button_click.mp3");
    if(SDL_Init(SDL_INIT_VIDEO)!=0)
    {
        printf("unable to initilize SDL:%s\n",SDL_GetError());
        return 1;
    }
    screen=SDL_SetVideoMode(1000,1000,32,SDL_HWSURFACE);
    if(screen==NULL)
    {
        printf("unable to set video mode: %s\n",SDL_GetError());
    }
    image=IMG_Load("background.png");
    if(image==NULL)
    {
        printf("unable to set background: %s\n",SDL_GetError());
        return 1;
    }
    posbackground.x=0;
    posbackground.y=0;
    posbackground.w=image->w;
    posbackground.h=image->h;

    money=IMG_Load("money.png");
    if(money==NULL)
    {
        printf("unable to set money: %s\n",SDL_GetError());
        return 1;
    }
    posmoney.x=0;
    posmoney.y=0;
    posmoney.w=100;
    posmoney.h=100;

    imageb=IMG_Load("background2.png");
    if(imageb==NULL)
    {
        printf("unable to set background2: %s\n",SDL_GetError());
        return 1;
    }
    posbackgroundb.x=0;
    posbackgroundb.y=0;
    posbackgroundb.w=imageb->w;
    posbackgroundb.h=imageb->h;

    imageb1=IMG_Load("background3.png");
    if(imageb1==NULL)
    {
        printf("unable to set background3: %s\n",SDL_GetError());
        return 1;
    }
    posbackgroundb1.x=0;
    posbackgroundb1.y=0;
    posbackgroundb1.w=imageb1->w;
    posbackgroundb1.h=imageb1->h;

    menu=IMG_Load("menu.png");
    if(menu==NULL)
    {
        printf("unable to load menu: %s\n",SDL_GetError());
        return 1;
    }
    posmenu.x=70;
    posmenu.y=260;
    posmenu.w=200;
    posmenu.h=100;

    arrow=IMG_Load("arrow.png");
    if(arrow==NULL)
    {
        printf("unable to load arrow: %s\n",SDL_GetError());
        return 1;
    }
    posarrow.x=00;
    posarrow.y=260;
    posarrow.w=200;
    posarrow.h=100;


    cursor=IMG_Load("cursor.png");
    if(cursor==NULL)
    {
        printf("unable to set cursor icon: %s\n",SDL_GetError());
        return 1;
    }
    poscursor.x=0;
    poscursor.y=0;
    poscursor.w=200;
    poscursor.h=100;


    unsigned int current_t ,previous_t;
unsigned int t,lt=0;



SDL_Surface *texte = NULL;


SDL_Color couleurNoire = {0, 0, 0}, couleurBlanche = {255, 255, 255};

int tempsActuel = 0, tempsPrecedent = 0, seconde = 0;
char *temps; /* Tableau de char suffisamment grand */
int l=0;
SDL_Rect position;
int mi=0,h=0,s=0;

temps=malloc(2*sizeof(char));

TTF_Init();


SDL_WM_SetCaption("Gestion du texte avec SDL_ttf", NULL);

/* Chargement de la police */
police = TTF_OpenFont("text.ttf", 50);

/* Initialisation du temps et du texte */
tempsActuel = SDL_GetTicks();
sprintf(temps, "%d:%d:%d",h,mi,s);
texte = TTF_RenderText_Blended(police, temps, couleurBlanche);
position.x = 910;
position.y = 0;




    while(keep)
    {




        SDL_ShowCursor(0);
        SDL_BlitSurface(imageb1,&posbackgroundb1,screen,NULL);
        SDL_BlitSurface(money,&posbackground,screen,&posmoney);
        SDL_BlitSurface(text,&posbackground,screen,&postext);
        SDL_BlitSurface(menu,&posbackground,screen,&posmenu);
        SDL_BlitSurface(arrow,&posbackground,screen,&posarrow);
        SDL_BlitSurface(cursor,&posbackground,screen,&poscursor);






        tempsActuel = SDL_GetTicks();
        if (tempsActuel - tempsPrecedent >= 2000) /* Si 100 ms au moins se sont écoulées */
        {
            s+= 1;  /* On rajoute 100 ms au compteur */
            if(s%2==0)
            {
              imageb1=IMG_Load("background3.png");
            }
            else
            {
              imageb1=IMG_Load("background2.png");
            }


            sprintf(temps, "%d:%d:%d",h,mi,s); /* On écrit dans la chaîne "temps" le nouveau temps */
            l=strlen(temps);
            temps=realloc(temps,sizeof(char)*l);
            SDL_FreeSurface(texte); /* On supprime la surface précédente */
            texte = TTF_RenderText_Blended(police, temps, couleurBlanche); /* On écrit la chaîne temps dans la SDL_Surface */
            tempsPrecedent = tempsActuel; /* On met à jour le tempsPrecedent */

        }














      if(posmoney.y<500)
      {
       posmoney.y+=3;
      }
      if(posmoney.y>=500)
      {
       posmoney.y=0;
      }
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {

            case SDL_QUIT:
            {
                keep=0;
                break;
            }
            case SDL_KEYDOWN:
            {
                if(event.key.keysym.sym==SDLK_ESCAPE)
                {
                    keep=0;
                }
                else if(event.key.keysym.sym==SDLK_UP)
                {
                    if(posarrow.y>260)
                    {
                      Mix_PlayMusic(BS,0);
                      posarrow.y-=55;

                    }
                }
                else if(event.key.keysym.sym==SDLK_DOWN)
                {
                   if(posarrow.y<413)
                   {
                    Mix_PlayMusic(BS,0);
                     posarrow.y+=55;

                   }
                }
                if(posarrow.y==260)
                {
                  if(event.key.keysym.sym==SDLK_RETURN)
                  {
                    play();
                  }
                }
                else if(posarrow.y==315)
                {
                  if(event.key.keysym.sym==SDLK_RETURN)
                  {
                    m=settings(music,m);
                  }
                }
                else if(posarrow.y==370)
                {
                  if(event.key.keysym.sym==SDLK_RETURN)
                  {
                    credits();
                  }
                }
                else if(posarrow.y==425)
                {
                  if(event.key.keysym.sym==SDLK_RETURN)
                  {
                    keep=0;
                  }
                }

                break;
            }
            case SDL_MOUSEMOTION:
            {
                x=event.motion.x;
                y=event.motion.y;
                poscursor.x=x;
                poscursor.y=y;
                if((x>0)&&(x<318)&&(y>260)&&(y<315))
                {
                  posarrow.y=260;
                  Mix_PlayMusic(BS,0);
                }
                if((x>0)&&(x<318)&&(y>315)&&(y<370))
                {
                  posarrow.y=315;
                  Mix_PlayMusic(BS,0);
                }
                if((x>0)&&(x<318)&&(y>370)&&(y<425))
                {
                  posarrow.y=370;
                  Mix_PlayMusic(BS,0);
                }
                if((x>0)&&(x<318)&&(y>425)&&(y<480))
                {
                  posarrow.y=425;
                  Mix_PlayMusic(BS,0);
                }
                SDL_Flip(screen);

                break;
            }
            case SDL_MOUSEBUTTONDOWN:
            {
                if((x>0)&&(x<318)&&(y>425)&&(y<480))
                {
                        keep=0;
                }
                if((x>0)&&(x<318)&&(y>370)&&(y<425))
                {
                    credits();
                }
                if((x>0)&&(x<318)&&(y>260)&&(y<315))
                {
                    play();

                }
                if((x>0)&&(x<318)&&(y>315)&&(y<370))
                {

                    m=settings(music,m);
                }
                break;
            }
            }
        }
        SDL_Flip(screen);
    }

    SDL_FreeSurface(cursor);
    SDL_FreeSurface(screen);
    SDL_FreeSurface(text);
    SDL_FreeSurface(texte);
    SDL_FreeSurface(image);
    SDL_FreeSurface(imageb1);
    SDL_FreeSurface(menu);
    SDL_FreeSurface(arrow);
    TTF_CloseFont(police);
    Mix_FreeChunk(music);
    SDL_Quit();
    TTF_Quit();
    return 0;
}
