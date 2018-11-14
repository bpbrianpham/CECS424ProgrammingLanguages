#include <iostream>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

int main(){
    int fp_count = 0, int_count = 0;
    for (float i = 0; i < 1; i += 0.01)
        fp_count++;

    for (int i = 0; i < 100; i += 1)
        int_count++;

    cout << fp_count << endl;
    cout << int_count << endl;

}