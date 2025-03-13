public class NumComplexo {
    double r, i;

    void atrib(double ar, double ai){
        r = ar;
        i = ai;
    }

    public static void main(String s[]){
        NumComplexo x = new NumComplexo();
        x.atrib(1.2, 9.8);
        System.out.format("(%.1f + %.1fi)\n", x.r, x.i);
    }
}
