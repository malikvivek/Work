/////////////////////////////////////////////////////////////////////////////////////
//Name 			: krushkal.c
//Copyright		: Copyright Vivek Malik,2012
//Created on	: 25-Apr-2012
//Author		: Vivek Malik
//Description 	: Finding Minimum Spanning tree using Krushkal algorithm
/////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX 100

//struct kruskal{

struct edge_info{
	int u, v, weight;
}edge[MAX];

int tree[MAX][2], set[MAX];
int n;
int readedges();
void makeset();
int find(int);
void join(int, int);
void arrange_edges(int);
int spanningtree(int);
void display(int);

int readedges(){
	int i, j, k, cost;
	k = 1;
	printf("Enter the number of Vertices in the Graph : ");
	scanf("%d",&n);
	printf("\n");
	for (i = 1; i <= n; i++){
		for (j = 1; j < i; j++){
			printf("weight[%d][%d] : ",j,i);
			scanf("%d",&cost);
			if (cost != 999){
				edge[k].u = i;
				edge[k].v = j;
				edge[k++].weight = cost;
			}
		}
	}
	return (k - 1);
}

void makeset(){
	int i;
	for (i = 1; i <= n; i++){
		set[i] = i;
	}
}

int find(int vertex){
	return (set[vertex]);
}

void join(int v1, int v2){
//	int i, j;
	if (v1 < v2){
		set[v2] = v1;
	}
	else{
		set[v1] = v2;
	}
}

void arrange_edges(int k)
{
	int i, j;
	struct edge_info temp;
	for (i = 1; i < k; i++)
		for (j = 1; j <= k - i; j++)
			if (edge[j].weight > edge[j + 1].weight)
			{
				temp = edge[j];
				edge[j] = edge[j + 1];
				edge[j + 1] = temp;
			}
}

int spanningtree(int k){
	int i, t, sum;
	arrange_edges(k);
	t = 1;
	sum = 0;
	for (i=1;i<=k;i++){
		printf("%d--%d :%d\n",edge[i].u,edge[i].v,edge[i].weight);
	}
//	cout<<edge[i].u<<edge[i].v<<" "<<edge[i].weight<<endl;
	for (i = 1; i <= k; i++){
		if (find (edge[i].u) != find (edge[i].v)){
			tree[t][1] = edge[i].u;
			tree[t][2] = edge[i].v;
			sum += edge[i].weight;
			join (edge[t].u, edge[t].v);
			t++;
		}
	}
	return sum;
}

void display(int cost)
{
	int  i;
	printf("\nThe Edges of the Minimum Spanning Tree are\n\n");
	for (i = 1; i < n; i++){
		printf("%d --- %d\n",tree[i][1],tree[i][2]);
	}
//		cout << tree[i][1] << " - " << tree[i][2] << endl;
	printf("\nThe Cost of the Minimum Spanning Tree is : %d",cost);
}

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int ecount, totalcost;
//	struct kruskal k;
	ecount = readedges();
	makeset();
	totalcost = spanningtree(ecount);
	display(totalcost);
	return 0;
}
