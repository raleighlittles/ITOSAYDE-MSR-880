// m160Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "m160.h"
#include "m160Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


#include "160.h"

int MSR_Statue=0;
extern int BoolMagCard;
extern int ZCS80ReadPro_flag;		//80读卡死循环
extern int ZCS80WritePro_flag;		//80写卡死循环
long Boudary;
int PortNum;
CButton* radio1;//=(CButton*)GetDlgItem(IDC_RADIO3);




extern	int  tr1bit;
extern	int tr2bit;
extern   int tr3bit ;
extern   int parity1 ;
 extern  int parity2 ;
 extern  int parity3 ;
 extern  int SS1 ;
 extern  int SS2 ;
 extern  int SS3 ;
extern   int ES1 ;
 extern  int ES2 ;
extern   int ES3 ;

extern char TK1Dat[256],TK2Dat[256],TK3Dat[256];
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CM160Dlg dialog

CM160Dlg::CM160Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CM160Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CM160Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CM160Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CM160Dlg)
	DDX_Control(pDX, IDC_TAB1, m_tabMain);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CM160Dlg, CDialog)
	//{{AFX_MSG_MAP(CM160Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, OnSelchangeTab1)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	ON_BN_CLICKED(IDC_RADIO3, OnRadio3)
	ON_BN_CLICKED(IDC_RADIO4, OnRadio4)
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CM160Dlg message handlers

BOOL CM160Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
 m_tabMain.InsertItem(0,_T("Magnetic card"));
 m_tabMain.InsertItem(1,_T("CPU card")); 
 m_tabMain.InsertItem(2,_T("Memory card")); 
 m_tabMain.InsertItem(4,_T("M1 card"));
 m_tabMain.InsertItem(5,_T("ULlight card")); 
 m_tabMain.InsertItem(6,_T("Desfire card")); 
 m_tabMain.InsertItem(7,_T("PinPad")); 
 m_tabMain.InsertItem(8,_T("EMV"));
//关联对话框,并且将IDC_TABMAIN控件设为父窗口
 m_para1.Create(IDD_DIALOG1,GetDlgItem(IDD_M160_DIALOG));
 m_para2.Create(IDD_DIALOG2,GetDlgItem(IDD_M160_DIALOG));
 m_para3.Create(IDD_DIALOG3,GetDlgItem(IDD_M160_DIALOG));
 m_para4.Create(IDD_DIALOG4,GetDlgItem(IDD_M160_DIALOG));
 m_para5.Create(IDD_DIALOG5,GetDlgItem(IDD_M160_DIALOG));

 m_paraDesfire.Create(IDD_DIALOGDESFIRE,GetDlgItem(IDD_M160_DIALOG));
 m_paraPinPad.Create(IDD_DIALOGPINPAD,GetDlgItem(IDD_M160_DIALOG));
 
 m_paraEmv.Create(IDD_DIALOGEMV,GetDlgItem(IDD_M160_DIALOG));  /////

 m_para6.Create(IDD_DIALOG6,GetDlgItem(IDD_M160_DIALOG));
 InfoDlg.Create(IDD_DIALOG6,GetDlgItem(IDD_M160_DIALOG));

 CRect rs;
 m_tabMain.GetClientRect(&rs);
 rs.top+=40; 
 rs.bottom-=2; 
 rs.left+=20; 
 rs.right+=10;

 m_para1.MoveWindow(&rs);
 m_para2.MoveWindow(&rs);
 m_para3.MoveWindow(&rs);
 m_para4.MoveWindow(&rs);
 m_para5.MoveWindow(&rs);
 m_para6.MoveWindow(&rs);
 m_paraDesfire.MoveWindow(&rs);
 m_paraPinPad.MoveWindow(&rs);
 m_paraEmv.MoveWindow(&rs);

m_para1.ShowWindow(true);
m_para2.ShowWindow(false);
m_para3.ShowWindow(false);
m_para4.ShowWindow(false);
m_para5.ShowWindow(false);
m_para6.ShowWindow(false);
m_paraDesfire.ShowWindow(false);
m_paraPinPad.ShowWindow(false);
m_paraEmv.ShowWindow(false);

//默认选项卡
m_tabMain.SetCurSel(0);



	CButton* radio=(CButton*)GetDlgItem(IDC_RADIO1);
	radio->SetCheck(1);
	Boudary=115200;			//默认波特率


	radio1=(CButton*)GetDlgItem(IDC_RADIO3);
	radio1->SetCheck(1);
	PortNum=201;			//默认USB通信

	SetDlgItemText(IDC_EDIT1,_T("1"));

	PortNum=201;

	OnButton2();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CM160Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CM160Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CM160Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

extern int MSR_INIT_FLAG;
void CM160Dlg::OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult) 
{

	if(MSR_Statue==0 && MSR_INIT_FLAG==0)	
	{
		MessageBox(_T("please click 'Connect'...","unconnect:") );
		m_tabMain.SetCurSel(0);
		return;
	}
/*
	if(MSR_Statue==0 && MSR_INIT_FLAG==1)	
	{
		MessageBox("该设备只支持磁条卡操作...","提示:" );
		m_tabMain.SetCurSel(0);
		return;
	}
*/
	BoolMagCard=0;
	ZCS80ReadPro_flag=0;
	ZCS80WritePro_flag=0;
//	GetDlgItem(IDOK2)->EnableWindow(1);
//	GetDlgItem(IDOK3)->EnableWindow(1);

	// TODO: Add your control notification handler code here
	int CurSel = m_tabMain.GetCurSel();
	m_para1.ShowWindow(false);
	m_para2.ShowWindow(false);
	m_para3.ShowWindow(false);
	m_para4.ShowWindow(false);
	m_para5.ShowWindow(false);
	m_para6.ShowWindow(false);
	m_paraDesfire.ShowWindow(false);
	m_paraPinPad.ShowWindow(false);
	m_paraEmv.ShowWindow(false);
	switch(CurSel)
	{
		case 0:
		m_para1.ShowWindow(true); break; 

		case 1:
		m_para2.ShowWindow(true); break;

		case 2:
		m_para3.ShowWindow(true); break;

		case 3:
		m_para4.ShowWindow(true); break;

		case 4:
		m_para5.ShowWindow(true); break;

		case 5:
		m_paraDesfire.ShowWindow(true); break;

		case 6:
		m_paraPinPad.ShowWindow(true); break;
		case 7:
		m_paraEmv.ReadEmvFile();   
		m_paraEmv.ShowWindow(true);
		break;
		default:
		break;
	}
//	*pResult = 0;
}
extern int MSR_INIT_FLAG;
extern unsigned char _stdcall openSer(int port);
void CM160Dlg::OnButton1() 
{
	int mark=3;
	CString strValue;
	unsigned char sn[50];

	if(radio1->GetCheck()==0)		//GetCheck
	{
		PortNum = GetDlgItemInt(IDC_EDIT1);
		if(PortNum>200)
		{
			strValue.Format("%d", PortNum);
			MessageBox(_T("COM ")+strValue+_T(""),_T("error:"));
		}
	}
	else
		PortNum=201;


//	if(MessageBox("你确定要初始化吗？","提示:",MB_OKCANCEL|MB_ICONQUESTION )==1)
	mark=InitDev((unsigned char)PortNum,Boudary);
	int mark1;

	ZCS80WritePro_flag=0;
	ZCS80ReadPro_flag=0;

//	INFOBOX1->SetWindowText("...");
	Sleep(5);
/*
	if(PortNum>200)   //   usb  ***************
	{
			mark1 = openSer(201);
			if( mark1!=0 || mark1==22)
			{
			//	INFOBOX1->SetWindowText("U口初始化失败...");
				MSR_INIT_FLAG = 0;
				return;
			}
			else
			{
				mark1 = MSR_Init();
				if(mark1<0 || mark1 == 255 || mark1 == 254) 
				{
				//	INFOBOX1->SetWindowText("初始化失败...");
					MSR_INIT_FLAG = 0;
					return;
				}
				else
				{
				//	INFOBOX1->SetWindowText("初始化成功...");
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
		//	INFOBOX1->SetWindowText("初始化失败...");
			return;
		}
		else
		{
		//	INFOBOX1->SetWindowText("初始化成功...");
			MSR_INIT_FLAG = 1;
		}
	}

	if(MSR_INIT_FLAG==1)
	{
		MSR_Set_HiCo();
		int ret = MSR_DoCancel();		//复位
	//	TK1Dat[0]='1';
	//	TK2Dat[0]='1';
	//	TK3Dat[0]='1';
	//	int nRet=MSR_Write_SPEC(TK1Dat,TK2Dat,TK3Dat,parity1,parity2,parity3,tr1bit,tr2bit,tr3bit,SS1,ES1,SS2,ES2,SS3,ES3);			

	//	 nRet=MSR_Write_status();
//		GetDlgItem(IDOK4)->EnableWindow(0);
	}

*/



	if(mark==0  )
	{
		memset(sn,0,sizeof(sn));
		ReadSN(sn);
		strValue=sn;
		GetDlgItem(IDC_STATIC1)->SetWindowText("succeed...\n"+strValue);
		MSR_Statue=1;
	}
	else
	{
		GetDlgItem(IDC_STATIC1)->SetWindowText(_T("failed..."));
		return;
	}




	
}








void ZCS80_hThreadInit80auto(LPVOID lpParam)
{




	int mark1=22;

	ZCS80WritePro_flag=0;
	ZCS80ReadPro_flag=0;

//	INFOBOX1->SetWindowText("...");
//	Sleep(5);

	if(PortNum>200)   //   usb  ***************
	{
		//	mark1 = openSer(201);
		//	if( mark1!=0 || mark1==22)
		//	{
			//	INFOBOX1->SetWindowText("U口初始化失败...");
		//		MSR_INIT_FLAG = 0;
		//		return;
		//	}
			
			
				mark1 = MSR_Init();
				if(mark1<0 || mark1 == 255 || mark1 == 254) 
				{
				//	INFOBOX1->SetWindowText("初始化失败...");
					MSR_INIT_FLAG = 0;
					return;
				}
				else if(mark1==0x1b)
				{
				//	INFOBOX1->SetWindowText("初始化成功...");
					MSR_INIT_FLAG = 1;
									
				}
				else
					MSR_INIT_FLAG = 0;
			
	
	}
	//   串口  ***************
	else
	{
		mark1 = MSR_Init();
		InitDev((unsigned char)PortNum,Boudary);
	
		if(mark1 < 0)
		{
			MSR_INIT_FLAG = 0;
		//	INFOBOX1->SetWindowText("初始化失败...");
		//	return;
		}
		else
		{
	//	INFOBOX1->SetWindowText("初始化成功...");
			MSR_INIT_FLAG = 1;
		}
	
	}
	if(MSR_INIT_FLAG==1)
	{
		MSR_Set_HiCo();
		int ret = MSR_DoCancel();		//复位
		if(MSR_Statue!=1)
			((CWnd*)lpParam)->SetDlgItemText(IDC_STATIC1,_T("Connect succeed..."));


	//	 M160Read->ShowWindow(0);
	//	 M160Stop->ShowWindow(0);
	//	 M80Read->ShowWindow(1);
	//	 M80Write->ShowWindow(1);

	}
	else if(MSR_Statue==0)
		((CWnd*)lpParam)->SetDlgItemText(IDC_STATIC1,_T("failed..."));


	 //    M160Read->ShowWindow(1);
	//	 M160Stop->ShowWindow(1);
	//	 M80Read->ShowWindow(0);
	//	 M80Write->ShowWindow(0);
}



void CM160Dlg::OnButton2() 
{
//	CDialog::OnCancel();	
	int mark=3,i,ret;
	CString strValue;
	unsigned char sn[50];


	GetDlgItem(IDC_STATIC1)->SetWindowText(_T(" "));
	
//*********************USB************************
	PortNum=201;
	mark=InitDev((unsigned char)PortNum,Boudary);

//********************串口 ************************
	if(mark!=0)
	{
		for(PortNum=1;PortNum<50;PortNum++)
		{
			ret=openSer(PortNum);
			if(ret!=0) continue;

			mark = InitDev((unsigned char)PortNum,Boudary);
			if(mark==0)
				break;

		}
		

	}
	





	if(mark==0  )
	{
		 MSR_Statue=1;
		memset(sn,0,sizeof(sn));
		ReadSN(sn);
		strValue=sn;
		GetDlgItem(IDC_STATIC1)->SetWindowText("Succeed...\n"+strValue);
		
	}
	else
	{
		PortNum=0;
		MSR_Statue=0;
		GetDlgItem(IDC_STATIC1)->SetWindowText("Connect failed...");
	//	return;
	}

	////HANDLE hThreadInit80auto;
	////hThreadInit80auto=CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)ZCS80_hThreadInit80auto,this,0,NULL);
	////CloseHandle(hThreadInit80auto);	
//////	Sleep(700);
}

void CM160Dlg::OnButton3() 
{
	int k=sizeof( int);
	CString strValue;
	strValue.Format("%d", k);
//	MessageBox(strValue);
	CDialog::OnCancel();
}

void CM160Dlg::OnRadio1() 
{
	// TODO: Add your control notification handler code here
	Boudary=115200;
}

void CM160Dlg::OnRadio2() 
{
	Boudary=9600;	
}

void CM160Dlg::OnRadio3() 
{
	PortNum=201;	
}

void CM160Dlg::OnRadio4() 
{
	// TODO: Add your control notification handler code here
	 PortNum = GetDlgItemInt(IDC_EDIT1);
}

void CM160Dlg::OnChangeEdit1() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
		 PortNum = GetDlgItemInt(IDC_EDIT1);
}
