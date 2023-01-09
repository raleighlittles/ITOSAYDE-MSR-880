// Dialog6.cpp : implementation file
//

#include "stdafx.h"
#include "m160.h"
#include "Dialog6.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include "160.h"
//#include "BitImage.h"


CEdit *data1;
CEdit *data2;
CEdit *data3;
CEdit *data4;
CEdit *data5;
CEdit *data6;
CEdit *data7_1;
CEdit *data7_2;
CEdit *data8;

CStatic  *INFOBOX6;

/////////////////////////////////////////////////////////////////////////////
// CDialog6 dialog


CDialog6::CDialog6(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog6::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialog6)
	//}}AFX_DATA_INIT
}


void CDialog6::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialog6)
	DDX_Control(pDX, IDC_BMP, m_image1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialog6, CDialog)
	//{{AFX_MSG_MAP(CDialog6)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialog6 message handlers

void CDialog6::OnOK() 
{
	// TODO: Add extra validation here
	int mark;
	mark = writeIDReset();
	if(mark==0)
	{
		INFOBOX6->SetWindowText(_T("复位成功..."));
		data1->SetWindowText(_T("..."));
		data2->SetWindowText(_T("..."));
		data3->SetWindowText(_T("..."));
		data4->SetWindowText(_T("..."));
		data5->SetWindowText(_T("..."));
		data6->SetWindowText(_T("..."));
		data7_1->SetWindowText(_T("..."));
		data7_2->SetWindowText(_T("..."));
		data8->SetWindowText(_T("..."));

	} 
	else
		INFOBOX6->SetWindowText(_T("复位失败..."));



}

BOOL CDialog6::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	data1=(CEdit*)GetDlgItem(IDC_EDIT1);
	data2=(CEdit*)GetDlgItem(IDC_EDIT11);
	data3=(CEdit*)GetDlgItem(IDC_EDIT19);
	data4=(CEdit*)GetDlgItem(IDC_EDIT20);
	data5=(CEdit*)GetDlgItem(IDC_EDIT21);
	data6=(CEdit*)GetDlgItem(IDC_EDIT22);
	data7_1=(CEdit*)GetDlgItem(IDC_EDIT23);
	data7_2=(CEdit*)GetDlgItem(IDC_EDIT24);
	data8=(CEdit*)GetDlgItem(IDC_EDIT5);

	INFOBOX6=(CStatic*)GetDlgItem(IDC_STATIC_INFO);





	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDialog6::OnCancel() 
{
	int ret;
	unsigned char buffer[80];


	CString str;
	ret = writeIDData();
	if(ret==0)
	{
		INFOBOX6->SetWindowText(_T("读卡成功..."));

		GetPeopleName (buffer);
		str=buffer;
		data1->SetWindowText(str);

		GetPeopleSex((char*)buffer);
		str=buffer;
		data2->SetWindowText(str);

		GetPeopleNation((char*)buffer);
		str=buffer;
		data8->SetWindowText(str);

		GetPeopleBirthday((char*)buffer);
		str=buffer;
		data3->SetWindowText(str);

		GetPeopleAddress((char*)buffer);
		str=buffer;
		data5->SetWindowText(str);

		GetPeopleIDCode((char*)buffer);
		str=buffer;
		data4->SetWindowText(str);

		GetDepartment((char*)buffer);
		str=buffer;
		data6->SetWindowText(str);

		GetStartDate((char*)buffer);
		str=buffer;
		data7_1->SetWindowText(str);

		GetEndDate((char*)buffer);
		str=buffer;
		data7_2->SetWindowText(str);

		this->m_image1.ModifyStyle(0,SS_BITMAP |  SS_CENTERIMAGE); 
		HBITMAP hBmp = (HBITMAP)::LoadImage(0, _T("zp.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		this->m_image1.SetBitmap(hBmp);  
	}
	else
		INFOBOX6->SetWindowText(_T("读卡失败..."));
}

void CDialog6::OnButton1() 
{
	// TODO: Add your control notification handler code here
	int ret = writeIDOff();
	if(ret==0)
	{
		INFOBOX6->SetWindowText(_T("下电成功..."));
	}
	else
		INFOBOX6->SetWindowText(_T("下电失败..."));


}
