import java.util.Scanner;

public class Matrix {

    int col, lin;
    int[][] matrix1, matrix2;

    public Matrix(int col, int lin) {
        this.col = col;
        this.lin = lin;

        matrix1 = new int[lin][col];
        matrix2 = new int[lin][col];
    }

    public void getMatrix(Scanner sc, int[][] mat, int num) {
        System.out.format("Matriz %d\n", num);
        for (int i = 0; i < lin; i++) {
            for (int j = 0; j < col; j++) {
                System.out.format("m[%d][%d]", i, j);
                mat[i][j] = sc.nextInt();
            }
        }
        // System.out.println("\n");
    }

    public void showMatrix(int[][] mat, int num) {

        System.out.format("Matriz %d\n", num);
        for (int i = 0; i < lin; i++) {
            for (int j = 0; j < col; j++) {
                System.out.format("m[%d][%d] = %d\n", i, j, mat[i][j]);
            }
        }
        // System.out.println("\n");
    }

    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);

        System.out.println("Digite a quantidade de colunas: ");
        int col = sc.nextInt();

        System.out.println("Digite a quantidade de linhas: ");
        int lin = sc.nextInt();

        Matrix obj = new Matrix(col, lin);

        obj.getMatrix(sc, obj.matrix1, 1);
        obj.getMatrix(sc, obj.matrix2, 2);
        obj.showMatrix(obj.matrix1, 1);
        obj.showMatrix(obj.matrix2, 2);

        sc.close();
    }
}
