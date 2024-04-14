#ifndef VOO_H
#define VOO_H

#include "astronauta.h"

class Voo {
    int codigo;
    Astronauta *passageiros;

    public:
        Voo();
        Voo(int cod, Astronauta *pass);

        int getCodigo();
        void setCodigo(int cod);

        Astronauta* getPassageiros();
        void setPassageiros(Astronauta *pass);

        // void addAstronautaNoVoo(std::string cpf);
        // void rmAstronautaDoVoo(std::string cpf);

        // void lancarVoo(Astronauta ast);

        // delete[]
        // void explodirVoo();
        // void finalizarVoo();
};

#endif