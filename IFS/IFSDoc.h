// IFSDoc.h : interface of the CIFSDoc class
//


#pragma once


class CIFSDoc : public CDocument
{
protected: // create from serialization only
	CIFSDoc();
	DECLARE_DYNCREATE(CIFSDoc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Implementation
public:
	virtual ~CIFSDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};


