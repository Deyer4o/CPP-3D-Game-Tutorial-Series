//Made by Deyan Mohamed
//Single Header file 2D/3D Pathfinder

#pragma once
#include <vector>
#include <iostream>
#include <CX3D/Math/CXVec3.h> //this can be swapped for any other simple Vec3 math lib
#define Vec3 CXVec3




////////////////////////////////////////////
////									////
////	Pathfinder Nodes functionality	////
////									////
////////////////////////////////////////////



constexpr long long int INF = 999999999; //used instead of infinity - needs to be bigger than the biggest unit for the algorithm to work
int Node_ID = 0; //this makes all Nodes unique - keep in mind, every time a Node constructor is called this increments by 1



//Nodes are the intersection points for the pathfinding algorithm
class Node
{
public:

	//Default Node Constructor
	Node() 
	{
		location = Vec3(0.0f, 0.0f, 0.0f);
		value = INF;
		AssignId();
	};

	//Node constructor with location <Vec3>
	Node(Vec3 _location)
	{
		location = _location;
		value = INF;
		AssignId();
	};

	//Node constructor with location <Vec3> and value <long long>
	Node(Vec3 _location, long long int _value)
	{
		location = _location;
		value = _value;
		AssignId();
	};

	//Node constructor with location <float> (x, y, z)
	Node(float _x, float _y, float _z)
	{
		location = Vec3(_x,_y,_z);
		value = INF;
		AssignId();
	};

	//Default Node Destructor
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
		std::cout << "----------Node [" << this->ID << "] Neighbours list : ----------" << std::endl;
		for (Node* itNode : NodeNeighbours) 
		{
			itNode->print();
		}
		std::cout << "---------------------------------------------" << std::endl;
	};

	//If _node is not a neighbour, add it to the neighbours list (NodeNeighbours) 
	void addNeighbour(Node *_node) 
	{
		//this needs to do 3 things
		//- check if it's trying to add itself
		//- if not then check if neighbour is already on the list
		//- if not add it to the list
		
		if (ID != _node->ID) //check if it's trying to add itself
		{
			if (NodeNeighbours.size() == 0)
			{
				//not on the list since list is empty, add to the list
				NodeNeighbours.push_back(_node);
			}
			else
			{
				//list is not empty, so go through every Node on the lsit and if there is no match, add to the list
				short matches = 0;
				for (Node* itNode : NodeNeighbours)
				{
					if (_node->ID == itNode->ID)
					{
						matches++;
					}
				}
				if (matches == 0) //there's no match
				{
					NodeNeighbours.push_back(_node);
				}
			}
		}

		//std::cout << "Size neighbours array of node[" << ID << "] is " << NodeNeighbours.size() << std::endl;
		//printNeighbours();
	};

	//Performs addNeighbour() on this Node for every _nodeArray[_indexArray] (also adds this Node as a neighbour to them)
	void addMultipleNeighbours(std::vector<Node>& _nodeArray, std::vector<int> _indexArray)
	{
		for (int i : _indexArray) {
			this->addNeighbour(&_nodeArray[i]);
			_nodeArray[i].addNeighbour(this);
		}
	};

	//Performs addNeighbour() on every Node in _nodeArray for every node in _nodeArray, including (this)
	void makeAllNeighbours(std::vector<Node> &_nodeArray, std::vector<int> _array)
	{

		_array.push_back(ID);

		for (int i : _array)
		for (int j : _array)
		{
			_nodeArray[i].addNeighbour(&_nodeArray[j]);
		}
	};



	//Unique Node ID (0,1,2...)
	int ID = -1;

	//Node 3D location (for 2D, just ignore Z)
	Vec3 location = Vec3();
	//value of
	long long int value = INF;
	std::vector<Node*> NodeNeighbours;

private:
	long long int valueToGoal = INF; //used for A* pathfinder addition on top of Dijkstra
	bool FULLY_CHECKED = false; //used for the pathfinding algorithm - flags if all neighbours have already been checked

	void AssignId() 
	{
		if (ID == -1)
		{
			ID = Node_ID;
			Node_ID++;
		}
	}
};
//end of Node class

//Makes all Nodes in _array neighbours with all other Nodes in _array
/*
void MakeAllNeighbours(std::vector<Node>& _nodeArray, std::vector<int> _array)
{
	for (int i : _array)
		for (int j : _array)
		{
			_nodeArray[i].addNeighbour(&_nodeArray[j]);
		}
};*/




////////////////////////////////////////////
////									////
////	Main Pathfinder functionality	////
////									////
////////////////////////////////////////////




//DeyanPathfinder is holding the main functionality of the pathfinder
class DPathfinder
{
public:

	//Default DPathfinder constructor
	DPathfinder()
	{
		
	};

	//DPathfinder constructor with default NodeArray of size _size
	DPathfinder(const int _size)
	{
		for (int i = 0; i < _size; i++)
		{
			Node CurrentNode;
			NodesArray.push_back(CurrentNode);
		}
	};

	//Default DPathfinder destructor
	~DPathfinder()
	{

	};

	//Prints NodesArray to console
	void print() 
	{
		std::cout << "------Printing Pathfinder NodesArray------" << std::endl;
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

	void printNeighbours()
	{
		std::cout << "------Printing ALL NEIGHBOURS from Pathfinder NodesArray------" << std::endl;
		if (NodesArray.size() > 0)
			for (Node member : NodesArray)
			{
				member.printNeighbours();
			}
		else
		{
			std::cout << "Nodes Array is Empty" << std::endl;
		};
	}

	//Adds _node to NodesArray
	void addNode(Node& _node)
	{
		NodesArray.push_back(_node);
	};

	void makeNodes(std::vector<Node> &_nodeArray)
	{
		for (Node n : _nodeArray)
		{
			addNode(n);
		}
	};
	
	std::vector<Node> NodesArray; //Holds all Nodes

	Node* startNode = nullptr;
	Node* endNode = nullptr;

private:

};
//end of DeyanPathfinder class



////////////////////////////////////////////////
////										////
////	Debug and other helping fuctions	////
////										////
////////////////////////////////////////////////


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
