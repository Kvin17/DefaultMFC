#pragma once
#include <afxwin.h>
#include <afxext.h>
#include <afxcmn.h>
#include <afxdll_.h>
#include "resource.h"


class CMyFrameWnd :public CFrameWnd
{
public:
    int my_poly_coef[7];
    static const int my_out_size = 30;
    int my_poly[7], my_poly_func[my_out_size + 1];

    CMyFrameWnd::CMyFrameWnd();

protected:
    CToolBar WndToolBar;
    bool my_paint = false;
    void Function(int* in_mas, int* out_mas, int out_sz);
    afx_msg void OnCalculateResult();
    afx_msg void CMyFrameWnd::OnPaint();
    //Кнопки

    afx_msg void OnAbout();
    afx_msg void OnExit();
    afx_msg void OnFileOpen();
    afx_msg void OnFileSave();
    afx_msg void OnFileDelete();
    afx_msg void OnProjectData();
    afx_msg void OnProjectRun();
    afx_msg void OnResultText();
    afx_msg void OnResultGraf();
    int CMyFrameWnd::OnCreate(LPCREATESTRUCT lpCreateStruct);
    DECLARE_MESSAGE_MAP();
};