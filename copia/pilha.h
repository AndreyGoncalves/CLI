#ifndef PILHA_H
#define PILHA_H

template <typename T> class Pilha {
public:
    // construtor: deve-se informar a capacidade da pilha
    Pilha(int umaCapacidade);

    // construtor de cópia: cria uma pilha que é cópia de outra
    Pilha(const Pilha& outra);

    // destrutor da pilha
    ~Pilha();

    // operador de atribuição: torna esta pilha uma cópia de outra pilha
    Pilha<T> & operator=(const Pilha<T> & outra);

    // operações da pilha

    void push(const T & dado); // empilha um dado

    T pop(); // desempilha um dado

    T& top() const; // retorna o dado do topo da pilha, sem retirá-lo

    bool vazia() const {
        return topo == 0;
    }

    bool cheia() const {
        return topo == capacidade;
    }
    void esvazia();
protected:
    // atributos da pilha
    T * buffer; // a área de memória para armazenamento da pilha
    int topo, capacidade;

};

template <typename T> Pilha<T> & Pilha<T>::operator=(const Pilha<T> & outra) {
    delete[] buffer;

    topo = outra.topo;
    capacidade = outra.capacidade;

    buffer = new T [capacidade];
    for (int i = 0; i < capacidade; i++) buffer[i] = outra.buffer [i];
}

template <typename T> Pilha<T>::Pilha(int umaCapacidade) {

    topo = 0;
    capacidade = umaCapacidade;
    buffer = new T [umaCapacidade];
}

template <typename T> Pilha<T>::Pilha(const Pilha& outra) {

    delete buffer;
    *this = outra;
}

template <typename T> Pilha<T>::~Pilha() {

}

template <typename T> void Pilha<T>::esvazia() {

}

template <typename T> void Pilha<T>::push(const T & dado) {

    if (cheia()) throw -1;
    buffer[topo] = dado;
    topo++;

}

template <typename T> T Pilha<T>::pop() {

    if (vazia()) throw -1;
    topo--;
    T dado = buffer[topo];

    return dado;
}

template <typename T> T& Pilha<T>::top() const {
    if (!vazia()) {
        return buffer[topo - 1];

    }
}

#endif
