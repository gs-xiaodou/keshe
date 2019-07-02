
// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�

#pragma once

#ifndef _SECURE_ATL
#define _SECURE_ATL 1
#endif

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // �� Windows ͷ���ų�����ʹ�õ�����
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // ĳЩ CString ���캯��������ʽ��

// �ر� MFC ��ĳЩ�����������ɷ��ĺ��Եľ�����Ϣ������
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC ��������ͱ�׼���
#include <afxext.h>         // MFC ��չ


#include <afxdisp.h>        // MFC �Զ�����



#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // MFC �� Internet Explorer 4 �����ؼ���֧��
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>             // MFC �� Windows �����ؼ���֧��
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxcontrolbars.h>     // �������Ϳؼ����� MFC ֧��









#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif

#define WM_MyMessage (WM_USER+100)
#include <iostream>
#include <regex>
#include <fstream>  
#include <sstream>
#include <utility>
#include <algorithm>
#include <string>
#include <cctype>
#include <set>

using namespace std;

typedef struct  //����һ���������ĵ����ƶ����еĽṹ
{
	string word;
	double EDnor; 
	int frequency; //��Ҫ��
	vector<int> t_loc; //��Ҫ��
	vector<int> d_list; //��Ҫ��

}Node;


string LoadDoc(string a);
string pre_treatment(string b);
string change(CString p);
void savekeyword(string address);
UINT ThreadFunc(LPVOID lpParam);
UINT ThreadFunc1(LPVOID lpParam);
int delet_stopword(string address,vector<Node> &delet_result);
vector<Node> getresult();

extern string doc;
extern string doc_pretreament;
extern Node *result;
extern string doc_address;
extern int matix;


#pragma comment (lib,"Keyword_Extraction.lib")
extern Node* keyword_extra_entropy(string text);
extern Node* keyword_extra_entropy_MAX(string text);