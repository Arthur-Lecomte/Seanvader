/**
 * @file main.cpp
 * @author Lecomte, Leiner, Cazals, Girault, Castillo
 * @date 12/01/2022
 * @version 1.0
 * @brief Rassemble les fichiers afin de faire fonctionner le jeu
*/
#define FPS_LIMIT 60

#include <iostream>
#include <thread>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <map>
#include <algorithm>

#include "mingl/gui/text.h"
#include "mingl/mingl.h"
#include "mingl/gui/sprite.h"
#include "mouvement.h"
#include "projectile.h"
#include "entite.h"
#include "score.h"
#include "srtuctEnsembleDeCleValide.h"
#include "gererJeu.h"

using namespace std;
using namespace nsGraphics;
using namespace nsGui;
using namespace chrono;

/**
 * @brief lireFichier
 * @param config : nom du fichiers yaml
 * @return : renvoie une map contenant les constantes nécessaires au jeu
 */
map <string,char> lireFichier (const string & config){
    map <string,char> mapVal;
    ifstream ifs (config);
    const ensembleDeCleValide Ke {{"haut", "bas", "droite", "gauche", "tirer", "pause"}};


    for (string cle; ifs >> cle ;){
        if (find (Ke.ensembleDeCleEntierNaturel.begin(),
                  Ke.ensembleDeCleEntierNaturel.end(), cle) ==
                Ke.ensembleDeCleEntierNaturel.end())
        {
            string ligne;
            getline (ifs, ligne);
        }
        char doublePoints ;
        ifs >> doublePoints;
        unsigned valeur;
        ifs >> valeur;
        mapVal [cle]=valeur;
    }
    return mapVal;
}

int main()
{
    map <string,char> mapVal=lireFichier("configuration.yaml");
    lireFichier("configuration.yaml");
    unsigned score = 0;
    string nom;
    vector <Sprite> invaderSprite;
    Sprite avion1("img/avion.si2", Vec2D(1, 0));
    Sprite avion2("img/avion.si2", Vec2D(116, 0));
    Sprite avion3("img/avion.si2", Vec2D(231, 0));
    Sprite avion4("img/avion.si2", Vec2D(346, 0));
    Sprite avion5("img/avion.si2", Vec2D(461, 0));
    Sprite avion6("img/avion.si2", Vec2D(1, 75));
    Sprite avion7("img/avion.si2", Vec2D(116, 75));
    Sprite avion8("img/avion.si2", Vec2D(231, 75));
    Sprite avion9("img/avion.si2", Vec2D(346, 75));
    Sprite avion10("img/avion.si2", Vec2D(461, 75));
    invaderSprite={avion1,avion2,avion3,avion4,avion5,avion6,avion7,avion8,avion9,avion10};
    vector <bool> vieInvader;
    vieInvader={true,true,true,true,true,true,true,true,true,true,true};
    unsigned alea=0;
    bool bateauB=true;
    struct missile
    {
        bool vieMissile=false;
        bool posMissile=false;
    };
    missile missileJoueur;
    missile missileInvader;
    missile missileBoss;
    bool joueurPret=false;
    unsigned nombreVague=1;
    bool bossVie=false;
    bool invaderVie=true;
    bool posBoss=false;
    unsigned PVBoss=10;
    MinGL window("Seanvaders", Vec2D(640, 640), Vec2D(128, 128), KBlue);
    window.initGlut();
    window.initGraphic();
    Sprite fond("img/fond.si2", Vec2D(0, 0));
    Sprite imageBateau("img/bateau.si2", Vec2D(256, 400));
    Sprite imageMissileJoueur("img/missile.si2", Vec2D(0, 0));
    Sprite imageMissileInvader("img/missileInvader.si2", Vec2D(0, 0));
    Sprite fondPause("img/fondPause.si2", Vec2D(0,0));
    Sprite imageBoss("img/boss.si2",Vec2D(-1000,-1000));
    Sprite nuke("img/nuke.si2", Vec2D(0,0));
    microseconds frameTime = microseconds::zero();
    while (window.isOpen())
    {
        time_point<steady_clock> start = steady_clock::now();
        window.clearScreen();
        menuEntreePause(window, joueurPret, mapVal["pause"]);
        if (bateauB==false)
        {
            enregistreScore(score,nom);
            break;
        }
        if (joueurPret==false){
            window<<fondPause;
            nom = nom+affichNom(window);
            window << Text(Vec2D(300, 100), nom, KBlack, GlutFont::BITMAP_HELVETICA_18);
            genereScoreboard(window);
        }
        else{
            window<<fond;
            invader(window, invaderSprite, vieInvader, imageMissileJoueur, missileJoueur.vieMissile, missileJoueur.posMissile,score);
            lanceMissile(window,invaderSprite,imageMissileInvader, imageBateau, imageMissileJoueur,imageBoss,nuke, missileJoueur.vieMissile,missileJoueur.posMissile,missileInvader.vieMissile,missileInvader.posMissile,missileBoss.vieMissile,missileBoss.posMissile,alea,mapVal["tirer"]);
            vague(nombreVague,posBoss,invaderVie,bossVie,invaderSprite,imageBoss);
            bato(window,imageBateau,bateauB,imageMissileInvader, nuke, mapVal["haut"], mapVal["bas"], mapVal["droite"], mapVal["gauche"]);
            boss(window,PVBoss,bossVie,imageMissileJoueur,imageBoss,missileJoueur.vieMissile,missileJoueur.posMissile,score);
            window << Text(Vec2D(20, 20), to_string(score), KRed, GlutFont::BITMAP_HELVETICA_18);
        }
        window.finishFrame();
        window.getEventManager().clearEvents();
        this_thread::sleep_for(milliseconds(1000 / FPS_LIMIT) - duration_cast<microseconds>(steady_clock::now() - start));
        frameTime = duration_cast<microseconds>(steady_clock::now() - start);
    }
    return 0;
}
