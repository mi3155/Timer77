
// Timer77View.cpp: CTimer77View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Timer77.h"
#endif

#include "Timer77Doc.h"
#include "Timer77View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTimer77View

IMPLEMENT_DYNCREATE(CTimer77View, CView)

BEGIN_MESSAGE_MAP(CTimer77View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CTimer77View 생성/소멸

CTimer77View::CTimer77View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CTimer77View::~CTimer77View()
{
}

BOOL CTimer77View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CTimer77View 그리기

void CTimer77View::OnDraw(CDC* /*pDC*/)
{
	CTimer77Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CTimer77View 인쇄

BOOL CTimer77View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CTimer77View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CTimer77View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CTimer77View 진단

#ifdef _DEBUG
void CTimer77View::AssertValid() const
{
	CView::AssertValid();
}

void CTimer77View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTimer77Doc* CTimer77View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTimer77Doc)));
	return (CTimer77Doc*)m_pDocument;
}
#endif //_DEBUG


// CTimer77View 메시지 처리기


void CTimer77View::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	SetTimer(1, 500, NULL);
	SetTimer(2, 100, NULL);
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
}


void CTimer77View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);
	CFont f;
	f.CreatePointFont(500, L"굴림");
	dc.SelectObject(&f);
	if (nIDEvent == 1) {
		static int n1; // 자동으로 0으로 초기화 시켜줌 
		CString str;
		str.Format(L"%d", ++n1);
		dc.TextOut(10, 100, str);
	}
	if (nIDEvent == 2) {
		static int n2; // 자동으로 0으로 초기화 시켜줌 
		CString str;
		str.Format(L"%d", ++n2);
		dc.TextOut(100, 100, str);
	}
	CView::OnTimer(nIDEvent);
}
