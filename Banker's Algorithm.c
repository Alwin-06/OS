#include<stdio.h>
#define MAX_P 10
#define MAX_R 5
int compare(int a[],int b[],int count)
{
    int i,flag=1;
    for(i=0;i<count;i++)
    {
        if(a[i]>b[i])
        {
            flag=0;
        }
    }
    return flag;
}

void result(int a[],int s)
{
    int i;
    printf("\nSafe Sequence: ");
    for(i=0;i<s;i++)
    {
        printf("P%d  ",a[i]);
    }
    printf("\n");
}

int main()
{
    int m,n,max[MAX_P][MAX_R],allocation[MAX_P][MAX_R],need[MAX_P][MAX_R],available[MAX_R];
    printf("How many processes: ");
    scanf("%d",&n);
    printf("How many types of resources: ");
    scanf("%d",&m);
    int i,j;
    printf("Enter the count of avaliable resources: \n");
    for(i=0;i<m;i++)
    {
        printf("%d : ",i);
        scanf("%d",&available[i]);
    }
    printf("Maximum Required Resources: \n");
    for(i=0;i<n;i++)
    {
        printf("P%d : ",i);
        for(j=0;j<m;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }
    printf("Currently Allocated Resources: \n");
    for(i=0;i<n;i++)
    {
        printf("P%d : ",i);
        for(j=0;j<m;j++)
        {
            scanf("%d",&allocation[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            need[i][j]=max[i][j]-allocation[i][j];
        }
    }
    int k,work[MAX_R],finish[MAX_P],states[MAX_P],l=0;
    for(i=0;i<m;i++)
    {
        work[i]=available[i];
    }
    for(i=0;i<n;i++)
    {
        finish[i]=0;
    }
    int count =0;
    for(j=0;j<n;j++)
    {
        for(i=0;i<n;i++)
        {
            if(finish[i]==0 && compare(need[i],work,m))
            {
                for(k=0;k<m;k++)
                {
                    work[k]+=allocation[i][k];
                }
                finish[i]=1;
                states[l++]=i;
                count++;
                break;
            }
        }
    }
    if(count==n)
    {
        result(states,n);
    }
    else
    {
        printf("\nDeadlock may occur....\n\n");
    }
    return 0;
}
