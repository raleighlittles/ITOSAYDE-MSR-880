#pragma once


// DialogPinPad �Ի���

class DialogPinPad : public CDialogEx
{
	DECLARE_DYNAMIC(DialogPinPad)

public:
	DialogPinPad(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DialogPinPad();

// �Ի�������
	enum { IDD = IDD_DIALOGPINPAD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	virtual BOOL OnInitDialog();
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton14();
	afx_msg void OnBnClickedRadio5();
	afx_msg void OnBnClickedRadio6();
	afx_msg void OnBnClickedButton15();
	afx_msg void OnBnClickedButton16();
};
