// TransformWindow.cpp : implementation file
//

#include "stdafx.h"
#include "TransformWindow.h"

// TransformWindow dialog

IMPLEMENT_DYNAMIC(TransformWindow, CDialogEx)

//Message map.  Just like MFCMAIN.cpp.  This is where we catch button presses etc and point them to a handy dandy method.
BEGIN_MESSAGE_MAP(TransformWindow, CDialogEx)

	ON_EN_CHANGE(IDC_EDIT1, DataChanged)
	ON_EN_CHANGE(IDC_EDIT2, DataChanged)
	ON_EN_CHANGE(IDC_EDIT3, DataChanged)
	ON_EN_CHANGE(IDC_EDIT4, DataChanged)
	ON_EN_CHANGE(IDC_EDIT5, DataChanged)
	ON_EN_CHANGE(IDC_EDIT6, DataChanged)
	ON_EN_CHANGE(IDC_EDIT7, DataChanged)
	ON_EN_CHANGE(IDC_EDIT8, DataChanged)
	ON_EN_CHANGE(IDC_EDIT9, DataChanged)
	ON_COMMAND(IDC_BUTTON1, LoadTexture)
	ON_COMMAND(IDOK, &TransformWindow::End)					//ok button

END_MESSAGE_MAP()


TransformWindow::TransformWindow(CWnd * pParent)			//constructor used in modeless
	: CDialogEx(IDD_DIALOG2, pParent)
{
}

TransformWindow::~TransformWindow()
{
}



void TransformWindow::DoDataExchange(CDataExchange * pDX)
{
	CDialogEx::DoDataExchange(pDX);

	if (m_holdObject)
	{
		DDX_Text(pDX, IDC_EDIT1, m_holdObject->posX);
		DDX_Text(pDX, IDC_EDIT2, m_holdObject->posY);
		DDX_Text(pDX, IDC_EDIT3, m_holdObject->posZ);

		DDX_Text(pDX, IDC_EDIT4, m_holdObject->rotX);
		DDX_Text(pDX, IDC_EDIT5, m_holdObject->rotY);
		DDX_Text(pDX, IDC_EDIT6, m_holdObject->rotZ);

		DDX_Text(pDX, IDC_EDIT7, m_holdObject->scaX);
		DDX_Text(pDX, IDC_EDIT8, m_holdObject->scaY);
		DDX_Text(pDX, IDC_EDIT9, m_holdObject->scaZ);

	}
}

void TransformWindow::DataChanged()
{
	// Read values from dialog controls
	if (m_holdObject)
	{
		UpdateData(TRUE);
		changedData = true;
	}
}
void TransformWindow::LoadTexture()
{
	const TCHAR szFilter[] = _T("DDS Files (*.dds)|*.dds||");
	CFileDialog dlg(TRUE, _T("dds"), NULL, OFN_HIDEREADONLY | OFN_FILEMUSTEXIST, szFilter, this);
	if (dlg.DoModal() == IDOK)
	{
		CString sFilePath = dlg.GetPathName();
		MessageBox(sFilePath, _T("FIle Loaded"));

		std::wstring w1 = sFilePath;
		std::string out_a;
		out_a.assign(w1.begin(), w1.end());
		m_holdObject->tex_diffuse_path = out_a;
		UpdateData(TRUE);
		changedData = true;
	}
}
void TransformWindow::End()
{
	DestroyWindow();	//destory the window properly.  INcluding the links and pointers created.  THis is so the dialogue can start again. 
}


