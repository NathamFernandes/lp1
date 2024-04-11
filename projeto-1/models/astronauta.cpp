#include <iostream>

#include "astronauta.h"

string Astronauta::getCpf() {
    return this.cpf; // this->cpf
}

void sAstronauta::setCpf(string cpf) {
    this.cpf = cpf;
}

string Astronauta::getNome() {
    return this.nome; // this->nome
}

void Astronauta::setNome(string nome) {
    this.nome = nome;
}

int Astronauta::getIdade() {
    return this.idade; // this->idade
}

void Astronauta::setIdade(int idade) {
    this.idade = idade;
}