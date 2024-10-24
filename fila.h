// Tipo abstrato de dado "fila de inteiros"
// Prof. Carlos Maziero - DINF/UFPR, Out 2024
//
// Este TAD implementa uma fila de números inteiros com capacidade
// para até CAP elementos, definida no momento de sua criação.
//
// Implementação com _______________ (completar).

#ifndef FILA
#define FILA
#include "fila.h"
#include <stdlib.h>
#include <stdio.h>
struct fila_t {
  int *elem;       // Vetor de elementos (ponteiro, alocado dinamicamente)
  int capacidade;  // Capacidade da fila
  int quant;       // Quantidade de elementos
  int ult;         // Índice do último elemento
  int prime;       // Índice do primeiro elemento
};
 
// Cria uma fila vazia com a capacidade informada e a retorna;
// Retorna NULL em caso de erro
struct fila_t *fila_cria(int capacidade) {
    struct fila_t *f = malloc(sizeof(struct fila_t));
    if (f == NULL) return NULL;  // Verifica se a alocação falhou

    f->elem = calloc(capacidade, sizeof(int));  // Aloca espaço para os elementos
    if (f->elem == NULL) {  // Verifica se a alocação de elementos falhou
        free(f);  // Libera a estrutura se a alocação de elementos falhar
        return NULL;
    }

    f->capacidade = capacidade;
    f->quant = 0;
    f->ult = -1;
    f->prime = 0;

    return f;
}


// Remove todos os elementos da fila, libera memória e retorna NULL
struct fila_t *fila_destroi (struct fila_t *f){
    if (f == NULL) return NULL;  // Verifica se a fila é NULL
    free(f->elem);  // Libera o vetor de elementos
    free(f);  // Libera a estrutura
    return NULL;
}

// Insere o elemento no final da fila (politica FIFO);
// Retorna o número de elementos na fila após a operação
// ou -1 em caso de erro
int fila_insere (struct fila_t *f, int elem){
  if (f-> ult == f-> capacidade - 1){
    return -1;
  }
  else{
    f-> ult++;
    f-> elem[f -> ult] = elem;
    f-> quant++;
    return f-> quant;
  }
}
// Retira o elemento do inicio da fila (politica FIFO) e o devolve;
// Retorna o número de elementos na fila após a operação
// ou -1 em caso de erro
int fila_retira (struct fila_t *f, int *elem){
  if (f -> quant == 0){
    return -1;
  }
  else{
    *elem = (f -> elem [f-> prime]);
    f-> prime++;
    f-> quant++;
    return f -> quant;
  }
  if (f -> prime != f-> capacidade - 1){
    f-> prime++;
  }
  else {
    f-> prime = 0;
  }
  f-> quant--;
  return f-> quant;
}
//para o ultimo valor da fila e ficar circular
int fila_circular(struct fila_t *f, int elem) {
    if (f->quant == f->capacidade) {
        return -1;  // Fila cheia
    }

    if (f->ult != f->capacidade - 1) {
        f->ult++;
    } else {
        f->ult = 0;
    }

    f->elem[f->ult] = elem;
    f->quant++;
    return f->quant;
}

// Devolve o primeiro da fila, sem removê-lo
// Retorna o número de elementos na fila ou -1 em caso de erro
int fila_primeiro (struct fila_t *f, int *elem){
  if (f->quant == 0)
    return - 1;
  else{
  *elem = f-> elem[f-> prime];
    return f-> quant;
  }
}

// Retorna o tamanho da fila (número de elementos presentes)
int fila_tamanho (struct fila_t *f){
  if (f-> quant == 0)
    return -1;
  return f-> quant;
}

// Retorna a capacidade da fila (número máximo de elementos)
int fila_capacidade (struct fila_t *f){
  if (f-> quant == 0)
    return -1;
  return f-> capacidade;
}

// Imprime o conteúdo da fila do início ao fim, no formato "item item ...",
// com um espaço entre itens, sem espaços antes/depois e sem \n no fim
void fila_imprime (struct fila_t *f) {
    if (f->quant == 0) return;  // Fila vazia

    int i = f->prime;
    for (int count = 0; count < f->quant; count++){
      printf("%d", f->elem[i]);
        if (count < f->quant - 1) {
            printf(" ");  // Imprime espaço entre os elementos
        }
        i = (i + 1) % f->capacidade;  // Avança para o próximo elemento (circular)
    }
}
 

#endif
