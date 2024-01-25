#include "Window.h"
#include <cstdlib>
#include <sstream>

int CALLBACK WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR     lpCmdLine,
	_In_ int       nCmdShow
)
{
	try
	{
		Window wnd(800, 500, "New Win32 Window");

		MSG msg;
		BOOL gResult;

		while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			/* WHEEL TEST
			static int i = 0;
			while (!wnd.mouse.IsEmpty())
			{
				const auto e = wnd.mouse.Read();
				switch (e.GetType())
				{
				case Mouse::Event::Type::WheelUp:
					i++;
					{
						std::ostringstream oss;
						oss << "Up: " << i;
						wnd.SetTitle(oss.str());
					}
					break;
				case Mouse::Event::Type::WheelDown:
					i--;
					{
						std::ostringstream oss;
						oss << "Down: " << i;
						wnd.SetTitle(oss.str());
					}
					break;
				}
			}

			IN WINDOW TEST
			while (!wnd.mouse.IsEmpty())
			{
				const auto e = wnd.mouse.Read();
				switch (e.GetType())
				{
				case Mouse::Event::Type::Leave:
					wnd.SetTitle("Gone!");
					break;
				case Mouse::Event::Type::Move:
					{
						std::ostringstream oss;
						oss << "Mouse moved to: (" << e.GetPosX() << "," << e.GetPosY() << ")";
						wnd.SetTitle(oss.str());
					}
					break;
				}
			}

		    MOUSE POSITION TEST
			while (!wnd.mouse.IsEmpty())
			{
				const auto e = wnd.mouse.Read();
				if (e.GetType() == Mouse::Event::Type::Move)
				{
					std::ostringstream oss;
					oss << "Mouse Position: (" << e.GetPosX() << "," << e.GetPosY() << ")";
					wnd.SetTitle(oss.str());
				}
			}

			KEY PRESS TEST
			if (wnd.kbd.KeyIsPressed(VK_MENU))
			{
				MessageBox(nullptr, "Something Happened!", "Space Key Was Pressed", MB_OK | MB_ICONEXCLAMATION);
			}
			*/
		}

		if (gResult == -1)
		{
			return -1;
		}

		// wParam is the value passed to PostQuitMessage
		return (int)msg.wParam;
	}
	catch (const ExceptionHandling& e)
	{
		// send MessageBox
		MessageBox(nullptr, e.what(), e.GetType(), MB_OK | MB_ICONEXCLAMATION);
	}
	catch (const std::exception& e)
	{
		// send MessageBox
		MessageBox(nullptr, e.what(), "Standard Exception", MB_OK | MB_ICONEXCLAMATION);
	}
	catch (...)
	{
		// send MessageBox
		MessageBox(nullptr, "No details available", "Unknown Exception", MB_OK | MB_ICONEXCLAMATION);
	}

	return -1;

}