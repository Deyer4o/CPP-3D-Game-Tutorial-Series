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








	
	
	
	
	
	
	
	





	



	//Custom approach:


	//Adding Pathfinder 
	DPathfinder pathfinder;
	
	std::vector<Node> nodeArray;
	//Node_ID = 0;
	float z = -300.0f;
	float dZ = 0.0f;
	nodeArray.push_back(Node(0.0f, 0.0f, z));		//0
	z += dZ;
	nodeArray.push_back(Node(0.0f, 200.0f, z));		//1
	z += dZ;
	nodeArray.push_back(Node(200.0f, 300.0f, z));	//2
	z += dZ;
	nodeArray.push_back(Node(600.0f, 0.0f, z));		//3
	z += dZ;
	nodeArray.push_back(Node(300.0f, 500.0f, z));	//4
	z += dZ;
	nodeArray.push_back(Node(1000.0f, 0.0f, z));	//5
	z += dZ;
	nodeArray.push_back(Node(1000.0f, 400.0f, z));	//6
	z += dZ;
	nodeArray.push_back(Node(1000.0f, 500.0f, z));	//7
	z += dZ;
	nodeArray.push_back(Node(400.0f, 800.0f, z));	//8
	z += dZ;
	nodeArray.push_back(Node(600.0f, 800.0f, z));	//9
	z += dZ;
	nodeArray.push_back(Node(750.0f, 430.0f, z));	//10
	z += dZ;
	
	pathfinder.makeNodes(nodeArray);


	pathfinder.NodesArray[3].addMultipleNeighbours(pathfinder.NodesArray, { 4, 5, 8 });
	pathfinder.NodesArray[0].addMultipleNeighbours(pathfinder.NodesArray, { 1, 5, 2 });
	pathfinder.NodesArray[2].addMultipleNeighbours(pathfinder.NodesArray, { 4, 1 });
	pathfinder.NodesArray[8].addMultipleNeighbours(pathfinder.NodesArray, { 9, 4 });
	pathfinder.NodesArray[10].addMultipleNeighbours(pathfinder.NodesArray, { 3, 9, 7, 6});
	pathfinder.NodesArray[7].addMultipleNeighbours(pathfinder.NodesArray, { 6, 9 });
	pathfinder.NodesArray[5].addMultipleNeighbours(pathfinder.NodesArray, { 6 });


	
	//nodeArray[3].printNeighbours();
	pathfinder.NodesArray[4].printNeighbours();

	pathfinder.print();

	std::vector<int> testNeighbours = { };
	std::vector<int> testPurple = {   };
	std::vector<int> testGreen = {   };

	for (int t : testNeighbours)
	{
		int dist = 100;
		pathfinder.NodesArray[t].printNeighbours();
		MakeSphere(pathfinder.NodesArray[t].location + CXVec3(0, 0, dist), 30.0f, matRed);
		for (Node* f : pathfinder.NodesArray[t].NodeNeighbours)
		{
			MakeLine(pathfinder.NodesArray[t].location + CXVec3(0, 0, dist), f->location + CXVec3(0, 0, dist), 5.0f, matPink);
		};
	}

	
	
	for (int t : testPurple)
	{
		MakeSphere(pathfinder.NodesArray[t].location + CXVec3(0, 0, -80), 30.0f, matPurple);
	}
	for (int t : testGreen)
	{
		MakeSphere(pathfinder.NodesArray[t].location + CXVec3(0, 0, -80), 30.0f, matGreen);
	}
	

	for (Node n : pathfinder.NodesArray) 
	{
		
		//if(n.ID <= lastmatNum && n.ID >= 0)MakeSphere(n.location, 30.0f, matNumbers[n.ID]);
		sceneNumber(n.location, n.ID, 30.0f);
		sceneNumber(n.location - CXVec3(30,-30,0), n.value, 10.0f);
		for (Node* f : pathfinder.NodesArray[n.ID].NodeNeighbours)
		{
			MakeLine(pathfinder.NodesArray[n.ID].location, f->location, 2.0f, matRed);
		};
	}

	

	//MakeLine(pathfinder.NodesArray[3].location, pathfinder.NodesArray[8].location, 5.0f, matRed);
	// 

	//DrawPathsToNeighbours(&pathfinder.NodesArray[3], 5.0f, matPurple);


	// Array approach:

	//int ArraySize = 5;
	//CXVec3 ArrayPosition = CXVec3(0.0f, 0.0f, 400.0f);
	//int NodesDistance = 100;
	//float ArrayScale = 10.0f;
	//
	//{
	//	srand((unsigned int)time(NULL));

	//	
	//	for (int y = 0; y < ArraySize; y++)
	//	for (int x = 0; x < ArraySize; x++)
	//	for (int z = 0; z < ArraySize; z++)
	//	{
	//		
	//		//auto entity = createEntity<CXMeshEntity>();
	//		//entity->setMesh(mesh);
	//		//entity->addMaterial(mat);
	//		//
	//		//entity->setPosition(CXVec3((rand() % 4000) + (-2000.0f), (rand() % 4000) + (-2000.0f), (rand() % 4000) + (-2000.0f)));
	//		//entity->setRotation(CXVec3((rand() % 628) / 100.0f, (rand() % 628) / 100.0f, (rand() % 628) / 100.0f));
	//		//float scale = rand() % 20 + (1.0f);
	//		//entity->setScale(CXVec3(scale, scale, scale));

	//		auto test_entity = createEntity<CXMeshEntity>();
	//		test_entity->setMesh(mesh_sphere);
	//		test_entity->addMaterial(mat);

	//		Node currentNode(CXVec3(x * NodesDistance + ArrayPosition.x, y * NodesDistance + ArrayPosition.y,z * NodesDistance + ArrayPosition.z),x + ArraySize * y);
	//		pathfinder.addNode(currentNode);

	//		test_entity->setPosition(currentNode.location);
	//		test_entity->setRotation(CXVec3(1.0f,1.0f,1.0f));
	//		
	//		test_entity->setScale(CXVec3(ArrayScale, ArrayScale, ArrayScale));
	//		
	//	}
	//}



	//pathfinder.print();





















	
	
	//Enable Play Mode - Cursor locked at the center of screen and invisible
	getInputManager()->enablePlayMode(m_input);
}


void SpaceShooterGame::onUpdate(f32 deltaTime)
{
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
