
#include "astronauta.h"

Astronauta::Astronauta() {
    this->cpf = "";
    this->nome = "";
    this->idade = 0;
    this->esta_vivo = true;
};

Astronauta::Astronauta(std::string param_cpf, std::string param_nome, int param_idade, bool param_esta_vivo) {
    this->cpf = param_cpf;
    this->nome = param_nome;
    this->idade = param_idade;
    this->esta_vivo = param_esta_vivo;
};

// Astronauta::Astronauta(Astronauta &param_astronauta) {
//     this->cpf = param_astronauta.getCpf();
//     this->nome = param_astronauta.getNome();
//     this->idade = param_astronauta.getIdade();
// };

// Astronauta Astronauta::operator= (Astronauta *param_astronauta) {
//     return Astronauta(param_astronauta->getCpf(), param_astronauta->getNome(), param_astronauta->getIdade());
// }

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