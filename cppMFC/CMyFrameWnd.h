#pragma once
#include <afxwin.h>
#include <afxext.h>
#include <windows.h>
#include "resource.h"
#include "CMyDialog.h"

class CMyFrameWnd :public CFrameWnd
{
public:
    int my_poly_coef[5];

    CMyFrameWnd::CMyFrameWnd()
    {
        m_bAutoMenuEnable = FALSE;
        Create(NULL, (LPCTSTR)"Project", WS_OVERLAPPEDWINDOW, rectDefault, NULL, MAKEINTRESOURCE(IDR_MENU1));
    };
protected:
    CToolBar WndToolBar;
    //обчислення
    afx_msg void OnCalculateData()
    {
        CMyDialog my_Dialog;
        my_Dialog.DoModal();
    }
    afx_msg void OnCalculateRun()
    {
        CString buf_data;

        buf_data.Format("a1 = %d, b1 = %d, a2 = %d, b2 = %d, c2 = %d ", my_poly_coef[0],
            my_poly_coef[1], my_poly_coef[2], my_poly_coef[3], my_poly_coef[4]);
        MessageBox(buf_data);
    }
    //Кнопки
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
    int CMyFrameWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
    {
        CFrameWnd::OnCreate(lpCreateStruct);
        WndToolBar.Create(this);
        WndToolBar.LoadToolBar(MAKEINTRESOURCE(IDR_TOOLBAR1));
        return 0;
    };
    DECLARE_MESSAGE_MAP();
};

