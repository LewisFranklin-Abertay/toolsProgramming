#pragma once

#include <afxext.h>
#include "pch.h"
#include "Game.h"
#include "sqlite3.h"
#include "SceneObject.h"
#include "InputCommands.h"
#include <vector>


class ToolMain
{
	constexpr static long BORDER_OFFSET = 2;

public: //methods
	ToolMain();
	~ToolMain();

	//onAction - These are the interface to MFC
	int		getCurrentSelectionID();										//returns the selection number of currently selected object so that It can be displayed.
	void	onActionInitialise(HWND handle, int width, int height);			//Passes through handle and hieght and width and initialises DirectX renderer and SQL LITE
	void	onActionFocusCamera();
	void	onActionLoad();													//load the current chunk
	afx_msg	void	onActionSave();											//save the current chunk
	afx_msg void	onActionSaveTerrain();									//save chunk geometry
	void	Tick(MSG *msg);
	void	UpdateInput(MSG *msg);

	SceneObject* GetSelectedObject();
	void updateObject(SceneObject* sce, int ID);
	bool updatedID;
	void WireFrameToggle();

	void ReLoadHeightMap(std::string path);
	void LoadModel(std::string path);
	void TextureTerrain(std::string);
	SceneObject* GetNewObject();
public:	//variables
	std::vector<SceneObject>    m_sceneGraph;	//our scenegraph storing all the objects in the current chunk
	ChunkObject					m_chunk;		//our landscape chunk
	int m_selectedObject;						//ID of current Selection

	Game	m_d3dRenderer;
private:	//methods
	void	onContentAdded();

	//camera stuff
	void	UpdateClientCenter();
	POINT	CalculateCenter(const RECT& rect) const;
	void	captureCursor(bool val, bool forFPSCamera);

private:	//variables
	HWND	m_toolHandle;		//Handle to the  window
								//Instance of D3D rendering system for our tool
	InputCommands m_toolInputCommands;		//input commands that we want to use and possibly pass over to the renderer
	CRect	WindowRECT;		//Window area rectangle. 
	char	m_keyArray[256];
	sqlite3 *m_databaseConnection;	//sqldatabase handle

	int m_width;		//dimensions passed to directX
	int m_height;
	int m_currentChunk;			//the current chunk of thedatabase that we are operating on.  Dictates loading and saving. 


	//camera stuff
	//like a vector2 but for mouse positions
	POINT m_clientCenter{ 0, 0 };
	POINT m_lastCursorPos{ 0, 0 }, m_cursorPos{ 0, 0 };
	RECT m_windowRect, m_dxClientRect;

	bool m_captureCursorThisFrame = false;
	bool m_captureCursorForCameraThisFrame = false;
	bool m_cursorCaptured = false;
	bool m_cursorControlsCamera = false;

	bool m_leftMouseBtnDown = false;
	bool m_isCopied = false;
};
