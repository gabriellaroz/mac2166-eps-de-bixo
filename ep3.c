
/* dificil pra caralho e tirei 7.5 */
    
#include <stdio.h>

#define NUM 0
#define CONT 1
#define COLS 2

int gMACtria(char c){
    int numero = 0;

    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')){
        if (c >= 'a'){
            c -= 'a' - 'A';
        }
        if (c <= 'I'){
            numero = c - 'A' + 1;
        }
        else if (c <= 'R') {
            numero = (c - 'J' + 1) * 10;
        }
        else{
            numero = (c - 'S' + 1) * 100;
        }
    }
    return numero;
}

int SomaCaracteres(char *palavra){
    int soma = 0;
    int i = 0;

    while (palavra[i] != '\0'){
        soma += gMACtria(palavra[i]);
        i++;
    }
    return soma;
}

int Numetrica(char texto[], int seqnum[]){
    int tamanho = 0;
    int i;
    int soma = 0;

    for (i = 0; texto[i] != '\0'; i++){
        seqnum[tamanho] = gMACtria(texto[i]);
        tamanho++;
    }
    return tamanho;
}

int main(){
    char c;
    int f;
    int resultadoF1;
    int resultadoF2;
    int repetir = 1;
    char linha[1000];
    int seqnum[1000];
    int tamanho;
    int i;

    while (repetir){
        printf("Selecione a funcionalidade f do programa (1-7): ");
        scanf("%d", &f);

        if (f == 1){
            printf("Digite um caractere: ");
            scanf(" %c", &c);
            resultadoF1 = gMACtria(c);
            printf("A gMACtria de '%c' eh %d\n", c, resultadoF1);
        }
        else if (f == 2){
            char palavra[100];
            printf("Digite uma palavra: ");
            scanf("%s", palavra);
            resultadoF2 = SomaCaracteres(palavra);
            printf("A numetria de '%s' eh %d\n", palavra, resultadoF2);
        }
        else if (f == 3){

            printf("Digite um texto com ateh 1000 letras: ");
            scanf(" %[^\n]", linha);

            tamanho = Numetrica(linha, seqnum);

            printf("Sequencia numetrica com codigos das'%s' palavras:\n", linha);
            for(i = 0; i < tamanho; i++){
                printf("%d ", seqnum[i]);
            }
            printf("\n");
        }
        else {
            printf("Tchau\n");
            repetir = 0;
        }
    }
    return 0;
}
