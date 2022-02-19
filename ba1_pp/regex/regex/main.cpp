//
//  main.cpp
//  regex
//
//  Created by Dr Mahike on 01.10.20.
//  Copyright © 2020 Dr Mahike. All rights reserved.
//

#include <iostream>
#include <regex>
#include <string>
using namespace std;


int main()
{
    //string to be searched
    string mystr = "6";
   
    // regex expression for pattern to be searched
    regex regexp("[[:digit:]]");
   
    
    if(regex_match(mystr, regexp)) {
        cout << "yolo" << endl;
    }

    return 0;
}
