#ifndef VOO_H
#define VOO_H

#include <string>
#include ASTRONAUTA_H

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