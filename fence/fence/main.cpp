#include <iostream>
#include <vector>
using namespace std;

/*******************************************
 * Complétez le programme à partir d'ici.
 *******************************************/
typedef vector<vector<int>> Carte;

bool verifie_et_modifie(Carte& carte);

double longueur_cloture(Carte const& carte, double echelle);

int amount_of_ones(vector<int> row, int num);

void ajoute_unique(vector<int>& ensemble, int valeur);

bool convexite_lignes(Carte& carte);

struct Position {
    int i;
    int j;
    size_t left;
    size_t right;
};

void ajoute_unique(vector<int>& ensemble, int valeur) {
    
}

bool convexite_lignes(Carte& carte, vector<int> const& labels_bords) {
return true;
}

bool convexite_lignes(Carte& carte) {
return true;
}



bool binaire(Carte const& carte) {
    for (auto row : carte) {
        for (auto field : row) {
            if (field < 0 or field > 1) {
                return false;
            };
        }
    }
    return true;
}

void affiche(Carte const& carte) {
    if (binaire(carte)) {
        
        for (auto row : carte) {
            for (auto field : row) {
                cout << field;
            }
          cout << endl;
        }
          cout << endl;
          cout << "----" << endl;
          cout << endl;
    }
}

bool verifie_et_modifie(Carte& carte) {
    if (binaire(carte)) {
        string str = "";
        for (int j = 0; j < carte.size();j++) {
            // Convert the row into a string
            for (int i = 0; i < carte[j].size(); i++) {
                str += to_string(carte[j][i]);
            }
            // Display the row
            // cout << "Old row is: " + str << endl;
            
            // Once we've got the row as a string
            // We need to get rid of the "ponds", i.e.: the 0's in the middle
            
            // The idea is to find and rfind starting and trailing 1's
            // Then, look for 0's between the range recently found and smash'em
            string one = "1";
            size_t left = str.find(one);
            size_t right = str.rfind(one);
            
            // Look for 0's in the range and turn them into 1's
            for (size_t i = left + 1; i < right; i++) {
                if (str[i] == '0') {
                    str[i] = '1';
                }
            }
            // Display row again and reset it
            //cout << "New row is: " + str << endl;
            
            // Now, update real map
            for (int i = 0; i < carte[j].size(); i++) {
                carte[j][i] = (str[i]-48);
                // cout  << carte[j][i] << " ";
            }
            str = "";
//            cout << endl;
        }
        return true;
    } else {
        cout << "Votre carte du terrain ne contient pas que des 0 et des 1." << endl;
        return false;
    }
}

//          cout << "Votre carte du terrain n'est pas convexe par lignes :" << endl;
//          cout << "bord extérieur entrant trouvé en position [";
//          cout << "][";
//          cout << "]" << endl;


double longueur_cloture(Carte const& carte, double echelle = 2.5) {
    
    // In order to calculate total fence amount
    // We must proceed row per row
    
    // First, count all the 1's per row
    // Then take the absolute value of the difference between last and current row
    // Sum up all the differences and add 2 per row
    // Multiply by scale and output result
    // PS: First and after-last's row's differences will amount to their amount of 1's since they are the borders
    
    // Call a function that computes the amount of 1's in a row
    int current = 0, previous = 0, last = amount_of_ones(carte[carte.size()-1], 1);
    double fence_length = 0;
    for (auto row : carte) {
        current = amount_of_ones(row, 1);
        fence_length += abs(current - previous);
        previous = current;
//        cout << "fence is currently at :" << fence_length << endl;

    }
    
//    cout << "fence is:" << fence_length << endl;

    // We still have to add the last's row's 1's
    // and must not forget to account for the borders
    fence_length += last + 2*carte.size();
//    cout << "fence is finally:" << fence_length << endl;

    return fence_length*echelle;
}

int amount_of_ones(vector<int> row, int num) {
    int counter = 0;
    for (auto n : row) {
        counter += (n == num) ? num : 0;
    }
    
    return counter;
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  Carte carte = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,0,0},
    {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
  };

  cout << "Carte au départ :" << endl;
  affiche(carte);
  if (verifie_et_modifie(carte)) {
    cout << "Carte après modification :" << endl;
    affiche(carte);
    cout << "Il vous faut " << longueur_cloture(carte)
         << " mètres de clôture pour votre terrain."
         << endl;
  }

  return 0;
}
