// G:\Fujh\SDK\ZCS160\DemoCode\DialogPinPad.cpp : 实现文件
//

#include "stdafx.h"
#include "m160.h"
#include "DialogPinPad.h"
#include "afxdialogex.h"

#include "160.h"

// DialogPinPad 对话框

IMPLEMENT_DYNAMIC(DialogPinPad, CDialogEx)

DialogPinPad::DialogPinPad(CWnd* pParent /*=NULL*/)
	: CDialogEx(DialogPinPad::IDD, pParent)
{

}

DialogPinPad::~DialogPinPad()
{
}

void DialogPinPad::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DialogPinPad, CDialogEx)
	ON_BN_CLICKED(IDOK, &DialogPinPad::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &DialogPinPad::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &DialogPinPad::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &DialogPinPad::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &DialogPinPad::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON14, &DialogPinPad::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_RADIO5, &DialogPinPad::OnBnClickedRadio5)
	ON_BN_CLICKED(IDC_RADIO6, &DialogPinPad::OnBnClickedRadio6)
	ON_BN_CLICKED(IDC_BUTTON15, &DialogPinPad::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON16, &DialogPinPad::OnBnClickedButton16)
END_MESSAGE_MAP()

CStatic *INFOBOX_PinPad;
CComboBox *Combo_ComNum;
CComboBox *Combo_Mkeytype;
CComboBox *Combo_Wkeytype;
CComboBox *Combo_CalcMode;
CComboBox *Combo_CBCMode;
// DialogPinPad 消息处理程序
BOOL DialogPinPad::OnInitDialog() 
{
	CDialog::OnInitDialog();

	INFOBOX_PinPad=(CStatic*)GetDlgItem(IDC_STATIC);
	Combo_ComNum=(CComboBox*)GetDlgItem(IDC_COMBO1);
	Combo_ComNum->InsertString(0,_T("00"));
	Combo_ComNum->InsertString(1,_T("01"));
	Combo_ComNum->InsertString(2,_T("02"));
	Combo_ComNum->InsertString(3,_T("03"));
	Combo_ComNum->InsertString(4,_T("04"));
	Combo_ComNum->InsertString(5,_T("05"));
	Combo_ComNum->InsertString(6,_T("06"));
	Combo_ComNum->InsertString(7,_T("07"));
	Combo_ComNum->InsertString(8,_T("08"));
	Combo_ComNum->InsertString(9,_T("09"));
	Combo_ComNum->InsertString(10,_T("10"));
	Combo_ComNum->InsertString(11,_T("11"));
	Combo_ComNum->InsertString(12,_T("12"));
	Combo_ComNum->InsertString(13,_T("13"));
	Combo_ComNum->InsertString(14,_T("14"));
	Combo_ComNum->InsertString(15,_T("15"));
	Combo_ComNum->InsertString(16,_T("16"));
	Combo_ComNum->InsertString(17,_T("17"));
	Combo_ComNum->InsertString(18,_T("18"));
	Combo_ComNum->InsertString(19,_T("19"));
	Combo_ComNum->InsertString(20,_T("20"));
	Combo_ComNum->SetCurSel(0);


	GetDlgItem(IDC_EDIT1)->SetWindowText(_T("1"));
	GetDlgItem(IDC_EDIT2)->SetWindowText(_T("12345"));
	GetDlgItem(IDC_EDIT3)->SetWindowText(_T("4"));
	GetDlgItem(IDC_EDIT4)->SetWindowText(_T("12"));
	GetDlgItem(IDC_EDIT5)->SetWindowText(_T("0"));
	GetDlgItem(IDC_EDIT6)->SetWindowText(_T("10"));
	GetDlgItem(IDC_EDIT7)->SetWindowText(_T("4012345678909"));

	GetDlgItem(IDC_EDIT9)->SetWindowText(_T("1"));
	GetDlgItem(IDC_EDIT11)->SetWindowText(_T("11223344556677889900AABBCCDDEEFF"));

	GetDlgItem(IDC_EDIT12)->SetWindowText(_T("1"));
	GetDlgItem(IDC_EDIT33)->SetWindowText(_T("1")); 
	GetDlgItem(IDC_EDIT18)->SetWindowText(_T("1234567890ABCDEF1122334455667788"));

	Combo_Mkeytype=(CComboBox*)GetDlgItem(IDC_COMBO3);
	Combo_Mkeytype->InsertString(0,_T("TYPE_PINEK"));
	Combo_Mkeytype->InsertString(1,_T("TYPE_DATAEK"));
	Combo_Mkeytype->InsertString(2,_T("TYPE_DATADK"));
	Combo_Mkeytype->SetCurSel(0);

	Combo_Wkeytype=(CComboBox*)GetDlgItem(IDC_COMBO5);
	Combo_Wkeytype->InsertString(0,_T("TYPE_PINEK"));
	Combo_Wkeytype->InsertString(1,_T("TYPE_DATAEK"));
	Combo_Wkeytype->InsertString(2,_T("TYPE_DATADK"));
	Combo_Wkeytype->SetCurSel(0);

	Combo_CalcMode=(CComboBox*)GetDlgItem(IDC_COMBO6);
	Combo_CalcMode->InsertString(0,_T("ENCRYPT"));
	Combo_CalcMode->InsertString(1,_T("DECRYPT"));
	Combo_CalcMode->SetCurSel(0);

	Combo_CBCMode=(CComboBox*)GetDlgItem(IDC_COMBO7);
	Combo_CBCMode->InsertString(0,_T("ECB"));
	Combo_CBCMode->InsertString(1,_T("CBC"));
	Combo_CBCMode->SetCurSel(0);

	GetDlgItem(IDC_EDIT14)->SetWindowText(_T("1"));
	GetDlgItem(IDC_EDIT35)->SetWindowText(_T("0000000000000000"));
	GetDlgItem(IDC_EDIT25)->SetWindowText(_T("1122334455667788"));


	((CButton*)(GetDlgItem(IDC_BUTTON1)))->EnableWindow(FALSE);	
	((CButton*)(GetDlgItem(IDC_BUTTON2)))->EnableWindow(FALSE);	
	((CButton*)(GetDlgItem(IDC_BUTTON3)))->EnableWindow(FALSE);	
	((CButton*)(GetDlgItem(IDC_BUTTON4)))->EnableWindow(FALSE);
	((CButton*)(GetDlgItem(IDC_BUTTON14)))->EnableWindow(FALSE);	
	((CButton*)(GetDlgItem(IDC_BUTTON15)))->EnableWindow(FALSE);
	((CButton*)(GetDlgItem(IDC_BUTTON16)))->EnableWindow(FALSE);

	return TRUE; 
}

void DialogPinPad::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	int ret;
	unsigned char ComNo;
	CString str;

	ComNo = Combo_ComNum->GetCurSel();
	ret=PinPadSetCom(ComNo);
	if(!ret)
	{ 
	   INFOBOX_PinPad->SetWindowText(_T("SetCom OK.."));
	   ((CButton*)(GetDlgItem(IDC_BUTTON1)))->EnableWindow(TRUE);	
	}else{
	   INFOBOX_PinPad->SetWindowText(_T("SetCom Fail.."));
	}
}


void DialogPinPad::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	int ret;
	CString str;

	ret = PinPadInit();
	if(!ret)
	{ 
	   INFOBOX_PinPad->SetWindowText(_T("PinPadInit OK.."));
	   ((CButton*)(GetDlgItem(IDC_BUTTON2)))->EnableWindow(TRUE);	
	  ((CButton*)(GetDlgItem(IDC_BUTTON3)))->EnableWindow(TRUE);	
	  ((CButton*)(GetDlgItem(IDC_BUTTON4)))->EnableWindow(TRUE);
	  ((CButton*)(GetDlgItem(IDC_BUTTON14)))->EnableWindow(TRUE);	
	  ((CButton*)(GetDlgItem(IDC_BUTTON15)))->EnableWindow(TRUE);
	  ((CButton*)(GetDlgItem(IDC_BUTTON16)))->EnableWindow(TRUE);
	}else{
	   INFOBOX_PinPad->SetWindowText(_T("PinPadInit Fail.."));
	}

}


void DialogPinPad::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	unsigned char wkeyindex,blocktype,minlen,maxlen,timeout;
	int ret;
	CString str,panstr;
	unsigned char pinbuf[32],panbuf[64],Amountbuf[64],databuf[64];

	wkeyindex=GetDlgItemInt(IDC_EDIT1);

	memset(panbuf,0,sizeof(panbuf));
	GetDlgItem(IDC_EDIT7)->GetWindowText(panstr);//
	if(panstr.GetLength()<12 )
	{
	   MessageBox(_T("inputs PAN lenght error"),_T("error:"));
	   return ;
	}
	strcpy((char*)panbuf,panstr);

	memset(Amountbuf,0,sizeof(Amountbuf));
	GetDlgItem(IDC_EDIT2)->GetWindowText(str);//
	strcpy((char*)Amountbuf,str);

	blocktype=GetDlgItemInt(IDC_EDIT5);

	minlen=GetDlgItemInt(IDC_EDIT3);
	maxlen=GetDlgItemInt(IDC_EDIT4);
	timeout=GetDlgItemInt(IDC_EDIT6);

	ret = PinPadGetPin(Amountbuf,blocktype,panbuf, pinbuf, minlen, maxlen, timeout, wkeyindex);
	if(ret>0)
	{ 
       memset(databuf,0,sizeof(databuf));
	   one_two(pinbuf,8,databuf);
	   str = databuf;
	   INFOBOX_PinPad->SetWindowText(_T("PinBlock:")+str);
	}else{
		str.Format("%d",ret);
	   INFOBOX_PinPad->SetWindowText(_T("PinPadGetPin Error ret=")+str);
	}
}


void DialogPinPad::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	unsigned char mkeyindex;
    int ret;
	CString str,mkeystr;
	unsigned char keytype;
	unsigned char keybuf[64],tmkbuf[32];

	GetDlgItem(IDC_EDIT11)->GetWindowText(mkeystr);//memset(tmkbuf,0x55,16);
	if((mkeystr.GetLength()!=16 && mkeystr.GetLength()!=32 && mkeystr.GetLength()!=48))
	{
	   MessageBox(_T("inputs MasterKey lenght error"),_T("error:"));
	   return ;
	}
	strcpy((char*)keybuf,mkeystr);
	two_one(keybuf,mkeystr.GetLength(),tmkbuf);

	mkeyindex=GetDlgItemInt(IDC_EDIT9);

	keytype = Combo_Mkeytype->GetCurSel();
	if(keytype==0)  keytype =KEYTYPE_PINEK;
	else if(keytype==1) keytype =KEYTYPE_DATAEK;
	else if(keytype==2) keytype =KEYTYPE_DATADK;

	ret = PinpadLoadMasterKey(mkeyindex,keytype, tmkbuf,mkeystr.GetLength()/2);

	if(!ret)
	{ 
	   INFOBOX_PinPad->SetWindowText(_T("PinpadLoadMasterKey OK!"));
	}else{
		str.Format("%d",ret);
	   INFOBOX_PinPad->SetWindowText(_T("PinpadLoadMasterKey Error ret=")+str);
	}

}


void DialogPinPad::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	unsigned char keytype;
	unsigned int wkeyindex,mkeyindex,kcvlen;
	int ret;
	CString str,mkeystr,wkeystr;
	unsigned char keybuf[64],tmkbuf[32],twkbuf[32],kcvbuf[16],twkbufchip[32],datain[8];

	GetDlgItem(IDC_EDIT11)->GetWindowText(mkeystr);//memset(tmkbuf,0x55,16);
	if((mkeystr.GetLength()!=16 && mkeystr.GetLength()!=32 && mkeystr.GetLength()!=48))
	{
	   MessageBox(_T("inputs MasterKey lenght error"),_T("error:"));
	   return ;
	}
	strcpy((char*)keybuf,mkeystr);
	two_one(keybuf,mkeystr.GetLength(),tmkbuf);

	GetDlgItem(IDC_EDIT18)->GetWindowText(wkeystr);
	if((wkeystr.GetLength()!=16 && wkeystr.GetLength()!=32 && wkeystr.GetLength()!=48))
	{
	   MessageBox(_T("inputs WorkKey lenght error"),_T("error:"));
	   return ;
	}
	strcpy((char*)keybuf,wkeystr);
	two_one(keybuf,wkeystr.GetLength(),twkbuf); //memset(twkbuf,0x88,16);
	
	CalcDesECB(twkbuf,wkeystr.GetLength()/2,twkbufchip,tmkbuf,mkeystr.GetLength()/2,1);

	keytype = Combo_Wkeytype->GetCurSel();
	if(keytype==0)  keytype =KEYTYPE_PINEK;
	else if(keytype==1) keytype =KEYTYPE_DATAEK;
	else if(keytype==2) keytype =KEYTYPE_DATADK;

	wkeyindex=GetDlgItemInt(IDC_EDIT12);
	mkeyindex=GetDlgItemInt(IDC_EDIT33);

	GetDlgItem(IDC_EDIT34)->GetWindowText(str);
	if(str.GetLength()==0)
	{
	    memset(datain,0,8);
		CalcDesECB(datain,8,kcvbuf,twkbuf,wkeystr.GetLength()/2,1);
		kcvlen=4;
	}else{
	    if(str.GetLength()%2)
		{
		   MessageBox(_T("inputs kcv lenght error"),_T("error:"));
		   return ;
		}
		kcvlen = str.GetLength()/2;
	}

	ret= PinpadLoadWorkKey(wkeyindex,mkeyindex,keytype,twkbufchip,wkeystr.GetLength()/2,kcvbuf,kcvlen);

	if(!ret)
	{ 
	   INFOBOX_PinPad->SetWindowText(_T("PinpadLoadWorkKey OK!"));
	}else{
		str.Format("%d",ret);
	   INFOBOX_PinPad->SetWindowText(_T("PinpadLoadWorkKey Error ret=")+str);
	}

}


void DialogPinPad::OnBnClickedButton14()
{
	// TODO: 在此添加控件通知处理程序代码
	unsigned int wkeyindex,datalen;
	unsigned char Calcmode,cbcmode,InvDatabuf[32],databuf[2048],datain[2048];
	int ret,i;
	CString str,Outdatastr="";

	GetDlgItem(IDC_EDIT25)->GetWindowText(str);
	if(str.GetLength()%16)
	{
		MessageBox(_T("inputs data lenght error"),_T("error:"));
		return ;
	}
	strcpy((char*)databuf,str);
	datalen=str.GetLength()/2;
	two_one(databuf,str.GetLength(),datain);

	wkeyindex=GetDlgItemInt(IDC_EDIT14);
	Calcmode = Combo_CalcMode->GetCurSel();
	cbcmode = Combo_CBCMode->GetCurSel();
	if(cbcmode)
	{
	   GetDlgItem(IDC_EDIT35)->GetWindowText(str);
	   if(str.GetLength()!=16)
	   {
			MessageBox(_T("inputs invdata lenght error"),_T("error:"));
			return ;
	   }
	   strcpy((char*)databuf,str);
	   two_one(databuf,str.GetLength(),InvDatabuf);
	}
	ret=PinPadCalcDES(Calcmode, databuf,datain,datalen,wkeyindex,cbcmode,InvDatabuf);
	if(!ret)
	{ 
	   for(i=0;i<datalen;i++)
	   {
		  str.Format("%02X",databuf[i]);
	      Outdatastr+=str;
	   }
	   
	   GetDlgItem(IDC_EDIT26)->SetWindowText(Outdatastr);
	}else{
	   str.Format("%d",ret);
	   INFOBOX_PinPad->SetWindowText(_T("PinPadCalcDES Error ret=")+str);
	}

}


void DialogPinPad::OnBnClickedRadio5()
{
	// TODO: 在此添加控件通知处理程序代码

	((CButton*)(GetDlgItem(IDC_COMBO7)))->EnableWindow(TRUE);	
	((CButton*)(GetDlgItem(IDC_EDIT35)))->EnableWindow(TRUE);	

	Combo_CalcMode->DeleteString(1);
	Combo_CalcMode->DeleteString(0);
	Combo_CalcMode->InsertString(0,_T("ENCRYPT"));
	Combo_CalcMode->InsertString(1,_T("DECRYPT"));
	Combo_CalcMode->SetCurSel(0);
}


void DialogPinPad::OnBnClickedRadio6()
{
	// TODO: 在此添加控件通知处理程序代码
	((CButton*)(GetDlgItem(IDC_COMBO7)))->EnableWindow(FALSE);	
	((CButton*)(GetDlgItem(IDC_EDIT35)))->EnableWindow(FALSE);	

	Combo_CalcMode->DeleteString(1);
	Combo_CalcMode->DeleteString(0);
	Combo_CalcMode->InsertString(0,_T("MAC_X99"));
	Combo_CalcMode->InsertString(1,_T("MAC_X919"));
	Combo_CalcMode->SetCurSel(0);
}


void DialogPinPad::OnBnClickedButton15()
{
	// TODO: 在此添加控件通知处理程序代码

	unsigned int wkeyindex,datalen;
	unsigned char Calcmode,cbcmode,InvDatabuf[32],databuf[2048],datain[2048];
	int ret,i;
	CString str,Outdatastr="";

	GetDlgItem(IDC_EDIT25)->GetWindowText(str);
	if(str.GetLength()%2)
	{
		MessageBox(_T("inputs data lenght error"),_T("error:"));
		return ;
	}
	strcpy((char*)databuf,str);
	datalen=str.GetLength()/2;
	two_one(databuf,str.GetLength(),datain);

	wkeyindex=GetDlgItemInt(IDC_EDIT14);
	Calcmode = Combo_CalcMode->GetCurSel();
	
	ret = PinPadGetMac(Calcmode,databuf,datain,datalen,wkeyindex);
	if(!ret)
	{ 
	   for(i=0;i<8;i++)
	   {
		  str.Format("%02X",databuf[i]);
	      Outdatastr+=str;
	   }
	   
	   GetDlgItem(IDC_EDIT26)->SetWindowText(Outdatastr);
	}else{
	   str.Format("%d",ret);
	   INFOBOX_PinPad->SetWindowText(_T("PinPadGetMac Error ret=")+str);
	}
}


void DialogPinPad::OnBnClickedButton16()
{
	// TODO: 在此添加控件通知处理程序代码
	unsigned char Ver[64],SN[64];
	int ret,i,len;
	CString str,Outdatastr="";
	memset(Ver,0,sizeof(Ver));
	memset(SN,0,sizeof(SN));
	ret =PinPadGetInfo(Ver,SN);
	if(!ret)
	{  
	   Outdatastr = "Ver:";
	   len=strlen((const char*)Ver);
	   for(i=0;i<len;i++)
	   {
		  str.Format("%c",Ver[i]);
	      Outdatastr+=str;
	   }
	   Outdatastr += "\r\n";
	   len=strlen((const char*)SN);
	   if(len>0){
		   Outdatastr += "SN:";
		   for(i=0;i<len;i++)
		   {
			  str.Format("%c",SN[i]);
			  Outdatastr+=str;
		   }
	   }
	   INFOBOX_PinPad->SetWindowText(Outdatastr);
	}else{
	   str.Format("%d",ret);
	   INFOBOX_PinPad->SetWindowText(_T("PinPadGetInfo Error ret=")+str);
	}
}
