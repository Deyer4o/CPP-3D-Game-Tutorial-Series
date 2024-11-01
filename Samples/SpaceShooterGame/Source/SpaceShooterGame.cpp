/*MIT License

CX3D Game Framework (https://github.com/PardCode/CX3D)

Copyright (c) 2019-2024, PardCode

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.*/

#include "SpaceShooterGame.h"
#include "Spaceship.h"
#include "Deyan/DeyanPathfinder.h"
#include "Deyan/DPathfinder_Project_Specific.h"
#include <time.h>

//Adding Pathfinder 
DPathfinder pathfinder;

SpaceShooterGame::SpaceShooterGame()
{
	InitMats();
	InitNumMats();
}

SpaceShooterGame::~SpaceShooterGame()
{
}

void SpaceShooterGame::onCreate()
{
	setTitle(L"SpaceShooterGame");

	//Adding SkyBox
	/*{
		auto tex = createTexture(L"Assets/Textures/stars_map.jpg");
		auto mesh = createMesh(L"Assets/Meshes/sphere.obj");
		auto mat = createMaterial(L"Assets/Shaders/skybox.hlsl");
		mat->addTexture(tex);
		mat->setCullMode(CXCullMode::Front);

		auto entity = createEntity<CXMeshEntity>();
		entity->setMesh(mesh);
		entity->addMaterial(mat);
		entity->setScale(CXVec3(20000, 20000, 20000));
	}*/

	//Adding DLightEntity
	{
		auto entity = createEntity<CXLightEntity>();
		entity->setColor(CXVec3(1, 1, 1));
		entity->setRotation(CXVec3(-0.707f, 0.707f, 0));
		entity->setPosition(CXVec3(-20.0f, -20.0f, -808.0f));
	}
	//Adding DLightEntity
	//{
	//	auto entity = createEntity<CXLightEntity>();
	//	entity->setColor(CXVec3(1, 1, 1));
	//	entity->setRotation(CXVec3(30.707f, -0.707f, 0));
	//	entity->setPosition(CXVec3(-20.0f, -20.0f, -428.0f));
	//}
	//Adding DLightEntity
	{
		auto entity = createEntity<CXLightEntity>();
		entity->setColor(CXVec3(1, 1, 1));
		entity->setRotation(CXVec3(-0.707f, -50.707f, 0));
		entity->setPosition(CXVec3(-20.0f, -20.0f, -828.0f));
	}

	//Adding DLightEntity
	{
		auto entity = createEntity<CXLightEntity>();
		entity->setColor(CXVec3(1, 1, 1));
		entity->setRotation(CXVec3(0.707f, 110.707f, 0));
		entity->setPosition(CXVec3(-20.0f, -20.0f, -928.0f));
	}

	//Adding DLightEntity
	{
		auto entity = createEntity<CXLightEntity>();
		entity->setColor(CXVec3(1, 1, 1));
		entity->setRotation(CXVec3(45.707f, -0.707f, 0));
		entity->setPosition(CXVec3(-20.0f, -20.0f, -928.0f));
	}

	//Adding Spaceship

	auto Player = createEntity<Spaceship>();
	//Player = &entity;
	//Player->m_print = true;

	




	//auto mesh_sphere = createMesh(L"Assets/Meshes/sphere.obj");
	//auto tex = createTexture(L"Assets/Textures/blue.jpg");
	
	//auto mesh_cube = createMesh(L"Assets/Meshes/Cube.obj");
	//auto mat = createMaterial(L"Assets/Shaders/base.hlsl");
	//mat->addTexture(tex);








	
	
	
	
	
	
	
	





	


	////////////////////////////
	////		INPUTS		////
	////////////////////////////
	

	//Pathfinder is added in static space outside of this scope 
	//DPathfinder pathfinder;
	
	float z = -300.0f;
	pathfinder.NodesArray.push_back(Node(	0.0f,		0.0f,		z));	//0
	pathfinder.NodesArray.push_back(Node(	0.0f,		200.0f,		z));	//1
	pathfinder.NodesArray.push_back(Node(	200.0f,		300.0f,		z));	//2
	pathfinder.NodesArray.push_back(Node(	600.0f,		0.0f,		z));	//3
	pathfinder.NodesArray.push_back(Node(	300.0f,		500.0f,		z));	//4
	pathfinder.NodesArray.push_back(Node(	1000.0f,	0.0f,		z));	//5
	pathfinder.NodesArray.push_back(Node(	1000.0f,	400.0f,		z));	//6
	pathfinder.NodesArray.push_back(Node(	1000.0f,	500.0f,		z));	//7
	pathfinder.NodesArray.push_back(Node(	400.0f,		800.0f,		z));	//8
	pathfinder.NodesArray.push_back(Node(	600.0f,		800.0f,		z));	//9
	pathfinder.NodesArray.push_back(Node(	750.0f,		430.0f,		z));	//10

	pathfinder.NodesArray[3].addMultipleNeighbours(pathfinder.NodesArray, { 4, 5, 8, 0	});
	pathfinder.NodesArray[0].addMultipleNeighbours(pathfinder.NodesArray, { 1, 2		});
	pathfinder.NodesArray[2].addMultipleNeighbours(pathfinder.NodesArray, { 4, 1		});
	pathfinder.NodesArray[8].addMultipleNeighbours(pathfinder.NodesArray, { 9, 4		});
	pathfinder.NodesArray[10].addMultipleNeighbours(pathfinder.NodesArray,{ 3, 9, 7, 6	});
	pathfinder.NodesArray[7].addMultipleNeighbours(pathfinder.NodesArray, { 6, 9		});
	pathfinder.NodesArray[5].addMultipleNeighbours(pathfinder.NodesArray, { 6			});	

	std::vector<int> start_end =		{ 0, 7	}; //only 2 Node IDs 
	

	////////////////////////////////////
	////		Functionality		////
	////////////////////////////////////

	pathfinder.startNode = &pathfinder.NodesArray[start_end[0]];
	pathfinder.endNode = &pathfinder.NodesArray[start_end[1]];
	
	pathfinder.Start();
	pathfinder.CalculateNeighboursNodeCosts(pathfinder.currentlyLookingAt);
	//int endc = 0;
	while (!pathfinder.finished)
	{
		if (!pathfinder.currentlyLookingAt->fullyChecked) 
		{
			pathfinder.CalculateNeighboursNodeCosts(pathfinder.currentlyLookingAt);
			pathfinder.CalculateLowestFromUnlocked();
		}
		else 
		{
			pathfinder.CalculateLowestFromUnlocked();
		}
	}

	////////////////////////////
	////		DEBUG		////
	////////////////////////////

	std::vector<int> testNeighbours={		};
	std::vector<int> testPurple =	{ pathfinder.currentlyLookingAt->ID };
	std::vector<int> testGreen =	{		};
	std::vector<int> testRed = {		};
	//std::vector<int> endRoute = {		};
	
	for (Node* n : pathfinder.currentlyUnlocked) 
	{
		testGreen.push_back(n->ID);
	}
	for (Node* n : pathfinder.currentlyFullyChcked)
	{
		testRed.push_back(n->ID);
	}

	//nodeArray[3].printNeighbours();
	//pathfinder.NodesArray[4].printNeighbours();
	//pathfinder.printNeighbours();

	print("----------shortest path:----------");
	print(pathfinder.shortestEndPath);



	if(pathfinder.shortestEndPath.size() > 0)
	for (int i = 0; i < pathfinder.shortestEndPath.size() - 1 ; i++)
	{
		int dist = 50;
		MakeLine(pathfinder.shortestEndPath[i]->location + Vec3(0, 0, dist), pathfinder.shortestEndPath[i+1]->location + Vec3(0, 0, dist), 5.0f, matGreen);
	}

	int offset = -30;
	for (int y = -1; y <= 1; y++)
	for (int x = -1; x <= 1; x++)
	{
		MakeSphere(pathfinder.startNode->location + Vec3(offset * x, offset * y, offset), 30.0f, matGreen);
		MakeSphere(pathfinder.endNode->location + Vec3(offset * x, offset * y, offset), 30.0f, matRed);
	}

	for (int t : testNeighbours)
	{
		int dist = 100;
		pathfinder.NodesArray[t].printNeighbours();
		MakeSphere(pathfinder.NodesArray[t].location + Vec3(0, 0, dist), 30.0f, matRed);
		for (Node* f : pathfinder.NodesArray[t].NodeNeighbours)
		{
			MakeLine(pathfinder.NodesArray[t].location + Vec3(0, 0, dist), f->location + Vec3(0, 0, dist), 5.0f, matPink);
		};
	}
	
	for (int t : testPurple)
	{
		MakeSphere(pathfinder.NodesArray[t].location + Vec3(0, 0, -80), 30.0f, matPurple);
	}
	for (int t : testGreen)
	{
		MakeSphere(pathfinder.NodesArray[t].location + Vec3(0, 0, -80), 30.0f, matGreen);
	}
	for (int t : testRed)
	{
		MakeSphere(pathfinder.NodesArray[t].location + Vec3(0, 0, -80), 30.0f, matRed);
	}
	
	for (Node n : pathfinder.NodesArray) 
	{
		
		//if(n.ID <= lastmatNum && n.ID >= 0)MakeSphere(n.location, 30.0f, matNumbers[n.ID]);
		printNumberInScene(n.location, n.ID, 30.0f);
		int offset = 40;
		if (n.ID >= 10) offset = 90;
		printNumberInScene(n.location - Vec3(offset, -30	 -15, 0), n.Gcost, 10.0f);
		printNumberInScene(n.location - Vec3(offset, 0	 -15, 0), n.Hcost, 10.0f);
		printNumberInScene(n.location - Vec3(offset, 30 -15, 0), n.Fcost, 10.0f);
		for (Node* f : pathfinder.NodesArray[n.ID].NodeNeighbours)
		{
			MakeLine(pathfinder.NodesArray[n.ID].location, f->location, 2.0f, matRed);
		};
	}


	

	//Enable Play Mode - Cursor locked at the center of screen and invisible
	getInputManager()->enablePlayMode(m_input);
}

f32 timerf32 = 0;
void SpaceShooterGame::onUpdate(f32 deltaTime)
{
	//timerf32 += deltaTime;
	//double timer = timerf32;
	//std::cout << timer << std::endl;

	
	

	if(getInputManager()->isKeyUp(CXKey::Escape))
	{
		m_input = !m_input;
		getInputManager()->enablePlayMode(m_input);
	}
	
	//entholder[1]->setPosition(entholder[1]->getPosition()+CXVec3(1,0,0));
}

void SpaceShooterGame::onQuit()
{
}
