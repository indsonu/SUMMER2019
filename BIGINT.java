import java.util.*;
import java.math.BigInteger;
public class Main {
    public static void main(String args[]) throws Exception {
        Scanner sc=new Scanner(System.in);
        BigInteger bi=sc.nextBigInteger();
        BigInteger a=new BigInteger("4");
        BigInteger b=new BigInteger("5");
        BigInteger c=new BigInteger("6");
        BigInteger d=new BigInteger("14");
        a=a.multiply(bi); a=a.multiply(bi); a=a.multiply(bi);
        b=b.multiply(bi);b=b.multiply(bi);
        c=c.multiply(bi);
        a=a.add(b);
        a=a.subtract(c);
        System.out.println(a.add(d));

    }
}
