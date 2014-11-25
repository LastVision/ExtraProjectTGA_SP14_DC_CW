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
	myHge = hgeCreate(HGE_VERSION);
	myHge->System_SetState(HGE_WINDOWED, true);
	myHge->System_SetState(HGE_USESOUND, false);
	myHge->System_SetState(HGE_SCREENWIDTH, 800);
	myHge->System_SetState(HGE_SCREENHEIGHT, 600);
	myHge->System_SetState(HGE_SCREENBPP, 32);
	myHge->System_SetState(HGE_TITLE, "Pong 2014 TGA Edition Alpha");
	myHge->System_SetState(HGE_SHOWSPLASH, false);

	if (myHge->System_Initiate())
	{
		myTimer.UpdateTimers();
		srand(static_cast<unsigned int>(myTimer.GetDeltaTime()));
		//Game Inits here
		myInput = new CU::InputHandler(GetActiveWindow(), aInstanceHandler, DISCL_FOREGROUND, DISCL_FOREGROUND);
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
	
	//Game Update Here
	myGame.Update(myDelta);

	myInput->CapturePreviousInput();
}

void Window::Render()
{
	myHge->Gfx_BeginScene();
	myHge->Gfx_Clear(0);

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
