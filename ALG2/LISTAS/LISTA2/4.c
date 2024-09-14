#include <stdio.h>

typedef struct
{
  int a;
  int b;
} racional;

racional ler()
{
  racional p;

  scanf("%d", &p.a);
  scanf("%d", &p.b);
  return p;
}

int mdc(int a, int b)
{
  if (b == 0)
    return a;
  return mdc(b, a % b);
}

racional simp(racional n)
{
  int div = mdc(n.a, n.b);
  n.a /= div;
  n.b /= div;
  return n;
}

racional multi(racional r1, racional r2){
  racional mult;

  mult.a = r1.a * r2.a;
  mult.b = r2.b * r1.b;
  return simp(mult);
}

racional sub(racional r1, racional r2)
{

  racional sub;

  sub.a = r1.a * r2.b + r2.a * r1.b;
  sub.b = r1.b * r1.b;
  return simp(sub);
}

racional somar(racional r1, racional r2)
{
  racional soma;

  soma.a = r1.a * r2.b + r2.a * r1.b;
  soma.b = r1.b * r1.b;
  return simp(soma);
}

racional div(racional r1, racional r2){
  racional d;

  d.a = r1.a * r2.b;
  d.a = r2.a * r1.b;

  return simp(d);
}

void imprime(racional m) {
    printf("%d/%d\n", m.a, m.b);
}

int main(int argc, char *argv[])
{
  racional m1, m2, res;

  m1 = ler();
  m2 = ler();

  res = somar(m1, m2);
  imprime(res);
  res = div(m1, m2);
  imprime(res);
  res = multi(m1, m2);
  imprime(res);
  res = sub(m1, m2);
  imprime(res);
  return 0;
}
