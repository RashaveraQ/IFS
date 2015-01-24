// IFSView.h : interface of the CIFSView class
//


#pragma once


class CIFSView : public CView
{
protected: // create from serialization only
	CIFSView();
	DECLARE_DYNCREATE(CIFSView)

// Attributes
public:
	CIFSDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CIFSView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

private:
	struct P {
		double x;
		double y;
	};
	double m[4][2][3];
	double v[4][2][3];
	long count;
	void IFS(P& p);
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

#ifndef _DEBUG  // debug version in IFSView.cpp
inline CIFSDoc* CIFSView::GetDocument() const
   { return reinterpret_cast<CIFSDoc*>(m_pDocument); }
#endif

