#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "voo.h"
#include "astronauta.h"

Voo *cadastrarVoo(Voo *param_lista_voos, int param_qtd_voos);
Astronauta* cadastrarAstronauta(Astronauta *param_astronautas_vivos, int param_qtd_astronautas_vivos);

void listarVoos(Voo *param_lista_voos, int param_qtd_voos);

void adicionarAstronautaNoVoo(Voo *param_lista_voos, Astronauta *param_lista_astronautas, int param_qtd_voos, int param_qtd_astronautas);

void listarAstronautasMortos(Astronauta *param_lista_astronautas, int param_qtd_astronautas);

// Utils

int selecionarVoo(Voo *param_lista_voos, int param_qtd_voos);
std::string selecionarAstronauta(Astronauta *param_lista_astronautas, int param_qtd_astronautas);
Astronauta findAstronauta(std::string param_cpf, Astronauta *param_lista_astronautas, int param_qtd_astronautas);

#endif