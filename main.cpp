//我并不想让他支持负数的加减，但是允许你用小数减大数
#include"bignum.h"

int main()
{
	cout<<" 这是大数四则运算：\n";
	//*Bcut的模型，this为被截数
	bignum a("6542325654834654654");
	bignum b("1759471564");
	b.output();
	cout<<" * ";
	a.output();
	cout<<" = ";
	(b*a).output();
	cout<<endl<<endl;
	

	b.output();
	cout<<" + ";
	a.output();
	cout<<" = ";
	(a+b).output();
	cout<<endl<<endl;
	
	a.output();
	cout<<" - ";
	b.output();
	cout<<" = ";
	(a-b).output();
	cout<<endl<<endl;

	a.output();
	cout<<" / ";
	b.output();
	cout<<" = ";
	(a/b).output();
	cout<<endl;
	cout<<"\n\n我要在这里吐槽了，这就是大数的加减乘除,也许你说："
		<<"这看着也不是很大嘛，我只是为了用计算器验证,"
		<<"19位是微软的计算器支持的最大位数，我用它验证了几下除法，"
		<<"至于精确到几位小数，我实在是不想写了，不是因为多难，是因为我不爽！！！"
		<<"再写本少爷就不高兴了,已经写得太多了，难的地方我都要写吐了，，好吧，让你看一个过瘾的：PS(你可以试着找一下*号和=号，我是故意的)\n\n\n\n\n";
	a="546512165795562154862132168765465498462165687984235689798765321184543235465646513267654654";
	b="984626565432566541465498465616465465412154654651312155421213123113258476213";
	a.output();
	cout<<"*";
	b.output();
	cout<<"=";
	(a*b).output();
	cout<<endl<<" 我其实是想说脏话的。\n不过现在爽多了\n";
	
	
	return 0;
}