#if !defined(AFX_DIALOG5_H__09D71238_D5B2_450C_8180_466797F69470__INCLUDED_)
#define AFX_DIALOG5_H__09D71238_D5B2_450C_8180_466797F69470__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dialog5.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDialog5 dialog

class CDialog5 : public CDialog
{
// Construction
public:
	CDialog5(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDialog5)
	enum { IDD = IDD_DIALOG5 };
	CComboBox	m_com5;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialog5)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialog5)
	virtual void OnCancel();
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG5_H__09D71238_D5B2_450C_8180_466797F69470__INCLUDED_)
