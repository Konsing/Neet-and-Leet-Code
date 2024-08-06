#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// BFS
void BFS(int start, const vector<vector<int>>& adjList, vector<bool>& visited) {
	queue<int> q;
	q.push(start);
	visited[start] = true; // With BFS, we mark as true before while loop

	while(!q.empty()){
		int node = q.front();
		q.pop();

		for(auto n : adjList[node]){ // BFS needs the "visited[neighbor] = true;" in if statement
			if(!visited[n]){
				q.push(n);
				visited[n] = true;
			}
		}
	}
}