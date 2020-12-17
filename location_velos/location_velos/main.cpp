#include <iostream>
using namespace std;

int main()
{
    cout << "Donnez l'heure de début de la location (un entier) : ";
    int debut;
    cin >> debut;
    
    cout << "Donnez l'heure de fin de la location (un entier) : ";
    int fin;
    cin >> fin;
    
    /*****************************************************
     * Compléter le code à partir d'ici
     *****************************************************/
    
    // Empty string
    string blank;
    int price = ( debut < 7 && fin < 7 ? fin - debut
                 : debut < 7 && fin < 17 ? fin - debut + fin - 7
                 : debut < 7 && fin <= 24 ? fin - debut + 10
                 : debut < 17 && fin < 17 ? 2*(fin - debut)
                 : debut < 17 && fin <= 24 ? fin - debut + 17 - debut
                 : debut <= 24 && fin <= 24 ? fin - debut : 0);
    
    // The value corresponds to the hourly wage, with wages 1 and 3 identical
    int onedollarrenting = ( debut < 7 && fin < 7 ? fin - debut
                            : debut < 7 && fin >= 7 && fin < 17 ? 7 - debut
                            : debut < 7 && fin >= 17 ? fin - debut - 10
                            : debut < 17 && fin < 17 ? 0
                            : debut < 17 && fin >= 17 ? fin - 17
                            : debut <= 24 && fin >= 17 ? fin - debut : 0 );
    
    int twodollarrenting = ( debut < 7 && fin < 7 ? 0
                            : debut < 7 && fin >= 7 && fin < 17 ? fin - 7
                            : debut < 7 && fin >= 17 ? 10
                            : debut <= 17 && fin <= 17 ? fin - debut
                            : debut <= 17 && fin > 17 ? 17 - debut
                            : debut > 17 && fin > 17 ? 0 : 0 );
    
    string result1;
    string result2;
    
    if ( debut > 24 || fin > 24 || debut < 0 || fin < 0) {
        cout << "Les heures doivent être comprises entre 0 et 24 !" << endl;
    } else if (abs(fin - debut) == 0) {
        cout << "Bizarre, vous n'avez pas loué votre vélo bien longtemps !" << endl;
    } else if (debut > fin) {
        cout << "Bizarre, le début de la location est après la fin ..." << endl;
    } else {
        // There's no problem
        // Proceed with output
        cout << "Vous avez loué votre vélo pendant " << endl;
        cout << (onedollarrenting != 0 ? result1+=to_string(onedollarrenting) + " heure(s) au tarif horaire de 1 franc(s)": blank) << endl;
        cout << (twodollarrenting != 0 ? result2+=to_string(twodollarrenting) + " heure(s) au tarif horaire de 2 franc(s)" : blank) << endl;
        
        cout << "Le montant total à payer est de " << price << " franc(s)." << endl;
    }
    
    
    
    /*******************************************
     * Ne rien modifier après cette ligne.
     *******************************************/
    
    return 0;
}
