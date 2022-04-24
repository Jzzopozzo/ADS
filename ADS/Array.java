import java.util.Scanner;

class Array
{
	public static void main(String args[])
	{
		Scanner s= new Scanner(System.in);
		int a[]= new int[50];
		int i, n;
		float sum=0, avg=0;
		System.out.print("Enter the size of array:");
		n= s.nextInt();
		System.out.println("Enter elements:");
		for(i=0; i<n; i++)
		{
			a[i]=s.nextInt();
			sum= sum+ a[i];
		}
		avg=sum/n;
		System.out.println("Elements of array are:");
		for(i=0; i<n; i++)
		{
			System.out.println(+a[i]);
		}
		System.out.println("Sum of the array= "+sum);
		System.out.println("Average of the array elements= "+avg);

		int tmp, gap, swapped, j;
		gap= n/2;
		do
		{
			do
			{
				swapped=0;
				for(i=0; i<n-gap; i++)				
				{
					if(a[i]>a[i+gap])
					{
						tmp=a[i];
						a[i]=a[i+gap];
						a[i+gap]=tmp;
						swapped=1;
						System.out.print("\n Pass "+i);
						System.out.println(":");			
					}
				}
			}while( swapped==1);
			for(j=0; j<n; j++)
			{
				System.out.println(+a[j]);
			}
				
		}while( gap== gap/ 2);	
		
		System.out.println("Finally, Sorted array is:");
		for(i=0; i<n; i++)	
		{
			System.out.println(+a[i]);
		}
			
	}

}
