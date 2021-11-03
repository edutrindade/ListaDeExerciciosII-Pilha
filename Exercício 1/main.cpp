#include <iostream>
#include <windows.h>
#include "Pilha.cpp"
 
using namespace std;

int maiorElemento(TipoPilha *pilha, TipoItem item);
 
int main() {
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls");

    TipoItem item;
    TipoPilha pilha;
    
    int retorno;

    FazPilhaVazia(&pilha);

    item.id = 30;
    Empilha(&pilha, item);

    item.id = 50;
    Empilha(&pilha, item);
    
    item.id = 60;
    Empilha(&pilha, item);
    
    item.id = 10;
    Empilha(&pilha, item);
    
    item.id = 20;
    Empilha(&pilha, item);
    
    item.id = 34;
    Empilha(&pilha, item);
    
    item.id = 45;
    Empilha(&pilha, item);

    ExibePilha(&pilha);

    retorno = maiorElemento(&pilha, item);

    cout << "\nMaior valor da Pilha: " << retorno;

    return 0;
}

int maiorElemento(TipoPilha *pilha, TipoItem item) {
    int maior, aux;
    maior = item.id;
    
    while (!VerificaPilhaVazia(pilha)) {
        aux = item.id;
        Desempilha(pilha, &item);
        if (aux >= maior) {
            maior = aux;
        }
    }

    return maior;
}