#pragma once
#include <afxwin.h>
#include <afxext.h>
#include <windows.h>
#include "resource.h"
#include "CMyFrameWnd.h"


#define LIST_SIZE 4
#define EDIT_SIZE 3

class CMyDialog : public CDialog
{
public :
	CMyDialog(UINT nIDTemplate = IDD_DIALOG1, CWnd* pParentWnd = NULL);
	CEdit my_DlgEdit[EDIT_SIZE];
	CListBox my_listbox[LIST_SIZE];
	int list_coef_range = 10;

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif
protected:
	void DoDataExchange(CDataExchange* pDX);
	void LoadListBox();
	virtual BOOL OnInitDialog();
	virtual void OnOK();

	DECLARE_MESSAGE_MAP();
};

