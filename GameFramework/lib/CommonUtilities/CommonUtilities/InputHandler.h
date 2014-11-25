#pragma once
#pragma comment (lib, "dxguid.lib")
#pragma comment (lib, "dinput8.lib")
#include <dinput.h>
#include <iostream>
namespace CommonUtilities
{
	struct MousePosition
	{
		float myX;
		float myY;
		float myScrollWheel = 0.0f;
	};

	class InputHandler
	{
	public:
		InputHandler();
		InputHandler(HWND aWindowHandler, HINSTANCE aInstanceHandler, DWORD aKeyCoopState, DWORD aMouseCoopState);
		~InputHandler();

		void Update();
		void CapturePreviousInput();

		bool GetKeyIsDown(unsigned char aKeyCode);
		bool GetKeyIsPressed(unsigned char aKeyCode);
		bool GetKeyIsReleased(unsigned char aKeyCode);

		bool GetMouseButtonIsDown(unsigned char aMouseButton);
		bool GetMouseButtonIsPressed(unsigned char aMouseButton);
		bool GetMouseButtonIsReleased(unsigned char aMouseButton);
		MousePosition GetRelativePosition();
		MousePosition GetAbsolutePosition();
	private:
		IDirectInput8 *myDirectInput;

		IDirectInputDevice8 *myKeyboard;
		unsigned char myKeyState[256];
		unsigned char myPrevKeyState[256];

		IDirectInputDevice8 *myMouse;
		DIMOUSESTATE2 myMouseState;
		DIMOUSESTATE2 myPrevMouseState;
		MousePosition myMousePosition;

		HWND myWindowHandler;
	};
} namespace CU = CommonUtilities;