#include <afxwin.h>
#include <afxext.h>
#include <windows.h>
#include "resource.h"

class CMyFrameWnd:public CFrameWnd
{
    public:
        CMyFrameWnd();
    protected:
        CToolBar WndToolBar;
        afx_msg void OnAbout()
        {
            ::MessageBox(NULL, (LPCSTR)"...", (LPCSTR)"About", MB_OK); 
        }
        afx_msg void OnExit()
        {
            ::MessageBox(NULL, (LPCSTR)"...", (LPCSTR)"QUIT", MB_OK);
            //SendMessage(WM_CLOSE);
        }
        afx_msg void OnFileOpen()
        {
            ::MessageBox(NULL, (LPCSTR)"...", (LPCSTR)"FileOpen", MB_OK);
        }
        afx_msg void OnFileSave()
        {
            ::MessageBox(NULL, (LPCSTR)"...", (LPCSTR)"FileSave", MB_OK);
        }
        afx_msg void OnFileDelete()
        {
            ::MessageBox(NULL, (LPCSTR)"...", (LPCSTR)"FileDelete", MB_OK);
        }
        afx_msg void OnProjectData()
        {
            ::MessageBox(NULL, (LPCSTR)"...", (LPCSTR)"ProjectData", MB_OK);
        }
        afx_msg void OnProjectRun()
        {
            ::MessageBox(NULL, (LPCSTR)"...", (LPCSTR)"ProjectRun", MB_OK);
        }
        afx_msg void OnResultText()
        {
            ::MessageBox(NULL, (LPCSTR)"...", (LPCSTR)"ResultText", MB_OK);
        }
        afx_msg void OnResultGraf()
        {
            ::MessageBox(NULL, (LPCSTR)"...", (LPCSTR)"ResultGraf", MB_OK);
        }
        int CMyFrameWnd::OnCreate(LPCREATESTRUCT lpCreateStruct);
        DECLARE_MESSAGE_MAP();
};

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



CMyFrameWnd::CMyFrameWnd()
{
    Create(NULL, (LPCTSTR)"Project", WS_OVERLAPPEDWINDOW, rectDefault, NULL, MAKEINTRESOURCE(IDR_MENU1));
};

int CMyFrameWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    CFrameWnd::OnCreate(lpCreateStruct);
    WndToolBar.Create(this);
    WndToolBar.LoadToolBar(MAKEINTRESOURCE(IDR_TOOLBAR1));
    return 0;
}

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