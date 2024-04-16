#ifndef VOO_H
#define VOO_H

#include "astronauta.h"

class Voo {
    int codigo;
    //
    int qtd_passageiros;
    std::string status;

    public:
        Astronauta *passageiros;

        Voo();
        Voo(int param_codigo, Astronauta *param_passageiros, int param_qtd_passageiros = 0, std::string param_status = "PLANEJAMENTO");

        int getCodigo();
        void setCodigo(int param_codigo);

        Astronauta* getPassageiros();
        void setPassageiros(Astronauta *param_passageiros);

        int getQtdPassageiros();
        void setQtdPassageiros(int param_qtd_passageiros);

        std::string getStatus();
        void setStatus(std::string param_status);
};

#endif

/*
        // void addAstronautaNoVoo(std::string cpf);
        // void rmAstronautaDoVoo(std::string cpf);

        // void lancarVoo(Astronauta ast);

        // void explodirVoo();
        // void finalizarVoo();
*/