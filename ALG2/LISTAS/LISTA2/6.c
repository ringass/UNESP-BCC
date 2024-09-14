#include <stdio.h>

/*Escreva uma função que receba dois parâmetros do tipo dma, cada um representando
uma data valida, e retorne o número de dias que decorreram entre as duas datas.  */
typedef struct 
{
  int dia;
  int mes;
  int ano;
}dma;

int bissexto(int ano){
  if(ano % 4 == 0 && ano % 100 != 0){
    return 366;
  }else{
    return 365;
  }
}

int dias(int m, int ano){
  switch (m) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return bissexto(ano) ? 29 : 28;
        default:
            return 0; 
    }
}

int convert(dma data){
  int d = 0,i = 0;
  d += data.dia;

  for(i = 0; i < data.ano; i++){
    d += bissexto(i);
  }

  for(i = 1; i < data.mes; i++){
    d = dias(i, data.ano);
  }

  return d;
}

int main()
{
  dma p1, p2;

  scanf("%d %d %d", &p1.dia, &p1.mes, &p1.ano);
  scanf("%d %d %d", &p2.dia, &p2.mes, &p2.ano);

  int res = abs(convert(p1) - convert(p2));
  printf("%d", res);
  return 0;
}