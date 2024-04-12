#ifndef ASTRONAUTA_H
#define ASTRONAUTA_H

#include <string>

class Astronauta {
    std::string cpf;
    std::string nome;
    int idade;

    public:
        std::string getCpf();
        void setCpf();

        std::string getNome();
        void setNome();

        int getIdade();
        void setIdade();

};

#endif