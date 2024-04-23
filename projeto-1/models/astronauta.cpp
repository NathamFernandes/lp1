
#include "astronauta.h"

Astronauta::Astronauta() {
    this->cpf       = "";
    this->nome      = "";
    this->idade     = 0;
    this->status    = DISPONIVEL;
};

Astronauta::Astronauta(std::string cpf, std::string nome, int idade, statusAstronauta status) {
    this->cpf       = cpf;
    this->nome      = nome;
    this->idade     = idade;
    this->status    = status;
};

std::string Astronauta::getCpf() {
    return this->cpf;
}

void Astronauta::setCpf(std::string cpf) {
    this->cpf = cpf;
}

std::string Astronauta::getNome() {
    return this->nome;
}

void Astronauta::setNome(std::string nome) {
    this->nome = nome;
}

int Astronauta::getIdade() {
    return this->idade;
}

void Astronauta::setIdade(int idade) {
    this->idade = idade;
}

statusAstronauta Astronauta::getStatus() {
    return this->status;
}

void Astronauta::setStatus(statusAstronauta status) {
    this->status = status;
}