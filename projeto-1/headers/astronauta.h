#ifndef ASTRONAUTA_H
#define ASTRONAUTA_H

#include <string>

class Astronauta {
    std::string cpf;
    std::string nome;
    int idade;
    //
    std::string status;
    // bool belongs_to_voo;

    public:
        Astronauta();
        Astronauta(std::string param_cpf, std::string param_nome, int param_idade, std::string param_status = "DISPONIVEL");

        std::string getCpf();
        void setCpf(std::string param_cpf);

        std::string getNome();
        void setNome(std::string param_nome);

        int getIdade();
        void setIdade(int param_idade);

        //

        std::string getStatus();
        void setStatus(std::string param_status);

        // bool getBelongsToVoo();
        // void setBelongsToVoo(bool param_belongs_to_voo);
};

#endif