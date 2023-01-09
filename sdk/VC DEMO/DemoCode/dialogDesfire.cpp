// dialogDesfire.cpp : 实现文件
//

#include "stdafx.h"
#include "m160.h"
#include "dialogDesfire.h"
#include "afxdialogex.h"
#include "160.h"

// dialogDesfire 对话框

IMPLEMENT_DYNAMIC(dialogDesfire, CDialog)

dialogDesfire::dialogDesfire(CWnd* pParent /*=NULL*/)
	: CDialog(dialogDesfire::IDD, pParent)
{

	EnableAutomation();

}

dialogDesfire::~dialogDesfire()
{
}

void dialogDesfire::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。基类将自动
	// 删除该对象。在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CDialog::OnFinalRelease();
}

void dialogDesfire::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(dialogDesfire, CDialog)
	ON_BN_CLICKED(IDOK, &dialogDesfire::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &dialogDesfire::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &dialogDesfire::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &dialogDesfire::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &dialogDesfire::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON7, &dialogDesfire::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &dialogDesfire::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &dialogDesfire::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON11, &dialogDesfire::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &dialogDesfire::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &dialogDesfire::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &dialogDesfire::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON15, &dialogDesfire::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON16, &dialogDesfire::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON17, &dialogDesfire::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON18, &dialogDesfire::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON19, &dialogDesfire::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON20, &dialogDesfire::OnBnClickedButton20)
	ON_BN_CLICKED(IDC_BUTTON24, &dialogDesfire::OnBnClickedButton24)
	ON_BN_CLICKED(IDC_BUTTON25, &dialogDesfire::OnBnClickedButton25)
	ON_BN_CLICKED(IDC_BUTTON21, &dialogDesfire::OnBnClickedButton21)
	ON_BN_CLICKED(IDC_BUTTON22, &dialogDesfire::OnBnClickedButton22)
	ON_BN_CLICKED(IDC_BUTTON23, &dialogDesfire::OnBnClickedButton23)
	ON_BN_CLICKED(IDC_BUTTON26, &dialogDesfire::OnBnClickedButton26)
	ON_BN_CLICKED(IDC_BUTTON27, &dialogDesfire::OnBnClickedButton27)
	ON_BN_CLICKED(IDC_BUTTON28, &dialogDesfire::OnBnClickedButton28)
	ON_BN_CLICKED(IDC_BUTTON29, &dialogDesfire::OnBnClickedButton29)
	ON_BN_CLICKED(IDC_BUTTON30, &dialogDesfire::OnBnClickedButton30)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(dialogDesfire, CDialog)
END_DISPATCH_MAP()

// 注意: 我们添加 IID_IdialogDesfire 支持
//  以支持来自 VBA 的类型安全绑定。此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {6B19AA83-B4F8-4C53-9B15-10F66A4C8D0F}
static const IID IID_IdialogDesfire =
{ 0x6B19AA83, 0xB4F8, 0x4C53, { 0x9B, 0x15, 0x10, 0xF6, 0x6A, 0x4C, 0x8D, 0xF } };

BEGIN_INTERFACE_MAP(dialogDesfire, CDialog)
	INTERFACE_PART(dialogDesfire, IID_IdialogDesfire, Dispatch)
END_INTERFACE_MAP()


CStatic *INFOBOX_Desfire;
CComboBox *Combo_KeyNo;
CEdit *Edit_Key;
CComboBox *Combo_ChangeKeyNo;
CComboBox *Combo_AIDNo;
CComboBox *Combo_FileNo;
CEdit *Edit_FileAccessRight;
CComboBox *Combo_CommSet;

CComboBox *Combo_DataFileNo;
// dialogDesfire 消息处理程序
BOOL dialogDesfire::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	

	INFOBOX_Desfire=(CStatic*)GetDlgItem(IDC_STATIC);

	Combo_KeyNo=(CComboBox*)GetDlgItem(IDC_COMBO1);
	Combo_KeyNo->InsertString(0,_T("00"));
	Combo_KeyNo->InsertString(1,_T("01"));
	Combo_KeyNo->InsertString(2,_T("02"));
	Combo_KeyNo->InsertString(3,_T("03"));
	Combo_KeyNo->InsertString(4,_T("04"));
	Combo_KeyNo->InsertString(5,_T("05"));
	Combo_KeyNo->InsertString(6,_T("06"));
	Combo_KeyNo->InsertString(7,_T("07"));
	Combo_KeyNo->InsertString(8,_T("08"));
	Combo_KeyNo->InsertString(9,_T("09"));
	Combo_KeyNo->InsertString(10,_T("10"));
	Combo_KeyNo->InsertString(11,_T("11"));
	Combo_KeyNo->InsertString(12,_T("12"));
	Combo_KeyNo->InsertString(13,_T("13"));
	Combo_KeyNo->SetCurSel(0);
	Edit_Key=(CEdit*)GetDlgItem(IDC_EDIT1);
	Edit_Key->SetWindowText("00000000000000000000000000000000");

	

	Combo_ChangeKeyNo=(CComboBox*)GetDlgItem(IDC_COMBO3);
	Combo_ChangeKeyNo->InsertString(0,_T("00"));
	Combo_ChangeKeyNo->InsertString(1,_T("01"));
	Combo_ChangeKeyNo->InsertString(2,_T("02"));
	Combo_ChangeKeyNo->InsertString(3,_T("03"));
	Combo_ChangeKeyNo->InsertString(4,_T("04"));
	Combo_ChangeKeyNo->InsertString(5,_T("05"));
	Combo_ChangeKeyNo->InsertString(6,_T("06"));
	Combo_ChangeKeyNo->InsertString(7,_T("07"));
	Combo_ChangeKeyNo->InsertString(8,_T("08"));
	Combo_ChangeKeyNo->InsertString(9,_T("09"));
	Combo_ChangeKeyNo->InsertString(10,_T("10"));
	Combo_ChangeKeyNo->InsertString(11,_T("11"));
	Combo_ChangeKeyNo->InsertString(12,_T("12"));
	Combo_ChangeKeyNo->InsertString(13,_T("13"));
	Combo_ChangeKeyNo->SetCurSel(0);

	Edit_Key=(CEdit*)GetDlgItem(IDC_EDIT11);
	Edit_Key->SetWindowText("00000000000000000000000000000000");
	Edit_Key=(CEdit*)GetDlgItem(IDC_EDIT3);
	Edit_Key->SetWindowText("00000000000000000000000000000000");

	Combo_AIDNo=(CComboBox*)GetDlgItem(IDC_COMBO2);
	Combo_AIDNo->InsertString(0,_T("00"));
	Combo_AIDNo->InsertString(1,_T("01"));
	Combo_AIDNo->InsertString(2,_T("02"));
	Combo_AIDNo->InsertString(3,_T("03"));
	Combo_AIDNo->InsertString(4,_T("04"));
	Combo_AIDNo->InsertString(5,_T("05"));
	Combo_AIDNo->InsertString(6,_T("06"));
	Combo_AIDNo->InsertString(7,_T("07"));
	Combo_AIDNo->InsertString(8,_T("08"));
	Combo_AIDNo->InsertString(9,_T("09"));
	Combo_AIDNo->InsertString(10,_T("10"));
	Combo_AIDNo->InsertString(11,_T("11"));
	Combo_AIDNo->InsertString(12,_T("12"));
	Combo_AIDNo->InsertString(13,_T("13"));
	Combo_AIDNo->InsertString(14,_T("14"));
	Combo_AIDNo->InsertString(15,_T("15"));
	Combo_AIDNo->InsertString(16,_T("16"));
	Combo_AIDNo->InsertString(17,_T("17"));
	Combo_AIDNo->InsertString(18,_T("18"));
	Combo_AIDNo->InsertString(19,_T("19"));
	Combo_AIDNo->InsertString(20,_T("20"));
	Combo_AIDNo->InsertString(21,_T("21"));
	Combo_AIDNo->InsertString(22,_T("22"));
	Combo_AIDNo->InsertString(23,_T("23"));
	Combo_AIDNo->InsertString(24,_T("24"));
	Combo_AIDNo->InsertString(25,_T("25"));
	Combo_AIDNo->InsertString(26,_T("26"));
	Combo_AIDNo->InsertString(27,_T("27"));
	Combo_AIDNo->SetCurSel(0);

	
	Combo_FileNo=(CComboBox*)GetDlgItem(IDC_COMBO4); 
	Combo_FileNo->InsertString(0,_T("00"));
	Combo_FileNo->InsertString(1,_T("01"));
	Combo_FileNo->InsertString(2,_T("02"));
	Combo_FileNo->InsertString(3,_T("03"));
	Combo_FileNo->InsertString(4,_T("04"));
	Combo_FileNo->InsertString(5,_T("05"));
	Combo_FileNo->InsertString(6,_T("06"));
	Combo_FileNo->InsertString(7,_T("07"));
	Combo_FileNo->SetCurSel(0);

	
	Combo_CommSet=(CComboBox*)GetDlgItem(IDC_COMBO5); 
	Combo_CommSet->InsertString(0,_T("Plain"));
	Combo_CommSet->InsertString(1,_T("MAC"));
	Combo_CommSet->InsertString(2,_T("DES/3DES"));
	Combo_CommSet->SetCurSel(0);
	Edit_FileAccessRight=(CEdit*)GetDlgItem(IDC_EDIT4);
	Edit_FileAccessRight->SetWindowText("0000");

	GetDlgItem(IDC_EDIT18)->SetWindowText("000020");
	GetDlgItem(IDC_EDIT14)->SetWindowText("00000000");
	GetDlgItem(IDC_EDIT25)->SetWindowText("000000ff");
	GetDlgItem(IDC_EDIT26)->SetWindowText("00000021");
	GetDlgItem(IDC_EDIT27)->SetWindowText("000020");
	GetDlgItem(IDC_EDIT28)->SetWindowText("000005");
	GetDlgItem(IDC_EDIT29)->SetWindowText("000000");
	GetDlgItem(IDC_EDIT30)->SetWindowText("000010");
	GetDlgItem(IDC_EDIT32)->SetWindowText("00000001");
	
	Combo_DataFileNo=(CComboBox*)GetDlgItem(IDC_COMBO6); 
	Combo_DataFileNo->InsertString(0,_T("00"));
	Combo_DataFileNo->InsertString(1,_T("01"));
	Combo_DataFileNo->InsertString(2,_T("02"));
	Combo_DataFileNo->InsertString(3,_T("03"));
	Combo_DataFileNo->InsertString(4,_T("04"));
	Combo_DataFileNo->InsertString(5,_T("05"));
	Combo_DataFileNo->InsertString(6,_T("06"));
	Combo_DataFileNo->InsertString(7,_T("07"));
	Combo_DataFileNo->SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void dialogDesfire::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	///CDialog::OnOK();
	unsigned char ret,uidbuff[64],atrbuff[64];
	CString str,uidstr="",atrstr="";
	int i;
	ret = DFRequest(uidbuff);
	if(!ret)
	{
	  ret = DFReset(atrbuff);
	  if(!ret)
	  {
		  for(i=0;i<uidbuff[0];i++){
		    str.Format("%02x",uidbuff[1+i]);
			uidstr += str;
		  }

		  for(i=0;i<atrbuff[0];i++){
		    str.Format("%02x",atrbuff[1+i]);
			atrstr += str;
		  }
		  INFOBOX_Desfire->SetWindowText(_T("UID: ")+uidstr+_T("\r\n")
			                             _T("ATS: ")+atrstr);
	  }else{
	     INFOBOX_Desfire->SetWindowText(_T("Reset fail.."));
	  }
	}else{
	   INFOBOX_Desfire->SetWindowText(_T("Request fail.."));
	}
}


void dialogDesfire::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	unsigned char ret,keyno,databuff[64],datakey[64];
	
	CString str,keynostr,keyvaluestr;
	keyno = Combo_KeyNo->GetCurSel();

	Edit_Key=(CEdit*)GetDlgItem(IDC_EDIT1);
	Edit_Key->GetWindowText(keyvaluestr);		
	if(keyvaluestr.GetLength()!=32)
	{
		MessageBox(_T("inputs should be 16 byte hex key:"),_T("error:"));
		return;
	} 
	strcpy((char*)databuff,keyvaluestr);
	two_one(databuff,32,datakey);

    ret=DFAuthenKey(keyno,datakey);
	if(!ret)
	{
	    INFOBOX_Desfire->SetWindowText(_T("AuthenKey succeed "));
	}else{
		str.Format("%02x",ret);
	    INFOBOX_Desfire->SetWindowText(_T("AuthenKey fail ret=0x")+str);
	}
}


void dialogDesfire::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	int ret;

	ret=DFHalt();
	if(!ret)
	{ 
	   INFOBOX_Desfire->SetWindowText(_T("Halt OK.."));
	}else{
	   INFOBOX_Desfire->SetWindowText(_T("Halt Fail.."));
	}
}


void dialogDesfire::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码

	unsigned char ret,keyno,databuff[64],olddatakey[64],newdatakey[64];
	
	CString str,keynostr,oldkeyvaluestr,newkeyvaluestr;
	keyno = Combo_ChangeKeyNo->GetCurSel();

	Edit_Key=(CEdit*)GetDlgItem(IDC_EDIT11);
	Edit_Key->GetWindowText(oldkeyvaluestr);		
	Edit_Key=(CEdit*)GetDlgItem(IDC_EDIT3);
	Edit_Key->GetWindowText(newkeyvaluestr);	
	if(oldkeyvaluestr.GetLength()!=32 ||newkeyvaluestr.GetLength()!=32)
	{
		MessageBox(_T("inputs should be 16 byte hex key:"),_T("error:"));
		return;
	} 
	strcpy((char*)databuff,oldkeyvaluestr);
	two_one(databuff,32,olddatakey);

    strcpy((char*)databuff,newkeyvaluestr);
	two_one(databuff,32,newdatakey);

	ret=DFUpdateKey(keyno,newdatakey,olddatakey);
	if(!ret)
	{
	    INFOBOX_Desfire->SetWindowText(_T("ChangeKey succeed "));
	}else{
		str.Format("%02x",ret);
	    INFOBOX_Desfire->SetWindowText(_T("ChangeKey fail ret=0x")+str);
	}
}


void dialogDesfire::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	unsigned char ret,aid,aidbuf[4];
	CString str;
	aid = Combo_AIDNo->GetCurSel();
	memset(aidbuf,0,sizeof(aidbuf));
	aidbuf[0]=aid;
	ret = DFSelectAID(aidbuf);
	if(!ret)
	{
	    INFOBOX_Desfire->SetWindowText(_T("SelectAPP succeed "));
	}else{
		str.Format("%02x",ret);
	    INFOBOX_Desfire->SetWindowText(_T("SelectAPP fail ret=0x")+str);
	}
}


void dialogDesfire::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	unsigned char ret,aid,aidbuf[4];
	CString str;
	aid = Combo_AIDNo->GetCurSel();
	memset(aidbuf,0,sizeof(aidbuf));
	aidbuf[0]=aid;
	ret = DFCreateAID(aidbuf,0x0f,0x0d);
	if(!ret)
	{
	    INFOBOX_Desfire->SetWindowText(_T("CreateAPP succeed "));
	}else{
		str.Format("%02x",ret);
	    INFOBOX_Desfire->SetWindowText(_T("CreateAPP fail ret=0x")+str);
	}

}


void dialogDesfire::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	unsigned char ret,aid,aidbuf[4];
	CString str;
	aid = Combo_AIDNo->GetCurSel();
	memset(aidbuf,0,sizeof(aidbuf));
	aidbuf[0]=aid;
	ret = DFDeleteApp(aidbuf);
	if(!ret)
	{
	    INFOBOX_Desfire->SetWindowText(_T("DeleteApp succeed "));
	}else{
		str.Format("%02x",ret);
	    INFOBOX_Desfire->SetWindowText(_T("DeleteApp fail ret=0x")+str);
	}
}


void dialogDesfire::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	unsigned char ret,resbuf[256],num,i;
	CString str,aidstr="";
	ret=DFGetApplicationIDs(&num,resbuf);
	if(!ret)
	{   
		for(i=0;i<num;i++)
		{
			str.Format("%02x",resbuf[3*i]);
			aidstr+=str;
			str.Format("%02x",resbuf[3*i+1]);
			aidstr+=str;
			str.Format("%02x",resbuf[3*i+2]);
			aidstr+=str;
			aidstr+=_T("  ");
		}
	    INFOBOX_Desfire->SetWindowText(_T("AIDs:")+aidstr);

	}else{
		str.Format("%02x",ret);
	    INFOBOX_Desfire->SetWindowText(_T("GetApplicationIDs fail ret=0x")+str);
	}
}


void dialogDesfire::OnBnClickedButton11()
{
	// TODO: 在此添加控件通知处理程序代码
	unsigned char ret;
	CString str;
	ret = DFFormatCard();
	if(!ret)
	{
	    INFOBOX_Desfire->SetWindowText(_T("FormatCard succeed "));
	}else{
		str.Format("%02x",ret);
	    INFOBOX_Desfire->SetWindowText(_T("FormatCard fail ret=0x")+str);
	}
}


void dialogDesfire::OnBnClickedButton12()
{
	// TODO: 在此添加控件通知处理程序代码
	unsigned char ret,resbuf[256],num,i;
	CString str,aidstr="";
	ret=DFGetFileIDs(&num,resbuf);
	if(!ret)
	{   
		for(i=0;i<num;i++)
		{
			str.Format("%02x",resbuf[i]);
			aidstr+=str;
			aidstr+=_T("  ");
		}
	    INFOBOX_Desfire->SetWindowText(_T("FileIDs:")+aidstr);

	}else{
		str.Format("%02x",ret);
	    INFOBOX_Desfire->SetWindowText(_T("GetFileIDs fail ret=0x")+str);
	}
}


void dialogDesfire::OnBnClickedButton13()
{
	// TODO: 在此添加控件通知处理程序代码
	unsigned char ret,aid,aidbuf[4];
	CString str;
	aid = Combo_FileNo->GetCurSel();

	ret = DFDeleteFile(aid);
	if(!ret)
	{
	    INFOBOX_Desfire->SetWindowText(_T("DeleteFile succeed "));
	}else{
		str.Format("%02x",ret);
	    INFOBOX_Desfire->SetWindowText(_T("DeleteFile fail ret=0x")+str);
	}
}


void dialogDesfire::OnBnClickedButton14()
{
	// TODO: 在此添加控件通知处理程序代码
	unsigned char ret,aid,comset,settingbuf[4],databuff[8],filesizebuf[8];
	CString str;
	aid = Combo_FileNo->GetCurSel();
	memset(settingbuf,0,sizeof(settingbuf));
	comset = Combo_CommSet->GetCurSel();
	if(comset==2) comset=3;
	settingbuf[0]=comset;
	GetDlgItem(IDC_EDIT4)->GetWindowText(str);
	if(str.GetLength()!=4)
	{
		MessageBox(_T("inputs should be 2 byte hex AccessRight:"),_T("error:"));
		return;
	} 
	strcpy((char*)databuff,str);
	two_one(databuff,4,settingbuf+2);
	settingbuf[1]=settingbuf[3];

	GetDlgItem(IDC_EDIT18)->GetWindowText(str);
	if(str.GetLength()!=6)
	{
		MessageBox(_T("inputs should be 3 byte hex filesize:"),_T("error:"));
		return;
	} 
	strcpy((char*)databuff,str);
	two_one(databuff,6,filesizebuf);
	filesizebuf[3]=filesizebuf[0];
	filesizebuf[0]=filesizebuf[2];
	filesizebuf[2]=filesizebuf[3];
	ret = DFCreateSTDFile(aid,settingbuf,filesizebuf);
	if(!ret)
	{
	    INFOBOX_Desfire->SetWindowText(_T("CreateSTDFile succeed "));
	}else{
		str.Format("%02x",ret);
	    INFOBOX_Desfire->SetWindowText(_T("CreateSTDFile fail ret=0x")+str);
	}
}


void dialogDesfire::OnBnClickedButton15()
{
	// TODO: 在此添加控件通知处理程序代码
	unsigned char ret,aid,comset,settingbuf[4],databuff[8],filesizebuf[8];
	CString str;
	aid = Combo_FileNo->GetCurSel();
	memset(settingbuf,0,sizeof(settingbuf));
	comset = Combo_CommSet->GetCurSel();
	if(comset==2) comset=3;
	settingbuf[0]=comset;
	GetDlgItem(IDC_EDIT4)->GetWindowText(str);
	if(str.GetLength()!=4)
	{
		MessageBox(_T("inputs should be 2 byte hex AccessRight:"),_T("error:"));
		return;
	} 
	strcpy((char*)databuff,str);
	two_one(databuff,4,settingbuf+2);
	settingbuf[1]=settingbuf[3];

	GetDlgItem(IDC_EDIT18)->GetWindowText(str);
	if(str.GetLength()!=6)
	{
		MessageBox(_T("inputs should be 3 byte hex filesize:"),_T("error:"));
		return;
	} 
	strcpy((char*)databuff,str);
	two_one(databuff,6,filesizebuf);
	filesizebuf[3]=filesizebuf[0];
	filesizebuf[0]=filesizebuf[2];
	filesizebuf[2]=filesizebuf[3];
	ret = DFCreateBackupDataFile(aid,settingbuf,filesizebuf);
	if(!ret)
	{
	    INFOBOX_Desfire->SetWindowText(_T("CreateBackupDataFile succeed "));
	}else{
		str.Format("%02x",ret);
	    INFOBOX_Desfire->SetWindowText(_T("CreateBackupDataFile fail ret=0x")+str);
	}
}


void dialogDesfire::OnBnClickedButton16()
{
	// TODO: 在此添加控件通知处理程序代码
	unsigned char ret,aid,comset,settingbuf[4],databuff[32],LowerLimitbuf[32],UpperLimitbuf[32],Valuebuf[32],LimitedEn;
	CString str;
	aid = Combo_FileNo->GetCurSel();
	memset(settingbuf,0,sizeof(settingbuf));
	comset = Combo_CommSet->GetCurSel();
	if(comset==2) comset=3;
	settingbuf[0]=comset;
	GetDlgItem(IDC_EDIT4)->GetWindowText(str);
	if(str.GetLength()!=4)
	{
		MessageBox(_T("inputs should be 2 byte hex AccessRight:"),_T("error:"));
		return;
	} 
	strcpy((char*)databuff,str);
	two_one(databuff,4,settingbuf+2);
	settingbuf[1]=settingbuf[3];

	GetDlgItem(IDC_EDIT14)->GetWindowText(str);
	if(str.GetLength()!=8)
	{
		MessageBox(_T("inputs should be 4 byte hex LowerLimit :"),_T("error:"));
		return;
	} 
	strcpy((char*)databuff,str);
	two_one(databuff,8,LowerLimitbuf+3);
	LowerLimitbuf[0]=LowerLimitbuf[6];
	LowerLimitbuf[1]=LowerLimitbuf[5];
	LowerLimitbuf[2]=LowerLimitbuf[4];

	GetDlgItem(IDC_EDIT25)->GetWindowText(str);
	if(str.GetLength()!=8)
	{
		MessageBox(_T("inputs should be 4 byte hex UpperLimit :"),_T("error:"));
		return;
	} 
	strcpy((char*)databuff,str);
	two_one(databuff,8,UpperLimitbuf+3);
	UpperLimitbuf[0]=UpperLimitbuf[6];
	UpperLimitbuf[1]=UpperLimitbuf[5];
	UpperLimitbuf[2]=UpperLimitbuf[4];

	GetDlgItem(IDC_EDIT26)->GetWindowText(str);
	if(str.GetLength()!=8)
	{
		MessageBox(_T("inputs should be 4 byte hex Value :"),_T("error:"));
		return;
	} 
	strcpy((char*)databuff,str);
	two_one(databuff,8,Valuebuf+3);
	Valuebuf[0]=Valuebuf[6];
	Valuebuf[1]=Valuebuf[5];
	Valuebuf[2]=Valuebuf[4];

	if(((CButton*)GetDlgItem(IDC_CHECK1))->GetCheck()==TRUE)
		LimitedEn=1;
	else
		LimitedEn=0;

	ret = DFCreateValueFile(aid,settingbuf,LowerLimitbuf,UpperLimitbuf,Valuebuf,LimitedEn);
	if(!ret)
	{
	    INFOBOX_Desfire->SetWindowText(_T("CreateValueFile succeed "));
	}else{
		str.Format("%02x",ret);
	    INFOBOX_Desfire->SetWindowText(_T("CreateValueFile fail ret=0x")+str);
	}
}


void dialogDesfire::OnBnClickedButton17()
{
	// TODO: 在此添加控件通知处理程序代码
	unsigned char ret,aid,comset,settingbuf[4],databuff[8],filesizebuf[8],numberbuf[8];
	CString str;
	aid = Combo_FileNo->GetCurSel();
	memset(settingbuf,0,sizeof(settingbuf));
	comset = Combo_CommSet->GetCurSel();
	if(comset==2) comset=3;
	settingbuf[0]=comset;
	GetDlgItem(IDC_EDIT4)->GetWindowText(str);
	if(str.GetLength()!=4)
	{
		MessageBox(_T("inputs should be 2 byte hex AccessRight:"),_T("error:"));
		return;
	} 
	strcpy((char*)databuff,str);
	two_one(databuff,4,settingbuf+2);
	settingbuf[1]=settingbuf[3];

	GetDlgItem(IDC_EDIT27)->GetWindowText(str);
	if(str.GetLength()!=6)
	{
		MessageBox(_T("inputs should be 3 byte hex recordsize:"),_T("error:"));
		return;
	} 
	strcpy((char*)databuff,str);
	two_one(databuff,6,filesizebuf);
	filesizebuf[3]=filesizebuf[0];
	filesizebuf[0]=filesizebuf[2];
	filesizebuf[2]=filesizebuf[3];

	GetDlgItem(IDC_EDIT28)->GetWindowText(str);
	if(str.GetLength()!=6)
	{
		MessageBox(_T("inputs should be 3 byte hex RecordNum:"),_T("error:"));
		return;
	} 
	strcpy((char*)databuff,str);
	two_one(databuff,6,numberbuf);
	numberbuf[3]=numberbuf[0];
	numberbuf[0]=numberbuf[2];
	numberbuf[2]=numberbuf[3];
	ret = DFCreateLinearRecordFile(aid,settingbuf,filesizebuf,numberbuf);
	if(!ret)
	{
	    INFOBOX_Desfire->SetWindowText(_T("CreateLinearRecordFile succeed "));
	}else{
		str.Format("%02x",ret);
	    INFOBOX_Desfire->SetWindowText(_T("CreateLinearRecordFile fail ret=0x")+str);
	}
}


void dialogDesfire::OnBnClickedButton18()
{
	// TODO: 在此添加控件通知处理程序代码
	unsigned char ret,aid,comset,settingbuf[4],databuff[8],filesizebuf[8],numberbuf[8];
	CString str;
	aid = Combo_FileNo->GetCurSel();
	memset(settingbuf,0,sizeof(settingbuf));
	comset = Combo_CommSet->GetCurSel();
	if(comset==2) comset=3;
	settingbuf[0]=comset;
	GetDlgItem(IDC_EDIT4)->GetWindowText(str);
	if(str.GetLength()!=4)
	{
		MessageBox(_T("inputs should be 2 byte hex AccessRight:"),_T("error:"));
		return;
	} 
	strcpy((char*)databuff,str);
	two_one(databuff,4,settingbuf+2);
	settingbuf[1]=settingbuf[3];

	GetDlgItem(IDC_EDIT27)->GetWindowText(str);
	if(str.GetLength()!=6)
	{
		MessageBox(_T("inputs should be 3 byte hex recordsize:"),_T("error:"));
		return;
	} 
	strcpy((char*)databuff,str);
	two_one(databuff,6,filesizebuf);
	filesizebuf[3]=filesizebuf[0];
	filesizebuf[0]=filesizebuf[2];
	filesizebuf[2]=filesizebuf[3];

	GetDlgItem(IDC_EDIT28)->GetWindowText(str);
	if(str.GetLength()!=6)
	{
		MessageBox(_T("inputs should be 3 byte hex RecordNum:"),_T("error:"));
		return;
	} 
	strcpy((char*)databuff,str);
	two_one(databuff,6,numberbuf);
	numberbuf[3]=numberbuf[0];
	numberbuf[0]=numberbuf[2];
	numberbuf[2]=numberbuf[3];
	ret = DFCreateCyclicRecordFile(aid,settingbuf,filesizebuf,numberbuf);
	if(!ret)
	{
	    INFOBOX_Desfire->SetWindowText(_T("CreateCyclicRecordFile succeed "));
	}else{
		str.Format("%02x",ret);
	    INFOBOX_Desfire->SetWindowText(_T("CreateCyclicRecordFile fail ret=0x")+str);
	}
}


void dialogDesfire::OnBnClickedButton19()
{
	// TODO: 在此添加控件通知处理程序代码
	unsigned int rlen,i;
	unsigned char ret,fileno,settingbuf[4],databuff[8],offsetbuf[8],lenghtbuf[8],Readbuf[2048+16];
	CString str,Datastr="";
	fileno = Combo_DataFileNo->GetCurSel();
	memset(settingbuf,0,sizeof(settingbuf));
	

	GetDlgItem(IDC_EDIT29)->GetWindowText(str);
	if(str.GetLength()!=6)
	{
		MessageBox(_T("inputs should be 3 byte hex offset:"),_T("error:"));
		return;
	} 
	strcpy((char*)databuff,str);
	two_one(databuff,6,offsetbuf);
	offsetbuf[3]=offsetbuf[0];
	offsetbuf[0]=offsetbuf[2];
	offsetbuf[2]=offsetbuf[3];

	GetDlgItem(IDC_EDIT30)->GetWindowText(str);
	if(str.GetLength()!=6)
	{
		MessageBox(_T("inputs should be 3 byte hex lenght:"),_T("error:"));
		return;
	} 
	strcpy((char*)databuff,str);
	two_one(databuff,6,lenghtbuf);
	lenghtbuf[3]=lenghtbuf[0];
	lenghtbuf[0]=lenghtbuf[2];
	lenghtbuf[2]=lenghtbuf[3];
	ret = DFReadDataFile(fileno,offsetbuf,lenghtbuf,Readbuf,&rlen);
	if(!ret)
	{
		for(i=0;i<rlen;i++){
		   str.Format("%02x",Readbuf[i]);
		   Datastr+=str;
		}
		GetDlgItem(IDC_EDIT31)->SetWindowText(Datastr);
	    INFOBOX_Desfire->SetWindowText(_T("ReadDataFile succeed "));

	}else{
		str.Format("%02x",ret);
	    INFOBOX_Desfire->SetWindowText(_T("ReadDataFile fail ret=0x")+str);
	}
}


void dialogDesfire::OnBnClickedButton20()
{
	// TODO: 在此添加控件通知处理程序代码
	unsigned int rlen,i;
	unsigned char ret,fileno,settingbuf[4],databuff[4096+8],offsetbuf[8],lenghtbuf[8],Writebuf[2048+16];
	CString strlen,str,Datastr="";
	fileno = Combo_DataFileNo->GetCurSel();
	memset(settingbuf,0,sizeof(settingbuf));
	

	GetDlgItem(IDC_EDIT29)->GetWindowText(str);
	if(str.GetLength()!=6)
	{
		MessageBox(_T("inputs should be 3 byte hex offset:"),_T("error:"));
		return;
	} 
	strcpy((char*)databuff,str);
	two_one(databuff,6,offsetbuf);
	offsetbuf[3]=offsetbuf[0];
	offsetbuf[0]=offsetbuf[2];
	offsetbuf[2]=offsetbuf[3];

	GetDlgItem(IDC_EDIT30)->GetWindowText(str);
	if(str.GetLength()!=6)
	{
		MessageBox(_T("inputs should be 3 byte hex lenght:"),_T("error:"));
		return;
	} 
	strcpy((char*)databuff,str);
	two_one(databuff,6,lenghtbuf);
	lenghtbuf[3]=lenghtbuf[0];
	lenghtbuf[0]=lenghtbuf[2];
	lenghtbuf[2]=lenghtbuf[3];

	rlen=lenghtbuf[0]+lenghtbuf[1]*256+lenghtbuf[2]*256*256;

	GetDlgItem(IDC_EDIT31)->GetWindowText(str);
	if(str.GetLength()!=rlen*2)
	{
		MessageBox(_T("inputs should be lenght byte hex lenght:"),_T("error:"));
		return;
	} 
	strcpy((char*)databuff,str);
	two_one(databuff,str.GetLength(),Writebuf);

	ret = DFWriteDataFile(fileno,offsetbuf,lenghtbuf,Writebuf);
	if(!ret)
	{
	    INFOBOX_Desfire->SetWindowText(_T("WriteDataFile succeed "));
	}else{
		str.Format("%02x",ret);
	    INFOBOX_Desfire->SetWindowText(_T("WriteDataFile fail ret=0x")+str);
	}
}


void dialogDesfire::OnBnClickedButton24()
{
	// TODO: 在此添加控件通知处理程序代码
	unsigned int rlen,i;
	unsigned char ret,fileno,settingbuf[4],databuff[8],offsetbuf[8],lenghtbuf[8],Readbuf[2048+16];
	CString str,Datastr="";
	fileno = Combo_DataFileNo->GetCurSel();
	memset(settingbuf,0,sizeof(settingbuf));
	

	GetDlgItem(IDC_EDIT29)->GetWindowText(str);
	if(str.GetLength()!=6)
	{
		MessageBox(_T("inputs should be 3 byte hex offset:"),_T("error:"));
		return;
	} 
	strcpy((char*)databuff,str);
	two_one(databuff,6,offsetbuf);
	offsetbuf[3]=offsetbuf[0];
	offsetbuf[0]=offsetbuf[2];
	offsetbuf[2]=offsetbuf[3];

	GetDlgItem(IDC_EDIT30)->GetWindowText(str);
	if(str.GetLength()!=6)
	{
		MessageBox(_T("inputs should be 3 byte hex lenght:"),_T("error:"));
		return;
	} 
	strcpy((char*)databuff,str);
	two_one(databuff,6,lenghtbuf);
	lenghtbuf[3]=lenghtbuf[0];
	lenghtbuf[0]=lenghtbuf[2];
	lenghtbuf[2]=lenghtbuf[3];
	ret = DFReadRecord(fileno,offsetbuf,lenghtbuf,Readbuf,&rlen);
	if(!ret)
	{
		for(i=0;i<rlen;i++){
		   str.Format("%02x",Readbuf[i]);
		   Datastr+=str;
		}
		GetDlgItem(IDC_EDIT31)->SetWindowText(Datastr);
	    INFOBOX_Desfire->SetWindowText(_T("ReadRecord succeed "));

	}else{
		str.Format("%02x",ret);
	    INFOBOX_Desfire->SetWindowText(_T("ReadRecord fail ret=0x")+str);
	}
}


void dialogDesfire::OnBnClickedButton25()
{
	// TODO: 在此添加控件通知处理程序代码

	unsigned int rlen,i;
	unsigned char ret,fileno,settingbuf[4],databuff[4096+8],offsetbuf[8],lenghtbuf[8],Writebuf[2048+16];
	CString strlen,str,Datastr="";
	fileno = Combo_DataFileNo->GetCurSel();
	memset(settingbuf,0,sizeof(settingbuf));
	

	GetDlgItem(IDC_EDIT29)->GetWindowText(str);
	if(str.GetLength()!=6)
	{
		MessageBox(_T("inputs should be 3 byte hex offset:"),_T("error:"));
		return;
	} 
	strcpy((char*)databuff,str);
	two_one(databuff,6,offsetbuf);
	offsetbuf[3]=offsetbuf[0];
	offsetbuf[0]=offsetbuf[2];
	offsetbuf[2]=offsetbuf[3];

	GetDlgItem(IDC_EDIT30)->GetWindowText(str);
	if(str.GetLength()!=6)
	{
		MessageBox(_T("inputs should be 3 byte hex lenght:"),_T("error:"));
		return;
	} 
	strcpy((char*)databuff,str);
	two_one(databuff,6,lenghtbuf);
	lenghtbuf[3]=lenghtbuf[0];
	lenghtbuf[0]=lenghtbuf[2];
	lenghtbuf[2]=lenghtbuf[3];

	rlen=lenghtbuf[0]+lenghtbuf[1]*256+lenghtbuf[2]*256*256;

	GetDlgItem(IDC_EDIT31)->GetWindowText(str);
	if(str.GetLength()!=rlen*2)
	{
		MessageBox(_T("inputs should be lenght byte hex lenght:"),_T("error:"));
		return;
	} 
	strcpy((char*)databuff,str);
	two_one(databuff,str.GetLength(),Writebuf);

	ret = DFWriteRecord(fileno,offsetbuf,lenghtbuf,Writebuf);
	if(!ret)
	{
	    INFOBOX_Desfire->SetWindowText(_T("WriteRecord succeed "));
	}else{
		str.Format("%02x",ret);
	    INFOBOX_Desfire->SetWindowText(_T("WriteRecord fail ret=0x")+str);
	}
}


void dialogDesfire::OnBnClickedButton21()
{
	// TODO: 在此添加控件通知处理程序代码
	unsigned int rlen,i;
	unsigned char ret,fileno,settingbuf[4],databuff[8],offsetbuf[8],lenghtbuf[8],Readbuf[2048+16];
	CString str,Datastr="";
	fileno = Combo_DataFileNo->GetCurSel();
	memset(settingbuf,0,sizeof(settingbuf));
	
	ret = DFGetValueFile(fileno,Readbuf);
	if(!ret)
	{
		for(i=0;i<4;i++){
		   str.Format("%02x",Readbuf[3-i]);
		   Datastr+=str;
		}
		GetDlgItem(IDC_EDIT32)->SetWindowText(Datastr);
	    INFOBOX_Desfire->SetWindowText(_T("GetValueFile succeed "));

	}else{
		str.Format("%02x",ret);
	    INFOBOX_Desfire->SetWindowText(_T("GetValueFile fail ret=0x")+str);
	}
}


void dialogDesfire::OnBnClickedButton22()
{
	// TODO: 在此添加控件通知处理程序代码
	unsigned int rlen,i;
	unsigned char ret,fileno,settingbuf[4],databuff[16],offsetbuf[8],lenghtbuf[8],Writebuf[2048+16];
	CString str,Datastr="";
	fileno = Combo_DataFileNo->GetCurSel();
	memset(settingbuf,0,sizeof(settingbuf));
	
	GetDlgItem(IDC_EDIT32)->GetWindowText(str);
	if(str.GetLength()!=8)
	{
		MessageBox(_T("inputs should be 4 byte hex value:"),_T("error:"));
		return;
	} 
	strcpy((char*)databuff,str);
	two_one(databuff,str.GetLength(),Writebuf+3);
	
	Writebuf[0]=Writebuf[6];
	Writebuf[1]=Writebuf[5];
	Writebuf[2]=Writebuf[4];

	ret = DFPlusValueFile(fileno,Writebuf);
	if(!ret)
	{
	
	    INFOBOX_Desfire->SetWindowText(_T("PlusValueFile succeed "));

	}else{
		str.Format("%02x",ret);
	    INFOBOX_Desfire->SetWindowText(_T("PlusValueFile fail ret=0x")+str);
	}
}


void dialogDesfire::OnBnClickedButton23()
{
	// TODO: 在此添加控件通知处理程序代码
	unsigned int rlen,i;
	unsigned char ret,fileno,settingbuf[4],databuff[16],offsetbuf[8],lenghtbuf[8],Writebuf[2048+16];
	CString str,Datastr="";
	fileno = Combo_DataFileNo->GetCurSel();
	memset(settingbuf,0,sizeof(settingbuf));
	
	GetDlgItem(IDC_EDIT32)->GetWindowText(str);
	if(str.GetLength()!=8)
	{
		MessageBox(_T("inputs should be 4 byte hex value:"),_T("error:"));
		return;
	} 
	strcpy((char*)databuff,str);
	two_one(databuff,str.GetLength(),Writebuf+3);
	Writebuf[0]=Writebuf[6];
	Writebuf[1]=Writebuf[5];
	Writebuf[2]=Writebuf[4];
	ret = DFMinusValueFile(fileno,Writebuf);
	if(!ret)
	{
	
	    INFOBOX_Desfire->SetWindowText(_T("MinusValueFile succeed "));

	}else{
		str.Format("%02x",ret);
	    INFOBOX_Desfire->SetWindowText(_T("MinusValueFile fail ret=0x")+str);
	}
}


void dialogDesfire::OnBnClickedButton26()
{
	// TODO: 在此添加控件通知处理程序代码
	unsigned char ret;
	CString str;
	ret = DFCommitTransion();
	if(!ret)
	{
	
	    INFOBOX_Desfire->SetWindowText(_T("CommitTransion succeed "));

	}else{
		str.Format("%02x",ret);
	    INFOBOX_Desfire->SetWindowText(_T("CommitTransion fail ret=0x")+str);
	}
}


void dialogDesfire::OnBnClickedButton27()
{
	// TODO: 在此添加控件通知处理程序代码
	unsigned char ret;
	CString str;
	ret = DFAbortTransion();
	if(!ret)
	{
	
	    INFOBOX_Desfire->SetWindowText(_T("AbortTransion succeed "));

	}else{
		str.Format("%02x",ret);
	    INFOBOX_Desfire->SetWindowText(_T("AbortTransion fail ret=0x")+str);
	}
}


void dialogDesfire::OnBnClickedButton28()
{
	// TODO: 在此添加控件通知处理程序代码
    unsigned char ret,resbuf[256],num,i;
	CString str,aidstr="";
	ret=DFGetInfo(resbuf);
	if(!ret)
	{   
		for(i=0;i<7;i++)
		{
			str.Format("%02x",resbuf[i]);
			aidstr+=str;
			aidstr+=_T(" ");
		}
		aidstr+=_T("\r\n");
		for(;i<7+7;i++)
		{
			str.Format("%02x",resbuf[i]);
			aidstr+=str;
			aidstr+=_T(" ");
		}
		aidstr+=_T("\r\n");
		for(;i<7+7+7;i++)
		{
			str.Format("%02x",resbuf[i]);
			aidstr+=str;
			aidstr+=_T(" ");
		}
		aidstr+=_T("   ");
		for(;i<7+7+7+7;i++)
		{
			str.Format("%02x",resbuf[i]);
			aidstr+=str;
			aidstr+=_T(" ");
		}
	    INFOBOX_Desfire->SetWindowText(_T("CardInfo:\r\n")+aidstr);

	}else{
		str.Format("%02x",ret);
	    INFOBOX_Desfire->SetWindowText(_T("GetInfo fail ret=0x")+str);
	}
}


void dialogDesfire::OnBnClickedButton29()
{
	// TODO: 在此添加控件通知处理程序代码
	unsigned char ret,resbuf[256],num,i;
	CString str,aidstr="";
	ret=DFGetKeySetting(resbuf);
	if(!ret)
	{   
		for(i=0;i<2;i++)
		{
			str.Format("%02x",resbuf[i]);
			aidstr+=str;
			aidstr+=_T(" ");
		}
	    INFOBOX_Desfire->SetWindowText(_T("KeySetting:\r\n")+aidstr);

	}else{
		str.Format("%02x",ret);
	    INFOBOX_Desfire->SetWindowText(_T("GetKeySetting fail ret=0x")+str);
	}
}


void dialogDesfire::OnBnClickedButton30()
{
	// TODO: 在此添加控件通知处理程序代码
	unsigned char ret,resbuf[256],len,i,fileno;
	CString str,aidstr="";
	memset(resbuf,0,sizeof(resbuf));
	fileno = Combo_FileNo->GetCurSel();
	ret=DFGetFileSetting(fileno,resbuf,&len);
	if(!ret)
	{   
		for(i=0;i<len;i++)
		{
			str.Format("%02x",resbuf[i]);
			aidstr+=str;
			aidstr+=_T(" ");
		}
	    INFOBOX_Desfire->SetWindowText(_T("FileSetting:\r\n")+aidstr);

	}else{
		str.Format("%02x",ret);
	    INFOBOX_Desfire->SetWindowText(_T("GetFileSetting fail ret=0x")+str);
	}
}
