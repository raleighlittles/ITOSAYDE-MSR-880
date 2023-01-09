#pragma once
#include "afxcmn.h"


// DialogEmvPara 对话框

class DialogEmvPara : public CDialog
{
	DECLARE_DYNAMIC(DialogEmvPara)

public:
	DialogEmvPara(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DialogEmvPara();

	virtual void OnFinalRelease();

// 对话框数据
	enum { IDD = IDD_DIALOGEMVPARA };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
	BOOL DialogEmvPara::OnInitDialog(); 
public:
	void DisplayAID(void);
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButton1();
	CListCtrl gAidList;
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
};
