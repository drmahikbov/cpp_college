//
//  main.cpp
//  encode_file
//
//  Created by Dr Mahike on 11.01.21.
//  Copyright © 2021 Dr Mahike. All rights reserved.
//


#include <iostream>
 #include <string>
 #include <vector>
 #include <array>
 #include <fstream>
 using namespace std;

typedef vector<string> Texte;

 // ======================================================================
 string encodage(Texte const& en_clair)
 {
 const array<string, 16> code({
 "01", "110", "101", "1111",
 "0100", "1010", "00101", "1110",
 "00", "0011", "11001", "111000",
 "0101", "11" , "01011", "101010"
 });

 string resultat;
 for (auto mot : en_clair) {
 for (auto c : mot) {
 while (c > 16) {
 resultat += code[c % 16];
 c -= 16;
 }
 resultat += code[c];
 }
 }
 return resultat;
 }

 // ======================================================================
 Texte lire_fichier(string const& nom)
 {
 Texte retour;
ifstream fichier(nom);
string mot = "hello";
size_t i(0);
 while (getline(fichier, mot)) {
retour[i] = mot;
 i += 1;
     cout << mot << '\n';
}
return retour;
}

// ======================================================================
string demander_nom_fichier()
{
string retour("test.txt");
cout << "Entrez un nom de fichier : ";
getline(cin, retour);
return retour;
 }
 // ======================================================================
 int main()
 {
 cout << encodage(lire_fichier(demander_nom_fichier()))
 << endl;
 return 0;
 }
