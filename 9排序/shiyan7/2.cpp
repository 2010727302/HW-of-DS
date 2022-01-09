#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <ctime>
#include <iostream>
#define MAX 150
using namespace std;
typedef struct ST
{
    char name[30]; //��������
    int id;       //ѧ�� 
    int score;       //�ܷ�
    int sub[10];//���Ƴɼ� 
} ST;        
ST student[10086], temp;
int n;
//ð������ 
void BubbleSort(ST a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
        	if (a[j].score < a[j - 1].score)
            {
                swap(a[j], a[j - 1]);
            }
            else if(a[j-1].score == a[j].score && strcmp(a[j-1].name , a[j].name) > 0)//�ɼ���ͬʱ�Ƚ����� 
            {
            	swap(a[j], a[j - 1]);
			}
		}
            
    }
}
int main()
{
	cout << "������Ҫ¼���ѧ���ĸ��� �� " << endl ;  
    cin >> n ;
    cout << "����������ѧ�ź͸��Ʒ��� " << endl ;  
    for( int i = 0 ; i < n ; i ++)
	{
        cin >> student[i].name >>student[i].id >> student[i].sub[0] >> student[i].sub[1] >> student[i].sub[2]  ;
        student[i].score = student[i].sub[0] + student[i].sub[1] + student[i].sub[2];
    }
    BubbleSort(student,n);
	int rank=1;//��������ͬ���� 
    cout << "\t\t\t\t" << "�������δ�ӡѧ����Ϣ�����£�" << endl ;
	//�����δ�ӡѧ���ɼ�������Ϣ 
	cout <<"\t"<< "rank"<<"\t" << "name" << "\t" << "id" << "\t" << "score" << "\t" << "english" << "\t" << "chinese" << "\t" << "math" << endl ; 
	for(int i = 0 ; i < n ; i ++)
	{
		
		if((i!=n)&&(student[i].score==student[i+1].score)) 
		{
			cout <<"\t"<< rank <<"\t" << student[i].name << " " << "\t"<< student[i].id << " "<< "\t"<< student[i].score <<" " << "\t"<< student[i].sub[0] 
			<< " "<< "\t"<< student[i].sub[1] << " "<< "\t"<< student[i].sub[2]   ;
		}
		else
		{
			cout <<"\t"<< rank <<"\t" << student[i].name << " " << "\t"<< student[i].id << " "<< "\t"<< student[i].score <<" " << "\t"<< student[i].sub[0] 
			<< " "<< "\t"<< student[i].sub[1] << " "<< "\t"<< student[i].sub[2]   ;
			rank++;
		}
        
		cout << endl ;
	}
    return 0;
}


