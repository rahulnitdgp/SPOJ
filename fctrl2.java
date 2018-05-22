import java.util.Scanner;
import java.math.BigInteger;

class fctrl
{
	int number, test_cases;
}
class fctrl2
{
	public static void main(String[] args)
	{
		fctrl obj = new fctrl();
		Scanner in = new Scanner(System.in);

		obj.test_cases  = in.nextInt();
		while(obj.test_cases>0)
		{
			obj.number = in.nextInt();
			BigInteger f = new BigInteger("1"); // Or BigInteger.ONE
			for(int i=2;i<=obj.number;i++)
			{
				f = f.multiply(BigInteger.valueOf(i));
			}
			System.out.println(f);
			(obj.test_cases)--;
		}
	}
}