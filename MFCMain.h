#pragma once

#include <afxwin.h> 
#include <afxext.h>
#include <afx.h>
#include "pch.h"
#include "Game.h"
#include "ToolMain.h"
#include "Inspector.h"
#include "resource.h"
#include "MFCFrame.h"
#include "SelectDialogue.h"
#include "TransformWindow.h"


class MFCMain : public CWinApp
{
public:
	MFCMain();
	~MFCMain();
	BOOL InitInstance();
	int  Run();

private:

	CMyFrame * m_frame;	//handle to the frame where all our UI is
	CMyFrame * m_Inspector;	//handle to the inspector window
	HWND m_toolHandle;	//Handle to the MFC window
	HWND m_inspectorHandle;	//Handle to the MFC window
	ToolMain m_ToolSystem;	//Instance of Tool System that we interface to. 
	Inspector m_InspectorSystem;	//Instance of Tool System that we interface to. 
	CRect WindowRECT;	//Window area rectangle. 
	CRect InspectorWindowRECT;	//Window area rectangle. 
	SelectDialogue m_ToolSelectDialogue;			//for modeless dialogue, declare it here
	TransformWindow m_TransformDialogue;
	int m_width;
	int m_height;

	//Interface funtions for menu and toolbar etc requires
	afx_msg void MenuFileQuit();
	afx_msg void MenuFileSaveTerrain();
	afx_msg void MenuEditLoadTerrain();
	afx_msg void MenuEditLoadTerrainTexture();
	afx_msg void MenuEditNewModel();
	afx_msg void MenuEditSelect();
	afx_msg void MenuEditInspector();
	afx_msg void MenuEditTransform();
	afx_msg	void ToolBarButton1();
	afx_msg	void ToolBarButton2();


	DECLARE_MESSAGE_MAP()	// required macro for message map functionality  One per class
};
