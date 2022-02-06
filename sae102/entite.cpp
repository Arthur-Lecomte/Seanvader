/**
 * @file entite.cpp
 * @author Lecomte, Leiner, Cazals, Girault, Castillo
 * @version 1.0
 * @date 12/01/2022
 * @brief gère l'apparition des entitees (avion, bateau, boss)
*/
#include "mingl/mingl.h"
#include "mingl/gui/sprite.h"
#include "mouvement.h"
#include "projectile.h"
#include <iostream>

using namespace nsGui;
using namespace std;
using namespace nsGraphics;

/**
 * @brief Gère l'apparition des invaders et leur destruction en cas de collision
 * @param window : fenetre de jeu
 * @param invaderSprite : image d'avion
 * @param vieInvader : etat de l'enemi ( mort ou vif )
 * @param imageMissileJoueur : image d'un missile du joueur
 * @param vieMissileJoueur : etat du missile du joueur ( detruit ou actif )
 * @param posMissileJoueur : booleen permettant de mettre qu'une seul fois la position du missile sur celle du joueur
 * @param score : variable stockant le score du joueur
 */
void invader (MinGL & window,vector <Sprite> & invaderSprite,vector <bool> & vieInvader,Sprite & imageMissileJoueur, bool & vieMissileJoueur, bool & posMissileJoueur, unsigned & score)
{
    for (unsigned i=0;i<10;++i)
    {
        if (collision(invaderSprite[i],64,0,0,imageMissileJoueur)==true)
        {
            vieMissileJoueur=false;
            posMissileJoueur=false;
            setPos(invaderSprite[i],invaderSprite[i],-1000,-1000);
            score=score+10;
        }
        if (vieInvader[i]==true)
        {
            mouvementInvader(invaderSprite[i]);
            window<<invaderSprite[i];
        }
    }
}

/**
 * @brief Gère l'apparition du joueur et ca destruction en cas de collision
 * @param window : fenetre de jeu
 * @param imageBato : image du joueur
 * @param batoB : etat du joueur ( mort ou vif )
 * @param missileInvader : image d'un missile d'un avion
 * @param missileBoss : image d'un missile du boss
 * @param haut : constante stockant les touches permettant au joueur de monter
 * @param bas : constante stockant les touches permettant au joueur de descendre
 * @param droite : constante stockant les touches permettant au joueur d'aller a droite
 * @param gauche : constante stockant les touches permettant au joueur d'aller a gauche
 */
void bato (MinGL & window,Sprite & imageBato,bool & batoB,Sprite & missileInvader,Sprite & missileBoss,const char & haut, const char & bas, const char & droite, const char & gauche)
{
    if (batoB==true)
    {
        mouvementJoueur(window,imageBato,haut,bas,droite,gauche);
        window<<imageBato;
    }
    if (collision(imageBato,64,0,0,missileInvader)==true || collision(missileBoss,104,0,0,imageBato)==true || collision(missileBoss,104,0,50,imageBato)==true )
        batoB=false;
}

/**
 * @brief Gère l'apparition du boss, de son nombre de point de vie et de ca destruction
 * @param window : fenetre de jeu
 * @param PV : nombre de point de vie du boss
 * @param bossVie : etat du boss ( mort ou vif )
 * @param imageMissileJoueur : image d'un missile du joueur
 * @param imageBoss : image du boss
 * @param vieMissileJoueur : etat du missile ( detruit ou actif )
 * @param posMissileJoueur : booleen permettant de mettre qu'une seul fois la position du missile sur celle du joueur
 * @param score : variable stockant le score du joueur
 */
void boss(MinGL & window,unsigned & PV,bool & bossVie,Sprite & imageMissileJoueur, Sprite & imageBoss, bool & vieMissileJoueur, bool & posMissileJoueur, unsigned & score)
{
    window<<imageBoss;
    mouvementBoss(imageBoss );
    if (collision(imageBoss,111,0,0,imageMissileJoueur)==true || collision(imageBoss,111,111,0,imageMissileJoueur)==true || collision(imageBoss,111,222,0,imageMissileJoueur)==true || collision(imageBoss,111,333,0,imageMissileJoueur)==true || collision(imageBoss,111,348,0,imageMissileJoueur)==true)
    {
        cout<<PV<<endl;
        changeCoordonnee(imageMissileJoueur,1000,1000);
        vieMissileJoueur=false;
        posMissileJoueur=false;
        --PV;
    }
    if (PV<=0)
    {
        bossVie=false;
        changeCoordonnee(imageBoss,-1000,-1000);
        PV=10;
        score=score+100;
    }
}
