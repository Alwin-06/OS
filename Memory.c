include<stdio.h>

void ff(int p,int b,int pro[12],int block[12])
{
   int i,j,alloc[12],flag=0,block1[12];
   for(i=0;i<b;i++)
   {
      block1[i]=block[i];
   }
   printf("\n Process Number \t\t Block Number\n");
   for(i=0;i<p;i++)
   {
      flag=0;
      for(j=0;j<b;j++)
      {
         if(block[j]>=pro[i])
         {
            alloc[j]>=pro[i];
            block1[j]=block[j]-pro[i];
            flag=1;
            break;
         }
      }
      if(flag==1)
      {
         printf("\n%d\t\t\t%d",i,j);
      }
      else
      {
         printf("\n%d\t\t\tnot allocated",i);
      }
   }
}

void bf(int p,int b,int pro[12],int block[12])
{
   int i,j,alloc[12],flag=0,block2[12],block1[12],best_index;
   for(i=0;i<b;i++)
   {
      block2[i]=block1[i];
   }
   for(i=0;i<b;i++)
   {
      alloc[i]=-1;
   }
   for(i=0;i<p;i++)
   {
      best_index=-1;
      for(j=0;j<b;j++)
      {
         if(pro[i]<=block2[j])
         {
            if(best_index=-1)
            {
               best_index=j;
            }
            else
            {
               if(best_index>block[j])
               {
                  best_index=j;
               }
            }
         }
   }   }
   if(best_index!=-1)
   {
      alloc[i]=best_index;
      block[best_index]=block2[best_index]-pro[i];
   }

   printf("\n Process Number \t\t Block Number \n");
   for(i=0;i<p;i++)
   {
      if(alloc[i]!=-1)
      {
         printf("\n%d\t\t%d",i,alloc[i]);
      }
      else
      {
         printf("\nNot Allocated");
      }
   }
}

void wf(int p,int b,int pro[12],int block[12])
{
   int i,j,alloc[12],flag=0,block3[12],worst_index;
   for(i=0;i<b;i++)
   {
      block3[i]=block[i];
   }
   for(i=0;i<p;i++)
   {
      alloc[i]=-1;
   }
   for(i=0;i<p;i++)
   {
      worst_index=-1;
      for(j=0;j<b;j++)
      {
         if(pro[i]<=block3[j])
         {
            if(worst_index==-1)
            {
               worst_index=j;
            }
            else if(block[worst_index]<block3[j])
            {
               worst_index=j;
}
         }
      }

   if(worst_index!=-1)
   {
      alloc[i]=worst_index;
      block[worst_index]-=pro[i];
   }}
   printf("\n Process Number \t\t Block Number\n");
   for(i=0;i<p;i++)
   {
      if(alloc[i]!=-1)
      {
         printf("\n%d\t\t\t%d",i,alloc[i]);
      }
      else
      {
         printf("\n%d\t\t\tNot Allocated",i);
      }
   }
}

int main()
{
   int i,p,b,pro[12],block[12],m;
   printf("Enter number of process and blocks respectively: ");
   scanf("%d %d",&p,&b);
   printf("\n Enter the size of process");
   for(i=0;i<p;i++)
   {
      scanf("%d",&pro[i]);
   }
   printf("\nEnter the size of blocks: ");
   for(i=0;i<b;i++)
   {
      scanf("%d",&block[i]);
   }
   printf("\nProcess Number \t Process Size\n");
   for(i=0;i<p;i++)
   {
      printf("%d\t\t%d",i,pro[i]);
      printf("\n");
   }
   printf("\nBlock Number \t Block Size\n");
   for(i=0;i<b;i++)
   {
      printf("%d\t\t%d",i,block[i]);
      printf("\n");
   }
   printf("\n | FIRST FIT | \n");
   ff(p,b,pro,block);
   printf("\n | BEST FIT | \n");
   bf(p,b,pro,block);
   printf("\n | WORST FIT | \n");
   wf(p,b,pro,block);
}
