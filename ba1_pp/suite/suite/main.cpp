#include <iostream>
using namespace std;

int main()
{
    int debut(0);
    do {
        cout << "de (>= 1) ? ";
        cin >> debut;
    } while (debut < 1);
    
    int fin(0);
    do {
        cout << "a (>= " << debut << ") ? ";
        cin >> fin;
    } while (fin < debut);
    
    /*******************************************
     * Completez le programme a partir d'ici.
     *******************************************/
    for (int i = debut, k, temp; i <= fin; i++) {
        k = 0;
        temp = i;
        while (i > 0) {
            i = ( i % 3 == 0) ?  i + 4 :
                (( i % 3 != 0) and ( i % 4 == 0)) ?  i/2 :
                i - 1;
            k++;
            //            cout << " i is at: " << i << endl;
        }
        i = temp;
        cout << i << " -> " << k << endl;
    }
    
    /*******************************************
     * Ne rien modifier apres cette ligne.
     *******************************************/
    
    return 0;
}
