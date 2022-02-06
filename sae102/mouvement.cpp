/**
 * @file mouvement.cpp
 * @author Lecomte, Leiner, Cazals, Girault, Castillo
 * @version 1.0
 * @date 12/01/2022
 * @brief gère les mouvements de toutes les entitees(avion, bateau, boss)
*/
#include "mingl/mingl.h"
#include "mingl/gui/sprite.h"
#include <iostream>

using namespace nsGui;
using namespace std;
using namespace nsGraphics;

/**
 * @brief permet de faire avancer un sprite selon une distance et un autre sprite
 * @param image : image a bouger
 * @param image2 : point de reference pour image
 * @param distanceX : distance a parcourir sur l'axe X
 * @param distanceY : distance a parcourir sur l'axe Y
 */
void setPos(Sprite & image,Sprite & image2, const int distanceX, const int distanceY)
{
    //fonction permettant de changer la position d'un sprite
    Vec2D position2(image2.getPosition());
    int imageX=position2.getX()+distanceX;
    int imageY=position2.getY()+distanceY;
    Vec2D positionModif(imageX, imageY);
    image.setPosition(positionModif);
}

/**
 * @brief permet de changer les coordonnees d'un sprite
 * @param image : image a bouger
 * @param coordonneeX : coordonnee sur l'axe X de l'image
 * @param coordonneeY : coordonnee sur l'axe Y de l'image
 */
void changeCoordonnee(Sprite & image,const int coordonneeX, const int coordonneeY)
{
    Vec2D position(image.getPosition());
    int imageX=coordonneeX;
    int imageY=coordonneeY;
    Vec2D positionModif(imageX,imageY);
    image.setPosition(positionModif);
}

/**
 * @brief mouvement automatique de l'invader selon ca position
 * @param avion : image de l'avion
 */
void mouvementInvader(Sprite & avion)
{
    //mouvement de l'invader par rapport a ca position
    Vec2D position(avion.getPosition());
    int imageX = position.getX();
    int imageY = position.getY();
    if (imageY%2==0)
    {
        if (imageX%115==0)
            setPos(avion,avion,-1,15);
        else
            setPos(avion,avion,1,0);
    }
    else
    {
        if (imageX%115==0)
            setPos(avion,avion,1,15);
        else
            setPos(avion,avion,-1,0);
    }
}

/**
 * @brief mouvement du joueur selon la touche enfoncee
 * @param window : fenetre de jeu
 * @param bato : image du joueur
 * @param haut : constante stockant la touche a enfoncer pour monter
 * @param bas : constante stockant la touche a enfoncer pour descendre
 * @param droite : constante stockant la touche a enfoncer pour aller a droite
 * @param gauche : constante stockant la touche a enfoncer pour aller a gauche
 */
void mouvementJoueur(MinGL &window,Sprite & bato,const char & haut, const char & bas, const char & droite, const char & gauche)
{
    Vec2D position(bato.getPosition());
    int imageX = position.getX();
    int imageY = position.getY();
    if (window.isPressed({haut, false}))
        if(imageY > 400)
            setPos(bato,bato,0,-3);
    if (window.isPressed({bas, false}))
        if(imageY < 576)
            setPos(bato,bato,0,3);
    if (window.isPressed({gauche, false}))
        if(imageX > 0)
            setPos(bato,bato,-3,0);
    if (window.isPressed({droite, false}))
        if(imageX < 1216)
            setPos(bato,bato,3,0);
}

/**
 * @brief mouvement du boss selon ca position
 * @param boss : image du boss
 */
void mouvementBoss (Sprite & boss)
{
    Vec2D position(boss.getPosition());
    int imageX = position.getX();
    int imageY = position.getY();
    if (imageY%2==0)
    {
        if (imageX%181==0)
            setPos(boss,boss,-1,15);
        else
            setPos(boss,boss,1,0);
    }
    else
    {
        if (imageX%181==0)
            setPos(boss,boss,1,15);
        else
            setPos(boss,boss,-1,0);
    }
}
