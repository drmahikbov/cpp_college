//
//  main.cpp
//  ensembles
//
//  Created by Dr Mahike on 01.10.20.
//  Copyright © 2020 Dr Mahike. All rights reserved.
//

#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Please enter a number: ";
    double x;
    cin >> x;
    
    double inf = -1;
    double sup = 1;

    cout << ( (x >= inf && x < sup && regex_match(to_string(x), regex("[[:digit:]]"))) ? "x appartient à I " : "x n'appartient pas à I" ) << endl;

    return 0;
}
