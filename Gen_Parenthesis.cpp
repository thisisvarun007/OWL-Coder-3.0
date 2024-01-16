#include<bits/stdc++.h>
using namespace std;

void Gen(int op,int cl,int n,string s,vector<string> &res){
	if (op == n && cl == n){
		res.push_back(s);
		return;
	}
	if (op == n && cl != n){//close only
		s.push_back(')');
		cl++;
		Gen(op,cl,n,s,res);
	}
	else if (op > cl){//open or close
		s.push_back('(');
		op++;
		Gen(op,cl,n,s,res);
		s.pop_back();
		op--;

		s.push_back(')');
		cl++;
		Gen(op,cl,n,s,res);
	}
	else if (op == cl){ //open only
		s.push_back('(');
		op++;
		Gen(op,cl,n,s,res);
	}
}
vector<string> Generate(int n){
	vector<string> res;
	string s;
	Gen(0,0,n,s,res);
	return res;
}
int main(){
	int n;
	cin >> n;
	vector<string> res = Generate(n);
	for (auto it : res) cout << it << "\n";
	return 0;
}