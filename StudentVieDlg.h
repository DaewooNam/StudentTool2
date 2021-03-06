#pragma once


// StudentVieDlg 대화 상자

class StudentVieDlg : public CDialogEx
{
	DECLARE_DYNAMIC(StudentVieDlg)

public:
	StudentVieDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~StudentVieDlg();

	//new function

	void AddStudent(StudentData* pData);

	
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonDel();
};
