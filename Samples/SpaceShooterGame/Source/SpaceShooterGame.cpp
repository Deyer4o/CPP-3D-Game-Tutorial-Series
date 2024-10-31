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

	




	auto mesh_sphere = createMesh(L"Assets/Meshes/sphere.obj");
	auto tex = createTexture(L"Assets/Textures/blue.jpg");
	
	//auto mesh_cube = createMesh(L"Assets/Meshes/Cube.obj");
	auto mat = createMaterial(L"Assets/Shaders/base.hlsl");
	mat->addTexture(tex);








	
	
	
	
	
	
	
	





	



	//Custom approach:


	//Adding Pathfinder 
	DPathfinder pathfinder;
	
	std::vector<Node> nodeArray;
	//Node_ID = 0;
	float z = -300.0f;
	nodeArray.push_back(Node(0.0f, 0.0f, z));	 //0
	nodeArray.push_back(Node(0.0f, 200.0f, z));	 //1
	nodeArray.push_back(Node(200.0f, 300.0f, z)); //2
	nodeArray.push_back(Node(600.0f, 0.0f, z));	 //3
	nodeArray.push_back(Node(300.0f, 500.0f, z));//4
	nodeArray.push_back(Node(1000.0f, 0.0f, z));//5
	nodeArray.push_back(Node(1000.0f, 400.0f, z));//6
	nodeArray.push_back(Node(1000.0f, 500.0f, z));//7
	nodeArray.push_back(Node(400.0f, 200.0f, z)); //8
	nodeArray.push_back(Node(600.0f, 800.0f, z)); //9
	
	pathfinder.makeNodes(nodeArray);


	pathfinder.NodesArray[3].addMultipleNeighbours(nodeArray, { 4, 5, 8 });

	//nodeArray[3].printNeighbours();

	//nodeArray[4].printNeighbours();

	pathfinder.print();
	pathfinder.NodesArray[3].printNeighbours();




	for (Node n : pathfinder.NodesArray) 
	{
		MakeSphere(n.location, 30.0f, matBlue);
	}

	MakeLine(CXVec3(0,0,0), CXVec3(200, 500, 400), 50, 10.0f, matRed);



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
	
	
}

void SpaceShooterGame::onQuit()
{
}
