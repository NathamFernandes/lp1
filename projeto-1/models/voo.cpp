#include <iostream>

#include "voo.h"

Voo::Voo() {
    this->codigo = 0;
    this->passageiros = new Astronauta[0];
}

Voo::Voo(int cod, Astronauta *pass) {
    this->codigo = cod;
    this->passageiros = pass;
    // delete[] pass;
}

int Voo::getCodigo() {
    return this->codigo;
}

void Voo::setCodigo(int codigo) {
    this->codigo = codigo;
}

Astronauta* Voo::getPassageiros() {
    return this->passageiros;
}

void Voo::setPassageiros(Astronauta *passageiros) {
    this->passageiros = passageiros;
}


// void finalizarVoo();
// void explodirVoo();