#pragma once
#include "GameObject.h"

class SeekerObject : public GameObject 
{
public:
	SeekerObject(std::string txFilename);
	~SeekerObject();
	void update(float elapsedTime);
private:
	void seek();
	const float MAX_SPEED = 0.6f;
};

