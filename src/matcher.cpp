#include "matcher.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>



void comp_prefix(string toSearch, vector<int> & prefix)
{
	int m=toSearch.length();
	prefix[0]=-1;
	int k=-1;
	for (int q=1; q<m; q++) {
		while (k>-1 && toSearch[k+1]!=toSearch[q])
			k = prefix[k];
		if (toSearch[k+1]==toSearch[q]) k=k+1;
		prefix[q]=k;
	}
}

bool kmp_matcher(string text, string toSearch){
	bool found= false;
	int num=0;
	int m=toSearch.length();
	vector<int> prefix(m);
	comp_prefix(toSearch, prefix);

	int n=text.length();

	int q=-1;
	for (int i=0; i<n; i++) {
		while (q>-1 && toSearch[q+1]!=text[i])
			q=prefix[q];
		if (toSearch[q+1]==text[i])
			q++;
		if (q==m-1) {
			//cout <<"pattern occurs with shift" << i-m+1 << endl;
			cout << toSearch <<endl;
			num++;
			found = true;
			q=prefix[q];
		}
	}
	return found;
}

int numStringMatching(string filename, string toSearch){
	ifstream fich(filename.c_str());
	if (!fich)
	{ cout << "Erro a abrir ficheiro de leitura\n"; return 0; }

	string line1, line2;
	int num=0;
	char van;
	bool write = false;
	bool result = false;
	cout << "RESULTADO PESQUISA: " << endl;
	while (!fich.eof()) {
		getline(fich,line1);
		for(int i=0; i<line1.length(); i++){

			if(line1.at(i)=='\{'){
				write=true;
			}else if(line1.at(i)=='\}'){
				write = false;
				if(kmp_matcher(line2,toSearch)){
					cout << "VAN: " << van << endl;
					cout << endl << endl;
					result=true;
					//return -1;
					break;
				}
				line2="";

			}

			if(!write && line1.at(i)!='\{' && line1.at(i)!='\}'){
				van = line1.at(i);
			}else if (write && line1.at(i)!='\{' && line1.at(i)!='\}'){
				line2 += line1.at(i);
			}

		}

	}
	if(!result){
		cout << "Sem Resultados." << endl;
	}

	fich.close();

	return num;
}

int editDistance(string pattern, string text)
{
	int n=text.length();
	vector<int> d(n+1);
	int old,neww;
	for (int j=0; j<=n; j++)
		d[j]=j;
	int m=pattern.length();
	for (int i=1; i<=m; i++) {
		old = d[0];
		d[0]=i;
		for (int j=1; j<=n; j++) {
			if (pattern[i-1]==text[j-1]){
				neww = old;
			}
			else {
				neww = min(old,d[j]);
				neww = min(neww,d[j-1]);
				neww = neww +1;
			}
			old = d[j];
			d[j] = neww;
		}
	}
	return d[n];
}

float numApproximateStringMatching(string filename,string toSearch)
{
	ifstream fich(filename.c_str());
	if (!fich)
	{ cout << "Erro a abrir ficheiro de leitura\n"; return 0; }

	vector<char> van;
	vector<float> result;
	string line1, line2, word1;
	float res;
	//char van;
	bool write = false;
	int num=0, nwords=0;
	cout << "RESULTADO PESQUISA: " << endl;
	while (!fich.eof()) {
		getline(fich,line1);

		for(int i=0; i<line1.length(); i++){

			if(line1.at(i)=='\{'){
				write=true;
			}else if(line1.at(i)=='\}'){
				write = false;
				stringstream s1(line2);
				while (!s1.eof()) {
					s1 >> word1;
					num += editDistance(toSearch,word1);
					nwords++;
				}
				result.push_back((float)num/nwords);
				line2="";
				num=0;
				nwords=0;

			}

			if(!write && line1.at(i)!='\{' && line1.at(i)!='\}'){
				van.push_back(line1.at(i));
			}else if (write && line1.at(i)!='\{' && line1.at(i)!='\}'){
				line2 += line1.at(i);
			}

		}

	}
	fich.close();
	//float res=(float)num/nwords;
	cout << "RES: "<<endl;
	for(int i =0 ; i < van.size(); i++){
		cout << van[i] << endl;
	}
	for(int j =0 ; j < van.size(); j++){
		cout << result[j] << endl;
	}


	return res;
}


