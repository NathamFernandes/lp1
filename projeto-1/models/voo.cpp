#include <iostream>

#include "voo.h"

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