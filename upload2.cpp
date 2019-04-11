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
    
    for(i=0;i<n;i++)
	{
        f1[i].rt= f1[n].bt;
        f1[i].ct
		= 0;
    }
    
    int tt,queue,rr[20];
    tt=0;
    queue=0;
    rr[queue]=0;
    
    int flag,x,m,z,wt=0;
    do 
	{
        for(i=0;i<n;i++)
		{
            if(tt>=f1[i].at)
			{
                z=0;
                for(x=0;x<=queue;x++)
				{
                    if(rr[x]==i) 
					{
                        z++;
                    }
                }
                if(z==0) 
				{
                    queue++; 
                    rr[queue]==i;
                }
            }
        }
        
        if(queue==0) 
		{
            m=0;
        }
        if(f1[m].rt==0) 
		{
            m++ ;
        }
        if(m>queue) 
		{
            m=(m-1)%queue;
        }
        if(m<=queue) 
		{
            if(f1[m].rt>0) 
			{
                if(f1[m].rt<qt)
				{
                    tt+=f1[m].rt;
                    f1[m].rt=0;
                }
				else 
				{
                    tt+=qt;
                    f1[m].rt-= qt;
                }
                f1[m].ct=tt;
            }
            m++;
        }
        flag=0;
        
        for(i=0;i<n;i++) 
		{
            if(f1[m].rt>0) 
			{
                flag++;
            }
        }
    }
