#ifndef FILA_H
#define	FILA_H

using namespace std;

template <typename T> class Fila {
public:
    // cria uma fila com capacidade "N"
    Fila(unsigned int N);
 
    // cria uma fila que é cópia de outra fila
    Fila(const Fila& orig);
 
    // destrutor da fila
    ~Fila();
 
    // enfileira "algo" no fim da fila
    void enfileira(const T & algo);
 	
    // desenfileira um dado do início da fila
    T desenfileira();
 
    // retorna uma referência ao dado que está no início 
    // da fila, sem removê-lo da fila
    T & frente() const;
    
   Fila<T> & operator = (const Fila<T> & outra);

    bool vazia() const {return itens == 0; }
    bool cheia() const { return itens == capacidade;}
    unsigned int tamanho() const { return itens;}
private:
    int capacidade;
    int itens, inicio, fim;
 
    // a área de armazenamento da fila
    T* buffer;
};
 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Abaixo seguem os esqueletos das implementações dos métodos da Fila
 
template <typename T> Fila<T>::Fila(unsigned int N) {
    // inicia os atributos da fila: inicialmente
    // ela está vazia
    capacidade = N;
    inicio = 0;
    fim = 0;
    itens = 0;
 
    // aloca memória para guardar "capacidade" dados do tipo "T"
    buffer = new T[capacidade];
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

template <typename T> Fila<T> & Fila<T>::operator = (const Fila<T> & outra){
//copia os atributos usado na F1//
	capacidade=outra.capacidade;
 	inicio=outra.inicio;
	fim=outra.fim;
	itens=outra.itens;

// Desaloca memória (libera o buffer que já tinha)
	delete[] buffer;      // [] pq vc alocou como vetor então tem que destruir como vetor//

// aloca dinamicamente a memória do "buffer"
	buffer = new T[capacidade];
	
// fazer a cópia do q está escrito no buffer
	//for (int n=0; n < capacidade; n++) buffer [n] = outra.buffer[n];
//começa o inicio e termina no fim
	for (int n=inicio; n < fim; n++) buffer[n] = outra.buffer[n];
	return *this;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

template <typename T> Fila<T>::Fila(const Fila& orig) {
    capacidade=orig.capacidade;
 	inicio=orig.inicio;
	fim=orig.fim;
	itens=orig.itens;
        buffer=orig.buffer;
}
 
template <typename T> Fila<T>::~Fila() {
}
 
template <typename T> void Fila<T>::enfileira(const T &algo) {
	
	if (cheia()) throw -1;
	  buffer[fim] = algo;
	  fim = (fim+1) % capacidade;
	  itens++;

}
 
template <typename T> T Fila<T>::desenfileira() {
	
	if (vazia())throw -1;
          //int pos = inicio;
	  T algo =buffer[inicio];
	  inicio++;
	  itens--;
	return algo;
}
 
template <typename T> T & Fila<T>::frente() const {
}
 
#endif	 /*FILA_H*/ 
