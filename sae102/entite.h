#ifndef ENTITE_H
#define ENTITE_H
#include "mingl/mingl.h"
#include "mingl/gui/sprite.h"

void invader (MinGL &,std::vector <nsGui::Sprite> &,std::vector <bool> &,nsGui::Sprite &, bool &, bool &, unsigned &);
void bato (MinGL &, nsGui::Sprite &, bool &, nsGui::Sprite &, nsGui::Sprite &,const char &, const char &, const char &, const char &);
void boss (MinGL &, unsigned &, bool &, nsGui::Sprite &, nsGui::Sprite &, bool &, bool &, unsigned &);
#endif // ENTITE_H
