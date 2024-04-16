#include <iostream>

#include "voo.h"

Voo::Voo() {
    this->codigo = 0;
    this->passageiros = new Astronauta[0];
    this->qtd_passageiros = 0;
    this->status = "";
}

Voo::Voo(int param_codigo, Astronauta *param_passageiros, int param_qtd_passageiros, std::string param_status) {
    this->codigo = param_codigo;
    this->passageiros = param_passageiros;
    this->qtd_passageiros = param_qtd_passageiros;
    this->status = param_status;
    // delete[] pass;
}

int Voo::getCodigo() {
    return this->codigo;
}

void Voo::setCodigo(int param_codigo) {
    this->codigo = param_codigo;
}

Astronauta* Voo::getPassageiros() {
    return this->passageiros;
}

void Voo::setPassageiros(Astronauta *param_passageiros) {
    this->passageiros = param_passageiros;
}

int Voo::getQtdPassageiros() {
    return this->qtd_passageiros;
}

void Voo::setQtdPassageiros(int param_qtd_passageiros) {
    this->qtd_passageiros = param_qtd_passageiros;
}

std::string Voo::getStatus() {
    return this->status;
}

void Voo::setStatus(std::string param_status) {
    this->status = param_status;
}

// void finalizarVoo();
// void explodirVoo();