#include "CMyDialog.h"
#include "CMyFrameWnd.h"

//Dialog
BEGIN_MESSAGE_MAP(CMyDialog, CDialog)

END_MESSAGE_MAP();

//Functions
    //CMyFrameWnd

    //CMyDialog
CMyDialog::CMyDialog(UINT nIDTemplate, CWnd* pParentWnd) :CDialog(nIDTemplate, pParentWnd)
{

}
BOOL CMyDialog::OnInitDialog()
{
    CDialog::OnInitDialog();
    CString buf_data;
    buf_data.Format("%d", 0);
    for (int i = 0; i < EDIT_SIZE; i++)
        my_DlgEdit[i].SetWindowText(buf_data);
    for (int i = 0; i < LIST_SIZE; i++)
        my_listbox[i].SetWindowText(buf_data);
  
    LoadListBox();
    return 1;
}
void CMyDialog::OnOK()
{
    CString tmp_data[(LIST_SIZE+EDIT_SIZE)];
    CMyFrameWnd* pMainWnd = (CMyFrameWnd*)(this->GetParent());  
    for (int i = 0; i < LIST_SIZE; i++)
    {
        my_listbox[i].GetText(my_listbox[i].GetCurSel(), tmp_data[i]);
        pMainWnd->my_poly_coef[i] = atoi(tmp_data[i]);
    }
    for (int i = 0; i < EDIT_SIZE; i++)
    {
        my_DlgEdit[i].GetWindowText(tmp_data[(i+LIST_SIZE)]);
        //my_DlgEdit[i].GetDlgItemText(my_DlgEdit[i].GetCurSel(), tmp_data[i]);
        pMainWnd->my_poly_coef[(i + LIST_SIZE)] = atoi(tmp_data[(i + LIST_SIZE)]);
    }
    CDialog::OnOK();
}
void CMyDialog :: LoadListBox()
{
    
    CString str = " ";
    for (int i = 0; i < list_coef_range; i++)
    {
        str.Format("%d", i);
        for (int j = 0; j < LIST_SIZE; j++)
        {
            my_listbox[j].AddString(str);
        }
    }
}
void CMyDialog::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_EDIT1, my_DlgEdit[0]);
    DDX_Control(pDX, IDC_EDIT2, my_DlgEdit[1]);
    DDX_Control(pDX, IDC_EDIT3, my_DlgEdit[2]);
    DDX_Control(pDX, IDC_LIST1, my_listbox[0]);
    DDX_Control(pDX, IDC_LIST2, my_listbox[1]);
    DDX_Control(pDX, IDC_LIST3, my_listbox[2]);
    DDX_Control(pDX, IDC_LIST4, my_listbox[3]);
   
}
//