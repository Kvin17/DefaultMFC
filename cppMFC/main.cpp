#include "main.h"
#include "CMyFrameWnd.h"


BOOL CMyApp::InitInstance()
{
    CMyFrameWnd* pMainWnd = new CMyFrameWnd;
    m_pMainWnd = pMainWnd;
    m_pMainWnd->ShowWindow(m_nCmdShow);
    m_pMainWnd->UpdateWindow();
    return TRUE;
};

CMyApp app;
