/* fiz com vontade e tirei 10, coloquei ate def pra cada termo kkkk */

#include <stdio.h>

double potencia(double base, double expoente){
    double potencia = 1;
    int i;

    for (i = 0; i < expoente; i++) {
        potencia *= base;
    }
    return potencia;
}

double Log2(double z, double eps){
    double lnZ = 0;
    double ln2 = 0.6931471805599453;
    double Log2;
    double parcela = (z - 1) / (z + 1);
    double valor = 1;
    double n = 1;

    while ((valor >= 0 && valor > eps) || (valor < 0 && -valor > eps)){
        lnZ += 2 * potencia(parcela, n) / n;
        Log2 = lnZ / ln2;
        valor = potencia(parcela, n);
        n += 2;
    }
    return Log2;
}

double InformacaoMutua(int N11, int N10, int N01, int N00, double eps){
    double N = N11 + N10 + N01 + N00;
    double x, y, conj1, conj2, conj3, conj4, parcela01, parcela02, parcela03, parcela04, somatoria;

    x = (N11 + N10) / N; /* xy = 11 */
    y = (N11 + N01) / N;
    conj1 = N11 / N;
    parcela01 = conj1 * Log2(conj1 / (x * y), eps);

    x = (N10 + N11) / N; /* xy = 10 */
    y = (N10 + N00) / N;
    conj2 = N10 / N;
    parcela02 = conj2 * Log2(conj2 / (x * y), eps);

    x = (N01 + N00) / N; /* xy = 01 */
    y = (N01 + N11) / N;
    conj3 = N01 / N;
    parcela03 = conj3 * Log2(conj3 / (x * y), eps);

    x = (N00 + N01) / N; /* xy = 00 */
    y = (N00 + N10) / N;
    conj4 = N00 / N;
    parcela04 = conj4 * Log2(conj4 / (x * y), eps);

    somatoria = parcela01 + parcela02 + parcela03 + parcela04;

    return somatoria;
}

int main(){
    double z, eps, resultado, N11, N10, N01, N00, resultado2;
    int f;

    printf("Selecione a funcionalidade f do programa (1 ou 2): ");
    scanf("%d", &f);

    if (f == 1){
        printf("Entre com x e eps: \n");
        scanf("%lf %lf", &z, &eps);

        resultado = Log2(z, eps);
        printf("O logaritmo de %g com precisao %g eh %g\n", z, eps, resultado);
    }
    else if (f == 2){
        printf("Entre com contadores N11, N10, N01, N00 e com eps: ");
        scanf("%lf %lf %lf %lf %lf", &N11, &N10, &N01, &N00, &eps);
        resultado2 = InformacaoMutua(N11, N10, N01, N00, eps);
        printf("A informacao mutua entre as duas variaveis aleatorias eh %g\n", resultado2);
    }
    return 0;
}
