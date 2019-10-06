#pragma once

#include <memory>
#include "PlatformIndependence/SpString.h"

#include "Game/Components/GameObjectComponent.h"
#include "Game/Components/Interface/IRenderer.h"
#include "Render/Shader/ShaderProgram.h"
#include "Render/UI/Font/Font.h"
#include "Core/Math/Vector2.h"

namespace sp {
	class TextRenderer : public GameObjectComponent, public IRenderer {
	public:
		TextRenderer(GameObject * const gameObject);

	public:
		void render() const override;
		void setFont(SpString const & fontPath);
		void setText(SpString const & text);

	private:
		void generateRenderData();
		Vector2 const getPosition() const;
		Vector2 const getScale() const;

	private:
		unsigned int VAO;
		unsigned int VBO;
		SpString text;
		ShaderProgram shaderProgram;
		std::shared_ptr<Font const> font;
	};
}
