#ifndef NODE_H
#define NODE_H

class Node
{
public:
	Node();
	Node(float x, float y, Node* parent, bool passable);
	~Node();

	// Getters
	int getF() { return m_gcost + m_hcost; }
	float getX() { return m_x; }
	float getY() { return m_y; }
	float getG() { return m_gcost; }
	float getH() { return m_hcost; }
	Node* getParent() { return m_parent; }
	bool getPass() { return m_passable; }

	// Setters
	void setX(float x) { m_x = x; }
	void setY(float y) { m_y = y; }
	void setG(float g) { m_gcost = g; }
	void setH(float h) { m_hcost = h; }
	void setParent(Node* parent) { m_parent = parent; }
	void setPass(bool pass) { m_passable = pass; }

	// Calculate the H cost
	float manhattenDist(Node* nodeEnd);

private:
	float m_x, m_y;
	Node* m_parent;
	float m_gcost, m_hcost;
	int m_fvalue;
	bool m_passable;



};

#endif
