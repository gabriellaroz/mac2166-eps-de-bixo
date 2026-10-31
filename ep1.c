

/* 5 de nota nesse aqui pqp */
#include <stdio.h>

int main(){
   int f = 0; /*f = opcao*/
   int n, i, k;
   int primo = 1; /*1 = primo e 0 = n eh primo*/
   int proximo = 0;
   int atual = 0;
   int numero = 0;
   int digitos = 0;
   int produto = 0;
   int num1 = 0;
   int num2 = 0;


   printf("Selecione a funcionalidade f do programa (0, 1, 2 ou 3):\n");
   scanf("%d", &f);

   if(f == 0){
      printf("Entre com um numero a testar se eh primo: ");
      scanf("%d", &n);

      for(i = 2; i < n; i++){ /* i++ -> i = i+1 */
         if(n%i == 0){
            primo = 0;
         }
      }

      if (primo == 0){
         printf("O numero %d nao eh primo", n);
      }
      else{
         printf("O numero %d eh primo", n);
      }
   }

   if(f == 1){
      printf("Entre com n e k: \n");
      scanf("%d %d", &n, &k);

      if(k > 0){ /* prox. k numeros primos maiores que n */
         for(atual = n+1; atual < 2147483647 && proximo < k; atual++){
            primo = 1;
            for(i = 2; i < atual && primo == 1; i++){ /* ver se atual eh primo */
               if(atual%i == 0){
                  primo = 0;
               }
            }

            if(primo == 1){
               proximo++;
            }
         }

         if(atual == 2147483647){
           printf("Nao existe(m) %d primo(s) entre %d e 2147483647", k, n);
         }
         else{
            numero = atual;
            while(numero > 0){
               digitos++;
               numero = numero/10;
            }

            printf("O %d-esimo primo maior que %d eh %d e possui %d digito(s)", k, n, atual-1, digitos);
            }
      }

      if(k < 0){ /* k numeros primos menores que n */
         for(atual = n-1; 0 < atual && proximo < -k; atual--){
            primo = 1;
            for(i = 2; i < atual && primo == 1; i++){ /* ver se atual eh primo */
               if(atual%i == 0){
                  primo = 0;
               }
            }

            if(primo == 1){
               proximo++;
            }
         }

         if(atual == 0){
            printf("Nao existe(m) %d primo(s) entre 0 e %d", -k, n);
         }
         else{
            numero = atual;
            while(numero > 0){
               digitos++;
               numero = numero/10;
            }

            printf("O %d-esimo primo menor que %d eh %d e possui %d digito(s)", -k, n, atual+1, digitos);
         }
      }

   }
         else if(f == 2){ /*SO PRA N PERDER*/
                printf("Entre com n e k: "); /*1*/
      scanf("%d %d", &n, &k);

      if(k > 0){ /* prox. k numeros primos maiores que n */
         for(atual = n+1; atual < 2147483647 && proximo < k; atual++){
            primo = 1;
            for(i = 2; i < atual && primo == 1; i++){ /* ver se atual eh primo */
               if(atual%i == 0){
                  primo = 0;
               }
            }

            if(primo == 1){
               proximo++;
            }
         }

         if(atual == 2147483647){
            printf("Nao existem %d primos entre %d e 2147483647\n", k, n);
         }
         else{
            numero = atual;
            while(numero > 0){
               digitos++;
               numero = numero/10;
            }

            printf("O %d-esimo primo maior que %d eh %d e possui %d digito(s)\n", k, n, atual-1, digitos);
            num1 = atual-1;
            }
      }

      if(k < 0){ /* k numeros primos menores que n */
         for(atual = n-1; 0 < atual && proximo < -k; atual--){
            primo = 1;
            for(i = 2; i < atual && primo == 1; i++){ /* ver se atual eh primo */
               if(atual%i == 0){
                  primo = 0;
               }
            }

            if(primo == 1){
               proximo++;
            }
         }

         if(atual == 0){
            printf("Nao existem %d primos entre 0 e %d\n", -k, n);
         }
         else{
            numero = atual;
            while(numero > 0){
               digitos++;
               numero = numero/10;
            }

            printf("O %d-esimo primo menor que %d eh %d e possui %d digito(s)\n", -k, n, atual+1, digitos);
            num1 = atual+1;
         }
      }

   printf("Entre com n e k: "); /*2*/
      scanf("%d %d", &n, &k);
      proximo = 0;

      if(k > 0){ /* prox. k numeros primos maiores que n */
         for(atual = n+1; atual < 2147483647 && proximo < k; atual++){
            primo = 1;
            for(i = 2; i < atual && primo == 1; i++){ /* ver se atual eh primo */
               if(atual%i == 0){
                  primo = 0;
               }
            }

            if(primo == 1){
               proximo++;
            }
         }

         if(atual >= 2147483647 || atual < 0){
            printf("Nao existem %d primos entre %d e 2147483647\n", k, n);
         }
          else{
            numero = atual-1;
            digitos = 0;
            while(numero > 0){
               digitos++;
               numero = numero/10;
            }

            printf("O %d-esimo primo maior que %d eh %d e possui %d digito(s)\n", k, n, atual-1, digitos);
            num2 = atual-1;
            }
      }

      if(k < 0){ /* k numeros primos menores que n */
         for(atual = n-1; 0 < atual && proximo < -k; atual--){
            primo = 1;
            for(i = 2; i < atual && primo == 1; i++){ /* ver se atual eh primo */
               if(atual%i == 0){
                  primo = 0;
               }
            }

            if(primo == 1){
               proximo++;
            }
         }

         if(atual == 0){
            printf("Nao existem %d primos entre 0 e %d\n", -k, n);
         }
         else{
            numero = atual+1;
            digitos = 0;
            while(numero > 0){
               digitos++;
               numero = numero/10;

            }
            printf("O %d-esimo primo menor que %d eh %d e possui %d digito(s)\n", -k, n, atual+1, digitos);
            num2 = atual+1;

         }
      }

      if(num1 > 0 && num2 > 0){
       produto = num1 * num2;

       if(2147483647/num1 < num2){
        printf("O produto dos dois primos eh maior que 2147483647");
       }
       else{
            numero = produto;
            digitos = 0;
            while(numero > 0){
               digitos++;
               numero = numero/10;
        }
        printf("O produto dos dois primos eh %d e possui %d digito(s)", produto, digitos);
       }

      }

         }

 return 0;
   }
