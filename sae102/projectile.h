#ifndef PROJECTILE_H
#define PROJECTILE_H
#include <vector>
#include "mingl/mingl.h"
#include "mingl/gui/sprite.h"

bool collision(nsGui::Sprite &,const unsigned &,const unsigned &,const unsigned &,nsGui::Sprite &);
void lanceMissileJoueur(MinGL &, bool &, bool &,nsGui::Sprite &,nsGui::Sprite &,const char &);
void lanceMissileInvader(MinGL &,bool &,bool &,std::vector <nsGui::Sprite> &, nsGui::Sprite &, unsigned &);
void lanceMissileBoss (MinGL &, bool &, bool &,nsGui::Sprite &, nsGui::Sprite &);
void lanceMissile(MinGL &, std::vector <nsGui::Sprite> &, nsGui::Sprite &, nsGui::Sprite &, nsGui::Sprite &, nsGui::Sprite &, nsGui::Sprite &, bool &, bool &, bool &, bool &, bool &, bool &, unsigned &, const char &);
#endif // PROJECTILE_H
