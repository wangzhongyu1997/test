#pragma once
#include<vector>
#include<iostream>
#include<string>
#include<deque>

using namespace std;
class bignum
{
public:
	bignum(void);
	bignum(string);
	bignum(vector<int> a)
		:num(a){}

	bignum(bignum a,bool fu)
		:num(a.num),fuhao(fu){}//三个构造


	void output();
	int LONG()const{return num.size();}
	bignum operator +(bignum&)const;
	bignum operator *(bignum&)const;
	bignum operator *(int)const;
	bignum operator -(bignum&)const;
	bignum operator / (bignum&)const;
	bignum operator =(string);

	bignum upanddown();
	bignum cut(bignum&);//*Bcut的模型，this为被截数
	bignum insert(int);
	bool operator >(bignum&) ;//仅用于比较，
	bool operator >=(bignum&);
	~bignum(void);
private:
	vector<int> num;
	bool fuhao;
};

