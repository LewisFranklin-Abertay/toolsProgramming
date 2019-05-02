#pragma once

#include <afxext.h>
#include "pch.h"
#include "Game.h"
#include "SceneObject.h"
#include "InputCommands.h"
#include <vector>


class Inspector
{
	constexpr static long BORDER_OFFSET = 2;

public: //methods
	Inspector();
	~Inspector();

	//onAction - These are the interface to MFC
	void	onActionInitialise(HWND handle, int width, int height);			//Passes through handle and hieght and width and initialises DirectX renderer and SQL LITE

public:	//variables
	std::vector<SceneObject>    m_sceneGraph;	//our scenegraph storing all the objects in the current chunk
	ChunkObject					m_chunk;		//our landscape chunk
	int m_selectedObject;						//ID of current Selection

	Game	m_d3dRenderer;

private:	//variables
	HWND	m_inspectorHandle;		//Handle to the  window
								//Instance of D3D rendering system for our tool
	CRect	WindowRECT;		//Window area rectangle. 


	int m_width;		//dimensions passed to directX
	int m_height;

	RECT m_windowRect, m_dxClientRect;

};
