// Aula 05 PAVIC Progrmação Paralela 2024

#include <iostream> // Entrada e saida de dados
#include <thread>   // Cria threads
#include <mutex>    // Manipulação de threads
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void print_hello_1(int ID) {
    std::unique_lock<std::mutex> lock(mtx);
    std::cout << "Hello from thread!" << ID << std::endl;
    lock.unlock();
}


void print_hello_2() {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [] { return ready; });
    std::cout << "Hello from thread!" << std::endl;
}

int main() {
    std::thread t(print_hello_2);
    {
        std::unique_lock<std::mutex> lock(mtx);
        ready = true;
    }
    cv.notify_one();
    t.join();
    return 0;
}