// Aula 01 PAVIC Progrmação Paralela 2024

#include <iostream> // Entrada e saida de dados

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");

    int numero;

    std::cout << "Digite sua nota" << std::endl;
    std::cin >> numero;

    if (numero >= 90)
        std::cout << "Nota A" << std::endl;
    else if (numero >= 80)
        std::cout << "Nota B" << std::endl;
    else if (numero >= 70)
        std::cout << "Nota C" << std::endl;
    else if (numero >= 60)
        std::cout << "Nota D" << std::endl;
    else {
        std::cout << "Nota F" << std::endl;
        std::cout << "Reprovado" << std::endl;
    }

    return 0;
}