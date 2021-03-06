// StudentVieDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "StudentTool2.h"
#include "StudentVieDlg.h"
#include "afxdialogex.h"


// StudentVieDlg 대화 상자

IMPLEMENT_DYNAMIC(StudentVieDlg, CDialogEx)

StudentVieDlg::StudentVieDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

StudentVieDlg::~StudentVieDlg()
{
}

void StudentVieDlg::AddStudent(StudentData * pData)
{
	CString str;

	str += pData->name;
	str += "(";

	
	
	if (pData->sex == 0)
		str += "성별:남, ";
	else
		str += "성별:여, ";

	CString age;
	age.Format("나이:%d", pData->age);
	str += age;
	
	str += "과목:";


	if (pData->subjects & SUBJECT_C)
		str += "C언어";

	if (pData->subjects & SUBJECT_JAVA)
		str += "자바";

	if (pData->subjects & SUBJECT_SERVER)
		str += "서버";

	if (pData->subjects & SUBJECT_DB)
		str += "디비";
	if((pData->subjects & SUBJECT_DB)==0 
		&& (pData->subjects & SUBJECT_JAVA) == 0
		&& (pData->subjects & SUBJECT_SERVER) == 0
		&& (pData->subjects & SUBJECT_DB) == 0
		)
	str += "없음";

	str += ")";

	CListBox* pList = (CListBox*)GetDlgItem(IDC_LIST_VIEW);

	
	pList->AddString(str);



}

void StudentVieDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(StudentVieDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_DEL, &StudentVieDlg::OnBnClickedButtonDel)
END_MESSAGE_MAP()


// StudentVieDlg 메시지 처리기


void StudentVieDlg::OnBnClickedButtonDel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int idx = ((CListBox*)GetDlgItem(IDC_LIST_VIEW))->GetCurSel();
	
	((CListBox*)GetDlgItem(IDC_LIST_VIEW))->DeleteString(idx);

	g_StudentInfoDlg.DeleteStudent(idx);

}
