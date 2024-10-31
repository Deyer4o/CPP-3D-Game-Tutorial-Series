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

	void InitMats()
	{
		matWhite->addTexture(texWhite);
		matBlue->addTexture(texBlue);
		matRed->addTexture(texRed);
		matGreen->addTexture(texGreen);
		matOrange->addTexture(texOrange);
		matPurple->addTexture(texPurple);
		matPink->addTexture(texPink);
	}

	void MakeSphere(CXVec3 _location,float _scale, CXMaterialPtr _mat)
	{
		auto ent = createEntity<CXMeshEntity>();
		ent->setMesh(meshSphere);
		ent->addMaterial(_mat);
		ent->setPosition(_location);
		ent->setRotation(CXVec3());
		ent->setScale(CXVec3(_scale, _scale, _scale));
	}

	void MakeLine(CXVec3 _A, CXVec3 _B, float _steps, float _scale, CXMaterialPtr _mat) 
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
		float steps = _steps;
		
		for (int step = 0; step <= steps; step++)
		{
			float factor = step / steps; // runs from 0 to 1 inclusive
			float x = X1 + dX * factor;
			float y = Y1 + dY * factor;
			float z = Z1 + dZ * factor;

			MakeSphere(CXVec3(x, y, z), _scale, _mat);
		}
		
	}
	

	
private:
	bool m_input = true;
};

