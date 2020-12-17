//
//  main.cpp
//  playground
//
//  Created by Dr Mahike on 17.12.20.
//  Copyright © 2020 Dr Mahike. All rights reserved.
//


#include <iostream>
#include <string>
using namespace std;

void affichage(int n, bool b)
{
  bool bb(b);

  for (int i(0); i < (n-2); ++i) {
    int j(0);
    if (!bb) {
      do {
        if (i > j) {
          cout << j << " ";
          ++j;
        } else {
          bb = not bb;
          ++j;
        }
      } while (j < n);

    } else {
      if (i > 0) {
        cout << i << " ";
      } else {
        cout << b << " ";
      }
    }
  }
}

int main ()
{
  int const CINQ(5);
  bool const VRAI(true);
  cout.setf(ios::boolalpha); // pour afficher true/false
 
  affichage(CINQ, VRAI);

affichage (2*CINQ, not VRAI);  return 0;
}
