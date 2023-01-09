#pragma once

#include "DialogEmvPara.h"
#include "DialogEmvCapk.h"
// DialogEmv �Ի���

class DialogEmv : public CDialog
{
	DECLARE_DYNAMIC(DialogEmv)

public:
	DialogEmvCapk m_paraEmvCapk;
	DialogEmvPara m_paraEmvPara;

	DialogEmv(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DialogEmv();

	virtual void OnFinalRelease();

// �Ի�������
	enum { IDD = IDD_DIALOGEMV };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()

	virtual BOOL OnInitDialog();
	
public:
	void ReadEmvFile(void);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton12();
};
