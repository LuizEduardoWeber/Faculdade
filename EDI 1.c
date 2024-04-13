#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_EQUIPES 2
#define NUM_PROJETOS_LEITOR 1
#define NUM_PROJETOS_LIVRO 1
#define NUM_PROJETOS_EVENTO 1

int main() {
    int equipes[NUM_EQUIPES][NUM_PROJETOS_LEITOR + NUM_PROJETOS_LIVRO + NUM_PROJETOS_EVENTO] = {0};
    int projetos[NUM_PROJETOS_LEITOR + NUM_PROJETOS_LIVRO + NUM_PROJETOS_EVENTO] = {0};
    int tempo_total[NUM_PROJETOS_LEITOR + NUM_PROJETOS_LIVRO + NUM_PROJETOS_EVENTO] = {0};
    int tarefas_por_equipe[NUM_EQUIPES] = {0}; 
    char novo_lancamento[10]; 

    while (1) {
        int equipe, projeto, tempo;

        printf("Equipe 1: Programação e Desenvolvimento\n");
        printf("Equipe 2: Design\n");

        printf("Qual a equipe que realizou a tarefa? (1-%d) ", NUM_EQUIPES);
        scanf("%d", &equipe);
        
        if (equipe == 1)
            printf("Equipe escolhida: Programação e Desenvolvimento\n");
        else if (equipe == 2)
            printf("Equipe escolhida: Design\n");
        else {
            printf("Opção de equipe inválida!\n");
            continue; 
        }

        printf("\nProjeto 1: Livros Digitais Para Crianças\n");
        printf("Projeto 2: Leitor de Textos Para Deficientes Visuais\n");
        printf("Projeto 3: Sistema de Registro de Participação em Eventos Culturais\n");

        printf("Qual o projeto que foi trabalhado? (1-%d) ", NUM_PROJETOS_LEITOR + NUM_PROJETOS_LIVRO + NUM_PROJETOS_EVENTO);
        scanf("%d", &projeto);

        if (projeto == 1)
            printf("Projeto escolhido: Livros Digitais Para Crianças\n");
        else if (projeto == 2)
            printf("Projeto escolhido: Leitor de Textos Para Deficientes Visuais\n");
        else if (projeto == 3)
            printf("Projeto escolhido: Sistema de Registro de Participação em Eventos Culturais\n");
        else {
            printf("Opção de projeto inválida!\n");
            continue; 
        }

        printf("\nQuanto tempo (em minutos) demorou para a tarefa ser executada? ");
        scanf("%d", &tempo);

        equipes[equipe - 1][projeto - 1] += tempo; 
        projetos[projeto - 1]++;
        tempo_total[projeto - 1] += tempo;

        tarefas_por_equipe[equipe - 1]++;

        printf("\nDeseja fazer um novo lançamento? (sim/não) ");
        scanf("%s", novo_lancamento); 

        if (strcmp(novo_lancamento, "não") == 0) { 
            break;
        } else if (strcmp(novo_lancamento, "sim") != 0) {
            printf("Resposta inválida! Por favor, responda 'sim' ou 'não'.\n");
            continue;
        }
    }

    printf("\nEstatísticas por equipe:\n");
    for (int i = 0; i < NUM_EQUIPES; i++) {
        printf("\nEquipe %d:\n", i + 1);
        int soma = 0;
        for (int j = 0; j < NUM_PROJETOS_LEITOR + NUM_PROJETOS_LIVRO + NUM_PROJETOS_EVENTO; j++) {
            soma += equipes[i][j];
        }
        printf("  Quantas tarefas foram realizadas: %d\n", tarefas_por_equipe[i]); 
        printf("  Tempo gasto total pela equipe: %d minutos\n", soma);
        if (soma != 0) { 
            for (int j = 0; j < NUM_PROJETOS_LEITOR + NUM_PROJETOS_LIVRO + NUM_PROJETOS_EVENTO; j++) { 
            printf("  Percentual de tarefas realizadas para o projeto %d: %.0f%%\n", j + 1, (float)equipes[i][j] / soma * 100);
            }
        } else {
            printf("  Nenhum tempo gasto nesta equipe.\n");
        }
    }

    printf("\nEstatísticas por projeto:\n");
    for (int i = 0; i < NUM_PROJETOS_LEITOR + NUM_PROJETOS_LIVRO + NUM_PROJETOS_EVENTO; i++) {
        printf("\nProjeto %d:\n", i + 1); 
        printf("  Quantas tarefas foram realizadas: %d\n", projetos[i]);
        printf("  Tempo gasto médio por tarefa: %.0f minutos\n", projetos[i] != 0 ? (float)tempo_total[i] / projetos[i] : 0); 
    }

 return 0;
}
