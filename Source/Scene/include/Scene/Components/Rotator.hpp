#include <Scene/Components/GameObjectComponent.hpp>

namespace sp {
	class Rotator : public GameObjectComponent {
	public:
		Rotator(GameObject * const gameObjectOwner);

	public:
		void update(SpFloat deltaTime) override;

	private:
		SpFloat _passedTime = 0.0F;
	};
}
