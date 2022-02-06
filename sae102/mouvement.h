#ifndef MOUVEMENT_H
#define MOUVEMENT_H
#include "mingl/mingl.h"
#include "mingl/gui/sprite.h"

void setPos(nsGui::Sprite &,nsGui::Sprite &, const int, const int);
void changeCoordonnee(nsGui::Sprite &,const int, const int);
void mouvementInvader(nsGui::Sprite &);
void mouvementJoueur(MinGL &,nsGui::Sprite &,const char &, const char &, const char &, const char &);
void mouvementBoss (nsGui::Sprite &);

#endif // MOUVEMENT_H
