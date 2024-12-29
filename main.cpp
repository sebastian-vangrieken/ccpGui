#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>
#include <iostream>

LRESULT CALLBACK WindowProc(
    HWND hwnd,
    UINT uMsg,
    WPARAM wParam,
    LPARAM lParam
);

void createDebugConsole();
void OnSize(HWND, WPARAM, LPARAM);

int WINAPI wWinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    PWSTR pCmdLine,
    int nCmdShow
) {
    const wchar_t CLASS_NAME[] = L"Sample Window Class";

    WNDCLASS wc = {};

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0, // Optional window style.
        CLASS_NAME,
        L"Learn to Program Windows",
        WS_OVERLAPPEDWINDOW, // Window style.

        // x-position, y-position, width, height.
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL, // Parent window.
        NULL, // Menu.
        hInstance,
        NULL // Additional Application data.
    );

    if (hwnd == NULL) {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }


    return 0;
}

LRESULT CALLBACK WindowProc(
    HWND hwnd,
    UINT uMsg,
    WPARAM wParam,
    LPARAM lParam
) {
    switch (uMsg) {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

        EndPaint(hwnd, &ps);
    }
    return 0;

    case WM_SIZE:
    {
        OnSize(hwnd, wParam, lParam);
    }
    return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

void OnSize(HWND hwnd, WPARAM wParam, LPARAM lParam) {
    createDebugConsole();

    switch (wParam) {
    case SIZE_RESTORED:
        std::cout << (UINT)(wParam) << "\n";
        std::cout << "Resizing...\n";
        std::cout << "Width: " << LOWORD(lParam) << " Height: " << HIWORD(lParam) << "\n";
    case SIZE_MINIMIZED:
        std::cout << (UINT)(wParam) << "\n";
        std::cout << "Window minimized\n";
    case SIZE_MAXIMIZED:
        std::cout << (UINT)(wParam) << "\n";
        std::cout << "Window maximized\n";
    }
}

void createDebugConsole() {
    AllocConsole();
    FILE* fp;
    freopen_s(&fp, "CONOUT$", "w", stdout);
    freopen_s(&fp, "CONOUT$", "w", stderr);
    freopen_s(&fp, "CONIN$", "r", stdin);
}