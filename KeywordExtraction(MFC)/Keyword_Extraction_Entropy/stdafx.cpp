
// stdafx.cpp : ֻ������׼�����ļ���Դ�ļ�
// Keyword_Extraction_Entropy.pch ����ΪԤ����ͷ
// stdafx.obj ������Ԥ����������Ϣ

#include "stdafx.h"

string doc;
string doc_pretreament;
Node *result;
string doc_address;
int matix=0;


string LoadDoc(string address){
	string s="";
	filebuf *pbuf;  
	ifstream filestr;  
	long size;  
	char * buffer;  
	// Ҫ���������ļ���������ö����ƴ�   
	filestr.open (address,ios::binary);  //TheOriginofSpeciesv6_rvPun
	if (!filestr)
	return s;
	
	// ��ȡfilestr��Ӧbuffer�����ָ��   
	pbuf=filestr.rdbuf();  

	// ����buffer���󷽷���ȡ�ļ���С  
	size=pbuf->pubseekoff (0,ios::end,ios::in);  
	pbuf->pubseekpos (0,ios::in);  

	// �����ڴ�ռ�  
	buffer=new char[size+1];  

	// ��ȡ�ļ�����  
	pbuf->sgetn (buffer,size);  
	buffer[size]='\0';
	filestr.close();  
	// �������׼���  

	string text=buffer;

	return text;
}

string pre_treatment(string text){
	
	regex pattern1("\\s{2,}");
	regex pattern2("[0 1 2 3 4 5 6 7 8 9 ��������������������������������(),.:'';!&#?\"]");
	

	text=regex_replace(text,pattern2,string(" "));
	//text=regex_replace(text,pattern3,string(" "));
	
text=regex_replace(text,pattern1,string(" "));

	return text;

}

string change(CString p){
	string text;
	wchar_t *a;
	char address[2000];
	a=p.GetBuffer(p.GetLength());
	WideCharToMultiByte(CP_ACP, 0, a, -1, address, sizeof(address), NULL, NULL);

	text=address;
	return text;
}


UINT ThreadFunc(LPVOID lpParam)
{

	result=keyword_extra_entropy_MAX(doc_pretreament);
	SendMessage(AfxGetMainWnd()->GetSafeHwnd(),WM_MyMessage, 0, 0);
	matix=1;
	return 0;
}

UINT ThreadFunc1(LPVOID lpParam)
{

	result=keyword_extra_entropy(doc_pretreament);
	SendMessage(AfxGetMainWnd()->GetSafeHwnd(),WM_MyMessage, 0, 0);
	matix=1;
	return 0;
}
void savekeyword(string address){

	int i=0;
	ofstream fout(address);
	while(!result[i].word.empty())
	{
     fout <<result[i].word<<"-"<<result[i].EDnor<<endl;
	 i++;
	}

}

int delet_stopword(string address,vector<Node> &delet_result){
	set<string> excluded_word;
	string stopword;

	ifstream stopwordfile;
	stopwordfile.open(address);
	if (!stopwordfile)  return -1;
	while (stopwordfile >> stopword)
		excluded_word.insert(stopword);
	stopwordfile.close();

	Node q;
	//vector<Node> P;
	int i=0;
	while(result[i].EDnor>0)
	{  
		if(!excluded_word.count(result[i].word))
		{
			q.word=result[i].word;
			q.EDnor=result[i].EDnor;
			delet_result.push_back(q);
		}
		i++;
	}

	result=new Node[delet_result.size()];
	for(i=0;i<delet_result.size();i++){
		result[i].word=delet_result[i].word;
		result[i].EDnor=delet_result[i].EDnor;
	}

	return 1;

}


vector<Node> getresult(){
	int i=0;
	Node p;
	vector<Node> result_show;
	while(result[i].EDnor>0){
		p.word=result[i].word;
		p.EDnor=result[i].EDnor;
		result_show.push_back(p);
		i++;

	}

	return result_show;
}