// m160.h : main header file for the M160 application
//

#if !defined(AFX_M160_H__68D48969_2BBD_40A3_BCEC_8DDC0ACCADC3__INCLUDED_)
#define AFX_M160_H__68D48969_2BBD_40A3_BCEC_8DDC0ACCADC3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CM160App:
// See m160.cpp for the implementation of this class
//

class CM160App : public CWinApp
{
public:
	CM160App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CM160App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CM160App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_M160_H__68D48969_2BBD_40A3_BCEC_8DDC0ACCADC3__INCLUDED_)
