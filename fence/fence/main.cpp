#include <iostream>
#include <vector>
using namespace std;

/*******************************************
 * Complétez le programme à partir d'ici.
 *******************************************/
typedef vector<vector<int>> Carte;

struct Position {
    int i;
    int j;
    int start = 0;
    int end = 0;
    int counter = 0;
    string row_as_string = "";
};

bool contains(vector<int> vec, int num);

void marque_composantes(Carte& carte);
void check_border_row(Carte& carte);
void check_border_col(Carte& carte);
bool neighboor_is_zero(Carte& carte, Position p, int up, int down);
void ajoute_unique(vector<int>& ensemble, int valeur);
bool convexite_lignes(Carte& carte);
bool convexite_lignes(Carte& carte, vector<int> const& labels_bords);
bool binaire(Carte const& carte);
bool verifie_et_modifie(Carte& carte);
double longueur_cloture(Carte const& carte, double echelle);
Position amount_of_ones(vector<int> row, int num);


bool contains(vector<int> vec, int num) {
    for (auto n : vec) {
        if (n == (num-48)) {
            return true;
        }
    }
    return false;
}


void affiche(Carte const& carte) {
//    if (binaire(carte)) {
        
        for (auto row : carte) {
            for (auto field : row) {
                cout << field;
            }
            cout << endl;
        }
        cout << endl;
        cout << "----" << endl;
        cout << endl;
//    }
}


void marque_composantes(Carte& carte) {

    // Store all the positions under current consideration
    vector<Position> matrix;


    // This variable is a counter that will be incremented each time we discorver a new zone
    int composante = 1;

    for (int i = 0; i < carte.size(); i++) {
        for (int j = 0; j < carte[i].size(); j++) {

            // If we find a 0, increment counter and store its position
            if (carte[i][j] == 0) {
                // We found a new zone
                composante++;
                Position p;
                p.i = i;
                p.j = j;
                matrix.push_back(p);

                while (!matrix.empty()) {
                    // carte[p.i][p.j] = composante;
                    Position curr_pos;

                    curr_pos.i = matrix.back().i;
                    curr_pos.j = matrix.back().j;
                    matrix.pop_back();
                    if (carte[curr_pos.i][curr_pos.j] == 0) {
                        // Mark the zone with its number
                        carte[curr_pos.i][curr_pos.j] = composante;
                        // Check all directions for 0's and replace them with composante
                        // Check above
                        if ((curr_pos.i != 0) and neighboor_is_zero(carte, curr_pos, -1, 0) ) {
                            Position neighboor;
                            neighboor.i = curr_pos.i-1;
                            neighboor.j = curr_pos.j;
                            matrix.push_back(neighboor);
                        }

                        // Check east
                        if ((curr_pos.j != (carte[curr_pos.i].size()-1)) and neighboor_is_zero(carte, curr_pos, 0, +1)) {
                            Position neighboor;
                            neighboor.i = curr_pos.i;
                            neighboor.j = curr_pos.j+1;
                            matrix.push_back(neighboor);
//                            for (auto p : matrix) {
//                                cout << "Matrix element: " << p.i << " and " << p.j << endl;
//                            }
                        }

                        // Check south
                        if ((curr_pos.i != (carte.size()-1)) and neighboor_is_zero(carte, curr_pos, +1, 0)) {
                            Position neighboor;
                            neighboor.i = curr_pos.i+1;
                            neighboor.j = curr_pos.j;
                            matrix.push_back(neighboor);
                        }

                        // Check west
                        if ((curr_pos.j != 0) and neighboor_is_zero(carte, curr_pos, 0, -1)) {
                            Position neighboor;
                            neighboor.i = curr_pos.i;
                            neighboor.j = curr_pos.j-1;
                            matrix.push_back(neighboor);
                        }
                    }
                }
            }
        }
    }

//    cout << "Colored map is:" << endl;
//    affiche(carte);
}

//void check_border_row(Carte& carte) {
//
//}

// Chech for ways out of maze on the top and bottom rows
void check_border_row(Carte& carte, vector<int>& borders) {
    for (auto num : carte[0]) {
         if(num != 1) {
             ajoute_unique(borders, num);
         }
     }
     
     for (auto num : carte[carte.size()-1]) {
         if(num != 1) {
             ajoute_unique(borders, num);
         }
     }
}

// Chech for ways out of maze on the side columns
void check_border_col(Carte& carte, vector<int>& borders) {
    for (int i = 0; i < carte.size(); i++) {
         if(carte[i][0] != 1) {
             ajoute_unique(borders, carte[i][0]);
         }
     }
     
     for (int i = 0; i < carte.size(); i++) {
         if(carte[i][carte[i].size()-1] != 1) {
             ajoute_unique(borders, carte[i][carte[i].size()-1]);
         }
     }
}

bool neighboor_is_zero(Carte& carte, Position p, int up, int down) {
    return ((carte[p.i+up][p.j+down]) == 0);
}

void ajoute_unique(vector<int>& ensemble, int valeur) {
    bool is_in_set = false;
    for (auto num : ensemble) {
        if (num == valeur) {
            is_in_set = true;
        }
    }
    
    if (!is_in_set) {
        ensemble.push_back(valeur);
    }
}


bool convexite_lignes(Carte& carte) {
    vector<int> ways_out;
    marque_composantes(carte);
//    cout << "current map: " << endl;
//    affiche(carte);
    // Fill the vector with the zone numbers on the borders
    check_border_col(carte, ways_out);
    check_border_row(carte, ways_out);
    
//    for (auto num : ways_out) {
//        cout << "The numbers found on the borders are: " << num << endl;
//    }
//
    
//    cout << "Carte convexe" << endl;
    return convexite_lignes(carte, ways_out);
}

bool convexite_lignes(Carte& carte, vector<int> const& labels_bords) {
    
    for (int row = 0; row < carte.size();row++) {
        // Convert the row into a string
        Position pos;
        pos = amount_of_ones(carte[row], 1);
        
        
        // Look for 0's in the range and start the maze solving
        for (int iter = pos.start; iter < pos.end; iter++) {
            
            // If we find a number different than 1 between two 1's that was seen on the border
            // it means the map is not convex
//            cout << "Current number being evaluated " << pos.row_as_string[iter] << " at position: " << "[" << row << "][" << iter  << "]" << endl;
//
//            for (auto number : labels_bords) {
//                cout << "Ways out contains: " << number << " and currently looking at: " << pos.row_as_string[iter] << endl;
//            }
//            cout << endl;
//
            if ((pos.row_as_string[iter] != 1) and (contains(labels_bords, pos.row_as_string[iter]))) {
                cout << "Votre carte du terrain n'est pas convexe par lignes :" << endl;
                cout << "bord extérieur entrant trouvé en position [" << row << "][" << iter  << "]"<< endl;
                cout << endl;
                return false;
            }
        }
        
    }
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
        affiche(carte);
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
    
    // Sum differences of start and end positions of 1's
    // Call a function that computes the amount of 1's in a row
    Position current, previous = amount_of_ones(carte[0], 1), first = amount_of_ones(carte[0], 1), last = amount_of_ones(carte[carte.size()-1], 1);
    previous.counter = 0;
    int fence_length = 0;
    int row_count = 0;
    
    for (auto row : carte) {
        // Count amount of ones
        current = amount_of_ones(row, 1);
        row_count = 2 + abs(current.start - previous.start) + abs(current.end - previous.end);
        fence_length += row_count;
        //  cout << "current row is " << row_count << endl;
        previous = current;
        //        cout << "fence is currently at :" << fence_length << endl;
        
    }
    
    // We still have to add the last's row's 1's
    // and must not forget to account for the borders
    fence_length += first.counter + last.counter;
    // cout << "fence is:" << fence_length << endl;
    //cout << "FINAL RESULT:" << fence_length*echelle << endl;
    return fence_length*echelle;
}

Position amount_of_ones(vector<int> row, int num) {
    
    Position pos;
    for (int i = 0; i < row.size(); i++) {
        pos.counter += (row[i] == num) ? 1 : 0;
        pos.row_as_string += to_string(row[i]);
    }
    // pos.start_curr = pos.row_as_string.find("1");
    pos.start = static_cast<int>(pos.row_as_string.find("1"));
    pos.end = static_cast<int>(pos.row_as_string.rfind("1"));
    //    cout << endl;
    //    cout << "START IS: " << pos.start << endl;
    //    cout << endl;
    
    return pos;
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
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,0,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,0,0,1,1,0,0,0,0,1,1,1,1,1,1,1,0,0},
    {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,1,1,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,0,0,0,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,0,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
  };

    convexite_lignes(carte);
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
