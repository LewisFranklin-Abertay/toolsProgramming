#pragma once
#include "afxdialogex.h"
#include "resource.h"
#include "afxwin.h"
#include "SceneObject.h"
#include <vector>

// SelectDialogue dialog

class TransformWindow : public CDialogEx
{
	DECLARE_DYNAMIC(TransformWindow)

public:
	TransformWindow(CWnd* pParent = NULL);
	virtual ~TransformWindow();
					
	inline void passInObject(SceneObject* currentSelectedObject) { m_holdObject = currentSelectedObject; };
	inline void passOutObject(SceneObject& currentSelectedObject) { currentSelectedObject = *m_holdObject; };

	bool transChanged() const { return changedData; }
	void HasObjectDataChanged() { changedData = false; };
	void DataChanged();
																				// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX) override;
	afx_msg void End();		//kill the dialogue

	DECLARE_MESSAGE_MAP()

private:
	SceneObject * m_holdObject;

	bool changedData = false;
};