#if !defined(AFX_DIALOG3_H__58181686_9CC0_422B_976A_6FD2D227B596__INCLUDED_)
#define AFX_DIALOG3_H__58181686_9CC0_422B_976A_6FD2D227B596__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dialog3.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDialog3 dialog

class CDialog3 : public CDialog
{
// Construction
public:
	CDialog3(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDialog3)
	enum { IDD = IDD_DIALOG3 };
	CComboBox	m_com;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialog3)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialog3)
	virtual void OnCancel();
	virtual BOOL OnInitDialog();
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	virtual void OnOK();
	afx_msg void OnCancel2();
	afx_msg void OnButton2();
	afx_msg void OnButton1();
	afx_msg void OnButton4();
	afx_msg void OnButton5();
	afx_msg void OnButton6();
	afx_msg void OnButton7();
	afx_msg void OnButton8();
	afx_msg void OnButton9();
	afx_msg void OnButton10();
	afx_msg void OnButton11();
	afx_msg void OnButton12();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG3_H__58181686_9CC0_422B_976A_6FD2D227B596__INCLUDED_)
