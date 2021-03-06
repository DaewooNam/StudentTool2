
// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 및 프로젝트 관련 포함 파일이 
// 들어 있는 포함 파일입니다.

#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // 일부 CString 생성자는 명시적으로 선언됩니다.

// MFC의 공통 부분과 무시 가능한 경고 메시지에 대한 숨기기를 해제합니다.
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC 핵심 및 표준 구성 요소입니다.
#include <afxext.h>         // MFC 확장입니다.


#include <afxdisp.h>        // MFC 자동화 클래스입니다.





#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // Internet Explorer 4 공용 컨트롤에 대한 MFC 지원입니다.
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>             // Windows 공용 컨트롤에 대한 MFC 지원입니다.
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxcontrolbars.h>     // MFC의 리본 및 컨트롤 막대 지원









#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif


#include<list>
#include <afxcontrolbars.h>
using namespace std;



#include "Resource.h" //STudent ID 값을 받기 위해


// 비트 연산
#define SUBJECT_C       0x01 //0x 16진수 2개값이 1byte
#define SUBJECT_JAVA    0x02
#define SUBJECT_SERVER  0x04
#define SUBJECT_DB      0x08




// 정보 값 memory에 할당 되지 않음
struct StudentData
{
	CString name;
	int age;
	int sex;
	BYTE subjects; // 비트 연산? 메모리 소비가 심해 질 수 있음, 이전 library 값들이 bite 연산으로 사용

};

#include "StudentInfoDlg.h" // 이 값이 여기 있어야 위에 값들을 받을 수 있음
#include "StudentVieDlg.h"
#include <afxcontrolbars.h>



//head에서 선언시 (선언이라는 것은 memory 가 할당됨 (변수값들))
//어딘가에 이 파일이 있으니깐 사용 memory 공통header는 extern 을 달아주게 된다.
// extern 이 붙으면 선언이 아니다.

extern list<StudentData*>		g_listStudents; 
extern StudentInfoDlg			g_StudentInfoDlg;
extern StudentVieDlg			g_StudentViewDlg;


