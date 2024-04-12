#include <iostream>

class Teste {
    public:
        int idade;

        void mytest(int param);
};

void Teste::mytest(int param) {
    std::cout << "xd" << std::endl;
}

int main (int arc, char *agrv[]) {
    Teste test;
    test.idade = 10;

    std::cout << test.idade << std::endl; 

    test.mytest(test.idade);
    return 0;
}