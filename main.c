#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "perso.h"

int main()
{
    SDL_Surface *screen;
    image IMAGE;
    Personne p;
    int posinit=p.pos.y;

   
    int boucle=1;
   
    SDL_Event event;
   
    if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER)==-1)
    {
    printf("COuld not initialize SDL : %s \n",SDL_GetError());
        return -1;
    }
    screen=SDL_SetVideoMode(SCREEN_W,SCREEN_H,32,SDL_SWSURFACE|SDL_DOUBLEBUF);  
   
    initialiser_imageBACK(&IMAGE);
    initPerso(&p);
   
    Uint32 dt ,t_prev;
   
  while(boucle)
    {
    t_prev = SDL_GetTicks();
    afficher_imageBMP(screen,IMAGE);
    afficherPerso(p,screen);
    while(SDL_PollEvent(&event))
    movePerso(&p, dt);
        {
            switch(event.type)
            {
                  case SDL_QUIT :
                    {
                    boucle=0;
                    break;
                    }
      case SDL_KEYDOWN:
      {
	switch (event.key.keysym.sym)
	{
		case SDLK_ESCAPE:
   	{
    		boucle=0;
    		break;
    	}
    		case SDLK_LEFT:
		{
			p.direction=0;
			//p.acceleration -= 0.01;
			movePerso(&p, dt);
			break;
		}
		case SDLK_RIGHT:
		{
   			p.direction=1;
   			//p.acceleration += 0.005;
   			movePerso(&p, dt);
			break;
		}
		case SDLK_SPACE:
		{
    			p.up=1;
    			saut(&p,dt,posinit) ;
			break;
		}
		case SDLK_e:
		{
   			//p.direction=1;
   			p.acceleration += 2;
   			movePerso(&p, dt);
			break;
		}
	}
     }
         
     /*case SDL_KEYUP:
     switch(event.key.keysym.sym)
     {
	case SDLK_SPACE:
	p.up=0;
	break;
     } 
		break;  */

	//p.acceleration -= 0.001;
        dt = SDL_GetTicks() - t_prev;
       
 } 
    SDL_Flip(screen);
    }
    }
   
   
   
    
    liberer_image(IMAGE);
    liberer_perso(p);
   
   
    SDL_Quit();
    return 0;
}


