#include "Window.h"

Window::Window()
{
	myHge = nullptr;
	myInput = nullptr;
	myRunningCheck = false;
}

Window::~Window()
{

}

void Window::Init(HINSTANCE aInstanceHandler)
{
	const int screenWidth = 1024;
	const int screenHeight = screenWidth / 16 * 9;
	myHge = hgeCreate(HGE_VERSION);
	myHge->System_SetState(HGE_WINDOWED, true);
	myHge->System_SetState(HGE_USESOUND, false);
	myHge->System_SetState(HGE_SCREENWIDTH, screenWidth);
	myHge->System_SetState(HGE_SCREENHEIGHT, screenHeight);
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

void Window::Run()
{
	while (myRunningCheck == true)
	{
		Update();
		Render();
	}
	delete myInput;
	myInput = nullptr;
	myHge->System_Shutdown();
	myHge->Release();
	delete myHge;
}

void Window::Update()
{
	myInput->Update();
	myTimer.UpdateTimers();
	myDelta = static_cast<float>(myTimer.GetDeltaTime() * 0.0001);
	if (myInput->GetKeyIsDown(DIK_ESCAPE) == true)
	{
		myRunningCheck = false;
		return;
	}
	myGame.Update(myDelta);
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
	window.Init(aInstanceHandler);
	window.Run();
	return 0;
}
