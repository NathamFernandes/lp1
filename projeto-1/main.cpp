#include <iostream>
#include <string>

int menuVoo();

#include "astronauta.h"
#include "utils.h"
// #include "voo_h"
// #include "menus_h"

int main(int argc, char *argv[]) {
    int opcao;

    Astronauta astronauta;

    while (opcao != 0) {
        // opcao = menuPrincipal();
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                menuVoo();
                break;
            case 2:
                //menuVoo();
                break;
            default:
                //menuOpcaoInvalida();
                break;
        }
    }

    return 0;
}

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
int menuVoo() {
    int opcao;
    std::string funcionalidades[8] = {
        "Voltar à tela anterior",
        "Cadastrar voo",
        "Listar voos",
        "Adicionar Astronauta em um Voo",
        "Remover Astronauta de um Voo",
        "Lançar um Voo",
        "Explodir um Voo",
        "Finalizar um Voo"
    };

    cls();

    for (int i = 0; i < 8; i++) {
        std::cout << i << " - " << funcionalidades[i] << "\n";
    }

    std::cin >> opcao;

    //std::cout << "0 - " << funcionalidades[0] << " " << funcionalidades[1] << " " << funcionalidades[2] << " " << funcionalidades[3] << " lol" << std::endl;

    return 1;
};


// int menuPrincipal();