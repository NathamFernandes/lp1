#ifndef ASTRONAUTA_H
#define ASTRONAUTA_H

#include <string>

class Astronauta {
    std::string cpf;
    std::string nome;
    int idade;
    //
    bool esta_vivo;

    public:
        Astronauta();
        Astronauta(std::string param_cpf, std::string param_nome, int param_idade, bool param_esta_vivo = true);
        // Astronauta(Astronauta &param_astronauta);

        // Astronauta operator= (Astronauta *param_astronauta);

        std::string getCpf();
        void setCpf(std::string param_cpf);

        std::string getNome();
        void setNome(std::string param_nome);

        int getIdade();
        void setIdade(int param_idade);

        bool getEstaVivo();
        void setEstaVivo(bool param_esta_vivo);
};

#endif