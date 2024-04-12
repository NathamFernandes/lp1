#ifndef VOO_H
#define VOO_H

#include <string>
#include "astronauta.h"

class Voo {
    int codigo;
    Astronauta *passageiros;

    public:
        int getCodigo();
        void setCodigo(int cod);

        Astronauta* getPassageiros();
        void setPassageiros(Astronauta *pass);

        void addAstronautaNoVoo(string cpf);
        void rmAstronautaDoVoo(string cpf);

        void lancarVoo(Astronauta ast);

        // delete[]
        void explodirVoo();
        void finalizarVoo();
}

#endif