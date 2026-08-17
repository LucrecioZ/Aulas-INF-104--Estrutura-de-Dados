#include <iostream>
using namespace std;

void inserir(int vetor[], int &tamanho, int valor) {
    vetor[tamanho] = valor;
    tamanho++;
}

void exibir(int vetor[], int tamanho) {

    for (int i = 0; i < tamanho; i++) {
        cout << vetor[i] << " ";
    }

    cout << endl;
}

int buscar(int vetor[], int tamanho, int valor) {

    for (int i = 0; i < tamanho; i++) {

        if (vetor[i] == valor)
            return i;
    }

    return -1;
}

bool remover(int vetor[], int &tamanho, int posicao) {

    if (posicao < 0 || posicao >= tamanho)
        return false;

    for (int i = posicao; i < tamanho - 1; i++) {
        vetor[i] = vetor[i + 1];
    }

    tamanho--;

    return true;
}

int maior(int vetor[], int tamanho) {

    int m = vetor[0];

    for (int i = 1; i < tamanho; i++) {
        if (vetor[i] > m)
            m = vetor[i];
    }

    return m;
}

int soma(int vetor[], int tamanho) {

    int total = 0;

    for (int i = 0; i < tamanho; i++)
        total += vetor[i];

    return total;
}

int main() {

    int vetor[100];
    int tamanho = 0;

    inserir(vetor, tamanho, 10);
    inserir(vetor, tamanho, 20);
    inserir(vetor, tamanho, 30);
    inserir(vetor, tamanho, 40);
    inserir(vetor, tamanho, 17);
    inserir(vetor, tamanho, 8);
    inserir(vetor, tamanho, 26);
    

    cout << "Vetor: ";
    exibir(vetor, tamanho);

    cout << "Maior: "
         << maior(vetor, tamanho) << endl;

    cout << "Soma: "
         << soma(vetor, tamanho) << endl;

    int posicao = buscar(vetor, tamanho, 8);

    cout << "08 está na posição: "
         << posicao << endl;

    remover(vetor, tamanho, 1);

    cout << "Após remoção: ";
    exibir(vetor, tamanho);

    return 0;
}