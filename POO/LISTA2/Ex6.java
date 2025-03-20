interface MostraDados {
    void mostra(int l);

    void mostra(float f);
}

// ------------------------------------------------

class Mostra implements MostraDados {
    @Override
    public void mostra(int l) {
        System.out.println("int: " + l);
    }

    @Override
    public void mostra(float f) {
        System.out.println("float: " + f);
    }
}

// ------------------------------------------------

class ProgPrincipal {
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
