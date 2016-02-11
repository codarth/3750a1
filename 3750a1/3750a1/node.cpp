#include "node.h"
#include <cmath>

Node::Node(){}

Node::Node(float x, float y, Node* parent, bool passable) :
   m_x(x), m_y(y), m_parent(parent),
   m_gcost(0), m_hcost(0), m_fvalue(0), m_passable(passable)
{
}

Node::~Node(){
}

// Calculate the H cost
float Node::manhattenDist(Node* nodeEnd) {
	float x = (float)(fabs((float)(this->m_x - nodeEnd->m_x)));
	float y = (float)(fabs((float)(this->m_y - nodeEnd->m_y)));
	return x + y;
}
