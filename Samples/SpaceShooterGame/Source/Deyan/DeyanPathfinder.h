#pragma once
#include <vector>
#include <iostream>
#include <CX3D/All.h>

constexpr long long int INF = 999999999;

class Node
{
public:
	Node() 
	{
		location = CXVec3(0.0f, 0.0f, 0.0f);
		value = INF;
		std::cout << "TEST: " << value << std::endl;
		
	};
	Node(CXVec3 _location, long long int _value)
	{
		location = _location;
		value = _value;

	};
	~Node() 
	{
		
	};

	CXVec3 location;
	long long int value;
	std::vector<Node> NodeNeighbours;
};

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


	std::vector<Node> NodesArray;

private:

};



