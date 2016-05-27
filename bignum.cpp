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

	int t2=0;//�ϴ������λ
	int t1=0;//��Ӧλ�Ӻ�
	int t3=0;//��Ӧλ�Ӻ͵ĸ�λ�����ϴ������λ��
	bool flag=0;//�ж�t3�Ƿ�Ϊ��λ����
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
	if(flag)//���t3��Ϊ��λ��������һλ��t2��
		c.push_back(t2);*/


	int l=min(i,j);
	int L=max(i,j);

	int t1=0;
	int t2=0;
	int t3=0;
	int n;//ѭ������
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
			else if(flag)//��a��
				{t1=a.num[n]+t3;}
			else 
				{t1=b.num[n]+t3;}
		else t1=0+t3;//�����ϳ�������λ��ǰһλ��һʱ
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
		//swap<bignum>(*this,B);// Ϊ��֤����Ч�ʣ����ö���*chang����
	}
	else
	{
		a=*this;
		b=B;
	}
	int k;//*�Ҳ��ÿһλ
	int l;//*����ÿһλ
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
			
			k=a.num[m];//��С����mλ
			if(k==0)
			{
				c.num.push_back(0);
				continue;
			}//���㲻�㣻
			//flag=0;
			c.num.clear();
			t3=0;//ÿ��ѭ������
			for(int v=0;v<m;v++)
					{c.num.push_back(0);}//��ĩβ������0,��mλ���Ǹ�λʱ
			for(int n=0;n<j;n++)
			{
				l=b.num[n];
				t1=k*l+t3;
				t2=t1%10;//��λ
				t3=t1/10;//��λ

				

				c.num.push_back(t2);
			}
			if(t1>10)
				c.num.push_back(t3);

			z=z+c;
		}
	}
	
	while((z.num.back()==0)&&(z.num.size()!=1))
		z.num.pop_back();//ɾ�����λ��0
	return bignum(z);
}




bignum bignum::operator*(int k)const//kֻ��Ϊһλ��
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
				t2=t1%10;//��λ
				t3=t1/10;//��λ

				

				c.num.push_back(t2);
			}
		if(t1>=10)
			c.num.push_back(t3);

	while((c.num.back()==0)&&(c.num.size()!=1))
		c.num.pop_back();//ɾ�����λ��0�ұ���һλ
	return bignum(c);

}



bool bignum::operator>(bignum&B)
{
	int l;//����
	if(this->LONG()>B.LONG())
		return true;//��ʾda
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
	int l;//����
	if(this->LONG()>B.LONG())
		return true;//��ʾda
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
	int i;//����
	int m=a.LONG();
	int n=b.LONG();
	vector<int>c;
	if(a>b)
		{
			//for(i=0;i<n||a.num[i]==-1;i++)//�Խ�С��Ϊ����a.num[i]==-1����Ϊ188�к�194���н�λ
			for(i=0;!(m==n&&n==i)&&(i<n||a.num[i]==-1);i++)
			{												/*158-123���д��󡣡���
															������Ϊȱ���ж�λ���Ƿ����
															����a.num[3]Խ��
															���Լ���!(m==n&&n==i)&&*/
				
				if(a.num[i]==-1)
				{a.num[i+1]--;a.num[i]=9;}//����λ��Ϊ9

				if(i>=n)
					c.push_back(a.num[i]);
				else if(i<n&&a.num[i]>=b.num[i])
					c.push_back(a.num[i]-b.num[i]);
				else//��Ϊa.num[i]<b.num[i]ʱ
				{c.push_back(a.num[i]-b.num[i]+10);a.num[i+1]--;}
			}
			for(i;i<m;i++)
				c.push_back(a.num[i]);
			while((c.back()==0)&&(c.size()!=1))
		c.pop_back();//ɾ�����λ��0�ұ���һλ

			return c;
		}
	else if(b>a)
		return bignum(b-a,false);
	else  c.push_back(0);
		return c;

}




bignum bignum::operator/(bignum&B)const//*Bcut��ģ�ͣ�thisΪ������
{
	bignum d=*this;
	bignum c=d.cut(B);//��ȨΪcut��ģ�ͣ�����Ϊ������//��Ϊ���ٻ���
										/*�ѱ������ض�*/
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
		rd.num.pop_back();//ɾ�����λ��0�ұ���һλ
	return rd;
}



bignum bignum ::cut(bignum&B)//*Bcut��ģ�ͣ�thisΪ������
{
	int a=this->LONG();//a��
	int b=B.LONG();//b��
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
