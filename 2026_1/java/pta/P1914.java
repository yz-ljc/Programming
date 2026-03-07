import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        int n = input.nextInt();
        String s = input.next();

        char[] arr = s.toCharArray();

        for (int i = 0; i < arr.length; i++) {

            char tmp = (char)(arr[i] + n);

            if (tmp > 'z') {
                tmp = (char)(tmp - 'z' - 1 + 'a');
            }

            arr[i] = tmp;
        }

        System.out.println(new String(arr));
    }
}