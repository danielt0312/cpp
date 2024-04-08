#include <QColor>
#include <vector>

class Node {
private:
	int x;
	int y;
	int valor;
public:
	Node(int, int, int);
	std::vector<Node*> transiciones;
	int getX() const, getY() const, getValor() const;
	bool operator==(const Node& other) const;
	QColor color;
};

