
// Keyword_Extraction_Entropy.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CKeyword_Extraction_EntropyApp:
// �йش����ʵ�֣������ Keyword_Extraction_Entropy.cpp
//

class CKeyword_Extraction_EntropyApp : public CWinApp
{
public:
	CKeyword_Extraction_EntropyApp();
	HMODULE m_hRichEdit;

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
	virtual int ExitInstance();
};

extern CKeyword_Extraction_EntropyApp theApp;