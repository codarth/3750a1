#include "astar.h"
#include <iostream>

AStar::AStar() {
}

AStar::~AStar()
{}

// Start of Calculations
void AStar::findPath() {
	// Clear all vectors
	for (unsigned int i = 0; i < m_openList.size(); i++) {
		delete m_openList[i];
	}
	m_openList.clear();
	for (unsigned int i = 0; i < m_visitedList.size(); i++) {
		delete m_visitedList[i];
	}
	m_visitedList.clear();
	for (unsigned int i = 0; i < m_goalPath.size(); i++) {
		delete m_goalPath[i];
	}
	m_goalPath.clear();

	// Build Coordinates
	buildlevel();

	// Init start node
	m_start->setG(0);
	m_start->setH(m_start->manhattenDist(m_goal));
	m_start->setParent(0);

	// Add start to openlist to get things going
	m_openList.push_back(m_start);

	// Main loop while looking for goal
	while (!m_foundGoal) {

		if (m_openList.empty()) {
			return;
		}

		// get next node with smallest f
		Node* currentNode = getNextNode();

		// Check if goal is found
		if (currentNode->getX() == m_goal->getX() &&
			currentNode->getY() == m_goal->getY()) {
			for (Node* getPath = currentNode; getPath != NULL; getPath = getPath->getParent()) {
				m_goalPath.push_back(getPath); // Create goal path
			}
			m_foundGoal = true;
		}
		else {
			// temp Node pointer
			Node* newNode = new Node(0, 0, 0, 0);

			// Check neighboring nodes
			// Right Node
			float x = currentNode->getX() + 1;
			float y = currentNode->getY();
			if (x < mapW && y < mapH && x >= 0 && y >= 0) {
				for (int i = 0; i < m_grid.size(); i++) {
					if (x == m_grid[i]->getX() && y == m_grid[i]->getY()) {
						newNode = m_grid[i];
						break;
					}
				}
				addNode(currentNode->getX() + 1, currentNode->getY(),
					currentNode->getG() + 1, currentNode, newNode);
			}
			// Left Node
			x = currentNode->getX() - 1;
			y = currentNode->getY();
			if (x < mapW && y < mapH && x >= 0 && y >= 0) {
				for (int i = 0; i < m_grid.size(); i++) {
					if (x == m_grid[i]->getX() && y == m_grid[i]->getY()) {
						newNode = m_grid[i];
						break;
					}
				}
				addNode(currentNode->getX() - 1, currentNode->getY(),
					currentNode->getG() + 1, currentNode, newNode);
			}
			// UP Node
			x = currentNode->getX();
			y = currentNode->getY() - 1;
			if (x < mapW && y < mapH && x >= 0 && y >= 0) {
				for (int i = 0; i < m_grid.size(); i++) {
					if (x == m_grid[i]->getX() && y == m_grid[i]->getY()) {
						newNode = m_grid[i];
						break;
					}
				}
				addNode(currentNode->getX(), currentNode->getY() - 1,
					currentNode->getG() + 1, currentNode, newNode);
			}
			// Down Node
			x = currentNode->getX();
			y = currentNode->getY() + 1;
			if (x < mapW && y < mapH && x >= 0 && y >= 0) {
				for (int i = 0; i < m_grid.size(); i++) {
					if (x == m_grid[i]->getX() && y == m_grid[i]->getY()) {
						newNode = m_grid[i];
						break;
					}
				}
				addNode(currentNode->getX(), currentNode->getY() + 1,
					currentNode->getG() + 1, currentNode, newNode);
			}
			// Right Up
			x = currentNode->getX() + 1;
			y = currentNode->getY() - 1;
			if (x < mapW && y < mapH && x >= 0 && y >= 0) {
				for (int i = 0; i < m_grid.size(); i++) {
					if (x == m_grid[i]->getX() && y == m_grid[i]->getY()) {
						newNode = m_grid[i];
						break;
					}
				}
				addNode(currentNode->getX() + 1, currentNode->getY() - 1,
					currentNode->getG() + 1.414, currentNode, newNode);
			}
			// Left Up
			x = currentNode->getX() - 1;
			y = currentNode->getY() - 1;
			if (x < mapW && y < mapH && x >= 0 && y >= 0) {
				for (int i = 0; i < m_grid.size(); i++) {
					if (x == m_grid[i]->getX() && y == m_grid[i]->getY()) {
						newNode = m_grid[i];
						break;
					}
				}
				addNode(currentNode->getX() - 1, currentNode->getY() - 1,
					currentNode->getG() + 1.414, currentNode, newNode);
			}
			// Right Down
			x = currentNode->getX() + 1;
			y = currentNode->getY() + 1;
			if (x < mapW && y < mapH && x >= 0 && y >= 0) {
				for (int i = 0; i < m_grid.size(); i++) {
					if (x == m_grid[i]->getX() && y == m_grid[i]->getY()) {
						newNode = m_grid[i];
						break;
					}
				}
				addNode(currentNode->getX() + 1, currentNode->getY() + 1,
					currentNode->getG() + 1.414, currentNode, newNode);
			}
			// Right Up
			x = currentNode->getX() + 1;
			y = currentNode->getY() - 1;
			if (x < mapW && y < mapH && x >= 0 && y >= 0) {
				for (int i = 0; i < m_grid.size(); i++) {
					if (x == m_grid[i]->getX() && y == m_grid[i]->getY()) {
						newNode = m_grid[i];
						break;
					}
				}
				addNode(currentNode->getX() + 1, currentNode->getY() - 1,
					currentNode->getG() + 1.414, currentNode, newNode);
			}


			for (int i = 0; i < m_openList.size(); i++) {
				if (currentNode == m_openList[i]) {
					m_openList.erase(m_openList.begin() + i);
				}
			}
		}
	}
}

// Establish Coordinates
void AStar::buildlevel() {
	for (int y = 0; y < mapH; y++) {
		std::cout << std::endl;
		for (int x = 0; x < mapW; x++) {
			switch (mapArray[y][x]) {
			case 0:
				std::cout << ".";
				m_grid.push_back(new Node(x, y, 0, true));
				break;
			case 1:
				std::cout << "#";
				m_grid.push_back(new Node(x, y, 0, false));
				break;
			case 5:
				std::cout << "S"; // set to Start Node
				m_grid.push_back(new Node(x, y, 0, true));
				m_start = m_grid.back();
				break;
			case 6:
				std::cout << "G"; // set to Goal Node
				m_grid.push_back(new Node(x, y, 0, true));
				m_goal = m_grid.back();
				break;
			}
		}
	}
	std::cout << "\nSearching for path to goal, please wait...\n\n";
}

// Calculate the next best node
Node* AStar::getNextNode() {
	float bestF = 99999.0f;
	int index = -1;
	Node* nextNode = NULL;

	for (int i = 0; i < m_openList.size(); i++) {
		if (m_openList[i]->getF() < bestF) {
			bestF = m_openList[i]->getF();
			index = i;
		}
	}

	if (index >= 0) {
		nextNode = m_openList[index];
		m_visitedList.push_back(nextNode);
		m_openList.erase(m_openList.begin() + index);
	}
	return nextNode;
}

// add node to open or visited list
void AStar::addNode(int x, int y, float newCost,
	Node* parent, Node* newNode) {
	if (!newNode->getPass()) {
		return;
	}

	// I had to use the x, y to compair nodes due to pointer issue (and out of time)
	Node* addNode = newNode;
	for (int i = 0; i < m_visitedList.size(); i++) { 
		if (addNode->getX() == m_visitedList[i]->getX()
			&& addNode->getY() == m_visitedList[i]->getY()) {
			return;
		}
	}

	// create temp node and establish it for the open list
	Node* newChild = new Node(x, y, parent, true);
	newChild->setG(newCost);
	newChild->setH(parent->manhattenDist(m_goal));
	for (int i = 0; i < m_openList.size(); i++) {
		if (addNode->getX() == m_openList[i]->getX() &&
			addNode->getY() == m_openList[i]->getY()) {
			float newF = newChild->getG() + newCost + m_openList[i]->getH();

			if (m_openList[i]->getF() > newF) {
				m_openList[i]->setG(newChild->getG() + newCost);
				m_openList[i]->setParent(newChild);
			}
			else {
				delete newChild;
				return;
			}
		}
	}
	m_openList.push_back(newChild);
}

