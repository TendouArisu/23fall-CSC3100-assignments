#include<iostream>

using namespace std;

struct store{
	long long edge[2022];
	long long count[2022];
	long long matrix[2022][2022];
};

long long v1,v2,w;
long long n,Mod;
long long sum = 0;

void init(store &Data){
	cin >> n >> Mod;
	int pos = 0;
	long long temp;
	long long list[n];
	while (pos < n){
		cin >> temp;
		list[pos] = temp;
		pos++;
	}
	for (int i = 0; i < n; i++){
	    for (int j = 0; j < n; j++){
	        Data.matrix[i][j] = 1;
	    }
	}
	
	for (int j = 0; j < n; j++){
		for (int k = j+1; k < n; k++){
			v1 = list[j];
			v2 = list[k];
			w = v1*v2;
			w = w%Mod;
			Data.matrix[j][k] = Data.matrix[k][j] = -w;
		}
	}       
	for (int i = 0; i < n; i++){
	    Data.edge[i] = Data.matrix[0][i];
	}
	Data.count[0] = 1;
}

void prim(store &Data){
	long long max,maxpos;
	for (int i = 0; i < n-1; i++){
	    max = 1;
	    for (int j = 0; j < n; j++){
	        if (Data.count[j] == 0 and Data.edge[j] < max){
				maxpos = j;
	            max = Data.edge[j];
	        }
	    }
	    Data.count[maxpos] = 1;
	    sum += Data.edge[maxpos];
	    for (int j = 0; j <= n; j++){
	        if (Data.count[j] == 0 and Data.matrix[maxpos][j] < Data.edge[j]){
	            Data.edge[j] = Data.matrix[maxpos][j];
			}
	    }
	}
}

store Data;
int main()
{
	init(Data);
	prim(Data);
    cout << -sum <<endl;
}