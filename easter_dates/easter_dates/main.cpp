//
//  main.cpp
//  easter_dates
//
//  Created by Dr Mahike on 17.12.20.
//  Copyright © 2020 Dr Mahike. All rights reserved.
//

#include <iostream>
using namespace std;

int demander_annee() {
    int year = 0;
    do {
        
        cout << "Entrez une annee (1583-4000) : ";
        cin >> year;
    } while (year > 4000 or year < 1583);
    
    return year;
}

string affiche_date(int year, int day) {
    return ("Date de Paques en " + to_string(year) + ": " + ((day <= 31) ? (to_string(day) + " mars ") : (to_string(day-31) + " avril ")));
}

int date_Paques(int year) {
    int century = year/100;
    int p = (13 + 8*century)/25;
    int q = century/4;
    int M = (15 - p + century - q)%30;
    int N =  (4 + century - q)%7;
    int d = (M + 19*(year%19))%30;
    int e = (2 * (year % 4) + 4 * (year % 7) + 6 * d + N) % 7;
    int day = ((e == 6) and ((d == 29) or ((d == 28) and (11*(M+1) % 30 < 19)))) ? e + d + 15 : e + d + 22;
    
    return day;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int y = demander_annee();
    cout << affiche_date(y, date_Paques(y)) << endl;
    
    return 0;
}
