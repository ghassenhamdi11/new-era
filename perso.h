#ifndef PERSO_H_INCLUDED
#define PERSO_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#define SCREEN_H 1000
#define SCREEN_W 1800
#define SAUT_HAUTEUR 13
#define gravite_vitesse 4
#define MAX_FALL_SPEED 200



typedef struct
{
    char *url;
    SDL_Rect pos_img_affice;
    SDL_Rect pos_img_ecran;
    SDL_Surface *img;
}image;

typedef struct
{
int x, y;          
    int w, h;
char *url;
    SDL_Surface *perso;
    SDL_Rect pos;
double vitesse,acceleration;
int direction;
int up;    
int vitesse_saut,vitesse_y,vitesse_x;    
}Personne;


void initialiser_imageBACK(image *imge);
//void init (Personne * p, int numperso);
void initPerso(Personne *p);
void afficher_imageBMP(SDL_Surface *screen,image imge);
void afficherPerso(Personne p, SDL_Surface * screen);
void movePerso (Personne *p,Uint32 dt);
void animerPerso (Personne* p);
void saut(Personne *P,int dt, int posinit);
void liberer_image(image imge);
void liberer_perso(Personne p);


#endif


