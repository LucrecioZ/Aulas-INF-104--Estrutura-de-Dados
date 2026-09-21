//INCLUA EM CADA CODIGO UM MENU QUE PERGUNTE AO USUARIO, QUAL A OPÇÃO ESCOLHIDA
// 1- Inserir elemento
// 2- Remover elemento
// 3- Consultar topo

#include <iostream>

using namespace std;

#define CAPACIDADE 5

class Pilha {
private:
    int elementos[CAPACIDADE];
    int topo;

public:

    // Construtor
    Pilha() {
        topo = -1;
    }

    // Inserir elemento
    bool push(int valor) {

        if (topo == CAPACIDADE - 1) {
            cout << "Erro: pilha cheia!" << endl;
            return false;
        }

        topo++;
        elementos[topo] = valor;

        return true;
    }

    // Remover elemento
    int pop() {

        if (topo == -1) {
            cout << "Erro: pilha vazia!" << endl;
            return -1;
        }

        int valor = elementos[topo];

        topo--;

        return valor;
    }

    // Consultar topo
    int top() {

        if (topo == -1) {
            cout << "Pilha vazia!" << endl;
            return -1;
        }

        return elementos[topo];
    }

    // Verificar se está vazia
    bool empty() {
        return topo == -1;
    }

    // Verificar se está cheia
    bool full() {
        return topo == CAPACIDADE - 1;
    }
};


int main() {

    Pilha pilha;
    int opcao;
    int valor;

    do {
        cout << "1- Inserir elemento" << endl;
        cout << "2- Remover elemento" << endl;
        cout << "3- Consultar topo" << endl;
        cout << "0- Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Digite o valor a ser inserido: ";
                cin >> valor;
                pilha.push(valor);
                break;
            case 2:
                cout << "Removido: " << pilha.pop() << endl;
                break;
            case 3:
                cout << "Topo: " << pilha.top() << endl;
                break;
            case 0:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opção inválida!" << endl;
        }
    } while (opcao != 0);

    cout << "Novo topo: "
         << pilha.top() << endl;

    return 0;
}