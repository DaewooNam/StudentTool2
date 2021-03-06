#pragma once


// StudentInfoDlg 대화 상자

#define FIRSTINDEX IDC_EDIT_NAME // index 계산을 편하게 해주기 위해


class StudentInfoDlg : public CDialogEx
{
	DECLARE_DYNAMIC(StudentInfoDlg)

public:
	StudentInfoDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~StudentInfoDlg();

	CWnd* m_pWinCtrl[IDC_EDIT_NAME - IDC_EDIT_NAME+1]; // GetdlgItem 값을 계속 써주지 않기 위해서 

	StudentData* GetStudentInfo(void); //리소스 데이타 얻기
	void AddStudent(StudentData* pData); // stl list,combobox 저장
	
	StudentData* GetStudentName(CString name); //이름과 같은 학생 정보 얻기
	void UpdateStudentInfo(StudentData* pData);
	void DeleteStudent(int idx);


	//ID 캡션 얻기
	CString GetText(DWORD dwID); // 추가
	void SetText(DWORD dwID, CString str);

	//라디오, 체크박스 상태 얻기
	BOOL GetCheck(DWORD dwID);
	void SetCheck(DWORD dwId, BOOL value)
	{

		((CButton*)(m_pWinCtrl[dwId - FIRSTINDEX]))->SetCheck(value);

	}

	//콤보박스 캐스팅
	CComboBox * GetCombo(DWORD dwID)
	{
		return ((CComboBox *)(m_pWinCtrl[dwID - FIRSTINDEX]));
	}


// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnCbnSelchangeComboAddName();
	afx_msg void OnBnClickedButtonView();
};
