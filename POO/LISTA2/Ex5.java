package POO.LISTA2;

abstract class MostraDados {
    abstract void mostra(int l);

    abstract void mostra(float f);
}

class Ex5 {
    static int valor = 123;
    static float x = 4.56;

    static void mostraValores(MostraDados db) {
        db.mostra(x);
        db.mostra(valor);
    }

    public static void main(String[] s) {
        Mostra mostra = new Mostra();
        mostraValores(mostra);
    }
}

// ------------------------------------------------
class Mostra extends MostraDados {
    @Override
    void mostra(int l) {
        System.out.println("int: " + l);
    }

    @Override
    void mostra(float f) {
        System.out.println("float: " + f);
    }
}
// ------------------------------------------------