//////////////////////////////////////////////////////////////////////////////////////
//Name 			:dijkstra.c
//Copyright 	:Copyright Vivek Malik,2012
//Created on	:29-Apr-2012
//Author		:Vivek Malik
//Description 	:Implementing Dijkstra's algorithm
//////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int minimum(int a[],int m[],int k);
void printpath(int,int,int[]);

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int graph[15][15],pathestimate[15],mark[15],s[15];
	int num_of_vertices,source,i,j,u,predecessor[15];
	int count=0;
	printf("enter the no.of vertices :");
	scanf("%d",&num_of_vertices);
	if(num_of_vertices<=0){
		printf("\nthis is meaningless\n");
		exit(1);
	}
	printf("\nenter the cost matrix\n");
    for(i=1;i<=num_of_vertices;i++){
    	printf("\nenter the elements of row %d\n",i);
    	for(j=1;j<=num_of_vertices;j++){
    		scanf("%d",&graph[i][j]);
    	}
    }
    printf("\nenter the source vertex\n");
    scanf("%d",&source);
    for(j=1;j<=num_of_vertices;j++){
    	mark[j]=0;
    	pathestimate[j]=INT_MAX;
    	predecessor[j]=0;
    }
    pathestimate[source]=0;
    while(count<num_of_vertices){
    	u=minimum(pathestimate,mark,num_of_vertices);
    	s[++count]=u;
    	mark[u]=1;
    	for(i=1;i<=num_of_vertices;i++){
    		if(graph[u][i]>0){
    			if(mark[i]!=1){
    				if(pathestimate[i]>pathestimate[u]+graph[u][i]){
    					pathestimate[i]=pathestimate[u]+graph[u][i];
    					predecessor[i]=u;
    				}
    			}
    		}
    	}
    }
    for(i=1;i<=num_of_vertices;i++){
    	printpath(source,i,predecessor);
    	if(pathestimate[i]!=INT_MAX){
    		printf("->(%d)\n",pathestimate[i]);
    	}
    }
 return(0);
}

int minimum(int a[],int m[],int k){
	int mi=INT_MAX;
	int i,t;
	for(i=1;i<=k;i++){
		if(m[i]!=1){
			if(mi>=a[i]){
				mi=a[i];
				t=i;
			}
		}
	}
	return t;
}

void printpath(int x,int i,int p[]){
	printf("\n");
	if(i==x){
		printf("%d",x);
	}
	else if(p[i]==0)
		printf("no path from %d to %d",x,i);
	else{
		printpath(x,p[i],p);
		printf("..%d",i);
	}
}

/*
#include<stdio.h>

#define MAX 10

int cost[MAX][MAX], d[MAX], p[MAX], visited[MAX];
int n;

//struct dijkstra{
/*	void readmatrix();
	void shortpath(int);
	void display(int);
};/

void readmatrix(){
	int i, j;
	printf("Enter the number of vertices in the Graph : ");
	scanf("%d",&n);
	printf("\nEnter the Cost matrix of the Graph\n\n");
	for (i = 1; i <= n; i++){
		for (j = 1; j <= n; j++){
			scanf("%d",&cost[i][j]);
		}
	}
}

void shortpath(int src){
	int i, j, min, u, v;
	for (i = 1; i <= n; i++){
		d[i] = cost[src][i];
		visited[i] = 0;
		p[i] = src;
	}
	visited[src] = 1;
	for (i = 1; i <= n; i++){
		min = 999;
		u = 0;
		for (j = 1; j <= n; j++){
			if (!visited[j]){
				if (d[j] < min){
					min = d[j];
					u = j;
				}
			}
		}
		visited[u] = 1;
		for (v = 1; v <= n; v++){
			if (!visited[v] && (d[u] + cost[u][v] < d[v])){
				d[v] = d[u] + cost[u][v];
				p[v] = u;
			}
		}
	}
}

void display(int src){
	int i, k, parent;
	for (i = 1; i <= n; i++){
		if (i == src)
			continue;
		printf("\nThe Shortest Path from %d to %d is ",src,i);
		k = i;
		printf("%d -",k);
		while (p[k] != src){
			printf("%d -",p[k]);
			k = p[k];
		}
		printf("%d",src);
		printf(" and the cost is : %d ",d[i]);
	}
}

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int source;
//	dijkstra dij;
	readmatrix();
	printf("\nEnter the Source : ");
	scanf("%d",&source);
	shortpath(source);
	display(source);
	return 0;
}
*/
