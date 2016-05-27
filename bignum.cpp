#include "bignum.h"


bignum::bignum(void)
{
}

bignum bignum::upanddown()
{
	vector<int>rd;
	for(int i=(this->LONG()-1);i>=0;i--)
		rd.push_back(this->num[i]);
	return rd;
}


bignum bignum::insert(int a)
{
	vector<int>c;
	c.push_back(a);
	for(int i=0;i<this->LONG();i++)
		c.push_back(num[i]);
	return c;
}

bignum::bignum(string A)
{
	int l=A.length();
	for(int i=l-1;i>=0;i--)
		num.push_back(A[i]-48);
}




bignum bignum::operator =(string A)
{
	int l=A.length();
	for(int i=l-1;i>=0;i--)
		num.push_back(A[i]-48);
	return *this;
}

bignum bignum::operator+(bignum& B)const
{
	bignum a=*this,b=B;
	vector<int>c;
	int i=a.num.size();
	int j=b.num.size();
	/*if(i>j)
		for(;j<i;j++)
			b.num.push_back(0);
	else for(;i<j;i++)
		a.num.push_back(0);

	int t2=0;//上次运算进位
	int t1=0;//对应位加和
	int t3=0;//对应位加和的个位加上上次运算进位；
	bool flag=0;//判断t3是否为两位数；
	int l=max(i,j);

	for(int n=0;n<l;n++)
	{
		flag=0;
		t1=b.num[n]+a.num[n];
		t3=t1%10+t2;
		if(t3<10)
			c.push_back(t3);
		else
		{c.push_back(t3%10);flag=1;}
		t2=t1/10;
	}
	if(flag)//最后t3若为两位数，还有一位，t2；
		c.push_back(t2);*/


	int l=min(i,j);
	int L=max(i,j);

	int t1=0;
	int t2=0;
	int t3=0;
	int n;//循环变量
	int flag=0;

	if(i>j)
		flag=1;
	else
		flag=0;


	for( n=0;n<l||t1>=10;n++)
	{
		if(L>n)
			if(l>n)
				t1=b.num[n]+a.num[n]+t3;
			else if(flag)//若a长
				{t1=a.num[n]+t3;}
			else 
				{t1=b.num[n]+t3;}
		else t1=0+t3;//当往较长数的首位的前一位进一时
		t2=t1%10;
		t3=t1/10;
		c.push_back(t2);
	}

	if(flag)
		for( n;n<L;n++)
			c.push_back(a.num[n]);
	else 
		for( n;n<L;n++)
			c.push_back(b.num[n]);
	return bignum(c);
}


bignum bignum::operator*(bignum&B)const
{
	bignum a,b;
	int i=num.size();
	int j=B.num.size();

	if(i>j)
	{
		swap(i,j);
		a=B;
		b=*this;
		//swap<bignum>(*this,B);// 为保证计算效率，采用短数*chang数，
	}
	else
	{
		a=*this;
		b=B;
	}
	int k;//*右侧的每一位
	int l;//*左侧的每一位
	int t1=0;
	int t2=0;
	int t3=0;
	bignum c,z;
	z.num.push_back(0);
	//bool flag=0;


	//if(j>=i)
	{
		for(int m=0;m<i;m++)
		{
			
			k=a.num[m];//较小数的m位
			if(k==0)
			{
				c.num.push_back(0);
				continue;
			}//有零不算；
			//flag=0;
			c.num.clear();
			t3=0;//每次循环清零
			for(int v=0;v<m;v++)
					{c.num.push_back(0);}//在末尾补几个0,当m位不是个位时
			for(int n=0;n<j;n++)
			{
				l=b.num[n];
				t1=k*l+t3;
				t2=t1%10;//该位
				t3=t1/10;//进位

				

				c.num.push_back(t2);
			}
			if(t1>10)
				c.num.push_back(t3);

			z=z+c;
		}
	}
	
	while((z.num.back()==0)&&(z.num.size()!=1))
		z.num.pop_back();//删除最高位的0
	return bignum(z);
}




bignum bignum::operator*(int k)const//k只能为一位数
{
	int t1=0;
	int t2=0;
	int t3=0;
	int l=0;
	bignum c;
	int j=this->LONG();
	for(int n=0;n<j;n++)
			{
				l=num[n];
				t1=k*l+t3;
				t2=t1%10;//该位
				t3=t1/10;//进位

				

				c.num.push_back(t2);
			}
		if(t1>=10)
			c.num.push_back(t3);

	while((c.num.back()==0)&&(c.num.size()!=1))
		c.num.pop_back();//删除最高位的0且保留一位
	return bignum(c);

}



bool bignum::operator>(bignum&B)
{
	int l;//长度
	if(this->LONG()>B.LONG())
		return true;//表示da
	else if((l=this->LONG())==B.LONG())
		{
			for(int i=l-1;i>=0;i--)
				if(this->num[i]>B.num[i])
					return true;
				else if(this->num[i]<B.num[i])
					return false;

			return false;
		}
			
	else return false;
}



bool bignum::operator>=(bignum&B)
{
	int l;//长度
	if(this->LONG()>B.LONG())
		return true;//表示da
	else if((l=this->LONG())==B.LONG())
		{
			for(int i=l-1;i>=0;i--)
				if(this->num[i]>B.num[i])
					return true;
				else if(this->num[i]<B.num[i])
					return false;

			return true;
		}
			
	else return false;
}



bignum bignum::operator-(bignum&B)const
{
	bignum a=*this;
	bignum b=B;
	int i;//索引
	int m=a.LONG();
	int n=b.LONG();
	vector<int>c;
	if(a>b)
		{
			//for(i=0;i<n||a.num[i]==-1;i++)//以较小数为限制a.num[i]==-1是因为188行和194行有借位
			for(i=0;!(m==n&&n==i)&&(i<n||a.num[i]==-1);i++)
			{												/*158-123会有错误。。。
															这是因为缺少判断位数是否相等
															会有a.num[3]越界
															所以加了!(m==n&&n==i)&&*/
				
				if(a.num[i]==-1)
				{a.num[i+1]--;a.num[i]=9;}//将借位补为9

				if(i>=n)
					c.push_back(a.num[i]);
				else if(i<n&&a.num[i]>=b.num[i])
					c.push_back(a.num[i]-b.num[i]);
				else//此为a.num[i]<b.num[i]时
				{c.push_back(a.num[i]-b.num[i]+10);a.num[i+1]--;}
			}
			for(i;i<m;i++)
				c.push_back(a.num[i]);
			while((c.back()==0)&&(c.size()!=1))
		c.pop_back();//删除最高位的0且保留一位

			return c;
		}
	else if(b>a)
		return bignum(b-a,false);
	else  c.push_back(0);
		return c;

}




bignum bignum::operator/(bignum&B)const//*Bcut的模型，this为被截数
{
	bignum d=*this;
	bignum c=d.cut(B);//左权为cut的模型，参数为被截数//此为被劫缓存
										/*把被除数截断*/
	bignum r,rd;

	for(int j=this->LONG()-B.LONG()   ;   j>=0;   j--)
	{
		for(int i=9;i>=0;i--)
		{
			bignum t1=B*i;
			if(c>=t1)
			{
				//int x=num[j-1];/***************************/
				if(j==0)
					c=(c-t1).insert(0);
				else
					//(c-t1).insert(num[j-1]);
					c=(c-t1).insert(num[j-1]);/***************************/
				r.num.push_back(i);
				break;
			}
		}
	}

	rd=r.upanddown();
	while((rd.num.back()==0)&&(rd.num.size()!=1))
		rd.num.pop_back();//删除最高位的0且保留一位
	return rd;
}



bignum bignum ::cut(bignum&B)//*Bcut的模型，this为被截数
{
	int a=this->LONG();//a长
	int b=B.LONG();//b短
	vector<int>c;
	for(int i=a-b;i<a;i++)
		c.push_back(num[i]);

	return c;


}
void bignum::output()
{
	int l=num.size();
	if(!fuhao)
		cout<<" - ";
	for(int i=0;i<l;i++)
		cout<<num[l-i-1];
}

bignum::~bignum(void)
{
}
