#pragma once

#include <afxwin.h>
#include <afxext.h>
#include <windows.h>
#include "resource.h"
#include "CMyFrameWnd.h"
#include "CMyDialog.h"

//Êíîïêè
BEGIN_MESSAGE_MAP(CMyFrameWnd, CFrameWnd)
    //Menu
    ON_COMMAND(ID_ABOUT, &CMyFrameWnd::OnAbout)
    ON_COMMAND(ID_EXIT, &CMyFrameWnd::OnExit)
    ON_COMMAND(ID_FILE_OPEN, &CMyFrameWnd::OnFileOpen)
    ON_COMMAND(ID_FILE_SAVE, &CMyFrameWnd::OnFileSave)
    ON_COMMAND(ID_FILE_DELETE, &CMyFrameWnd::OnFileDelete)
    ON_COMMAND(ID_PROJECT_DATA, &CMyFrameWnd::OnProjectData)
    ON_COMMAND(ID_PROJECT_RUN, &CMyFrameWnd::OnProjectRun)
    ON_COMMAND(ID_RESULT_TEXT, &CMyFrameWnd::OnResultText)
    ON_COMMAND(ID_RESULT_GRAF, &CMyFrameWnd::OnResultGraf)

    //ToolBar
    ON_COMMAND(ID_BUTTON_ABOUT, &CMyFrameWnd::OnAbout)
    ON_COMMAND(ID_BUTTON_QUIT, &CMyFrameWnd::OnExit)
    ON_COMMAND(ID_BUTTON_FILE_OPEN, &CMyFrameWnd::OnFileOpen)
    ON_COMMAND(ID_BUTTON_FILE_SAVE, &CMyFrameWnd::OnFileSave)
    ON_COMMAND(ID_BUTTON_FILE_DELETE, &CMyFrameWnd::OnFileDelete)
    ON_COMMAND(ID_BUTTON_PROJECT_DATA, &CMyFrameWnd::OnProjectData)
    ON_COMMAND(ID_BUTTON_PROJECT_RUN, &CMyFrameWnd::OnProjectRun)
    ON_COMMAND(ID_BUTTON_RESULT_TEXT, &CMyFrameWnd::OnResultText)
    ON_COMMAND(ID_BUTTON_RESULT_GRAF, &CMyFrameWnd::OnResultGraf)

    //...
    ON_WM_CREATE()
END_MESSAGE_MAP();

//Dialog
BEGIN_MESSAGE_MAP(CMyDialog, CDialog)

END_MESSAGE_MAP();

class CMyApp : public CWinApp
{
public:
    virtual BOOL InitInstance();
};
BOOL CMyApp :: InitInstance()
{
    CMyFrameWnd *pMainWnd = new CMyFrameWnd;
    m_pMainWnd = pMainWnd;
    m_pMainWnd->ShowWindow(m_nCmdShow);
    m_pMainWnd->UpdateWindow();
        return TRUE;
};

CMyApp app;