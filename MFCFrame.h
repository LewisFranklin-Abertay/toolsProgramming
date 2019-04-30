#pragma once
#include <afxwin.h> 
#include <afxext.h>
#include "MFCRenderFrame.h"
#include "ToolMain.h"
#include "TransformWindow.h"



class CMyFrame : public CFrameWnd
{
protected:
	//	DECLARE_DYNAMIC(CMainFrame)

public:

	CMenu			m_menu1;	//menu bar
	CStatusBar		m_wndStatusBar;
	CToolBar		m_toolBar;
	CChildRender	m_DirXView;
	ToolMain*		m_toolMain;
	TransformWindow m_TransformDialogue;

public:
	CMyFrame();
	void SetCurrentSelectionID(int ID);
	afx_msg void OnUpdatePage(CCmdUI *pCmdUI);
	afx_msg void LoadTerrain();
	afx_msg void LoadTerrainTexture();
	afx_msg void NewModel();

private:	//overrides
	int		m_selectionID;	//

							//note the afx_message keyword is linking this method to message map access.
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()	// required macro for message map functionality  One per class
};