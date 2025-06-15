#pragma once

#include "Huiluna/Renderer/Texture.h"

namespace Huiluna {

	class OpenGLTexture2D : public Texture2D
	{
	public:
		OpenGLTexture2D(const std::string& path);
		virtual ~OpenGLTexture2D() override;

		virtual uint32_t GetWidth() const override { return m_Width; }
		virtual uint32_t GeHeight() const override { return m_Height; }
		
		virtual void Bind(uint32_t slot) const override;
	private:
		std::string m_Path;

		uint32_t m_Width, m_Height;
		uint32_t m_RendererID;
	};

}