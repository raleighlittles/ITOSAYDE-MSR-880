#pragma once
#include "afxcmn.h"


// DialogEmvCapk �Ի���

class DialogEmvCapk : public CDialog
{
	DECLARE_DYNAMIC(DialogEmvCapk)

public:
	DialogEmvCapk(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DialogEmvCapk();

	virtual void OnFinalRelease();

// �Ի�������
	enum { IDD = IDD_DIALOGEMVCAPK };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
	BOOL DialogEmvCapk::OnInitDialog(); 
public:
	void DisplayCapk(void);
	CListCtrl gEmvCapkList;
	afx_msg void OnBnClickedOk();
	afx_msg void OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton1();
};
