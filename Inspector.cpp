#include "Inspector.h"


Inspector::Inspector()
{
}

Inspector::~Inspector()
{
}

void Inspector::onActionInitialise(HWND handle, int width, int height)
{
	//window size, handle etc for directX
	m_width = width;
	m_height = height;
	m_inspectorHandle = handle;
	m_d3dRenderer.InspectorInitialize(handle, m_width, m_height);

	// Initialise handle measurements
	GetWindowRect(m_inspectorHandle, &m_windowRect);
	m_windowRect.left += BORDER_OFFSET;
	m_windowRect.top += BORDER_OFFSET;
	m_windowRect.right -= BORDER_OFFSET;
	m_windowRect.bottom -= BORDER_OFFSET;

	GetClientRect(m_inspectorHandle, &m_dxClientRect);
}