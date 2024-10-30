//Made by Deyan Mohamed
//Single Header file 2D/3D Pathfinder

#pragma once
#include <vector>
#include <iostream>
#include <CX3D/All.h>

constexpr long long int INF = 999999999; //used instead of infinity - needs to be bigger than the biggest unit for the algorithm to work
int Node_ID = 0; //this makes all Nodes unique - keep in mind, every time a constructor is called this increments by 1


//Nodes are the intersection points for the pathfinding algorithm
class Node
{
public:

	//Default Constructor
	Node() 
	{
		location = CXVec3(0.0f, 0.0f, 0.0f);
		value = INF;
		ID = Node_ID;
		Node_ID++;

	};

	//Constructor with location <CXVec3>
	Node(CXVec3 _location)
	{
		location = _location;
		value = INF;
		ID = Node_ID;
		Node_ID++;

	};

	//Constructor with location <CXVec3> and value <long long>
	Node(CXVec3 _location, long long int _value)
	{
		location = _location;
		value = _value;
		ID = Node_ID;
		Node_ID++;

	};

	//Constructor with location <float> (x, y, z)
	Node(float _x, float _y, float _z)
	{
		location = CXVec3(_x,_y,_z);
		value = INF;
		ID = Node_ID;
		Node_ID++;

	};

	//Default Destructor
	~Node() 
	{
		
	};

	//Debug print to console (ID, value, location)
	void print() 
	{
		std::cout << "Node " << ID << ": value = " << value << ": location = X:" << location.x << " Y:" << location.y << " Z:" << location.z << std::endl;
	};

	//Debug print of Node and Neighbours to console (ID, value, location)
	void printNeighbours()
	{
		//print();
		std::cout << "----------Node " << this->ID << " Neighbours list : ----------" << std::endl;
		for (Node itNode : NodeNeighbours) 
		{
			itNode.print();
		}
		std::cout << "---------------------------------------------" << std::endl;
	};

	//If _node is not a neighbour, add it to the neighbours list (NodeNeighbours) 
	void addNeighbour(Node &_node) 
	{
		short test_hits = 0;
		for (Node itNode : NodeNeighbours) //iterate through array
		{
			if (itNode.ID == _node.ID) //check for same ID
			{
				test_hits++; //if test hits, iterate the temporary int and break the "for each" loop
				break;
			}
		};
		if (test_hits == 0) //if test doesn't hit
		{
			NodeNeighbours.push_back(_node); //add the node to neighbour vector array
			_node.addNeighbours({ *this }); //performs the same action but from the opposite Node /////////////////////THIS DOESN"T WORKKKKK????
		}
		else {
			//std::cout << "addNeighbour() ERROR - element already in the array!" << std::endl; //error message
		}

	};

	//Performs addNeighbour() on a vector Array of Nodes
	void addNeighbours(std::vector<Node> _nodes)
	{
		for (Node& currentNode : _nodes)
		{
			addNeighbour(currentNode);
		};
	};

	//Unique Node ID (0,1,2...)
	int ID;

	//Node 3D location (for 2D, just ignore Z)
	CXVec3 location;
	//value of
	long long int value;
	std::vector<Node> NodeNeighbours;

private:
	long long int valueToGoal = INF; //used for A* pathfinder addition on top of Dijkstra
	bool FULLY_CHECKED = false; //used for the pathfinding algorithm - flags if all neighbours have already been checked
};
//end of Node class



//DeyanPathfinder is holding the main functionality of the pathfinder
class DeyanPathfinder
{
public:
	DeyanPathfinder()
	{
		
	};

	DeyanPathfinder(const int Size)
	{
		for (int i = 0; i < Size; i++)
		{
			Node CurrentNode;
			NodesArray.push_back(CurrentNode);
		}
	};

	~DeyanPathfinder()
	{

	};

	void print() 
	{
		if (NodesArray.size() > 0)
			for (Node member : NodesArray)
			{
				member.print();
			}
		else
		{
			std::cout << "Nodes Array is Empty" << std::endl;
		};
	}

	void addNode(Node& _node)
	{
		NodesArray.push_back(_node);
	};

	std::vector<Node> NodesArray;

private:

};
//end of DeyanPathfinder class




//Debug and other helping fuctions

void MakeNeighbours(std::vector<Node> _nodes) // THIS DOESN"T CURRENTLY WORK!!!
{
	for (Node itNode : _nodes)
	{
		itNode.addNeighbours(_nodes);
	};
};

//Debug print to console <const char*>
void print(const char* _string) {
	std::cout << _string << std::endl;
};

//Debug print to console <int>
void print(int _int) {
	std::cout << _int << std::endl;
};

//Debug print to console <Node>
void print(Node& _node) {
	_node.print();
};


//ToDO:
//- Add randomizer for ease of use / testing
//- Add connection function
//- Add a way to bulk add nodes and connections (or random 2d/3d?)
//- Add the dijkstra algorithm as an option
//- Add the A* algorithm as an option
//- Fix Error with neighbours!!!!!!!
