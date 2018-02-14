#include <stdio.h>

int main()
{
	int n,i,j;
	printf("Enter the number of Pages: ");
	scanf("%d",&n);
	int p[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
	}
	int m[4]={0};
	int f=0,fault=0,flag=0;
	for(i=0;i<n;i++)
	{
		flag=0;
		for(j=0;j<4;j++)
		{
			if(p[i]==m[j])
			{
				flag=1;
				break;
			}
		}
		if(!flag)
		{
			m[f%4]=p[i];
			f++;
			fault++;
		}
	}
	printf("No of Faults= %d",fault);
}

