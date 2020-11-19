#include "testlib.h"
using namespace std;

const int N = 2e5+100, MAXM = 1e9;

int a[N], b[N];

int main(int argc, char * argv[])
{
	registerChecker("mls", argc, argv);
	int n = inf.readInt();
	for(int i=1 ; i<=n ; i++)
		a[i] = inf.readInt();
	
	int jans = ans.readInt();
	if(jans == -1){
		int d = ouf.readInt(-10, 10);
		if(d == -1)
			quitf(_ok, "ok.");
		else
			quitf(_wa, "there is no heap with conditions.");
	}

	for(int i=1 ; i<=n ; i++)
		b[i] = ouf.readInt(1, MAXM);
	
	for(int i=1 ; i<=n ; i++)
		if(a[i] > 0 && a[i] != b[i])
			quitf(_wa, "You should not change fixed nodes.");
	bool f = true;
	for(int i=1 ; i<=n ; i++){
		auto ch = [&](int ind){
			if(ind <= n)
				f &= (b[i] > b[ind]);
		};
		ch(2*i);
		ch(2*i+1);
	}
	if(!f)
		quitf(_wa, "Ouput is not a heap.");
	quitf(_ok, "ok.");
}
