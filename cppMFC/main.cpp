#include <afxwin.h>
#include <afxext.h>
#include <windows.h>
#include "resource.h"



class CMyFrameWnd :public CFrameWnd
{
public:
    int my_poly_coef[5];
    static const int my_out_size = 10;
    int my_poly[5], my_poly_func[2 * my_out_size+1];


    CMyFrameWnd::CMyFrameWnd();

protected:
    CToolBar WndToolBar;
    //обчислення
    afx_msg void OnCalculateData();
    afx_msg void OnCalculateRun();
    afx_msg void OnCalculateResult();
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



//
//Dialog
//
class CMyDialog : public CDialog
{
public:
    CMyDialog(UINT nIDTemplate = IDD_DIALOG1, CWnd* pParentWnd = NULL);
    CEdit my_DlgEdit;

protected:
    void DoDataExchange(CDataExchange* pDX);
    virtual BOOL OnInitDialog();
    virtual void OnOK();

    DECLARE_MESSAGE_MAP();
};
//Кнопки
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

//Functions
    //CMyFrameWnd
CMyFrameWnd::CMyFrameWnd()
{
    m_bAutoMenuEnable = FALSE;
    Create(NULL, (LPCTSTR)"Project", WS_OVERLAPPEDWINDOW, rectDefault, NULL, MAKEINTRESOURCE(IDR_MENU1));
};

    afx_msg void CMyFrameWnd::OnCalculateData()
    {
        CMyDialog my_Dialog;
        my_Dialog.DoModal();
    }
    afx_msg void CMyFrameWnd::OnCalculateResult()
    {
        CString buf_data, res_data;
        for (int i = 0; i < 2 * my_out_size + 1; i++)
        {
            buf_data.Format("y[%d] = %d \n, i, my_poly_func[i]");
            res_data += buf_data;
        }
        MessageBox(res_data);
    }
    afx_msg void CMyFrameWnd::OnCalculateRun()
    {
        CString buf_data;

        buf_data.Format("a1 = %d, b1 = %d, a2 = %d, b2 = %d, c2 = %d ", my_poly_coef[0],
            my_poly_coef[1], my_poly_coef[2], my_poly_coef[3], my_poly_coef[4]);
        MessageBox(buf_data);
        HINSTANCE my_hdll = AfxLoadLibrary("asmDynamicFunc.dll");
        typedef void (*CALFUN)(int*, int*, int);
        CALFUN my_CalcFunc = (CALFUN)GetProcAddress(my_hdll, "CalculateFunc");
        (*my_CalcFunc)(my_poly_coef, my_poly_func, 2 * my_out_size + 1);
        AfxFreeLibrary(my_hdll);
    }
    //Кнопки
    afx_msg void CMyFrameWnd::OnAbout()
    {
        ::MessageBox(NULL, (LPCSTR)"...", (LPCSTR)"About", MB_OK);
    }
    afx_msg void CMyFrameWnd::OnExit()
    {
       // ::MessageBox(NULL, (LPCSTR)"...", (LPCSTR)"QUIT", MB_OK);
       SendMessage(WM_CLOSE);
    }
    afx_msg void CMyFrameWnd::OnFileOpen()
    {
        ::MessageBox(NULL, (LPCSTR)"...", (LPCSTR)"FileOpen", MB_OK);
    }
    afx_msg void CMyFrameWnd::OnFileSave()
    {
        ::MessageBox(NULL, (LPCSTR)"...", (LPCSTR)"FileSave", MB_OK);
    }
    afx_msg void CMyFrameWnd::OnFileDelete()
    {
        ::MessageBox(NULL, (LPCSTR)"...", (LPCSTR)"FileDelete", MB_OK);
    }
    afx_msg void CMyFrameWnd::OnProjectData()
    {
        //::MessageBox(NULL, (LPCSTR)"...", (LPCSTR)"ProjectData", MB_OK);
    }
    afx_msg void CMyFrameWnd::OnProjectRun()
    {
        OnCalculateData();

        //::MessageBox(NULL, (LPCSTR)my_poly_coef, (LPCSTR)"dd", MB_OK);
    }
    afx_msg void CMyFrameWnd::OnResultText()
    {::MessageBox(NULL, (LPCSTR)"l", (LPCSTR)"dd", MB_OK);
        ::MessageBox(NULL, (LPCSTR)"...", (LPCSTR)"ResultText", MB_OK);
    }
    afx_msg void CMyFrameWnd::OnResultGraf()
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
    //CMyDialog
    CMyDialog::CMyDialog(UINT nIDTemplate, CWnd* pParentWnd):CDialog(nIDTemplate, pParentWnd)
    {

    }
    BOOL CMyDialog::OnInitDialog()
    {
        CDialog::OnInitDialog();
        CString buf_data;
        buf_data.Format("%d", 0);
        my_DlgEdit.SetWindowText(buf_data);
        return 1;
    }
    void CMyDialog::OnOK()
    {
        CString tmp_data;
        CMyFrameWnd* pMainWnd = (CMyFrameWnd*)(this->GetParent());
        my_DlgEdit.GetWindowText(tmp_data);
        pMainWnd->my_poly_coef[0] = atoi(tmp_data);

        CDialog::OnOK();
    }
    void CMyDialog::DoDataExchange(CDataExchange* pDX)
    {
        CDialog::DoDataExchange(pDX);
        DDX_Control(pDX, IDC_EDIT1, my_DlgEdit);
    }
//

//Program
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