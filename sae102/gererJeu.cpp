/**
 * @file gererJeu.cpp
 * @author Lecomte, Leiner, Cazals, Girault, Castillo
 * @version 1.0
 * @date 12/01/2022
 * @brief Gère le deroulement du jeu, les vagues, le système de pause.
*/
#include <iostream>
#include "mingl/gui/sprite.h"
#include "mouvement.h"

using namespace std;
using namespace nsGui;
using namespace nsGraphics;

/**
 * @brief Gère le deroulement des vagues
 * @param nombreVague : variables permettant de compter le nombre de vague
 * @param posBoss : booleen permettant de changer la position du boss qu'une seul fois
 * @param invaderVie : etat d'un invader ( mort ou vif )
 * @param bossVie : etat du boss ( mort ou vif )
 * @param invaderSprite : image d'un invader
 * @param imageBoss : image du boss
 */
void vague (unsigned & nombreVague,bool & posBoss,bool & invaderVie,bool & bossVie, vector <Sprite> & invaderSprite, Sprite & imageBoss)
{
    unsigned test=0;
    for (unsigned i=0;i<10;++i)
    {
        Vec2D position(invaderSprite[i].getPosition());
        int temp=position.getY();
        if (temp<0)
        {
            test=test+1;
        }
    }
    if (test==10)
        invaderVie=false;
    if (invaderVie==false && bossVie==false)
    {
        if ((nombreVague+1)%3==0)
        {
            bossVie=true;
            posBoss=true;
            ++nombreVague;
        }
        else
        {
            invaderVie=true;
            ++nombreVague;
        }
    }
    if (invaderVie==true && test==10)
    {
        changeCoordonnee(invaderSprite[0],1,0);
        changeCoordonnee(invaderSprite[1],116,0);
        changeCoordonnee(invaderSprite[2],231,0);
        changeCoordonnee(invaderSprite[3],346,0);
        changeCoordonnee(invaderSprite[4],461,0);
        changeCoordonnee(invaderSprite[5],1,75);
        changeCoordonnee(invaderSprite[6],116,75);
        changeCoordonnee(invaderSprite[7],231,75);
        changeCoordonnee(invaderSprite[8],346,75);
        changeCoordonnee(invaderSprite[9],461,75);
    }
    else if (bossVie==true)
        if (posBoss==true)
        {
            changeCoordonnee(imageBoss,1,0);
            posBoss=false;
        }
}

/**
 * @brief fonction permettant de changer l'etat d'un booleen afin de lancer ou mettre en pause le jeu
 * @param window : fenetre du jeu
 * @param joueurPret : booleen controlant la fenetre de pause du jeu
 * @param pause : constante etant la touche qui permet de changer l'etat de joueur pret
 */
void menuEntreePause(MinGL & window, bool & joueurPret, const char & pause)
{
    if(window.isPressed({' ', false}))
        joueurPret=true;
    if(window.isPressed({pause, false}))
        joueurPret=false;
}
