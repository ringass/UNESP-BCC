//instancia é o processo utilizado para criar um objeto a partir de uma classe, ao criar uma instacia vc aloca memoria para armazenar o objeto com os moldes descritos por sua classe.

public class Ex2{
    String cor;

    public Ex2(String cor){
        this.cor = cor;
    }

    public static void main(String[] args){
        Ex2 mesa = new Ex2("preto"); //instancia

        System.out.println("cor da mesa: " + mesa.cor);
    }
}