#if !defined(AFX_DIALOG1_H__7DB42D2F_874C_41EE_9AD0_1D63672A38D8__INCLUDED_)
#define AFX_DIALOG1_H__7DB42D2F_874C_41EE_9AD0_1D63672A38D8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dialog1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDialog1 dialog

class CDialog1 : public CDialog
{
// Construction
public:
	CDialog1(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDialog1)
	enum { IDD = IDD_DIALOG1 };
	CEdit	m_zcs80trcak1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialog1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialog1)
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnRadio3();
	afx_msg void OnRadio4();
	virtual BOOL OnInitDialog();
	afx_msg void OnOk4();
	afx_msg void OnOk2();
	afx_msg void OnCancel2();
	afx_msg void OnOk3();
	afx_msg void OnOk5();
	afx_msg void OnChangeEdit17();
	afx_msg void OnChangeEdit18();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG1_H__7DB42D2F_874C_41EE_9AD0_1D63672A38D8__INCLUDED_)
