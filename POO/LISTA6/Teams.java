import java.util.*;

public class Teams {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n + 5];

        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        Arrays.sort(arr, 0, n);

        int ans = 0;

        for (int i = 0; i < n; i += 2) {
            if (arr[i] != arr[i + 1]) {
                ans += Math.abs(arr[i] - arr[i + 1]);
            }
        }

        System.out.println(ans);
    }
}
