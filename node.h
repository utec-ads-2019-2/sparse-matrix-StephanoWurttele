#ifndef SPARSE_MATRIX_NODE_H
#define SPARSE_MATRIX_NODE_H
#include <vector>
template <typename T>
class Matrix;

template <typename T>
class Node {
protected:
    Node<T> *next, *down;
    int posx=0,posy=0;
    T value;
public:
    Node (unsigned int posx, unsigned int posy,T value):value(value),next(nullptr),down(nullptr),posx(posx),posy(posy){};
    void set_down(Node<T> nodo){
        down=nodo;
    }
    void set_next(Node<T> nodo){
        down=nodo;
    }

    friend class Matrix<T>;
};


#endif //SPARSE_MATRIX_NODE_H
