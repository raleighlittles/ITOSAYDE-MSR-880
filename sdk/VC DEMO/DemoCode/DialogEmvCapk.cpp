// DialogEmvCapk.cpp : 实现文件
//

#include "stdafx.h"
#include "m160.h"
#include "DialogEmvCapk.h"
#include "afxdialogex.h"
#include "160.h"
#include "DemoFiles.h" 

#include "DialogEmv.h"
extern DialogEmv m_DialgEmv;
// DialogEmvCapk 对话框

IMPLEMENT_DYNAMIC(DialogEmvCapk, CDialog)

DialogEmvCapk::DialogEmvCapk(CWnd* pParent /*=NULL*/)
	: CDialog(DialogEmvCapk::IDD, pParent)
{

	EnableAutomation();

}

DialogEmvCapk::~DialogEmvCapk()
{
}

void DialogEmvCapk::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。基类将自动
	// 删除该对象。在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CDialog::OnFinalRelease();
}

void DialogEmvCapk::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, gEmvCapkList);
}


BEGIN_MESSAGE_MAP(DialogEmvCapk, CDialog)
	ON_BN_CLICKED(IDOK, &DialogEmvCapk::OnBnClickedOk)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &DialogEmvCapk::OnNMClickList1)
	ON_BN_CLICKED(IDC_BUTTON1, &DialogEmvCapk::OnBnClickedButton1)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(DialogEmvCapk, CDialog)
END_DISPATCH_MAP()

// 注意: 我们添加 IID_IDialogEmvCapk 支持
//  以支持来自 VBA 的类型安全绑定。此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {36805A6E-7454-4AC8-9E37-819F567A22AD}
static const IID IID_IDialogEmvCapk =
{ 0x36805A6E, 0x7454, 0x4AC8, { 0x9E, 0x37, 0x81, 0x9F, 0x56, 0x7A, 0x22, 0xAD } };

BEGIN_INTERFACE_MAP(DialogEmvCapk, CDialog)
	INTERFACE_PART(DialogEmvCapk, IID_IDialogEmvCapk, Dispatch)
END_INTERFACE_MAP()


// DialogEmvCapk 消息处理程序
BOOL DialogEmvCapk::OnInitDialog()  
{
	CDialog::OnInitDialog();

	gEmvCapkList.DeleteAllItems();//清空
	gEmvCapkList.InsertColumn(0,_T("RID"));//添加列
	gEmvCapkList.SetColumnWidth(0, 150);//设置列宽
	gEmvCapkList.InsertColumn(1,_T("CapkIndex"));
	gEmvCapkList.SetColumnWidth(1, 100);
	gEmvCapkList.InsertColumn(2,_T("HashIndicator"));
	gEmvCapkList.SetColumnWidth(2, 100);
    gEmvCapkList.InsertColumn(3,_T("CapkIndicator"));  
	gEmvCapkList.SetColumnWidth(3, 100);    
	gEmvCapkList.InsertColumn(4,_T("Modulus"));  
	gEmvCapkList.SetColumnWidth(4, 150); 
	gEmvCapkList.InsertColumn(5,_T("Exponent"));  
	gEmvCapkList.SetColumnWidth(5, 100);  
	gEmvCapkList.InsertColumn(6,_T("ExpDate"));  
	gEmvCapkList.SetColumnWidth(6, 100);   
	gEmvCapkList.InsertColumn(7,_T("CheckSum"));  
	gEmvCapkList.SetColumnWidth(7, 150);
	
	//gAidList.InsertColumn(4,_T(".....")); 
	//gAidList.SetColumnWidth(4, 50);   

	gEmvCapkList.SetRedraw(FALSE);//防止重绘

    gEmvCapkList.SetExtendedStyle(gEmvCapkList.GetExtendedStyle() | LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);

	gEmvCapkList.SetRedraw(TRUE);//显示
   

	return TRUE; 
}

extern unsigned int gCapkFileLen;
extern unsigned char gCapkFileData[512*128];

void DialogEmvCapk::DisplayCapk() 
{
	int i,len,j,SubItem=1,Item=0;
	T_EMV_TERM_CAPK *pCapkList;
	CString Outstr,str;
    int nIndex;

	if(gCapkFileLen>0){
	   
       nIndex = gEmvCapkList.GetItemCount();
	   if(nIndex>0) return;

	   for(i=0;i<gCapkFileLen;i+=sizeof(T_EMV_TERM_CAPK),Item++)
	   {
		    SubItem=1;
		    pCapkList = (T_EMV_TERM_CAPK*)&gCapkFileData[i];
			len=5;
			Outstr="";
			for(j=0;j<len;j++)
			{
				str.Format("%02x",pCapkList->ucRID[j]);
				Outstr+= str;
			}
			nIndex=gEmvCapkList.InsertItem( Item,_T(Outstr) );
			if( nIndex < 0 ) return;

			str.Format("%02x",pCapkList->ucIndex);
			gEmvCapkList.SetItemText( nIndex, SubItem++, str );

			str.Format("%02x",pCapkList->ucHashIndicator);
			gEmvCapkList.SetItemText( nIndex, SubItem++, str );

			str.Format("%02x",pCapkList->ucCAPKIndicator);
			gEmvCapkList.SetItemText( nIndex, SubItem++, str );

			len=pCapkList->ucModulusLen;
			Outstr="";
			for(j=0;j<len;j++)
			{
				str.Format("%02x",pCapkList->ucModulus[j]);
				Outstr+= str;
			}
			gEmvCapkList.SetItemText( nIndex, SubItem++, Outstr );

			len=pCapkList->ucExponentLen;
			Outstr="";
			for(j=0;j<len;j++)
			{
				str.Format("%02x",pCapkList->ucExponent[j]);
				Outstr+= str;
			}
			gEmvCapkList.SetItemText( nIndex, SubItem++, Outstr );

			len=3;
			Outstr="";
			for(j=0;j<len;j++)
			{
				str.Format("%02x",pCapkList->ucExpDate[j]);
				Outstr+= str;
			}
			gEmvCapkList.SetItemText( nIndex, SubItem++, Outstr );

			len=20;
			Outstr="";
			for(j=0;j<len;j++)
			{
				str.Format("%02x",pCapkList->ucCheckSum[j]);
				Outstr+= str;
			}
			gEmvCapkList.SetItemText( nIndex, SubItem++, Outstr );


	   }
	}
}
extern void two2one(unsigned char *in,int in_len,unsigned char *out);
void DialogEmvCapk::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialog::OnOK();
	T_EMV_TERM_CAPK AddCapk;

	char textbuf[512];
	CString str,capkstr,Indexstr;
	int SubItem=1,i,ret,j;
    int nIndex = gEmvCapkList.GetItemCount();

	GetDlgItem(IDC_EDIT1)->GetWindowText(str);
	for(i=0;i<nIndex;i++)
	{
	   gEmvCapkList.GetItemText(i,0,textbuf,200);
	   capkstr = textbuf;
       if(strcmp(str,capkstr)==0)
	   {
		  GetDlgItem(IDC_EDIT2)->GetWindowText(Indexstr);
		  gEmvCapkList.GetItemText(i,1,textbuf,200);
		  capkstr = textbuf;
		  if(strcmp(Indexstr,capkstr)==0){
	        MessageBox(_T("This CAPK Index already exists"),_T("error:"));
		    return;
		  }
	   }
	}
	if (gEmvCapkList.InsertItem( nIndex,_T(str) ) != -1)
	{  
	   memset(&AddCapk,0,sizeof(AddCapk));

	   two2one((unsigned char*)str.GetBuffer(0),str.GetLength(),AddCapk.ucRID);

	   GetDlgItem(IDC_EDIT2)->GetWindowText(str);
	   gEmvCapkList.SetItemText( nIndex, SubItem++, str );
	   two2one((unsigned char*)str.GetBuffer(0),str.GetLength(),&AddCapk.ucIndex);

       GetDlgItem(IDC_EDIT3)->GetWindowText(str);
	   gEmvCapkList.SetItemText( nIndex, SubItem++, str );  
	   two2one((unsigned char*)str.GetBuffer(0),str.GetLength(),&AddCapk.ucHashIndicator);

	   GetDlgItem(IDC_EDIT4)->GetWindowText(str);
	   gEmvCapkList.SetItemText( nIndex, SubItem++, str );
	   two2one((unsigned char*)str.GetBuffer(0),str.GetLength(),&AddCapk.ucCAPKIndicator);

	   GetDlgItem(IDC_EDIT5)->GetWindowText(str);
	   gEmvCapkList.SetItemText( nIndex, SubItem++, str );
	   AddCapk.ucModulusLen=str.GetLength()/2;
	   two2one((unsigned char*)str.GetBuffer(0),str.GetLength(),AddCapk.ucModulus);

	   GetDlgItem(IDC_EDIT6)->GetWindowText(str);
	   gEmvCapkList.SetItemText( nIndex, SubItem++, str );
	   AddCapk.ucExponentLen=str.GetLength()/2;
	   two2one((unsigned char*)str.GetBuffer(0),str.GetLength(),AddCapk.ucExponent);

	   GetDlgItem(IDC_EDIT7)->GetWindowText(str);
	   gEmvCapkList.SetItemText( nIndex, SubItem++, str );
	   two2one((unsigned char*)str.GetBuffer(0),str.GetLength(),AddCapk.ucExpDate);

	   GetDlgItem(IDC_EDIT8)->GetWindowText(str);
	   gEmvCapkList.SetItemText( nIndex, SubItem++, str );
	   two2one((unsigned char*)str.GetBuffer(0),str.GetLength(),AddCapk.ucCheckSum);

	   AddCapk.unCrc = 0x5a5a;  


	   ret = FileGetSize((unsigned char*)CAPK_NAME);
	   if(ret<0){
         ret=FileWrite((unsigned char*)CAPK_NAME,(unsigned char*)&AddCapk,sizeof(AddCapk));
	   }else
	     ret = FileAppend((unsigned char*)CAPK_NAME,(unsigned char*)&AddCapk,sizeof(AddCapk)); 

	   if(!ret)
	   {
		  EmvADDCAPKList((T_EMV_TERM_CAPK*)&AddCapk);
	      MessageBox(_T("CAPK added successfully"),_T("note"));
	   }
	}
}


void DialogEmvCapk::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	int gItem;
	if(pNMItemActivate != NULL)
	{
		gItem = pNMItemActivate->iItem;
	}else{
	  return ;
	}

	   //获取信息
    char textbuf[512];
	int i=0;
	CString str;
	gEmvCapkList.GetItemText(gItem,i++,textbuf,200);
	str = textbuf;
	GetDlgItem(IDC_EDIT1)->SetWindowText(str);


	gEmvCapkList.GetItemText(gItem,i++,textbuf,200);
	str = textbuf;
	GetDlgItem(IDC_EDIT2)->SetWindowText(str);

	gEmvCapkList.GetItemText(gItem,i++,textbuf,200);
	str = textbuf;
	GetDlgItem(IDC_EDIT3)->SetWindowText(str);

	gEmvCapkList.GetItemText(gItem,i++,textbuf,200);
	str = textbuf;
	GetDlgItem(IDC_EDIT4)->SetWindowText(str);

	gEmvCapkList.GetItemText(gItem,i++,textbuf,500);
	str = textbuf;
	GetDlgItem(IDC_EDIT5)->SetWindowText(str);

	gEmvCapkList.GetItemText(gItem,i++,textbuf,200);
	str = textbuf;
	GetDlgItem(IDC_EDIT6)->SetWindowText(str);

	gEmvCapkList.GetItemText(gItem,i++,textbuf,200);
	str = textbuf;
	GetDlgItem(IDC_EDIT7)->SetWindowText(str);

	gEmvCapkList.GetItemText(gItem,i++,textbuf,200);
	str = textbuf;
	GetDlgItem(IDC_EDIT8)->SetWindowText(str);
}


void DialogEmvCapk::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	int ret,capklen,i,AidIndex;
	unsigned int filelen;
	char AIDbuf[36];
	CString str,aidstr,indexstr;
	int CapkNum = gEmvCapkList.GetItemCount();
	ret = FileGetSize((unsigned char*)CAPK_NAME);
	if(ret>0)
	{  
		GetDlgItem(IDC_EDIT1)->GetWindowText(str);
		for(i=0;i<CapkNum;i++)
		{
		   gEmvCapkList.GetItemText(i,0,AIDbuf,32);
		   aidstr = AIDbuf;
		   if(strcmp(str,aidstr)==0)
		   {
			   GetDlgItem(IDC_EDIT2)->GetWindowText(indexstr);
			   gEmvCapkList.GetItemText(i,1,AIDbuf,32);
			   aidstr = AIDbuf;
			   if(strcmp(indexstr,aidstr)==0)
			   {
			     AidIndex=i;
			     break;
			   }
		   }
		}
		if(i==CapkNum)
		{
		   MessageBox(_T("This AID does not exist"),_T("error:"));
		   return;
		}

	   capklen =  sizeof(T_EMV_TERM_CAPK);
       filelen = ret;
	   if(filelen>sizeof(gCapkFileData)) filelen= sizeof(gCapkFileData);
	   ret=FileRead((unsigned char*)CAPK_NAME,gCapkFileData,0,&filelen);
	   if(ret!=0) return;
	   memmove(gCapkFileData+capklen*AidIndex,gCapkFileData+capklen*(AidIndex+1),filelen-capklen*(AidIndex+1));
	   ret=FileWrite((unsigned char*)CAPK_NAME,(unsigned char*)gCapkFileData,filelen-capklen);
	   if(ret!=0) return;

       gEmvCapkList.DeleteItem(AidIndex);
	   m_DialgEmv.ReadEmvFile();

	   MessageBox(_T("CAPK delete successfully"),_T("note"));    
	}
}
