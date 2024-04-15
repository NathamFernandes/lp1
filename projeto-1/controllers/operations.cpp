#include <iostream>

#include "operations.h"
#include "menus.h"
#include "utils.h"

Voo *cadastrarVoo(Voo *param_lista_voos, int param_qtd_voos) {
    int codigo;
    Astronauta *passageiros = new Astronauta[0];

    clear_terminal();

    std::cout << "Codigo do Voo: ";
    std::cin >> codigo;

    Voo *new_lista_voos = new Voo[param_qtd_voos + 1];

    for (int i = 0; i < param_qtd_voos; i++) {
        new_lista_voos[i] = param_lista_voos[i];
    }

    new_lista_voos[param_qtd_voos] = Voo(codigo, passageiros);

    delete[] param_lista_voos;

    return new_lista_voos;
}

Astronauta *cadastrarAstronauta(Astronauta *param_lista_astronautas, int param_qtd_astronautas) {
    std::string cpf;
    std::string nome;
    int idade;

    clear_terminal();

    std::cout << "CPF: ";
    std::cin >> cpf;
    std::cout << "Nome: ";
    std::cin >> nome;
    std::cout << "Idade: ";
    std::cin >> idade;

    Astronauta *new_astronautas_vivos = new Astronauta[param_qtd_astronautas + 1];

    for (int i = 0; i < param_qtd_astronautas; i++) {
        new_astronautas_vivos[i] = param_lista_astronautas[i];
    }
    
    new_astronautas_vivos[param_qtd_astronautas] = Astronauta(cpf, nome, idade);

    delete[] param_lista_astronautas;

    return new_astronautas_vivos;
}

int selecionarVoo(Voo *param_lista_voos, int param_qtd_voos) {
    int opcao;
    bool opcao_invalida;

    do {
        clear_terminal();

        std::cout << "Por favor, selecione o indice do voo.\n" << std::endl;

        for (int i = 0; i < param_qtd_voos; i++) {
            std::cout << i + 1 << " - Codigo: " << param_lista_voos[i].getCodigo() << "\n";
        }

        std::cin >> opcao;

        opcao_invalida = opcao <= 0 || opcao > param_qtd_voos || (param_lista_voos[opcao -1].getStatus().compare("PLANEJADO") != 0);

        if (opcao_invalida) displayOpcaoInvalida();
    } while (opcao_invalida);

    return opcao;
}

std::string selecionarAstronauta(Astronauta *param_lista_astronautas, int param_qtd_astronautas) {
    std::string cpf;
    bool opcao_invalida = true;

    do {
        clear_terminal();

        std::cout << "Por favor, insira o CPF do astronauta.\n" << std::endl;

        for (int i = 0; i < param_qtd_astronautas; i++) {
            std::cout << param_lista_astronautas[i].getCpf() << " - Nome: " << param_lista_astronautas[i].getNome() << "\n";
        }

        std::cin >> cpf;

        for (int i = 0; i < param_qtd_astronautas; i++) {
            if (cpf.compare(param_lista_astronautas[i].getCpf()) == 0) {
                opcao_invalida = false;
            }
        }

        if (opcao_invalida) displayOpcaoInvalida();
    } while (opcao_invalida);

    return cpf;
}

// Opção 3 -> 1
void listarVoos(Voo *param_lista_voos, int param_qtd_voos) {
    int qtd_passageiros;
    clear_terminal();

    std::cout << "Lista de voos\n\n";

    for (int i = 0; i < param_qtd_voos; i++) {
        qtd_passageiros = param_lista_voos[i].getQtdPassageiros();

        std::cout << i + 1 << " - Codigo: " << param_lista_voos[i].getCodigo() << "; Passageiros: " << qtd_passageiros << "\n";
        for (int j = 0; j < qtd_passageiros; j++) {
            std::cout << "    " << "- Astronauta: " << j + 1 << ": " << param_lista_voos[i].getPassageiros()[j].getNome() << " CPF: " << param_lista_voos[i].getPassageiros()[j].getCpf() << "\n";
        }
    }

    pause_terminal();
}

// Opção 3 -> 2
void adicionarAstronautaNoVoo(Voo *param_lista_voos, Astronauta *param_lista_astronautas, int param_qtd_voos, int param_qtd_astronautas) {
    int opcao_voo, index_astronauta;
    std::string cpf_astronauta;

    /* Inputs e validações */
    if (param_qtd_voos == 0 || param_qtd_astronautas == 0) {
        displayQtdInsuficiente();
        return;
    }

    opcao_voo = selecionarVoo(param_lista_voos, param_qtd_voos);
    if (opcao_voo == 0) return;
    opcao_voo--;

    cpf_astronauta = selecionarAstronauta(param_lista_astronautas, param_qtd_astronautas);

    if (existeAstronautaRepetido(param_lista_voos[opcao_voo], cpf_astronauta)) {
        return;
    };

    /* Declaração e inicialização de nova lista de passageiros */
    int old_qtd_passageiros = param_lista_voos[opcao_voo].getQtdPassageiros();
    Astronauta *new_passageiros = new Astronauta[old_qtd_passageiros + 1];

    for (int i = 0; i < old_qtd_passageiros; i++) {
        new_passageiros[i] = param_lista_voos[opcao_voo].passageiros[i];
    }

    /* Validação para o caso o astronauta já esteja em outro voo. */
    index_astronauta = findAstronauta(cpf_astronauta, param_lista_astronautas, param_qtd_astronautas);

    if (param_lista_astronautas[index_astronauta].getIsInVoo()) return;
    else param_lista_astronautas[index_astronauta].setIsInVoo(true);

        std::cout << param_lista_astronautas[index_astronauta].getIsInVoo() << std::endl;

    pause_terminal();

    new_passageiros[old_qtd_passageiros] = param_lista_astronautas[index_astronauta];

    /* Realocação de memória e free */
    delete[] param_lista_voos[opcao_voo].passageiros;
    param_lista_voos[opcao_voo].passageiros = new_passageiros;
    param_lista_voos[opcao_voo].setQtdPassageiros(old_qtd_passageiros + 1);

    std::cout << "Astronauta adicionado com sucesso!\n\n" << std::endl;
    
    pause_terminal();
}

bool existeAstronautaRepetido(Voo param_voo, std::string param_cpf) {
    int qtd_total = 0;

    for (int i = 0; i < param_voo.getQtdPassageiros(); i++) {
        if (param_cpf.compare(param_voo.getPassageiros()[i].getCpf()) == 0) {
            qtd_total++;
        }
    }

    if (qtd_total > 0) return true;
    else return false;
}

int findAstronauta(std::string param_cpf, Astronauta *param_lista_astronautas, int param_qtd_astronautas) {
    for (int i = 0; i < param_qtd_astronautas; i++) {
        if (param_cpf.compare(param_lista_astronautas[i].getCpf()) == 0) {
            return i;
        }
    }

    return -1;
}

// Opção 4
void listarAstronautasMortos(Astronauta *param_lista_astronautas, int param_qtd_astronautas) {
    clear_terminal();

    std::cout << "Astronautas Mortos\n\n" << std::endl;

    for (int i = 0; i < param_qtd_astronautas; i++) {
        if (!(param_lista_astronautas[i].getEstaVivo())) {
            std::cout << i + 1 << " - Nome: " << param_lista_astronautas[i].getNome() << "; Idade: " << param_lista_astronautas[i].getIdade() << "; CPF: " << param_lista_astronautas[i].getCpf() << "\n";
        }
        
    }

    pause_terminal();
}

