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
#include <time.h>



SpaceShooterGame::SpaceShooterGame()
{
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
	}

	//Adding DLightEntity
	{
		auto entity = createEntity<CXLightEntity>();
		entity->setColor(CXVec3(1, 0, 0));
		entity->setRotation(CXVec3(0.707f, 0.707f, 0));
	}





















	auto tex = createTexture(L"Assets/Textures/orange.jpg");
	auto mesh_sphere = createMesh(L"Assets/Meshes/sphere.obj");
	//auto mesh_cube = createMesh(L"Assets/Meshes/Cube.obj");
	auto mat = createMaterial(L"Assets/Shaders/base.hlsl");
	mat->addTexture(tex);









	//Adding Pathfinding Array 
	DeyanPathfinder pathfinder;
	


	//Custom approach:

	std::vector<Node> nodeArray;
	//Node_ID = 0;

	nodeArray.push_back(Node(0.0f, 0.0f, 400.0f));
	nodeArray.push_back(Node(0.0f, 20.0f, 400.0f));
	nodeArray.push_back(Node(20.0f, 30.0f, 400.0f));
	nodeArray.push_back(Node(60.0f, 0.0f, 400.0f));
	nodeArray.push_back(Node(30.0f, 100.0f, 400.0f));
	nodeArray.push_back(Node(1000.0f, 0.0f, 400.0f));
	nodeArray.push_back(Node(100.0f, 40.0f, 400.0f));
	nodeArray.push_back(Node(100.0f, 50.0f, 400.0f));
	nodeArray.push_back(Node(40.0f, 20.0f, 400.0f));
	nodeArray.push_back(Node(60.0f, 80.0f, 400.0f));
	
	//nodeArray[3].addNeighbours({ nodeArray[4] , nodeArray[5] });
	//nodeArray[3].addNeighbours({ nodeArray[4] , nodeArray[5] });

	//nodeArray[3].addNeighbour(&nodeArray[4]);
	//nodeArray[3].addNeighbour(&nodeArray[5]);
	//nodeArray[3].addNeighbour(&nodeArray[3]);
	//nodeArray[3].addNeighbour(&nodeArray[4]);
	//nodeArray[4].ID = 69;
	
	//nodeArray[3].addNeighbours({ &nodeArray[3] , &nodeArray[4] });
	//Node MNArray[3] = { nodeArray[3] , nodeArray[4] , nodeArray[5] };
	//MakeNeighbours({ nodeArray[3] , nodeArray[4] , nodeArray[5] });

	//std::vector<Node>* nodeArrayPointer = &nodeArray;
	//nodeArray[3].addNeighbours(nodeArrayPointer, { 3, 4, 5 });

	//print("test");
	//MakeNeighbours(nodeArray, { 3, 4, 5, 8 });
	
	nodeArray[3].makeAllNeighbours(nodeArray, { 4, 5, 8 , 5, 4});

	nodeArray[3].ID = 33;
	nodeArray[5].ID = 555;// change param here to test for cross neighbours

	nodeArray[3].printNeighbours(); 
	nodeArray[5].printNeighbours();
	//print(nodeArray[4]);
	//nodeArray[4].printNeighbours();
	//nodeArray[5].printNeighbours();

	for (int i = 0; i < 10; i++)
	{
		//print(nodeArray[i]);
	}
		//pathfinder.addNode();
	



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



	pathfinder.print();





















	//Adding Spaceship
	{
		auto entity = createEntity<Spaceship>();
	}
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
}

void SpaceShooterGame::onQuit()
{
}
