#include <iostream>

#include ASTRONAUTA_H

Astronauta::getCpf() {
    return this.cpf; // this->cpf
}

Astronauta::setCpf(string cpf) {
    this.cpf = cpf;
}

Astronauta::getNome() {
    return this.nome; // this->nome
}

Astronauta::setNome(string nome) {
    this.nome = nome;
}

Astronauta::getIdade() {
    return this.idade; // this->idade
}

Astronauta::setIdade(int idade) {
    this.idade = idade;
}