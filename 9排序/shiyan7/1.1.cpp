#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
#include<stack>
#define MAXSIZE 100086
using namespace std;
int a[10086];
//用pivot讲序列化为两个部分
int Partition(int a[], int low, int high)
{
	int pivot=a[low];//将第一个元素作为pivot
	while(low < high) 
	{
		while(low < high && a[high] >= pivot)
		{
			high --;//找到比pivot 小的元素 
		}
		a[low]=a[high];//移到左端
		while(low < high && a[low] <= pivot)
		{
			low ++;//找到比pivot大的元素 
		} 
		a[high] = a[low];//移到右 
	}
	//跳出循环表示找到pivot位置 
	a[low]=pivot;
	return low; 
 } 
void quick_sort(int a[], int low, int high)
{
	if(low<high)//递归跳出条件 
	{
		int pos=Partition(a, low, high);
		quick_sort(a, low, pos-1);//划分左子表
		quick_sort(a, pos+1, high);//划分右子表
	}
}
int main()
{
	cout<<"请输入十个数："<<endl;
	for(int i = 0; i < 10; i++) 
	{
		cin>>a[i];
	}
	//快速排序
	quick_sort(a, 0, 9);
	for(int i = 0; i < 10; i++) 
	{
		cout<<a[i]<<" ";
	}
    return 0;
}
