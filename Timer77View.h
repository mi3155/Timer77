
// Timer77View.h: CTimer77View 클래스의 인터페이스
//

#pragma once


class CTimer77View : public CView
{
protected: // serialization에서만 만들어집니다.
	CTimer77View() noexcept;
	DECLARE_DYNCREATE(CTimer77View)

// 특성입니다.
public:
	CTimer77Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CTimer77View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // Timer77View.cpp의 디버그 버전
inline CTimer77Doc* CTimer77View::GetDocument() const
   { return reinterpret_cast<CTimer77Doc*>(m_pDocument); }
#endif

