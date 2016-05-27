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
		:num(a.num),fuhao(fu){}//��������


	void output();
	int LONG()const{return num.size();}
	bignum operator +(bignum&)const;
	bignum operator *(bignum&)const;
	bignum operator *(int)const;
	bignum operator -(bignum&)const;
	bignum operator / (bignum&)const;
	bignum operator =(string);

	bignum upanddown();
	bignum cut(bignum&);//*Bcut��ģ�ͣ�thisΪ������
	bignum insert(int);
	bool operator >(bignum&) ;//�����ڱȽϣ�
	bool operator >=(bignum&);
	~bignum(void);
private:
	vector<int> num;
	bool fuhao;
};

