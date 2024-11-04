/*

a) (p->prox = q) estamos atribuindo a ligacao de p como q;

b) (p->prox = q->prox) atribuimos a ligacao de p ao elemento que esta sendo a ligacao de q;

c) (p->info = q->info) atribuimos a informacao guardada em p como a informacao atribuida em q;

d) (p = q) estamos igualando nos;

e) (p->prox = NULL) atribuimos a ligacao de p como nula, usada para sinalizar final de lista ou simplesmente atribuir como nula;

f) (p = p->prox) o p atual se torna sua ligacao, como se estivesemos pulando uma casa para tras;

g) (p = (p->prox)->prox) estamos atribuindo p como a ligacao da sua ligacao;

h) (p->prox = p) estamos conectando p a ele mesmo;

*/