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

#pragma once

#include <CX3D/All.h>
#include <string>

class SpaceShooterGame : public CXGame
{
public:
	SpaceShooterGame();
	~SpaceShooterGame();

	virtual void onCreate();
	virtual void onUpdate(f32 deltaTime);
	virtual void onQuit();

	//Spaceship Player;
	//CXMeshEntity Player = createEntity<CXMeshEntity>();
	
	CXMeshEntity* ent = createEntity<CXMeshEntity>();

	CXMeshPtr meshSphere = createMesh(L"Assets/Meshes/sphere.obj");
	CXMaterialPtr matBase = createMaterial(L"Assets/Shaders/base.hlsl");

	CXTexturePtr texWhite = createTexture(L"Assets/Textures/white.jpg");
	CXMaterialPtr matWhite = createMaterial(L"Assets/Shaders/base.hlsl");;
	CXTexturePtr texBlue = createTexture(L"Assets/Textures/blue.jpg");
	CXMaterialPtr matBlue = createMaterial(L"Assets/Shaders/base.hlsl");;
	CXTexturePtr texRed = createTexture(L"Assets/Textures/red.jpg");
	CXMaterialPtr matRed = createMaterial(L"Assets/Shaders/base.hlsl");;
	CXTexturePtr texGreen = createTexture(L"Assets/Textures/green.jpg");
	CXMaterialPtr matGreen = createMaterial(L"Assets/Shaders/base.hlsl");;
	CXTexturePtr texOrange = createTexture(L"Assets/Textures/orange.jpg");
	CXMaterialPtr matOrange = createMaterial(L"Assets/Shaders/base.hlsl");;
	CXTexturePtr texPurple = createTexture(L"Assets/Textures/purple.jpg");
	CXMaterialPtr matPurple = createMaterial(L"Assets/Shaders/base.hlsl");;
	CXTexturePtr texPink = createTexture(L"Assets/Textures/pink.jpg");
	CXMaterialPtr matPink = createMaterial(L"Assets/Shaders/base.hlsl");;

	std::vector<CXMaterialPtr> matNumbers;
	//std::vector<CXTexturePtr*> texNumbers;
	
	int lastmatNum = 11;
	void InitNumMats()
	{
		CXTexturePtr tex0 = createTexture(L"Assets/Textures/0.jpg");
		CXMaterialPtr mat0 = createMaterial(L"Assets/Shaders/base.hlsl");
		CXTexturePtr tex1 = createTexture(L"Assets/Textures/1.jpg");
		CXMaterialPtr mat1 = createMaterial(L"Assets/Shaders/base.hlsl");
		CXTexturePtr tex2 = createTexture(L"Assets/Textures/2.jpg");
		CXMaterialPtr mat2 = createMaterial(L"Assets/Shaders/base.hlsl");
		CXTexturePtr tex3 = createTexture(L"Assets/Textures/3.jpg");
		CXMaterialPtr mat3 = createMaterial(L"Assets/Shaders/base.hlsl");
		CXTexturePtr tex4 = createTexture(L"Assets/Textures/4.jpg");
		CXMaterialPtr mat4 = createMaterial(L"Assets/Shaders/base.hlsl");
		CXTexturePtr tex5 = createTexture(L"Assets/Textures/5.jpg");
		CXMaterialPtr mat5 = createMaterial(L"Assets/Shaders/base.hlsl");
		CXTexturePtr tex6 = createTexture(L"Assets/Textures/6.jpg");
		CXMaterialPtr mat6 = createMaterial(L"Assets/Shaders/base.hlsl");
		CXTexturePtr tex7 = createTexture(L"Assets/Textures/7.jpg");
		CXMaterialPtr mat7 = createMaterial(L"Assets/Shaders/base.hlsl");
		CXTexturePtr tex8 = createTexture(L"Assets/Textures/8.jpg");
		CXMaterialPtr mat8 = createMaterial(L"Assets/Shaders/base.hlsl");
		CXTexturePtr tex9 = createTexture(L"Assets/Textures/9.jpg");
		CXMaterialPtr mat9 = createMaterial(L"Assets/Shaders/base.hlsl");
		CXTexturePtr tex10 = createTexture(L"Assets/Textures/10.jpg");
		CXMaterialPtr mat10 = createMaterial(L"Assets/Shaders/base.hlsl");
		CXTexturePtr tex11 = createTexture(L"Assets/Textures/11.jpg");
		CXMaterialPtr mat11 = createMaterial(L"Assets/Shaders/base.hlsl");
		
		mat0->addTexture(tex0);
		mat1->addTexture(tex1);
		mat2->addTexture(tex2);
		mat3->addTexture(tex3);
		mat4->addTexture(tex4);
		mat5->addTexture(tex5);
		mat6->addTexture(tex6);
		mat7->addTexture(tex7);
		mat8->addTexture(tex8);
		mat9->addTexture(tex9);
		mat10->addTexture(tex10);
		mat11->addTexture(tex11);
		
		matNumbers.push_back(mat0);
		matNumbers.push_back(mat1);
		matNumbers.push_back(mat2);
		matNumbers.push_back(mat3);
		matNumbers.push_back(mat4);
		matNumbers.push_back(mat5);
		matNumbers.push_back(mat6);
		matNumbers.push_back(mat7);
		matNumbers.push_back(mat8);
		matNumbers.push_back(mat9);
		matNumbers.push_back(mat10);
		matNumbers.push_back(mat11);
	}

	void InitMats()
	{
		matWhite->addTexture(texWhite);
		matBlue->addTexture(texBlue);
		matRed->addTexture(texRed);
		matGreen->addTexture(texGreen);
		matOrange->addTexture(texOrange);
		matPurple->addTexture(texPurple);
		matPink->addTexture(texPink);
		//mat0->addTexture(tex0);
		//mat1->addTexture(tex1);
		//mat2->addTexture(tex2);
		//mat3->addTexture(tex3);
		//mat4->addTexture(tex4);
		//mat5->addTexture(tex5);
		//mat6->addTexture(tex6);
		//mat7->addTexture(tex7);
		//mat8->addTexture(tex8);
		//mat9->addTexture(tex9);
		//mat10->addTexture(tex10);
		//mat11->addTexture(tex11);
	}

	auto* MakeSphere(CXVec3 _location,float _scale, CXMaterialPtr _mat)
	{
		auto ent = createEntity<CXMeshEntity>();
		ent->setMesh(meshSphere);
		ent->addMaterial(_mat);
		ent->setPosition(_location);
		ent->setRotation(CXVec3());
		ent->setScale(CXVec3(_scale, _scale, _scale));

		return ent;
	}

	void printNumberInScene(CXVec3 _location, int _number, float _size) 
	{
		std::string sNum = std::to_string(_number);

		for (int i = 0; i < sNum.length(); i++) 
		{
			int x = (int)sNum[i] - 48;
			MakeSphere(_location - CXVec3(i * _size * 1.5,0,0), _size,  matNumbers[x]);
		}
		
	}

	void MakeLine(CXVec3 _A, CXVec3 _B, float _scale, CXMaterialPtr _mat) 
	{
		// Compute vector from A to B by subtracting A from B
		float X1 = _A.x;
		float X2 = _B.x;
		float Y1 = _A.y;
		float Y2 = _B.y;
		float Z1 = _A.z;
		float Z2 = _B.z;

		float dX = X2 - X1;
		float dY = Y2 - Y1;
		float dZ = Z2 - Z1;

		// Start at A and interpolate along this vector
		float steps = (abs(dX) / _scale + abs(dY) / _scale + abs(dZ) / _scale) / 2;
		
		for (int step = 0; step <= steps; step++)
		{
			float factor = step / steps; // runs from 0 to 1 inclusive
			float x = X1 + dX * factor;
			float y = Y1 + dY * factor;
			float z = Z1 + dZ * factor;

			MakeSphere(CXVec3(x, y, z), _scale, _mat);
		}
		
	}
	
	//std::vector<CXMeshEntity*> entholder;

	
private:
	bool m_input = true;
};

