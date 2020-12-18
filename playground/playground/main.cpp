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

bool gagne(char c1, char c2, char c3, char c4)
{
    return ((c1 == c3) and (c2 == c4));
}

int main ()
{
    
    cout << ((gagne('a', 'b', 'a', 'b')) ? "YATAAA" : "mmhm") << endl;
    return 0;
    
}
