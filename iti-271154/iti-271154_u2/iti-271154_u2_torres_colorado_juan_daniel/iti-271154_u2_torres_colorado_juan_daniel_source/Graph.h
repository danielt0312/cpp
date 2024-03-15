#include <deque>

class Graph {
private:
	int x;
	int y;
	int valor;
public:
	Graph(int, int, int);
	std::deque<Graph> vertices;
	int getX() const, getY() const, getValor() const;
	bool operator==(const Graph& other) const;
};

