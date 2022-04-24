import java.io.*;
import java.util.*;

public class Scan
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

		System.out.print("Roll number ?");
		roll=s.nextInt();

		System.out.print("Name? ")		;
		name=s.next();

		System.out.println("\nRoll No: "+roll);
		System.out.println("Name: "+name);
	}
}

/*
OUTPUT:
jayashree@kkw-HP-Pro-3330-MT:~/Documents$ javac Scan.java
jayashree@kkw-HP-Pro-3330-MT:~/Documents$ java Buffer

Enter any number:
9999

You just entered 9999

Who are you?
No one

Okay! What's your roll number?
03

Your name is No one	and the roll number: 3
*/

