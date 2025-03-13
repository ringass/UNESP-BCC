import java.util.Scanner;

public class Fibonacci {
    
    private int x;

    

    public Fibonacci(int x){
        this.x = x;
    }

    
    public int calc(){
        int f1 = 0, f2 = 1;
        int f3 = 0;
        
        if(x == 0 || x == 1){
            return 0;
        }

        for(int i = 0; i < x; i++){
            f1 = f2;
            f2 = f3;
            f3 = f2 + f1;
        }


        return f3;
    }

    public static void main(String args[]){

        Scanner sc = new Scanner(System.in);

        System.out.println("Digite: ");
        int t = sc.nextInt();

        Fibonacci fibo = new Fibonacci(t);


        System.out.format("termo de numero %d: %d", t, fibo.calc());


        sc.close();

    }


}
