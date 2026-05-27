# Sistema de Notas v4.0

Este é um programa em **C++** desenvolvido para o gerenciamento de notas escolares de alunos. Ele permite a criação de um novo relatório de desempenho (com cálculo de médias e classificação de status do aluno) ou a leitura de um relatório gerado anteriormente e salvo em um arquivo de texto.

## 🚀 Funcionalidades

- **Menu Inicial:** Escolha entre iniciar um novo relatório ou abrir um relatório salvo anteriormente.
- **Cadastro de Alunos:** Suporta o cadastro de 1 a 20 alunos.
- **Cadastro de Disciplinas e Notas:** Suporta a inserção de notas (0 a 10) para 1 a 5 disciplinas por aluno.
- **Cálculo Automático:** Calcula a média de cada aluno de acordo com o número de disciplinas inseridas.
- **Classificação de Status:**
  - 🟢 **Aprovado:** Média igual ou superior a 7.0.
  - 🟡 **Recuperação:** Média menor ou igual a 5.0.
  - 🔴 **Reprovado:** Médias intermediárias (entre 5.1 e 6.9).
- **Persistência de Dados:** Salva automaticamente o relatório final e um resumo estatístico em um arquivo chamado `relatorio.txt`.
- **Compatibilidade de Caracteres:** Configurado para exibir caracteres especiais e acentuação corretamente no terminal Windows (UTF-8).

## 📁 Estrutura de Commits (Histórico de Desenvolvimento)

O desenvolvimento deste código seguiu uma abordagem incremental dividida em etapas mapeadas nos comentários:
1. **Commit 1:** Implementação da leitura inicial e cadastro dos nomes dos alunos.
2. **Commit 2:** Adição do fluxo de leitura de notas por disciplinas e cálculo das médias.
3. **Commit 3:** Implementação do relatório de classificação (Aprovado/Recuperação/Reprovado) e resumo estatístico.
4. **Commit 4:** Integração do sistema de persistência para exportar dados no arquivo `relatorio.txt`.
5. **Commit 5:** Criação da opção de leitura e exibição no terminal de relatórios previamente salvos.

## 🛠️ Pré-requisitos e Como Executar

### Pré-requisitos
Como o programa utiliza a biblioteca `<windows.h>` para configurar o encoding do console (`SetConsoleOutputCP(65001)`), ele foi projetado nativamente para ambientes **Windows**. Você precisará de um compilador C++ (como o `g++` do MinGW) instalado no seu sistema.

### Passo a Passo

1. **Clone o repositório:**
   ```bash
   git clone [https://github.com/seu-usuario/seu-repositorio.git](https://github.com/seu-usuario/seu-repositorio.git)
   cd seu-repositorio