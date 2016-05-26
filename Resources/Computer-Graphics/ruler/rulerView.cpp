// rulerView.cpp : implementation of the CRulerView class
//

#include "stdafx.h"
#include "ruler.h"

#include "rulerDoc.h"
#include "rulerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRulerView

IMPLEMENT_DYNCREATE(CRulerView, CView)

BEGIN_MESSAGE_MAP(CRulerView, CView)
	//{{AFX_MSG_MAP(CRulerView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRulerView construction/destruction

CRulerView::CRulerView()
{
	// TODO: add construction code here

}

CRulerView::~CRulerView()
{
}

BOOL CRulerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CRulerView drawing

void CRulerView::OnDraw(CDC* pDC)
{
	CRulerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CRect rect;   //�����ͻ�������
    GetClientRect(&rect);   //��ÿͻ�������
    pDC->SetMapMode(MM_LOMETRIC);  //����ӳ��ģʽΪ��MM_LOMETRIC����ÿ���߼����걻ת��Ϊ0.1 mm����x���ң���y���ϡ�
    //����ʵ�ʵĿͻ������ڵĳ��ȺͿ�ȷ�Χ
    int height=rect.Height()*2.5;
	int width=rect.Width()*2.5;
    int i;
	
    //top ruler �������ĳ���
	//�������ϲ���һ��ֱ�ߣ���Ϊ���ӵĶ�����Ե�����ϣ�/�����£�/�ң���
	pDC->MoveTo(0,0);  
	pDC->LineTo(width-100,0);
	COLORREF c=RGB(0,0,255);
    //��ʼ����ѭ���������ӵĿ̶�
	for( i=0;i<width-100;i+=10)
	{   
        //���Ӿ���Ϊ1���׵ģ��̶����߳���Ϊ7����
		if(i%100==0)
		{ 
			pDC->MoveTo(i,0);
		    pDC->LineTo(i,-70);
		}
        //���Ӿ���Ϊ5���׵ģ��̶����߳���Ϊ6����
		else if(i%50==0)
		{
            pDC->MoveTo(i,0);
			pDC->LineTo(i,-60);

		}
		//���Ӿ���Ϊ1���׵ģ��̶����߳���Ϊ5����
		else 
		{
			pDC->MoveTo(i,0);
			pDC->LineTo(i,-50);
		}
	}
	//bottom ruler  ���ײ��ĳ���
	//���ڵײ���һ��ֱ�ߣ���Ϊ���ӵĶ�����Ե������/������/�һ���
	pDC->MoveTo(width,-height+100);
	pDC->LineTo(100,-height+100);
    //��ʼ����ѭ���������ӵĿ̶�
	for( i=0;i<width-100;i+=10)
	{    //���Ӿ���Ϊ1���׵ģ��̶����߳���Ϊ7����
		if(i%100==0)
		{ 
			pDC->MoveTo(width-i,-height+100);
		    pDC->LineTo(width-i,-height+30);
		}
		 //���Ӿ���Ϊ5���׵ģ��̶����߳���Ϊ6����
		else if(i%50==0)
		{
            pDC->MoveTo(width-i,-height+100);
			pDC->LineTo(width-i,-height+40);

		}
		//���Ӿ���Ϊ1���׵ģ��̶����߳���Ϊ5����
		else 
		{
			pDC->MoveTo(width-i,-height+100);
			pDC->LineTo(width-i,-height+50);
		}
	}
	//*/

    ///*
	//left ruler  ����ߵĳ���
    //�������󲿻�һ��ֱ�ߣ���Ϊ���ӵĶ�����Ե������/������/�һ���
    pDC->MoveTo(0,-height);
	pDC->LineTo(0,-100);
	//��ʼ����ѭ���������ӵĿ̶�
	for( i=0;i<height-100;i+=10)
	{
		 //���Ӿ���Ϊ1���׵ģ��̶����߳���Ϊ7����
		if(i%100==0)
		{ 
			pDC->MoveTo(0,-height+i);
		    pDC->LineTo(70,-height+i);
		}
		 //���Ӿ���Ϊ5���׵ģ��̶����߳���Ϊ6����
		else if(i%50==0)
		{
            pDC->MoveTo(0,-height+i);
			pDC->LineTo(60,-height+i);

		}
		//���Ӿ���Ϊ1���׵ģ��̶����߳���Ϊ5����
		else 
		{
			pDC->MoveTo(0,-height+i);
			pDC->LineTo(50,-height+i);
		}
	}
	//*/
    //right ruler  ���ұߵĳ���
	//�������ұ߻�һ��ֱ�ߣ���Ϊ���ӵĶ�����Ե���������󻭣�
    pDC->MoveTo(width,0);
	pDC->LineTo(width,-height+150);
	//��ʼ����ѭ���������ӵĿ̶�
	for( i=0;i<height-150;i+=10)
	{   
		 //���Ӿ���Ϊ1���׵ģ��̶����߳���Ϊ7����
		if(i%100==0)
		{ 
			pDC->MoveTo(width,-i);
		    pDC->LineTo(width-70,-i);
		}
		 //���Ӿ���Ϊ5���׵ģ��̶����߳���Ϊ6����
		else if(i%50==0)
		{
            pDC->MoveTo(width,-i);
			pDC->LineTo(width-60,-i);

		}
		//���Ӿ���Ϊ1���׵ģ��̶����߳���Ϊ5����
		else 
		{
			pDC->MoveTo(width,-i);
			pDC->LineTo(width-50,-i);
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
// CRulerView printing

BOOL CRulerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CRulerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CRulerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CRulerView diagnostics

#ifdef _DEBUG
void CRulerView::AssertValid() const
{
	CView::AssertValid();
}

void CRulerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRulerDoc* CRulerView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRulerDoc)));
	return (CRulerDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRulerView message handlers
