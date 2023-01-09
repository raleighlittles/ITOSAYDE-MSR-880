// Dialog5.cpp : implementation file
//

#include "stdafx.h"
#include "m160.h"
#include "Dialog5.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif






#include "160.h"
//#include "GongXiang.h"
extern CString ShowHexData(unsigned char * Data,int num);
CStatic *INFOBOX5;


/////////////////////////////////////////////////////////////////////////////
// CDialog5 dialog


CDialog5::CDialog5(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog5::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialog5)
	//}}AFX_DATA_INIT
}


void CDialog5::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialog5)
	DDX_Control(pDX, IDC_COMBO1, m_com5);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialog5, CDialog)
	//{{AFX_MSG_MAP(CDialog5)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialog5 message handlers

void CDialog5::OnCancel() 
{
	int block,mark ,mark1,cardType,length;
	unsigned char datain[255],dataout[255],pck[4],pwdnew[16],buff[48],snr[8],serial[8],len;
	CString strValue,str1,str2,str3,str;

	block = m_com5.GetCurSel();

	mark = M1ReadBlock( block,pck);
	if(mark==0)
	{
		str.Format("%d",block);
		strValue = ShowHexData(pck,4);
		INFOBOX5->SetWindowText(_T("block")+str+_T(": ") + strValue);
	}
	else
		INFOBOX5->SetWindowText(_T("read fail..."));

}





BOOL CDialog5::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	


	INFOBOX5=(CStatic*)GetDlgItem(IDC_STATIC1);



	m_com5.InsertString(0,_T("00"));
	m_com5.InsertString(1,_T("01"));
	m_com5.InsertString(2,_T("02"));
	m_com5.InsertString(3,_T("03"));
	m_com5.InsertString(4,_T("04"));
	m_com5.InsertString(5,_T("05"));
	m_com5.InsertString(6,_T("06"));
	m_com5.InsertString(7,_T("07"));
	m_com5.InsertString(8,_T("08"));
	m_com5.InsertString(9,_T("09"));
	m_com5.InsertString(10,_T("10"));
	m_com5.InsertString(11,_T("11"));
	m_com5.InsertString(12,_T("12"));
	m_com5.InsertString(13,_T("13"));
	m_com5.InsertString(14,_T("14"));
	m_com5.InsertString(15,_T("15"));
	m_com5.SetCurSel(0);

//m_com5.SetReadOnly(1);





	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDialog5::OnOK() 
{
	// TODO: Add extra validation here
	
	int sector,block,mark ,mark1,cardType=0,length;
	unsigned char datain[255],dataout[255],pck[16],pwdnew[16],buff[48],snr[8],serial[8],len;
	CString strValue,str1,str2,str3,str;

	memset(serial,0,sizeof(serial));

	mark = ULRequest( cardType,serial,&len);
	if(mark !=0)
	{
		INFOBOX5->SetWindowText(_T("no card..."));
		return;
	}
	mark = ULSelect(serial);

	strValue = ShowHexData(serial,7);
	INFOBOX5->SetWindowText(_T("succeed ,SN: ") + strValue);
}

void CDialog5::OnButton1() 
{
	int block,mark ,mark1,cardType,length;
	unsigned char datain[255],dataout[255],pck[4],pwdnew[16],buff[48],snr[8],serial[8],len;
	CString strValue,str1,str2,str3,str;

	block = m_com5.GetCurSel();

	GetDlgItem(IDC_EDIT1)->GetWindowText(strValue);		
	if(strValue.GetLength()!=8)
	{
		MessageBox(_T("inputs should be 4 byte hex data:"),_T("error:"));
		return;
	} 
	strcpy((char*)datain,strValue);
	two_one(datain,8,pck);


	mark = ULWrite(block, pck);
	if(mark==8)
		INFOBOX5->SetWindowText(_T("no card...") );
	else if(mark==12)
		INFOBOX5->SetWindowText(_T("failed...") );
	else if(mark==0)
		INFOBOX5->SetWindowText(_T("write succeed...") );
	else
		INFOBOX5->SetWindowText(_T("write failed...") );
}
