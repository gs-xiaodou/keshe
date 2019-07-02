
// Keyword_Extraction_EntropyDlg.h : ͷ�ļ�
//

#pragma once


// CKeyword_Extraction_EntropyDlg �Ի���
class CKeyword_Extraction_EntropyDlg : public CDialogEx
{
// ����
public:
	CKeyword_Extraction_EntropyDlg(CWnd* pParent = NULL);	// ��׼���캯��
	
// �Ի�������
	enum { IDD = IDD_KEYWORD_EXTRACTION_ENTROPY_DIALOG };
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CString m_txtaddress;
	afx_msg void OnBnClickedKeywordsave();
	afx_msg void OnBnClickedButton2();
//	CString m_txtorigin;
	afx_msg void OnBnClickedPretreament();
	afx_msg LRESULT OnMyMessage(WPARAM wParam, LPARAM lParam); 


	afx_msg void OnBnClickedKeywordextr();
	afx_msg void OnBnClickedQuick();
	CListCtrl m_keywordshow;
	afx_msg void OnEnChangeEdit1();
	CWinThread* pThread;

	
//	afx_msg void OnUpdateWizfinish(CCmdUI *pCmdUI);
	CRichEditCtrl m_richedit;
	CRichEditCtrl m_status;
	afx_msg void OnBnClickedStopword();
//	afx_msg void OnNMClickKeyword(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton3();
	afx_msg void OnEnChangeRichedit21();
	afx_msg void OnLvnItemchangedKeyword(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnEnChangeEdit2();
};
