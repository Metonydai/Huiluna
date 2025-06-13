#include "hlpch.h"
#include "VertexArray.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

#include "Renderer.h"


namespace Huiluna {

	VertexArray* VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:	     HL_CORE_ASSERT(false, "RendererAPI::None is currently not supported"); return nullptr;
			case RendererAPI::API::OpenGL:	     return new OpenGLVertexArray();
		}

		HL_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}