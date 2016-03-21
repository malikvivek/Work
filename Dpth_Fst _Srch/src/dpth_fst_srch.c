//////////////////////////////////////////////////////////////////////////////////////
//Name 			:topological_sort.c
//Copyright 	:Copyright Vivek Malik,2012
//Created on	:19-Apr-2012
//Author		:Vivek Malik
//Description 	:To sort a graph using topological sort algorithm
//////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>

int nodes, edges, src;
int graph[100][100], color[100];
const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;
int time=1;
int start_time[100], finish_time[100];
int top_sort[100];

void dfs(int);

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int x,y,i;
	printf("Nodes 	:");
	scanf("%d",&nodes);
	printf("Edges 	:");
	scanf("%d",&edges);
	printf("Source 	:");
	scanf("%d",&src);
	for(i=0;i<edges;i++){
		printf("Edge %d	:",(i+1));
		scanf("%d%d",&x,&y);
		graph[x][y]=1;
//		graph[y][x]=1;
	}
	for(i=1;i<=nodes;i++){
		color[i]=WHITE;
	}
	printf("\nThe DFS order is 	:\t");
	dfs(src);
	printf("\n\nNodes 			:\t");
	for(i=1;i<=nodes;i++){
		printf("%d\t",i);
	}
	printf("\nStart Time 		:\t");
	for(i=1;i<=nodes;i++){
		printf("%d\t", start_time[i]);
	}
	printf("\nFinish Time 		:\t");
	for(i=1;i<=nodes;i++){
		printf("%d\t", finish_time[i]);
	}
	printf("\nTopplogical Sort 	:\t");
	for(i=nodes;i>=1;i--){
		printf("%d\t", top_sort[i]);
	}
	return(0);
}

void dfs(int node){
	int i;
	static int j = 1;
	start_time[node]=time;
	time=time+1;
	color[node]=GRAY;
	printf("%d\t", node);		// i=nodes;i>=1;i-- --> Preorder traversal
	for(i=nodes;i>=1;i--){		// i=1;i<=nodes;i++  --> Postorder traversal
		if ((graph[node][i] == 1) && (color[i] == WHITE)){
			dfs(i);
		}
	}
	finish_time[node]=time;
	top_sort[j]=node;
	j++;
	time=time+1;
}
