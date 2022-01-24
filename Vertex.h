#pragma once

template<typename T>
class Vertex
{
public:
	Vertex(T _data);
	T getData();
	bool getVisited() const;
	void setVisited(bool flag);

private:
	T data;
	bool visited = false;
};

template<typename T>
inline Vertex<T>::Vertex(T _data)
	:
	data(_data)
{
}

template<typename T>
inline T Vertex<T>::getData()
{
	return data;
}

template<typename T>
inline bool Vertex<T>::getVisited() const
{
	return visited;
}

template<typename T>
inline void Vertex<T>::setVisited(bool flag)
{
	visited = flag;
}
