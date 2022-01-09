#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <ctime>
#include <iostream>
#define MAX 1000
using namespace std;
typedef struct SORTTYPE
{
    char name[30]; //排序名称
    int num_compare;       //比较的次数
    int num_move;       //移动的次数
} ST;        //存储分析效率的数据
int num_compare = 0, num_move = 0; //关键字比较和移动的次数
ST st[9];                 //9种算法的分析数据

//直接插入排序算法
void InsertSort(int a[], int n)
{
    int i, j;
    int temp;
    for (i = 1; i < n; i++) //for循环内一定比较了n-1次，if判断语句
    {
        if (a[i] < a[i - 1]) //一旦出现了逆序的关键字，就进行插入
        {
            temp = a[i];
            j = i - 1;
            num_compare++;
            do //往后移动一个位置，腾空间给temp；
            {
                a[j + 1] = a[j];
                num_move++; //移动加一
                j--;
                num_compare++; //比较次数加一
            }
            while (j >= 0 && a[j] > temp);

            a[j + 1] = temp; //最后把temp放在对应的位置
            num_move += 2;  //移动的temp
        }
    }
}
//折半插入排序法
//有序区利用折半查找来寻找的改进算法
void BinInsertSort(int a[], int n)
{
    int i, j, low, high, mid;
    int temp;
    for (i = 1; i < n; i++) //已经比较了n-1次
    {
        if (a[i] < a[i - 1])
        {
            temp = a[i];
            low = 0;
            high = i - 1;
            num_compare++;
            while (low <= high)
            {
                num_compare++; //while进入比较
                mid = (low + high) / 2;
                if (temp < a[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            for (j = i - 1; j >= high + 1; j--)
            {
                a[j + 1] = a[j];
                num_move++; //移动次数加一
            }
            a[high + 1] = temp;
            num_move += 2; //temp交换
        }
    }
}
//二路插入
//类似于循环队列 
void InsertSort2(int a[], int n)    
{
	int first=0, last=0;
	int *b = new int[n];//b循环数组 
	 
	b[0] = a[0];//初始化 
	for (int i = 1; i < n; i++)
	{
		if (a[i] < b[first])
		{
			num_compare++; 
			first = (first - 1 + n) % n;
			b[first] = a[i];
			num_move++;
		}
		else if (a[i] >= b[last])
		{
			num_compare+=2; //和b[last]及b[first]比较 
			last=(last + 1) % n;
			b[last] = a[i];
			num_move++;
		}
		else
		{
			num_compare+=2;
			int low, high, mid, d;
			low = first, high = last;
			while (low != high)      //折半查找
			{
				num_compare++;
				d = (high-low+n) % n;    //元素个数
				mid = (low + d / 2) % n;    //中间位置
				if (a[i] < b[mid])
				{
					high = mid;
					num_compare++;
				}
					
				else
				{
					low = (mid + 1) % n;
					num_move++;
				}
					
			}
			for (int k = last + 1; k != low; k = (k - 1 + n) % n)  //移动元素
			{
				b[k] = b[(k - 1 + n) % n];
				num_move++;
			}
				
			b[low] = a[i];
			num_move++;
			last++;
		}
	}
	for (int i = 0; i < n; i++)
		a[i] = b[(i + first) % n];
	delete[]b;
}
//希尔排序算法
void ShellSort(int a[], int n)
{
    int i, j, d;
    int temp;
    d = n / 2;

    while (d > 0)
    {
        for (i = d; i < n; i++)
        {
            temp = a[i];
            j = i - d;

            while (j >= 0 && temp < a[j])
            {
                num_compare++;
                num_move++;
                a[j + d] = a[j];
                j = j - d;
            }
            a[j + d] = temp;
            num_move += 2; //temp进行两次操作
        }
        d = d / 2;
    }
}
//冒泡排序算法
void BubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j > i; j--)
            if (a[j] < a[j - 1])
            {
                num_compare++;
                num_move += 3;
                swap(a[j], a[j - 1]);
            }
    }
}
//用pivot讲序列化为两个部分
int Partition(int a[], int low, int high)
{
	int pivot=a[low];//将第一个元素作为pivot
	while(low < high) 
	{
		while(low < high && a[high] >= pivot)
		{
			high --;//找到比pivot 小的元素 
			num_compare++; //进行比较
		}
		a[low]=a[high];//移到左端
		num_move++;  //移动++
		while(low < high && a[low] <= pivot)
		{
			low ++;//找到比pivot大的元素 
			num_compare++; //进行比较
		} 
		a[high] = a[low];//移到右 
		num_move++;  //移动++
	}
	//跳出循环表示找到pivot位置 
	a[low]=pivot;
	num_move +=2;  //移动+2
	return low; 
 } 
 //快速排序算法
void QuickSort(int a[], int low, int high)
{
	if(low <high)//递归跳出条件 
	{
		int pos=Partition(a, low, high);
		QuickSort(a, low, pos-1);//划分左子表
		QuickSort(a, pos+1, high);//划分右子表
	}
}
//选择排序算法 
void SelectionSort(int a[], int n) 
{
	int mid;
	for (int i = 0; i < n - 1; ++i) 
	{
		mid = i;
		for (int j = i + 1; j < n; ++j) 
		{
			if (a[j] < a[mid]) 
			{
				
				mid = j;
			}
			num_compare++;
		}
		swap(a[mid], a[i]);
		//cout<<num_move<<" ";
		num_move+=3;
	}
}
void HeapAdjust(int a[], int parent, int length) 
{
    int temp = a[parent]; // temp保存当前父节点
    int child = 2 * parent + 1; // 先获得左孩子
 
    while (child < length) 
	{
        // 如果有右孩子结点，并且右孩子结点的值大于左孩子结点，则选取右孩子结点
        if (child + 1 < length && a[child] < a[child + 1]) 
		{
            child++;
        }
 
        // 如果父结点的值已经大于孩子结点的值，则直接结束
        if (temp >= a[child])
        {
        	num_compare++;
			break;
		}
            
        // 把孩子结点的值赋给父结点
        a[parent] = a[child];
 		num_move++;
        // 选取孩子结点的左孩子结点,继续向下筛选
        parent = child;
        child = 2 * child + 1;
    }
 
    a[parent] = temp;
    num_move+=2;
}
 //堆排序 
void HeapSort(int a[], int n) 
{
    // 循环建立初始堆
    for (int i = n / 2; i >= 0; i--) 
	{
        HeapAdjust(a, i, n);
    }
 
    // 进行n-1次循环，完成排序
    for (int i = n - 1; i > 0; i--) 
	{
        // 最后一个元素和第一元素进行交换
        swap(a[i], a[0]);
 		num_move+=3;
        // 筛选 R[0] 结点，得到i-1个结点的堆
        HeapAdjust(a, 0, i);
        //System.out.format("第 %d 趟: \t", n - i);
        //printPart(a, 0, a.length - 1);
    }
}

void merge(int a[],int l,int r,int mid)
{
  int aux[r-l+1],i,j,k;//aux辅助数组 
  
  for(k=l;k<=r;k++)
  {
  	aux[k-l]=a[k];
  	num_move++;
  }
  	

  i=l;
  j=mid+1;
  for(k=l;k<=r;k++)
  {
	if(i>mid)
  	{
  		a[k]=aux[j-l];
  		num_move++; 
  		j++;
	}
	else if(j>r)
	{
		a[k]=aux[i-l];
		num_move++;
		i++;
	}
	else if(aux[i-l]>aux[j-l])
	{
		a[k]=aux[j-l];
		num_move++;
		num_compare++;
		j++;
	}
	else
	{
		a[k]=aux[i-l];
		num_move++;
		num_compare++;
		i++;
	}
				    
  	
  }	
	
}
 
void merge_sort(int a[],int l,int r)
{
    if(l>=r)
		return;
	
	int mid=(l+r)/2;//找中间 
	
	merge_sort(a,l,mid);//归并左边 
	merge_sort(a,mid+1,r);//归并右边 
	merge(a,l,r,mid);//合并	
	
}
 //归并排序
void MergeSort(int a[],int l,int r)
{
	merge_sort(a,l,r-1);
}
//主菜单 
void menu()
{
    printf("\t\t1.直接插入排序法\n");
    printf("\t\t2.折半插入排序法\n");
    printf("\t\t3.希尔排序法\n");
    printf("\t\t4.冒泡排序法\n");
    printf("\t\t5.快速排序法\n");
    printf("\t\t6.二路插入\n");
    printf("\t\t7.简单选择排序\n");
    printf("\t\t8.堆排序\n");
    printf("\t\t9.归并排序\n");
    printf("\t\t10.效率比较\n");
    printf("\t\t11.退出\n");
    printf("请选择操作：");
}
//打印数组数据
void printArray(int a[]) 
{
    int i;
    for (i = 0; i < MAX; i++)
        printf("%2d%c", a[i], (i+1)%40 ? ' ' : '\n');
    putchar(10);
}
//为数组获得随机数
void GetRandArray(int a[]) 
{
    int i;
    for (i = 0; i < MAX; i++)
        a[i] = rand() % 100;
}
//调用各个排序的实现函数
void op1(int a[])
{
    GetRandArray(a);
    printf("伪随机数已经生成的1000个新的随机数\n");
    //打印排序前的数组
    printArray(a);
    InsertSort(a, MAX);
    cout<<"利用直接插入排序后的数列如下："<<endl;
    //打印排序后的数组
    printArray(a);
    printf("\n\n直接插入排序法：\n一共比较%d，移动%d\n", num_compare, num_move);
    st[0].num_compare = num_compare;
    st[0].num_move = num_move;
    strcpy(st[0].name, "直接插入排序");
}
void op2(int a[])
{
    GetRandArray(a);
    printf("已经生成1000个新的随机数\n");
    //打印排序前的数组
    printArray(a);
    num_compare = 0;
    num_move = 0;
    BinInsertSort(a, MAX);
    cout<<"利用折半插入排序后的数列如下："<<endl;
    //打印排序后的数组
    printArray(a);
    printf("\n\n折半插入排序：\n一共比较了%d次，移动了%d次\n", num_compare, num_move);
    st[1].num_compare = num_compare;
    st[1].num_move = num_move;
    strcpy(st[1].name, "折半插入排序");
}
void op3(int a[])
{
    GetRandArray(a);
    printf("已经生成1000个新的随机数\n");
    //打印排序前的数组
    printArray(a);
    num_compare = 0;
    num_move = 0;
    ShellSort(a, MAX);
    cout<<"\n利用希尔排序算法后的数列如下："<<endl;
    //打印排序后的数组
    printArray(a);
    printf("\n\n希尔排序算法：\n一共比较了%d次，移动了%d次\n", num_compare, num_move);
    st[2].num_compare = num_compare;
    st[2].num_move = num_move;
    strcpy(st[2].name, "希尔排序算法");
}
void op4(int a[])
{
    GetRandArray(a);
    printf("已经生成1000个新的随机数\n");

    //打印排序前的数组
    printArray(a);

    num_compare = 0;
    num_move = 0;
    BubbleSort(a, MAX);

    cout<<"利用冒泡排序法后的数列如下："<<endl;
    //打印排序后的数组
    printArray(a);

    printf("\n\n冒泡排序算法：\n一共比较了%d次，移动了%d次\n", num_compare, num_move);
    st[3].num_compare = num_compare;
    st[3].num_move = num_move;
    strcpy(st[3].name, "冒泡排序算法");
}
void op5(int a[])
{
    GetRandArray(a);
    printf("已经生成1000个新的随机数\n");

    //打印排序前的数组
    printArray(a);
    num_compare = 0;
    num_move = 0;
    QuickSort(a, 0, MAX);
    cout<<"\n利用快速排序算法后的数列如下："<<endl;
    //打印排序后的数组
    printArray(a);
    printf("\n\n快速排序算法：\n一共比较了%d次，移动了%d次\n", num_compare, num_move);
    st[4].num_compare = num_compare;
    st[4].num_move = num_move;
    strcpy(st[4].name, "快速排序算法");
}
void op6(int a[])
{
	GetRandArray(a);
    printf("已经生成1000个新的随机数\n");

    //打印排序前的数组
    printArray(a);
    num_compare = 0;
    num_move = 0;
    InsertSort2(a, MAX);
    cout<<"利用二路插入算法后的数列如下："<<endl;
    //打印排序后的数组
    printArray(a);
    printf("\n\n二路插入算法：\n一共比较了%d次，移动了%d次\n", num_compare, num_move);
    st[5].num_compare = num_compare;
    st[5].num_move = num_move;
    strcpy(st[5].name, "二路插入算法");
}
void op7(int a[])
{
	GetRandArray(a);
    printf("已经生成1000个新的随机数\n");

    //打印排序前的数组
    printArray(a);
    num_compare = 0;
    num_move = 0;
    //InsertSort2(a, MAX);
    SelectionSort(a, MAX);
    cout<<"利用选择排序算法后的数列如下："<<endl;
    //打印排序后的数组
    printArray(a);
    printf("\n\n选择排序算法：\n一共比较了%d次，移动了%d次\n", num_compare, num_move);
    st[6].num_compare = num_compare;
    st[6].num_move = num_move;
    strcpy(st[6].name, "选择排序算法");
}
void op8(int a[])
{
	GetRandArray(a);
    printf("已经生成1000个新的随机数\n");

    //打印排序前的数组
    printArray(a);
    num_compare = 0;
    num_move = 0;
    HeapSort(a, MAX);
    cout<<"利用堆排序算法后的数列如下："<<endl;
    //打印排序后的数组
    printArray(a);
    printf("\n\n堆排序算法：\n一共比较了%d次，移动了%d次\n", num_compare, num_move);
    st[7].num_compare = num_compare;
    st[7].num_move = num_move;
    strcpy(st[7].name, "堆排序算法");
}
void op9(int a[])
{
	GetRandArray(a);
    printf("已经生成1000个新的随机数\n");

    //打印排序前的数组
    printArray(a);
    num_compare = 0;
    num_move = 0;
    MergeSort(a, 0, MAX);
    cout<<"利用归并排序算法后的数列如下："<<endl;
    //打印排序后的数组
    printArray(a);
    printf("\n\n归并排序算法：\n一共比较了%d次，移动了%d次\n", num_compare, num_move);
    st[8].num_compare = num_compare;
    st[8].num_move = num_move;
    strcpy(st[8].name, "归并排序算法");
}
void op10(int a[])
{
    int i;
    printf("各种排序算法的比较于移动次数的对比：\n\n");
    printf("   名称          比较次数          移动次数\n");

    for (i = 0; i < 9; i++)
    {
        printf("%-18s%-18d %d\n", st[i].name, st[i].num_compare, st[i].num_move);
    }
}
int main()
{
    int a[MAX]; //列表数组
    int op;
    srand((unsigned)time(NULL)); //随机种子
    do
    {
        system("cls");
        menu();
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            op1(a);
            break;
        case 2:
            op2(a);
            break;
        case 3:
            op3(a);
            break;
        case 4:
            op4(a);
            break;
        case 5:
            op5(a);
            break;
        case 6:
            op6(a);
            break;
        case 7:
            op7(a);
            break;
        case 8:
            op8(a);
            break;
        case 9:
            op9(a);
            break;
        case 10:
            op10(a);
            break;
        default:
            break;
        }
        system("pause");

    }while(op!=11);
    return 0;
}


