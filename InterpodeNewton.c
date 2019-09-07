 #include <stdio.h>
#include <stdlib.h>


     //Polinômio Interpolador de Newton
    / 

float newton(int n, float x[], float y[], float xi);

int main(){
    int n, i, j, p;
    float y[n];
    float x[n];
    float b[20][20];
    float xi, xt, yi;



    printf("Quantos  intervalos?: ");
    scanf("%d", &n);

    printf("\n");

    for(i= 0; i<n; i++){
        printf("Digite o x%d: ", i+1);
        scanf(" %f", &x[i]);
        printf("\n");
        printf("Digite o y%d: ", i+1);
        scanf(" %f", &y[i]);
        printf("\n");
    }

    //inicializa a tabela de diferencas
        for(i = 0; i<n; i++){
               b[i][0] = y[i];
        }

    //calcula a tabela de diferenças
        for(j = 1; j<n; j++){
            for(i =0; i<n-j; i++){
                b[i][j] = (b[i+1][j-1]-b[i][j-1])/(x[i+j]-x[i]);
            }
        }

 	/*//imprime o polinomio
 	  printf("f(x): [ ");

        for(j = 1; j<n; j++){
            for(i =0; i<n; i++){
                printf("%.f ", b[i][j]);
            }

        }
        printf(" ]\n");
        printf("------------------------ \n");
    */

    printf("Digite a quantidade de x's': ");
    scanf("%d", &p );

    for(i = 0; i < p; i++){
	    printf("------------------------ \n");
	    printf("\nDigite o valor de x: ");
	    scanf(" %f", &xi);

	    //interpola com o polinomio
	    xt = 1;
        yi = b[0][0];



        for(j=0; j<n-1;j++){
            xt=xt*(xi-x[j]);
            yi= yi+b[0][j+1]*xt;


        }


	    printf("\n::Valor interpolado:  %.2f::", yi);

		printf("\n");

    }


    return 0;
}

