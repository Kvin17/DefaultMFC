#include "CMyFrameWnd.h"
#include "CMyDialog.h"
#include <string>
#include <mydll.h>
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
    ON_WM_PAINT()
    //...
    ON_WM_CREATE()
END_MESSAGE_MAP();

CMyFrameWnd::CMyFrameWnd()
{
    m_bAutoMenuEnable = FALSE;
    Create(NULL, (LPCTSTR)"Project", WS_OVERLAPPEDWINDOW, rectDefault, NULL, MAKEINTRESOURCE(IDR_MENU1));
};
//Кнопки
afx_msg void CMyFrameWnd::OnAbout()
{
    ::MessageBox(NULL, (LPCSTR)"Zhenia", (LPCSTR)"About", MB_OK);
}
afx_msg void CMyFrameWnd::OnExit()
{ 
    SendMessage(WM_CLOSE);
}
afx_msg void CMyFrameWnd::OnFileOpen()
{
    CFile my_File;
    CFileDialog my_FileDialog(TRUE, "txt");
    if (my_FileDialog.DoModal() == IDOK)
    {
        CStdioFile file(my_FileDialog.GetPathName(), CFile::modeRead);
        CString numBuffer;
        for (int i = 0; i < my_out_size; i++)
        {
            file.ReadString(numBuffer);
            my_poly_func[i] = _ttoi(numBuffer);
        }
        file.Close();
    }
}
afx_msg void CMyFrameWnd::OnFileSave()
{
    CFile my_File;
    CFileDialog my_FileDialog(FALSE, "txt", "Result");
    if (my_FileDialog.DoModal() == IDOK)
    {
        CStdioFile file(my_FileDialog.GetPathName(), CFile::modeWrite | CFile::modeCreate);
        CString numBuffer;
        for (int i = 0; i < my_out_size; i++)
        {
            numBuffer.Format(_T("%d\n"), my_poly_func[i]);
            file.WriteString(numBuffer);
        }
        file.Close();
    }
}
afx_msg void CMyFrameWnd::OnFileDelete()
{
   
    CFileDialog fileDlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, _T("All Files (*.*)|*.*||"), this);

    // Відобразити діалогове вікно вибору файлу
    if (fileDlg.DoModal() == IDOK)
    {
        CString filePath = fileDlg.GetPathName(); // Отримати шлях до вибраного файлу

        // Видалити файл
        if (DeleteFile(filePath))
        {
            AfxMessageBox(_T("Файл видалено успішно."), MB_OK | MB_ICONINFORMATION);
        }
        else
        {
            AfxMessageBox(_T("Не вдалося видалити файл."), MB_OK | MB_ICONERROR);
        }
    }
}
afx_msg void CMyFrameWnd::OnProjectData()
{
    CMyDialog my_Dialog;
    my_Dialog.DoModal();
}
afx_msg void CMyFrameWnd::OnProjectRun()
{
    CString buf_data;

    buf_data.Format("a1 = %d, b1 = %d, a2 = %d, b2 = %d, c1 = %d, c2 = %d, c3 = %d ",
        my_poly_coef[0], my_poly_coef[1], my_poly_coef[2], my_poly_coef[3], my_poly_coef[4], my_poly_coef[5], my_poly_coef[6]);

    MessageBox(buf_data);

    HINSTANCE load;
    load = LoadLibrary("mydll.dll");
    typedef void (*fn)(int*, int*, int);
    fn Fn;
    Fn = (fn)GetProcAddress(load, "CalcFunction");
    Fn(my_poly_coef, my_poly_func, my_out_size+1);
    FreeLibrary(load);
}
afx_msg void CMyFrameWnd::OnResultText()
{
    CString buf_data, res_data;
    for (int i = 0; i <  my_out_size + 1; i++)
    {
        buf_data.Format("y[%d] = %d \n", i, my_poly_func[i]);
        res_data += buf_data;
    }
    MessageBox(res_data);
}
afx_msg void CMyFrameWnd::OnResultGraf()
{
    my_paint = true;
    SendMessage(WM_PAINT);
}
int CMyFrameWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    CFrameWnd::OnCreate(lpCreateStruct);
    WndToolBar.Create(this);
    WndToolBar.LoadToolBar(MAKEINTRESOURCE(IDR_TOOLBAR1));
    return 0;
};
afx_msg void CMyFrameWnd::OnPaint()
{
    CFrameWnd::OnPaint();
    if (my_paint)
    {
        CRect my_rect;
        this->GetClientRect(&my_rect);
        CDC* my_wDC = this->GetDC();
        CPen my_ax(PS_SOLID, 3, RGB(0, 0, 0))
            , my_ax_dt(PS_SOLID, 1, RGB(0, 0, 0))
            , my_gr(PS_SOLID, 5, RGB(255, 0, 0));
        CFont my_fnt;
        my_fnt.CreatePointFont(120, "SF Mono");
        int out_max = 15, out_min = -15;
        double ms_X, ms_Y;
        int gap = 5;
        int h_graf=0;
      
        for (size_t i = 0; i < my_out_size + 1; i++)
        {
            if (i != 8 || i != 18) {
                if (out_max < my_poly_func[i])
                    out_max = my_poly_func[i];
                if (out_min > my_poly_func[i])
                    out_max = my_poly_func[i];
            }
            else
                continue;
        }
        if (out_max > 0)
        {
            if (out_max > -(out_min))
                h_graf = out_max;
            else h_graf = -(out_min);
        }
        CPoint zero(50, 50);
        int field_h = 600, field_w = 930;
        ms_X = (double)field_w / (double)(my_out_size+1);
        ms_Y =(double)(field_h/2) /(double) h_graf;
        my_wDC->SelectObject(my_fnt);

        my_wDC->SelectObject(my_ax);
        my_wDC->MoveTo(zero.x,zero.y);
        my_wDC->LineTo(zero.x+field_w, zero.y);
        my_wDC->LineTo(zero.x + field_w,zero.y+field_h);
        my_wDC->LineTo(zero.x, zero.y+field_h);
        my_wDC->LineTo(zero.x, zero.y);
       
       
        my_wDC->TextOut((field_w / 2)+zero.x-1, (field_h / 2)+zero.y-10, "0");
        my_wDC->SelectObject(my_ax_dt);
        //x
        double zero_axis = ((double)field_h/31)*15;
        for (size_t i = 0; i < my_out_size + 1; i++)
        {
            if (i == 15)
            {
                my_wDC->SelectObject(my_ax);
               
            }
            else
            {
                my_wDC->SelectObject(my_ax_dt);
            }
            my_wDC->MoveTo(ms_X * i + zero.x, zero.y);
            my_wDC->LineTo(ms_X * i + zero.x, field_h + zero.y);
        }
        my_wDC->TextOut((field_w)+zero.x-11, (field_h/2)+zero.y-10, "X");
        double temp_gap = (double)(field_h / (double)(my_out_size + 1));     
        //y
        for (size_t i = 0; i < my_out_size + 1; i++)
        {
            if (i == 16)
            {
                my_wDC->SelectObject(my_ax); 
            }
            else
            {
                my_wDC->SelectObject(my_ax_dt);
            }
            my_wDC->MoveTo(zero.x, temp_gap * i + zero.y);
            my_wDC->LineTo(field_w+zero.x, temp_gap * i + zero.y);
        }
        my_wDC->TextOut((field_w/2)+zero.x,zero.y +5, "Y");
        my_wDC->SelectObject(my_gr);
        my_wDC->MoveTo(zero.x, field_h -(my_poly_func[0] * ms_Y) + zero.y - zero_axis);
        for (size_t i = 0; i < my_out_size; i++)
        {
            if (i == 8)
            {
                my_wDC->MoveTo(9 * ms_X + zero.x, field_h -(my_poly_func[9] * ms_Y) + zero.y - zero_axis);
            }
            else if (i == 18)
            {
                my_wDC->MoveTo(19 * ms_X + zero.x, field_h -(my_poly_func[19] * ms_Y) + zero.y - zero_axis);
            }
            else
            {
                my_wDC->LineTo(i * ms_X + zero.x, field_h -(my_poly_func[i] * ms_Y) + zero.y - zero_axis);
            }
                
        }
    }
}
