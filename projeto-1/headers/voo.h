#ifndef VOO_H
#define VOO_H

#include "astronauta.h"

enum statusVoo {
        PLANEJAMENTO,
        EM_CURSO,
        FINALIZADO_SUCESSO,
        FINALIZADO_FRACASSO,
}

class Voo {
    int codigo;
    //
    int qtd_passageiros;
    statusVoo status;

    public:
        Astronauta *passageiros;

        Voo();
        Voo(int codigo, Astronauta *passageiros = new Astronauta[0], int qtd_passageiros = 0, statusVoo status = PLANEJAMENTO);

        int getCodigo();
        void setCodigo(int codigo);

        Astronauta* getPassageiros();
        void setPassageiros(Astronauta *passageiros);

        int getQtdPassageiros();
        void setQtdPassageiros(int qtd_passageiros);

        statusVoo getStatus();
        void setStatus(statusVoo status);
};

#endif