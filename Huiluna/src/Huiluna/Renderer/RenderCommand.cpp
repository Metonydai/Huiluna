#include "hlpch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Huiluna {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI();

}
