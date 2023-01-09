// ReadInfo.cpp : implementation file
//

#include "stdafx.h"
#include "m160.h"
#include "ReadInfo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


//extern CEdit *m_zcs80trcak1;
extern int ZCS80ReadPro_flag;
extern int ZCS80WritePro_flag;
extern int ZCS80EreasePro_flag;
/////////////////////////////////////////////////////////////////////////////
// ReadInfo dialog


ReadInfo::ReadInfo(CWnd* pParent /*=NULL*/)
	: CDialog(ReadInfo::IDD, pParent)
{
	//{{AFX_DATA_INIT(ReadInfo)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void ReadInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ReadInfo)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ReadInfo, CDialog)
	//{{AFX_MSG_MAP(ReadInfo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ReadInfo message handlers

void ReadInfo::OnOK() 
{
	ZCS80ReadPro_flag=0;
	ZCS80WritePro_flag=0;	

	ZCS80EreasePro_flag=0;

//	MSR_DoCancel();
	CDialog::OnOK();
}
