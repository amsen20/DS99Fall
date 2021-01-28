#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

typedef pair<int, int> ii;

int pw(int t){
    int ret=1;
    while(t--)
        ret *= 10;
    return ret;
}

string to_str(int num){
    string cur;
    while(num){
        cur.push_back('0' + num%10);
        num /= 10;
    }
    reverse(cur.begin(), cur.end());
    return cur;
}

int main(int argc , char* argv[]){
	registerGen(argc, argv , 1);
	int deg = atoi(argv[1]);
    int mx = atoi(argv[2]);
    string s;
    int len = 2*pw(deg)-1;
    // base string
    for(int i=0 ; i<len ; i++){
        if(i%2 == 0)
            s.push_back('$');
        else
            s += rnd.next("+|-|*");
    }
    int t = pw(deg-1);
    // add parentheses
    map<int, int> op, cl;
    do{
        int x = rnd.next(pw(deg)-1), y = rnd.next(pw(deg));
        x = 2*x+1;
        y *= 2;
        if(x < y && y < len){
            op[x] ++;
            cl[y] ++;
            t --;
        }
    }while(t);
    // remove ()
    for(int i=1 ; i<s.size() ; i++)
        while(op[i-1] && cl[i]){
            op[i-1] --;
            cl[i] --;
        }
    string tmp;
    for(int i=0 ; i<s.size() ; i++){
        tmp.push_back(s[i]);
        while(op[i] --)
            tmp.push_back('(');
        while(cl[i] --)
            tmp.push_back(')');
    }
    s = tmp;
    // transfer $ to numbers
    tmp = "";
    for(int i=0 ; i<s.size() ; i++){
        if(s[i] != '$'){
            tmp.push_back(s[i]);
            continue;
        }
        tmp += to_str(rnd.next(1, mx));
    }
    s = tmp;
    string init;
    map<int, vector<int> > toadd;
    for(int i=0 ; i<s.size() ; i++){
        if(rnd.next(2))
            init.push_back(s[i]);
        else
            toadd[init.size()].push_back(s[i]);
    }
    vector<string> qs;
    qs.push_back("<");
    for(int i=0 ; i<=init.size() ; i++){
        for(auto c : toadd[i]){
            string cur = "+ ";
            cur.push_back(c);
            qs.push_back(cur);
        }
        qs.push_back(">");
        if(!rnd.next(init.size()/4))
            qs.push_back("?");
    }
    qs.push_back("?");

    qs.push_back("!");
    vector<int> digs;
    for(int i=0 ; i<s.size() ; i++)
        if(s[i] >= '0' && s[i] <= '9')
            digs.push_back(i);
    shuffle(digs.begin(), digs.end());
    digs.resize(2);
    for(auto ind : digs){
        for(int i=0 ; i<s.size()-1-ind ; i++)
            qs.push_back("<");
        for(char c='1' ; c<='9' ; c++){
            qs.push_back("-");
            string cur = "+ ";
            cur.push_back(c);
            qs.push_back(cur);
            if(rnd.next(2))
                qs.push_back("?");
            qs.push_back("!");
        }
        for(int i=0 ; i<s.size() ; i++)
            qs.push_back(">");
    }
    
    cout << qs.size() << "\n";
    cout << init << "\n";
    for(auto q : qs)
        cout << q << "\n";
}
