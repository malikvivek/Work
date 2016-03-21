/*
 * prims.c
 *
 *  Created on: 25-Apr-2012
 *      Author: vivek
 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX 10

int cost[MAX][MAX], tree[MAX][MAX];
int n;

void readmatrix();
int spanningtree(int);
void display(int);


int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int source, treecost;
	readmatrix();
	printf("\nEnter the Source : ");
	scanf("%d",&source);
	treecost =spanningtree(source);
	display(treecost);
	return 0;
}

void readmatrix(){
	int i, j;
	printf("Enter the number of vertices in the Graph : ");
	scanf("%d",&n);
	printf("\nEnter the Cost matrix of the Graph\n");
	for (i = 1; i <= n; i++){
		for (j = 1; j <= n; j++){
			scanf("%d",&cost[i][j]);
		}
	}
}

int spanningtree(int src){
	int visited[MAX], d[MAX], parent[MAX];
	int i, j, k, min, u, v, stcost;
	for (i = 1; i <= n; i++){
		d[i] = cost[src][i];
		visited[i] = 0;
		parent[i] = src;
	}
	visited[src] = 1;
	stcost = 0;
	k = 1;
	for (i = 1; i < n; i++){
		min = 999;
		for (j = 1; j <= n; j++){
			if (!visited[j] && d[j] < min){
				min = d[j];
				u = j;
			}
		}
		visited[u] = 1;
		stcost = stcost + d[u];
		tree[k][1] = parent[u];
		tree[k++][2] = u;
		for (v = 1; v <= n; v++){
			if (!visited[v] && (cost[u][v] < d[v])){
				d[v] = cost[u][v];
				parent[v] = u;
			}
		}
	}
	return (stcost);
}

void display(int cost){
	int i;
	printf("\nThe Edges of the Mininum Spanning Tree are\n\n");
	for (i = 1; i < n; i++){
		printf("%d  %d\n",tree[i][1],tree[i][2]);
	}
	printf("\nThe Total cost of the Minimum Spanning Tree is : %d",cost);
}
