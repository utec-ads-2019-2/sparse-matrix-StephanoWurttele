#ifndef SPARSE_MATRIX_MATRIX_H
#define SPARSE_MATRIX_MATRIX_H

#include <stdexcept>
#include "node.h"
using namespace std;

template <typename T>
class Matrix {
public:
    unsigned rows, columns;
    vector<Node<T>*> row;
    vector<Node<T>*> column;

    void addNode(unsigned x, unsigned y, Node<T>* inserted){
        cout<<"In add Node"<<endl;
        //Column{}
            Node<T>* temp=row[x];
            cout<<"Temp is ";
            cout<<temp<<endl;
            for(int i=0;i<x-1;x++){
                if(temp->down){
                    cout<<"Temp down found"<<endl;
                    if(temp->down->posy<y){
                        cout<<"Advancing"<<endl;
                        temp=temp->down;
                    }
                    else{
                        cout<<"Broke!"<<endl;
                        break;
                    }
                }
                else{
                    cout<<"No temp down!"<<endl;
                    break;
                }
            }
            if(temp->down){
                if((temp->down->posy)==y){
                    temp->down->nvalue=inserted->nvalue;
                }
                else{
                    Node<T>* prevtemp=temp->down;
                    inserted->down=prevtemp;
                    temp->down=inserted;
                }
            }
            else{
                temp->down=inserted;
            }
        //Row{}
            Node<T>* temp2=column[y];
            for(int i=0;i<y-1;y++){
                if(temp2->next){
                    if(temp2->next->posx<x)
                        temp2=temp2->next;
                    else{
                        break;
                    }
                }
                else{
                    break;
                }
            }
            if(temp2->next){
                if((temp2->next->posx)!=x){
                    Node<T>* prevtemp=temp->next;
                    temp2->next=inserted;
                    temp2->next->next=prevtemp;
                }
            }
            else{
                temp2->next=inserted;
            }
    }
    void delNode(unsigned x,unsigned y){
        Node<T>* temp=row[x];
        if(temp->down){
            if(temp->posy!=y){
                while(temp){
                    if(temp->down){
                        cout<<"There is down"<<endl;
                        if(temp->down->posy==y && temp->down->posx==x){
                            cout<<"temp is equal to "<<y<<endl;
                            break;
                        }
                        else{
                            if(temp->down->posy<y){
                                cout<<"Down with "<<temp->down<<" is smaller than current"<<endl;
                                temp=temp->down;
                                cout<<"Replaced temp with "<<temp;
                            }
                            else{
                                return;
                            }
                        }
                    }
                    else{
                        return;
                    }
                }
                if(temp->down->posy==y){
                    Node<T>* todelete=temp->down;
                    Node<T>* newdown=temp->down->down;
                    Node<T>* temp2=column[y];
                    while(temp2->next->posx!=x){
                        temp2=temp2->next;
                    }
                    Node<T>* newnext=temp2->next->next;
                    temp2->next=newnext;
                    temp->down=newdown;
                    delete todelete;
                }
            }
        }
    }
public:
    Matrix(unsigned rows, unsigned columns):rows(rows),columns(columns){
        for(int i=0;i<rows;i++){
            column.push_back(new Node<T>());
        }
        for(int i=0;i<columns;i++){
            row.push_back(new Node<T>());
        }
    };

    void set(unsigned x, unsigned y, T data){
        if(x>=columns || y>=rows)
            throw out_of_range("Out of range");
        if(data!=0){
            Node<T>* inserted=new Node<T>(x,y,data);
            addNode(x,y,inserted);
        }
        else{
            cout<<"remove!"<<endl;
            delNode(x,y);
        }
    
    };

void print(){
        //for (auto it=column.begin();it!=column.end();it++){
        for (auto it:column){
            int contador=0;
            auto it2=it->next;
            while (it2){
                for (int i=contador;i<it2->posx;i++){
                    cout<<0<<" ";
                }
                cout<<*(it2->value)<<" ";
                contador=it2->posx+1;
                it2=it2->next;
            }
            for (int i=contador;i<columns;i++){
                cout<<0<<" ";
            }
            cout<<endl;
        }
    }



    T operator()(unsigned, unsigned) const;
    Matrix<T> operator*(T scalar) const;
    Matrix<T> operator*(Matrix<T> other) const;
    Matrix<T> operator+(Matrix<T> other) const;
    Matrix<T> operator-(Matrix<T> other) const;
    Matrix<T> transpose() const;
    //void print() const{    };

    //~Matrix();
};

#endif //SPARSE_MATRIX_MATRIX_H