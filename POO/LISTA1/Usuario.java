import java.util.Scanner;

public class Usuario {

    int[] arr;

    public Usuario(int x){
        arr = new int[x];
    }
    
    public void getElements(Scanner sc) {

        for (int i = 0; i < arr.length; i++) {
            System.out.format("arr[%d] = ", i);
            arr[i] = sc.nextInt();
        }
    }

    public void sort() {

        int flag = 0;

        int i, temp;

        while (flag != 1) {
            flag = 1;
            for (i = 0; i < arr.length-1; i++) {
                if (arr[i] > arr[i + 1]) {
                    temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                    flag = 0;
                }
            }
        }
    
    }

    public static void main(String args[]){

        Scanner sc = new Scanner(System.in);

        System.out.println("Digite o tamanho do seu vetor: ");
        int n = sc.nextInt();
        

        Usuario user = new Usuario(n);
        
        user.getElements(sc);
        user.sort();

        System.out.println("VETOR: ");

        for(int i = 0; i < n; i++){
            System.out.format("arr[%d]: %d\n", i, user.arr[i]);
        }

        sc.close();

    }
}
