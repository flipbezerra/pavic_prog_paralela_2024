// Aula 03 PAVIC Progrmação Paralela 2024

#include <iostream> // Entrada e saida de dados
#include <fstream> // Ler e escrever imagens
#include <chrono>   // para cronometrar o tempo de execução

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");

    std::ofstream image;
    image.open("Image_2.ppm");
    // PPM Image Header
    image << "P3" << std::endl;
    image << "250 250" << std::endl;
    image << "255" << std::endl;

    //Timer
    auto start_single_thread = std::chrono::high_resolution_clock::now();
    std::cout << "início do processo" << std::endl;

    // PPM Image Body
    for (int y = 0; y < 250; y++) {
        for (int x = 0; x < 250; x++) {
            // Pixel RGB (0->> 255) 8 bits
            // image << "R" << " " << "G" << " " << "B" << std::endl;
            image << y << " " << 255 << " " << x << std::endl;
            
        }
    }
    // Parar o timer
    auto stop_single_thread = std::chrono::high_resolution_clock::now();
    std::cout << "Processo finalizado" << std::endl;

    //Salvar tempo de execução
    auto duration_single_thread = std::chrono::duration_cast<std::chrono::milliseconds>(stop_single_thread - start_single_thread);

    //Mostrar tempo de execução
    std::cout << "Tempo de processamento: " << duration_single_thread.count() << " ms" << std::endl;

    image.close();

    return 0;
}