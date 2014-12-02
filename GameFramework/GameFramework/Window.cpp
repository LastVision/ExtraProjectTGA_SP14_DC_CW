#include "Window.h"

const float locScale = 2.0f;
const unsigned int locScreenWidth = static_cast<unsigned int>(480 * locScale);
const unsigned int locScreenHeight = locScreenWidth / 16 * 9;

Window::Window()
{
	myHge = nullptr;
	myInput = nullptr;
	myRunningCheck = false;
}

Window::~Window()
{

}

void Window::Init(HINSTANCE aInstanceHandler, bool aRunningCheck)
{
	myRunningCheck = aRunningCheck;
	myHge = hgeCreate(HGE_VERSION);
	myHge->System_SetState(HGE_WINDOWED, true);
	myHge->System_SetState(HGE_USESOUND, false);
	myHge->System_SetState(HGE_SCREENWIDTH, locScreenWidth);
	myHge->System_SetState(HGE_SCREENHEIGHT, locScreenHeight);
	myHge->System_SetState(HGE_SCREENBPP, 32);
	myHge->System_SetState(HGE_TITLE, "Unnamed RPG Alpha v0.1");

	if (myHge->System_Initiate())
	{
		myInput = new CU::InputHandler(GetActiveWindow(), aInstanceHandler, DISCL_FOREGROUND, DISCL_FOREGROUND);
		//Game Inits here
		myGame.Init(myHge, myInput);

		myHge->System_Start();
	}
	else
	{
		MessageBox(nullptr, myHge->System_GetErrorMessage(), "Error", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		myRunningCheck = false;
	}
	myRunningCheck = true;
}

bool Window::Run()
{
	if (myRunningCheck == true)
	{
		Update();
		Render();
	}
	else
	{
		return false;
	}
	return true;
}

void Window::Shutdown()
{
	myHge->System_Shutdown();
	myHge->Release();
}

void Window::Update()
{
	myInput->Update();
	myTimer.UpdateTimers();
	myDelta = static_cast<float>(myTimer.GetDeltaTime() * 0.0001);
	if (myGame.Update(myDelta) == true)
	{
		myRunningCheck = false;
		return;
	}
	myInput->CapturePreviousInput();
}

void Window::Render()
{
	myHge->Gfx_BeginScene();
	myHge->Gfx_Clear(0xAAAAED);

	// Game Render here
	myGame.Render();

	myHge->Gfx_EndScene();
}

int WINAPI WinMain(HINSTANCE aInstanceHandler, HINSTANCE, LPSTR, int)
{
	Window window;
	bool runningFlag = true;
	window.Init(aInstanceHandler, runningFlag);
	MSG windowsMessage;
	while (runningFlag == true)
	{
		// check for messages
		if (PeekMessage(&windowsMessage, NULL, 0, 0, PM_REMOVE))
		{
			// handle or dispatch messages
			if (windowsMessage.message == WM_QUIT)
			{
				break;
			}
			TranslateMessage(&windowsMessage);
			DispatchMessage(&windowsMessage);
		}
		else
		{
			if (window.Run() == false)
			{
				runningFlag = false;
			}
		}
	}
	window.Shutdown();
	return 0;
}