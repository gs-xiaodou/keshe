
// Keyword_Extraction_EntropyDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Keyword_Extraction_Entropy.h"
#include "Keyword_Extraction_EntropyDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CKeyword_Extraction_EntropyDlg �Ի���




CKeyword_Extraction_EntropyDlg::CKeyword_Extraction_EntropyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CKeyword_Extraction_EntropyDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_txtaddress = _T("");
	//  m_txtorigin = _T("");
}

void CKeyword_Extraction_EntropyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_txtaddress);
	//  DDX_Text(pDX, IDC_TXTORIGIN, m_txtorigin);
	DDX_Control(pDX, IDC_KEYWORD, m_keywordshow);

	DDX_Control(pDX, IDC_RICHEDIT21, m_richedit);
	DDX_Control(pDX, IDC_RICHEDIT22, m_status);
}

BEGIN_MESSAGE_MAP(CKeyword_Extraction_EntropyDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CKeyword_Extraction_EntropyDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_KEYWORDSAVE, &CKeyword_Extraction_EntropyDlg::OnBnClickedKeywordsave)
	ON_BN_CLICKED(IDC_BUTTON2, &CKeyword_Extraction_EntropyDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_PRETREAMENT, &CKeyword_Extraction_EntropyDlg::OnBnClickedPretreament)
	ON_BN_CLICKED(IDC_KEYWORDEXTR, &CKeyword_Extraction_EntropyDlg::OnBnClickedKeywordextr)
	ON_BN_CLICKED(IDC_QUICK, &CKeyword_Extraction_EntropyDlg::OnBnClickedQuick)
	ON_EN_CHANGE(IDC_EDIT1, &CKeyword_Extraction_EntropyDlg::OnEnChangeEdit1)
//	ON_UPDATE_COMMAND_UI(ID_WIZFINISH, &CKeyword_Extraction_EntropyDlg::OnUpdateWizfinish)
	 ON_MESSAGE(WM_MyMessage, OnMyMessage)
	 ON_BN_CLICKED(IDC_STOPWORD, &CKeyword_Extraction_EntropyDlg::OnBnClickedStopword)
//	 ON_NOTIFY(NM_CLICK, IDC_KEYWORD, &CKeyword_Extraction_EntropyDlg::OnNMClickKeyword)
ON_BN_CLICKED(IDC_BUTTON3, &CKeyword_Extraction_EntropyDlg::OnBnClickedButton3)
ON_EN_CHANGE(IDC_RICHEDIT21, &CKeyword_Extraction_EntropyDlg::OnEnChangeRichedit21)
ON_NOTIFY(LVN_ITEMCHANGED, IDC_KEYWORD, &CKeyword_Extraction_EntropyDlg::OnLvnItemchangedKeyword)
ON_EN_CHANGE(IDC_EDIT2, &CKeyword_Extraction_EntropyDlg::OnEnChangeEdit2)
END_MESSAGE_MAP()


// CKeyword_Extraction_EntropyDlg ��Ϣ�������

BOOL CKeyword_Extraction_EntropyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	CHARFORMAT cf;
	ZeroMemory(&cf, sizeof(CHARFORMAT));
	cf.cbSize = sizeof(CHARFORMAT);
	cf.dwMask = CFM_BOLD | CFM_COLOR | CFM_FACE |
		CFM_ITALIC | CFM_SIZE | CFM_UNDERLINE;
	cf.dwEffects = 0;
	cf.yHeight = 12*12;//���ָ߶�
	cf.crTextColor = RGB(200, 100, 255); //������ɫ
	m_richedit.SetBackgroundColor(0,RGB(240,247,233));
	m_richedit.SetSel(1, 5); //���ô�������
	m_richedit.SetSelectionCharFormat(cf);


	
	m_status.SetBackgroundColor(0,RGB(240,247,233));
	m_status.SetSel(1, 5); //���ô�������
	m_status.SetSelectionCharFormat(cf);





	WORD dwStyle = m_keywordshow.GetExtendedStyle();                    //����б��������ߣ�����

	dwStyle |= LVS_EX_FULLROWSELECT;            
	dwStyle |= LVS_EX_GRIDLINES;   


	m_keywordshow.SetExtendedStyle(dwStyle);
	m_keywordshow.SetBkColor(RGB(240,247,233));             //ѡ�д����ǵ���ɫ
	m_keywordshow.SetTextBkColor(RGB(240,247,233));

	m_keywordshow.InsertColumn(0,_T("���"),LVCFMT_CENTER,37);
	m_keywordshow.InsertColumn(1,_T("����"),LVCFMT_CENTER,80);
	m_keywordshow.InsertColumn(2,_T("EDnor"),LVCFMT_CENTER,80);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CKeyword_Extraction_EntropyDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CKeyword_Extraction_EntropyDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CKeyword_Extraction_EntropyDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strFilter = _T("Data Files (*.txt)|*.txt||");
	CFileDialog fileDlg(
		true,//��Ϊtrue�������������һ�����ļ��Ի�����ΪFalse�򴴽�����һ�������ļ��Ի���
		NULL,//��ӵ�û����չ���ļ��ϵ���չ��
		_T(""),//��ʼѡ�����ļ���
		NULL,//�Ƿ񴴽�������ʾ��ı����ļ��Ի���
		strFilter//files of type �еĹ��˲���
		);
	int result = fileDlg.DoModal();//����һ�����ļ��Ի���

	if(result == IDOK)//����û����OK��ť
	{	string address;
	    address=change(fileDlg.GetFolderPath());
		if (address[address.size()-1]=='\\')
		{
			address=address+change(fileDlg.GetFileName());
		}
		else 
			address=address+"\\"+change(fileDlg.GetFileName());
		
		m_txtaddress=address.c_str();

	UpdateData(false);//������༭������ĳ�Ա����m_openFileName��ֵ
	GetDlgItem(IDC_EDIT1)->SetWindowText(m_txtaddress);//��m_openFileName��������ʾ�ڱ༭����


	//CClientDC dc(this);
	//CRect rc;
	//GetClientRect(&rc); //��õ�ǰ�Ի����rc
	////��ʼ�����
	//MoveToEx(dc, 50,540, NULL);
	//LineTo(dc,602, 540);
	//MoveToEx(dc, 50,540, NULL);
	//LineTo(dc,50, 600);
	//MoveToEx(dc, 50,600, NULL);
	//LineTo(dc,601, 600);
	//MoveToEx(dc, 601,600, NULL);
	//LineTo(dc,601, 540);
	}
}


void CKeyword_Extraction_EntropyDlg::OnBnClickedKeywordsave()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strFilter = _T("Data Files (*.txt)|*.txt||");
	CFileDialog fileDlg(
		false,//��Ϊtrue�������������һ�����ļ��Ի�����ΪFalse�򴴽�����һ�������ļ��Ի���
		NULL,//��ӵ�û����չ���ļ��ϵ���չ��
		_T(""),//��ʼѡ�����ļ���
		NULL,//�Ƿ񴴽�������ʾ��ı����ļ��Ի���
		strFilter//files of type �еĹ��˲���
		);
	int result = fileDlg.DoModal();//����һ�����ļ��Ի���

	if(result == IDOK)//����û����OK��ť
	{string address;
	address=change(fileDlg.GetFolderPath());
	if (address[address.size()-1]=='\\')
	{
		address=address+change(fileDlg.GetFileName());
	}
	else 
		address=address+"\\"+change(fileDlg.GetFileName());

	savekeyword(address);
	m_status.SetWindowText(_T("�ؼ��ʱ���ɹ���"));
	
	}	
}


void CKeyword_Extraction_EntropyDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	
	string doc_address=change(m_txtaddress);
	string origintext=LoadDoc(doc_address);
	if(!origintext.empty())
	{doc=origintext;
	doc_pretreament=origintext;
	m_status.SetWindowText(_T("txt��ȡ�ɹ���"));
	GetDlgItem(IDC_KEYWORDEXTR)->EnableWindow(TRUE);
	GetDlgItem(IDC_PRETREAMENT)->EnableWindow(TRUE);
	GetDlgItem(IDC_QUICK)->EnableWindow(TRUE);

	CString strText;
	
	strText=doc.c_str();
	m_richedit.SetWindowText(strText );
	//InvalidateRect(NULL, TRUE);
	m_keywordshow.DeleteAllItems();
	}
	else
		m_status.SetWindowText(_T("�����·�������txt��û�����ݣ����������룡"));
	
}


void CKeyword_Extraction_EntropyDlg::OnBnClickedPretreament()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	doc_pretreament=pre_treatment(doc);
	m_status.SetWindowText(_T("Ԥ������ɣ�"));
}


void CKeyword_Extraction_EntropyDlg::OnBnClickedKeywordextr()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_status.SetWindowText(_T("���ڽ��йؼ�����ȡ�������ĵȴ���һƪ19�������£���2��4���ӣ�"));
	UpdateData(TRUE);
	
	GetDlgItem(IDC_KEYWORDEXTR)->EnableWindow(FALSE);
	GetDlgItem(IDC_PRETREAMENT)->EnableWindow(FALSE);
	GetDlgItem(IDC_STOPWORD)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
	GetDlgItem(IDC_QUICK)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
	GetDlgItem(IDC_QUICK)->EnableWindow(FALSE);
	GetDlgItem(IDC_KEYWORDSAVE)->EnableWindow(FALSE);
	m_keywordshow.DeleteAllItems();
	pThread=AfxBeginThread(ThreadFunc,0,0,0,NULL);

	
	
}


void CKeyword_Extraction_EntropyDlg::OnBnClickedQuick()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	m_status.SetWindowText(_T("���ڽ��йؼ�����ȡ�������ĵȴ���һƪ19�������£���2��4���ӣ�"));
	UpdateData(TRUE);

	GetDlgItem(IDC_KEYWORDEXTR)->EnableWindow(FALSE);
	GetDlgItem(IDC_PRETREAMENT)->EnableWindow(FALSE);
	GetDlgItem(IDC_STOPWORD)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
	GetDlgItem(IDC_QUICK)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
	GetDlgItem(IDC_QUICK)->EnableWindow(FALSE);
	GetDlgItem(IDC_KEYWORDSAVE)->EnableWindow(FALSE);

	m_keywordshow.DeleteAllItems();
	pThread=AfxBeginThread(ThreadFunc1,0,0,0,NULL);
	
	
}


void CKeyword_Extraction_EntropyDlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�
	UpdateData(TRUE);
	string address=change(m_txtaddress);
	 if (address.empty())
	 {
		 GetDlgItem(IDC_KEYWORDEXTR)->EnableWindow(FALSE);
		 GetDlgItem(IDC_PRETREAMENT)->EnableWindow(FALSE);
		 GetDlgItem(IDC_STOPWORD)->EnableWindow(FALSE);
		 GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
		 GetDlgItem(IDC_QUICK)->EnableWindow(FALSE);
	 }
	 else 
	 GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
	 
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


//void CKeyword_Extraction_EntropyDlg::OnUpdateWizfinish(CCmdUI *pCmdUI)
//{
//	// TODO: �ڴ������������û����洦��������
//	
//}

LRESULT CKeyword_Extraction_EntropyDlg::OnMyMessage(WPARAM wParam, LPARAM lParam)
{
	//MessageBox("recv msg success");
	//����Լ�����Ϣ����
	int i=0;
	CString str;
	vector<Node> result_show=getresult();
	
    for(i=0;i<result_show.size();i++){
		str.Format(_T("%d"),i+1);
		m_keywordshow.InsertItem(i,str);

		str=result_show[i].word.c_str();
		m_keywordshow.SetItemText(i,1,str);

		str.Format(_T("%lf"),result_show[i].EDnor);
		m_keywordshow.SetItemText(i,2,str);
	}
	m_status.SetWindowText(_T("�ؼ�����ȡ��ɣ�"));
	GetDlgItem(IDC_KEYWORDEXTR)->EnableWindow(TRUE);
	GetDlgItem(IDC_PRETREAMENT)->EnableWindow(TRUE);
	GetDlgItem(IDC_STOPWORD)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
	GetDlgItem(IDC_QUICK)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
	GetDlgItem(IDC_QUICK)->EnableWindow(TRUE);
	GetDlgItem(IDC_KEYWORDSAVE)->EnableWindow(TRUE);
	return 0;    
}

void CKeyword_Extraction_EntropyDlg::OnBnClickedStopword()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	vector<Node> delet_result;

	CString strFilter = _T("Data Files (*.txt)|*.txt||");
	CFileDialog fileDlg(
		true,//��Ϊtrue�������������һ�����ļ��Ի�����ΪFalse�򴴽�����һ�������ļ��Ի���
		NULL,//��ӵ�û����չ���ļ��ϵ���չ��
		_T(""),//��ʼѡ�����ļ���
		NULL,//�Ƿ񴴽�������ʾ��ı����ļ��Ի���
		strFilter//files of type �еĹ��˲���
		);
	int result = fileDlg.DoModal();//����һ�����ļ��Ի���

	if(result == IDOK)//����û����OK��ť
	{	string address;
	address=change(fileDlg.GetFolderPath());
	if (address[address.size()-1]=='\\')
	{
		address=address+change(fileDlg.GetFileName());
	}
	else 
		address=address+"\\"+change(fileDlg.GetFileName());
  

	int tag=delet_stopword(address,delet_result);
	if(tag==1) 
	{   
		m_keywordshow.DeleteAllItems();
		CString str;
		for(int i=0;i<delet_result.size();i++){
			str.Format(_T("%d"),i+1);
			m_keywordshow.InsertItem(i,str);

			str=delet_result[i].word.c_str();
			m_keywordshow.SetItemText(i,1,str);

			str.Format(_T("%lf"),delet_result[i].EDnor);
			m_keywordshow.SetItemText(i,2,str);
		}
		m_status.SetWindowText(_T("ͣ�ô�ȥ���ɹ���"));
	}
	   else
	   m_status.SetWindowText(_T("�����·�������txt��û�����ݣ����������룡"));
    }
}

//void CKeyword_Extraction_EntropyDlg::OnNMClickKeyword(NMHDR *pNMHDR, LRESULT *pResult)
//{
//	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
//	// TODO: �ڴ���ӿؼ�֪ͨ����������
//	POSITION pos=m_ClusterAll.GetFirstSelectedItemPosition();
//
//	if(pos!=NULL){
//		int tag=(int)m_ClusterAll.GetNextSelectedItem(pos);
//		vector<Node> result_show;
//		result_show=getresult();
//		result_show[tag]
//	}
//	*pResult = 0;
//}


void CKeyword_Extraction_EntropyDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	char word[96][50];
	char key[100][50];
	int number1, number2;
	float b1 = 0, b2 = 0, b3 = 0, b4 = 0, b5 = 0;
	float g;

	FILE* fp = fopen("ciku.txt", "r");
	FILE* fp1 = fopen("key.txt", "r");

	if (fp1 == NULL || fp == NULL)
	{
		perror("file");
		exit(1);
	}

	for (number1 = 0; number1 < 96; number1++) {
		fscanf(fp, "%s", word[number1]);
	}



	for (number2 = 0; number2 < 100; number2++) {
		fscanf(fp1, "%s", key[number2]);
	}
	int i = 0, j = 0,count=0;
	for (number2 = 0; number2 < 100; number2++) {
		for (number1 = 0; number1 < 96; number1++) {
			i = 0;
			j = 0;
			count = 0;
			float a, b;
			while (word[number1][i] != '\0') {
				j = 0;
				while (key[number2][j] != '\0') {
					if (word[number1][i] == key[number2][j] && word[number1][i + 1] == key[number2][j + 1]) {
						count++;
					}
					j = j + 2;
				}
				i = i + 2;
			}
			a = count / (i / 2);
			b = count / (j / 2);
			if (a > b) {
				g = a;
			}
			else {
				g = b;
			}

			if (g>=0.75) {
				float b = 0;
				if (0 <= number2 && number2 < 20)
					b = 0.02;
				else if (20 <= number2 < 60)
					b = 0.01;
				else if (60 <= number2 < 100)
					b = 0.005;

				if (0 <= number1 && number1 < 21)
					b1 = b1 + b;
				else if (21 <= number1 && number1 < 34)
					b2 = b2 + b;
				else if (34 <= number1 && number1 < 47)
					b3 = b3 + b;
				else if (47 <= number1 && number1 < 67)
					b4 = b4 + b;
				else if (67 <= number1 && number1 < 96)
					b5 = b5 + b;


				//printf("%s\n",key[number2]);
				break;
			}
		}
	}
	/*char* pszFileName = "key.txt";

	CStdioFile myFile;

	CFileException fileException;

	if (myFile.Open(pszFileName, CFile::typeText | CFile::modeReadWrite), &fileException)

	{

		myFile.SeekToBegin();

		CString str1;

		myFile.ReadString(str1);

		CString str2;

		myFile.ReadString(str2);

		AfxMessageBox(str1 + str2);

	}

	else

	{

		TRACE("Can't open file %s,error=%u\n", pszFileName, fileException.m_cause);

	}

	myFile.Close();*/
	CString s1,s2,s3,s4,s5;
	/*float b1 = 0.01;
	float b2 = 0.02;
	float b3 = 0.03;
	float b4 = 0.04;
	float b5 = 0.05;*/

	/*s1= _T("��ȷ��\n");
	s2 = _T("��׳��\n");
	s3 = _T("�ɿ���\n");
	s4 = _T("����\n");
	s5 = _T("�ɲ�����\n");*/
	s1.Format(_T("��ȷ�ԣ�%.3f  ��׳�ԣ�%.3f  �ɿ���:%.3f  ���ܣ�%.3f  �ɲ����ԣ�%.3f"),b1/(b1+b2+b3+b4+b5),b2 / (b1 + b2 + b3 + b4 + b5),b3 / (b1 + b2 + b3 + b4 + b5),b4 / (b1 + b2 + b3 + b4 + b5),b5 / (b1 + b2 + b3 + b4 + b5));
	GetDlgItem(IDC_EDIT2)->SetWindowText(s1);
	/*GetDlgItem(IDC_EDIT2)->SetWindowText(s2);
	GetDlgItem(IDC_EDIT2)->SetWindowText(s3);
	GetDlgItem(IDC_EDIT2)->SetWindowText(s4);
	GetDlgItem(IDC_EDIT2)->SetWindowText(s5);*/

	//printf("��ȷ��  %.2f\n��׳��  %.2f\n�ɿ���  %.2f\n����  %.2f\n�ɲ����� %.2f\n", b1, b2, b3, b4, b5);
	//fclose(fp);
	//fclose(fp1);
	//return ;
}

	


void CKeyword_Extraction_EntropyDlg::OnEnChangeRichedit21()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CKeyword_Extraction_EntropyDlg::OnLvnItemchangedKeyword(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}


void CKeyword_Extraction_EntropyDlg::OnEnChangeEdit2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
