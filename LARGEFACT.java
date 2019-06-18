import java.util.*;
import java.math.BigInteger;
public class Main {
    public static void main(String args[]) throws Exception {
        Scanner sc=new Scanner(System.in);
        BigInteger result = BigInteger.ONE;
        int bi=sc.nextInt();
        for(int i=2;i<=bi;i++){
            result=result.multiply(new BigInteger(i+"")); //N IMP** WHILE PASSING THE OBJECT I+"" IS MUST OTHER WISE CTE
        }
        System.out.println(result);
    }
}
