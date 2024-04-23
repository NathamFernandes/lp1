#ifndef ASTRONAUTA_H
#define ASTRONAUTA_H

#include <string>

enum statusAstronauta {
    DISPONIVEL,
    ALOCADO,
    EM_MISSAO,
    MORTO,
}

class Astronauta {
    std::string cpf;
    std::string nome;
    int idade;
    
    //

    statusAstronauta status;

    public:
        Astronauta();
        Astronauta(std::string cpf, std::string nome, int idade, statusAstronauta status = DISPONIVEL);

        std::string getCpf();
        void setCpf(std::string cpf);

        std::string getNome();
        void setNome(std::string nome);

        int getIdade();
        void setIdade(int idade);

        //

        statusAstronauta getStatus();
        void setStatus(statusAstronauta status);
};

#endif