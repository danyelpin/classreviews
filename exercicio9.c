#include <stdio.h>
#include <stdlib.h>
#define MAX_ALUNOS 10

struct DadosAl {
    char Nome[30];
    int matricula;
    float media_Final;
};

void ArmazenaDados(struct DadosAl alunosNota) {
    printf("\nMatricula = %d\n", alunosNota.matricula);
    printf("\nNome da Pessoa = %s\n", alunosNota.Nome);
    printf("\nMedia final = %.2f\n", alunosNota.media_Final);
}

int main() {
    struct DadosAl armInfo[MAX_ALUNOS];
    struct DadosAl AlApro[MAX_ALUNOS];
    struct DadosAl AlRepro[MAX_ALUNOS];
    int i, alunos_totais = 0;
    int AlApro_count = 0, AlRepro_count = 0;
    int notaMin = 5;

    while (alunos_totais < MAX_ALUNOS) {
        printf("Insira sua matricula: \n");
        scanf("%d", &armInfo[alunos_totais].matricula);

        printf("Insira seu nome: \n");
        scanf("%s", armInfo[alunos_totais].Nome);//o que varia são os alunos totais por isso eles vao no vetor

        printf("Insira sua media_Final: \n");
        scanf("%f", &armInfo[alunos_totais].media_Final);

        ArmazenaDados(armInfo[alunos_totais]);


        if (armInfo[alunos_totais].media_Final >= notaMin) {
            AlApro[AlApro_count++] = armInfo[alunos_totais];
        } else {
            AlRepro[AlRepro_count++] = armInfo[alunos_totais];
        }

        alunos_totais++;
    }

    printf("\nAlunos aprovados:\n");
    for (i = 0; i < AlApro_count; i++) {
        printf("Nome do aluno: %s e media do aluno: %.2f\n", AlApro[i].Nome, AlApro[i].media_Final);
    }

    printf("\nAlunos reprovados:\n");
    for (i = 0; i < AlRepro_count; i++) {
        printf("Nome do aluno: %s e media do aluno: %.2f\n", AlRepro[i].Nome, AlRepro[i].media_Final);
    }

    return 0;
}
