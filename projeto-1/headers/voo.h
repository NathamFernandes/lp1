#ifndef VOO_H
#define VOO_H

#include <string>
#include "astronauta.h"

class Voo {
    int codigo;
    Astronauta *passageiros;

    public:
        Voo getCodigo();
        Voo setCodigo();

        Voo getPassageiros();
        Voo setPassageiros();
}

#endif