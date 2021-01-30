#include <Render/UI/Font/Character.h>

sp::Character::Character(
	SpUnsigned const textureId,
	SpUnsigned const width,
	SpUnsigned const height,
	SpUnsigned const bitmapLeft,
	SpUnsigned const bitmapTop,
	SpUnsigned const advance) :
	textureId{ textureId }, width{ width }, height{ height }, bitmapLeft{ bitmapLeft }, bitmapTop{ bitmapTop }, advance{ advance } {
}
