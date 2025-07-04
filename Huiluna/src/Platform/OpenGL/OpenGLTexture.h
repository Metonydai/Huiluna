#pragma once

#include "Huiluna/Renderer/Texture.h"

#include <glad/glad.h>

namespace Huiluna {

	class OpenGLTexture2D : public Texture2D
	{
	public:
		OpenGLTexture2D(uint32_t width, uint32_t height);
		OpenGLTexture2D(const std::string& path);
		virtual ~OpenGLTexture2D() override;

		virtual uint32_t GetWidth() const override { return m_Width; }
		virtual uint32_t GetHeight() const override { return m_Height; }
		virtual uint32_t GetRendererID() const override { return m_RendererID; }

		virtual void SetData(void* data, uint32_t size) override;

		virtual void Bind(uint32_t slot) const override;
		
		virtual bool IsLoaded() const override { return m_IsLoaded; }

		virtual bool operator==(const Texture& other) const override
		{ 
			return this->m_RendererID == ((OpenGLTexture2D&)other).m_RendererID; 
		}

	private:
		std::string m_Path;
		bool m_IsLoaded = false;

		uint32_t m_Width, m_Height;
		uint32_t m_RendererID;

		GLenum m_InternalFormat, m_DataFormat;
	};

}