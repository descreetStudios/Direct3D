#include "App.h"
#include <sstream>
#include <iomanip>

App::App()
	:
	wnd(800, 500, "New Win32 Window")
{}

int App::Go()
{
	while (true)
	{
		if (const auto ecode = Window::ProcessMessages())
		{
			return *ecode;
		}
		DoFrame();
	}
}

void App::DoFrame()
{
	const float c = sin(timer.Peek()) / 1.0f + 2.0f;
	wnd.Gfx().ClearBuffer(c, c, 1.0f);
	wnd.Gfx().EndFrame();
}