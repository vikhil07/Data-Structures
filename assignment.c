#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node
{
    char name[20];
    int goals;
    char club[20];
    struct node *link;
}Node, *NP;

NP start;

NP create(int goals, char name[], char club[])
{
	NP new=(NP)malloc(sizeof(Node));
   new->link=NULL;
   strcpy(new->name,name);
   strcpy(new->club,club);
	new->goals=goals;
	return new;
}

void insertbeg(int goals, char name[], char club[])
{
    NP new = create(goals,name,club);
    if(start==NULL)
        start=new;
    else
    {
        new->link=start;
        start=new;
    }
}

void insertend(int goals, char name[], char club[])
{
    NP new = create(goals,name,club);
    if(start==NULL)
        start=new;
    else
    {
        NP tmp=start;
        while(tmp->link!=NULL)
            tmp=tmp->link;
        tmp->link=new;
    }
}

void insertany(int goals, char name[], char club[], int pos)
{
    NP new = create(goals,name,club);
    int posi = 1;
	 NP tmp=start;
    if(pos==1)
    {
    	new->link=start;
    	start=new;
    }
    else
    {
    	while(tmp->link!=NULL)
    	{ 	
    		 if(posi+1==pos)
    		 {																
    			new->link=tmp->link;
    			tmp->link=new;
    		}
      	tmp=tmp->link;
      	posi++;  
    	}
    }
}

void del(char name[])
{
	NP tmp=start;
	if(start==NULL)
		return;

	if(!strcmp(tmp->name,name))
	{
	    start=tmp->link;
       free(tmp);
	}
	else
	{	while( strcmp(tmp->link->name,name) )
			tmp=tmp->link;
		NP to_free = tmp->link;
		tmp->link=tmp->link->link;
      free(to_free);
	}
}
void display()
{
	if(start==NULL)
		printf("EMPTY LIST");
	else
	{
		NP tmp=start;
		while(tmp!=NULL)
		{
		   printf("[%s,%s,%d] ----> ",tmp->name,tmp->club,tmp->goals);
		   tmp=tmp->link;
		}
	}
}


void search_node(char name[])
{
	NP tmp=start;
	if(start==NULL)
		return;
	int flag=0,pos = 1;
	while( tmp!=NULL )
	{	
		if(strcmp(tmp->name,name)==0)
		{
			printf("%s found at position: %d \n",name,pos);		
			flag=1;
		}
		pos++;	
		tmp=tmp->link;
	}
	if(flag==0)
		printf("Player not found\n");	
	
}

void count_nodes()
{
	NP tmp=start;
	int count=0;
	while(tmp!=NULL)
	{	
		count++; 
		tmp=tmp->link;	
	}
	
	printf("Number of nodes are %d\n",count);
}

void avg()
{
	NP tmp=start;
	int sum=0,count=0;
	while(tmp!=NULL)
	{	
		count++;
		sum+=tmp->goals;		
		tmp=tmp->link;
	}
	float aveg = (float)sum/count;
	printf("Average goals: %f\n",aveg);
}

int main()
{
	int ch, goal, nxt, pos;
	char name[20], club[20], car;
	int num;
	
	insertend(1,"Messi","Barcelona");
	insertend(2,"Ronaldo","Madrid");
	printf("\n");display();printf("\n");
	//Insertion Beginning
	printf("\nEnter number of nodes to be inserted at beginning:");
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{	
		
		printf("\nNode-%d\nEnter the Goals: ",i+1);
		scanf("%d",&goal);
		printf("Enter the Name: ");
		scanf("%s",name);
		printf("Enter the Club: ");
		scanf("%s",club);
		insertbeg(goal,name,club);
		printf("\n");
		display();
		printf("\n");
	}
	
	//Insertion End
	printf("\nEnter number of nodes to be inserted at end:");
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{	
		
		printf("\nNode-%d\nEnter the Goals: ",i+1);
		scanf("%d",&goal);
		printf("Enter the Name: ");
		scanf("%s",name);
		printf("Enter the Club: ");
		scanf("%s",club);
		insertend(goal,name,club);
		printf("\n");
		display();
		printf("\n");
	}
	//Insertion Any
	printf("\nEnter number of nodes to be inserted at given position:");
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{	
		
		printf("\nNode-%d\nEnter the Goals: ",i+1);
		scanf("%d",&goal);
		printf("Enter the Name: ");
		scanf("%s",name);
		printf("Enter the Club: ");
		scanf("%s",club);
		printf("Enter the Position: ");
		scanf("%d",&pos);
		insertany(goal,name,club,pos);
		printf("\n");
		display();
		printf("\n");
	}
	//Deletion		
	printf("\nEnter number of nodes to be deleted:");
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		printf("\nDelete operation:%d\nEnter the name to be deleted : ",i+1);
		scanf("%s",name);
		del(name);
		printf("\n");
		display();
		printf("\n");
	}
	//Search
	printf("\nEnter number of nodes to be searched:");
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		printf("\nEnter the name to be Searched : ");
		scanf("%s",name);
		search_node(name);
	}
	printf("\n");
	count_nodes(); //Count
	avg();			//Average
return 0;
}
