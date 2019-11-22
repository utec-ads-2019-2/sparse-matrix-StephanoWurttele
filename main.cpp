#include <iostream>

#include "tester/tester.h"
#include "mocker/mocker.h"
int main() {
    Tester::execute();
    /*Matrix<int> SparseMatrix(4,4);
    //adding nodes{}
        SparseMatrix.set(0,0,1);
        cout<<"Node 1 added"<<endl;
        SparseMatrix.set(0,1,2);
        cout<<"Node 2 added"<<endl;
        SparseMatrix.set(0,2,3);
        cout<<"Node 3 added"<<endl;
        SparseMatrix.set(0,3,4);
        cout<<"Node 4 added"<<endl;
        SparseMatrix.set(1,0,5);
        cout<<"Node 5 added"<<endl;
        SparseMatrix.set(3,3,6);
        cout<<"Node 6 added"<<endl;
        SparseMatrix.set(3,2,7);
        cout<<"Node 7 added"<<endl;
        SparseMatrix.set(3,1,8);
        cout<<"Node 8 added"<<endl;
        SparseMatrix.set(3,0,9);
        cout<<"Node 9 added"<<endl;
        SparseMatrix.set(2,3,10);
        cout<<"Node 10 added"<<endl;
        SparseMatrix.set(1,1,11);
        cout<<"Node 11 added"<<endl;
        SparseMatrix.set(2,1,12);
        cout<<"Node 12 added"<<endl;
        SparseMatrix.set(1,2,13);
        cout<<"Node 13 added"<<endl;
        SparseMatrix.set(1,3,14);
        cout<<"Node 14 added"<<endl;
        SparseMatrix.set(2,0,15);
        cout<<"Node 15 added"<<endl;
        SparseMatrix.set(2,2,16);
        cout<<"Node 16 added"<<endl;
    SparseMatrix.print();
    cout<<endl<<"ORIGINAL matrix"<<endl;
    //deleting nodes{}
        SparseMatrix.set(0,2,0);
        SparseMatrix.set(0,0,0);
        SparseMatrix.set(2,0,0);
    
    
    SparseMatrix.print();
    cout<<endl;
    //Operations{}
        cout<<"OPERATIONS:"<<endl;

        cout<<"Scalar product: "<<endl;
        auto newproduct=SparseMatrix*3;
        newproduct.print();
        cout<<endl;

        newproduct=SparseMatrix*1;
        newproduct.set(0,1,0);
        newproduct.set(0,3,0);
        cout<<"Addition:"<<endl;
        cout<<"Going to add"<<endl;
        SparseMatrix.print();
        cout<<"and"<<endl;
        newproduct.print();
        cout<<endl;
        auto newaddition=SparseMatrix+newproduct;
        newaddition.print();
        cout<<endl;


        cout<<"Real product"<<endl;
        Matrix<int> factor1(2,3);
        Matrix<int> factor2(3,2);
        factor1.set(0,0,1);
        factor1.set(0,1,4);
        factor1.set(1,0,2);
        factor1.set(1,1,0);
        factor1.set(2,0,-3);
        factor1.set(2,1,-2);
        factor1.print();
        cout<<"times"<<endl;
        factor2.set(0,0,3);
        factor2.set(0,1,2);
        factor2.set(0,2,-1);
        factor2.set(1,0,1);
        factor2.set(1,1,4);
        factor2.set(1,2,5);
        factor2.print();
        cout<<"equals"<<endl;
        auto product=factor1*factor2;
        product.print();
        newproduct.set(1,2,0);
        newproduct.set(3,1,0);
        auto product2=SparseMatrix*newproduct;
        product2.print();
        cout<<endl;
        cout<<endl<<endl;
        cout<<"() operator: "<<newproduct(1,0)<<endl;
        
        cout<<"Transpose:"<<endl;
        auto newsparse=SparseMatrix.transpose();
        newsparse.print();
        cout<<endl<<endl;*/
    
    return EXIT_SUCCESS;
}

