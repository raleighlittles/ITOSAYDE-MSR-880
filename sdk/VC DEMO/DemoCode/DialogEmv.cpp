// DialogEmv.cpp : 实现文件
//

#include "stdafx.h"
#include "m160.h"
#include "DialogEmv.h"
#include "afxdialogex.h"
#include "DemoFiles.h"

#include "160.h"
// DialogEmv 对话框

IMPLEMENT_DYNAMIC(DialogEmv, CDialog)

DialogEmv::DialogEmv(CWnd* pParent /*=NULL*/)
	: CDialog(DialogEmv::IDD, pParent)
{

	EnableAutomation();

}

DialogEmv::~DialogEmv()
{
}

void DialogEmv::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。基类将自动
	// 删除该对象。在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CDialog::OnFinalRelease();
}

void DialogEmv::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DialogEmv, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &DialogEmv::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &DialogEmv::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &DialogEmv::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &DialogEmv::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_CHECK1, &DialogEmv::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_BUTTON7, &DialogEmv::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &DialogEmv::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON11, &DialogEmv::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &DialogEmv::OnBnClickedButton12)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(DialogEmv, CDialog)
END_DISPATCH_MAP()

// 注意: 我们添加 IID_IDialogEmv 支持
//  以支持来自 VBA 的类型安全绑定。此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {0617CF37-D7A7-4D7F-B7C7-BD6D837499E4}
static const IID IID_IDialogEmv =
{ 0x617CF37, 0xD7A7, 0x4D7F, { 0xB7, 0xC7, 0xBD, 0x6D, 0x83, 0x74, 0x99, 0xE4 } };

BEGIN_INTERFACE_MAP(DialogEmv, CDialog)
	INTERFACE_PART(DialogEmv, IID_IDialogEmv, Dispatch)
END_INTERFACE_MAP()

CEdit *INFOBOX_EMV;

// DialogEmv 消息处理程序
BOOL DialogEmv::OnInitDialog() 
{
	CDialog::OnInitDialog();


	//关联对话框,并且将IDC_TABMAIN控件设为父窗口
   m_paraEmvPara.Create(IDD_DIALOGEMVPARA,GetDlgItem(IDD_DIALOGEMV));  //IDD_DIALOGEMV  IDD_M160_DIALOG
  // m_para2.Create(IDD_DIALOG2,GetDlgItem(IDD_DIALOGEMV));
   GetDlgItem(IDC_EDIT1)->SetWindowText(_T("0"));
   GetDlgItem(IDC_EDIT2)->SetWindowText(_T("123"));

   INFOBOX_EMV=(CEdit*)GetDlgItem(IDC_EDIT3);
   INFOBOX_EMV->SetLimitText(UINT_MAX); //设置显示最大字符数

    m_paraEmvCapk.Create(IDD_DIALOGEMVCAPK,GetDlgItem(IDD_DIALOGEMV));

   EmvCoreCbInit();

   unsigned char TerCapabuf[3];
   memcpy(TerCapabuf,EmvCoreGetTermParam()->ucTermCapa,3);
   if(TerCapabuf[0]&0x80)
   	 ((CButton*)GetDlgItem(IDC_CHECK2))->SetCheck(TRUE);
   if(TerCapabuf[0]&0x40)
	((CButton*)GetDlgItem(IDC_CHECK3))->SetCheck(TRUE);
   if(TerCapabuf[0]&0x20)
	((CButton*)GetDlgItem(IDC_CHECK4))->SetCheck(TRUE);

   if(TerCapabuf[1]&0x80) 
	 ((CButton*)GetDlgItem(IDC_CHECK5))->SetCheck(TRUE);
   if(TerCapabuf[1]&0x40) 
	 ((CButton*)GetDlgItem(IDC_CHECK6))->SetCheck(TRUE);
   if(TerCapabuf[1]&0x20) 
	 ((CButton*)GetDlgItem(IDC_CHECK7))->SetCheck(TRUE);
   if(TerCapabuf[1]&0x10) 
	 ((CButton*)GetDlgItem(IDC_CHECK8))->SetCheck(TRUE);
   if(TerCapabuf[1]&0x08) 
	 ((CButton*)GetDlgItem(IDC_CHECK9))->SetCheck(TRUE);

   if(TerCapabuf[2]&0x80) 
	((CButton*)GetDlgItem(IDC_CHECK10))->SetCheck(TRUE);
   if(TerCapabuf[2]&0x40) 
	((CButton*)GetDlgItem(IDC_CHECK11))->SetCheck(TRUE);
   if(TerCapabuf[2]&0x20) 
	((CButton*)GetDlgItem(IDC_CHECK12))->SetCheck(TRUE);
   if(TerCapabuf[2]&0x08)  
	((CButton*)GetDlgItem(IDC_CHECK13))->SetCheck(TRUE);

   int i;
   CString str,OutStr;
   for(i=0;i<3;i++)
	{
		str.Format("%02x",TerCapabuf[i]);
		OutStr += str;
	}
	GetDlgItem(IDC_EDIT4)->SetWindowText(OutStr);


	str.Format("%s",EmvCoreGetTermParam()->ucMerchantNameLocation);
	GetDlgItem(IDC_EDIT7)->SetWindowText(str);

	OutStr = "";
	for(i=0;i<2;i++)
	{
		str.Format("%02x",EmvCoreGetTermParam()->ucTerminalCountry[i]);
		OutStr += str;
	}
	GetDlgItem(IDC_EDIT8)->SetWindowText(OutStr);

	OutStr = "";
	for(i=0;i<2;i++)
	{
		str.Format("%02x",EmvCoreGetTermParam()->ucTranCurrCode[i]);
		OutStr += str;
	}
	GetDlgItem(IDC_EDIT10)->SetWindowText(OutStr);

	str.Format("%02x",EmvCoreGetTermParam()->ucTermType);
	GetDlgItem(IDC_EDIT9)->SetWindowText(str);


	//trans setting
	if(EmvCoreGetTransParam()->ucIsForceOnline) 
	((CButton*)GetDlgItem(IDC_CHECK14))->SetCheck(TRUE);
	if(EmvCoreGetTransParam()->ucIsSimpleFlow) 
	((CButton*)GetDlgItem(IDC_CHECK15))->SetCheck(TRUE);

	str.Format("%02x",EmvCoreGetTransParam()->ucTransType);
	GetDlgItem(IDC_EDIT12)->SetWindowText(str);
	OutStr = "";
	for(i=0;i<4;i++)
	{
		str.Format("%02x",EmvCoreGetTransParam()->ucReaderTTQ[i]);
		OutStr += str;
	}
	GetDlgItem(IDC_EDIT13)->SetWindowText(OutStr);
	OutStr = "";
	for(i=0;i<4;i++)
	{
		str.Format("%02x",EmvCoreGetTransParam()->ucTransNo[i]);
		OutStr += str;
	}
	GetDlgItem(IDC_EDIT14)->SetWindowText(OutStr);

   return TRUE; 
}
unsigned int gAidFileLen,gCapkFileLen;
unsigned char gAidFileData[1024*128];
unsigned char gCapkFileData[512*128];
void DialogEmv::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	m_paraEmvPara.CenterWindow();
	m_paraEmvPara.ShowWindow(true);

	m_paraEmvPara.DisplayAID();
		
}
void two2one(unsigned char *in,int in_len,unsigned char *out)
{
	unsigned char tmpc;
	int i;

	for(i=0;i<in_len;i+=2){
		tmpc=in[i];
		tmpc=toupper(tmpc);
		if((tmpc<'0'||tmpc>'9') && (tmpc<'A'||tmpc>'F'))tmpc='F';
		if(tmpc>'9')
			tmpc=toupper(tmpc)-'A'+0x0A;
		else
	 		tmpc-='0';
		tmpc<<=4;
		out[i/2]=tmpc;

		tmpc=in[i+1];
		tmpc=toupper(tmpc);
		if((tmpc<'0'||tmpc>'9') && (tmpc<'A'||tmpc>'F'))tmpc='F';
		if(tmpc>'9')
			 tmpc=toupper(tmpc)-'A'+0x0A;
	 	else
			 tmpc-='0';

		out[i/2]|=tmpc;
	}
}
void DialogEmv::ReadEmvFile(void)
{
	T_EMV_TERM_CAPK AddCapk;
    T_EMV_APP_LIST AddAid;
	int ret,i;

	gAidFileLen =0;
	ret = FileGetSize((unsigned char*)AID_NAME);
	if(ret<0){
		
		memset(&AddAid,0,sizeof(AddAid));
	    memcpy(AddAid.ucAID,"\xA0\x00\x00\x00\x04\x10\x10", 7);
		AddAid.ucAIDLen = 7;
		memcpy(AddAid.ucTermAVM, "\x00\x02", 2);
		memcpy(AddAid.ucDdol, "\x9F\x37\x04", 3);
		AddAid.ucDdolLen = 3;
		memcpy(AddAid.ucTdol,"\x9F\x02\x06\x5F\x2A\x02\x9A\x03\x9C\x01\x95\x05\x9F\x37\x04", 15);
		AddAid.ucTdolLen = 15;
		memcpy(AddAid.ucTACDefault, "\x00\x20\x00\x00\x00", 5);
		memcpy(AddAid.ucTACOnline, "\x00\x20\x00\x00\x00", 5);
		memcpy(AddAid.ucTACDenial, "\x00\x20\x00\x00\x00", 5);
		AddAid.ucSelectIndicator = 0;
		AddAid.ucOnLinePINFlag = 1;
		memcpy(AddAid.ucTermFloor, "\x00\x01\x50\x00", 4);   //15000
		memcpy(AddAid.ucECTranLmt, "\x00\x00\x00\x02\x50\x00", 6);   //25000
		memcpy(AddAid.ucRFFLmt, "\x00\x00\x00\x01\x00\x00", 6);   //10000
		memcpy(AddAid.ucRFTxnLmt, "\x00\x00\x00\x01\x00\x00", 6);   //10000
		memcpy(AddAid.ucRFCVMLmt, "\x00\x00\x00\x00\x20\x00", 6);   //2000
		AddAid.ucTargetPercentage = 0x99;
		AddAid.ucMaxTargetPercentage = 0x99;
		AddAid.uiThresholdValue = 0;

		AddAid.ucPayPassTermType = 0x22;//
		memcpy(AddAid.TermCapNoCVMReq, "\xA0\x08\x88", 3);   
		memcpy(AddAid.TermCapCVMReq, "\xA0\x60\x88", 3);   
		memcpy(AddAid.ucUdol,"\x9F\x6A\x04", 3);   
		AddAid.ucUdolLen = 3;

		AddAid.unCrc = 0x5678;   
		ret=FileWrite((unsigned char*)AID_NAME,(unsigned char*)&AddAid,sizeof(AddAid));
        if(ret!=0) return;

	    memcpy(AddAid.ucAID,"\xA0\x00\x00\x00\x04\x20\x10", 7);
		AddAid.ucAIDLen = 7;
		ret = FileAppend((unsigned char*)AID_NAME,(unsigned char*)&AddAid,sizeof(AddAid));
		if(ret!=0) return;

		memcpy(AddAid.ucAID,"\xA0\x00\x00\x03\x33\x01\x01", 7);
		AddAid.ucAIDLen = 7;
		ret = FileAppend((unsigned char*)AID_NAME,(unsigned char*)&AddAid,sizeof(AddAid));
		if(ret!=0) return;

		memcpy(AddAid.ucAID,"\xA0\x00\x00\x03\x33\x01\x01\x02", 8);
		AddAid.ucAIDLen = 8;
		ret = FileAppend((unsigned char*)AID_NAME,(unsigned char*)&AddAid,sizeof(AddAid));
		if(ret!=0) return;

		memcpy(AddAid.ucAID,"\xA0\x00\x00\x03\x33\x01\x01\x01", 8);
		AddAid.ucAIDLen = 8;
		ret = FileAppend((unsigned char*)AID_NAME,(unsigned char*)&AddAid,sizeof(AddAid));
		if(ret!=0) return;
		//VSDC
		memcpy(AddAid.ucAID,"\xA0\x00\x00\x00\x03\x10\x10", 7);
		AddAid.ucAIDLen = 7;
		ret = FileAppend((unsigned char*)AID_NAME,(unsigned char*)&AddAid,sizeof(AddAid));
		if(ret!=0) return;
		//VISA  Electron
		memcpy(AddAid.ucAID,"\xA0\x00\x00\x00\x03\x20\x10", 7);
		AddAid.ucAIDLen = 7;
		ret = FileAppend((unsigned char*)AID_NAME,(unsigned char*)&AddAid,sizeof(AddAid));
		if(ret!=0) return;
		//JCB
		memcpy(AddAid.ucAID,"\xA0\x00\x00\x00\x65\x10\x10", 7);
		AddAid.ucAIDLen = 7;
		ret = FileAppend((unsigned char*)AID_NAME,(unsigned char*)&AddAid,sizeof(AddAid));
		if(ret!=0) return;
	    
		ret = FileGetSize((unsigned char*)AID_NAME);
	}
	gAidFileLen = ret;
	if(gAidFileLen>sizeof(gAidFileData)) gAidFileLen= sizeof(gAidFileData);
	ret=FileRead((unsigned char*)AID_NAME,gAidFileData,0,&gAidFileLen);
	if(ret!=0) return;
	EmvClearAIDList();
	for(i=0;i<gAidFileLen;i+=sizeof(AddAid)){
	  memset(&AddAid,0,sizeof(AddAid));
	  memcpy(&AddAid,&gAidFileData[i],sizeof(AddAid));
	  EmvAddAIDList(&AddAid);
	}


	gCapkFileLen =0;
	ret = FileGetSize((unsigned char*)CAPK_NAME);
	if(ret<0){
		
		memset(&AddCapk,0,sizeof(AddCapk));
	    memcpy(AddCapk.ucRID,"\xA0\x00\x00\x03\x33", 5);
	    AddCapk.ucIndex = 0x01;
	    memcpy(AddCapk.ucExpDate,"\x35\x12\x31", 3);
	    AddCapk.ucHashIndicator = 1;
	    AddCapk.ucCAPKIndicator = 1;
	    memcpy(AddCapk.ucModulus,
		"\xBB\xE9\x06\x6D\x25\x17\x51\x1D\x23\x9C\x7B\xFA\x77\x88\x41\x44\xAE\x20\xC7\x37\x2F\x51\x51\x47\xE8\xCE\x65\x37\xC5\x4C\x0A\x6A\x4D\x45\xF8\xCA\x4D\x29\x08\x70\xCD\xA5\x9F\x13\x44\xEF\x71\xD1\x7D\x3F\x35\xD9\x2F\x3F\x06\x77\x8D\x0D\x51\x1E\xC2\xA7\xDC\x4F\xFE\xAD\xF4\xFB\x12\x53\xCE\x37\xA7\xB2\xB5\xA3\x74\x12\x27\xBE\xF7\x25\x24\xDA\x7A\x2B\x7B\x1C\xB4\x26\xBE\xE2\x7B\xC5\x13\xB0\xCB\x11\xAB\x99\xBC\x1B\xC6\x1D\xF5\xAC\x6C\xC4\xD8\x31\xD0\x84\x87\x88\xCD\x74\xF6\xD5\x43\xAD\x37\xC5\xA2\xB4\xC5\xD5\xA9\x3B",
		128);
	   AddCapk.ucModulusLen = 128;
	   memcpy(AddCapk.ucExponent,"\x03", 1);
	   AddCapk.ucExponentLen = 1;
	   memcpy(AddCapk.ucCheckSum,"\xE8\x81\xE3\x90\x67\x5D\x44\xC2\xDD\x81\x23\x4D\xCE\x29\xC3\xF5\xAB\x22\x97\xA0", 20);
	   ret=FileWrite((unsigned char*)CAPK_NAME,(unsigned char*)&AddCapk,sizeof(AddCapk));
       if(ret!=0) return;

	   //PBOC LK02
		memcpy(AddCapk.ucRID,"\xA0\x00\x00\x03\x33", 5);
		AddCapk.ucIndex = 0x02;
		memcpy(AddCapk.ucExpDate,"\x35\x12\x31", 3);
		AddCapk.ucHashIndicator = 1;
		AddCapk.ucCAPKIndicator = 1;
		memcpy(AddCapk.ucModulus,
			"\xA3\x76\x7A\xBD\x1B\x6A\xA6\x9D\x7F\x3F\xBF\x28\xC0\x92\xDE\x9E\xD1\xE6\x58\xBA\x5F\x09\x09\xAF\x7A\x1C\xCD\x90\x73\x73\xB7\x21\x0F\xDE\xB1\x62\x87\xBA\x8E\x78\xE1\x52\x9F\x44\x39\x76\xFD\x27\xF9\x91\xEC\x67\xD9\x5E\x5F\x4E\x96\xB1\x27\xCA\xB2\x39\x6A\x94\xD6\xE4\x5C\xDA\x44\xCA\x4C\x48\x67\x57\x0D\x6B\x07\x54\x2F\x8D\x4B\xF9\xFF\x97\x97\x5D\xB9\x89\x15\x15\xE6\x6F\x52\x5D\x2B\x3C\xBE\xB6\xD6\x62\xBF\xB6\xC3\xF3\x38\xE9\x3B\x02\x14\x2B\xFC\x44\x17\x3A\x37\x64\xC5\x6A\xAD\xD2\x02\x07\x5B\x26\xDC\x2F\x9F\x7D\x7A\xE7\x4B\xD7\xD0\x0F\xD0\x5E\xE4\x30\x03\x26\x63\xD2\x7A\x57",
			144);
		AddCapk.ucModulusLen = 144;
		memcpy(AddCapk.ucExponent,"\x03", 1);
		AddCapk.ucExponentLen = 1;
		memcpy(AddCapk.ucCheckSum,"\x03\xBB\x33\x5A\x85\x49\xA0\x3B\x87\xAB\x08\x9D\x00\x6F\x60\x85\x2E\x4B\x80\x60", 20);
		ret = FileAppend((unsigned char*)CAPK_NAME,(unsigned char*)&AddCapk,sizeof(AddCapk));
		if(ret!=0) return;

		//PBOC LK03
		memcpy(AddCapk.ucRID,"\xA0\x00\x00\x03\x33", 5);
		AddCapk.ucIndex = 0x03;
		memcpy(AddCapk.ucExpDate,"\x35\x12\x31", 3);
		AddCapk.ucHashIndicator = 1;
		AddCapk.ucCAPKIndicator = 1;
		memcpy(AddCapk.ucModulus,
			"\xB0\x62\x7D\xEE\x87\x86\x4F\x9C\x18\xC1\x3B\x9A\x1F\x02\x54\x48\xBF\x13\xC5\x83\x80\xC9\x1F\x4C\xEB\xA9\xF9\xBC\xB2\x14\xFF\x84\x14\xE9\xB5\x9D\x6A\xBA\x10\xF9\x41\xC7\x33\x17\x68\xF4\x7B\x21\x27\x90\x7D\x85\x7F\xA3\x9A\xAF\x8C\xE0\x20\x45\xDD\x01\x61\x9D\x68\x9E\xE7\x31\xC5\x51\x15\x9B\xE7\xEB\x2D\x51\xA3\x72\xFF\x56\xB5\x56\xE5\xCB\x2F\xDE\x36\xE2\x30\x73\xA4\x4C\xA2\x15\xD6\xC2\x6C\xA6\x88\x47\xB3\x88\xE3\x95\x20\xE0\x02\x6E\x62\x29\x4B\x55\x7D\x64\x70\x44\x0C\xA0\xAE\xFC\x94\x38\xC9\x23\xAE\xC9\xB2\x09\x8D\x6D\x3A\x1A\xF5\xE8\xB1\xDE\x36\xF4\xB5\x30\x40\x10\x9D\x89\xB7\x7C\xAF\xAF\x70\xC2\x6C\x60\x1A\xBD\xF5\x9E\xEC\x0F\xDC\x8A\x99\x08\x91\x40\xCD\x2E\x81\x7E\x33\x51\x75\xB0\x3B\x7A\xA3\x3D",
			176);
		AddCapk.ucModulusLen = 176;
		memcpy(AddCapk.ucExponent,"\x03", 1);
		AddCapk.ucExponentLen = 1;
		memcpy(AddCapk.ucCheckSum,"\x87\xF0\xCD\x7C\x0E\x86\xF3\x8F\x89\xA6\x6F\x8C\x47\x07\x1A\x8B\x88\x58\x6F\x26", 20);
		ret = FileAppend((unsigned char*)CAPK_NAME,(unsigned char*)&AddCapk,sizeof(AddCapk));
		if(ret!=0) return;
		//PBOC LK04
		memcpy(AddCapk.ucRID,"\xA0\x00\x00\x03\x33", 5);
		AddCapk.ucIndex = 0x04;
		memcpy(AddCapk.ucExpDate,"\x35\x12\x31", 3);
		AddCapk.ucHashIndicator = 1;
		AddCapk.ucCAPKIndicator = 1;
		memcpy(AddCapk.ucModulus,
			"\xBC\x85\x3E\x6B\x53\x65\xE8\x9E\x7E\xE9\x31\x7C\x94\xB0\x2D\x0A\xBB\x0D\xBD\x91\xC0\x5A\x22\x4A\x25\x54\xAA\x29\xED\x9F\xCB\x9D\x86\xEB\x9C\xCB\xB3\x22\xA5\x78\x11\xF8\x61\x88\xAA\xC7\x35\x1C\x72\xBD\x9E\xF1\x96\xC5\xA0\x1A\xCE\xF7\xA4\xEB\x0D\x2A\xD6\x3D\x9E\x6A\xC2\xE7\x83\x65\x47\xCB\x15\x95\xC6\x8B\xCB\xAF\xD0\xF6\x72\x87\x60\xF3\xA7\xCA\x7B\x97\x30\x1B\x7E\x02\x20\x18\x4E\xFC\x4F\x65\x30\x08\xD9\x3C\xE0\x98\xC0\xD9\x3B\x45\x20\x10\x96\xD1\xAD\xFF\x4C\xF1\xF9\xFC\x02\xAF\x75\x9D\xA2\x7C\xD6\xDF\xD6\xD7\x89\xB0\x99\xF1\x6F\x37\x8B\x61\x00\x33\x4E\x63\xF3\xD3\x5F\x32\x51\xA5\xEC\x78\x69\x37\x31\xF5\x23\x35\x19\xCD\xB3\x80\xF5\xAB\x8C\x0F\x02\x72\x8E\x91\xD4\x69\xAB\xD0\xEA\xE0\xD9\x3B\x1C\xC6\x6C\xE1\x27\xB2\x9C\x7D\x77\x44\x1A\x49\xD0\x9F\xCA\x5D\x6D\x97\x62\xFC\x74\xC3\x1B\xB5\x06\xC8\xBA\xE3\xC7\x9A\xD6\xC2\x57\x87\x75\xB9\x59\x56\xB5\x37\x0D\x1D\x05\x19\xE3\x79\x06\xB3\x84\x73\x62\x33\x25\x1E\x8F\x09\xAD\x79\xDF\xBE\x2C\x6A\xBF\xAD\xAC\x8E\x4D\x86\x24\x31\x8C\x27\xDA\xF1",
			248);
		AddCapk.ucModulusLen = 248;
		memcpy(AddCapk.ucExponent,"\x03", 1);
		AddCapk.ucExponentLen = 1;
		memcpy(AddCapk.ucCheckSum,"\xF5\x27\x08\x1C\xF3\x71\xDD\x7E\x1F\xD4\xFA\x41\x4A\x66\x50\x36\xE0\xF5\xE6\xE5", 20);
		ret = FileAppend((unsigned char*)CAPK_NAME,(unsigned char*)&AddCapk,sizeof(AddCapk));
		if(ret!=0) return;

		  //Master  04
		memcpy(AddCapk.ucRID,"\xA0\x00\x00\x00\x04", 5);
		AddCapk.ucIndex = 0x04;
		memcpy(AddCapk.ucExpDate,"\x35\x12\x31", 3);
		AddCapk.ucHashIndicator = 1;
		AddCapk.ucCAPKIndicator = 1;
		AddCapk.ucModulusLen = 144;
		two2one((unsigned char*)"A6DA428387A502D7DDFB7A74D3F412BE762627197B25435B7A81716A700157DDD06F7CC99D6CA28C2470527E2C03616B9C59217357C2674F583B3BA5C7DCF2838692D023E3562420B4615C439CA97C44DC9A249CFCE7B3BFB22F68228C3AF13329AA4A613CF8DD853502373D62E49AB256D2BC17120E54AEDCED6D96A4287ACC5C04677D4A5A320DB8BEE2F775E5FEC5"
			   ,AddCapk.ucModulusLen*2,AddCapk.ucModulus);
		memcpy(AddCapk.ucExponent,"\x03", 1);
		AddCapk.ucExponentLen = 1;
		two2one((unsigned char*)"BD331F9996A490B33C13441066A09AD3FEB5F66C",20*2,AddCapk.ucCheckSum);
		ret = FileAppend((unsigned char*)CAPK_NAME,(unsigned char*)&AddCapk,sizeof(AddCapk));
		if(ret!=0) return;
	   //Master  05
		memcpy(AddCapk.ucRID,"\xA0\x00\x00\x00\x04", 5);
		AddCapk.ucIndex = 0x05;
		memcpy(AddCapk.ucExpDate,"\x35\x12\x31", 3);
		AddCapk.ucHashIndicator = 1;
		AddCapk.ucCAPKIndicator = 1;
		memcpy(AddCapk.ucModulus,
			"\xB8\x04\x8A\xBC\x30\xC9\x0D\x97\x63\x36\x54\x3E\x3F\xD7\x09\x1C\x8F\xE4\x80\x0D\xF8\x20\xED\x55\xE7\xE9\x48\x13\xED\x00\x55\x5B\x57\x3F\xEC\xA3\xD8\x4A\xF6\x13\x1A\x65\x1D\x66\xCF\xF4\x28\x4F\xB1\x3B\x63\x5E\xDD\x0E\xE4\x01\x76\xD8\xBF\x04\xB7\xFD\x1C\x7B\xAC\xF9\xAC\x73\x27\xDF\xAA\x8A\xA7\x2D\x10\xDB\x3B\x8E\x70\xB2\xDD\xD8\x11\xCB\x41\x96\x52\x5E\xA3\x86\xAC\xC3\x3C\x0D\x9D\x45\x75\x91\x64\x69\xC4\xE4\xF5\x3E\x8E\x1C\x91\x2C\xC6\x18\xCB\x22\xDD\xE7\xC3\x56\x8E\x90\x02\x2E\x6B\xBA\x77\x02\x02\xE4\x52\x2A\x2D\xD6\x23\xD1\x80\xE2\x15\xBD\x1D\x15\x07\xFE\x3D\xC9\x0C\xA3\x10\xD2\x7B\x3E\xFC\xCD\x8F\x83\xDE\x30\x52\xCA\xD1\xE4\x89\x38\xC6\x8D\x09\x5A\xAC\x91\xB5\xF3\x7E\x28\xBB\x49\xEC\x7E\xD5\x97"
			 ,176);
		AddCapk.ucModulusLen = 176;
		memcpy(AddCapk.ucExponent,"\x03", 1);
		AddCapk.ucExponentLen = 1;
		memcpy(AddCapk.ucCheckSum,"\xEB\xFA\x0D\x5D\x06\xD8\xCE\x70\x2D\xA3\xEA\xE8\x90\x70\x1D\x45\xE2\x74\xC8\x45", 20);
		ret = FileAppend((unsigned char*)CAPK_NAME,(unsigned char*)&AddCapk,sizeof(AddCapk));
		if(ret!=0) return;
		 //Master  06
		memcpy(AddCapk.ucRID,"\xA0\x00\x00\x00\x04", 5);
		AddCapk.ucIndex = 0x06;
		memcpy(AddCapk.ucExpDate,"\x35\x12\x31", 3);
		AddCapk.ucHashIndicator = 1;
		AddCapk.ucCAPKIndicator = 1;
		AddCapk.ucModulusLen = 248;
		two2one((unsigned char*)"CB26FC830B43785B2BCE37C81ED334622F9622F4C89AAE641046B2353433883F307FB7C974162DA72F7A4EC75D9D657336865B8D3023D3D645667625C9A07A6B7A137CF0C64198AE38FC238006FB2603F41F4F3BB9DA1347270F2F5D8C606E420958C5F7D50A71DE30142F70DE468889B5E3A08695B938A50FC980393A9CBCE44AD2D64F630BB33AD3F5F5FD495D31F37818C1D94071342E07F1BEC2194F6035BA5DED3936500EB82DFDA6E8AFB655B1EF3D0D7EBF86B66DD9F29F6B1D324FE8B26CE38AB2013DD13F611E7A594D675C4432350EA244CC34F3873CBA06592987A1D7E852ADC22EF5A2EE28132031E48F74037E3B34AB747F"
			   ,AddCapk.ucModulusLen*2,AddCapk.ucModulus);
		memcpy(AddCapk.ucExponent,"\x03", 1);
		AddCapk.ucExponentLen = 1;
		two2one((unsigned char*)"F910A1504D5FFB793D94F3B500765E1ABCAD72D9",20*2,AddCapk.ucCheckSum);
		ret = FileAppend((unsigned char*)CAPK_NAME,(unsigned char*)&AddCapk,sizeof(AddCapk));
		if(ret!=0) return;

		//VISA  07
		memcpy(AddCapk.ucRID,"\xA0\x00\x00\x00\x03", 5);
		AddCapk.ucIndex = 0x07;
		memcpy(AddCapk.ucExpDate,"\x35\x12\x31", 3);
		AddCapk.ucHashIndicator = 1;
		AddCapk.ucCAPKIndicator = 1;
		AddCapk.ucModulusLen = 1152/8;
		two2one((unsigned char*)"A89F25A56FA6DA258C8CA8B40427D927B4A1EB4D7EA326BBB12F97DED70AE5E4480FC9C5E8A972177110A1CC318D06D2F8F5C4844AC5FA79A4DC470BB11ED635699C17081B90F1B984F12E92C1C529276D8AF8EC7F28492097D8CD5BECEA16FE4088F6CFAB4A1B42328A1B996F9278B0B7E3311CA5EF856C2F888474B83612A82E4E00D0CD4069A6783140433D50725F"
			   ,AddCapk.ucModulusLen*2,AddCapk.ucModulus);
		memcpy(AddCapk.ucExponent,"\x03", 1);
		AddCapk.ucExponentLen = 1;
		two2one((unsigned char*)"B4BC56CC4E88324932CBC643D6898F6FE593B172",20*2,AddCapk.ucCheckSum);
		ret = FileAppend((unsigned char*)CAPK_NAME,(unsigned char*)&AddCapk,sizeof(AddCapk));
		if(ret!=0) return;

			//VISA  08
		memcpy(AddCapk.ucRID,"\xA0\x00\x00\x00\x03", 5);
		AddCapk.ucIndex = 0x08;
		memcpy(AddCapk.ucExpDate,"\x35\x12\x31", 3);
		AddCapk.ucHashIndicator = 1;
		AddCapk.ucCAPKIndicator = 1;
		AddCapk.ucModulusLen = 1408/8;
		two2one((unsigned char*)"D9FD6ED75D51D0E30664BD157023EAA1FFA871E4DA65672B863D255E81E137A51DE4F72BCC9E44ACE12127F87E263D3AF9DD9CF35CA4A7B01E907000BA85D24954C2FCA3074825DDD4C0C8F186CB020F683E02F2DEAD3969133F06F7845166ACEB57CA0FC2603445469811D293BFEFBAFAB57631B3DD91E796BF850A25012F1AE38F05AA5C4D6D03B1DC2E568612785938BBC9B3CD3A910C1DA55A5A9218ACE0F7A21287752682F15832A678D6E1ED0B"
			   ,AddCapk.ucModulusLen*2,AddCapk.ucModulus);
		memcpy(AddCapk.ucExponent,"\x03", 1);
		AddCapk.ucExponentLen = 1;
		two2one((unsigned char*)"20D213126955DE205ADC2FD2822BD22DE21CF9A8" ,20*2,AddCapk.ucCheckSum);
		ret = FileAppend((unsigned char*)CAPK_NAME,(unsigned char*)&AddCapk,sizeof(AddCapk));
		if(ret!=0) return;

		//VISA  09
		memcpy(AddCapk.ucRID,"\xA0\x00\x00\x00\x03", 5);
		AddCapk.ucIndex = 0x09;
		memcpy(AddCapk.ucExpDate,"\x35\x12\x31", 3);
		AddCapk.ucHashIndicator = 1;
		AddCapk.ucCAPKIndicator = 1;
		AddCapk.ucModulusLen = 1984/8;
		two2one((unsigned char*)"9D912248DE0A4E39C1A7DDE3F6D2588992C1A4095AFBD1824D1BA74847F2BC4926D2EFD904B4B54954CD189A54C5D1179654F8F9B0D2AB5F0357EB642FEDA95D3912C6576945FAB897E7062CAA44A4AA06B8FE6E3DBA18AF6AE3738E30429EE9BE03427C9D64F695FA8CAB4BFE376853EA34AD1D76BFCAD15908C077FFE6DC5521ECEF5D278A96E26F57359FFAEDA19434B937F1AD999DC5C41EB11935B44C18100E857F431A4A5A6BB65114F174C2D7B59FDF237D6BB1DD0916E644D709DED56481477C75D95CDD68254615F7740EC07F330AC5D67BCD75BF23D28A140826C026DBDE971A37CD3EF9B8DF644AC385010501EFC6509D7A41"
			   ,AddCapk.ucModulusLen*2,AddCapk.ucModulus);
		memcpy(AddCapk.ucExponent,"\x03", 1);
		AddCapk.ucExponentLen = 1;
		two2one((unsigned char*)"1FF80A40173F52D7D27E0F26A146A1C8CCB29046",20*2,AddCapk.ucCheckSum);
		ret = FileAppend((unsigned char*)CAPK_NAME,(unsigned char*)&AddCapk,sizeof(AddCapk));
		if(ret!=0) return;

		ret = FileGetSize((unsigned char*)CAPK_NAME);
	}
	gCapkFileLen = ret;
	if(gCapkFileLen>sizeof(gCapkFileData)) gCapkFileLen=sizeof(gCapkFileData);
	ret=FileRead((unsigned char*)CAPK_NAME,gCapkFileData,0,&gCapkFileLen);
	if(ret!=0) return;
	EmvClearCAPKList();
	for(i=0;i<gCapkFileLen;i+=sizeof(AddCapk)){
	    memset(&AddCapk,0,sizeof(AddCapk));
		memcpy(&AddCapk,&gCapkFileData[i],sizeof(AddCapk));
		EmvADDCAPKList((T_EMV_TERM_CAPK*)&gCapkFileData[i]);
	}


}

void DialogEmv::OnBnClickedButton2()
{

	CTime tm;
	char time[6];
	unsigned char timeBCD[3];
	int ret,i,index;
	unsigned int Amt,Taglen;
	unsigned char ATR[64],slot,Amoutbuf[16],TransResult[16],buf[512];
	CString str,Amtstr="",Tagstr;
	GetDlgItem(IDC_EDIT1)->GetWindowText(str);
	slot = atol(str);
	int mark = IccInit(slot,ATR);	
	if(mark!=0){
		GetDlgItem(IDC_EDIT3)->SetWindowText(_T("Card Reset Failed"));
		return ;
	}
	GetDlgItem(IDC_EDIT2)->GetWindowText(str);
	if(str.GetLength()>12)
	{
	   GetDlgItem(IDC_EDIT3)->SetWindowText(_T("Amout len error"));
	   return ;
	}if(str.GetLength()<12)
	{
	   for(i=0;i<12-str.GetLength();i++)
	      Amtstr+= "0";

	   Amtstr+= str;
	   strcpy((char*)buf,Amtstr);
	}else{
	   strcpy((char*)buf,str);
	}

	GetDlgItem(IDC_EDIT3)->SetWindowText("");

	two2one(buf,12,Amoutbuf);
	

	tm=CTime::GetCurrentTime();
	str=tm.Format("%Y%m%d");
	 for(i=0;i<6;i++)
	time[i]=str.GetAt(2+i);
	two2one((unsigned char *)time,6,EmvCoreGetTransParam()->ucTransDate);

	str=tm.Format("%H%M%S");
	 for(i=0;i<6;i++)
	time[i]=str.GetAt(i);
	two2one((unsigned char *)time,6,EmvCoreGetTransParam()->ucTransTime);

	ret = EmvCoreTrans(slot,Amoutbuf,TransResult);

	if(ret!=0)
	{
		Tagstr="\r\nEmvCoreTrans failed!! \r\nret=";
		str.Format("%d",ret);
		Tagstr += str;
	   // GetDlgItem(IDC_EDIT3)->SetWindowText(Tagstr);
		index = INFOBOX_EMV->GetWindowTextLength();
        INFOBOX_EMV->SetSel(index, index);
        INFOBOX_EMV->ReplaceSel((LPCTSTR)Tagstr);
	}else{
	   Tagstr="\r\nEmvCoreTrans Finish!! \r\n";
	   ret=EmvCoreGetTagData(0x5F20,buf,&Taglen);
	   if(!ret){
		  Tagstr+= "Cardholder Name:";
	      for(i=0;i<Taglen;i++){
			str.Format("%c",buf[i]);
			Tagstr +=str;
		  }
		  Tagstr+= "\r\n";
	   }
	   ret=EmvCoreGetTagData(0x5A,buf,&Taglen);
	   if(!ret){
		  Tagstr+= "PAN:";
	      for(i=0;i<Taglen;i++){
			str.Format("%02x",buf[i]);
			Tagstr +=str;
		  }
		  Tagstr+= "\r\n";
	   }

	 //  GetDlgItem(IDC_EDIT3)->SetWindowText(Tagstr);
	  index = INFOBOX_EMV->GetWindowTextLength();
      INFOBOX_EMV->SetSel(index, index);
      INFOBOX_EMV->ReplaceSel((LPCTSTR)Tagstr);
	}

}




//Enter PIN, ucPINType =0 online cipher text PIN, return encrypted PINBLOCK
//ucPINType =1 or 2 Offline PIN needs to return the plain text ASC format PIN
//Return 0 input success, no password return -32, return other values for input failure
int EmvCbInputPinFun(unsigned char ucPINType,unsigned char *pucOutPINBlock)
{

	return 0;
}
/*
回调联机处理函数
提供给应用自行处理发给后台的55域和后台返回的发卡行的脚本数据
55域数据自行通过EmvCoreGetTagData函数获取TAG值，发卡行返回的脚本需要
通过EmvCoreSetTagData函数设置进去
Callback online processing function
Provides the application with the script data of the 55 domain sent to the background and the issuer returned by the background.
The 55 domain data itself obtains the TAG value through the EmvCoreGetTagData function, and the script returned by the issuing bank needs to be set through the EmvCoreSetTagData function.
*/
int EmvCbOnlineProcFun(void)
{
   
   return 0;
}



int EmvCbDebugLogFun(u8 *pIn, u32 uiLen)
{

   int index;

   index = INFOBOX_EMV->GetWindowTextLength();
   INFOBOX_EMV->SetSel(index, index);
   INFOBOX_EMV->ReplaceSel((LPCTSTR)pIn);

   return 0;
}
/*
Emv 内核回调设置，需要设置哪个函数就重新赋值该函数就可以了，不重新赋值的内核默认返回成功的。
Emv kernel callback settings, you need to set which function to re-assign the function, the kernel without re-assignment returns successfully by default.
*/
void DialogEmv::OnBnClickedButton3()
{

	CString str;
	int ret;
    T_EMVCORE_CALLBACK tEmvCb;
	memset(&tEmvCb,0,sizeof(tEmvCb));
	tEmvCb.EmvCbOnlineProcFun = EmvCbOnlineProcFun;
	tEmvCb.EmvCbInputPINFun = EmvCbInputPinFun;
	tEmvCb.EmvCbDebugPritLogFun = EmvCbDebugLogFun;
	ret = EmvCoreSetCallBackFun(&tEmvCb);
	if(ret){
	  str.Format("%02x",ret);
	  GetDlgItem(IDC_EDIT3)->SetWindowText(_T("EmvCoreSetCallBackFun failed ret =")+str);
	}else{
	  GetDlgItem(IDC_EDIT3)->SetWindowText(_T("EmvCoreSetCallBackFun OK"));
	}
}


void DialogEmv::OnBnClickedButton4()
{

	int ret;
	char *pLog;
	CString OutLogstr;
	GetDlgItem(IDC_EDIT3)->GetWindowText(OutLogstr);

	pLog = OutLogstr.GetBuffer(0); 
	ret=FileWrite((unsigned char*)"EmvDebugLog.txt",(unsigned char*)pLog,OutLogstr.GetLength());
	if(!ret)
	{
	   MessageBox(_T("Log saved in EmvDebugLog.txt file"),_T("note"));
	}else{
	   MessageBox(_T("Saving file failed"),_T("error:"));
	}
}


void DialogEmv::OnBnClickedCheck1()
{


	if(((CButton*)GetDlgItem(IDC_CHECK1))->GetCheck()==TRUE)
		EmvCoreGetTermParam()->ucPrintfDebugInfo=1;
	else
		EmvCoreGetTermParam()->ucPrintfDebugInfo=0;
}


void DialogEmv::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码

	m_paraEmvCapk.CenterWindow();
	m_paraEmvCapk.ShowWindow(true);

	m_paraEmvCapk.DisplayCapk();
}


void DialogEmv::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	unsigned char TerCapa[4];
	CString str,OutStr="";
	int i;

	memset(TerCapa,0,sizeof(TerCapa));
	if(((CButton*)GetDlgItem(IDC_CHECK2))->GetCheck()==TRUE)
		TerCapa[0] |= 0x80; 
	if(((CButton*)GetDlgItem(IDC_CHECK3))->GetCheck()==TRUE)
		TerCapa[0] |= 0x40; 
	if(((CButton*)GetDlgItem(IDC_CHECK4))->GetCheck()==TRUE)
		TerCapa[0] |= 0x20; 

	if(((CButton*)GetDlgItem(IDC_CHECK5))->GetCheck()==TRUE)
		TerCapa[1] |= 0x80; 
	if(((CButton*)GetDlgItem(IDC_CHECK6))->GetCheck()==TRUE)
		TerCapa[1] |= 0x40; 
	if(((CButton*)GetDlgItem(IDC_CHECK7))->GetCheck()==TRUE)
		TerCapa[1] |= 0x20; 
	if(((CButton*)GetDlgItem(IDC_CHECK8))->GetCheck()==TRUE)
		TerCapa[1] |= 0x10; 
	if(((CButton*)GetDlgItem(IDC_CHECK9))->GetCheck()==TRUE)
		TerCapa[1] |= 0x08; 

	if(((CButton*)GetDlgItem(IDC_CHECK10))->GetCheck()==TRUE)
		TerCapa[2] |= 0x80; 
	if(((CButton*)GetDlgItem(IDC_CHECK11))->GetCheck()==TRUE)
		TerCapa[2] |= 0x40; 
	if(((CButton*)GetDlgItem(IDC_CHECK12))->GetCheck()==TRUE)
		TerCapa[2] |= 0x20; 
	if(((CButton*)GetDlgItem(IDC_CHECK13))->GetCheck()==TRUE)
		TerCapa[2] |= 0x08;

	for(i=0;i<3;i++)
	{
		str.Format("%02x",TerCapa[i]);
		OutStr += str;
	}
	 GetDlgItem(IDC_EDIT4)->SetWindowText(OutStr);

	 memcpy(EmvCoreGetTermParam()->ucTermCapa,TerCapa,3);

	 MessageBox(_T("Setting OK"),_T("note"));
}


void DialogEmv::OnBnClickedButton11()
{
	// TODO: 在此添加控件通知处理程序代码

    int i;
    CString str,OutStr;


	GetDlgItem(IDC_EDIT7)->GetWindowText(str);
	if(str.GetLength()>80){
	   MessageBox(_T("MerchantNameLocation len error"),_T("error:"));
	}
	memset(EmvCoreGetTermParam()->ucMerchantNameLocation,0,sizeof(EmvCoreGetTermParam()->ucMerchantNameLocation));
	strcpy((char*)EmvCoreGetTermParam()->ucMerchantNameLocation,str);

	GetDlgItem(IDC_EDIT8)->GetWindowText(str);
	if(str.GetLength()!=4){
	   MessageBox(_T("TerminalCountry len error"),_T("error:"));
	}
	two2one((unsigned char *)str.GetBuffer(0),str.GetLength(),EmvCoreGetTermParam()->ucTerminalCountry);
	
	GetDlgItem(IDC_EDIT10)->SetWindowText(str);
	if(str.GetLength()!=4){
	   MessageBox(_T("TranCurrCode len error"),_T("error:"));
	}
	two2one((unsigned char *)str.GetBuffer(0),str.GetLength(),EmvCoreGetTermParam()->ucTranCurrCode);
	
	GetDlgItem(IDC_EDIT9)->GetWindowText(str);
	if(str.GetLength()!=2){
	   MessageBox(_T("TermType len error"),_T("error:"));
	}
	two2one((unsigned char *)str.GetBuffer(0),str.GetLength(),&EmvCoreGetTermParam()->ucTermType);

	MessageBox(_T("Setting OK"),_T("note"));
}


void DialogEmv::OnBnClickedButton12()
{
	// TODO: 在此添加控件通知处理程序代码
	int i;
    CString str,OutStr;
    if(((CButton*)GetDlgItem(IDC_CHECK14))->GetCheck()==TRUE)
	  EmvCoreGetTransParam()->ucIsForceOnline = 1;
	else
      EmvCoreGetTransParam()->ucIsForceOnline = 0;
		
	if(((CButton*)GetDlgItem(IDC_CHECK15))->GetCheck()==TRUE)
      EmvCoreGetTransParam()->ucIsSimpleFlow = 1;
	else
	  EmvCoreGetTransParam()->ucIsSimpleFlow = 0;

    GetDlgItem(IDC_EDIT12)->GetWindowText(str);
	if(str.GetLength()!=2){
	   MessageBox(_T("TransType len error"),_T("error:"));
	}
	two2one((unsigned char *)str.GetBuffer(0),str.GetLength(),&EmvCoreGetTransParam()->ucTransType);
	

	GetDlgItem(IDC_EDIT13)->GetWindowText(str);
	if(str.GetLength()!=8){
	   MessageBox(_T("ReaderTTQ len error"),_T("error:"));
	}
	two2one((unsigned char *)str.GetBuffer(0),str.GetLength(),EmvCoreGetTransParam()->ucReaderTTQ);
	
	GetDlgItem(IDC_EDIT14)->GetWindowText(OutStr);
	if(str.GetLength()!=8){
	   MessageBox(_T("ReaderTTQ len error"),_T("error:"));
	}
	two2one((unsigned char *)str.GetBuffer(0),str.GetLength(),EmvCoreGetTransParam()->ucTransNo);
	
	MessageBox(_T("Setting OK"),_T("note"));
}
