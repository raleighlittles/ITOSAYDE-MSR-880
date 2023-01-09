// edit1.cpp : implementation file
//

#include "stdafx.h"
#include "m160.h"
#include "edit1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Cedit1 dialog


Cedit1::Cedit1(CWnd* pParent /*=NULL*/)
	: CDialog(Cedit1::IDD, pParent)
{
	//{{AFX_DATA_INIT(Cedit1)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void Cedit1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Cedit1)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Cedit1, CDialog)
	//{{AFX_MSG_MAP(Cedit1)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Cedit1 message handlers
