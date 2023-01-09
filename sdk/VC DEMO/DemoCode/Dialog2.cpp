// Dialog2.cpp : implementation file
//

#include "stdafx.h"
#include "m160.h"
#include "Dialog2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



#include "GongXiang.h"
#include "160.h"

int CPU_CardType=1;		// 1  A卡
						// 2  B卡

CStatic *INFOBOX;


CEdit *CLA;//(CEdit*)GetDlgItem(IDC_EDIT2);
CEdit *INS;
CEdit *P1;
CEdit *P2;
CEdit *LC;
CEdit *DATA;
CEdit *LE;
/////////////////////////////////////////////////////////////////////////////
// CDialog2 dialog


CDialog2::CDialog2(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog2::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialog2)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDialog2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialog2)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialog2, CDialog)
	//{{AFX_MSG_MAP(CDialog2)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_STATIC1, OnStatic1)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON3, &CDialog2::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON11, &CDialog2::OnBnClickedButton11)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialog2 message handlers



void CDialog2::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}

void CDialog2::OnButton1() 
{
	// IccInit
	int mark;
	CString strValue,str;

	uchar ATR[50];
	memset(ATR,0,sizeof(ATR));


	int slot = GetDlgItemInt(IDC_EDIT1);

	if(CPU_CardType==1)		//A 卡
	{
		mark=IccInit(slot,ATR);																	//IccInit
		if(mark!=0)
		{
			INFOBOX->SetWindowText(_T("reset failed"));

		}
		else 
		{
			strValue= ShowHexData(ATR+1,*ATR);
			INFOBOX->SetWindowText(_T("reset succeed: ")+strValue);
		}

	}
	else if(CPU_CardType==2)	//B 卡
	{
	    mark = BRequest(ATR);
	    if(mark!=0)
		{
			INFOBOX->SetWindowText(_T("type B can`t find card"));
		}
		else
		{
			 mark = BAttrib();
			 if(mark!=0)
				INFOBOX->SetWindowText(_T("type B attrib failed"));
			 else
			 {
				strValue= ShowHexData(ATR,13);
				INFOBOX->SetWindowText(_T("succeed:")+strValue);
			 
			 }
		}
	
	
	
	}


}

void CDialog2::OnRadio1() 
{
	CPU_CardType=1;
}

void CDialog2::OnRadio2() 
{
	// TODO: Add your control notification handler code here
	CPU_CardType=2;
}

BOOL CDialog2::DestroyWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CDialog::DestroyWindow();
}

CScrollBar* CDialog2::GetScrollBarCtrl(int nBar) const
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CDialog::GetScrollBarCtrl(nBar);
}

int CDialog2::DoModal() 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CDialog::DoModal();
}

LRESULT CDialog2::DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CDialog::DefWindowProc(message, wParam, lParam);
}

BOOL CDialog2::OnInitDialog() 
{
	CDialog::OnInitDialog();

	CButton* radio=(CButton*)GetDlgItem(IDC_RADIO1);
	radio->SetCheck(1);

	//CButton* infobox=(CButton*)GetDlgItem(IDC_STATIC1);
	
	SetDlgItemText(IDC_EDIT1,_T("0"));


	INFOBOX=(CStatic*)GetDlgItem(IDC_STATIC1);

	CLA=(CEdit*)GetDlgItem(IDC_EDIT2);
	INS=(CEdit*)GetDlgItem(IDC_EDIT5);
	P1=(CEdit*)GetDlgItem(IDC_EDIT6);
	P2=(CEdit*)GetDlgItem(IDC_EDIT7);
	LC=(CEdit*)GetDlgItem(IDC_EDIT8);
	DATA=(CEdit*)GetDlgItem(IDC_EDIT9);
	LE=(CEdit*)GetDlgItem(IDC_EDIT10);

	CLA->SetWindowText(_T("00"));
	INS->SetWindowText(_T("84"));
	P1->SetWindowText(_T("00"));
	P2->SetWindowText(_T("00"));


	LE->SetWindowText(_T("08"));







	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}



void CDialog2::OnButton2() 
{
	int mark,apdulen=0,rlen;
	CString strValue,str,strWA,strWB;
	unsigned char buff[300];
	memset(buff,0,sizeof(buff));

	unsigned char datain[225],APDU[300],ResBuf[300];
	memset(datain,0,sizeof(datain));

	int slot = GetDlgItemInt(IDC_EDIT1);

	int inlen=2;
	apdulen=0;
//CLA
	CLA->GetWindowText(strValue);
	strcpy((char*)datain,strValue);
	two_one(datain,inlen,buff);
	APDU[0]=buff[0];
	apdulen++;
//INS
	memset(buff,0,sizeof(buff));
	INS->GetWindowText(strValue);
	strcpy((char*)datain,strValue);
	two_one(datain,inlen,buff);
	APDU[1]=buff[0];
	apdulen++;

//P1
	memset(buff,0,sizeof(buff));
	P1->GetWindowText(strValue);
	strcpy((char*)datain,strValue);
	two_one(datain,inlen,buff);
	APDU[2]=buff[0];
	apdulen++;
//P2
	memset(buff,0,sizeof(buff));
	P2->GetWindowText(strValue);
	strcpy((char*)datain,strValue);
	two_one(datain,inlen,buff);
	APDU[3]=buff[0];
	apdulen++;

//LC
	DATA->GetWindowText(strValue);
	if(strValue==""){
	}else
	{
		int len=strValue.GetLength();
		if(len%2==1)
		{
			MessageBox(_T("wrong data format..."),_T("error:"));
			return ;
		}
		APDU[4]=len/2;	
		apdulen++;
		str.Format("%02x", APDU[4]);
		LC->SetWindowText(str);

		strcpy((char*)datain,strValue);
		two_one(datain,len,APDU+5);		//DataIn		
		apdulen+=len/2;
	}

	//LE
	memset(buff,0,sizeof(buff));
	LE->GetWindowText(strValue);
	if(strValue==_T("")){
		
	}else{
		strcpy((char*)datain,strValue);
		two_one(datain,inlen,buff);
		APDU[apdulen]=buff[0];
		apdulen++;
	}


	if(CPU_CardType==1)
		mark = IccIsoCommand2( slot,APDU,apdulen,ResBuf,rlen);
	else if(CPU_CardType==2)
		mark = B_Apdu2( slot,APDU,apdulen,ResBuf,rlen);
	else
	{
		MessageBox(_T("unknow error..."),_T("error:"));
		return;
	}	

	if(!mark){
		memset(buff,0,sizeof(buff));
		one_two(ResBuf,rlen-2,buff);
		strValue=buff;
		strWA.Format("%02x", ResBuf[rlen-2]);
		strWB.Format("%02x", ResBuf[rlen-1]);
		INFOBOX->SetWindowText(_T("IC card re:\r\n") + strValue + _T("\n\nWA:") +strWA +  _T("\nWB:") + strWB );
	}
	else{
	    INFOBOX->SetWindowText(_T("IC card return  failed\r\n") );
	}
}

void CDialog2::OnStatic1() 
{ 
	// TODO: Add your control notification handler code here
	
}

void CDialog2::OnButton5() 
{

}

void CDialog2::OnButton4() 
{
	int slot = GetDlgItemInt(IDC_EDIT1);
	IccClose(slot);
	INFOBOX->SetWindowText(_T("Off succeed...")  );
}


void CDialog2::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	int mark;
	CString strValue;
	int slot = GetDlgItemInt(IDC_EDIT1);
	char cardnum[50];


	memset(cardnum,0,sizeof(cardnum));

	mark = MSR_ICCardID(slot, cardnum);
	if(mark==0)
	{
	  strValue = cardnum+1;
	  INFOBOX->SetWindowText(_T("PAN:") + strValue );
	}else{
	  INFOBOX->SetWindowText(_T("Read Fail:") );
	}
}

extern void _stdcall EmvLogCtrlEn(unsigned char en);
void CDialog2::OnBnClickedButton11()
{
	// TODO: 在此添加控件通知处理程序代码
	ThailandIDObj ThailandIDInfo;
	int mark;
	CString strValue,str,str2,str3,str4;
	int slot = GetDlgItemInt(IDC_EDIT1);
	char cardnum[50],buff2[512],buff3[256],buff4[128];

	memset(&ThailandIDInfo,0,sizeof(ThailandIDInfo));
	memset(cardnum,0,sizeof(cardnum));
	memset(buff2,0,sizeof(buff2));
	memset(buff3,0,sizeof(buff3));
	memset(buff4,0,sizeof(buff4));
	EmvLogCtrlEn(1);
	mark = GetThailandIDInfo(slot, &ThailandIDInfo);
	EmvLogCtrlEn(0);
	if(mark==0)
	{   
		//one_two(ThailandIDInfo.CID,0x0d,(unsigned char *)cardnum);
	  	str = ThailandIDInfo.CID;//cardnum;
		//one_two(ThailandIDInfo.NameSex,0xd1,(unsigned char *)buff2);
		str2 = ThailandIDInfo.NameSex;//buff2;
		//one_two(ThailandIDInfo.Address,0x64,(unsigned char *)buff3);
		str3 = ThailandIDInfo.Address;//buff3;
		//one_two(ThailandIDInfo.IssueExpire,0x12,(unsigned char *)buff4);
		str4 = ThailandIDInfo.IssueExpire;//buff4;
		INFOBOX->SetWindowText("CID："+str + "\r\n"+ 
			                   "NameSex："+ str2+ "\r\n" +
							   "Address：" + str3+ "\r\n" +
							   "IssueExpire："+ str4);
	}else{
	  str.Format("%02x",mark);
	  INFOBOX->SetWindowText(_T("Read Fail ret=:")+str );
	}
}
