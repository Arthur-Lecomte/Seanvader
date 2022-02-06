/**
 * @file score.cpp
 * @author Lecomte, Leiner, Cazals, Girault, Castillo
 * @date 12/01/2022
 * @version 1.0
 * @brief Gère le tri et l'affichage des scores.
*/
#include <iostream>
#include <vector>
#include <fstream>


#include "mingl/gui/text.h"
#include "mingl/mingl.h"

using namespace std;
using namespace nsGui;
using namespace nsGraphics;

/**
 * @brief permet la saisie et l'affichage du nom du joueur
 * @param window : fenetre du jeu
 * @return renvoie le nom du joueur
 */
string affichNom(MinGL & window){
    string nomJoueur;
    if (window.isPressed({'a', false})) {
        window.resetKey({'a', false});
        nomJoueur+= "A";
    }else if(window.isPressed({'b', false})) {
        window.resetKey({'b', false});
        nomJoueur+= "B";
    }else if(window.isPressed({'c', false})) {
        window.resetKey({'c', false});
        nomJoueur+= "C";
    }else if(window.isPressed({'d', false})) {
        window.resetKey({'d', false});
        nomJoueur+= "D";
    }else if(window.isPressed({'e', false})) {
        window.resetKey({'e', false});
        nomJoueur+= "E";
    }else if(window.isPressed({'f', false})) {
        window.resetKey({'f', false});
        nomJoueur+= "F";
    }else if(window.isPressed({'g', false})) {
        window.resetKey({'g', false});
        nomJoueur+= "G";
    }else if(window.isPressed({'h', false})) {
        window.resetKey({'h', false});
        nomJoueur+= "H";
    }else if(window.isPressed({'i', false})) {
        window.resetKey({'i', false});
        nomJoueur+= "I";
    }else if(window.isPressed({'j', false})) {
        window.resetKey({'j', false});
        nomJoueur+= "J";
    }else if(window.isPressed({'k', false})) {
        window.resetKey({'k', false});
        nomJoueur+= "K";
    }else if(window.isPressed({'l', false})) {
        window.resetKey({'l', false});
        nomJoueur+= "L";
    }else if(window.isPressed({'m', false})) {
        window.resetKey({'m', false});
        nomJoueur+= "M";
    }else if(window.isPressed({'n', false})) {
        window.resetKey({'n', false});
        nomJoueur+= "N";
    }else if(window.isPressed({'o', false})) {
        window.resetKey({'o', false});
        nomJoueur+= "O";
    }else if(window.isPressed({'p', false})) {
        window.resetKey({'p', false});
        nomJoueur+= "P";
    }else if(window.isPressed({'q', false})) {
        window.resetKey({'q', false});
        nomJoueur+= "Q";
    }else if(window.isPressed({'r', false})) {
        window.resetKey({'r', false});
        nomJoueur+= "R";
    }else if(window.isPressed({'s', false})) {
        window.resetKey({'s', false});
        nomJoueur+= "S";
    }else if(window.isPressed({'t', false})) {
        window.resetKey({'t', false});
        nomJoueur+= "T";
    }else if(window.isPressed({'u', false})) {
        window.resetKey({'u', false});
        nomJoueur+= "U";
    }else if(window.isPressed({'v', false})) {
        window.resetKey({'v', false});
        nomJoueur+= "V";
    }else if(window.isPressed({'w', false})) {
        window.resetKey({'w', false});
        nomJoueur+= "W";
    }else if(window.isPressed({'x', false})) {
        window.resetKey({'x', false});
        nomJoueur+= "X";
    }else if(window.isPressed({'y', false})) {
        window.resetKey({'y', false});
        nomJoueur+= "Y";
    }else if(window.isPressed({'z', false})) {
        window.resetKey({'z', false});
        nomJoueur+= "Z";
    }
    cout << nomJoueur;
    return nomJoueur;
}

/**
 * @brief tri les veteurs de noms et de scores
 * @param names : vecteur de nom
 * @param scores : vecteur de score
 */
void dataSort(vector<string> &names, vector<unsigned> &scores)
{
    for(size_t i=0;i<names.size();i++){
        for(size_t j=0;j<names.size();j++){
            if(scores[i]>scores[j]){
                unsigned tempscore=scores[i];
                scores[i]=scores[j];
                scores[j]=tempscore;
                string tempname=names[i];
                names[i]=names[j];
                names[j]=tempname;
            }
        }
    }
}

/**
 * @brief extrait les noms et scores de leur fichiers vers des vecteurs puis les affichent une fois trie
 * @param window : fenetre du jeu
 */
void genereScoreboard(MinGL &window) {
    ifstream score_name("nom.txt");

    vector<string> player;
    string name;
    while(score_name >> name)
        player.push_back(name);

    ifstream score_point("score.txt");

    vector<unsigned> score;
    unsigned points;
    while (score_point >> points)
        score.push_back(points);
    dataSort(player, score);
    vector<string> scoreInString;
    for (unsigned i = 0; i<10; ++i) {
        scoreInString.push_back(to_string(score[i]));
        window << Text(Vec2D(260, 350+(30*i)), player[i], KBlack, GlutFont::BITMAP_HELVETICA_18)
               << Text(Vec2D(360, 350+(30*i)), scoreInString[i], KBlack, GlutFont::BITMAP_HELVETICA_18);
    }
}

/**
 * @brief ecrit le score et le nom dans leur fichier respectifs
 * @param score : score du joueur
 * @param nom : nom du joueur
 */
void enregistreScore(unsigned & score,string & nom)
{
    ofstream fichierScore("score.txt", ios::app);
    ofstream fichierNom("nom.txt", ios::app);
    if(fichierScore && fichierNom){
        fichierScore << score << endl;
        fichierNom << nom << endl;
    }
    else
    {
        cerr << "Error!";
    }
}
