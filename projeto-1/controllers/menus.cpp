#include <iostream>

#include "menus.h"
#include "utils.h"
#include "astronauta.h"
#include "voo.h"

int displayMenuPrincipal() {
    int opcao;
    std::string funcionalidades[5] = {
        "Encerrar programa",
        "Cadastrar um voo",
        "Cadastrar um astronauta",
        "Listar e gerenciar voos",
        "Mostrar astronautas mortos",
    };

    clear();

    for (int i = 0; i < 5; i++) {
        std::cout << i << " - " << funcionalidades[i] << "\n";
    }

    std::cin >> opcao;

    return opcao;
}

Voo *cadastrarVoo(Voo *param_lista_voos, int tamanho_lista) {
    int codigo;
    Astronauta *passageiros = new Astronauta[0];

    std::cout << "Código do Voo: ";
    std::cin >> codigo;

    Voo *new_lista_voos = new Voo[tamanho_lista + 1];

    for (int i = 0; i < tamanho_lista; i++) {
        new_lista_voos[i] = param_lista_voos[i];
    }

    new_lista_voos[tamanho_lista] = Voo(codigo, passageiros);

    delete[] param_lista_voos;

    return new_lista_voos;
}

Astronauta *cadastrarAstronauta(Astronauta *param_astronautas_vivos, int tamanho_lista) {
    std::string cpf;
    std::string nome;
    int idade;

    std::cout << "CPF: ";
    std::cin >> cpf;
    std::cout << "Nome: ";
    std::cin >> nome;
    std::cout << "Idade: ";
    std::cin >> idade;

    Astronauta *new_astronautas_vivos = new Astronauta[tamanho_lista + 1];

    for (int i = 0; i < tamanho_lista; i++) {
        new_astronautas_vivos[i] = param_astronautas_vivos[i];
    }
    
    new_astronautas_vivos[tamanho_lista] = Astronauta(cpf, nome, idade);

    delete[] param_astronautas_vivos;

    return new_astronautas_vivos;
}

void displayAstronautasMortos(Astronauta *param_astronautas_mortos, int tamanho_lista) {
    clear();

    for (int i = 0; i < tamanho_lista; i++) {
        std::cout << i << " - Nome: " << param_astronautas_mortos[i].getNome() << "; Idade: " << param_astronautas_mortos[i].getIdade() << "; CPF: " << param_astronautas_mortos[i].getCpf() << "\n";
    }

    pause();
}

void displayOpcaoInvalida() {
    clear();

    std::cout << "Opção invalida!" << std::endl;

    pause();
};

///////////////////////

// int displayListaVoos(Voo *param_lista_de_voos) {
//     int tamanho_lista = sizeof(param_lista_de_voos) / sizeof(param_lista_de_voos[0]);
//     int opcao;

//     for (int i = 0; i < tamanho_lista; i++) {
//         std::cout << i << " - Código: " << param_lista_de_voos[i].getCodigo() << "\n";
//     }

//     std::cin >> opcao;

//     return opcao;
// }

// int displayMenuVoo() {
//     int opcao;
//     std::string funcionalidades[8] = {
//         "Voltar a tela anterior",
//         "Cadastrar voo",
//         "Listar voos",
//         "Adicionar Astronauta em um Voo",
//         "Remover Astronauta de um Voo",
//         "Lançar um Voo",
//         "Explodir um Voo",
//         "Finalizar um Voo"
//     };

//     clear();

//     for (int i = 0; i < 8; i++) {
//         std::cout << i << " - " << funcionalidades[i] << "\n";
//     }

//     std::cin >> opcao;

//     return opcao;
// };