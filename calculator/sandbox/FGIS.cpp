#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 1e9, MOD = 1e9+7, base = 251;

struct MyHash{
	size_t operator()(const string &exp) const noexcept {
		int ret = 0;
		for(auto c : exp){
			ret = 1LL * ret * base % MOD;
			ret += c;
			ret %= MOD;
		}
		return ret;
	}
};

map<char, int> pr;
unordered_map<string, int, MyHash> cache;

string to_str(const list<char> &ls){
	string s;
	for(auto it : ls)
		s.push_back(it);
	return s;
}

void print(const list<char> &ls){
	cout << to_str(ls) << endl;
}

bool ls(char a, char b){
	return pr[a] <= pr[b];
}

int do_op(int a, int b, char c){
	if(c == '+')
		return (a + b) % MOD;
	if(c == '-')
	 	return (a - b + 2LL*MOD) % MOD;
	 if(c == '*')
	 	return 1LL * a * b % MOD;
	 assert(false); 
}

bool is_dig(char c){
    return (c <= '9' && c >= '0');
}

bool is_paran(char c){
    return (c == '(' || c == ')');
}

bool is_op(char c){
    return (c == '*' || c == '+' || c == '-');
}

bool valid(string exp){
	vector<int> st;
	for(int i=0 ; i<exp.size() ; i++){
		if(exp[i] == '('){
			st.push_back(i);
			if(i<exp.size() && !is_dig(exp[i+1]) && exp[i+1] != '(')
				return false;
			if(!i || is_op(exp[i-1]) || exp[i-1] == '(')
				continue;
			return false;
		}
		if(exp[i] == ')'){
			if(st.empty() || st.back() == i-1)
				return false;
			st.pop_back();
			if(i<exp.size() && !is_op(exp[i+1]) && exp[i+1] != ')')
				return false;
			if(!i || is_dig(exp[i-1]) || exp[i-1] == ')')
				continue;
			return false;
		}
	}
	for(int i=1 ; i<exp.size() ; i++)
		if(is_op(exp[i]) && is_op(exp[i-1]))
			return false;
	return true;
}

int eval(string exp){
	assert(valid(exp));
	vector<char> o;
	vector<int> v;
	for(int i=0 ; i<exp.size() ; i++){
		if(exp[i] < '0' || exp[i] > '9'){
			if(exp[i] != '(' && exp[i] != ')'){
				while(!o.empty() && ls(exp[i], o.back())){
					char cur = o.back();
					o.pop_back();
					assert(v.size()>1);
					int res = do_op(v[v.size()-2], v[v.size()-1], cur);
					v.pop_back();
					v.pop_back();
					v.push_back(res);
				}
				o.push_back(exp[i]);
			}else if(exp[i] == '(')
				o.push_back(exp[i]);
			else{
				while(o.back() != '('){
					char cur = o.back();
					o.pop_back();
					assert(v.size()>1);
					int res = do_op(v[v.size()-2], v[v.size()-1], cur);
					v.pop_back();
					v.pop_back();
					v.push_back(res);					
				}
				o.pop_back();
			}
			continue;
		}
		int num=0;
		while(i < exp.size() && (exp[i] >= '0' && exp[i] <= '9')){
			num *= 10;
			num += exp[i] - '0';
			i ++;
		}
		v.push_back(num);
		i --;
	}
	while(!o.empty()){
		char cur = o.back();
		o.pop_back();
		assert(v.size()>1);
		int res = do_op(v[v.size()-2], v[v.size()-1], cur);
		v.pop_back();
		v.pop_back();
		v.push_back(res);					
	}
	assert(v.size() == 1);
	return v.back();
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	// operations priority
	pr['('] = -1;
	pr['+'] = pr['-'] = 0;
	pr['*'] = pr['/'] = 1;
	
	int q;cin >> q;
	string s;cin >> s;
	list<char> ls;
	ls.insert(ls.begin(), s.begin(), s.end());
	auto it = ls.begin();
    int sum=0;
    int h = 1;
	while(q --){
		char op, ch;cin >> op;
		string cur;
		int res;
		switch (op)
		{
		case '<':
			if(it != ls.begin())
				--it;
			break;
		case '>':
			if(it != ls.end())
				++it;
			break;
		case '-':
			assert(ls.size());
            for(auto it2 = it ; it2 != ls.end() ; it2++)
                h *= *it;
            sum += h;
			if(it != ls.begin())
				ls.erase(prev(it));
			break;
		case '+':
			cin >> ch;
			ls.insert(it, ch);
            for(auto it2 = it ; it2 != ls.end() ; it2++)
                h *= *it;
            sum += h;
			break;
		case '?':
			ls.insert(it, '|');
			print(ls);
			ls.erase(prev(it));
			break;
		case '!':
			cur = to_str(ls);
			if(cache.count(cur)){
				cout << cache[cur] << "\n";
				continue;
			}
			res = eval(cur);
			cache[cur] = res;
			cout << res << "\n";
			break;
		default:
			break;
		}
	}
    cerr << sum << "\n";
}
