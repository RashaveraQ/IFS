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
	ON_WM_TIMER()
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()

// CIFSView construction/destruction

// Pteridophyte
const double M[4][2][3] = {
		  0   ,     0, 0,   0   , 0.16, 0   ,
		  0.2 , -0.26, 0,   0.23, 0.22, 1.6 ,
		 -0.15,  0.28, 0,   0.26, 0.24, 0.44,
		  0.85,  0.04, 0,  -0.04, 0.85, 1.6 };

CIFSView::CIFSView()
{
	srand((unsigned)time(NULL));
	count = 0;
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

int CIFSView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO:  Add your specialized creation code here
	return 0;
}

void CIFSView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	if (cx > 0 && cy > 0) {
		HDC	hdc = ::GetDC(m_hWnd);
		HBITMAP hBitmap = CreateCompatibleBitmap(hdc, cx, cy);
		hMemDC = CreateCompatibleDC(hdc);
		::ReleaseDC(m_hWnd, hdc);
		SelectObject(hMemDC, hBitmap);
		DeleteObject(hBitmap);
		SetTimer(1, 1, NULL);
	}
}

// CIFSView message handlers
void CIFSView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	if (!count--) {
		count = 30;

		memcpy(&m[0][0][0], &M[0][0][0], 24 * sizeof(double));
		for (int t = 0; t < 4; t++) {
			for (int r = 0; r < 2; r++) {
				for (int c = 0; c < 3; c++) {
					v[t][r][c] = (((double)rand() / RAND_MAX) - 0.5) / 100;
				}
			}
		}
	}

	for (int t = 0; t < 4; t++) {
		for (int r = 0; r < 2; r++) {
			for (int c = 0; c < 3; c++) {
				m[t][r][c] += v[t][r][c];
			}
		}
	}

	Invalidate(FALSE);

	CView::OnTimer(nIDEvent);
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

	SelectObject(hMemDC, GetStockObject(WHITE_BRUSH));
	Rectangle(hMemDC, 0, 0, w, h);

	// TODO: add draw code for native data here
	for (int j = 0; j < 1000; j++) {
		P p = {0,0};
		for (int i = 0; i < 40; i++) {
			IFS(p);
			SetPixel(hMemDC, w / 2 + 50 * p.x, h - 50 * p.y, 0);
		}
	}

	BitBlt(pDC->m_hDC,0,0,w,h,hMemDC,0,0,SRCCOPY);
}

void CIFSView::IFS(P& p)
{
	int r = rand() % 100;
	int t = (r < 1) ? 0 : (r < 8) ? 1 : (r < 15) ? 2 : 3;
	double x = p.x;
	p.x = m[t][0][0] * x + m[t][0][1] * p.y + m[t][0][2];
	p.y = m[t][1][0] * x + m[t][1][1] * p.y + m[t][1][2];
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



