#include <iostream>
#include <vector>

void ascSelectionSort(std::vector<int> vetor);
void descSelectionSort(std::vector<int> vetor);

void ascInsertionSort(std::vector<int> vetor);
void descInsertionSort(std::vector<int> vetor);

void ascBubbleSort(std::vector<int> vetor);
void descBubbleSort(std::vector<int> vetor);

void printArray(std::vector<int> vetor);

void printArray(std::vector<int> vetor) {
    for (int i = 0; i < vetor.size(); i++) {
        std::cout << vetor[i] << " ";
    }

    std::cout << "\n" << std::endl;
}

// Comando: ache o menor da fila depois do atual e troque com ele. 
void ascSelectionSort(std::vector<int> vetor) {
    int indexMenorDaVez;

    for (int i = 0; i < vetor.size() - 1; i++) {
        indexMenorDaVez = i;
        for (int j = i + 1; j < vetor.size(); j++) {
            if (vetor[j] < vetor[indexMenorDaVez]) {
                indexMenorDaVez = j;
            }
        }
        
        std::swap(vetor[i], vetor[indexMenorDaVez]);

    }

    std::cout << "Vetor Ordenado Selection ASC: \n\n";

    printArray(vetor);
}

// Comando: ache o maior da fila depois do atual e troque com ele. 
void descSelectionSort(std::vector<int> vetor) {
    int indexMaiorDaVez;

    for (int i = 0; i < vetor.size() - 1; i++) {
        indexMaiorDaVez = i;
        for (int j = i + 1; j < vetor.size(); j++) {
            if (vetor[j] > vetor[indexMaiorDaVez]) {
                indexMaiorDaVez = j;
            }
        }
        
        std::swap(vetor[i], vetor[indexMaiorDaVez]);

    }

    std::cout << "Vetor Ordenado Selection DESC: \n\n";

    printArray(vetor);
}

// Comando: troque enquanto o meu atual não for o primeiro e for menor que o meu atual + 1. 
void ascInsertionSort(std::vector<int> vetor) {
    int j;

    for (int i = 0; i < vetor.size(); i++) {
        j = i;

        while (j > 0 && vetor[j] < vetor[j - 1]) {
            std::swap(vetor[j], vetor[j - 1]);
            j--;
        }
    }

    std::cout << "Vetor Ordenado Insertion ASC: \n\n";

    printArray(vetor);
}

// Comando: troque enquanto o meu atual não for o primeiro e for maior que o meu atual + 1. 
void descInsertionSort(std::vector<int> vetor) {
    int j;

    for (int i = 0; i < vetor.size() - 1; i++) {
        j = i;

        while (j > 0 && vetor[j - 1] < vetor[j]) {
            std::swap(vetor[j], vetor[j - 1]);
            j--;
        }
    }

    std::cout << "Vetor Ordenado Insertion DESC: \n\n";

    printArray(vetor);
}

// Comando: se o meu atual for menor do que o anterior, troque.
void ascBubbleSort(std::vector<int> vetor) {
    bool houveTroca;

    for (int i = 0; i < vetor.size(); i++) {
        houveTroca = false;

        for (int j = 1; j < vetor.size(); j++) {
            if (vetor[j] < vetor[j - 1]) {
                std::swap(vetor[j], vetor[j - 1]);
                houveTroca = true;
            }
        }

        if (!(houveTroca)) break;
    }

    std::cout << "Vetor Ordenado Bubble ASC: \n\n";

    printArray(vetor);
}

// Comando: se o meu atual for maior do que o anterior, troque.
void descBubbleSort(std::vector<int> vetor) {
    bool houveTroca;

    for (int i = 0; i < vetor.size(); i++) {
        houveTroca = false;

        for (int j = 1; j < vetor.size(); j++) {
            if (vetor[j] > vetor[j - 1]) {
                std::swap(vetor[j], vetor[j - 1]);
                houveTroca = true;
            }
        }

        if (!(houveTroca)) break;
    }

    std::cout << "Vetor Ordenado Bubble ASC: \n\n";

    printArray(vetor);
}

int main () {
    std::vector<int> v = {5, 2, 3, 6, 8, 1, 7, 10, 11, 12, 4};

    ascSelectionSort(v);
    descSelectionSort(v);
    ascInsertionSort(v);
    descInsertionSort(v);
    ascBubbleSort(v);   
    descBubbleSort(v); 
}