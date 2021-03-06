// StudentInfoDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "StudentTool2.h"
#include "StudentInfoDlg.h"
#include "afxdialogex.h"


// StudentInfoDlg 대화 상자

IMPLEMENT_DYNAMIC(StudentInfoDlg, CDialogEx)

StudentInfoDlg::StudentInfoDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

StudentInfoDlg::~StudentInfoDlg()
{
}

StudentData* StudentInfoDlg::GetStudentInfo(void)
{
	StudentData* pStu = new StudentData;


	pStu->name = GetText(IDC_EDIT_NAME);


	if (GetCheck(IDC_RADIO_MAN))
		pStu->sex = 0;
	else
		pStu->sex = 1;

	//나이
	pStu->age = GetCombo(IDC_COMBO_AGE)->GetCurSel() + 20;


	//관심 과목(c,java,server,DB)

	BYTE btValue = 0;
	BOOL bCheck;


	bCheck = GetCheck(IDC_CHECK_C);
	if (bCheck)
	{
		btValue = btValue | SUBJECT_C; // 비트 연산  비트 값들을 비교해서 그 값이 일치하게 되면 1 일치하지 않으면 0
	}

	bCheck = GetCheck(IDC_CHECK_JAVA);
	if (bCheck)
	{
		btValue = btValue | SUBJECT_JAVA;
	}


	bCheck = GetCheck(IDC_CHECK_SERVER);
	if (bCheck)
	{
		btValue = btValue | SUBJECT_SERVER;
	}

	bCheck = GetCheck(IDC_CHECK_DB);
	if (bCheck)
	{
		btValue = btValue | SUBJECT_DB;
	}

	pStu->subjects = btValue;

	return pStu;


}

void StudentInfoDlg::AddStudent(StudentData * pData) // stl list and combo box data 등록
{
	//list 사용 방법
	// static 값에 몇명인지 확인해줌

	g_listStudents.push_back(pData);



	int nCnt = (int)g_listStudents.size();


	CString str;
	str.Format("%d", nCnt);
	SetText(IDC_STATIC_COUNT, str);




	GetCombo(IDC_COMBO_ADD_NAME)->AddString(pData->name);

}

StudentData * StudentInfoDlg::GetStudentName(CString name)
{
	for (list<StudentData *>::iterator itor = g_listStudents.begin(); itor != g_listStudents.end(); itor++)
	{
		StudentData* p = (*itor);

		if (p->name == name)
		{
			return p;

		}



	}//중간 데이터를 지우기 위해 사용(포인터가 가리키는 값이 주소)


	return NULL; // 오타가 생기는 오류를 막아줌


	/*
	for each(auto p in g_listStudents)
	{

	}//중간에 값을 지우지 못함(포인터가 가리키는 값이 정보)
	*/

	return nullptr;
}

void StudentInfoDlg::UpdateStudentInfo(StudentData * pData)
{
	//이름
	SetText(IDC_EDIT_NAME, pData->name);

	//성별
	if (pData->sex == 1) //d여자
	{
		SetCheck(IDC_RADIO_WOMAN, pData->sex);
		SetCheck(IDC_RADIO_MAN, !pData->sex);

	}
	else
	{
		SetCheck(IDC_RADIO_WOMAN, pData->sex);
		SetCheck(IDC_RADIO_MAN, !pData->sex);
	}
	//나이
	GetCombo(IDC_COMBO_AGE)->SetCurSel(pData->age - 20);

	//관심과목
	SetCheck(IDC_CHECK_C, pData->subjects & SUBJECT_C);
	SetCheck(IDC_CHECK_JAVA, pData->subjects & SUBJECT_JAVA);
	SetCheck(IDC_CHECK_SERVER, pData->subjects & SUBJECT_SERVER);
	SetCheck(IDC_CHECK_DB, pData->subjects & SUBJECT_DB);

}

void StudentInfoDlg::DeleteStudent(int idx)
{
	GetCombo(IDC_COMBO_ADD_NAME)->DeleteString(idx);
	
	int nCnt = 0;
	//노드삭제시 증감자는 안에서 꼭
	for (list<StudentData*>::iterator itor= g_listStudents.begin();itor != g_listStudents.end();)//dele 증감자 없음
	{
		if (nCnt == idx)
		{
			StudentData *p = (*itor);
			delete p;//동적객체 삭제

			//노드삭제
			itor = g_listStudents.erase(itor);
			break;

		}
		else
		{
			nCnt++;
			++itor;

		}
	
	}
}

CString StudentInfoDlg::GetText(DWORD dwID) // text 문자를 얻기 위해 (모든 resource.h 값들)
{
	CString str;

	m_pWinCtrl[dwID - FIRSTINDEX]->GetWindowText(str);


	return str;
}

void StudentInfoDlg::SetText(DWORD dwID, CString str)
{
	m_pWinCtrl[dwID - FIRSTINDEX]->SetWindowText(str);

}

BOOL StudentInfoDlg::GetCheck(DWORD dwID)
{

	return ((CButton*)(m_pWinCtrl[dwID - FIRSTINDEX]))->GetCheck();

}

void StudentInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(StudentInfoDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &StudentInfoDlg::OnBnClickedButtonAdd)
	ON_CBN_SELCHANGE(IDC_COMBO_ADD_NAME, &StudentInfoDlg::OnCbnSelchangeComboAddName)
	ON_BN_CLICKED(IDC_BUTTON_VIEW, &StudentInfoDlg::OnBnClickedButtonView)
END_MESSAGE_MAP()


// StudentInfoDlg 메시지 처리기


BOOL StudentInfoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.


	for (int i = 0; i < IDC_COMBO_ADD_NAME - IDC_EDIT_NAME + 1; i++)
	{
		m_pWinCtrl[i] = GetDlgItem(IDC_EDIT_NAME + i);

		if (m_pWinCtrl[i] == NULL)
		{
			AfxMessageBox("StudentInfoDlg::OnInitDialog() - GetDlgTiem");
		}


	}


	// 콤보 박스 세팅
	CString str;
	for (int i = 20; i <= 40; i++)
	{

		str.Format("%d", i); // int 형 문자를 string 값으로 받게 된다.
		GetCombo(IDC_COMBO_AGE)->AddString(str);

	}

	GetCombo(IDC_COMBO_AGE)->SetCurSel(0); // 콤보 초기값 세팅




	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void StudentInfoDlg::OnBnClickedButtonAdd()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	//AddStudent(GetStudentInfo());
	StudentData* pData = GetStudentInfo();
	AddStudent(pData);
	g_StudentViewDlg.AddStudent(pData);


}


void StudentInfoDlg::OnCbnSelchangeComboAddName()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	int idx = GetCombo(IDC_COMBO_ADD_NAME)->GetCurSel();
	CString str;
	GetCombo(IDC_COMBO_ADD_NAME)->GetLBText(idx, str);

	StudentData* pStu = GetStudentName(str); // List 목록에 이름 찾기

	UpdateStudentInfo(pStu); // data를 control box에 출력

}


void StudentInfoDlg::OnBnClickedButtonView()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	g_StudentViewDlg.ShowWindow(SW_SHOW);
}
