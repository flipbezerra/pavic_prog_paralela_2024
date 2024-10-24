// Atividade Biblioteca STB para processamento de imagens

#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

// Função para processar a imagem em tons de verde
void processImageGreen(unsigned char* data, int start, int end) {
    for (int i = start; i < end; i += 3) {
        data[i] = 0;           // R = 0
        // G mantém seu valor original
        data[i + 2] = 0;       // B = 0
    }
}

// Função para inverter as cores da imagem
void processImageInvert(unsigned char* data, int start, int end) {
    for (int i = start; i < end; i++) {
        data[i] = 255 - data[i];
    }
}

// Função para processamento multithread
void processSegment(unsigned char* data, int start, int end, bool greenFilter) {
    if (greenFilter) {
        processImageGreen(data, start, end);
    } else {
        processImageInvert(data, start, end);
    }
}

int main() {
    int width, height, channels;
    
    // Carregar a imagem
    unsigned char* image = stbi_load("apple.jpg", &width, &height, &channels, 0);
    if (image == nullptr) {
        std::cout << "Erro ao carregar a imagem!" << std::endl;
        return -1;
    }
    
    std::cout << "Imagem carregada: " << width << "x" << height << " com " << channels << " canais" << std::endl;
    
    // Criar cópia para processamento sequencial e paralelo
    int imageSize = width * height * channels;
    unsigned char* imageSeq = new unsigned char[imageSize];
    unsigned char* imagePar = new unsigned char[imageSize];
    std::memcpy(imageSeq, image, imageSize);
    std::memcpy(imagePar, image, imageSize);
    
    // 1. Processamento Sequencial
    auto start = std::chrono::high_resolution_clock::now();
    
    // Aplicar filtro verde
    processImageGreen(imageSeq, 0, imageSize);
    
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Tempo de processamento sequencial: " << duration.count() << "ms" << std::endl;
    
    // Salvar resultado sequencial
    stbi_write_jpg("output_sequential.jpg", width, height, channels, imageSeq, 100);
    
    // 2. Processamento Multithread
    start = std::chrono::high_resolution_clock::now();
    
    // Definir número de threads
    const int numThreads = std::thread::hardware_concurrency();
    std::vector<std::thread> threads;
    int segmentSize = imageSize / numThreads;
    
    // Criar e executar threads
    for (int i = 0; i < numThreads; i++) {
        int segStart = i * segmentSize;
        int segEnd = (i == numThreads - 1) ? imageSize : (i + 1) * segmentSize;
        threads.emplace_back(processSegment, imagePar, segStart, segEnd, true);
    }
    
    // Aguardar todas as threads terminarem
    for (auto& thread : threads) {
        thread.join();
    }
    
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Tempo de processamento paralelo: " << duration.count() << "ms" << std::endl;
    
    // Salvar resultado paralelo
    stbi_write_jpg("output_parallel.jpg", width, height, channels, imagePar, 100);
    
    // Liberar memória
    stbi_image_free(image);
    delete[] imageSeq;
    delete[] imagePar;
    
    return 0;
}