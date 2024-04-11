#include <iostream>

#include VOO_H

Voo::getCodigo() {
    return this.codigo;
}

Voo::setCodigo(int codigo) {
    this.codigo = codigo;
}

Voo::getPassageiros() {
    return this.passageiros;
}

Voo::setPassageiros(Astronauta *passageiros) {
    this.passageiros = passageiros;
}