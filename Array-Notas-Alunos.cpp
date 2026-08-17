#include <iostream>

using namespace std;

int main() {

    const int TAMANHO = 15;

    float notas[TAMANHO];

    float soma = 0;
    float maior;
    float menor;

    // Leitura das notas
    for (int i = 0; i < TAMANHO; i++) {

        cout << "Digite a nota do aluno "
             << i + 1 << ": ";

        cin >> notas[i];
    }

    // Inicializa maior e menor
    maior = notas[0];
    menor = notas[0];

    // Processa as notas
    for (int i = 0; i < TAMANHO; i++) {

        soma += notas[i];

        if (notas[i] > maior) {
            maior = notas[i];
        }

        if (notas[i] < menor) {
            menor = notas[i];
        }
    }

    float media = soma / TAMANHO;

    // Conta aprovados
    int aprovados = 0;
    int reprovados = 0;

    for (int i = 0; i < TAMANHO; i++) {

        if (notas[i] >= 60) {
            aprovados++;
        } 
        
        if (notas[i] <= 59) {
            reprovados++;
        }
    }

    // Exibe resultados
    cout << "\n===== RESULTADO =====\n";

    cout << "Notas:\n";

    for (int i = 0; i < TAMANHO; i++) {

        cout << "Aluno " << i + 1
             << ": "
             << notas[i]
             << endl;
    }

    cout << "\nMedia: "
         << media << endl;

    cout << "Maior nota: "
         << maior << endl;

    cout << "Menor nota: "
         << menor << endl;

    cout << "Alunos aprovados: "
         << aprovados << endl;
         
    cout << "Alunos reprovados: "
         << reprovados << endl;

    return 0;
}