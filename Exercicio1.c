# include <stdio.h>
# include <stdlib.h>


float *CriaVetorAleatorio(int tamanho){
    /*Função que cria um vetor, de tamanho [tamanho] com valores aleatórios para testar 
    as funcionalidades do programa*/

    int i;
    static float faturamento_diario[1000];

    for (i = 0; i < tamanho; i++){
        if(i%7 == 0){
            faturamento_diario[i] = 0;
            i++;
            faturamento_diario[i] = 0;
        }
        else faturamento_diario[i] = rand() % 50;
    }
    return faturamento_diario;
}

int Comparar (const void * a, const void * b){
    /*Função utilizada pelo qsort (quick sort) para comparação dos valores 
    na lista do faturamento*/

    if(*(float*)a < *(float*)b) return -1;
    if(*(float*)a == *(float*)b) return 0;
    if(*(float*)a > *(float*)b) return 1;
}

int BuscaZero(float *vetor, int length){
    /*Função retorna a posição do primeiro elemento,  no vetor passado como
    parâmetro, que não é zero. Esta função auxilia a busca dos días úteis.*/

    int i;
    for (i = 0; i < length - 1; i++){
        if(*(vetor+i) > 0) break;
    }
    return i;
}

int Media(float *vetor, int finaisDeSemana, int diasDoAno){
    /*Função responsável por calcular a média de um vetor no intervalo de
    posições entre {finaisDeSemana} e {diasDoAno}, passadas como parâmetro.*/

    int i;
    float media = 0;

    for(i = finaisDeSemana; i < diasDoAno; i++){
        media = media + *(vetor+i);
    }
    return media/(diasDoAno-finaisDeSemana);
}

int ComparaMedia(float *vetor, int mediaAnual, int diasDoAno, int finaisDeSemana){
    /*Função calcula em quantos dias do ano o faturamento diário foi maior do que a média dos
    faturamentos.*/

    int i, cont;

    cont = 0;
    
    for (i = diasDoAno; i > finaisDeSemana; i--){
        if(*(vetor + i) > mediaAnual){
            cont++;
        }
    }
    return cont;
}

int main(){
    /*Função principal que desencadeia as operações de:
    - Criar um vetor com valores aleatórios;
    - Ordenar o vetor de faturamentos;
    - Calcular a média dos valores do vetor;
    - Calcular em quantos dias do ano o faturamento diário foi maior 
      do que o faturamento anual*/

    int dias,i, finaisDeSemana, diasAcimaMedia;
    float *faturamento_diario, media;

    dias = 365;

    faturamento_diario = CriaVetorAleatorio(dias);
    qsort(faturamento_diario, dias, sizeof(float), Comparar);
    finaisDeSemana = BuscaZero(faturamento_diario, dias);
    media = Media(faturamento_diario, finaisDeSemana, dias);
    diasAcimaMedia = ComparaMedia(faturamento_diario, media, dias, finaisDeSemana);

    printf("\nMenor faturamento do ano: %.2f\n", *(faturamento_diario + finaisDeSemana));
    printf("Maior faturamento do ano: %.2f\n", *(faturamento_diario + dias - 1));
    printf("Média anual: %.2f\n", media);
    printf("Dias acima da média: %d\n", diasAcimaMedia);

    return 0;
}