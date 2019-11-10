#ifndef SPARSE_MATRIX_NODE_H
#define SPARSE_MATRIX_NODE_H
#include <vector>
template <typename T>
class Matrix;

template <typename T>
class Node {
protected:
    Node<T> *next, *down;
    unsigned int posx=0,posy=0;
    T value;
    void build(unsigned int x, unsigned int y, T valor, Node<T>* nnext, Node<T>* ddown){
        this->posx=x;
        this->posy=y;
        this->next=nnext;
        this->down=ddown;
        this->value=valor;
    }
public:
    Node(){
        posx=-1;
        posy=-1;
        value=-1;
        down=nullptr;
        next=nullptr;
    }
    Node (unsigned int _posx, unsigned int _posy,T _value){
        build(_posx,_posy,_value,nullptr,nullptr);
    };
    void set_down(Node<T> nodo){
        down=nodo;
    }
    void set_next(Node<T> nodo){
        down=nodo;
    }
    Node(const Node<T>& other){
        build(other.posx,other.posy,other.value,other.next,other.down);
    }
    Node<T>& operator=(Node<T>& other){
        cout<<"Operador ="<<endl;
        cout<<other.posx<<" "<<other.posy<<" "<<other.value<<" "<<other.next<<" "<<other.down<<endl;
        build(other.posx,other.posy,other.value,other.next,other.down);
        return *this;
    }
    friend class Matrix<T>;
};

template <typename T>
class Root{
    Node<T> *next;
    Node<T> *down;
    public:
    Root (){
        next=nullptr;
        down=nullptr;
    }
    friend class Matrix<T>;
};

#endif //SPARSE_MATRIX_NODE_H
