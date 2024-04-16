
#include "astronauta.h"

Astronauta::Astronauta() {
    this->cpf       = "";
    this->nome      = "";
    this->idade     = 0;
    this->status    = "";
};

Astronauta::Astronauta(std::string param_cpf, std::string param_nome, int param_idade, std::string param_status) {
    this->cpf       = param_cpf;
    this->nome      = param_nome;
    this->idade     = param_idade;
    this->status    = param_status;
};

std::string Astronauta::getCpf() {
    return this->cpf;
}

void Astronauta::setCpf(std::string param_cpf) {
    this->cpf = param_cpf;
}

std::string Astronauta::getNome() {
    return this->nome;
}

void Astronauta::setNome(std::string param_nome) {
    this->nome = param_nome;
}

int Astronauta::getIdade() {
    return this->idade;
}

void Astronauta::setIdade(int param_idade) {
    this->idade = param_idade;
}

std::string Astronauta::getStatus() {
    return this->status;
}

void Astronauta::setStatus(std::string param_status) {
    this->status = param_status;
}