#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
	int alloc[10][10],max[10][10],need[10][10];
	int avble[1][10];
  	int exct[10];
	int flag=0,flag_safe=0;
	int n,m,i,j,a[10],k,x=0;
  char input[4];
  int reqmat[1][10];
  int ret,pid;
  int safety(int aloc[][10],int neede[][10],int avble[1][10],int n,int m,int exct[]){
	int able[1][10];
	for(i=0;i<n;i++)
		exct[i]=0;
	for(i=0;i<m;i++)
		able[0][i]=avble[0][i];
  for(k=0;k<n;k++){
		for(i=0;i<n;i++){
			if(exct[i]==0){
				flag=0;//reset flag
				for(j=0;j<m;j++){
					if(neede[i][j]>able[0][j]) flag=1;
				}
				if(flag==0&&exct[i]==0){
					for(j=0;j<m;j++) 
          {
            able[0][j]+=alloc[i][j];
          }
					exct[i]=1;//executed
					flag_safe++;//Count the number of processes executed
					a[x++]=i;
				}
			}
		}
	}
  return flag_safe;
  }

  int res_request(int alloc[][10],int need[][10],int avble[1][10],int pid,int m){
	int reqmat[1][10];
	int aloc[10][10], neede[10][10],able[1][10];
	int i;
	int id=pid-1;
	printf("\n Enter request :- \n");
	for(i=0;i<m;i++){
		scanf("%d",&reqmat[0][i]);
	}
	for(i=0;i<m;i++)
		able[0][i]=avble[0][i];
	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
	aloc[i][j]=alloc[i][j];
	neede[i][j]=need[i][j];
	}}
		
	for(i=0;i<m;i++)
		if(reqmat[0][i] > neede[id][i]){
			printf("\nRequest greater than need. \n");
			return(-1);
	}

	for(i=0;i<m;i++)
		if(reqmat[0][i] > able[0][i]){
			printf("\n Resources unavailable.\n");
			return (-1);
		}
	
	for(i=0;i<m;i++){
		able[0][i]-=reqmat[0][i];
		aloc[id][i]+=reqmat[0][i];
		neede[id][i]-=reqmat[0][i];
	}
	int ans=safety(aloc,neede,able,n,m,exct);
	return ans;
}


int main(){
  
	printf("\n DEADLOCK AVOIDANCE USING BANKER'S ALGORITHM\n");

	printf("\n Enter total no. of processes: ");
	scanf("%d",&n);

	printf("\n Enter total no. of resources: ");
	scanf("%d",&m);

  printf("\n Enter the Allocation Matrix:");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&alloc[i][j]);
    }
  }
  retry:
  printf("\nDo you want to enter the max matrix or the need matrix?: ");
  scanf("%s",input);

  for (i = 0;i<strlen(input);i++)
  {
    input[i] = tolower((unsigned char)input[i]);
  }
  if(strcmp(input,"max")==0)
  {
    printf("\nEnter the Maximum Matrix: ");
    for(i=0;i<n;i++){
		  for(j=0;j<m;j++){
			  scanf("%d",&max[i][j]);
		  }
	  }
    
    for(i=0;i<n;i++)
		  for(j=0;j<m;j++)
			  need[i][j]=max[i][j]-alloc[i][j];//Calculate Need Matrix
  }

  else if(strcmp(input,"need")==0)
  {
    printf("\nEnter the Need Matrix:");
    
   for(i=0;i<n;i++)
		  for(j=0;j<m;j++)
       {scanf("%d",&need[i][j]);
		}

  }

  else
  {
   printf("Not a valid choice");
   goto retry;
  }

	printf("\nEnter the Available resources:");
	for(i=0;i<m;i++){
		scanf("%d",&avble[0][i]);
	}

	printf("\n Allocation Matrix:");
	for(i=0;i<n;i++){
		printf("\n");
		for(j=0;j<m;j++){
			printf("%d\t",alloc[i][j]);
		}
	}	

  if(strcmp(input,"max")==0)
	{
    printf("\n Maximum Matrix:");
	  for(i=0;i<n;i++)
    {
		  printf("\n");
		  for(j=0;j<m;j++)
      {
			  printf("%d\t",max[i][j]);
		  }
	  }
  }	

	printf("\n Need Matrix:");
	for(i=0;i<n;i++)
  {
		printf("\n");
		for(j=0;j<m;j++)
    {
			printf("%d\t",need[i][j]);
		}
	}	

  ret=safety(alloc,need,avble,n,m,exct);
  if(ret!=0)
  { printf("\n A safe sequence has been detected");
	  again: printf("\nDo you want to request for any processes(YES||NO): ");
    scanf("%s",input);

    for (i = 0;i<strlen(input);i++)
    {
      input[i] = tolower((unsigned char)input[i]);
    }
    if (strcmp(input,"yes")==0)
    {
      printf("\nEnter your request:");
		  printf("\n Enter Process no.: ");
		  scanf("%d",&pid);
		  int check=res_request(alloc,need,avble,pid,m);
		  if(check==-1)	goto again;
	    if(check!=0)
      {
        printf("\n A safe sequence has been detected.No Deadlocks\n");
		    for(i=0;i<n;i++)
        {
          printf("P%d",a[i]);
          if(i!=n-1) printf("--->");
        }
      }
    } 
    else
    {
      printf("\n A safe sequence has been detected.No Deadlocks\n");
		  for(i=0;i<n;i++)
      {
        printf("P%d",a[i]);
        if(i!=n-1) printf("---->");
      }
    }
  }
	else
  {
		printf("\n Deadlock has occured.Exiting...\n");
		exit(0);
	  }
}



