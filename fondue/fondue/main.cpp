//
//  main.cpp
//  fondue
//
//  Created by Dr Mahike on 22.09.20.
//  Copyright © 2020 Dr Mahike. All rights reserved.
//

#include <iostream>
#include <map>
#include <iterator>

using namespace std;
const int numberOfIngredients = 6;


class Products {
    public:
        const double BASE = 4;
        double cheese = 800.0;
        double water = 2.0;
        double garlic = 2.0;
        double bread = 400;
        string pepper;
        double guests;
} ;




int main(int argc, const char * argv[]) {
    // insert code here...
   
    
    Products foo;
   
    cout << "How many people dine with us tonight?" << endl;
    cin >> foo.guests;
    
    
    map<double, string> ingredients;
    ingredients.insert(pair<double, string>(foo.BASE, ""), pair<double, string>(foo.cheese, " gr de Vacherin fribourgeois"));
    ingredients.insert(pair<double, string>(foo.water, " dl d'eau"), pair<double, string>(foo.garlic, " gousse(s) d'ail"));
    ingredients.insert(pair<double, string>(foo.bread, " gr de pain"), pair<double, string>(0, " du poivre à volonté"));
    map<double, string>::iterator itr;
    
    cout << "To prepare your recipe for " << foo.guests << " guests, you will need:" << endl;
    
    for (itr = ingredients.begin(); itr != ingredients.end(); ++itr) {
        cout << itr->first << ":" << itr->second << endl;
    }

    
    return 0;
}


