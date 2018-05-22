import java.util.*;

class fctrl{

	static int t;
	static int n;
	static int trail_zero , k, fraction;
	public static void main(String args[])
	{
		Scanner in = new Scanner(System.in);
		
		t = in.nextInt();
		while(t>0)
		{
			trail_zero = 0;
			k = 1;
			n = in.nextInt();
			fraction = Integer.MIN_VALUE;
			while(fraction <= n)
			{
				fraction = (int)Math.pow(5,k);
				trail_zero += n/fraction;
				k++;
			}
			System.out.println(trail_zero);
			t--;
		}
	}
}