// Dialog3.cpp : implementation file
//

#include "stdafx.h"
#include "m160.h"
#include "Dialog3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif










#include "160.h"
CStatic *INFOBOX3;
//CEdit *INFOBOX3_AT;
CStatic *INFOBOX3_AT;
int CardType;

/////////////////////////////////////////////////////////////////////////////
// CDialog3 dialog
  

CDialog3::CDialog3(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog3::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialog3)
	//}}AFX_DATA_INIT
}


void CDialog3::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialog3)
	DDX_Control(pDX, IDC_COMBO1, m_com);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialog3, CDialog)
	//{{AFX_MSG_MAP(CDialog3)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	ON_BN_CLICKED(IDC_BUTTON7, OnButton7)
	ON_BN_CLICKED(IDC_BUTTON8, OnButton8)
	ON_BN_CLICKED(IDC_BUTTON9, OnButton9)
	ON_BN_CLICKED(IDC_BUTTON10, OnButton10)
	ON_BN_CLICKED(IDC_BUTTON11, OnButton11)
	ON_BN_CLICKED(IDC_BUTTON12, OnButton12)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP() 

/////////////////////////////////////////////////////////////////////////////
// CDialog3 message handlers

void CDialog3::OnCancel() 
{
	int mark;
	if(CardType==1)
	mark = chk_4442(0);
	else
	mark = chk_4428(0);
	if(mark==0)
		INFOBOX3->SetWindowText(_T("check OK..."));
	else
		INFOBOX3->SetWindowText(_T("check failed..."));
}

BOOL CDialog3::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	INFOBOX3=(CStatic*)GetDlgItem(IDC_STATIC1);
//	INFOBOX3_AT=(CEdit*)GetDlgItem(IDC_EDIT14);//IDC_EDIT14
	INFOBOX3_AT=(CStatic*)GetDlgItem(IDC_STATIC_AT);
	

	CButton* radio=(CButton*)GetDlgItem(IDC_RADIO1);
	radio->SetCheck(1);
	CardType=1;




	GetDlgItem(IDC_EDIT1)->SetWindowText(_T("FFFFFF"));
	GetDlgItem(IDC_EDIT11)->SetWindowText(_T("8"));
	GetDlgItem(IDC_EDIT12)->SetWindowText(_T("0000"));
	GetDlgItem(IDC_EDIT13)->SetWindowText(_T("0008"));



	m_com.InsertString(0,_T("AT24C01"));
	m_com.InsertString(1,_T("AT24C02"));
	m_com.InsertString(2,_T("AT24C04"));
	m_com.InsertString(3,_T("AT24C08"));
	m_com.InsertString(4,_T("AT24C16"));
	m_com.InsertString(5,_T("AT24C32"));
	m_com.InsertString(6,_T("AT24C64"));

	m_com.SetCurSel(0);


	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDialog3::OnRadio1() 
{
	SetDlgItemText(IDCANCEL,_T("4442 check"));
	
//	SetDlgItemText(IDC_BUTTON7,"read protect");
	CardType=1;
}

void CDialog3::OnRadio2() 
{
	SetDlgItemText(IDCANCEL,_T("4428 check"));
//	SetDlgItemText(IDC_BUTTON7,"保护位标志读");
	CardType=2;
}

void CDialog3::OnOK() 
{
	// TODO: Add extra validation here
	unsigned char mark;

	if(CardType==1)
		mark = Init4442();
	else
		mark = Init4428();

	if(mark==0)
		INFOBOX3->SetWindowText(_T("init succeed..."));
	else
		INFOBOX3->SetWindowText(_T("init failed..."));
}




void CDialog3::OnButton2() 
{
	int mark,icdev=0,length=3;
	unsigned char data_buff[50],datain[50];
	CString strValue,str;




	GetDlgItem(IDC_EDIT1)->GetWindowText(strValue);
	if(strValue==_T(""))
	{
		MessageBox(_T("null password..."),_T("error:"));
		return;
	}

	
	strcpy((char*)datain,strValue);
	two_one(datain,length*2,data_buff);
	if(CardType==1)
		mark = csc_4442( icdev, length,data_buff);
	else
		mark = csc_4428( icdev, length,data_buff);
		
	if(mark==0)
		INFOBOX3->SetWindowText(_T("password correct..."));
	else
		INFOBOX3->SetWindowText(_T("password wrong..."));


}

void CDialog3::OnButton1() 
{
	int mark,icdev=0,length=3;
	unsigned char data_buff[50],dataout[50];
	CString strValue,str;


	memset(data_buff,0,sizeof(data_buff));
	if(CardType==1)
		mark = rsc_4442( icdev, length,data_buff);
	else
	{
		length = 2;
		mark = rsc_4428( icdev, length,data_buff);	
	}
	if(mark==0)
	{
		one_two(data_buff,length,dataout);
		strValue=dataout;
		INFOBOX3->SetWindowText(_T("password：") + strValue);
		//return;
	}
	else
		INFOBOX3->SetWindowText(_T("read password failed..."));
	
}

void CDialog3::OnButton4() 
{
	// TODO: Add your control notification handler code here
	int mark,icdev=0,length=3;
	unsigned char data_buff[50],datain[50];
	CString strValue,str;




	GetDlgItem(IDC_EDIT2)->GetWindowText(strValue);
	if(strValue==_T(""))
	{
		MessageBox(_T("please enter password..."),_T("error:"));
		return;
	}
	else if((strValue.GetLength()!=6))
	{
		MessageBox(_T("password wrong format..."),_T("error:"));//("密码格式为3字节16进制数据...");
		return;
	}
	strcpy((char*)datain,strValue);
	two_one(datain,length*2,data_buff);
	if(CardType==1)
		mark = wsc_4442( icdev, length,data_buff);
	else
		mark = wsc_4428( icdev, length,data_buff);
		
	if(mark==0)
		INFOBOX3->SetWindowText(_T("change key succeed..."));
	else
		INFOBOX3->SetWindowText(_T("change key failed..."));



//	mark = wsc_4442(icdev, len_, data_buffer);

}

void CDialog3::OnButton5() 
{
	int mark,icdev,length,offset;
	unsigned char data_buff[50],dataout[50];
	CString strValue,str;

	offset=10;
	icdev=1;
	length = GetDlgItemInt(IDC_EDIT11);
	if(CardType==1)
		mark = srd_4442( icdev,offset, length,data_buff);
	else
		mark = srd_4428( icdev,offset, length,data_buff);


	if(mark==0)
	{
		one_two(data_buff,length,dataout);
		strValue=dataout;
		INFOBOX3->SetWindowText(_T("read succeed...\ndata:") + strValue);
		//return;
	}
	else
		INFOBOX3->SetWindowText(_T("read failed..."));


}

void CDialog3::OnButton6() 
{

	int mark,icdev,length,offset;
	unsigned char data_buff[50],datain[50];
	CString strValue,str;	

	offset=10;
	icdev=1;

	GetDlgItem(IDC_EDIT2)->GetWindowText(strValue);
	if(strValue==_T(""))
	{
		MessageBox(_T("please enter data..."),_T("error:"));
		return;
	}
	else if((strValue.GetLength()%2==1))
	{
		MessageBox(_T("wrong data format..."),_T("error:"));//("密码格式为3字节16进制数据...");
		return;
	}

	length=strValue.GetLength()/2;
	strcpy((char*)datain,strValue);
	two_one(datain,strValue.GetLength(),data_buff);

	if(CardType==1)
		mark = swr_4442( icdev,offset, length,data_buff);
	else
		mark = swr_4428( icdev,offset, length,data_buff);

	if(mark==0)
	{
		INFOBOX3->SetWindowText(_T("write succeed...") );
	}
	else
		INFOBOX3->SetWindowText(_T("write failed..."));
}

void CDialog3::OnButton7() 
{
	int mark,icdev,length,offset;
	unsigned char data_buff[50],dataout[50];
	CString strValue,str;	

	offset=10;
	icdev=1;
	length = GetDlgItemInt(IDC_EDIT11);
	if(CardType==1)
	{
		length=4;
		mark = prd_4442( icdev, length,data_buff);
		if(mark==0)
		{
			one_two(data_buff,length,dataout);
			strValue=dataout;
			INFOBOX3->SetWindowText(_T("read protect succeed...\n mark: ") + strValue);
		}
		else
			INFOBOX3->SetWindowText(_T("read protect failed..."));
	}
	else
	{
		length = 10 ;//读的长度和偏移位置 自由设置
		mark = rdwpb_4428( icdev,offset, length,data_buff);
		if(mark==0)
		{
			one_two(data_buff,length,dataout);
			strValue=dataout;
			INFOBOX3->SetWindowText(_T("read protect succeed:\n mark: ") + strValue);
		}
		else
			INFOBOX3->SetWindowText(_T("read protect failed..."));

	}
}

void CDialog3::OnButton8() 
{
	int mark,icdev,length,offset,Maxlen;
	unsigned char data_buff[50];//,dataout[50];
	CString strValue,str;
	
	if(CardType==1)
		Maxlen=32;
	else
		Maxlen=1024;

	GetDlgItem(IDC_EDIT2)->GetWindowText(strValue);
	if(strValue==_T(""))
	{
		MessageBox(_T("Null data..."),_T("error:"));
		return;
	}
	else if((strValue.GetLength()%2==1))
	{
		MessageBox(_T("wrong data format..."),_T("error:"));//("密码格式为3字节16进制数据...");
		return;
	}
	else if((strValue.GetLength()<1) || (strValue.GetLength()>Maxlen))
	{
		str.Format("%d",Maxlen);
		MessageBox(_T("wrong data format! Len :1~") + str );//("密码格式为3字节16进制数据...");
		return;
	}

	uchar datain[255];

	icdev=1;
	offset=10;

	length=strValue.GetLength()/2;
	strcpy((char*)datain,strValue);
	two_one(datain,strValue.GetLength(),data_buff);

	if(CardType==1)
	{	
		mark = pwr_4442( icdev,offset, length,data_buff);
	}
	else
	{
		mark = pwr_4428( icdev,offset, length,data_buff);
	
	}

	if(mark==0)
		INFOBOX3->SetWindowText(_T("write protect succeed...") );
	else
		INFOBOX3->SetWindowText(_T("write protect failed..."));
}

void CDialog3::OnButton9() 
{
	int mark,icdev=1,length,offset,Maxnum;
	int data_buff[50],dataout[50];
	CString strValue,str;
	
	if(CardType==1)	
	{
		Maxnum=3;
		mark = rsct_4442(icdev,data_buff);
	}
	else
	{
		Maxnum=8;
		mark = rsct_4428(icdev,data_buff);
	}

	str.Format("%d",data_buff[0]);
	strValue.Format("%d",Maxnum);
	if(mark==0)
		INFOBOX3->SetWindowText(_T("read succeed...") + str + _T("(0~") + strValue +_T(")" ));
	else
		INFOBOX3->SetWindowText(_T("read failed..."));



}

void CDialog3::OnButton10() 
{
	int mark;
	mark = InitAT();
	if(mark==0)
		INFOBOX3_AT->SetWindowText(_T("init succeed...") );
	else
		INFOBOX3_AT->SetWindowText(_T("init failed...") );

	
}

void CDialog3::OnButton11() 
{
	int mark,ctype,length;
	unsigned char lens[8],start[8],data[1024],datain[255],dataout[255];
	CString strValue;

	memset(data,0,sizeof(data));

	ctype = m_com.GetCurSel() + _T('0');

	// 起始地址
	GetDlgItem(IDC_EDIT12)->GetWindowText(strValue);
	if(strValue.GetLength()!=4)
	{
		MessageBox(_T("addr should be 2 byte hex data..."),_T("error:"));
		return;
	}
	if(strValue=="")
	{
		MessageBox(_T("Null addr..."),_T("error:"));
		return;
	}
	strcpy((char*)datain,strValue);
	two_one(datain,4,start);


	// 读数据长度
	GetDlgItem(IDC_EDIT13)->GetWindowText(strValue);
	if(strValue.GetLength()!=4)
	{
		MessageBox(_T("Len should be 2 byte hex data..."),_T("error:"));
		return;
	}
	if(strValue==_T(""))
	{
		MessageBox(_T("Null length..."),_T("error:"));
		return;
	}
	strcpy((char*)datain,strValue);
	two_one(datain,4,lens);



	mark = AT24_Read(start,lens, ctype,data);
	
	if(mark!=0)
		INFOBOX3_AT->SetWindowText(_T("read failed...") );
	else
	{
		length=lens[0]*256+lens[1];
		one_two(data,length,dataout);
		strValue=dataout;
	
		INFOBOX3_AT->SetWindowText(_T("data :")+strValue );
	}
}

void CDialog3::OnButton12() 
{
	int mark,ctype,length;
	unsigned char lens[2],start[2],data[255],datain[255],dataout[255];
	CString strValue;

	memset(data,0,sizeof(data));

	ctype = m_com.GetCurSel() + '0';
	
	// 起始地址
	GetDlgItem(IDC_EDIT12)->GetWindowText(strValue);
	if(strValue.GetLength()!=4)
	{
		MessageBox(_T("addr should be 2 byte hex data..."),_T("error:"));
		return;
	}
	if(strValue==_T(""))
	{
		MessageBox(_T("Null addr..."),_T("error:"));
		return;
	}
	strcpy((char*)datain,strValue);
	two_one(datain,4,start);


	// 读数据长度
	GetDlgItem(IDC_EDIT13)->GetWindowText(strValue);
	if(strValue.GetLength()!=4)
	{
		MessageBox(_T("Len should be 2 byte hex data..."),_T("error:"));
		return;
	}
	if(strValue=="")
	{
		MessageBox(_T("Null length..."),_T("error:"));
		return;
	}
	strcpy((char*)datain,strValue);
	two_one(datain,4,lens);


	// xie数据
	GetDlgItem(IDC_EDIT14)->GetWindowText(strValue);
	strcpy((char*)datain,strValue);
	if(strValue=="")
	{
		MessageBox(_T("Null data..."),_T("error:"));
		return;
	}
	if(strValue.GetLength()%2==1)
	{
		MessageBox(_T("wrong input data format..."),_T("Error:"));
		return;
	}


	two_one(datain,strValue.GetLength(),data);

	mark = AT24_Write(start,lens, ctype,data);
	if(mark==0)
		INFOBOX3_AT->SetWindowText(_T("write succeed...") );
	else
		INFOBOX3_AT->SetWindowText(_T("write failed...") );
}
