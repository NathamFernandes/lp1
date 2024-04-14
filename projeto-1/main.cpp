#include <iostream>
#include <string>

#include "voo.h"
#include "astronauta.h"
#include "utils.h"
#include "menus.h"

int main(int argc, char *argv[]) {
    int opcao = -1, qtd_astronauta_vivos = 0, qtd_astronauta_mortos = 0, qtd_de_voos;

    Astronauta *astronautas_vivos = new Astronauta[0];
    Astronauta *astronautas_mortos = new Astronauta[0];
    Voo *lista_de_voos = new Voo[0];

    while (opcao != 0) {
        opcao = displayMenuPrincipal();

        switch (opcao) {
            case 0:
                break;
            case 1:
                lista_de_voos = cadastrarVoo(lista_de_voos, qtd_de_voos); 
                qtd_de_voos++;
                break;
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