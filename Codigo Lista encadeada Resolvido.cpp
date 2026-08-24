#include <iostream>
using namespace std;

struct No {
    int valor;
    float quantidade;
    No* proximo;
};

class ListaEncadeada {
private:
    No* inicio;

public:
    ListaEncadeada() {
        inicio = nullptr;
    }

    void inserirFim(int val, float qtd) {
        No* novo = new No;
        novo->valor = val;
        novo->quantidade = qtd;
        novo->proximo = nullptr;

        if (inicio == nullptr) {
            inicio = novo;
        } else {
            No* temp = inicio;
            while (temp->proximo != nullptr) {
                temp = temp->proximo;
            }
            temp->proximo = novo;
        }
    }

    void imprimir() {
        No* temp = inicio;
        cout << "Lista: ";

        while (temp != nullptr) {
            cout << temp->valor << " ";
            temp = temp->proximo;
        }

        cout << endl;
    }

    bool buscar(int val) {
        No* temp = inicio;

        while (temp != nullptr) {
            if (temp->valor == val)
                return true;

            temp = temp->proximo;
        }

        return false;
    }

    ~ListaEncadeada() {
        No* temp;

        while (inicio != nullptr) {
            temp = inicio;
            inicio = inicio->proximo;
            delete temp;
        }
    }
};

int main() {
    ListaEncadeada lista;
    int opcao, valor;
    float quantidade;

    do {
        cout << "\n1. Inserir elemento\n";
        cout << "2. Buscar elemento\n";
        cout << "3. Mostrar lista\n";
        cout << "0. Sair\n";
        cout << "Escolha: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Valor a inserir: ";
                cin >> valor;

                cout << "Quantidade: ";
                cin >> quantidade;

                lista.inserirFim(valor, quantidade);
                break;

            case 2:
                cout << "Valor a buscar: ";
                cin >> valor;

                if (lista.buscar(valor))
                    cout << "Valor encontrado na lista.\n";
                else
                    cout << "Valor NÃO encontrado.\n";

                break;

            case 3:
                lista.imprimir();
                break;

            case 0:
                cout << "Encerrando...\n";
                break;

            default:
                cout << "Opção inválida!\n";
        }

    } while (opcao != 0);

    return 0;
}

