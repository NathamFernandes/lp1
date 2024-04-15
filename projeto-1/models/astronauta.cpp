
#include "astronauta.h"

Astronauta::Astronauta() {
    this->cpf       = "";
    this->nome      = "";
    this->idade     = 0;
    this->esta_vivo = true;
    this->is_in_voo = false;
};

Astronauta::Astronauta(std::string param_cpf, std::string param_nome, int param_idade, bool param_esta_vivo, bool param_is_in_voo) {
    this->cpf       = param_cpf;
    this->nome      = param_nome;
    this->idade     = param_idade;
    this->esta_vivo = param_esta_vivo;
    this->is_in_voo = param_is_in_voo;
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

bool Astronauta::getEstaVivo() {
    return this->esta_vivo;
}

void Astronauta::setEstaVivo(bool param_esta_vivo) {
    this->esta_vivo = param_esta_vivo;
}

bool Astronauta::getIsInVoo() {
    return this->is_in_voo;
}

void Astronauta::setIsInVoo(bool param_is_in_voo) {
    this->is_in_voo = param_is_in_voo;
}