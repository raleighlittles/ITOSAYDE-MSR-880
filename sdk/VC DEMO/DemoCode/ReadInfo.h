#if !defined(AFX_READINFO_H__D7BE332E_C8D6_4E82_B76C_85AF79198872__INCLUDED_)
#define AFX_READINFO_H__D7BE332E_C8D6_4E82_B76C_85AF79198872__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ReadInfo.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ReadInfo dialog

class ReadInfo : public CDialog
{
// Construction
public:
	ReadInfo(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ReadInfo)
	enum { IDD = IDD_DIALOG7 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ReadInfo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ReadInfo)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_READINFO_H__D7BE332E_C8D6_4E82_B76C_85AF79198872__INCLUDED_)
