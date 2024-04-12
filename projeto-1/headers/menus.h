#ifndef MENUS_H
#define MENUS_H

/*
 * 0 - Encerrar programa
 * 1 - Opções de voo
 * 2 - Opções para astronautas
 *
 */
int menuPrincipal();

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
int menuVoo();

void menuListarVoos();
void menuAddAstronautaNoVoo();



int menuAstronauta();

void menuListarAstronautasMortos();

#endif