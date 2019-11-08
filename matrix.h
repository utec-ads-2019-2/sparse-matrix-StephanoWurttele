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
        cout<<inserted<<endl;
        //Column{}
            Node<T>* temp=row[x];
            if(!temp){
                row[x]=inserted;
            }
            else{
                for(int i=0;i<x-1;x++){
                    if(temp->down){
                        if(temp->down->posy<y)
                            temp=temp->down;
                        else{
                            break;
                        }
                    }
                    else{
                        break;
                    }
                }
                if(temp->down){
                    if((temp->down->posy)==y){
                        temp->down->value=inserted->value;
                    }
                    else{
                        Node<T>* prevtemp=temp->down;
                        temp->down=inserted;
                        temp->down->down=prevtemp;
                    }
                }
                else{
                    temp->down=inserted;
                }
            }

        //Row{}
            Node<T>* temp2=column[y];
            if(!temp2){
                column[y]=inserted;
                return;
            }
            else{
                for(int i=0;i<y-1;y++){
                    if(temp2->next){
                        if(temp2->next->posx<=x)
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
                        temp2->down->next=prevtemp;
                    }
                }
                else{
                    temp2->next=inserted;
                }
            }
    }
    void delNode(unsigned x,unsigned y){
        Node<T>* temp=row[x];
        if(temp){
            if(temp->posy!=y){
                while(temp){
                    cout<<"Temp is now "<<temp<<endl;
                    if(temp->down){
                        cout<<"There is down"<<endl;
                        if(temp->down->posy==y && temp->down->posx==x){
                            cout<<"temp is equal to "<<y<<endl;
                            break;
                        }
                        else{
                            if(temp->down->posy<y){
                                cout<<"Down is smaller than current";
                                temp=temp->down;
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
                cout<<"Temp after while is "<<temp<<endl;
                if(temp->posy==y){
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
            else{
                cout<<"forcecode"<<endl;
                Node<T>* newroot=temp->down;
                Node<T>* temp2=column[y];
                while(temp2->posx!=x){
                    temp2=temp2->next;
                }
                Node<T>* newnext=temp2->next;
                delete temp;
                row[x]=newroot;
                column[y]=newnext;
            }
            return;
        }
        cout<<"lmao"<<endl;
    }
public:
    Matrix(unsigned rows, unsigned columns):rows(rows),columns(columns){
        row.resize(rows);
        column.resize(columns);
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
            while (it){
                for (int i=contador;i<it->posx;i++){
                    cout<<0<<" ";
                }
                cout<<it->value<<" ";
                contador=it->posx+1;
                it=it->next;
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