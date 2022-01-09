#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
#define MAXSIZE 10086
using namespace std;

int hlist[40];
int count=0;//计算asl 
//哈希表结点 
typedef struct h
{
	int key;
	string hinfo; 
}htable[40];
//转换为key 
int hkey(string t)
{
	int key1=0;
	//将字符串的各个字符所对应的ASCII码相加，所得的整数做为哈希表的关键字
	for(int i=0;i<t.length();i++)
	{
		key1+=(int)t[i];
	//	cout<<key1<<endl;
	}
	
	return key1;
}
//查找(除留余数法)
int htsearch(htable& ht,string info) 
{
	int a=hkey(info);
	int h0=a%37;//求其在表中的位子 
	count=1;
	//cout<<info<<":"<<h0<<endl;
	if(ht[h0].hinfo==info) //成功 
	{
		return h0;
	}
	else
	{
		for(int i=1;i<100;i++)
		{
			int hi=(h0+i)%40;//线性探测
			count++;
			if(ht[hi].hinfo==info)
			{
				return hi;	
			}
			else if(ht[hi].key==-1)	
			{
				break;
			}
		}	
	}
	return -1;
}
//创建
void htcreate(htable& ht,string name[])
{
	//memset(ht[])
	for(int i=0;i<40;i++)
	{
		ht[i].key=-1;
	}
	for(int i=0;i<30;i++)
	{
		//哈希函数用除留余数法构造 H（key） = key % 39
		//因为哈希表长40，mod数取37  
		int a=hkey(name[i]);
		int h0=a%37;
		if(ht[h0].key==-1)//该位没有值 
		{
			ht[h0].hinfo=name[i];
			ht[h0].key=h0;
		}
		else//冲突探测 
		{
			for(int j=1;j<100;j++)
			{
				int hj=(h0+j)%40;
				if(ht[hj].key==-1)
				{
					ht[hj].hinfo=name[i];
					ht[hj].key=hj;
					break;
				}
			}
		}
	}
}
//输出哈希表
void hprint(htable ht)
{
	cout<<"id        哈 希 值       人 名"<<endl; 
	for(int i=0;i<30;i++)
	{
		printf("%-4d\t%8d\t",i,ht[i].key);
		cout<<ht[i].hinfo<<endl;
	} 
} 
//asl
double asl(htable& ht,string name[])
{
	double re=0;
	for(int i=0;i<30;i++)
	{
		htsearch(ht,name[i]);
		cout<<name[i]<<":";
		printf("%-10d\n",count);
		re+=count;
	}
	return re/30.0;
 } 
int main()
{
	   string name[30]={
        		"xvzhenhua", "xinzebin",
	                    "caoshenjie", "wuhaobin",
						"yinjiacai", "muxin",
						"guozihan", "guanshanyue",
						"chensijia", "zhaoran",
						"chenbin", "wudi",
						"liuxisheng", "masifan",
						"laihongbin", "liulichao",
						"chenqilin", "chengjiawei",
						"fanyvqing", "huangjunhui",
						"huangzaoying", "liyifei",
						"liuxinrui", "luoxiaoyv",
						"wangxiaoke", "wenbo",
						"houjinbing", "yangguang",
						"zhangyvqian", "zhangzijian"
    };
 /*string name[30]={
					"wangyuhan","dukefei","sutianyu","shihanpeng","xiedonglin",
                    "sunliangliang","pengsihao","hanrui","hourunning","xiekai",
                    "zhaoran","jiahaochen","zhangaiqi","yaoliunian","lijiahe",
                     "luxintong","zhouying","zhanglongwei","hanyu","zixinyuan",
                            "xutianhang","heyujie","wangxiaochen","linanxin","zhangshuning",
                            "yanhaolong","zhangmingxin","majiaji","liutianyi","mayuchen"
                        };*/
	cout<<"线性探测再散列法处理冲突"<<endl;
	htable ht;
	string shuru;
	htcreate(ht,name);
	cin>>shuru;//输入要查找的名字
	cout<<htsearch(ht,shuru)<<endl;
	hprint(ht);
	cout<<"asl:"<<asl(ht,name)<<endl;
    return 0;
}
