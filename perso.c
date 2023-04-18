#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "perso.h"

void initialiser_imageBACK(image *imge){
    imge->url="set.jpg";
    imge->img=IMG_Load(imge->url);
    if(imge->img == NULL){
        printf("unable to load background image %s \n",SDL_GetError());
        return;
    }
    imge->pos_img_ecran.x=0;
    imge->pos_img_ecran.y=0;
    imge->pos_img_affice.h=SCREEN_H;
    imge->pos_img_affice.w=SCREEN_W;
}

/*void init (Personne * p, int numperso)
{

}*/

void initPerso(Personne *p)
{
p->url="right.png";
        p->perso=IMG_Load(p->url);
        if(p->perso == NULL){
        printf("unable to load perso's image %s \n",SDL_GetError());
        return;
    }
    p->x = 120;
    p->y = 650;
    p->w = 20;
    p->h = 20;
p->pos.x=120;
p->pos.y=650;
p->vitesse=1;
p->direction=1;

p->acceleration=0;
p->up=0 ;
p->vitesse_x=1;
p->vitesse_saut=-4,5;
p->vitesse_y=p->vitesse_saut;
p->time=TIME;
p->nbr=0;
}


void afficher_imageBMP(SDL_Surface *screen,image imge)
{
SDL_BlitSurface(imge.img,&imge.pos_img_affice,screen,&imge.pos_img_ecran);
}
void afficherPerso(Personne *p, SDL_Surface * screen)
{
SDL_Rect pos1,pos2;
pos1.x=p->pos.x;
pos1.y=p->pos.y;
pos1.w=p->pos.w;
pos1.h=p->pos.h;

pos2.x=p->nbr*160;
pos2.y=0;
pos2.w=160;
pos2.h=160;







SDL_BlitSurface(p->sprite,&pos2,screen,&pos1);

}

void movePerso (Personne *p, Uint32 dt)
{
double dx = 0.5 * p->acceleration * dt * dt + p->vitesse * dt ;
   
    if (p->direction ==1)
    {
    {
    p->pos.x += dx;
    }
     if (p->up!=walk_right)
    {
    	p->up=walk_right;
    	p->sprite=IMG_Load("right.png");
    }
    }
    else if(p->direction==0){
    {
    p->pos.x -= dx;
    }
    if (p->up!=walk_left)
    {
    	p->up=walk_left;
    	p->sprite=IMG_Load("left.png");
    }
    }
    if(p->up==0)
    {
    	p->pos.y-=SAUT_HAUTEUR;
           if (p->pos.y<0)
             {
    	        p->pos.y=0;
             }if ((p->up=0)&&(p->direction==1))
    {
    	p->up=walk_right;
    	p->sprite=IMG_Load("walk right.png");
    }
    }        
    p->pos.y+=gravite_vitesse;
    
     if ((p->pos.y<MAX_FALL_SPEED)&&(p->direction==1))
    {
    	p->pos.x+=p->vitesse_x;
    	p->vitesse_y+=gravite_vitesse;
    	if (p->up!=walk_right)
    {
    	p->up=walk_right;
    	p->sprite=IMG_Load("walk right.png");
    }
    }
    else if ((p->pos.y<MAX_FALL_SPEED)&&(p->direction==0))
    {
    	p->pos.x-=p->vitesse_x;
    	p->vitesse_y+=gravite_vitesse;
    	if (p->up!=walk_left)
    {
    	p->up=walk_left;
    	p->sprite=IMG_Load("walk left.png");
    }
 
     }
    if (p->pos.y =MAX_FALL_SPEED)
    {
    	p->pos.y=MAX_FALL_SPEED;
    }
    if(p->pos.x>=SCREEN_W-192){
    	p->pos.x=SCREEN_W-192;
    }
    if(p->pos.x<=0){
    	p->pos.x=0;
    }
	
    
}

void animerPerso (Personne* p)
{
	if (p->time<=0)
	{
		p->nbr++;
		p->time=TIME;
		
		if (p->nbr >=p->sprite->w/160)
		{
			p->nbr=0;
		}
		
	}
	else
	{
		p->time--;
	}

}




void saut(Personne *p,int dt, int posinit)
{
double dx = 0.5 * p->acceleration * dt * dt + p->vitesse * dt ;
int seuil=500;
if (p->pos.y != seuil && p->up==1)
{
p->pos.y -= dx;
}
if(p->pos.y == seuil)
{
p->up=2;
}
if (p->pos.y != posinit &&p->up==2)
{
p->pos.y += dx;
}
if(p->pos.y == posinit)
{
p->up=0;
}
p->vitesse += p->acceleration * dt;

}
void liberer_image(image imge)    
{
    SDL_FreeSurface(imge.img);
}
void liberer_perso(Personne p)
{
    SDL_FreeSurface(p.perso);
}


