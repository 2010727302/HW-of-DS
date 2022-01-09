#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
#include<stack>
#define MAXSIZE 100086
using namespace std;
int a[10086];
//��pivot�����л�Ϊ��������
int Partition(int a[], int low, int high)
{
	int pivot=a[low];//����һ��Ԫ����Ϊpivot
	while(low < high) 
	{
		while(low < high && a[high] >= pivot)
		{
			high --;//�ҵ���pivot С��Ԫ�� 
		}
		a[low]=a[high];//�Ƶ����
		while(low < high && a[low] <= pivot)
		{
			low ++;//�ҵ���pivot���Ԫ�� 
		} 
		a[high] = a[low];//�Ƶ��� 
	}
	//����ѭ����ʾ�ҵ�pivotλ�� 
	a[low]=pivot;
	return low; 
 } 
void quick_sort(int a[], int low, int high)
{
	if(low<high)//�ݹ��������� 
	{
		int pos=Partition(a, low, high);
		quick_sort(a, low, pos-1);//�������ӱ�
		quick_sort(a, pos+1, high);//�������ӱ�
	}
}
int main()
{
	cout<<"������ʮ������"<<endl;
	for(int i = 0; i < 10; i++) 
	{
		cin>>a[i];
	}
	//��������
	quick_sort(a, 0, 9);
	for(int i = 0; i < 10; i++) 
	{
		cout<<a[i]<<" ";
	}
    return 0;
}
