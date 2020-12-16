#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int N = 500, M = 50000;

char mat[N][N];

int main(int argc , char* argv[]){
	registerValidation(argc, argv);
	int n = inf.readInt(1, N);
	inf.readSpace();
	int m = inf.readInt(1, N);
	inf.readEoln();
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<m ; j++){
			char c = inf.readChar();
			mat[i][j] = c;
			ensuref(c == '.' || c == '#', "grid must be '#' & '.'");
		}
		inf.readEoln();
	}
	int q = inf.readInt(1, M);
	inf.readEoln();
	while(q --){
		int x1 = inf.readInt(1, n);x1 --;
		inf.readSpace();
		int y1 = inf.readInt(1, m);y1 --;
		inf.readSpace();
		int x2 = inf.readInt(1, n);x2 --;
		inf.readSpace();
		int y2 = inf.readInt(1, m);y2 --;
		inf.readEoln();
		ensuref(mat[x1][y1] == '.', "must be .");
		ensuref(mat[x2][y2] == '.', "must be .");
	}
	inf.readEof();
}
