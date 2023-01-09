// Dialog1.cpp : implementation file
//

#include "stdafx.h"
#include "m160.h"
#include "Dialog1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

int BoolMagCard;


//#define Shutdown80Editbox
#define IDC_STATIC_TRACE1_NUM           1028
#define IDC_STATIC_TRACE2_NUM           1029
#define IDC_STATIC_TRACE3_NUM           1030


#include "ReadInfo.h"
//extern int MagSwiped();
#include "160.h"
extern int MSR_Statue;   	//160连接标志

HANDLE hThread,hWThread,hThread80;


CEdit *Track1;
CEdit *Track2;
CEdit *Track3;

CStatic *INFOBOX1;
CStatic *INFOBOX1ext;
extern unsigned char _stdcall openSer(int port);
extern int PortNum;
int MSR_INIT_FLAG=0;		//80连接标志	
int ZCS80ReadPro_flag;		//80读卡死循环
int ZCS80WritePro_flag;		//80写卡死循环
int ZCS80EreasePro_flag;
	int  tr1bit = 7;
	int tr2bit = 5;
   int tr3bit = 5;
   int parity1 = 0;
   int parity2 = 0;
   int parity3 = 0;
   int SS1 = 37;
   int SS2 = 59;
   int SS3 = 59;
   int ES1 = 63;
   int ES2 = 63;
   int ES3 = 63;

char TK1Dat[256],TK2Dat[256],TK3Dat[256];
CButton *pButton1;
CButton *pButton2;
CButton *pButton3;

CButton *M160Read;
CButton *M160Stop;
CButton *M80Read;
CButton *M80Write;

/////////////////////////////////////////////////////////////////////////////
// CDialog1 dialog


CDialog1::CDialog1(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog1::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialog1)
	//}}AFX_DATA_INIT
}


void CDialog1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialog1)
	DDX_Control(pDX, IDC_EDIT16, m_zcs80trcak1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialog1, CDialog)
	//{{AFX_MSG_MAP(CDialog1)
	ON_BN_CLICKED(IDC_RADIO3, OnRadio3)
	ON_BN_CLICKED(IDC_RADIO4, OnRadio4)
	ON_BN_CLICKED(IDOK4, OnOk4)
	ON_BN_CLICKED(IDOK2, OnOk2)
	ON_BN_CLICKED(IDCANCEL2, OnCancel2)
	ON_BN_CLICKED(IDOK3, OnOk3)
	ON_BN_CLICKED(IDOK5, OnOk5)
	ON_EN_CHANGE(IDC_EDIT17, OnChangeEdit17)
	ON_EN_CHANGE(IDC_EDIT18, OnChangeEdit18)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialog1 message handlers
void ReadPro(LPVOID lpParam)
{
	int nRet,i=0;

	CString strValue;
	CString str;
	char TK1Dat[256],TK2Dat[256],TK3Dat[256],tmp[1000];
	while(1 && BoolMagCard)
	{

		if(BoolMagCard==0)
			return;

		switch((i++)%3)
		{
			case 0:
				((CWnd*)lpParam)->SetDlgItemText(IDC_STATIC1,_T("Read ->"));
				break;
			case 1:
				((CWnd*)lpParam)->SetDlgItemText(IDC_STATIC1,_T("Read -->"));
				break;
			case 2:
				((CWnd*)lpParam)->SetDlgItemText(IDC_STATIC1,_T("Read --->"));
				break;
		}
		if(i==3) i=0;
		Sleep(500);

		nRet=MagSwiped();

	//	strValue.Format("%d", nRet);
	//	((CWnd*)lpParam)->SetDlgItemText(IDC_EDIT1,strValue);

		if(nRet==0)
		{
			memset(TK1Dat,0,sizeof(TK1Dat));
			memset(TK2Dat,0,sizeof(TK2Dat));
			memset(TK3Dat,0,sizeof(TK3Dat));
		//	nRet=MagRead((unsigned char *)TK1Dat, (unsigned char *)TK2Dat, (unsigned char *)TK3Dat);
		
			nRet=MagRead_DES((unsigned char *)TK1Dat, (unsigned char *)TK2Dat, (unsigned char *)TK3Dat);

		//	strValue.Format("%d", strlen(TK1Dat));
		//	AfxMessageBox(strValue,NULL,NULL);

			((CWnd*)lpParam)->SetDlgItemText(IDC_EDIT2,_T(""));
			((CWnd*)lpParam)->SetDlgItemText(IDC_EDIT3,_T(""));
			((CWnd*)lpParam)->SetDlgItemText(IDC_EDIT4,_T(""));
			Sleep(100);
		
		/*		
			strValue="";
			for(int i=0;i<strlen(TK1Dat);i++)
			{	
				str.Format("%02x ",TK1Dat[i]);
				strValue=strValue+str;
		
			}
*/
			strValue = TK1Dat+1;
		//	strValue=ShowHexData(TK1Dat);

			((CWnd*)lpParam)->SetDlgItemText(IDC_EDIT2,strValue);

			strValue = TK2Dat+1;
			((CWnd*)lpParam)->SetDlgItemText(IDC_EDIT3,strValue);


			strValue = TK3Dat+1;
			((CWnd*)lpParam)->SetDlgItemText(IDC_EDIT4,strValue);

			Sleep(5);

		}
		/*
		strcpy(tmp+1,TK1Dat);
		tmp[0]='%';
		tmp[strlen(tmp)]='?';
		//strValue.Format("%c", tmp);
		strValue = tmp;
		((CWnd*)lpParam)->SetDlgItemText(IDC_EDIT7,strValue);
		*/

	//	AfxMessageBox(strValue,NULL,NULL);

	//AfxMessageBox("无法连接终端",NULL,NULL);

	}

}

void CDialog1::OnOK() 
{
	if( MSR_INIT_FLAG==1)
	{
		MessageBox(_T("please use Read-Write..."),_T("error:") );
	}
	else if(MSR_Statue==0)	
	{
		MessageBox(_T("unconnect..."),_T("error:") );
	}
	else
	{
	BoolMagCard=1;
	hThread=CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)ReadPro,this,0,NULL);
	CloseHandle(hThread);
	}
}

void CDialog1::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	BoolMagCard=0;	
		GetDlgItem(IDC_STATIC1)->SetWindowText(_T("..."));

}

void CDialog1::OnRadio3() 
{
	
	ZCS80ReadPro_flag=0;
	ZCS80WritePro_flag=0;
//	INFOBOX1->SetWindowText("...");


//	GetDlgItem(IDOK2)->EnableWindow(1);
//	GetDlgItem(IDOK3)->EnableWindow(1);
//	GetDlgItem(IDOK4)->EnableWindow(1);
	GetDlgItem(IDC_STATIC3)->SetWindowText(_T(""));

//	GetDlgItem(IDC_EDIT16)->SetWindowText("");
//	GetDlgItem(IDC_EDIT17)->SetWindowText("");
//	GetDlgItem(IDC_EDIT18)->SetWindowText("");

#if defined Shutdown80Editbox
	GetDlgItem(IDC_EDIT16)->EnableWindow(0);
	GetDlgItem(IDC_EDIT17)->EnableWindow(0);
	GetDlgItem(IDC_EDIT18)->EnableWindow(0);
#endif

		MSR_Set_HiCo();
}

void CDialog1::OnRadio4() 
{

	ZCS80ReadPro_flag=0;
	ZCS80WritePro_flag=0;
//	INFOBOX1->SetWindowText("...");

//	GetDlgItem(IDOK2)->EnableWindow(1);
//	GetDlgItem(IDOK3)->EnableWindow(1);
//	GetDlgItem(IDOK4)->EnableWindow(1);
	GetDlgItem(IDC_STATIC3)->SetWindowText(_T(""));

//	GetDlgItem(IDC_EDIT16)->SetWindowText("");
//	GetDlgItem(IDC_EDIT17)->SetWindowText("");
//	GetDlgItem(IDC_EDIT18)->SetWindowText("");

#if defined Shutdown80Editbox
	GetDlgItem(IDC_EDIT16)->EnableWindow(0);
	GetDlgItem(IDC_EDIT17)->EnableWindow(0);
	GetDlgItem(IDC_EDIT18)->EnableWindow(0);
#endif


		MSR_Set_LoCo();	
}


BOOL CDialog1::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
		

	GetDlgItem(IDOK5)->ShowWindow(0);
	GetDlgItem(IDCANCEL2)->ShowWindow(0);

	Track1=(CEdit*)GetDlgItem(IDC_EDIT16);
	Track2=(CEdit*)GetDlgItem(IDC_EDIT17);
	Track3=(CEdit*)GetDlgItem(IDC_EDIT18);

	CButton* M160Read=(CButton*)GetDlgItem(IDOK);
	CButton* M160Stop=(CButton*)GetDlgItem(IDCANCEL);
	CButton* M80Read=(CButton*)GetDlgItem(IDOK2);
	CButton* M80Write=(CButton*)GetDlgItem(IDOK3);



	CButton* radio=(CButton*)GetDlgItem(IDC_RADIO3);
	radio->SetCheck(1);

	pButton1 = (CButton*)GetDlgItem(IDC_CHECK1); 
	pButton1->SetCheck(1);

	pButton2 = (CButton*)GetDlgItem(IDC_CHECK2); 
	pButton2->SetCheck(1);

	pButton3 = (CButton*)GetDlgItem(IDC_CHECK3); 
	pButton3->SetCheck(1);
//	MSR_Set_HiCo();	

	INFOBOX1=(CStatic*)GetDlgItem(IDC_STATIC2);
	INFOBOX1ext=(CStatic*)GetDlgItem(IDC_STATIC3);
	CEdit *keybox;
	CEdit *keybox1;
	CEdit *keybox2;
	keybox=(CEdit*)GetDlgItem(IDC_EDIT16);
	keybox1=(CEdit*)GetDlgItem(IDC_EDIT17);
	keybox2=(CEdit*)GetDlgItem(IDC_EDIT18);
	keybox->SetLimitText(76);
	keybox1->SetLimitText(37);
	keybox2->SetLimitText(104);
#if defined Shutdown80Editbox
	GetDlgItem(IDC_EDIT16)->EnableWindow(0);
	GetDlgItem(IDC_EDIT17)->EnableWindow(0);
	GetDlgItem(IDC_EDIT18)->EnableWindow(0);
#endif
	GetDlgItem(IDOK4)->ShowWindow(0);



//	GetDlgItem(IDC_EDIT16)->SetLimitText(32);
//	GetDlgItem(IDC_EDIT17)->SetLimitText(32);
//	GetDlgItem(IDC_EDIT18)->SetLimitText(32);


	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDialog1::OnOk4() 
{
	int mark1;

	ZCS80WritePro_flag=0;
	ZCS80ReadPro_flag=0;

	INFOBOX1->SetWindowText(_T("..."));
	Sleep(5);

	if(PortNum>200)   //   usb  ***************
	{
			mark1 = openSer(201);
			if( mark1!=0 || mark1==22)
			{
				INFOBOX1->SetWindowText(_T("U口初始化失败..."));
				MSR_INIT_FLAG = 0;
				return;
			}
			else
			{
				mark1 = MSR_Init();
				if(mark1<0 || mark1 == 255 || mark1 == 254) 
				{
					INFOBOX1->SetWindowText(_T("初始化失败..."));
					MSR_INIT_FLAG = 0;
					return;
				}
				else
				{
					INFOBOX1->SetWindowText(_T("初始化成功..."));
					MSR_INIT_FLAG = 1;
									
				}
			}
	}
	else		//   串口  ***************
	{
	
		mark1 = MSR_Init();
		if(mark1 < 0)
		{
			MSR_INIT_FLAG = 0;
			INFOBOX1->SetWindowText(_T("初始化失败..."));
			return;
		}
		else
		{
			INFOBOX1->SetWindowText(_T("初始化成功..."));
			MSR_INIT_FLAG = 1;
		}
	}

	if(MSR_INIT_FLAG==1)
	{
		MSR_Set_HiCo();
		int mark = MSR_DoCancel();		//复位

		GetDlgItem(IDOK4)->EnableWindow(0);
	}
}







void ZCS80_ReadPro(LPVOID lpParam)
{
		unsigned char cRet;
		CString m_time,strread,str1,str2,str3;
		char tmp[1024];
		int nRet,i=0;


		while(ZCS80ReadPro_flag)
		{

			if(ZCS80ReadPro_flag==0)
				return;

			nRet=MSR_ASC_Read();
		//	nRet=MSR_Read();
			if(nRet<0)
			{
				nRet=MSR_ASC_Read();
				if(nRet<0)
				{
					INFOBOX1->SetWindowText(_T("通讯失败..."));
					ZCS80ReadPro_flag=0;
					return;
				}
			}
			while(ZCS80ReadPro_flag)
			{

				switch((i++)%3)
				{
					case 0:
						((CWnd*)lpParam)->SetDlgItemText(IDC_STATIC2,_T("Read ->"));
						break;
					case 1:
						((CWnd*)lpParam)->SetDlgItemText(IDC_STATIC2,_T("Read -->"));
						break;
					case 2:
						((CWnd*)lpParam)->SetDlgItemText(IDC_STATIC2,_T("Read --->"));
						break;
				}
				if(i==3) i=0;
			//	Sleep(500);


				nRet=MSR_GetTrackData((unsigned char *)TK1Dat, (unsigned char *)TK2Dat, (unsigned char *)TK3Dat);
				if(nRet>0)break;
				Sleep(100);
			}

				if(ZCS80ReadPro_flag==0)
					return;

			((CWnd*)lpParam)->SetDlgItemText(IDC_EDIT16,_T(""));
			((CWnd*)lpParam)->SetDlgItemText(IDC_EDIT17,_T(""));
			((CWnd*)lpParam)->SetDlgItemText(IDC_EDIT18,_T(""));	
			Sleep(30);

			cRet=User_To_ASC((unsigned char *)TK1Dat,(unsigned char *)TK2Dat,(unsigned char *)TK3Dat,parity1,parity2,parity3,tr1bit,tr2bit,tr3bit,ES1,ES2,ES3);


			//	GetDlgItem(IDC_EDIT4)->SetWindowText(strValue);
			str1=TK1Dat;
			((CWnd*)lpParam)->SetDlgItemText(IDC_EDIT16,str1);

			str2=TK2Dat;
			((CWnd*)lpParam)->SetDlgItemText(IDC_EDIT17,str2);

			str3=TK3Dat;
			((CWnd*)lpParam)->SetDlgItemText(IDC_EDIT18,str3);

		}


}




//extern ReadInfo InfoDlg;

void CDialog1::OnOk2() 
{
	ZCS80WritePro_flag=0;
	ZCS80ReadPro_flag=0;
	if(MSR_INIT_FLAG==0 && MSR_Statue==0)
	{
		MessageBox(_T("unconnect..."),_T("error:") );
		return;
	}
	else if(MSR_Statue==1 && MSR_INIT_FLAG==0)
	{
		MessageBox(_T("please use Read-Only..."),_T("error:") );
		return;
	}

#if defined Shutdown80Editbox
	GetDlgItem(IDC_EDIT16)->EnableWindow(0);
	GetDlgItem(IDC_EDIT17)->EnableWindow(0);
	GetDlgItem(IDC_EDIT18)->EnableWindow(0);
#endif
//	GetDlgItem(IDOK2)->EnableWindow(0);  //IDOK5

	GetDlgItem(IDOK3)->EnableWindow(1);

	GetDlgItem(IDC_STATIC3)->SetWindowText(_T(""));


	GetDlgItem(IDC_EDIT18)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT17)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT16)->SetWindowText(_T(""));

	int mark = MSR_DoCancel();		//复位

	ZCS80ReadPro_flag=1;
	hThread80=CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)ZCS80_ReadPro,this,0,NULL);
	CloseHandle(hThread80);

	ReadInfo InfoDlg;
	InfoDlg.DoModal();
}

void CDialog1::OnCancel2() 
{
	ZCS80ReadPro_flag=0;
	ZCS80WritePro_flag=0;
	INFOBOX1->SetWindowText(_T("..."));

	GetDlgItem(IDOK2)->EnableWindow(1);
	GetDlgItem(IDOK3)->EnableWindow(1);
	GetDlgItem(IDOK4)->EnableWindow(1);
	GetDlgItem(IDC_STATIC3)->SetWindowText(_T(""));

	GetDlgItem(IDC_EDIT16)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT17)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT18)->SetWindowText(_T(""));

#if defined Shutdown80Editbox
	GetDlgItem(IDC_EDIT16)->EnableWindow(0);
	GetDlgItem(IDC_EDIT17)->EnableWindow(0);
	GetDlgItem(IDC_EDIT18)->EnableWindow(0);
#endif
		int mark = MSR_DoCancel();
}



void ZCS80_WritePro(LPVOID lpParam)
{

	unsigned char cRet;
	CString m_time,strread,str1,str2,str3,str;
	char tmp[1024];
	int nRet,i=0;
	int ReadSucceedNum=0;


	((CWnd*)lpParam)->GetDlgItemText(IDC_EDIT16,str1);
	((CWnd*)lpParam)->GetDlgItemText(IDC_EDIT17,str2);
	((CWnd*)lpParam)->GetDlgItemText(IDC_EDIT18,str3);

	if(pButton1->GetCheck()==0)
		str1="";
	if(pButton2->GetCheck()==0)
		str2="";
	if(pButton3->GetCheck()==0)
		str3="";
	
	strcpy((char*)TK1Dat,str1);	

	strcpy((char*)TK2Dat,str2);	

	strcpy((char*)TK3Dat,str3);	


	while(ZCS80WritePro_flag)
	{

		nRet=MSR_Write_SPEC(TK1Dat,TK2Dat,TK3Dat,parity1,parity2,parity3,tr1bit,tr2bit,tr3bit,SS1,ES1,SS2,ES2,SS3,ES3);			
		if(nRet<0)
		{
			((CWnd*)lpParam)->SetDlgItemText(IDC_STATIC2,_T("write Error"));
			ZCS80WritePro_flag=0;
			return;
		}
		while(ZCS80WritePro_flag)
		{

				switch((i++)%3)
				{
					case 0:
						((CWnd*)lpParam)->SetDlgItemText(IDC_STATIC2,_T("Write ->"));
						break;
					case 1:
						((CWnd*)lpParam)->SetDlgItemText(IDC_STATIC2,_T("Write -->"));
						break;
					case 2:
						((CWnd*)lpParam)->SetDlgItemText(IDC_STATIC2,_T("Write --->"));
						break;
				}
				if(i==3) i=0;


				nRet=MSR_Write_status();
			//	if(nRet!=0x0)
				if(nRet==0x30)
				{	
					ReadSucceedNum++;
					str.Format(_T("%d"),ReadSucceedNum);
					
					((CWnd*)lpParam)->SetDlgItemText(IDC_STATIC3,_T("Write succeed:")+str);
					break;
				}
				else if(nRet<0)
				{
					((CWnd*)lpParam)->SetDlgItemText(IDC_STATIC3,_T("Failed..."));
					break;
				}
				else if(nRet==27 || nRet==0x31 ||  nRet==0x32)	//error
				{
					((CWnd*)lpParam)->SetDlgItemText(IDC_STATIC3,_T("写卡失败..."));
					break;
				}
				Sleep(100);		
		
		}

	}
	return;

}




void CDialog1::OnOk3() 
{
	ZCS80ReadPro_flag=0;
	ZCS80WritePro_flag=0;
	if(MSR_INIT_FLAG==0 && MSR_Statue==0)
	{
		MessageBox(_T("unconnect..."),_T("error:") );
		return;
	}
	else if(MSR_Statue==1 && MSR_INIT_FLAG==0)
	{
		MessageBox(_T("please use Read-Only..."),_T("error:") );
		return;
	}
	
//Sleep(2000);
#if defined Shutdown80Editbox
	GetDlgItem(IDC_EDIT16)->EnableWindow(0);
	GetDlgItem(IDC_EDIT17)->EnableWindow(0);
	GetDlgItem(IDC_EDIT18)->EnableWindow(0);
#endif
	GetDlgItem(IDOK2)->EnableWindow(1);
//	GetDlgItem(IDOK3)->EnableWindow(0);


	CString strValue,str1,str2,str3;
	GetDlgItem(IDC_EDIT16)->GetWindowText(str1);
	GetDlgItem(IDC_EDIT17)->GetWindowText(str2);
	GetDlgItem(IDC_EDIT18)->GetWindowText(str3);

	if(pButton1->GetCheck()!=0 && str1=="")
	{
		MessageBox(_T("track 1 no data..."));
		return;
	}
	if(pButton2->GetCheck()!=0 && str2=="")
	{
		MessageBox(_T("track 2 no data..."));
		return;
	}
	if(pButton3->GetCheck()!=0 && str3=="")
	{
		MessageBox(_T("track 3 no data..."));
		return;
	}

	GetDlgItem(IDC_STATIC3)->SetWindowText(_T(""));


	//str1 = ClearFlag(str1);
	//%ABCDEFG123450000000000000000000?
	int i=str1.GetLength();
	if(i!=0)
	{
		if(str1[i-1]=='?')
		{
			str1=str1.Left(i-1);
			GetDlgItem(IDC_EDIT16)->SetWindowText(str1);
		}
		if(str1[0]=='%')
		{
			i=str1.GetLength();
			str1=str1.Right(i-1);
			GetDlgItem(IDC_EDIT16)->SetWindowText(str1);
		}
	}
	//;1234567891001?
	i=str2.GetLength();
	if(i!=0)
	{
		if(str2[i-1]=='?')
		{

			str2=str2.Left(i-1);
			GetDlgItem(IDC_EDIT17)->SetWindowText(str2);
		}
		if(str2[0]==';')
		{
			i=str2.GetLength();
			str2=str2.Right(i-1);
			GetDlgItem(IDC_EDIT17)->SetWindowText(str2);
		}

	}

	//;12345678911231300100990?
	i=str3.GetLength();
	if(i!=0)
	{
		if(str3[i-1]=='?')
		{

			str3=str3.Left(i-1);
			GetDlgItem(IDC_EDIT18)->SetWindowText(str3);
		}
		if(str3[0]==';')
		{
			i=str3.GetLength();
			str3=str3.Right(i-1);
			GetDlgItem(IDC_EDIT18)->SetWindowText(str3);
		}
	}


	int mark = MSR_DoCancel();		//复位

	ZCS80WritePro_flag=1;	
	
	hThread80=CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)ZCS80_WritePro,this,0,NULL);
	CloseHandle(hThread80);	

	ReadInfo InfoDlg;
	InfoDlg.DoModal();
}

void CDialog1::OnOk5() 
{

	ZCS80ReadPro_flag=0;
	ZCS80WritePro_flag=0;

	if(MSR_INIT_FLAG==0)
	{
		MessageBox(_T("unconnect..."),_T("error:") );
		return;
	}

	GetDlgItem(IDOK2)->EnableWindow(1);
	GetDlgItem(IDOK3)->EnableWindow(1);


	GetDlgItem(IDC_STATIC3)->SetWindowText(_T(""));

	GetDlgItem(IDC_STATIC2)->SetWindowText(_T("请输入数据..."));

#if defined Shutdown80Editbox
	GetDlgItem(IDC_EDIT16)->EnableWindow(1);
	GetDlgItem(IDC_EDIT17)->EnableWindow(1);
	GetDlgItem(IDC_EDIT18)->EnableWindow(1);
#endif


	CString strValue,str1,str2,str3;
	GetDlgItem(IDC_EDIT16)->GetWindowText(str1);
	GetDlgItem(IDC_EDIT17)->GetWindowText(str2);
	GetDlgItem(IDC_EDIT18)->GetWindowText(str3);

	int i=str1.GetLength();
	if(i!=0)
	{
		if(str1[i-1]=='?')
		{
			str1=str1.Left(i-1);
			GetDlgItem(IDC_EDIT16)->SetWindowText(str1);
		}
		if(str1[0]=='%')
		{
			i=str1.GetLength();
			str1=str1.Right(i-1);
			GetDlgItem(IDC_EDIT16)->SetWindowText(str1);
		}
	}
	//;1234567891001?
	i=str2.GetLength();
	if(i!=0)
	{
		if(str2[i-1]=='?')
		{

			str2=str2.Left(i-1);
			GetDlgItem(IDC_EDIT17)->SetWindowText(str2);
		}
		if(str2[0]==';')
		{
			i=str2.GetLength();
			str2=str2.Right(i-1);
			GetDlgItem(IDC_EDIT17)->SetWindowText(str2);
		}
	}


	//;12345678911231300100990?
	i=str3.GetLength();
	if(i!=0)
	{
		if(str3[i-1]=='?')
		{

			str3=str3.Left(i-1);
			GetDlgItem(IDC_EDIT18)->SetWindowText(str3);
		}
		if(str3[0]==';')
		{
			i=str3.GetLength();
			str3=str3.Right(i-1);
			GetDlgItem(IDC_EDIT18)->SetWindowText(str3);
		}
	}
}

void CDialog1::OnChangeEdit17() 
{
	CString csAreaS;
	CPoint CPos;
	int dwX,dwY;
	char mod,decnum;
	

	if(tr2bit==4||tr2bit==5){
		decnum=0x30;
		mod=0xf0;
	}else{
		decnum=0x20;
		mod=0xc0;			
	}
	
	dwX=0;
	dwY=0;
	((CEdit*)GetDlgItem( IDC_EDIT17 ))->GetWindowText( csAreaS );
	int nStringLength = csAreaS.GetLength();
	((CEdit*)GetDlgItem( IDC_EDIT17 ))->GetSel(dwX,dwY);
	if(1){
		for ( int nIndex = 0; nIndex < nStringLength; nIndex++ ){
			if((csAreaS[ nIndex ]-decnum)&mod||csAreaS[ nIndex ]==SS2||csAreaS[ nIndex ]==ES2){	
				csAreaS = csAreaS.Left( nIndex ) + csAreaS.Right( csAreaS.GetLength() - nIndex - 1 );
				GetDlgItem( IDC_EDIT17 )->SetWindowText( csAreaS );
				((CEdit*)GetDlgItem(IDC_EDIT17))->SetSel(dwX-1,dwY-1,TRUE);
				break;
			}
		}
	}
	else{

		for ( int nIndex = 0; nIndex < nStringLength; nIndex++ ){
			if(( csAreaS[ nIndex ] > '9' || csAreaS[ nIndex ] < '0' )){
				if(( csAreaS[ nIndex ] > 'F' || csAreaS[ nIndex ] < 'A' )){
					csAreaS = csAreaS.Left( nIndex ) + csAreaS.Right( csAreaS.GetLength() - nIndex - 1 );
					GetDlgItem( IDC_EDIT17 )->SetWindowText( csAreaS );
					((CEdit*)GetDlgItem(IDC_EDIT17))->SetSel(dwX-1,dwY-1,TRUE);
					break;
				}
			}
		}
	}

	CString strCounts(_T("")), strText(_T(""));
	GetDlgItemText(IDC_EDIT17, strText);

	strCounts.Format(_T("%d"), strText.GetLength());



	SetDlgItemText(IDC_STATIC_TRACE2_NUM, strCounts);
	
}

void CDialog1::OnChangeEdit18() 
{
	CString csAreaS;
	CPoint CPos;
	int dwX,dwY;
	char mod,decnum;
	

	if(tr3bit==4||tr3bit==5){
		decnum=0x30;
		mod=0xf0;
	}else{
		decnum=0x20;
		mod=0xc0;			
	}
	
	dwX=0;
	dwY=0;
	((CEdit*)GetDlgItem( IDC_EDIT18 ))->GetWindowText( csAreaS );
	int nStringLength = csAreaS.GetLength();
	((CEdit*)GetDlgItem( IDC_EDIT18 ))->GetSel(dwX,dwY);
	
	if(1){
		for ( int nIndex = 0; nIndex < nStringLength; nIndex++ ){
			if((csAreaS[ nIndex ]-decnum)&mod||csAreaS[ nIndex ]==SS3||csAreaS[ nIndex ]==ES3){	
				csAreaS = csAreaS.Left( nIndex ) + csAreaS.Right( csAreaS.GetLength() - nIndex - 1 );
				GetDlgItem( IDC_EDIT18 )->SetWindowText( csAreaS );
				((CEdit*)GetDlgItem(IDC_EDIT18))->SetSel(dwX-1,dwY-1,TRUE);
				break;
			}
		}	
	}
	else{

		for ( int nIndex = 0; nIndex < nStringLength; nIndex++ ){
			if(( csAreaS[ nIndex ] > '9' || csAreaS[ nIndex ] < '0' )){
				if(( csAreaS[ nIndex ] > 'F' || csAreaS[ nIndex ] < 'A' )){
					csAreaS = csAreaS.Left( nIndex ) + csAreaS.Right( csAreaS.GetLength() - nIndex - 1 );
					GetDlgItem( IDC_EDIT18 )->SetWindowText( csAreaS );
					((CEdit*)GetDlgItem(IDC_EDIT18))->SetSel(dwX-1,dwY-1,TRUE);
					break;
				}
			}
		}
	}
	CString strCounts(_T("")), strText(_T(""));
	GetDlgItemText(IDC_EDIT18, strText);

	strCounts.Format(_T("%d"), strText.GetLength());



	SetDlgItemText(IDC_STATIC_TRACE3_NUM, strCounts);	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}
unsigned char EraseType;
void ZCS80_EreeasePro(LPVOID lpParam)
{
	int nRet;
	while(ZCS80EreasePro_flag)
	{
		nRet=MSR_Erase(EraseType);
		if(nRet<0);
		//	((CWnd*)lpParam)->SetDlgItemText(IDC_STATIC2,"擦除失败...");
		else
		{
			while(1)
			{
				nRet=MSR_Erase_status();
				((CWnd*)lpParam)->SetDlgItemText(IDC_STATIC2,_T("..."));
				if(nRet!=0)
				{
					((CWnd*)lpParam)->SetDlgItemText(IDC_STATIC2,_T("擦除成功..."));
					break;
				}
				Sleep(5);
			}
		
		}

	}



}
void CDialog1::OnButton1() 
{
	if(MSR_INIT_FLAG==0 && MSR_Statue==0)
	{
		MessageBox(_T("unconnect..."),_T("error:") );
		return;
	}
	else if(MSR_Statue==1 && MSR_INIT_FLAG==0)
	{
		MessageBox(_T("please use Read-Only..."),_T("error:") );
		return;
	}

	// TODO: Add your control notification handler code here
	EraseType=0;
	if(pButton1->GetCheck()!=0)
		EraseType|=0x01;
	if(pButton2->GetCheck()!=0)
		EraseType|=0x02;
	if(pButton3->GetCheck()!=0)
		EraseType|=0x04;

	HANDLE hThread81;
	ZCS80EreasePro_flag=1;
	hThread81=CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)ZCS80_EreeasePro,this,0,NULL);
	CloseHandle(hThread81);

		ReadInfo InfoDlg;
	InfoDlg.DoModal();
	
}
