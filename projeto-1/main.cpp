#include <iostream>
#include <string>

#include "voo.h"
#include "astronauta.h"
#include "utils.h"
#include "menus.h"

int main(int argc, char *argv[]) {
    int opcao_menu = -1;
    int opcao_func = -1;
    int opcao = -1;

    Astronauta *astronautas_vivos;
    int qtd_astronauta_vivos = 0;
    Astronauta *astronautas_mortos;
    int qtd_astronauta_mortos = 0;
    // Voo voo;
    // Voo *lista_de_voos;

    while (opcao != 0) {
        opcao = displayMenuPrincipal();

        switch (opcao) {
            case 0:
                break;
            // case 1:
            //     opcao_func = displayMenuVoo();
            //     break;
            case 2:
                astronautas_vivos = cadastrarAstronauta(astronautas_vivos, qtd_astronauta_vivos);
                qtd_astronauta_vivos++;
                break;
            // case 3:
            //     break;
            case 4:
                displayAstronautasMortos(astronautas_vivos, qtd_astronauta_vivos);
                break;
            default:
                displayOpcaoInvalida();
                break;
        }


    }

    return 0;
}