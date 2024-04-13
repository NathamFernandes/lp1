#ifndef MENUS_H
#define MENUS_H

#include "astronauta.h"

/*
 * 0 - Encerrar programa
 * 1 - Opções de voo
 * 2 - Opções para astronautas
 *
 */
int displayMenuPrincipal();

/*
 * 0 -
 * 1 - Cadastrar voo
 * *2 - Listar voos
 * *3 - Adicionar astronauta em um voo
 * **4 - Remover astronauta de um voo
 * **5 - Lançar um voo
 * ***6 - Explodir um voo
 * ***7 - Finalizar um voo
 */
// int displayMenuVoo();

Astronauta* cadastrarAstronauta(Astronauta *param_astronautas_vivos, int param_qtd_astronautas_vivos);

void displayAstronautasMortos(Astronauta *param_astronautas_mortos, int param_qtd_astronautas_vivos);

void displayOpcaoInvalida();

// void menuListarVoos();
// void menuAddAstronautaNoVoo();



// int menuAstronauta();

// void menuListarAstronautasMortos();

#endif