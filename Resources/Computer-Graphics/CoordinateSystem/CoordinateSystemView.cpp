// CoordinateSystemView.cpp : implementation of the CCoordinateSystemView class
//

#include "stdafx.h"
#include "CoordinateSystem.h"

#include "CoordinateSystemDoc.h"
#include "CoordinateSystemView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCoordinateSystemView

IMPLEMENT_DYNCREATE(CCoordinateSystemView, CView)

BEGIN_MESSAGE_MAP(CCoordinateSystemView, CView)
	//{{AFX_MSG_MAP(CCoordinateSystemView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCoordinateSystemView construction/destruction

CCoordinateSystemView::CCoordinateSystemView()
{
	// TODO: add construction code here

}

CCoordinateSystemView::~CCoordinateSystemView()
{
}

BOOL CCoordinateSystemView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCoordinateSystemView drawing

void CCoordinateSystemView::OnDraw(CDC* pDC)
{
	CCoordinateSystemDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	CRect rect;//�����ͻ�������
	GetClientRect(&rect);//��ÿͻ�������

	int height=(int)rect.Height()*2.5;
	int width=(int)rect.Width()*2.5;
    int i;
	 pDC->SetMapMode(MM_LOMETRIC);  //����ӳ��ģʽΪ��MM_LOMETRIC����ÿ���߼����걻ת��Ϊ0.1 mm����x���ң���y���ϡ�
	 pDC->SetWindowExt(width,height); //���ô���

	 pDC->SetViewportExt(width,-height); //x��ˮƽ���ң�y�ᴹֱ����

	 //pDC->SetViewportOrg(width/2,height/2); //�ͻ�������Ϊ����ϵԭ��

	 //��X��
     pDC->MoveTo(0,-height/2);
	 pDC->LineTo(width,-height/2);
	 //��Y��
     pDC->MoveTo(width/2,0);
	 pDC->LineTo(width/2,-height);
     
	 //��X�Ḻ����̶�
	 for( i=0;i<=width/2;i+=100)
	 {
		 pDC->MoveTo(i,-height/2);
		 pDC->LineTo(i,-height/2+70);
	 }
     //��X��������̶�
	 for( i=width/2;i<=width;i+=100)
	 {
		 pDC->MoveTo(i,-height/2);
		 pDC->LineTo(i,-height/2+70);
	 }
     //��y��������̶�
	 for( i=0;i<=height/2;i+=100)
	 {
		 pDC->MoveTo(width/2,i);
		 pDC->LineTo(width/2+70,i);
	 }
     //��X�Ḻ����̶�
	 for( i=-height/2;i<=height;i+=100)
	 {
		 pDC->MoveTo(width/2,-i);
		 pDC->LineTo(width/2+70,-i);
	 }

}

/////////////////////////////////////////////////////////////////////////////
// CCoordinateSystemView printing

BOOL CCoordinateSystemView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCoordinateSystemView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCoordinateSystemView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CCoordinateSystemView diagnostics

#ifdef _DEBUG
void CCoordinateSystemView::AssertValid() const
{
	CView::AssertValid();
}

void CCoordinateSystemView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCoordinateSystemDoc* CCoordinateSystemView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCoordinateSystemDoc)));
	return (CCoordinateSystemDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCoordinateSystemView message handlers
