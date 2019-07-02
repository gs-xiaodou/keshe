#include <regex>
#include <fstream>  
#include <sstream>
#include <utility>
#include <algorithm>
#include <vector>
#include <string>
#include <cctype>
#include <set>
#include <queue>

#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS

#include <hash_map>
#include "Term.h"

using namespace std;



#ifdef Keyword_EXPORTS
#define Keyword_API __declspec(dllexport)
#else
#define Keyword_API __declspec(dllimport)
#endif

typedef struct  //����һ���������ĵ����ƶ����еĽṹ
{
	string word;
	double EDnor; 
	int frequency; //��Ҫ��
	vector<int> t_loc; //��Ҫ��
	vector<int> d_list; //��Ҫ��
	
}Node;



Keyword_API Node* keyword_extra_entropy_MAX(string text);
Keyword_API Node* keyword_extra_entropy(string text);
//Keyword_API void Quick_sort(Node ArrayInput[],int nLow,int nHigh);
//Keyword_API int Partition(Node ArrayInput[],int nLow,int nHigh);
//Keyword_API void Swap(Node &p,Node &q);
