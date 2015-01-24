// IFSView.cpp : implementation of the CIFSView class
//

#include "stdafx.h"
#include "IFS.h"

#include "IFSDoc.h"
#include "IFSView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CIFSView

IMPLEMENT_DYNCREATE(CIFSView, CView)

BEGIN_MESSAGE_MAP(CIFSView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CIFSView construction/destruction

CIFSView::CIFSView()
{
	// TODO: add construction code here

}

CIFSView::~CIFSView()
{
}

BOOL CIFSView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CIFSView drawing

void CIFSView::OnDraw(CDC* pDC)
{
	CIFSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CRect rect;
	GetClientRect(&rect);
	int w = rect.Width();
	int h = rect.Height();

	// TODO: add draw code for native data here
	for (int j = 0; j < 1000; j++) {
		P p = {0,0};
		for (int i = 0; i < 40; i++) {
			IFS(p);
			pDC->SetPixel(w / 2 + 50 * p.x, h - 50 * p.y, 0);
		}
	}
}

void CIFSView::IFS(P& p)
{
	int r = rand() % 100;
	if (r < 1) {
		p.x = 0;
		p.y *= 0.16;
	} else if (r < 8) {
		double x = p.x;
		p.x = 0.2 * x - 0.26 * p.y;
		p.y = 0.23 * x + 0.22 * p.y + 1.6;
	} else if (r < 15) {
		double x = p.x;
		p.x = -0.15 * x + 0.28 * p.y;
		p.y = 0.26 * x + 0.24 * p.y + 0.44;
	} else {
		double x = p.x;
		p.x = 0.85 * x + 0.04 * p.y;
		p.y = -0.04 * x + 0.85 * p.y + 1.6;
	}
}


// CIFSView printing

BOOL CIFSView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CIFSView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CIFSView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CIFSView diagnostics

#ifdef _DEBUG
void CIFSView::AssertValid() const
{
	CView::AssertValid();
}

void CIFSView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CIFSDoc* CIFSView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CIFSDoc)));
	return (CIFSDoc*)m_pDocument;
}
#endif //_DEBUG


// CIFSView message handlers
