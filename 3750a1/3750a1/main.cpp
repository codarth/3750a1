#include "astar.h"
#include "node.h"
#include <iostream>

int main() {
	// Main object
	AStar pathstart;
	pathstart.findPath(); // Calculate the Path

	std::vector<Node*> goalPath = pathstart.getGoalPath(); // Get the path vector to the goal

	std::cout << "\n\nPath To Goal:\n";

	// Print Path to goal
	for (int i = goalPath.size(); i--; 0) {
		std::cout << " x: " << goalPath[i]->getX() <<
			" y: " << goalPath[i]->getY() << std::endl;
	}

	std::cout << "GOAL!\n\n";
	// To Be Deleted... not needed for linux
	//char a;
	//std::cout << "\n Goal!!\n\npress a key to exit!";
	//std::cin >> a;

	return 0;
}

