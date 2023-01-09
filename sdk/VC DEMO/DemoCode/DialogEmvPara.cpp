// DialogEmvPara.cpp : 实现文件
//

#include "stdafx.h"
#include "m160.h"
#include "DialogEmvPara.h"
#include "afxdialogex.h"
#include "160.h"
#include "DemoFiles.h" 

#include "DialogEmv.h"
DialogEmv m_DialgEmv;

// DialogEmvPara 对话框

IMPLEMENT_DYNAMIC(DialogEmvPara, CDialog)

DialogEmvPara::DialogEmvPara(CWnd* pParent /*=NULL*/)
	: CDialog(DialogEmvPara::IDD, pParent)
{

	EnableAutomation();

}

DialogEmvPara::~DialogEmvPara()
{
}

void DialogEmvPara::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。基类将自动
	// 删除该对象。在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CDialog::OnFinalRelease();
}

void DialogEmvPara::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, gAidList);
}


BEGIN_MESSAGE_MAP(DialogEmvPara, CDialog)
	ON_BN_CLICKED(IDOK, &DialogEmvPara::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &DialogEmvPara::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON1, &DialogEmvPara::OnBnClickedButton1)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &DialogEmvPara::OnLvnItemchangedList1)
    ON_NOTIFY(NM_CLICK,IDC_LIST1,&DialogEmvPara::OnClickList1)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(DialogEmvPara, CDialog)
END_DISPATCH_MAP()

// 注意: 我们添加 IID_IDialogEmvPara 支持
//  以支持来自 VBA 的类型安全绑定。此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {3D8D92D7-AD2E-4131-A786-AC0B1B2E08DC}
static const IID IID_IDialogEmvPara =
{ 0x3D8D92D7, 0xAD2E, 0x4131, { 0xA7, 0x86, 0xAC, 0xB, 0x1B, 0x2E, 0x8, 0xDC } };

BEGIN_INTERFACE_MAP(DialogEmvPara, CDialog)
	INTERFACE_PART(DialogEmvPara, IID_IDialogEmvPara, Dispatch)
END_INTERFACE_MAP()


// DialogEmvPara 消息处理程序
BOOL DialogEmvPara::OnInitDialog() 
{
	CDialog::OnInitDialog();

	gAidList.DeleteAllItems();//清空
	gAidList.InsertColumn(0,_T("AID"));//添加列
	gAidList.SetColumnWidth(0, 150);//设置列宽
	gAidList.InsertColumn(1,_T("SelectIndicator"));
	gAidList.SetColumnWidth(1, 120);
	gAidList.InsertColumn(2,_T("TermAVM"));
	gAidList.SetColumnWidth(2, 80);
    gAidList.InsertColumn(3,_T("OnLinePINFlag")); 
	gAidList.SetColumnWidth(3, 120);   
	
	//gAidList.InsertColumn(4,_T(".....")); 
	//gAidList.SetColumnWidth(4, 50);   

	gAidList.SetRedraw(FALSE);//防止重绘

    gAidList.SetExtendedStyle(gAidList.GetExtendedStyle() | LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);

	gAidList.SetRedraw(TRUE);//显示
   

	return TRUE; 
}
extern  unsigned int gAidFileLen;
extern  unsigned char gAidFileData[1024*128];
extern void two2one(unsigned char *in,int in_len,unsigned char *out);
int  gItem;
void DialogEmvPara::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialog::OnOK();
	T_EMV_APP_LIST AddAid;

	char textbuf[256];
	CString str,aidstr;
	int SubItem=1,i,ret;
    int nIndex = gAidList.GetItemCount();

	GetDlgItem(IDC_EDIT1)->GetWindowText(str);
	for(i=0;i<nIndex;i++)
	{
	   gAidList.GetItemText(i,0,textbuf,200);
	   aidstr = textbuf;
       if(strcmp(str,aidstr)==0)
	   {
	      MessageBox(_T("This AID already exists"),_T("error:"));
		  return;
	   }
	}
	if (gAidList.InsertItem( nIndex,_T(str) ) != -1)
	{  
	   memset(&AddAid,0,sizeof(AddAid));
	   AddAid.ucAIDLen = str.GetLength()/2;
	   two2one((unsigned char*)str.GetBuffer(0),str.GetLength(),AddAid.ucAID);

	   GetDlgItem(IDC_EDIT2)->GetWindowText(str);
	   gAidList.SetItemText( nIndex, SubItem++, str );
	   AddAid.ucSelectIndicator = atol(str);

       GetDlgItem(IDC_EDIT3)->GetWindowText(str);
	   gAidList.SetItemText( nIndex, SubItem++, str );  
	   two2one((unsigned char*)str.GetBuffer(0),str.GetLength(),AddAid.ucTermAVM);

	   GetDlgItem(IDC_EDIT18)->GetWindowText(str);
	   gAidList.SetItemText( nIndex, SubItem++, str );
	   AddAid.ucOnLinePINFlag = atol(str);

       //设置默认值	
		memcpy(AddAid.ucDdol, "\x9F\x37\x04", 3);
		AddAid.ucDdolLen = 3;
		memcpy(AddAid.ucTdol,"\x9F\x02\x06\x5F\x2A\x02\x9A\x03\x9C\x01\x95\x05\x9F\x37\x04", 15);
		AddAid.ucTdolLen = 15;
		memcpy(AddAid.ucTACDefault, "\x00\x00\x00\x00\x00", 5);
		memcpy(AddAid.ucTACOnline, "\x00\x00\x00\x00\x00", 5);
		memcpy(AddAid.ucTACDenial, "\x00\x00\x00\x00\x00", 5);
		
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


	   ret = FileGetSize((unsigned char*)AID_NAME);
	   if(ret<0){
         ret=FileWrite((unsigned char*)AID_NAME,(unsigned char*)&AddAid,sizeof(AddAid));
	   }else
	     ret = FileAppend((unsigned char*)AID_NAME,(unsigned char*)&AddAid,sizeof(AddAid)); 

	   if(!ret)
	   {
		  EmvAddAIDList((T_EMV_APP_LIST*)&AddAid);
	      MessageBox(_T("AID added successfully"),_T("note"));
	   }
	}

}


void DialogEmvPara::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::OnCancel();
}


void DialogEmvPara::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	int ret,aidlen,i,AidIndex;
	unsigned int filelen;
	char AIDbuf[36];
	CString str,aidstr;
	int AidNum = gAidList.GetItemCount();
	ret = FileGetSize((unsigned char*)AID_NAME);
	if(ret>0)
	{  
		GetDlgItem(IDC_EDIT1)->GetWindowText(str);
		for(i=0;i<AidNum;i++)
		{
		   gAidList.GetItemText(i,0,AIDbuf,32);
		   aidstr = AIDbuf;
		   if(strcmp(str,aidstr)==0)
		   {
			  AidIndex=i;
			  break;;
		   }
		}
		if(i==AidNum)
		{
		   MessageBox(_T("This AID does not exist"),_T("error:"));
		   return;
		}

	   aidlen =  sizeof(T_EMV_APP_LIST);
       filelen = ret;
	   if(filelen>sizeof(gAidFileData)) filelen= sizeof(gAidFileData);
	   ret=FileRead((unsigned char*)AID_NAME,gAidFileData,0,&filelen);
	   if(ret!=0) return;
	   memmove(gAidFileData+aidlen*AidIndex,gAidFileData+aidlen*(AidIndex+1),filelen-aidlen*(AidIndex+1));
	   ret=FileWrite((unsigned char*)AID_NAME,(unsigned char*)gAidFileData,filelen-aidlen);
	   if(ret!=0) return;

       gAidList.DeleteItem(AidIndex);
	   m_DialgEmv.ReadEmvFile();

	   MessageBox(_T("AID delete successfully"),_T("note"));    
	}
}

void DialogEmvPara::OnClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	
	LPNMITEMACTIVATE lpNMItemActivate = (LPNMITEMACTIVATE)pNMHDR;
	if(lpNMItemActivate != NULL)
	{
		gItem = lpNMItemActivate->iItem;
	}else{
	  return ;
	}

	   //获取信息
    char textbuf[256];
	int i=0;
	CString str;
	gAidList.GetItemText(gItem,i++,textbuf,200);
	str = textbuf;
	GetDlgItem(IDC_EDIT1)->SetWindowText(str);


	gAidList.GetItemText(gItem,i++,textbuf,200);
	str = textbuf;
	GetDlgItem(IDC_EDIT2)->SetWindowText(str);

	gAidList.GetItemText(gItem,i++,textbuf,200);
	str = textbuf;
	GetDlgItem(IDC_EDIT3)->SetWindowText(str);

	gAidList.GetItemText(gItem,i++,textbuf,200);
	str = textbuf;
	GetDlgItem(IDC_EDIT18)->SetWindowText(str);
}
void DialogEmvPara::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;

   if(pNMLV != NULL)
   {

   }


}


void DialogEmvPara::DisplayAID()
{
	int i,len,j,SubItem=1,Item=0;
	T_EMV_APP_LIST *pAidList;
	CString Outstr,str;
    int nIndex;

	if(gAidFileLen>0){
	   
       nIndex = gAidList.GetItemCount();
	   if(nIndex>0) return;

	   for(i=0;i<gAidFileLen;i+=sizeof(T_EMV_APP_LIST),Item++)
	   {
		    SubItem=1;
		    pAidList = (T_EMV_APP_LIST*)&gAidFileData[i];
			len=pAidList->ucAIDLen;
			Outstr="";
			for(j=0;j<len;j++)
			{
				str.Format("%02x",pAidList->ucAID[j]);
				Outstr+= str;
			}
			nIndex=gAidList.InsertItem( Item,_T(Outstr) );
			if( nIndex < 0 ) return;

			str.Format("%d",pAidList->ucSelectIndicator);
			gAidList.SetItemText( nIndex, SubItem++, str );

			len=2;
			Outstr="";
			for(j=0;j<len;j++)
			{
				str.Format("%02x",pAidList->ucTermAVM[j]);
				Outstr+= str;
			}
			gAidList.SetItemText( nIndex, SubItem++, Outstr );

			str.Format("%d",pAidList->ucOnLinePINFlag);
			gAidList.SetItemText( nIndex, SubItem++, str );

		


	   }
	}
}

