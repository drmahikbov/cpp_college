//
//  main.cpp
//  age
//
//  Created by Dr Mahike on 22.09.20.
//  Copyright © 2020 Dr Mahike. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int age;
    cout << "How old are you?" << endl;
    cin  >> age;
    std::cout << "Hello, World!\n";
   
      time_t t = time(NULL);
      tm* timePtr = localtime(&t);

    cout << "You were born in " << timePtr->tm_year + 1900 - age << " !" << endl;
  
    return 0;
}
