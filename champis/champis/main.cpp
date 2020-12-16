//
//  main.cpp
//  champis
//
//  Created by Dr Mahike on 28.10.20.
//  Copyright © 2020 Dr Mahike. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    
    cout << "Pensez à un champignon : amanite tue-mouches, pied bleu, girolle, cèpe de Bordeaux, coprin chevelu ou agaric jaunissant." << endl;
    cout << "" << endl;
    
    string q_lamelles = "Est-ce que votre champignon a des lamelles (1 : oui, 0 : non) ? ";
    string q_foret =  "Est-ce que votre champignon vit en forÃªt (1 : oui, 0 : non) ? ";
    string q_chapeau =  "Est-ce que votre champignon a un chapeau convexe (1 : oui, 0 : non) ? ";
    string q_anneau =  "Est-ce que votre champignon a un anneau (1 : oui, 0 : non) ? ";
    
    string agaric = "l'agaric jaunissant";
    string mouches = "l'amanite tue-mouches";
    string bordeaux = "le cÃ¨pe de Bordeaux";
    string coprin = "le coprin chevelu";
    string girolle = "la girolle";
    string pied_bleu = "le pied bleu";
    
    string endsentence = "==> Le champignon auquel vous pensez est ";
    
    bool chapeau, foret, anneau_lamelle;
    cout << q_chapeau << endl;
    cin >> chapeau;
    cout << q_foret << endl;
    cin >> foret;
    cout << ((chapeau and foret) ? q_anneau :
            (not(chapeau) and foret) ? q_lamelles :
            (chapeau and not(foret)) ? (endsentence + agaric) :
             (not(chapeau) and not(foret)) ? (endsentence + coprin) : "smth failed boi" ) << endl;
    cin >> anneau_lamelle;
    
    cout << ((chapeau and foret and anneau_lamelle) ? (endsentence + mouches) :
             (chapeau and foret and not(anneau_lamelle)) ? (endsentence + pied_bleu) :
             (not(chapeau) and foret and anneau_lamelle) ? (endsentence + girolle) :
             (not(chapeau) and foret and not(anneau_lamelle)) ? (endsentence + bordeaux) :
             "u got lost somwer, bro" );
    
    return 0;
}

