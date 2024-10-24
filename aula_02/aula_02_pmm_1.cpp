// Aula 02 PAVIC Progrmação Paralela 2024

#include <iostream> // Entrada e saida de dados
#include <fstream> // Ler e escrever imagens

int main() {

    std::ofstream image;
    image.open("Image.ppm");
    // Image PPM Header
    image << "P3" << std::endl;
    image << "3 2" << std::endl;
    image << "255" << std::endl;
    // Image PPM Body
    image << "255 0 0" << std::endl; //Red
    image << "0 255 0" << std::endl; //Green
    image << "0 0 255" << std::endl; //Blue
    image << "255 255 255" << std::endl; //White
    image << "0 0 0" << std::endl; //Black

    image.close();

    return 0;
}