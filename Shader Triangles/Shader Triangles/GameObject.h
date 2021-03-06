#pragma once
#include "Dependencies\soil\SOIL.h"
#include "Dependencies\glew\glew.h" 
#include "Dependencies\freeglut\freeglut.h" 
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"
#include "Mesh2D.h"
#include "Texture.h"
#include "Transform.h"
#include "Camera.h"
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"
#include "Sound.h"
#include "Collision.h"
#include "RadiusCollision.h"
#include <iostream>

class GameObject
{
	Mesh2D* mesh2D = nullptr;
	Texture* textureObject = nullptr;
	
	glm::mat4 modelMatrix;
	glm::mat4 pvmMatrix;

public:
	GameObject();
	virtual ~GameObject();

	virtual void initialise(int spriteWidth, int spriteHeight, int texWidth, int texHeight, int frameIndex, std::string);
	virtual void render(GLuint program);
	virtual void update(float deltaTime, bool isSpriteSheet, int animationIndex, bool isInAction, float frameIndex);

	virtual bool getIsCompleted();
	
	void calculateModelMatrix();
	void calculatePVMMatrix(glm::mat4 PV);

	glm::mat4 getModelMatrix();
	glm::mat4 getPVMMatrix();

	float getObjectDiameter();

	void setIsVisible(bool visible);
	bool getIsVisible();

	RadiusCollision* getCollider();

	Transform transform;

protected:

	int frameIndex = 0;
	float objectDiameter;
	int animationIndex = 0;
	RadiusCollision* collider = nullptr;
	bool isVisible = true;
};

