#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "voo.h"
#include "astronauta.h"

/*
-> Opção: 1
- @param Voo *param_lista_voos, o endereço da lista de voos.
- @param int param_qtd_voos, tamanho da lista de voos atual.
- @return um novo endereço para a lista incrementado do novo voo.
*/
Voo* cadastrarVoo(Voo *lista_voos, int *qtd_voos);

// Opção: 2
Astronauta* cadastrarAstronauta(Astronauta *lista_astronautas, int *qtd_astronautas);

void listarVoos(Voo *param_lista_voos, int param_qtd_voos);

void adicionarAstronautaNoVoo(Voo *param_lista_voos, Astronauta *param_lista_astronautas, int param_qtd_voos, int param_qtd_astronautas);

// Opção: 3 -> 3
void removerAstronautaDoVoo();

// Opção: 3 -> 4
void lancarVoo(Voo *param_lista_voos, int param_qtd_voos, int param_qtd_astronautas);

// Opção: 3 -> 5
void explodirVoo();

// Opção: 3 -> 6
void finalizarVoo();

// Opção: 4
void listarAstronautasMortos(Astronauta *param_lista_astronautas, int param_qtd_astronautas);

/*
Funções auxiliares e de validação para a regra de negócio do programa.
*/

int selecionarVoo(Voo *param_lista_voos, int param_qtd_voos);
std::string selecionarAstronauta(Astronauta *param_lista_astronautas, int param_qtd_astronautas);

int findVoo(int param_codigo, Voo *param_lista_voos, int param_qtd_voos);
int findAstronauta(std::string param_cpf, Astronauta *param_lista_astronautas, int param_qtd_astronautas);
bool existeAstronautaRepetido(Voo param_voo, std::string param_cpf);


#endif