// Aula 04 PAVIC Progrmação Paralela 2024

#include<iostream>  // Entrada e saida de dados
#include<thread>    // Cria threads

using namespace std;

void Task_1(){ 
    cout << "Hello From Thread A!!" << endl;

}

void Task_2(){ 
    cout << "Hello From Thread B!!" << endl;

}


void Task_3(){ 
    cout << "Hello From Thread C!!" << endl;

}

int main (){
    // Task principal
    cout << "Hello From Main !!" << endl;
    
    thread Child_A(Task_1); // Cria threads
    thread Child_B(Task_2);
    thread Child_C(Task_3);

    // Retorna as threads
    Child_A.join();
    Child_B.join();
    Child_C.join();

    return 0;
}