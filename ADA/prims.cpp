#include <iostream>

using namespace std;

void getMinimum(int *res,int *graph,int *visited,int edge,int n){
	res[0] = -1;
	res[1] = 100000;
	int node = 0;
	int cost = 1;
	for(int i=0;i<n;i++){
			if(visited[i] == 0){
				if(res[cost] > graph[i]){
					res[cost] = graph[i];
					res[node] = i;
				}
			}
		}
}
int allvisited(int *visited,int n){
	for(int i=0;i<n;i++){
		if(visited[i] == 0)
			return 1;
	}
	return 0;
}
int main(){
	int n,*res,node=0,cost=1;
	res = new int[2];
	cout<<"\nEnter the number of nodes: ";
	cin>>n;
	int graph[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			graph[i][j] = -1;
		}
	}

	int visited[n] = {0};
	int path[n] = {-1};
	
	cout<<"\nEnter the distances: ";
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i == j){
				graph[i][i] = 1000000;
			}
			else if(graph[i][j] == -1){
				cout<<"Node "<<i+1<<" to Node "<<j+1<<": ";
				cin>>graph[i][j];
				graph[i][j] = (graph[i][j] < 1)?1000000:graph[i][j];
				graph[j][i] = graph[i][j];
			}
		}
	}

	int edge1=0,edge2,*temp;
	temp = new int[2];
	int mycost = 0;
	getMinimum(res,graph[edge1],visited,edge1,n);
	edge2 = res[node];
	visited[edge1] = 1;
	visited[edge2] = 1;
	mycost = res[cost];
	path[edge1] = edge2;
	int sum=edge2;
	
	while(allvisited(visited,n) != 0){
		getMinimum(res,graph[edge1],visited,edge1,n);
		getMinimum(temp,graph[edge2],visited,edge2,n);
		if(res[cost] > temp[cost]){
			sum = sum + temp[node];
			path[edge2] = temp[node];
			mycost = mycost + temp[cost];
			edge2 = temp[node];
			visited[edge2] = 1;
		}
		else if(res[node] != -1){
			sum = sum + res[node];
			path[edge1] = res[node];
			mycost = mycost + res[cost];
			edge1 = res[node];
			visited[edge1] = 1;
		}
	}
	cout<<"\nSolution Cost "<<mycost<<endl<<"Path is: ";
	int head = n*(n-1)/2 - sum;
	int i = head;
	while(path[i] != head){
		cout<<i+1<<" -> ";
		i = path[i];
	}
	cout<<"-1\n";
	return 0;
}