 /* Experiment Lab-9: Design, Develop and Implement a Program in C for the following operations 
 on Graph(G) of Cities
a. Create a Graph of N cities using Adjacency Matrix.
b. Print all the nodes reachable from a given starting node in a digraph using
DFS/BFS method */

#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

//Breadth First Source - Traversal
void bfs(int n, int source, int adjmat[][SIZE], int visited[]);
//Depth First Source - Traversal
void dfs(int n, int source, int adjmat[][SIZE], int visited[]);

void main()
{
	int n, adjmat[SIZE][SIZE], source, visited[SIZE]={0}, i, j;
	int choice;
	for(;;)
	{
		printf("Enter number of vertices:\n");
		scanf("%d", &n);
		printf("\nEnter the adjacency matrix:\n");
		for(i=0; i<n; i++)
		{
			for(j=0; j<n; j++)
			{
				scanf("%d", &adjmat[i][j]);
			}
		}
		printf("\nThe adjacency matrix is:\n");
		for(i=0; i<n; i++)
		{
			for(j=0; j<n; j++)
			{
				printf("%d\t", adjmat[i][j]);
			}
			printf("\n");
		}
		printf("Give the source:\n");
		scanf("%d", &source);
		for(i=0; i<n; i++)
			visited[i]=0;
		printf("\nEnter 1. BFS\n 2. DFS ");
		printf("\n Enter the choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 : 	bfs(n, source, adjmat, visited);
						break;
			case 2 : 	dfs(n, source, adjmat, visited);
						break;
			default:    printf("\n Wrong choice, Try again ");
		}			
		for(i=0;i<n;i++)
		{
				if(visited[i]==0)
					printf("%d is not reachable\n", i);
				else
					printf("%d is reachable\n",i);
		}
	}
}
void bfs(int n, int source, int adjmat[][SIZE], int visited[])
{
	int queue[SIZE], r=-1, f=0, u, v;
	visited[source]=1;
	printf("%d\t",source);
	queue[++r]=source;
	while(f<=r) //until queue is empty
	{
		u= queue[f++]; //Remove or delete an vertex from queue
		for(v=0;v<n;v++)
		{
			// An edge between u to v and  the vertex 'v' not visited
			if((adjmat[u][v]==1)&(visited[v] != 1)) 
			{
				queue[++r]=v; //Insert the node in the Queue
				visited[v]=1; // Make the inserted node - visited
				printf("%d\t",v);
			}

		}
	}
}

void dfs(int n, int source, int adjmat[][SIZE], int visited[]) 
{
	int i;
	visited[source]=1;
	printf("%d\t",source);
	for (i=0;i<n;i++)
		// An edge between u to v and  the vertex 'v' not visited
		if(adjmat[source][i] && !visited[i]) 
		{
			visited[i]=1;
			dfs(n, i, adjmat, visited);
    	}
 }
 