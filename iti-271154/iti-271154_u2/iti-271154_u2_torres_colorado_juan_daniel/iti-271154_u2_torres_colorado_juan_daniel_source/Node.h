#include <QColor>
#include <deque>

class Node {
private:
	int x;
	int y;
	int valor;
public:
	Node(int, int, int);
	std::deque<Node*> aristas;
	int getX() const, getY() const, getValor() const;
	bool operator==(const Node& other) const;
	QColor color;
};

