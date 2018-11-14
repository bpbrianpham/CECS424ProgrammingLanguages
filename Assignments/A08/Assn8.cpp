/*
Brian Pham
CECS 424
*/
#include <iostream>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]){
    //setup
    int r1 = atoi(argv[1]);
    int c1 = atoi(argv[2]);
    int r2 = atoi(argv[3]);
    int c2 = atoi(argv[4]);
    
    cout << "Number of rows in matrix 1:\t"     << r1 << endl;
    cout << "Number of columns in matrix 1:\t"  << c1 << endl;
    cout << "Number of rows in matrix 2:\t"     << r2 << endl;
    cout << "Number of columns in matrix 2:\t"  << c2 << endl;
    
    int element1 = r1 * c1;
    int element2 = r2 * c2;

    cout << "\nNumber of elements in matrix 1:\t"   << element1 << endl;
    cout << "Number of elements in matrix 2:\t"     << element2 << endl;
    
    
    cout << endl << "Matrix 1:\n";
    //making matrix 1
    int* matrix1 = (int *)malloc(r1 * c1 * sizeof(int));

    //create matrix 1
    int m1cnt = 1;
    for(int r = 0; r < r1; r++)
        for(int c = 0; c < c1; c++)
            *(matrix1 + r*c1 + c) = m1cnt++;

    //print matrix 1
    for(int r = 0; r < r1; r++){
        for(int c = 0; c < c1; c++)
            cout << *(matrix1 + r*c1 + c) << "\t";
        cout << endl << endl;
    }    

    cout << "\nMatrix 2:\n";
    //making matrix 2
    int* matrix2 = (int *)malloc(r2 * c2 * sizeof(int));

    //create matrix 2
    int m2cnt = element2;
    for(int r = 0; r < r2; r++)
        for(int c = 0; c < c2; c++)
            *(matrix2 + r*c2 + c) = m2cnt--;

    //print matrix 2
    for(int r = 0; r < r2; r++){
        for(int c = 0; c < c2; c++)
            cout << *(matrix2 + r*c2 + c) << "\t";
        cout << endl << endl;
    }

    //multiplying the two matrices
    cout << "\nMatrix 1 X Matrix 2:\n";
    if(r1 != c2){
        cout << "Mismatch Matrices: Cannot multiply.";
    }
    else{
        int r3 = r1;
        int c3 = c2;
        int* matrix3 = (int *)malloc(r3 * c3 * sizeof(int));

        //initialize all product matrix to 0
        for(int r = 0; r < r3; r++)
            for(int c = 0; c < c3; c++)
                *(matrix3 + r*c3 + c) = 0;

        //calculate for product matrix
        for(int r = 0; r < r1; r++)
            for(int c = 0; c < c2; c++)
                for(int cc = 0; cc < c1; cc++)
                    *(matrix3 + r*c3 + c) += (*(matrix1 + r*c1 + cc)) * (*(matrix2 + cc*c2 + c));
        
        //print product matrix
        for(int r = 0; r < r3; r++){
            for(int c = 0; c < c3; c++)
                cout << *(matrix3 + r*c3 + c) << "\t";
            cout << endl << endl;
        }
    }
}