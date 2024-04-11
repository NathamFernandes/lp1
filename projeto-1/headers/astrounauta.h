#ifndef ASTRONAUTA_H
#define ASTRONAUTA_H

#include <string>

class Astronauta {
    string cpf;
    string nome;
    int idade;

    public:
        Astronauta getCpf();
        Astronauta setCpf();

        Astronauta getNome();
        Astronauta setNome();

        Astronauta getIdade();
        Astronauta setIdade();

}

#endif