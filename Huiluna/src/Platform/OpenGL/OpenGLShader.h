#pragma once

#include "Huiluna/Renderer/Shader.h"

#include <unordered_map>

#include <glm/glm.hpp>

typedef int GLint;

namespace Huiluna {

	class OpenGLShader : public Shader
	{
	public:
		OpenGLShader(const std::string& vertexSrc, const std::string& fragmentSrc);
		virtual ~OpenGLShader();

		virtual void Bind() const override;
		virtual void Unbind() const override;

		void UploadUniformInt(const std::string& name, int value);

		void UploadUniformFloat(const std::string& name, float value);
		void UploadUniformFloat2(const std::string& name, const glm::vec2& values);
		void UploadUniformFloat3(const std::string& name, const glm::vec3& values);
		void UploadUniformFloat4(const std::string& name, const glm::vec4& values);
		void UploadUniformMat4(const std::string& name, const glm::mat4& matrix);
	private:
		GLint GetUniformLocation(const std::string& name) const;
	private:
		uint32_t m_RendererID;

		mutable std::unordered_map<std::string, GLint> m_UniformLocationCache;
	};
}
