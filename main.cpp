#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>

int WINAPI wWinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    PWSTR pCmdLine,
    int nCmdShow
) {
    // MessageBox(NULL, pCmdLine, L"title", MB_OK);
    const wchar_t CLASS_NAME[] = L"Sample Window Class";

    WNDCLASS wc = {};

    // wc.lpfnWndProc = WindowProc;
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

    return 0;
}