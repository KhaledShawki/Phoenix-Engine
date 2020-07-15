#pragma once

#include "Phoenix/EvaRenderer/GraphicsContext.h"

struct GLFWwindow;
namespace Phx {

	class OpenGLContext : public GraphicsContext
	{
	public:
		OpenGLContext(GLFWwindow* windowHandle);
		virtual void Init() override;
		virtual void SwapBuffers() override;
	private:
		GLFWwindow* m_WindowHandle;
	};
}
