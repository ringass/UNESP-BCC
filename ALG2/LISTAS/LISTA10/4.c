/* Nao é necessario mallocar, nesse contexto de impressao é preciso apenas passar pelos elementos da lista e nao abrir um novo espaço de memoria, alem disso nao precisamos passar a lista como editavel, ou seja utilizando um ponteiro, pois ela só sera mostrada

comandos inuteis = 
    no p = (no)malloc(sizeof(struct reg));
    (no *lista) poderia ser (no lista);
*/