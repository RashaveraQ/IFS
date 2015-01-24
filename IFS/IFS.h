// IFS.h : main header file for the IFS application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CIFSApp:
// See IFS.cpp for the implementation of this class
//

class CIFSApp : public CWinApp
{
public:
	CIFSApp();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CIFSApp theApp;