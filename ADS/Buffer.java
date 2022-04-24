import java.io.*;
import java.util.*;

public class Buffer
{
	public static void main(String args[]) throws IOException
	{
		int r;
		String name;
		int roll;
		System.out.println("\nEnter any number:");
		Scanner s=new Scanner(System.in);
		r= s.nextInt();
		System.out.println("\nYou just entered "+r);

		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));

		System.out.println("\nWho are you?");		
		name=br.readLine();

		System.out.println("\nOkay! What's your roll number?");
		roll=Integer.parseInt(br.readLine());

		System.out.print("\nYour name is "+name);
		System.out.println("\tand the roll number: "+roll);
	}
}

/*
OUTPUT:
jayashree@kkw-HP-Pro-3330-MT:~/Documents$ javac Buffer.java
jayashree@kkw-HP-Pro-3330-MT:~/Documents$ java Buffer

Enter any number:
0

You just entered 0

Who are you?
No one

Okay! What's your roll number?
03

Your name is No one	and the roll number: 3
*/
