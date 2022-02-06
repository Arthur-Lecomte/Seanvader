#ifndef SCORE_H
#define SCORE_H
#include "mingl/mingl.h"
#include <vector>

std::string affichNom(MinGL &);
void dataSort(std::vector <std::string> &, std::vector <unsigned> &);
void genereScoreboard(MinGL &);
void enregistreScore(unsigned &,std::string &);
#endif // SCORE_H
