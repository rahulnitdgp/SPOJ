import java.util.Scanner;


class toandfro
{
	//declare obj = new declare();	

	public static void main(String[] args)
	{

		declare obj = new declare();	

		Scanner sc = new Scanner(System.in);
		
		obj.col = sc.nextInt();

		while(obj.col!=0)
		{
			//obj.s = new String();
			obj.s = sc.nextLine();
			obj.s = sc.nextLine();
			obj.row = (obj.s.length())/(obj.col);
			int cnt = 1;
			for(int i=0;i<obj.col;i++)
			{
				int count = 0;
				for(int j=i;count<obj.row;)
				{
					System.out.print(obj.s.charAt(j));
					if(count%2==0)
					{
						j = j + (2*obj.col - cnt);
					}
					else
					{
						j = j+cnt;
					}
					count+=1;
				}
				cnt+=2;
			}
			System.out.println();
			obj.col = sc.nextInt();
		}
	}
}
	
class declare
{
	int col,row;
	String s;
	
}
