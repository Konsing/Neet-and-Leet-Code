#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// DFS

void DFS(int start, const vector<vector<int>>& adjList, vector<bool>& visited) {
	stack<int> s;
	s.push(start);

	while(!s.empty()){
		int node = s.top();
		s.pop();

		if(!visited[node]){ // DFS needs this check
			visited[node] = true;
		}

		for(auto n : adjList[node]){ // DFS doesn't need the "visited[neighbor] = true;" in the if statement
			if(!visited[n]){
				s.push(n);
			}
		}
	}
}