#include "InputHandler.h"

CU::InputHandler::InputHandler()
{
	myDirectInput = nullptr;
	myKeyboard = nullptr;
	myMouse = nullptr;
	myWindowHandler = nullptr;
}

CU::InputHandler::InputHandler(HWND aWindowHandler, HINSTANCE aInstanceHandler, DWORD aKeyCoopState, DWORD aMouseCoopState)
{
	myWindowHandler = aWindowHandler;
	if (DirectInput8Create(aInstanceHandler, DIRECTINPUT_VERSION, IID_IDirectInput8, reinterpret_cast<void**>(&myDirectInput), 0) == false)
	{
		std::cout << "Error: failed to create Direct Input" << std::endl;
	}
	if (myDirectInput->CreateDevice(GUID_SysKeyboard, &myKeyboard, 0) == false)
	{
		std::cout << "Error: failed to create Keyboard Device" << std::endl;
	}
	if (myDirectInput->CreateDevice(GUID_SysMouse, &myMouse, 0) == false)
	{
		std::cout << "Error: failed to create Mouse Device" << std::endl;
	}
	if (myKeyboard->SetDataFormat(&c_dfDIKeyboard) == false)
	{
		std::cout << "Error: failed to set Keyboard data format" << std::endl;
	}
	if (myMouse->SetDataFormat(&c_dfDIMouse2) == false)
	{
		std::cout << "Error: failed to set Mouse data format" << std::endl;
	}
	if (myKeyboard->SetCooperativeLevel(aWindowHandler, aKeyCoopState) == false)
	{
		std::cout << "Error: failed to set Keyboard cooperative level" << std::endl;
	}
	if (myMouse->SetCooperativeLevel(aWindowHandler, aMouseCoopState) == false)
	{
		std::cout << "Error: failed to set Mouse cooperative level" << std::endl;
	}
	if (myKeyboard->Acquire() == false)
	{
		std::cout << "Error: failed to acquire Keyboard" << std::endl;
	}
	if (myMouse->Acquire() == false)
	{
		std::cout << "Error: failed to acquire Mouse" << std::endl;
	}
}

CU::InputHandler::~InputHandler()
{
	if (myDirectInput != nullptr)
	{
		myDirectInput->Release();
		myDirectInput = nullptr;
	}
	myKeyboard->Unacquire();
	myMouse->Unacquire();
	if (myKeyboard != nullptr)
	{
		myKeyboard->Release();
		myKeyboard = nullptr;
	}
	if (myMouse != nullptr)
	{
		myMouse->Release();
		myMouse = nullptr;
	}
}

void CU::InputHandler::Update()
{
	HRESULT handleResult = myKeyboard->GetDeviceState(sizeof(myKeyState), reinterpret_cast<void**>(&myKeyState));
	if (FAILED(handleResult) == true)
	{
		ZeroMemory(myKeyState, sizeof(myKeyState));
		myKeyboard->Acquire();
	}

	handleResult = myMouse->GetDeviceState(sizeof(DIMOUSESTATE2), reinterpret_cast<void**>(&myMouseState));
	if (FAILED(handleResult) == true)
	{
		ZeroMemory(&myMouseState, sizeof(myMouseState));
		myMouse->Acquire();
	}
}

void CU::InputHandler::CapturePreviousInput()
{
	memcpy_s(myPrevKeyState, sizeof(myPrevKeyState), myKeyState, sizeof(myKeyState));
	memcpy_s(&myPrevMouseState, sizeof(myPrevMouseState), &myMouseState, sizeof(myMouseState));
}

bool CU::InputHandler::GetKeyIsDown(unsigned char aKeyCode)
{
	if ((myKeyState[aKeyCode] & 0x80) != 0)
	{
		return true;
	}
	return false;
}

bool CU::InputHandler::GetKeyIsPressed(unsigned char aKeyCode)
{
	if (((myKeyState[aKeyCode] & 0x80) != 0) && ((myPrevKeyState[aKeyCode] & 0x80) == 0))
	{
		return true;
	}
	return false;
}

bool CU::InputHandler::GetKeyIsReleased(unsigned char aKeyCode)
{
	if (((myKeyState[aKeyCode] & 0x80) == 0) && ((myPrevKeyState[aKeyCode] & 0x80) != 0))
	{
		return true;
	}
	return false;
}

bool CU::InputHandler::GetMouseButtonIsDown(unsigned char aMouseButton)
{
	if ((myMouseState.rgbButtons[aMouseButton] & 0x80) != 0)
	{
		return true;
	}
	return false;
}

bool CU::InputHandler::GetMouseButtonIsPressed(unsigned char aMouseButton)
{
	if (((myMouseState.rgbButtons[aMouseButton] & 0x80) != 0) && ((myPrevMouseState.rgbButtons[aMouseButton] & 0x80) == 0))
	{
		return true;
	}
	return false;
}

bool CU::InputHandler::GetMouseButtonIsReleased(unsigned char aMouseButton)
{
	if (((myMouseState.rgbButtons[aMouseButton] & 0x80) == 0) && ((myPrevMouseState.rgbButtons[aMouseButton] & 0x80) != 0))
	{
		return true;
	}
	return false;
}

CU::MousePosition CU::InputHandler::GetRelativePosition()
{
	myMousePosition.myX = static_cast<float>(myMouseState.lX);
	myMousePosition.myY = static_cast<float>(myMouseState.lY);
	myMousePosition.myScrollWheel = static_cast<float>(myMouseState.lZ);

	return myMousePosition;
}

CU::MousePosition CU::InputHandler::GetAbsolutePosition()
{
	tagPOINT getMouseXAndY;
	GetCursorPos(&getMouseXAndY);
	ScreenToClient(myWindowHandler, &getMouseXAndY);
	
	myMousePosition.myX = static_cast<float>(getMouseXAndY.x);
	myMousePosition.myY = static_cast<float>(getMouseXAndY.y);
	myMousePosition.myScrollWheel += static_cast<float>(myMouseState.lZ);

	return myMousePosition;
}