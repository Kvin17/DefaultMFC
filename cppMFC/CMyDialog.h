#pragma once
#include <afxwin.h>
#include <afxext.h>
#include <windows.h>
#include "resource.h"
#include "CMyFrameWnd.h"
    
class CMyDialog : public CDialog
{
public :
	CMyDialog(UINT nIDTemplate = IDD_DIALOG1, CWnd* pParentWnd = NULL);
	CEdit my_DlgEdit;

protected:
	void DoDataExchange(CDataExchange* pDX);
	virtual BOOL OnInitDialog()
	{
		CDialog::OnInitDialog();
		CString buf_data;
		buf_data.Format("%d", 0);
		my_DlgEdit.SetWindowTextA(buf_data);
	}
	virtual void OnOK()
	{
		CString tmp_data;
		CMyFrameWnd* pMainWnd = (CMyFrameWnd*)(this->GetParent());
		my_DlgEdit.GetWindowText(tmp_data);
		pMainWnd->my_poly_coef[0] = atoi(tmp_data);

		CDialog::OnOK();
	}

	DECLARE_MESSAGE_MAP();
};

