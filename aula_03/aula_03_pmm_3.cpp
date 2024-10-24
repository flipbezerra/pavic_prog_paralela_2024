// Aula 03 PAVIC Progrmação Paralela 2024

#include <iostream> // Entrada e saida de dados
#include <fstream>  // Ler e escrever imagens
#include <chrono>   // para cronometrar o tempo de execução
#include <sstream>  // para converter int para string

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");

    // Header
    std::string type = "";
    std::string width = "";
    std::string height = "";
    std::string RGB = "";

    std::ifstream old_image; // Ler arquivo
    std::ofstream new_image; // Escrever arquivo

    old_image.open("Image_2.ppm");
    new_image.open("Image_3.ppm");

    // Copiar do arquivo antigo para a memória
    old_image >> type;
    old_image >> width;
    old_image >> height;
    old_image >> RGB;

    // Copiar da memória para o novo arquivo
    new_image << type << std::endl;
    new_image << width << " " << height << std::endl;
    new_image << RGB << std::endl;

    // Copiar do arquivo antigo para a memória
    std::string red = "";
    std::string green = "";
    std::string blue="";
    int intred = 0;
    int intgreen = 0;
    int intblue = 0;

    //Timer
    auto start_single_thread = std::chrono::high_resolution_clock::now();
    std::cout << "início do processo" << std::endl;

    // Ler cada pixel
    while (!old_image.eof()){

        old_image >> red;
        old_image >> green;
        old_image >> blue;

        // Converter string para números
        intred = std::stoi(red, nullptr);
        intgreen = std::stoi(green, nullptr);
        intblue = std::stoi(blue, nullptr);

        // Filtro azul
        intblue = intblue + 100;

        if (intblue > 249) {
            intblue = 255;
        }

        // Copiar pixels
        new_image << red << " " << green << " " << intblue << std::endl;
    }

    // Parar o timer
    auto stop_single_thread = std::chrono::high_resolution_clock::now();
    std::cout << "Processo finalizado" << std::endl;

    //Salvar tempo de execução
    auto duration_single_thread = std::chrono::duration_cast<std::chrono::milliseconds>(stop_single_thread - start_single_thread);

    //Mostrar tempo de execução
    std::cout << "Tempo de processamento: " << duration_single_thread.count() << " ms" << std::endl;

    new_image.close();
    old_image.close();

    return 0;
}