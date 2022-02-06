/**
 * @file projectile.cpp
 * @author Lecomte, Leiner, Cazals, Girault, Castillo
 * @date 12/01/2022
 * @version 1.0
 * @brief Gère l'apparition et les collisions des projectiles des joueurs et des ennemis.
*/
#include "mingl/mingl.h"
#include "mingl/gui/sprite.h"
#include "mouvement.h"
#include <iostream>

using namespace nsGui;
using namespace std;
using namespace nsGraphics;

/**
 * @brief renvoie un booleen selon si un Vec2D est a l'interieur d'une boite de collision
 * @param boite : image etant la boite de collsion
 * @param tailleSprite : entier permettant de determiner la taille de la boite de collision
 * @param decalageX : entier permettant de decaler la boite sur l'axe X
 * @param decalageY : entier permettant de decaler la boite sur l'axe Y
 * @param collisionneur : image dont on tire un Vecd2D
 */
bool collision(Sprite & boite,const unsigned & tailleSprite,const unsigned & decalageX,const unsigned & decalageY,Sprite & collisionneur)
{
    //fonction permettant de detecter la collision entre un sprite et un point (Vec2D)
    Vec2D temp(boite.getPosition());
    unsigned tempX=temp.getX()+decalageX;
    unsigned tempY=temp.getY()+decalageY;
    Vec2D firstCorner(tempX,tempY);
    tempX=firstCorner.getX()+tailleSprite+decalageX;
    tempY=firstCorner.getY()+tailleSprite+decalageY;
    Vec2D secondCorner(tempX, tempY);
    Vec2D positionC(collisionneur.getPosition());
    if((firstCorner.getX()<=positionC.getX() && firstCorner.getY()<=positionC.getY()) && (secondCorner.getX()>=positionC.getX() && secondCorner.getY()>=positionC.getY()))
    {
        return true;
    }
    return false;
}

/**
 * @brief permet au joueur de tirer un missile depuis l'image du joueur
 * @param window : fenetre du jeu
 * @param vieMissileJoueur : etat d'un missile du joueur
 * @param posMissileJoueur : booleen permettant de mettre la position du missile une seul fois sur le joueur
 * @param bato : image du Joueur
 * @param missile : image du missile
 * @param tirer : constante contenant le touche a actionner pour tirer un missile
 */
void lanceMissileJoueur(MinGL &window, bool & vieMissileJoueur, bool & posMissileJoueur,Sprite & bato,Sprite & missile,const char & tirer)
{
    //Missile envoye grace a la touche espace
    Vec2D positionM(missile.getPosition());
    int tempYM=positionM.getY();
    if (window.isPressed({tirer, false}))
        vieMissileJoueur=true;
    if (vieMissileJoueur==true)
    {
        if (posMissileJoueur==false)
        {
            missile.setPosition(bato.getPosition());
        }
        posMissileJoueur=true;
        window << missile;
        setPos(missile,missile,0,-5);
    }
    if (tempYM<0)
    {
        vieMissileJoueur=false;
        posMissileJoueur=false;
    }
}

/**
 * @brief permet au invader de tirer des missiles aleatoirement
 * @param window : fenetre du jeu
 * @param vieMissileInvader : etat du missile de l'invader
 * @param posMissile : booleen permettant de mettre la position du missile une seul fois sur un invader
 * @param invaderSprite : image d'un invader
 * @param missile : image du missile d'un invader
 * @param alea : variable aleatoire permettant de choisir un invader qui va tirer
 */
void lanceMissileInvader(MinGL & window,bool & vieMissileInvader,bool & posMissile,vector <Sprite> & invaderSprite, Sprite & missile, unsigned & alea)
{
    Vec2D positionM(missile.getPosition());
    int tempYM=positionM.getY();
    if (vieMissileInvader==false)
    {
        srand((unsigned int)time(0));
        alea=(rand()%9);
        vieMissileInvader=true;
    }
    if (vieMissileInvader==true)
    {
        if (posMissile==false)
            setPos(missile,invaderSprite[alea],32,65);
        posMissile=true;
        window << missile;
        setPos(missile,missile,0,5);
    }
    if (tempYM>640 || tempYM<0)
    {
        vieMissileInvader=false;
        posMissile=false;
    }
}

/**
 * @brief permet au bosser de tirer un missile
 * @param window : fenetre de jeu
 * @param vieMissileBoss : etat du missile du boss
 * @param posMissileBoss : booleen permettant de mettre la position du missile une seul fois sur le boss
 * @param imageBoss : image du boss
 * @param missile : image du missile du boss
 */
void lanceMissileBoss (MinGL & window, bool & vieMissileBoss, bool & posMissileBoss,Sprite & imageBoss, Sprite & missile)
{
    Vec2D positionM(missile.getPosition());
    int tempYM=positionM.getY();
    if (vieMissileBoss==false)
    {
        vieMissileBoss=true;
    }
    if (vieMissileBoss==true)
    {
        if (posMissileBoss==false)
            setPos(missile,imageBoss,229,55);
        posMissileBoss=true;
        window<<missile;
        setPos(missile,missile,0,3);
    }
    if (tempYM>900 || tempYM<0)
    {
        vieMissileBoss=false;
        posMissileBoss=false;
    }
}

/**
 * @brief fonction lancant toutes les autres fonctions qui lance des missiles
 * @param window : fenetre de jeu
 * @param invaderSprite : image d'un invader
 * @param imageMissileInvader : image du missile d'un invader
 * @param imageBateau : image du joueur
 * @param imageMissileJoueur : image du missile du joueur
 * @param imageBoss : image du boss
 * @param imageBossMissile : image du missile du boss
 * @param vieMissileJoueur : etat d'un missile du joueur
 * @param posMissileJoueur : booleen permettant de mettre la position du missile une seul fois sur le joueur
 * @param vieMissileInvader : etat du missile d'un invader
 * @param posMissileInvader : booleen permettant de mettre la position du missile une seul fois sur un invader
 * @param vieMissileBoss : etat du missile d'un boss
 * @param posMissileBoss : booleen permettant de mettre la position du missile une seul fois sur le boss
 * @param alea : variable aleatoire permettant de choisir un invader qui va tirer
 * @param tirer : constante contenant le touche a actionner pour tirer un missile
 */
void lanceMissile(MinGL & window, vector <Sprite> & invaderSprite,Sprite & imageMissileInvader,Sprite & imageBateau, Sprite & imageMissileJoueur,Sprite & imageBoss,Sprite & imageBossMissile, bool & vieMissileJoueur, bool & posMissileJoueur, bool & vieMissileInvader, bool & posMissileInvader,bool & vieMissileBoss,bool & posMissileBoss, unsigned & alea, const char & tirer)
{
    lanceMissileInvader(window, vieMissileInvader, posMissileInvader,invaderSprite,imageMissileInvader,alea);
    lanceMissileJoueur(window, vieMissileJoueur, posMissileJoueur,imageBateau,imageMissileJoueur,tirer);
    lanceMissileBoss(window, vieMissileBoss, posMissileBoss, imageBoss,imageBossMissile);
}
