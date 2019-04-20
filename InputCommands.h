#pragma once

struct InputCommands
{
	bool forward;
	bool back;
	bool right;
	bool left;
	bool rotRight;
	bool rotLeft;

	long mouse_X;
	long mouse_Y;

	bool focusCamera;
	bool orbCam;
	bool WireFrame;
};
