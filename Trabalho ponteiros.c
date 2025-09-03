#include <stdio.h>

int main() {
//1.
   int cofrinho = 150;
   int *p = &cofrinho;
    printf("Valor no Cofrinho: %d, Endereco do Cofrinho: %p\n\n", *p, p);

//2.
int idade;
    printf("Digite a idade: ");
    scanf("%d", &idade);
    int *ptr = &idade;
    printf("Idade: %d, endereco: %p\n\n", *ptr, ptr);
    
//3.
float precos[5], *pp = precos;
    for(int i=0;i<5;i++){
        printf("Preco %d: ", i+1);
        scanf("%f", pp+i);
    }
    for(int i=0;i<5;i++){
        printf("Produto %d: %.2f | Desconto 10%%: %.2f\n", i+1, *(pp+i), *(pp+i)*0.9);
    }
    printf("\n");

//4.
 int n;
    printf("Numero de funcionarios: ");
    scanf("%d", &n);
    int horas[n], *ph = horas, total=0;
    for(int i=0;i<n;i++){
        printf("Horas funcionario %d: ", i+1);
        scanf("%d", ph+i);
        total += *(ph+i);
    }
    printf("Total de horas: %d\n\n", total);
    
 //5.
  float notas[6], *pn = notas, temp;
    for(int i=0;i<6;i++){
        printf("Nota %d: ", i+1);
        scanf("%f", pn+i);
    }
    for(int i=0;i<3;i++){
        temp = *(pn+i);
        *(pn+i) = *(pn+5-i);
        *(pn+5-i) = temp;
    }
    printf("Notas invertidas: ");
    for(int i=0;i<6;i++) printf("%.2f ", *(pn+i));
    printf("\n\n");
    
//6.
float mat[3][3], *pm = &mat[0][0], soma=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++){
            printf("Nota aluno %d prova %d: ", i+1,j+1);
            scanf("%f", pm+i*3+j);
            if(i==j) soma += *(pm+i*3+j);
        }
    printf("Matriz de notas:\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++) printf("%.2f ", *(pm+i*3+j));
        printf("\n");
    }
    printf("Soma diagonal: %.2f\n\n", soma);

//7.
 int pontos[4][4], *ppontos = &pontos[0][0], pares=0, impares=0;
    int soma_j[4]={0}, soma_s[4]={0}, maior_diff=1000, jogador_regular=0;

    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++){
            printf("Pontos jogador %d set %d: ", i+1,j+1);
            scanf("%d", ppontos+i*4+j);
            soma_j[i] += *(ppontos+i*4+j);
            soma_s[j] += *(ppontos+i*4+j);
            if(*(ppontos+i*4+j)%2==0) pares++; else impares++;
        }

    printf("\nMatriz de pontos:\n");
    for(int i=0;i<4;i++){
        int maior=*(ppontos+i*4), menor=*(ppontos+i*4);
        for(int j=0;j<4;j++){
            printf("%d ", *(ppontos+i*4+j));
            if(*(ppontos+i*4+j) > maior) maior = *(ppontos+i*4+j);
            if(*(ppontos+i*4+j) < menor) menor = *(ppontos+i*4+j);
        }
        if(maior-menor < maior_diff){
            maior_diff = maior-menor;
            jogador_regular = i+1;
        }
        printf("\n");
    }

    int maior_j=0, jog_maior=0, maior_s=0, set_maior=0;
    for(int i=0;i<4;i++){
        printf("Total jogador %d: %d\n", i+1, soma_j[i]);
        if(soma_j[i]>maior_j){maior_j=soma_j[i]; jog_maior=i+1;}
    }
    printf("Jogador com mais pontos: %d\n", jog_maior);

    for(int i=0;i<4;i++){
        printf("Total set %d: %d\n", i+1, soma_s[i]);
        if(soma_s[i]>maior_s){maior_s=soma_s[i]; set_maior=i+1;}
    }
    printf("Set mais disputado: %d\n", set_maior);

    printf("Pares: %d, Impares: %d\n", pares, impares);

    printf("Media por jogador:\n");
    for(int i=0;i<4;i++) printf("Jogador %d: %.2f\n", i+1, soma_j[i]/4.0);

    printf("Jogador mais regular: %d\n", jogador_regular);

    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
