#pragma once
#include "afxcmn.h"


// DialogEmvPara �Ի���

class DialogEmvPara : public CDialog
{
	DECLARE_DYNAMIC(DialogEmvPara)

public:
	DialogEmvPara(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DialogEmvPara();

	virtual void OnFinalRelease();

// �Ի�������
	enum { IDD = IDD_DIALOGEMVPARA };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
