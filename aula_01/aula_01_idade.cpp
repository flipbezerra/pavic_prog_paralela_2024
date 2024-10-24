// Aula 01 PAVIC Progrmação Paralela 2024

#include <iostream> // Entrada e saida de dados
#include <cctype>   // Manipulador de caracteres

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");

    std::string nome;
    int numero;

    std::cout << "Olá!" << std::endl;

    std::cout << "Digite seu nome: ";
    std::cin >> nome;
    nome[0] = std::toupper(nome[0]);
    std::cout << "Digite sua idade: ";
    std::cin >> numero;

    std::cout << "Seu nome é: " << nome << std::endl;
    std::cout << "Sua idade é: " << numero << std::endl;

    if (numero > 18)
        std::cout << "Voce é maior de idade" << std::endl;
    else
        std::cout << "Voce é menor de idade" << std::endl;

    return 0;
}