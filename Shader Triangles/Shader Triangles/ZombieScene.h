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
#include "GameObject.h"
#include "Input.h"
#include <iostream>
class ZombieScene :public GameObject
{
	Texture texture;
	Sound sound;

public:
	ZombieScene();
	virtual ~ZombieScene();

	void Movement();

	virtual void render(GLuint program);

	virtual void update(float deltaTime, GLuint program);

	virtual void initialise();

	void updateSprite();

	void updateSounds();

private:
	bool hasBeenReleased = true;
	int frameIndex = 1;
	int animationIndex = 5;
};

