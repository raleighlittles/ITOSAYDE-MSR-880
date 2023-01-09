#if !defined(AFX_DIALOG2_H__F347D469_5C93_4BEB_B165_7C264C4F2C45__INCLUDED_)
#define AFX_DIALOG2_H__F347D469_5C93_4BEB_B165_7C264C4F2C45__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dialog2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDialog2 dialog

class CDialog2 : public CDialog
{
// Construction
public:
	CDialog2(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDialog2)
	enum { IDD = IDD_DIALOG2 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialog2)
	public:
	virtual BOOL DestroyWindow();
	virtual CScrollBar* GetScrollBarCtrl(int nBar) const;
	virtual int DoModal();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual LRESULT DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialog2)
	virtual void OnOK();
	afx_msg void OnButton1();
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	virtual BOOL OnInitDialog();
	afx_msg void OnButton2();
	afx_msg void OnStatic1();
	afx_msg void OnButton5();
	afx_msg void OnButton4();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton11();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG2_H__F347D469_5C93_4BEB_B165_7C264C4F2C45__INCLUDED_)
