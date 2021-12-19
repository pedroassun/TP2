#include <iostream>
#include <windows.h>
#include "pilha.cpp" 

using namespace std;

int main() {
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    TPilha pilha;
    Pedido pi;
    TPilha_Inicializa(&pilha);
    
    Menu(&pi, &pilha);
    
    return 0;
}