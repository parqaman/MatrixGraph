#pragma once
#include <iostream>
#include "Vertex.h"

template<typename T, int maxNodes>
class Graph
{
public:
	Graph();
	void addVertex(int key, T data);
	void addEdge(int from, int to, int weight);
	void print();
	void dijkstra(int sourceKey);

	Graph& operator=(const Graph& g) {
		if (this->size != g.size) {
			std::cout << "Size of graphs differ\n";
			return *this;
		}

		for (int i = 0; i < maxNodes; i++) {
			delete this->vertices[i];
			this->vertices[i] = g.vertices[i];
			for (int j = 0; j < maxNodes; j++) {
				this->edges[i][j] = g.edges[i][j];
			}
		}
		return *this;
	}



private:
	int getMinimumDistance(int distances[]);
	void resetToFalse();

private:
	void printDijkstra(int distances[]);
	int size = maxNodes;
	Vertex<T>* vertices[maxNodes];
	int edges[maxNodes][maxNodes];
};

template<typename T, int maxNodes>
Graph<T, maxNodes>::Graph()
{
	for (int i = 0; i < maxNodes; i++) {
		vertices[i] = nullptr;
		for(int j = 0; j < maxNodes; j++){
			edges[i][j] = 0;
		}
	}
}

template<typename T, int maxNodes>
inline void Graph<T, maxNodes>::addVertex(int key, T data)
{
	if (key >= maxNodes) return;
	Vertex<T>* newVertex = new Vertex<T>(data);
	vertices[key] = newVertex;
}

template<typename T, int maxNodes>
inline void Graph<T, maxNodes>::addEdge(int from, int to, int weight)
{
	if (from >= maxNodes || to >= maxNodes || weight <= 0) return;

	edges[from][to] = weight;
	edges[to][from] = weight;
}

template<typename T, int maxNodes>
inline void Graph<T, maxNodes>::print()
{
	std::cout << "Adjazenzmatrix\n";
	std::cout << "\t";

	for (int i = 0; i < maxNodes; i++) {
		std::cout << i << "\t";
	}
	std::cout << std::endl;
	for (int i = 0; i < maxNodes; i++) {
		std::cout << "========";
	}
	std::cout << "==" << std::endl;
	for (int i = 0; i < maxNodes; i++) {
		std::cout << i << " |" << "\t";
		for (int j = 0; j < maxNodes; j++) {
			std::cout << edges[i][j] << "\t";
		}
		std::cout << "\n";
	}
}

template<typename T, int maxNodes>
inline int Graph<T, maxNodes>::getMinimumDistance(int distances[])
{
	int min = INT_MAX;
	int min_index;

	for (int v = 0; v < maxNodes; v++) {
		if (vertices[v]->getVisited() == false && distances[v] <= min){
			min = distances[v];
			min_index = v;
		}
	}

	return min_index;
}

template<typename T, int maxNodes>
inline void Graph<T, maxNodes>::dijkstra(int startkey)
{
	if (startkey >= maxNodes) throw std::string("Flughafen nicht gefunden");
	resetToFalse();
	int distances[maxNodes];

	for (int i = 0; i < maxNodes; i++) {
		distances[i] = INT_MAX;
	}

	distances[startkey] = 0;

	for (int i = 0; i < maxNodes - 1; i++) {
		int min = getMinimumDistance(distances);
		vertices[min]->setVisited(true);

		for (int j = 0; j < maxNodes; j++) {
			if (vertices[j]->getVisited() == false && edges[min][j] && distances[min] != INT_MAX && distances[min] + edges[min][j] < distances[j]) {
				distances[j] = distances[min] + edges[min][j];
			}
		}
	}

	std::cout << "Vertex \t Distance from " << vertices[startkey]->getData() << std::endl;
	printDijkstra(distances);
}

template<typename T, int maxNodes>
inline void Graph<T, maxNodes>::printDijkstra(int distances[])
{
	for (int i = 0; i < maxNodes; i++)
		std::cout << vertices[i]->getData() << " \t\t" << distances[i] << std::endl;
}

template<typename T, int maxNodes>
inline void Graph<T, maxNodes>::resetToFalse()
{
	for (int i = 0; i < maxNodes; i++) {
		vertices[i]->setVisited(false);
	}
}

