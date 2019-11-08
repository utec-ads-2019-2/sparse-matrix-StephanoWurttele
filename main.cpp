#include <iostream>

#include "tester/tester.h"

int main() {
    //Tester::execute();
    Matrix<int> SparseMatrix(4,4);
    SparseMatrix.set(0,2,2);
    SparseMatrix.set(0,0,1);
    SparseMatrix.set(2,0,4);
    SparseMatrix.set(1,2,3);
    SparseMatrix.set(2,1,5);
    SparseMatrix.set(2,2,6);
    SparseMatrix.set(1,1,7);

    /*SparseMatrix.set(0,1,9);
    SparseMatrix.set(1,1,5);
    SparseMatrix.set(2,2,6);
    SparseMatrix.set(3,3,7);
    SparseMatrix.set(1,3,8);*/
    SparseMatrix.print();
    SparseMatrix.set(0,2,0);
    SparseMatrix.print();
    SparseMatrix.set(0,0,0);
    SparseMatrix.set(2,0,0);
    SparseMatrix.set(2,0,0);
    SparseMatrix.print();
    cout<<SparseMatrix.row[0]<<endl;
    cout<<SparseMatrix.column[0]<<endl;
    return EXIT_SUCCESS;
}

