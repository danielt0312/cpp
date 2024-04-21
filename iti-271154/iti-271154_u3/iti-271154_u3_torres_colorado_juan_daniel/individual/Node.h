#include <QColor>
#include <deque>

#include <string>

class Node {
private:
	int x;
	int y;
	int valor;
public:
	Node(int, int, int);
	std::deque<Node*> transiciones;
	std::deque<std::string> input, pop, push;
	int getX() const, getY() const, getValor() const;
	bool operator==(const Node& other) const;
	QColor color;
	bool finalState = false;
};

