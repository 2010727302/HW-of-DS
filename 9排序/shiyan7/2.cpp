#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <ctime>
#include <iostream>
#define MAX 150
using namespace std;
typedef struct ST
{
    char name[30]; //排序名称
    int id;       //学号 
    int score;       //总分
    int sub[10];//各科成绩 
} ST;        
ST student[10086], temp;
int n;
//冒泡排序 
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
            else if(a[j-1].score == a[j].score && strcmp(a[j-1].name , a[j].name) > 0)//成绩相同时比较姓名 
            {
            	swap(a[j], a[j - 1]);
			}
		}
            
    }
}
int main()
{
	cout << "请输入要录入的学生的个数 ： " << endl ;  
    cin >> n ;
    cout << "输入姓名，学号和各科分数 " << endl ;  
    for( int i = 0 ; i < n ; i ++)
	{
        cin >> student[i].name >>student[i].id >> student[i].sub[0] >> student[i].sub[1] >> student[i].sub[2]  ;
        student[i].score = student[i].sub[0] + student[i].sub[1] + student[i].sub[2];
    }
    BubbleSort(student,n);
	int rank=1;//处理有相同分数 
    cout << "\t\t\t\t" << "按照名次打印学生信息表如下：" << endl ;
	//按名次打印学生成绩表及其信息 
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


