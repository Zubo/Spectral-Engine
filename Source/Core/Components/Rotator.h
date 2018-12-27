#include "Components/GameObjectComponent.h"

class Rotator : public GameObjectComponent {
public:
	Rotator(GameObject * const gameObjectOwner);

public:
	void update(float deltaTime) override;

private:
	float passedTime = 0.0F;
};