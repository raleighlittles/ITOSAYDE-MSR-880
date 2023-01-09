// m160Dlg.h : header file
//

#if !defined(AFX_M160DLG_H__8554156E_300F_4CB6_B0A1_D720828D12A4__INCLUDED_)
#define AFX_M160DLG_H__8554156E_300F_4CB6_B0A1_D720828D12A4__INCLUDED_

#include "Dialog1.h"	// Added by ClassView
#include "Dialog2.h"	// Added by ClassView
#include "Dialog3.h"	// Added by ClassView
#include "Dialog4.h"	// Added by ClassView
#include "Dialog5.h"	// Added by ClassView
#include "Dialog6.h"	// Added by ClassView
#include "ReadInfo.h"	// Added by ClassView
#include "dialogDesfire.h"
#include "DialogPinPad.h"
#include "DialogEmv.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CM160Dlg dialog

class CM160Dlg : public CDialog
{
// Construction
public:
	DialogEmv m_paraEmv;
	DialogPinPad m_paraPinPad;
	dialogDesfire m_paraDesfire;
	ReadInfo InfoDlg;
	CDialog6 m_para6;
	CDialog5 m_para5;
	CDialog4 m_para4;
	CDialog3 m_para3;
	CDialog2 m_para2;
	CDialog1 m_para1;
	CM160Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CM160Dlg)
	enum { IDD = IDD_M160_DIALOG };
	CTabCtrl	m_tabMain;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CM160Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CM160Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	afx_msg void OnRadio3();
	afx_msg void OnRadio4();
	afx_msg void OnChangeEdit1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_M160DLG_H__8554156E_300F_4CB6_B0A1_D720828D12A4__INCLUDED_)
