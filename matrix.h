#ifndef SPARSE_MATRIX_MATRIX_H
#define SPARSE_MATRIX_MATRIX_H

#include <stdexcept>
#include "node.h"
using namespace std;

template <typename T>
class Matrix {
    //Matrix(const Matrix<T>& other){    other}
public:
    unsigned rows, columns;
    vector<Node<T>*>* row;
    vector<Node<T>*>* column;

    void addNode(unsigned x, unsigned y, Node<T>* inserted){
        //Column{}
            Node<T>* temp=(*row)[x];
            for(int i=0;i<y;i++){
                if(temp->down){
                    if(temp->down->posy<y)
                        temp=temp->down;
                    else
                        break;
                }
                else
                    break;
            }
            if(temp->down){
                if((temp->down->posy)==y){
                    temp->down->value=inserted->value;
                    return;
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
            Node<T>* temp2=(*column)[y];
            for(int i=0;i<x;i++){
                if(temp2->next){
                    if(temp2->next->posx<x)
                        temp2=temp2->next;
                    else
                        break;
                    
                }
                else{
                    break;
                }
            }
            if(temp2->next){
                inserted->next=temp2->next;
                temp2->next=inserted;
            }
            else{
                temp2->next=inserted;
            }
    }
    void delNode(unsigned x,unsigned y){        
        Node<T>* temp=(*row)[x];
        if(temp->down){
            if(temp->posy!=y){
                while(temp){
                    if(temp->down){
                        if(temp->down->posy==y && temp->down->posx==x)
                            break;
                        else{
                            if(temp->down->posy<y)
                                temp=temp->down;
                            else
                                return;
                        }
                    }
                    else
                        return;
                }
                if(temp->down->posy==y){
                    Node<T>* todelete=temp->down;
                    Node<T>* newdown=temp->down->down;
                    Node<T>* temp2=(*column)[y];
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
        row=new vector<Node<T>*>;
        column=new vector<Node<T>*>;
        for(int i=0;i<rows;i++){
            column->push_back(new Node<T>());
        }
        for(int i=0;i<columns;i++){
            row->push_back(new Node<T>());
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
            delNode(x,y);
        }
    
    };
    T operator()(unsigned column, unsigned row) const{
        if(row<rows && column < columns){
            Node<T>* temp = (*(this->row))[column];           
            while (temp != nullptr){
                if(temp->posy == row){
                    return temp->value;
                }
                temp=temp->down;
            }
            return 0;
        }else
            throw out_of_range("Out of range");
    };
    Matrix<T>& operator=(Matrix<T> other){
        for(int i = 0; i < other.columns; i++ ){
            for(int j = 0; j < other.rows ; j++){
                this->set(i,j,other(i,j));
            }
        }
        return *this;
    };
    Matrix<T> operator*(T scalar) const{
        Matrix<T> answer(columns,rows);
        for(auto it:(*column)){
            auto it2=it->next;
            while (it2){
                answer.set(it2->posx,it2->posy,(it2->value)*scalar);
                it2=it2->next;
            }
        }
        return answer;
    };
    Matrix<T> operator*(Matrix<T>& other) const{
        if(this->rows!=other.columns)
            throw invalid_argument("Invalid sizes");
        Matrix<T> answer(rows,rows);
        for(int i=0;i<rows;i++){
            auto temp1=(*(this->column))[i];
            for(int j=0;j<rows;j++){
                auto temp2=(*(other.row))[j];
                auto temp3=temp1->next;
                auto temp4=temp2->down;
                T temp=0;
                while(temp3 && temp4){
                    if(temp3->posx>temp4->posy){
                        temp4=temp4->down;
                    }
                    else{
                        if(temp3->posx<temp4->posy){
                            temp3=temp3->next;
                        }
                        else{
                            temp+=temp3->value*temp4->value;
                            temp4=temp4->down;
                            temp3=temp3->next;
                        }
                        
                    }
                }
                answer.set(j,i,temp);
            }
        }
        return answer;
    };
    Matrix<T> operator+(Matrix<T>& other) const{
        if(this->columns!=other.columns || this->rows!=other.rows)
            throw invalid_argument("Different sizes");
        Matrix<T> answer(columns,rows);
        for(int i=0;i<columns;i++){
            auto temp1=(*(this->row))[i];
            auto temp2=(*(other.row))[i];
            auto temp3=temp1->down;
            auto temp4=temp2->down;
            while(temp3 || temp4){
                if(temp3 && temp4){
                    if(temp3->posy < temp4->posy){
                        answer.set(temp3->posx,temp3->posy,temp3->value);
                        temp3=temp3->down;
                    }
                    else{
                        if(temp3->posy > temp4->posy){
                            answer.set(temp4->posx,temp4->posy,temp4->value);
                            temp4=temp4->down;
                        }
                        else{
                            answer.set(temp4->posx,temp4->posy,(temp4->value)+(temp3->value));
                            temp3=temp3->down;
                            temp4=temp4->down;
                        }
                    }
                }
                else{
                    while(temp3){
                        answer.set(temp3->posx,temp3->posy,temp3->value);
                        temp3=temp3->down;
                    }
                    while(temp4){
                        answer.set(temp4->posx,temp4->posy,temp4->value);
                        temp4=temp4->down;
                    }
                }
            }
        }
        return answer;
    };
    Matrix<T> operator-(Matrix<T>& other) const{
        if(this->columns!=other.columns || this->rows!=other.rows)
            throw invalid_argument("Different sizes");
        Matrix<T> answer(columns,rows);
        for(int i=0;i<columns;i++){
            auto temp1=(*(this->row))[i];
            auto temp2=(*(other.row))[i];
            auto temp3=temp1->down;
            auto temp4=temp2->down;
            while(temp3 || temp4){
                if(temp3 && temp4){
                    if(temp3->posy < temp4->posy){
                        answer.set(temp3->posx,temp3->posy,temp3->value);
                        temp3=temp3->down;
                    }
                    else{
                        if(temp3->posy > temp4->posy){
                            answer.set(temp4->posx,temp4->posy,temp4->value);
                            temp4=temp4->down;
                        }
                        else{
                            answer.set(temp4->posx,temp4->posy,(temp4->value)-(temp3->value));
                            temp3=temp3->down;
                            temp4=temp4->down;
                        }
                    }
                }
                else{
                    while(temp3){
                        answer.set(temp3->posx,temp3->posy,temp3->value);
                        temp3=temp3->down;
                    }
                    while(temp4){
                        answer.set(temp4->posx,temp4->posy,temp4->value);
                        temp4=temp4->down;
                    }
                }
            }
        }



        return answer;
    };
    Matrix<T> transpose() const{
        Matrix<T> answer(columns,rows);
        for(auto it:(*column)){
            auto it2=it->next;
            while (it2){
                answer.set(it2->posy,it2->posx,it2->value);
                it2=it2->next;
            }
        }
        return answer;
    };
    void print() const{
        for (auto it:(*column)){
            int contador=0;
            auto it2=it->next;
            while (it2){
                for (int i=contador;i<it2->posx;i++)
                    cout<<0<<" ";
                cout<<(it2->value)<<" ";
                contador=it2->posx+1;
                it2=it2->next;
            }
            for (int i=contador;i<columns;i++){
                cout<<0<<" ";
            }
            cout<<endl;
        }
    };

    ~Matrix(){
        for(int i = 0 ; i < columns ; i++){
            Node<T>* temp=(*row)[i];
            temp->destroySelf();
        }
        delete row;
        delete column;
    };
};

#endif //SPARSE_MATRIX_MATRIX_H