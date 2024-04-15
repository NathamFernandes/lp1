_g++ -W -I .\headers .\controllers\operations.cpp .\controllers\utils.cpp .\controllers\menus.cpp .\models\astronauta.cpp .\models\voo.cpp .\main.cpp -o mainfile_

_g++ -W -I ./headers ./controllers/operations.cpp ./controllers/utils.cpp ./controllers/menus.cpp ./models/astronauta.cpp ./models/voo.cpp ./main.cpp -o mainfile_

## aula sei la

### sobrecarga de funcao

nome > tipos dos parâmetros | definem a função

esse processo ocorre na compilação, e não na execução


--

assinaturas diferentes e argumento padrão

-> niveis de otimização no compilador

argumentos padrão devem ser os ÚLTIMOS para evitar ambiguidades.

int coisar(int a = 10, int b = 10, int c);

coisar(1, 2); ??

--

passagem de parâmetro por valor

cópia do endereço. (C)

passagem por referência do endereço e utilizando a variável do escopo pai.

-- 

### sobrecarga de operadores

-> aula 22, projeto

<<, >>, +, -

tipos primitivos não podem ser alterados. classes sim.

"construtor padrão, construtuor parametrizado, construtor cópia"

-> Copy Constructor (deep copy && shallow copy)

char também é um número. (ascii)
booleano ocupa 1 byte :0

-> short type??

error: no match for 'operator+' 

implementar o método

```
Tempo a, b;
Tempo new_tempo = tempo_a.somar(tempo_b)
```

*C++ NÃO PERMITE CRIAR NOVOS OPERADORES.*

-> linguagem verbosa, explícita
-> armadillo c++ (matrizes, exemplo)

SOBRECARGA: operator+, operator-, operator\*

-> https://stackoverflow.com/questions/7740350/overloading-postfix-and-prefix-operators

-> operador cópia? wtf