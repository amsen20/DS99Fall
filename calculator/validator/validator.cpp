#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

typedef pair<int, int> ii;

const int N = 3e5;

bool is_dig(char c){
    return (c <= '9' && c >= '0');
}

bool is_paran(char c){
    return (c == '(' || c == ')');
}

bool is_op(char c){
    return (c == '*' || c == '+' || c == '-');
}

bool is_val(char c){
    bool f = false;
    f |= is_dig(c);
    f |= is_paran(c);
    f |= is_op(c);
    return f;
}

int main(int argc , char* argv[])
{
	registerValidation(argc, argv);

	int q = inf.readInt(1 , N);
    inf.readEoln();
    string s = inf.readToken();
    for(auto c : s)
        ensuref(is_val(c), "invalid character");
    inf.readEoln();
    int sz = s.size();
    map<char, int> mp;
    int mx = sz;
    while(q --){
        mx = max(mx, sz);
        char c = inf.readChar();
        mp[c] ++;
        if(c == '<' || c == '>' || c == '-' || c == '?' || c == '!'){
            if(c == '-')
                sz --;
            inf.readEoln();
            continue;
        }
        if(c == '+'){
            sz ++;
            inf.readSpace();
            ensuref(is_val(inf.readChar()), "invalid character +");
            inf.readEoln();
            continue;
        }
        ensuref(false, "invalid query");
    }
    mx = max(mx, sz);
    ensuref(mx < 1e5, "too large string");
    ensuref(mp['?'] <= 20, "too many ?");
    ensuref(mp['!'] <= 20, "too many !");
	inf.readEof();
}
