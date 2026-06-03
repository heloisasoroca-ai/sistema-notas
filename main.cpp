#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <ctime>

using namespace std;

int main(){
    SetConsoleOutputCP(65001);

    //Entrada - declaração das variáveis
    string nomes[20];
    int qtdAlunos;
    float notas[20][5];
    float media[20];
    int qtdDisciplinas;
    int opcaoInicial;
    int notaMaior = 0;
    int notaMenor = 0;

    //Processamento 

    //Leitura de alunos (commit 1)
    cout << "=== SISTEMA DE NOTAS v4.1 ===" << endl;
    cout << "1 - Novo Relatório" << endl;
    cout << "2 - Ver relatório salvo" << endl;
    cout << "3 - Sobre o sistema" << endl;
    cout << "4 - Relatório de reprovados" << endl;
    cout << "Escolha um opção: " << endl;
    cin >> opcaoInicial;

    //Leitura de arquivo (commit 5)
    if (opcaoInicial == 2) 
    {
        ifstream leitura("relatorio.txt");
        if(leitura.is_open()){
            string linha;
            cout << "\n";
            while(getline(leitura, linha)){
                cout << linha << endl;
            
            }
            leitura.close();
        } else {
            cout << "Nenhum relatório encontrado." << endl;
        }
        return 0;
    }
    if (opcaoInicial == 3) {
        cout << "==== Sobre ====" << endl;
        cout << "Sistema de Notas v4.1" << endl;
        cout << "Desenvolvido por: Heloisa Gigliott" << endl;
        cout << "Turma: LOPAL 2026 - SENAI-SP" << endl;
    }

    if (opcaoInicial == 4) 
    {
        ifstream leitura("reprovados.txt");
        
        if (leitura.is_open()) {
            string reprovados;
            cout << "\n";
            while (getline(leitura, reprovados)) {
                cout << reprovados << endl;
            }
            leitura.close();
        } else {
            cout << "Nenhum relatório de reprovados encontrado." << endl;
        }
        
        return 0; 
    }

    do 
    {
        cout << "Quantidade de Alunos (1 a 20): ";
        cin >> qtdAlunos;
    } while (qtdAlunos < 1 || qtdAlunos > 20);
    
    cin.ignore();

   for (int i = 0; i < qtdAlunos; i++) {
   
    do {
        cout << "Nome do aluno " << i + 1 << ": ";
        getline(cin, nomes[i]);

       
        if (nomes[i] == "") {
            cout << "O nome nao pode ficar em branco! Tente novamente.\n";
        }

    } while (nomes[i] == "");
   }
    //Notas e médias (commit 2)
    do {
        cout << "\nQuantidade de disciplinas (1 a 5): " << endl;
        cin >> qtdDisciplinas;
    } while (qtdDisciplinas < 1 || qtdDisciplinas > 5);

    for (int i = 0; i  < qtdAlunos; i++){
        cout << "\nNotas de " << nomes[i] << ": " << endl;
        float soma = 0;

        for (int j = 0; j < qtdDisciplinas; j++){
            do {
                cout << "Disciplina " << j + 1 << "(1 a 5): ";
                cin >> notas[i][j];
            } while (notas[i][j] < 0 || notas[i][j] > 10);
            soma += notas[i][j];
        }
        media[i] = soma / qtdDisciplinas;
    }

    //Saída
    cout << "\nAlunos cadastrados: " << endl;
    for (int i = 0; i < qtdAlunos; i++)
    {
        cout << "  " << i + 1 << ". " << nomes[i] << endl;
    }

    //Classificação e relatório (commit 3)
    cout << "\n==== RETLATÓRIO ====" << endl;
    int aprovados = 0, recuperacao = 0, reprovados = 0;

    for (int i = 0; i < qtdAlunos; i++) 
    {
        cout << nomes[i] << "- Média: " << media[i] << "  -  " << endl;
        if (media[i] >= 7)
        {
            cout << "Aprovado" << endl;
            aprovados++;

        } 

        else if ( media[i] >= 5)
        {
            cout << "Recuperação" << endl;
            recuperacao++;
        }

        else 
        {
            cout << "Reprovado" << endl;
            reprovados++;
        }
    }

    cout << "\nResumo: " << aprovados << " aprovados, " << recuperacao << " em recuperação, " << reprovados << " reprovados." << endl;


//Salvar em arquivo (commit 4) 
ofstream arquivo("relatorio.txt");
 

if (arquivo.is_open())
{
     time_t agora = time(0);
char* dataHora = ctime(&agora);
arquivo << "Data do relatorio: " << dataHora << endl;
    arquivo << "====RELATÓRIO====" << endl;

    for (int i = 0; i < qtdAlunos; i++)
    {
        arquivo << nomes[i] << "- Média: " << media[i] << "-";
        if (media[i] >= 7) {

            arquivo << "Aprovado" << endl;
        } else if (media[i] >= 5) {

            arquivo << "Recuperação" << endl;
        } else {

            arquivo << "Reprovado" << endl;
        }
    } 
    arquivo << "\nResumo: " << aprovados << " aprovados, " << recuperacao << " em recuperação, " << reprovados << " reprovados." << endl;

    
for (int i = 1; i < qtdAlunos; i++) {
   
    if (media[i] > media[notaMaior])
    {
        notaMaior = i; 
    } 
    if (media[i] < media[notaMenor]) 
    {
        notaMenor = i;
    }

cout << "Maior media: " << nomes[notaMaior] << " (" << media[notaMaior] << ")" << endl;
cout << "Menor media: " << nomes[notaMenor] << " (" << media[notaMenor] << ")" << endl;
}

    arquivo.close();
    cout << "\nRelatório salvo com sucesso " << endl;
} else {
    cout << "Erro ao criar arquivo." << endl;
}
    

    return 0;
}