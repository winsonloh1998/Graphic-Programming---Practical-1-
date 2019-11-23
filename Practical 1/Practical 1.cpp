#include <Windows.h>
#include <math.h>
#include <gl/GL.h>

#define WINDOW_TITLE "Practical 1"

#pragma comment (lib, "OpenGL32.lib")

int displayKey = 1;

LRESULT WINAPI WindowProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE)
			PostQuitMessage(0);
		else if (wParam == 0x31)
			displayKey = 1;
		else if (wParam == 0x32)
			displayKey = 2;
		else if (wParam == 0x33)
			displayKey = 3;
		else if (wParam == 0x34)
			displayKey = 4;
		else if (wParam == 0x35)
			displayKey = 5;
		else if (wParam == 0x36)
			displayKey = 6;
			break;

	default:
		break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}
//--------------------------------------------------------------------

bool initPixelFormat(HDC hdc)
{
	PIXELFORMATDESCRIPTOR pfd;
	ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));

	pfd.cAlphaBits = 8;
	pfd.cColorBits = 32;
	pfd.cDepthBits = 24;
	pfd.cStencilBits = 0;

	pfd.dwFlags = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;

	pfd.iLayerType = PFD_MAIN_PLANE;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;

	// choose pixel format returns the number most similar pixel format available
	int n = ChoosePixelFormat(hdc, &pfd);

	// set pixel format returns whether it sucessfully set the pixel format
	if (SetPixelFormat(hdc, n, &pfd))
	{
		return true;
	}
	else
	{
		return false;
	}
}
//--------------------------------------------------------------------

void pahangFlag() {
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_QUADS);

	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-1.0, 0.0);

	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(1.0, 0.0);

	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(1.0, -1.0);

	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-1.0, -1.0);

	glEnd();
}
//--------------------------------------------------------------------

void negeriSembilanFlag() {
	glClearColor(1.0f, 1.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-1.0, 1.0);

	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(0.0, 0.0);

	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-1.0, 0.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(-1.0, 1.0);

	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(0.0, 1.0);

	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(0.0, 0.0);
	glEnd();
}
//--------------------------------------------------------------------

void englandFlag() {
	glClearColor(0.76f, 0.76f, 0.76f, 0.5f);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POLYGON);
	glColor3f(0.8, 0.8, 0.8);
	glVertex2f(-1.0, 1.0);

	glColor3f(0.8, 0.8, 0.8);
	glVertex2f(-0.15, 1.0);

	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(-0.15, 0.2);

	glColor3f(0.8, 0.8, 0.8);
	glVertex2f(-1.0, 0.2);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.8, 0.8, 0.8);
	glVertex2f(1.0, 1.0);

	glColor3f(0.8, 0.8, 0.8);
	glVertex2f(1.0, 0.2);

	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(0.15, 0.2);

	glColor3f(0.8, 0.8, 0.8);
	glVertex2f(0.15, 1.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.8, 0.8, 0.8);
	glVertex2f(-1.0, -1.0);

	glColor3f(0.8, 0.8, 0.8);
	glVertex2f(-1.0, -0.2);

	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(-0.15, -0.2);

	glColor3f(0.8, 0.8, 0.8);
	glVertex2f(-0.15, -1.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.8, 0.8, 0.8);
	glVertex2f(1.0, -1.0);

	glColor3f(0.8, 0.8, 0.8);
	glVertex2f(0.15, -1.0);

	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(0.15, -0.2);

	glColor3f(0.8, 0.8, 0.8);
	glVertex2f(1.0, -0.2);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.545, 0.0, 0.0);
	glVertex2f(-1.0, 0.2);
	glVertex2f(1.0, 0.2);
	glVertex2f(1.0, -0.2);
	glVertex2f(-1.0, -0.2);
	glEnd();

	glBegin(GL_QUADS);

	glColor3f(0.545, 0.0, 0.0);
	glVertex2f(-0.15, 1.0);

	glColor3f(0.545, 0.0, 0.0);
	glVertex2f(0.15, 1.0);

	glColor3f(0.545, 0.0, 0.0);
	glVertex2f(0.15, -1.0);

	glColor3f(0.545, 0.0, 0.0);
	glVertex2f(-0.15, -1.0);

	glEnd();
}
//--------------------------------------------------------------------

void scotlandFlag() {
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_TRIANGLES);

	glColor3f(0.0, 0.5, 1.0);
	glVertex2f(-1.0, 0.8);

	glColor3f(0.0, 0.5, 1.0);
	glVertex2f(-0.2, 0.0);

	glColor3f(0.0, 0.5, 1.0);
	glVertex2f(-1.0, -0.8);

	glEnd();

	glBegin(GL_TRIANGLES);

	glColor3f(0.0, 0.5, 1.0);
	glVertex2f(0.2, 0.0);

	glColor3f(0.0, 0.5, 1.0);
	glVertex2f(1.0, 0.8);

	glColor3f(0.0, 0.5, 1.0);
	glVertex2f(1.0, -0.8);

	glEnd();

	glBegin(GL_TRIANGLES);

	glColor3f(0.0, 0.5, 1.0);
	glVertex2f(-0.8, 1.0);

	glColor3f(0.0, 0.5, 1.0);
	glVertex2f(0.8, 1.0);

	glColor3f(0.0, 0.5, 1.0);
	glVertex2f(0.0, 0.2);

	glEnd();

	glBegin(GL_TRIANGLES);

	glColor3f(0.0, 0.5, 1.0);
	glVertex2f(-0.8, -1.0);

	glColor3f(0.0, 0.5, 1.0);
	glVertex2f(0.8, -1.0);

	glColor3f(0.0, 0.5, 1.0);
	glVertex2f(0.0, -0.2);

	glEnd();
}
//--------------------------------------------------------------------

void japanFlag() {
	const float DEG2RAD = 3.14159 / 180;
	const float radius = 0.3;

	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POLYGON);

	for (int i = 0; i <= 360; i++)
	{
		float degInRad = i * DEG2RAD;
		glColor3f(1.0, 0.0, 0.0);
		glVertex2f(cos(degInRad)*radius, sin(degInRad)*(radius + 0.20));

	}

	glEnd();
}
//--------------------------------------------------------------------

void pikachuMeme()
{
	const float DEG2RAD = 3.14159 / 180;
	float radius = 0.0;

	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	//WHOLE FACE PART1
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.90f, 0.18f);
	glVertex2f(-0.5f, 0.2f);
	glVertex2f(-1.0f, 0.8f);
	glVertex2f(-0.1f, 0.4f);
	glVertex2f(0.4f, 0.4f);
	glVertex2f(-0.5f, 0.2f);
	glEnd();

	//WHOLE FACE PART2
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.90f, 0.18f);
	glVertex2f(0.4f, 0.4f);
	glVertex2f(1.0f, 0.7f);
	glVertex2f(0.6f, 0.1f);
	glVertex2f(0.8f, -0.7f);
	glVertex2f(0.4f, 0.4f);
	glEnd();

	//WHOLE FACE PART3
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.90f, 0.18f);
	glVertex2f(0.8f, -0.7f);
	glVertex2f(-0.5f, -0.7f);
	glVertex2f(-0.5f, 0.2f);
	glVertex2f(0.4f, 0.4f);
	glVertex2f(0.8f, -0.7f);
	glEnd();

	//UPPER PART OF FACE
	glBegin(GL_POLYGON);
	radius = 0.25;
	for (int i = 0; i <= 360; i++)
	{
		float degInRad = i * DEG2RAD;
		glColor3f(1.0f, 0.90f, 0.18f);
		glVertex2f((cos(degInRad)*radius) + 0.15, (sin(degInRad)*(radius - 0.23)) + 0.4);
	}
	glEnd();

	//LOWER PART OF FACE
	glBegin(GL_POLYGON);
	radius = 0.45;
	float cornor;
	for (int i = 89; i <= 270; i++)
	{
		cornor = 0.0;

		if (i <= 95) {
			cornor = 0.45f;
		}
		else if (i <= 175) {
			cornor = 0.43f;
		}
		else {
			cornor = 0.325;
		}

		float degInRad = i * DEG2RAD;
		glColor3f(1.0f, 0.90f, 0.18f);
		glVertex2f((cos(degInRad)*(radius - cornor)) - 0.5, (sin(degInRad)*(radius)) - 0.25);
	}
	glEnd();

	//LEFT EAR
	glBegin(GL_POLYGON);
	glColor3f(0.36f, 0.21f, 0.07f);
	glVertex2f(-1.0f, 0.8f);
	glVertex2f(-0.8f, 0.71f);
	glVertex2f(-0.75f, 0.5f);
	glVertex2f(-1.0f, 0.8f);
	glEnd();

	//RIGHT EAR
	glBegin(GL_POLYGON);
	glColor3f(0.36f, 0.21f, 0.07f);
	glVertex2f(0.9f, 0.65f);
	glVertex2f(1.0f, 0.7f);
	glVertex2f(0.8f, 0.4f);
	glVertex2f(0.9f, 0.65f);
	glEnd();

	//LEFT OUTER EYE
	glBegin(GL_POLYGON);
	radius = 0.05;
	for (int i = 0; i <= 360; i++)
	{
		float degInRad = i * DEG2RAD;
		glColor3f(0.36f, 0.21f, 0.07f);
		glVertex2f((cos(degInRad)*radius) - 0.3, sin(degInRad)*(radius + 0.05));
	}
	glEnd();

	//LEFT INNER EYE
	glBegin(GL_POLYGON);
	radius = 0.025;
	for (int i = 0; i <= 360; i++)
	{
		float degInRad = i * DEG2RAD;
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2f((cos(degInRad)*radius) - 0.315, (sin(degInRad)*(radius + 0.0125)) + 0.04);
	}
	glEnd();

	//RIGHT OUTER EYE
	glBegin(GL_POLYGON);
	radius = 0.05;
	for (int i = 0; i <= 360; i++)
	{
		float degInRad = i * DEG2RAD;
		glColor3f(0.36f, 0.21f, 0.07f);
		glVertex2f((cos(degInRad)*radius) + 0.35, sin(degInRad)*(radius + 0.05));
	}
	glEnd();

	//RIGHT INNER EYE
	glBegin(GL_POLYGON);
	radius = 0.025;
	for (int i = 0; i <= 360; i++)
	{
		float degInRad = i * DEG2RAD;
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2f((cos(degInRad)*radius) + 0.338, (sin(degInRad)*(radius + 0.0125)) + 0.045);
	}
	glEnd();

	//LEFT CHEEK
	glBegin(GL_POLYGON);
	radius = 0.08;
	for (int i = 0; i <= 360; i++)
	{
		float degInRad = i * DEG2RAD;
		//glColor3f(0.91f, 0.16f, 0.16f);
		glColor3f(0.5f, 0.0f, 0.0f);
		glVertex2f((cos(degInRad)*(radius + 0.02)) - 0.5, (sin(degInRad)* (radius + 0.04)) - 0.3);
	}
	glEnd();

	//RIGHT CHEEK
	glBegin(GL_POLYGON);
	radius = 0.08;
	for (int i = 0; i <= 360; i++)
	{
		float degInRad = i * DEG2RAD;
		glColor3f(0.5f, 0.0f, 0.0f);
		glVertex2f((cos(degInRad)*(radius + 0.02)) + 0.48, (sin(degInRad)* (radius + 0.04)) - 0.34);
	}
	glEnd();

	//NOSE
	glBegin(GL_POLYGON);
	radius = 0.025;
	for (int i = 0; i <= 360; i++)
	{
		float degInRad = i * DEG2RAD;
		glColor3f(0.36f, 0.21f, 0.07f);
		glVertex2f((cos(degInRad)*(radius + 0.02)) - 0.05, (sin(degInRad)* (radius)) - 0.18);
	}
	glEnd();

	//MOUTH
	glBegin(GL_POLYGON);
	radius = 0.1;
	for (int i = 0; i <= 360; i++)
	{
		float degInRad = i * DEG2RAD;
		glColor3f(0.91f, 0.16f, 0.16f);
		glVertex2f((cos(degInRad)*(radius)), (sin(degInRad)* (radius + 0.025)) - 0.5);
	}
	glEnd();

}
//--------------------------------------------------------------------

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int nCmdShow)
{
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hInstance = GetModuleHandle(NULL);
	wc.lpfnWndProc = WindowProcedure;
	wc.lpszClassName = WINDOW_TITLE;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClassEx(&wc)) return false;

	HWND hWnd = CreateWindow(WINDOW_TITLE, WINDOW_TITLE, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 1200, 700,
		NULL, NULL, wc.hInstance, NULL);

	//--------------------------------
	//	Initialize window for OpenGL
	//--------------------------------

	HDC hdc = GetDC(hWnd);

	//	initialize pixel format for the window
	initPixelFormat(hdc);

	//	get an openGL context
	HGLRC hglrc = wglCreateContext(hdc);

	//	make context current
	if (!wglMakeCurrent(hdc, hglrc)) return false;

	//--------------------------------
	//	End initialization
	//--------------------------------

	ShowWindow(hWnd, nCmdShow);

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) break;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		if (displayKey == 1)
			pahangFlag();
		else if (displayKey == 2)
			negeriSembilanFlag();
		else if (displayKey == 3)
			englandFlag();
		else if (displayKey == 4)
			scotlandFlag();
		else if (displayKey == 5)
			japanFlag();
		else if (displayKey == 6)
			pikachuMeme();

		SwapBuffers(hdc);
	}

	UnregisterClass(WINDOW_TITLE, wc.hInstance);

	return true;
}
//--------------------------------------------------------------------