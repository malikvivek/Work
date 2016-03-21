//////////////////////////////////////////////////////////////////////////////////////
//Name 			:bfs.c
//Copyright 	:Copyright Vivek Malik,2012
//Created on	:19-Apr-2012
//Author		:Vivek Malik
//Description 	:To traverse a graph using BFS algorithm
//////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<iostream>
#include<queue>

using namespace std;

int nodes, edges, src;
int graph[100][100], color[100];
const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

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
		graph[y][x]=1;
	}
	printf("\nThe BFS Order is : \t");
	//run BFS
	queue<int> q;           //create a queue
	q.push(src);            //1. put root node on the queue
	do {
		int u = q.front();  //2. pull a node from the beginning of the queue
		q.pop();
		printf("%d\t", u);   //print the node
		for (int i = 1; i <= nodes; i++) {  //4. get all the adjacent nodes
			if ((graph[u][i] == 1)  //if an edge exists between these two nodes,
					&& (color[i] == WHITE)) {   //and this adjacent node is still WHITE,
				q.push(i);                  //4. push this node into the queue
				color[i] = GRAY;            //color this adjacent node with GRAY
			}
		}
		color[u] = BLACK;   //color the current node black to mark it as dequeued
	} while (!q.empty());   //5. if the queue is empty, then all the nodes have been visited*/

	return(0);
}
