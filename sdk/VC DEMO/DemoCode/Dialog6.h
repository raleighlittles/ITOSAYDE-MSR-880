#if !defined(AFX_DIALOG6_H__D336A948_6B07_4C4B_B0E2_C5FCAB9109A9__INCLUDED_)
#define AFX_DIALOG6_H__D336A948_6B07_4C4B_B0E2_C5FCAB9109A9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dialog6.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDialog6 dialog

class CDialog6 : public CDialog
{
// Construction
public:
	CDialog6(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDialog6)
	enum { IDD = IDD_DIALOG6 };
	CStatic	m_image1;
	CStatic	m_image;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialog6)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialog6)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	virtual void OnCancel();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG6_H__D336A948_6B07_4C4B_B0E2_C5FCAB9109A9__INCLUDED_)
