#include <iostream>
using namespace std;

int separer_chiffre_gauche(int& nombre)
{
    int dix(1);
    int temp(nombre);
    while (temp >= 10) {
        dix  *= 10;
        temp /= 10;
    }
    nombre %= dix;
    return temp;
}

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/
void ajouter_chiffre_droit(int& nombre, int chiffre) {
    nombre *= 10;
    nombre += chiffre;
}

void dire_chiffre(int& nombre, int repetitions_chiffre, int chiffre) {
    ajouter_chiffre_droit(nombre, repetitions_chiffre);
    ajouter_chiffre_droit(nombre, chiffre);
}

int lire_et_dire(int nombre) {
    
    int useless_num = 1;
    dire_chiffre(useless_num, 3, 3);
    // cout  << "x is: " << useless_num << endl;
    
    std::string copy = std::to_string(nombre);
    int result = 0;
    
    int counter = 1;
    
    for (unsigned int i = 1; i < copy.length() + 1; i++) {
        unsigned int temp = 0;
        unsigned int digit = separer_chiffre_gauche(nombre);
        temp = copy[i] - 48;
        
        // cout << "current digit is: " << digit << endl;
        // cout << "next digit is: " << temp << endl;
        
        if (digit == temp) {
            counter++;
        } else {
            // cout << "NEXT DIGIT IS DIFFERENT" << endl;
            
            // Append the values to the result
            // if no zeroes
            if(digit != 0 and counter != 0) {
                dire_chiffre(result, counter, digit);
            }
            // cout << "Counter reset!" << endl;
            counter = 1;
            // cout  << result << endl;
            
        }
        
        // cout << "counter is at: " << counter << endl;
        // cout << endl;
    }
    
    std::string str = std::to_string(result);
    for (int i = 0; i < str.length(); i++) {
        char s = str.at(i);
        if(s == '0') {
            str.erase(i, 1);
        }
    }

//    cout << "final answer is: " << stoi(str) << endl;
    int answer = stoi(str);
    return answer;
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

void repeter_lire_et_dire(int& nombre, int fois)
{
  while (fois-- > 0) {
    nombre = lire_et_dire(nombre);
  }
}

int main()
{
  int nombre(1);
  int fois(1);
  cin >> nombre >> fois;
  repeter_lire_et_dire(nombre, fois);
  cout << nombre << endl;
  return 0;
}
