//
//  main.cpp
//  julius_caesar
//
//  Created by Dr Mahike on 18.12.20.
//  Copyright © 2020 Dr Mahike. All rights reserved.
//

#include <iostream>
using namespace std;

char decale(char c, char debut, int decalage);

char code(char c, int d);

string code(string c, int shift);

string decode(string cypher, int shift);

string decode(string cypher, int shift) {
    return code(cypher, -shift);
}

string code(string str, int shift) {
    
    string new_string = "";
    
    for (int i = 0; i < str.size(); i++) {
        new_string += code(str[i], shift);
    }
    
    return new_string;
}

char code(char c, int d) {
    return (((c >= 'a') and (c <= 'z')) ? decale(c, 'a', d)
            : ((c >= 'A') and (c <= 'Z')) ? decale(c, 'A', d)
            : c );
}

char decale(char c, char debut, int decalage) {
    while (decalage < 0) {
        decalage += (decalage < 0) ? 26: 0;
    }
    
    return (debut + (((c - debut) + decalage) % 26));
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    //    cout << code("Avez-vous vu mes 3 chats et mes 2 chiens ?", 4)<< endl;
    //    cout << decode(code("Avez-vous vu mes 3 chats et mes 2 chiens ?", 4), 4)<< endl;
    cout << code('g', -133) << endl;
    cout << code("g", -133) << endl;
    
}
