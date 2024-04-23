#include <iostream>

#include "operations.h"
#include "menus.h"
#include "utils.h"

// Opção: 1
Voo *cadastrarVoo(Voo *lista_voos, int *qtd_voos) {
    int codigo;
    int qtd = *qtd_voos;

    clear_terminal();

    std::cout << "Codigo do Voo: ";
    std::cin >> codigo;

    if (findVoo(codigo, lista_voos, qtd) != -1) {
        displayOperacaoInvalida("voo já cadastrado!");
        return lista_voos;
    }

    Voo *new_lista_voos = new Voo[qtd + 1];

    for (int i = 0; i < qtd; i++) {
        new_lista_voos[i] = lista_voos[i];
    }

    new_lista_voos[qtd] = Voo(codigo);

    delete[] lista_voos;

    (*qtd_voos)++;

    return new_lista_voos;
}

// Opção: 2
Astronauta *cadastrarAstronauta(Astronauta *lista_astronautas, int *qtd_astronautas) {
    std::string cpf;
    std::string nome;
    int idade;

    int qtd = *qtd_astronautas;

    clear_terminal();

    std::cout << "CPF: ";
    std::cin >> cpf;

    if (findAstronauta(cpf, lista_astronautas, qtd) != -1) {
        displayOperacaoInvalida("cpf já cadastrado!");
        return lista_astronautas;
    }

    std::cout << "Nome: ";
    std::cin >> nome;
    std::cout << "Idade: ";
    std::cin >> idade;

    Astronauta *new_lista_astronautas = new Astronauta[qtd + 1];

    for (int i = 0; i < qtd; i++) {
        new_lista_astronautas[i] = lista_astronautas[i];
    }
    
    new_lista_astronautas[qtd] = Astronauta(cpf, nome, idade);

    delete[] lista_astronautas;

    (*qtd_astronautas)++;

    return new_lista_astronautas;
}

// Opção: 3 -> 1
void listarVoos(Voo *lista_voos, int *qtd_voos) {
    int qtd_passageiros;

    clear_terminal();

    std::cout << "Lista de voos\n\n";

    for (int i = 0; i < *qtd_voos; i++) {
        qtd_passageiros = lista_voos[i].getQtdPassageiros();

        std::cout << i + 1 << " - Codigo: " << lista_voos[i].getCodigo() << "; Passageiros: " << qtd_passageiros << "\n";
        for (int j = 0; j < qtd_passageiros; j++) {
            std::cout << "    " << "- Astronauta: " << j + 1 << ": " << lista_voos[i].getPassageiros()[j].getNome() << " CPF: " << lista_voos[i].getPassageiros()[j].getCpf() << "\n";
        }
    }

    pause_terminal();
}

// Opção: 3 -> 2
void adicionarAstronautaNoVoo(Voo *lista_voos, Astronauta *lista_astronautas, int *qtd_voos, int *qtd_astronautas) {
    int opcao_voo, index_astronauta;
    std::string cpf_astronauta;

    clear_terminal();

    /* Inputs e validações */
    if (*qtd_voos == 0 || *qtd_astronautas == 0) {
        displayOperacaoInvalida("quantidade insuficiente astronautas/voos");
        return;
    }

    opcao_voo = selecionarVoo(lista_voos, *qtd_voos);
    if (opcao_voo == 0) return;
    opcao_voo--;

    cpf_astronauta = selecionarAstronauta(lista_astronautas, *qtd_astronautas);

    if (vooContainsAstronauta(lista_voos[opcao_voo], cpf_astronauta)) {
        displayOperacaoInvalida("o astronauta escolhido ja faz parte dos passageiros");
        return;
    };

    /* Declaração e inicialização de nova lista de passageiros */
    int old_qtd_passageiros = lista_voos[opcao_voo].getQtdPassageiros();
    Astronauta *new_passageiros = new Astronauta[old_qtd_passageiros + 1];

    for (int i = 0; i < old_qtd_passageiros; i++) {
        new_passageiros[i] = lista_voos[opcao_voo].passageiros[i];
    }

    /* Validação para o caso o astronauta já esteja em outro voo. */
    index_astronauta = findAstronauta(cpf_astronauta, lista_astronautas, *qtd_astronautas);

    if (lista_astronautas[index_astronauta].getStatus() == DISPONIVEL != 0) {
        displayOperacaoInvalida("o astronauta escolhido nao esta disponivel para novos voos");
        return;
    } else lista_astronautas[index_astronauta].setStatus(ALOCADO);

    new_passageiros[old_qtd_passageiros] = lista_astronautas[index_astronauta];

    /* Realocação de memória e free */
    delete[] lista_voos[opcao_voo].passageiros;
    lista_voos[opcao_voo].passageiros = new_passageiros;
    lista_voos[opcao_voo].setQtdPassageiros(old_qtd_passageiros + 1);

    clear_terminal();

    std::cout << "Astronauta adicionado com sucesso!\n\n" << std::endl;
    
    pause_terminal();
}

// Opção: 3 -> 3
void removerAstronautaDoVoo(Voo *lista_voos, Astronauta *lista_astronautas, int *qtd_voos, int *qtd_astronautas) {
    int opcao_voo, index_astronauta;
    std::string cpf_astronauta;

    clear_terminal();

    /* Inputs e validações */
    if (*qtd_voos == 0 || *qtd_astronautas == 0) {
        displayOperacaoInvalida("quantidade insuficiente astronautas/voos");
        return;
    }

    opcao_voo = selecionarVoo(lista_voos, *qtd_voos);
    if (opcao_voo == 0) return;
    opcao_voo--;

    cpf_astronauta = selecionarAstronauta(lista_astronautas, *qtd_astronautas);

    if (!(vooContainsAstronauta(lista_voos[opcao_voo], cpf_astronauta))) {
        displayOperacaoInvalida("o astronauta escolhido não faz parte dos passageiros");
        return;
    };

    /* Validação para o caso o astronauta já esteja em outro voo. */
    index_astronauta = findAstronauta(cpf_astronauta, lista_astronautas, *qtd_astronautas);

    lista_astronautas[index_astronauta].setStatus = DISPONIVEL;

    /* Declaração e inicialização de nova lista de passageiros */
    int old_qtd_passageiros = lista_voos[opcao_voo].getQtdPassageiros();
    Astronauta *new_passageiros = new Astronauta[old_qtd_passageiros - 1];

    for (int i = 0; i < index_astronauta; i++) {
        new_passageiros[i] = lista_voos[opcao_voo].passageiros[i];
    }

    for (int i = index_astronauta; i < old_qtd_passageiros - 1; i++) {
        new_passageiros[i] = lista_voos[opcao_voo].passageiros[i + 1];
    }

    delete[] lista_voos[opcao_voo].passageiros;
    lista_voos[opcao_voo].passageiros = new_passageiros;
    lista_voos[opcao_voo].setQtdPassageiros(old_qtd_passageiros - 1);

    clear_terminal();

    std::cout << "Astronauta removido com sucesso!\n\n" << std::endl;
    
    pause_terminal();
}

// Opção: 3 -> 4

void lancarVoo(Voo *param_lista_voos, int param_qtd_voos, int param_qtd_astronautas) {
    int opcao_voo;
    
    clear_terminal();

    /* Inputs e validações */
    if (param_qtd_voos == 0 || param_qtd_astronautas == 0) {
        displayOperacaoInvalida("quantidade insuficiente astronautas/voos");
        return;
    }

    opcao_voo = selecionarVoo(param_lista_voos, param_qtd_voos);
    if (opcao_voo == 0) return;
    opcao_voo--;

    clear_terminal();

    std::cout << "Voo lançado com sucesso!\n\n" << std::endl;
    
    pause_terminal();    

}

// Opção: 3 -> 5

void explodirVoo() {

}

// Opção: 3 -> 6

void finalizarVoo() {

}

// Opção: 4
void listarAstronautasMortos(Astronauta *param_lista_astronautas, int param_qtd_astronautas) {
    clear_terminal();

    std::cout << "Astronautas Mortos\n\n" << std::endl;

    for (int i = 0; i < param_qtd_astronautas; i++) {
        if (param_lista_astronautas[i].getStatus() == "MORTO") {
            std::cout << i + 1 << " - Nome: " << param_lista_astronautas[i].getNome() << "; Idade: " << param_lista_astronautas[i].getIdade() << "; CPF: " << param_lista_astronautas[i].getCpf() << "\n";
        }
        
    }

    pause_terminal();
}



// AUX/VALIDATIONS

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

        opcao_invalida = opcao <= 0 || opcao > param_qtd_voos || (param_lista_voos[opcao -1].getStatus().compare("PLANEJAMENTO") != 0);

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

int findVoo(int param_codigo, Voo *param_lista_voos, int param_qtd_voos) {
    for (int i = 0; i < param_qtd_voos; i++) {
        if (param_codigo == param_lista_voos[i].getCodigo()) {
            return i;
        }
    }

    return -1;
}

int findAstronauta(std::string param_cpf, Astronauta *param_lista_astronautas, int param_qtd_astronautas) {
    for (int i = 0; i < param_qtd_astronautas; i++) {
        if (param_cpf.compare(param_lista_astronautas[i].getCpf()) == 0) {
            return i;
        }
    }

    return -1;
}

bool vooContainsAstronauta(Voo param_voo, std::string param_cpf) {
    int qtd_total = 0;

    for (int i = 0; i < param_voo.getQtdPassageiros(); i++) {
        if (param_cpf.compare(param_voo.getPassageiros()[i].getCpf()) == 0) {
            qtd_total++;
        }
    }

    if (qtd_total > 0) return true;
    else return false;
}