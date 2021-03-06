#include "stdafx.h"
#include <iostream>
#include <set>
#include <vector>
#include <queue>

using namespace std;

template <typename T>
class Graph {
	vector<T> vertices;
	vector<vector<bool>> matrix;

	void DFS_util(T startVertex, set<T> &visited) {
		int getIndexOfStart = getIndex(startVertex);
		if (visited.count(startVertex)) return;

		visited.insert(startVertex);
		cout << startVertex << " ";

		for (auto adj : getAdjacentsOf(startVertex)) {
			DFS_util(adj, visited);
		}
	}
	bool hasPath_util(T startVertex, T endVertex, set<T> &visited) {
		if (startVertex == endVertex) return true;
		visited.insert(startVertex);
		for (auto adj : getAdjacentsOf(startVertex)) {
			if (visited.count(adj) == 0) {
				if (hasPath_util(adj, endVertex, visited)) {
					return true;
				}
			}
		}
		return false;
	}

public:
	Graph() : vertices(vector<T>()), matrix(vector<vector<bool>>()) {}
	unsigned int getIndex(T vertex) {
		for (size_t i = 0; i < vertices.size(); i++)
		{
			if (vertices[i] == vertex) return i;
		}
		return -1;
	}
	bool hasVertex(T vertexToCheck) {
		for (auto vertex : vertices) {
			if (vertex == vertexToCheck)
				return true;
		}
		return false;
	}
	bool hasEdge(T startVertex, T endVertex) {
		return matrix[getIndex(startVertex)][getIndex(endIndex)];
	}
	void addVertex(T vertex) {
		matrix.push_back(vector<bool>(vertices.size(), false));
		vertices.push_back(vertex);
		for (auto &row : matrix) {
			row.push_back(false);
		}
	}
	vector<T> getAdjacentsOf(T vertex) {
		vector<T> adjacents;
		for (size_t i = 0; i < matrix[getIndex(vertex)].size(); i++)
		{
			if (matrix[getIndex(vertex)][i]) {
				adjacents.push_back(vertices[i]);
			}
		}
		return adjacents;
	}
	void addEdge(T startVertex, T endVertex) {
		if (!hasVertex(startVertex)) {
			addVertex(startVertex);
		}
		if (!hasVertex(endVertex)) {
			addVertex(endVertex);
		}

		int indexOfStart = getIndex(startVertex);
		int indexOfEnd = getIndex(endVertex);

		matrix[indexOfStart][indexOfEnd] = true;
	}
	void removeEdge(T startVertex, T endVertex) {
		matrix[getIndex(startVertex)][getIndex(endVertex)] = false;
	}
	void removeVertex(T vertex) {
		int indexOfTheVictim = getIndex(vertex);
		typename vector<T> ::iterator victimAdress;
		matrix.erase(matrix.begin() + indexOfTheVictim, matrix.begin() + indexOfTheVictim + 1);
		for (victimAdress = vertices.begin(); victimAdress != vertices.end(); victimAdress++) {
			if (*victimAdress == vertex) break;
		}
		if (victimAdress == vertices.end()) return;
		vertices.erase(victimAdress, victimAdress + 1);

		for (auto &row : matrix) {
			row.erase(row.begin() + indexOfTheVictim, row.begin() + indexOfTheVictim + 1);
		}
	}

	void BFS(T startVertex) {
		set<T> visited;
		queue<T> que;

		que.push(startVertex);
		visited.insert(startVertex);

		while (!que.empty()) {
			T current = que.front();
			cout << current << " ";
			que.pop();

			for (auto adj : getAdjacentsOf(current)) {
				if (visited.count(adj) == 0) {
					visited.insert(adj);
					que.push(adj);
				}
			}
		}
	}
	void DFS(T startVertex) {
		set<T> visited;
		DFS_util(startVertex, visited);
	}

	bool isCyclic() {
		set<T> visited;
		T startVertex = vertices[0];

		queue<T> que;

		que.push(startVertex);
		visited.insert(startVertex);

		while (!que.empty()) {
			T current = que.front();
			que.pop();

			for (auto adj : getAdjacentsOf(current)) {

				if (visited.count(adj) == 0) {
					visited.insert(adj);
					que.push(adj);
				}
				else {
					return true;
				}
			}
		}
		return false;
	}
	bool hasPath(T startVertex, T endVertex) {
		if (!hasVertex(startVertex) || !hasVertex(endVertex)) return false;
		set<T> visited;
		return hasPath_util(startVertex, endVertex, visited);
	};
};

int main()
{
	Graph<int> myGraph;
	myGraph.addVertex(0);
	myGraph.addVertex(1);
	myGraph.addVertex(2);
	myGraph.addVertex(3);

	myGraph.addEdge(0, 1);
	myGraph.addEdge(0, 2);

	myGraph.addEdge(1, 2);

	myGraph.addEdge(2, 0);
	myGraph.addEdge(2, 3);

	myGraph.addEdge(3, 3);

	myGraph.BFS(0);
	cout << endl;
	myGraph.DFS(2);
	cout << endl;
	cout << myGraph.isCyclic() << endl;

	//myGraph.removeVertex(3);

	cout << myGraph.hasPath(1, 3) << endl;

	return 0;
}