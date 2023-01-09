#if !defined(AFX_DIALOG4_H__A0889776_AD17_4C7A_B25B_224F5B3C32A0__INCLUDED_)
#define AFX_DIALOG4_H__A0889776_AD17_4C7A_B25B_224F5B3C32A0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dialog4.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDialog4 dialog

class CDialog4 : public CDialog
{
// Construction
public:
	CDialog4(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDialog4)
	enum { IDD = IDD_DIALOG4 };
	CComboBox	m_list1;
	CComboBox	m_list;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialog4)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialog4)
	virtual BOOL OnInitDialog();
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton4();
	afx_msg void OnButton13();
	afx_msg void OnButton8();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG4_H__A0889776_AD17_4C7A_B25B_224F5B3C32A0__INCLUDED_)
