#include<stdio.h>
#include<string.h>

struct process
{
	char pname[100];
	int at,bt,ct,rt;
}p1;

void faculty(int n)
{
	int i,at1,bt1,qt;
	struct process f1[n];
	
	for(i=0;i<n;i++)
	{
		printf("Enter the details of Process[%d]", i+1);
        puts("");
        printf("Process Name : ");
        scanf("%s", &f1[i].pname);

        printf("Arrival Time : ");
        scanf("%d", &f1[i].at);

        printf("Burst Time : ");
        scanf("%d", &f1[i].bt);
        puts("");
	}
	printf("Now, enter the quantum time for FACULTY : ");
    scanf("%d", &qt);
    
    
    for(i=0;i<n;i++)
	{
    	for(int x=i+1;x<i;x++)
		{
            if(f1[i].at > f1[x].at)
			{
                p1 = f1[i];
                f1[i] = f1[x];
                f1[x] = p1;
            }
        }
    }	
    
