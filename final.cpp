#include<stdio.h>
#include<string.h>

struct process
{
	char pname[100];
	int at,bt,ct,rt;
}p1;

void project(int n)
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
	printf("Now, enter the quantum time: ");
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
    while(flag!=0);
    
    puts("\n\t\t\t********************************************");
    puts("\t\t\t*****    QUERY TABLE   *****");
    puts("\t\t\t********************************************\n");
    printf("\n|\tQuery Name\t  |\tArrival Time\t  |\tBurst Time\t |\tCompletion Time  \t|\n");
    
    for(i=0;i<n;i++)
	{
        wt=(f1[i].ct - f1[i].at) - f1[i].bt;
       	printf("\n|\t      %s\t        |\t      %d\t       |\t      %d\t       |\t      %d\t       |\n", f1[i].pname, f1[i].at, f1[i].bt, f1[i].ct);
    
	}
    int sum=0;
    float avg;
    for(i=0;i<n;i++)
    {
    sum=sum+f1[i].ct;
	}
	avg=sum/n;
	printf("TOTAL COMPLETION TIME OF THE QUERY IS:%d\n",sum);
	printf("AVERAGE TIME OF THE QUERY IS:%f",avg);
	puts("Thank You");
}
int main(int argc, char const *argv[])
{	
	int o,n,h;
	puts("\t                             **********************QUERY HANDLER**********************");
	puts("");
	puts("ENTER CURRENT TIME(Only the hour part and it must be in 24hr format.)");
	printf("> ");
	scanf("%d", &h);
	if((h>12)||(h<10))
	{
		puts("Sorry Query Handling Service Is Only Between 10-12");
		puts("Reach Us Between 10 to 12");
		puts("Thank You");
	}
	else
	{
	puts("Please choose a queue to post your query : ");
    puts("1. FACULTY queue.");
    puts("2. STUDENT queue.");
    printf("> ");
    scanf("%d", &o);

    switch(o) 
	{
        case 1 :
                printf("Enter number of process for FACULTY queue : ");
                scanf("%d", &n);
                
                project(n);
                
                break;

        case 2 :
                printf("Enter number of process for STUDENT queue : ");
                scanf("%d", &n);

                project(n);
                
                break;

        default : 
                printf("Please selet the correct option by running the program again.");
    }
	return 0;
}
	
}

