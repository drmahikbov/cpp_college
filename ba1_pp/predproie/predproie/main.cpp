#include <iostream>
#include <iomanip> // pour setprecision()
using namespace std;

int main()
{
    // Réduire le format d'affichage
    cout << setprecision(4);
    
    // Paramètres
    double taux_croissance_lapins(0.3);
    double taux_attaque(0.01);
    double taux_croissance_renards(0.008);
    double taux_mortalite(0.1);
    int duree(50);
    
    double renards_i(0.0);
    double lapins_i(0.0);
    
    /*****************************************************
     * Compléter le code à partir d'ici
     *****************************************************/
    
    // ===== PARTIE 1 =====
    // Saisie des populations initiales
    do {
        cout << "Combien de renards au départ (>= 2) ? ";
        cin >> renards_i;
    } while (renards_i < 2);
    
    do {
        cout << "Combien de lapins au départ  (>= 5) ? ";
        cin >> lapins_i;
    } while (lapins_i  < 5);
        
    cout <<  endl << "***** Le taux d'attaque vaut "<< taux_attaque * 100 << "%" <<  endl;

    // Temp variables
    double lapins_i_input = lapins_i;
    double renards_i_input = renards_i;
    
    // ===== PARTIE 2 =====
    // Première simulation
    
    double oldfox = renards_i;
    double oldrabbit = lapins_i;
    
    for (int i = 1; (i <= duree) && (renards_i != 0 || lapins_i != 0); i++) {
        // Set the equations for both populations growth
        oldfox = renards_i;
        oldrabbit = lapins_i;
        
        renards_i *=  (1.0 + (taux_attaque * oldrabbit  * taux_croissance_renards) - taux_mortalite);
        renards_i = (renards_i <= 0) ? 0 : renards_i;
        
        
        lapins_i  *= (1.0 + taux_croissance_lapins - taux_attaque * oldfox);
        lapins_i = (lapins_i <= 0) ? 0 : lapins_i;
        
        
        // Print demographics
        cout << "Après " << i << " mois, il y a " << lapins_i  << " lapins et " << renards_i << " renards" << endl;
    }
    
    // ===== PARTIE 3 =====
    // Ask for user defined attack rates
    double begin_rate = 0, end_rate = 0;
    do {
        cout << "taux d'attaque au départ en % (entre 0.5 et 6) ? ";
        cin >> begin_rate;
    } while ((begin_rate < 0.5) or (begin_rate > 6 ));
    
    do {
        cout  << "taux d'attaque à la fin  en % (entre " << begin_rate << " et 6) ? ";
        cin >> end_rate;
    } while ((end_rate < begin_rate) or (end_rate > 6 ));
     
    bool allIsFine = true;
    bool renards_exctincts, plusderenards, lapins_exctincts, plusdelapin, remontada_lapins, remontada_renards;
    int mois;
    for (double attaq_inc = 0; attaq_inc < (end_rate - begin_rate); attaq_inc++) {
        cout <<  endl << "***** Le taux d'attaque vaut "<< (attaq_inc + begin_rate) << "%" <<  endl;
        lapins_i  = lapins_i_input;
        renards_i = renards_i_input;
        renards_exctincts = false;
        plusderenards = false;
        lapins_exctincts = false;
        plusdelapin = false;
        remontada_renards = false;
        remontada_lapins = false;
        mois = 0;
        
        for (int i = 1; i <= duree && (renards_i != 0 || lapins_i != 0); i++) {
            
            // Set the stats anew for each iteration
            oldfox = renards_i;
            oldrabbit = lapins_i;
            
            taux_attaque = (attaq_inc + begin_rate)/100;
            // Set the equations for both populations growth
            lapins_i  *= (1.0 + taux_croissance_lapins - (taux_attaque * oldfox));
            lapins_i = (lapins_i <= 0) ? 0 : lapins_i;
            
            
            renards_i *= (1.0 + (taux_attaque * oldrabbit * taux_croissance_renards) - taux_mortalite);
            renards_i = (renards_i <= 0) ? 0 : renards_i;
            
            // Print demographics
            //cout << "Après " << i << " mois, il y a " << lapins_i  << " lapins et " << renards_i << " renards" << endl;
            
            // Check if a population was near extinction
            if (lapins_i  < 5) {
                lapins_exctincts = true;
                allIsFine = false;
            }
            if (lapins_i  < 2) {
                plusdelapin = true;
                remontada_lapins = false;
                lapins_i  = 0;
                mois = i;
            }
            
            if (renards_i < 5) {
                renards_exctincts = true;
                allIsFine = false;
            }
            if (renards_i < 2) {
                plusderenards = true;
                remontada_renards = false;
                renards_i = 0;
                mois = i;
            }
            
            // Check if a population resurfaced
            if (  ((lapins_i >  5) and (oldrabbit < 5))  ) {
                remontada_lapins = true;
                allIsFine = false;
            }
            
            // Check if a population resurfaced
            if (  ((renards_i >  5) and (oldfox < 5))  ) {
                remontada_renards = true;
                allIsFine = false;
            }
            
            
            
            
            // If both are dead, end the simulations
            if (renards_i < 2 && lapins_i < 2) {
                renards_i = 0;
                lapins_i = 0;
            }
            
            
        }
        
        // Output messages according to demographics
        cout << "Après " << ((mois != 0) ? mois : duree) <<  " mois, il y a " << lapins_i  << " lapins " << "et " << renards_i << " renards" << endl;
        if (allIsFine) cout << "Les lapins et les renards ont des populations stables. \n" << endl;
        
     
        
        if (renards_exctincts) cout << "Les renards ont été en voie d'extinction" << endl;
        if ( (plusderenards)   ) {
            cout << "et les renards ont disparu :-(" << endl;
            
        } else if  ( (remontada_renards)) {
            cout << "mais la population est remontée ! Ouf !" << endl;
        }
        
        
        if (lapins_exctincts) cout << "Les lapins ont été en voie d'extinction"  << endl;
             if ( (plusdelapin) ) {
                 cout << "et les lapins ont disparu :-(" << endl;
                 
             } else if  ((remontada_lapins)) {
                 cout << "mais la population est remontée ! Ouf !" << endl;
             }
        
        
    }
    
    // ===== PARTIE 3 =====
    // Variation du taux d'attaque
    
    
    /*******************************************
     * Ne rien modifier après cette ligne.
     *******************************************/
    
    return 0;
}
