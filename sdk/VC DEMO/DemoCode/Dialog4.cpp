// Dialog4.cpp : implementation file
//

#include "stdafx.h"
#include "m160.h"
#include "Dialog4.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include "160.h"
//#include "GongXiang.h"
extern CString ShowHexData(unsigned char * Data,int num);
CStatic *INFOBOX4;

int keyType;
unsigned char pwd[6];
 

CEdit *pDlgKey1;
CEdit *pDlgKey2;
CEdit *pDlgKey3;////////////////////////////////////////////////////////////////////////////
// CDialog4 dialog


CDialog4::CDialog4(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog4::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialog4)
	//}}AFX_DATA_INIT
}


void CDialog4::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialog4)
	DDX_Control(pDX, IDC_COMBO2, m_list1);
	DDX_Control(pDX, IDC_COMBO1, m_list);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialog4, CDialog)
	//{{AFX_MSG_MAP(CDialog4)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON13, OnButton13)
	ON_BN_CLICKED(IDC_BUTTON8, OnButton8)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialog4 message handlers

BOOL CDialog4::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	INFOBOX4=(CStatic*)GetDlgItem(IDC_STATIC1);

	keyType=0xA;

	CButton* radio=(CButton*)GetDlgItem(IDC_RADIO1);
	radio->SetCheck(1);

	GetDlgItem(IDC_EDIT1)->SetWindowText(_T("FFFFFFFFFFFF"));

CEdit *keybox;
CEdit *keybox1;
keybox=(CEdit*)GetDlgItem(IDC_EDIT1);
keybox1=(CEdit*)GetDlgItem(IDC_EDIT11);
keybox->SetLimitText(12);
keybox1->SetLimitText(12);
//pDlgKey->GetDlgItem(IDC_EDIT1)->SetLimitText(4);
pDlgKey1=(CEdit*)GetDlgItem(IDC_EDIT3);
pDlgKey2=(CEdit*)GetDlgItem(IDC_EDIT15);
pDlgKey3=(CEdit*)GetDlgItem(IDC_EDIT5);

pDlgKey1->SetLimitText(32);
pDlgKey2->SetLimitText(32);
pDlgKey3->SetLimitText(32);

pDlgKey1->SetWindowText(_T("11223344556677889900AABBCCDDEEFF"));
pDlgKey2->SetWindowText(_T("11111111111111111111111111111111"));
pDlgKey3->SetWindowText(_T("22222222222222222222222222222222"));


	m_list.InsertString(0,_T("00"));
	m_list.InsertString(1,_T("01"));
	m_list.InsertString(2,_T("02"));
	m_list.InsertString(3,_T("03"));
	m_list.InsertString(4,_T("04"));
	m_list.InsertString(5,_T("05"));
	m_list.InsertString(6,_T("06"));
	m_list.InsertString(7,_T("07"));
	m_list.InsertString(8,_T("08"));
	m_list.InsertString(9,_T("09"));
	m_list.InsertString(10,_T("10"));
	m_list.InsertString(11,_T("11"));
	m_list.InsertString(12,_T("12"));
	m_list.InsertString(13,_T("13"));
	m_list.InsertString(14,_T("14"));
	m_list.InsertString(15,_T("15"));
	m_list.SetCurSel(0);


	m_list1.InsertString(0,_T("00"));
	m_list1.InsertString(1,_T("01"));
	m_list1.InsertString(2,_T("02"));
	m_list1.InsertString(3,_T("03"));
	m_list1.SetCurSel(0);







	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDialog4::OnRadio1() 
{
	keyType=0xA;	
}

void CDialog4::OnRadio2() 
{
	keyType=0xB;
}

void CDialog4::OnOK() 
{
	// TODO: Add extra validation here
	
	int sector,mark ;
	unsigned char temp[8],datain[255],dataout[255];
	CString strValue,str;
	sector = m_list.GetCurSel();

	mark=M1Request( keyType,temp);
		//ULRequest
	if(mark==255)
	{
		INFOBOX4->SetWindowText(_T("do not detect card...") );
		return;
	}
	else
		mark = M1Select(temp);


	GetDlgItem(IDC_EDIT1)->GetWindowText(strValue);
	if(strValue.GetLength()!=12)
	{
		MessageBox(_T("wrong key format..."),_T("error:"),MB_ICONERROR);
		return;
	}


	strcpy((char*)datain,strValue);	
	two_one(datain,12,pwd);




	mark = M1Authority( keyType, sector*4 ,pwd);

	one_two(temp,4,dataout);
//	str=dataout;
	str=ShowHexData(temp,4);
	if(mark==0)
	{

		INFOBOX4->SetWindowText(_T("succeed...SN: ") + str );
	}
	else
		INFOBOX4->SetWindowText(_T("failed...SN:") + str );

}

void CDialog4::OnCancel() 
{

	int sector,block,mark ;
	unsigned char datain[255],dataout[255],pck[16];
	CString strValue,str1,str2;

	sector = m_list.GetCurSel();	
	block = m_list1.GetCurSel();

	str1.Format("%d",sector);
	str2.Format("%d",block);

	mark = M1ReadBlock(sector*4 + block , pck);
	if(mark==0)
	{
		one_two(pck,16,dataout);
		//strValue=dataout;
		strValue = ShowHexData(pck,16);
		INFOBOX4->SetWindowText(_T("secor ")+str1+_T(" block ")+str2+": "+strValue);
	}
	else
		INFOBOX4->SetWindowText(_T("not detect card..."));
}

void CDialog4::OnButton1() 
{
	int sector,block,mark,mark1 ;
	unsigned char datain[255],dataout[255],pck[16];
	CString strValue,str1,str2;

	sector = m_list.GetCurSel();	
	block = m_list1.GetCurSel();
	strValue="";

	memset(datain,0,sizeof(datain));
	memset(pck,0,sizeof(pck));
	switch(block)
	{
	case 0:
			pDlgKey1->GetWindowText(strValue);
			break;
	case 1:
			pDlgKey2->GetWindowText(strValue);
			break;	
	case 2:
			pDlgKey3->GetWindowText(strValue);
			break;
	case 3:
			MessageBox(_T("block-03 can`t be write......"),_T("error:"));
			return;
			break;
	default:
			return;
	}
	if(strValue.GetLength()!=32)
	{
			MessageBox(_T("wrong key format..."),_T("error:"));
			return;
	}

	strcpy((char*)datain,strValue);
	two_one(datain,32,pck);
	mark = M1WriteBlock( sector*4 + block , pck);
	switch(mark)
	{
	case 8:
		INFOBOX4->SetWindowText(_T("not detect card..."));
		break;
	case 12:
		INFOBOX4->SetWindowText(_T("wrong key..."));
		break;
	case 0:
		INFOBOX4->SetWindowText(_T("write succeed..."));
		break;
	default:
		INFOBOX4->SetWindowText(_T("write failed..."));
		break;
	}
}








void CDialog4::OnButton2() 
{
	int sector,block,mark ,mark1,cardtype=0;
	unsigned char datain[255],dataout[255],pck[16],buff[48],snr[8];
	CString strValue,str1,str2,str3;

//*********密码
	GetDlgItem(IDC_EDIT1)->GetWindowText(strValue);
	if(strValue.GetLength()!=12)
	{
		MessageBox(_T("key should be 6 bye hex data..."),_T("error:"));
		return;
	}

	strcpy((char*)datain,strValue);	
	two_one(datain,12,pwd);

	
	sector = m_list.GetCurSel();	
	block = m_list1.GetCurSel();


	mark = M1ReadSec( cardtype,pwd,keyType,sector,buff,0 ,snr,5);
	if(mark==8)
	{
		INFOBOX4->SetWindowText(_T("no card..."));
		return;
	}
	else if(mark==12) 
	{
		INFOBOX4->SetWindowText(_T("wrong key..."));
		return;
	}
	else if(mark==1)
	{
		INFOBOX4->SetWindowText(_T("try again..."));
		return;
	}
	else if(mark==0)
	{
		memset(pck,0,sizeof(pck));
		mark1 = M1ReadBlock(sector*4 + 3 , pck ); 


		str1 = ShowHexData(buff,16);
		str2 = ShowHexData(buff+16,16);
		str3 = ShowHexData(buff+32,16);
		strValue = ShowHexData(pck,16);

		INFOBOX4->SetWindowText(_T("read succeed...\nblock 00: ") + str1 + _T("\nblock 01: ") + str2 + _T("\nblock 02: ") + str3 + _T("\nblock 03: ") + strValue);
	
	}
	else
		INFOBOX4->SetWindowText(_T("failed ,unknow error..."));
}









void CDialog4::OnButton4() 
{
	int sector,block,mark ,mark1,cardtype=0;
	unsigned char datain[255],dataout[255],pck[16],buff[48],snr[8];
	CString strValue,str1,str2,str3;
	


	sector = m_list.GetCurSel();	
	block = m_list1.GetCurSel();
//*********数据
	pDlgKey1->GetWindowText(str1);
	pDlgKey2->GetWindowText(str2);
	pDlgKey3->GetWindowText(str3);

	if(str1.GetLength()!=32 || str2.GetLength()!=32 || str3.GetLength()!=32 )
	{
		MessageBox(_T("wrong data ..."),_T("error"), MB_ICONWARNING );
		//MessageBox("请检查后重新输入...","数据有误:");
		return;
	}
	strcpy((char*)datain,str1);
	two_one(datain,32,buff);

	strcpy((char*)datain,str2);
	two_one(datain,32,buff+16);

	strcpy((char*)datain,str3);
	two_one(datain,32,buff+32);
//*********密码
	GetDlgItem(IDC_EDIT1)->GetWindowText(strValue);
	if(strValue.GetLength()!=12)
	{
		MessageBox(_T("key should be 6 byte hex data..."),_T("error:"));
		return;
	}

	strcpy((char*)datain,strValue);	
	two_one(datain,12,pwd);



	mark = M1WriteSec( cardtype,pwd,keyType, sector,buff,48,0 ,snr,5);
	if(mark==8)
		INFOBOX4->SetWindowText(_T("no card..."));
	else if(mark==12)
		INFOBOX4->SetWindowText(_T("wrong key..."));
	else if(mark==0)
		INFOBOX4->SetWindowText(_T("write succeed..."));
	else 
		INFOBOX4->SetWindowText(_T("write failed..."));

}

void CDialog4::OnButton13() 
{
	M500PiccHalt();	
	
	INFOBOX4->SetWindowText(_T("off succeed..."));
}

void CDialog4::OnButton8() 
{
	int sector,block,mark ,mark1,cardtype,myctrlword,keyA1B0;
	unsigned char datain[255],dataout[255],pck[16],pwdnew[16],buff[48],snr[8],serial[5];
	CString strValue,str1,str2,str3,str;

	sector = m_list.GetCurSel();	
	block = m_list1.GetCurSel();

//*********Old密码
	GetDlgItem(IDC_EDIT1)->GetWindowText(strValue);
	if(strValue.GetLength()!=12)
	{
		MessageBox(_T("old key wrong format..."),_T("error:"));
		return;
	}

	strcpy((char*)datain,strValue);	
	two_one(datain,12,pwd);
	
//*********Old密码
	GetDlgItem(IDC_EDIT11)->GetWindowText(strValue);
	if(strValue.GetLength()!=12)
	{
		MessageBox(_T("new key wrong format..."),_T("error:"));
		return;
	}

	strcpy((char*)datain,strValue);	
	two_one(datain,12,pwdnew);




	myctrlword = 0x01 + 0x02 + 0x04 +0x10;
	if(	keyType==0xA)
		keyA1B0=1;
	else
		keyA1B0=0;
	mark = piccchangesinglekey(myctrlword , serial , sector , keyA1B0 , pwd , pwdnew);

	switch(mark)
	{
	case 0:
			str.Format("%d",sector);
			INFOBOX4->SetWindowText(_T("sector ")+str+_T(" change key succeed..."));
			break;
	case 8:
			INFOBOX4->SetWindowText(_T("no card..."));
			break;
	case 9:
			INFOBOX4->SetWindowText(_T("detect more than one card..."));
			break;
	case 10:
			INFOBOX4->SetWindowText(_T("card may be off!..."));
			break;
	case 11:
			INFOBOX4->SetWindowText(_T("load key failed..."));
			break;	
	case 12:
			INFOBOX4->SetWindowText(_T("wrong key..."));
			break;	
	case 21:
			INFOBOX4->SetWindowText(_T("can`t find API..."));
			break;
	default:
			INFOBOX4->SetWindowText(_T("change key failed..."));
			break;
	}

}
