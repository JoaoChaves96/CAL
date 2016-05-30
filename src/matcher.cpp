#include "matcher.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>


/**
 * Processing prefix
 */
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

/**
 * Returns TRUE if found a match or False if don't
 */
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
			cout << toSearch <<endl;
			num++;
			found = true;
			q=prefix[q];
		}
	}
	return found;
}

/**
 * Read file, call the function to search and display result
 */
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

/**
 *	Calculate edit distance
 */
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

/**
 * Read file and call the function to search and display result
 */
float numApproximateStringMatching(string filename,string toSearch)
{
	ifstream fich(filename.c_str());
	if (!fich)
	{ cout << "Erro a abrir ficheiro de leitura\n"; return 0; }

	vector<string> sugest;
	vector<float> result;
	string line1, line2, word1, word2, finalSug;
	int res = 0;
	char van;
	bool write = false;
	int num=0;
	cout << "RESULTADO PESQUISA: " << endl << endl;
	while (!fich.eof()) {
		getline(fich,line1);

		for(int i=0; i<line1.length(); i++){

			if(line1.at(i)=='\{'){
				write=true;
			}else if(line1.at(i)=='\}'){
				write = false;
				stringstream s1(line2);
				stringstream s2(toSearch);
				stringstream s3(toSearch);
				while (!s1.eof()) {
					s1 >> word1;
					s2 >> word2;
					num = editDistance(word2,word1);
					res += num;
					finalSug += word1+" ";
					if(s2.eof() && res==0){
						cout << toSearch << endl;
						cout << "VAN: " << van << endl;;
						return 0;
					}
					if(word1[word1.length()-1]==';'){
						result.push_back(res);
						sugest.push_back(finalSug);
						res=0;
						finalSug="";
						s2.clear();
						s2.seekg(0, ios::beg);
					}
				}

				line2="";
				num=0;

			}

			if(!write && line1.at(i)!='\{' && line1.at(i)!='\}'){
				van=line1.at(i);
			}else if (write && line1.at(i)!='\{' && line1.at(i)!='\}'){
				line2 += line1.at(i);
			}

		}

	}
	fich.close();

	int aux, i, j;
	string aux2;

	for(j=result.size()-1; j>=1; j--)
	{
		for(i=0; i<j; i++)
		{
			if(result[i]>result[i+1])
			{
				aux=result[i];
				aux2=sugest[i];
				result[i]=result[i+1];
				sugest[i]=sugest[i+1];
				result[i+1]=aux;
				sugest[i+1]=aux2;

			}
		}
	}

	cout << "Sem Resultados" << endl;
	cout << "Será que quis dizer: " << endl;

	int count =0;
	string finals;
	for(int x=0; x<result.size(); x++){
		finals = sugest[x];
		if(sugest[x] == sugest[x+1]){

		}else{
			finals.erase(remove(finals.begin(), finals.end(), ';'), finals.end());
			cout << finals <<  " - " <<result[x] << endl;
			count++;
		}
		if (count==2){
			break;
		}

	}


	return res;
}


