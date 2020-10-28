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
    
    cout << "Pensez Ã  un champignon : amanite tue-mouches, pied bleu, girolle," << endl
    << "cÃ¨pe de Bordeaux, coprin chevelu ou agaric jaunissant." << endl << endl;
    
    string q1 = "Est-ce que votre champignon a des lamelles (1 : oui, 0 : non) ? ";
    string q2 =  "Est-ce que votre champignon vit en forÃªt (1 : oui, 0 : non) ? ";
    string q3 =  "Est-ce que votre champignon a un chapeau convexe (1 : oui, 0 : non) ? ";
    string q4 =  "Est-ce que votre champignon a un anneau (1 : oui, 0 : non) ? ";
    
    string champi1 = "l'agaric jaunissant";
    string champi2 = "l'amanite tue-mouches";
    string champi3 = "le cÃ¨pe de Bordeaux";
    string champi4 = "le coprin chevelu";
    string champi5 = "la girolle";
    string champi6 = "le pied bleu";
    
    string endsentence = "==> Le champignon auquel vous pensez est ";
    
    bool answerone, answertwo, answerthree;
    cout << q3 << endl;
    cin >> answerone;
    cout << q2 << endl;
    cin >> answertwo;
    cout << q4 << endl;
    cin >> answerthree;
    
    cout << ((answerone and not(answertwo)) ? (endsentence + champi1) :
             (answerone and answertwo and answerthree) ? (endsentence + champi2) :
             (answerone and answertwo and not(answerthree)) ? (endsentence + champi6) :
             (not(answerone) and not(answertwo)) ? "ur shroom aint comin from dis planet, dog" :
             (not(answerone) and answertwo and answerthree) ? (endsentence + champi5) :
             (not(answerone) and answertwo and not(answerthree)) ? (endsentence + champi3) :
             "u got lost somwer, bro" );
    
    return 0;
}
