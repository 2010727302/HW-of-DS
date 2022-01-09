#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <ctime>
#include <iostream>
#define MAX 1000
using namespace std;
typedef struct SORTTYPE
{
    char name[30]; //��������
    int num_compare;       //�ȽϵĴ���
    int num_move;       //�ƶ��Ĵ���
} ST;        //�洢����Ч�ʵ�����
int num_compare = 0, num_move = 0; //�ؼ��ֱȽϺ��ƶ��Ĵ���
ST st[9];                 //9���㷨�ķ�������

//ֱ�Ӳ��������㷨
void InsertSort(int a[], int n)
{
    int i, j;
    int temp;
    for (i = 1; i < n; i++) //forѭ����һ���Ƚ���n-1�Σ�if�ж����
    {
        if (a[i] < a[i - 1]) //һ������������Ĺؼ��֣��ͽ��в���
        {
            temp = a[i];
            j = i - 1;
            num_compare++;
            do //�����ƶ�һ��λ�ã��ڿռ��temp��
            {
                a[j + 1] = a[j];
                num_move++; //�ƶ���һ
                j--;
                num_compare++; //�Ƚϴ�����һ
            }
            while (j >= 0 && a[j] > temp);

            a[j + 1] = temp; //����temp���ڶ�Ӧ��λ��
            num_move += 2;  //�ƶ���temp
        }
    }
}
//�۰��������
//�����������۰������Ѱ�ҵĸĽ��㷨
void BinInsertSort(int a[], int n)
{
    int i, j, low, high, mid;
    int temp;
    for (i = 1; i < n; i++) //�Ѿ��Ƚ���n-1��
    {
        if (a[i] < a[i - 1])
        {
            temp = a[i];
            low = 0;
            high = i - 1;
            num_compare++;
            while (low <= high)
            {
                num_compare++; //while����Ƚ�
                mid = (low + high) / 2;
                if (temp < a[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            for (j = i - 1; j >= high + 1; j--)
            {
                a[j + 1] = a[j];
                num_move++; //�ƶ�������һ
            }
            a[high + 1] = temp;
            num_move += 2; //temp����
        }
    }
}
//��·����
//������ѭ������ 
void InsertSort2(int a[], int n)    
{
	int first=0, last=0;
	int *b = new int[n];//bѭ������ 
	 
	b[0] = a[0];//��ʼ�� 
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
			num_compare+=2; //��b[last]��b[first]�Ƚ� 
			last=(last + 1) % n;
			b[last] = a[i];
			num_move++;
		}
		else
		{
			num_compare+=2;
			int low, high, mid, d;
			low = first, high = last;
			while (low != high)      //�۰����
			{
				num_compare++;
				d = (high-low+n) % n;    //Ԫ�ظ���
				mid = (low + d / 2) % n;    //�м�λ��
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
			for (int k = last + 1; k != low; k = (k - 1 + n) % n)  //�ƶ�Ԫ��
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
//ϣ�������㷨
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
            num_move += 2; //temp�������β���
        }
        d = d / 2;
    }
}
//ð�������㷨
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
//��pivot�����л�Ϊ��������
int Partition(int a[], int low, int high)
{
	int pivot=a[low];//����һ��Ԫ����Ϊpivot
	while(low < high) 
	{
		while(low < high && a[high] >= pivot)
		{
			high --;//�ҵ���pivot С��Ԫ�� 
			num_compare++; //���бȽ�
		}
		a[low]=a[high];//�Ƶ����
		num_move++;  //�ƶ�++
		while(low < high && a[low] <= pivot)
		{
			low ++;//�ҵ���pivot���Ԫ�� 
			num_compare++; //���бȽ�
		} 
		a[high] = a[low];//�Ƶ��� 
		num_move++;  //�ƶ�++
	}
	//����ѭ����ʾ�ҵ�pivotλ�� 
	a[low]=pivot;
	num_move +=2;  //�ƶ�+2
	return low; 
 } 
 //���������㷨
void QuickSort(int a[], int low, int high)
{
	if(low <high)//�ݹ��������� 
	{
		int pos=Partition(a, low, high);
		QuickSort(a, low, pos-1);//�������ӱ�
		QuickSort(a, pos+1, high);//�������ӱ�
	}
}
//ѡ�������㷨 
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
    int temp = a[parent]; // temp���浱ǰ���ڵ�
    int child = 2 * parent + 1; // �Ȼ������
 
    while (child < length) 
	{
        // ������Һ��ӽ�㣬�����Һ��ӽ���ֵ�������ӽ�㣬��ѡȡ�Һ��ӽ��
        if (child + 1 < length && a[child] < a[child + 1]) 
		{
            child++;
        }
 
        // ���������ֵ�Ѿ����ں��ӽ���ֵ����ֱ�ӽ���
        if (temp >= a[child])
        {
        	num_compare++;
			break;
		}
            
        // �Ѻ��ӽ���ֵ���������
        a[parent] = a[child];
 		num_move++;
        // ѡȡ���ӽ������ӽ��,��������ɸѡ
        parent = child;
        child = 2 * child + 1;
    }
 
    a[parent] = temp;
    num_move+=2;
}
 //������ 
void HeapSort(int a[], int n) 
{
    // ѭ��������ʼ��
    for (int i = n / 2; i >= 0; i--) 
	{
        HeapAdjust(a, i, n);
    }
 
    // ����n-1��ѭ�����������
    for (int i = n - 1; i > 0; i--) 
	{
        // ���һ��Ԫ�غ͵�һԪ�ؽ��н���
        swap(a[i], a[0]);
 		num_move+=3;
        // ɸѡ R[0] ��㣬�õ�i-1�����Ķ�
        HeapAdjust(a, 0, i);
        //System.out.format("�� %d ��: \t", n - i);
        //printPart(a, 0, a.length - 1);
    }
}

void merge(int a[],int l,int r,int mid)
{
  int aux[r-l+1],i,j,k;//aux�������� 
  
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
	
	int mid=(l+r)/2;//���м� 
	
	merge_sort(a,l,mid);//�鲢��� 
	merge_sort(a,mid+1,r);//�鲢�ұ� 
	merge(a,l,r,mid);//�ϲ�	
	
}
 //�鲢����
void MergeSort(int a[],int l,int r)
{
	merge_sort(a,l,r-1);
}
//���˵� 
void menu()
{
    printf("\t\t1.ֱ�Ӳ�������\n");
    printf("\t\t2.�۰��������\n");
    printf("\t\t3.ϣ������\n");
    printf("\t\t4.ð������\n");
    printf("\t\t5.��������\n");
    printf("\t\t6.��·����\n");
    printf("\t\t7.��ѡ������\n");
    printf("\t\t8.������\n");
    printf("\t\t9.�鲢����\n");
    printf("\t\t10.Ч�ʱȽ�\n");
    printf("\t\t11.�˳�\n");
    printf("��ѡ�������");
}
//��ӡ��������
void printArray(int a[]) 
{
    int i;
    for (i = 0; i < MAX; i++)
        printf("%2d%c", a[i], (i+1)%40 ? ' ' : '\n');
    putchar(10);
}
//Ϊ�����������
void GetRandArray(int a[]) 
{
    int i;
    for (i = 0; i < MAX; i++)
        a[i] = rand() % 100;
}
//���ø��������ʵ�ֺ���
void op1(int a[])
{
    GetRandArray(a);
    printf("α������Ѿ����ɵ�1000���µ������\n");
    //��ӡ����ǰ������
    printArray(a);
    InsertSort(a, MAX);
    cout<<"����ֱ�Ӳ����������������£�"<<endl;
    //��ӡ����������
    printArray(a);
    printf("\n\nֱ�Ӳ������򷨣�\nһ���Ƚ�%d���ƶ�%d\n", num_compare, num_move);
    st[0].num_compare = num_compare;
    st[0].num_move = num_move;
    strcpy(st[0].name, "ֱ�Ӳ�������");
}
void op2(int a[])
{
    GetRandArray(a);
    printf("�Ѿ�����1000���µ������\n");
    //��ӡ����ǰ������
    printArray(a);
    num_compare = 0;
    num_move = 0;
    BinInsertSort(a, MAX);
    cout<<"�����۰�����������������£�"<<endl;
    //��ӡ����������
    printArray(a);
    printf("\n\n�۰��������\nһ���Ƚ���%d�Σ��ƶ���%d��\n", num_compare, num_move);
    st[1].num_compare = num_compare;
    st[1].num_move = num_move;
    strcpy(st[1].name, "�۰��������");
}
void op3(int a[])
{
    GetRandArray(a);
    printf("�Ѿ�����1000���µ������\n");
    //��ӡ����ǰ������
    printArray(a);
    num_compare = 0;
    num_move = 0;
    ShellSort(a, MAX);
    cout<<"\n����ϣ�������㷨����������£�"<<endl;
    //��ӡ����������
    printArray(a);
    printf("\n\nϣ�������㷨��\nһ���Ƚ���%d�Σ��ƶ���%d��\n", num_compare, num_move);
    st[2].num_compare = num_compare;
    st[2].num_move = num_move;
    strcpy(st[2].name, "ϣ�������㷨");
}
void op4(int a[])
{
    GetRandArray(a);
    printf("�Ѿ�����1000���µ������\n");

    //��ӡ����ǰ������
    printArray(a);

    num_compare = 0;
    num_move = 0;
    BubbleSort(a, MAX);

    cout<<"����ð�����򷨺���������£�"<<endl;
    //��ӡ����������
    printArray(a);

    printf("\n\nð�������㷨��\nһ���Ƚ���%d�Σ��ƶ���%d��\n", num_compare, num_move);
    st[3].num_compare = num_compare;
    st[3].num_move = num_move;
    strcpy(st[3].name, "ð�������㷨");
}
void op5(int a[])
{
    GetRandArray(a);
    printf("�Ѿ�����1000���µ������\n");

    //��ӡ����ǰ������
    printArray(a);
    num_compare = 0;
    num_move = 0;
    QuickSort(a, 0, MAX);
    cout<<"\n���ÿ��������㷨����������£�"<<endl;
    //��ӡ����������
    printArray(a);
    printf("\n\n���������㷨��\nһ���Ƚ���%d�Σ��ƶ���%d��\n", num_compare, num_move);
    st[4].num_compare = num_compare;
    st[4].num_move = num_move;
    strcpy(st[4].name, "���������㷨");
}
void op6(int a[])
{
	GetRandArray(a);
    printf("�Ѿ�����1000���µ������\n");

    //��ӡ����ǰ������
    printArray(a);
    num_compare = 0;
    num_move = 0;
    InsertSort2(a, MAX);
    cout<<"���ö�·�����㷨����������£�"<<endl;
    //��ӡ����������
    printArray(a);
    printf("\n\n��·�����㷨��\nһ���Ƚ���%d�Σ��ƶ���%d��\n", num_compare, num_move);
    st[5].num_compare = num_compare;
    st[5].num_move = num_move;
    strcpy(st[5].name, "��·�����㷨");
}
void op7(int a[])
{
	GetRandArray(a);
    printf("�Ѿ�����1000���µ������\n");

    //��ӡ����ǰ������
    printArray(a);
    num_compare = 0;
    num_move = 0;
    //InsertSort2(a, MAX);
    SelectionSort(a, MAX);
    cout<<"����ѡ�������㷨����������£�"<<endl;
    //��ӡ����������
    printArray(a);
    printf("\n\nѡ�������㷨��\nһ���Ƚ���%d�Σ��ƶ���%d��\n", num_compare, num_move);
    st[6].num_compare = num_compare;
    st[6].num_move = num_move;
    strcpy(st[6].name, "ѡ�������㷨");
}
void op8(int a[])
{
	GetRandArray(a);
    printf("�Ѿ�����1000���µ������\n");

    //��ӡ����ǰ������
    printArray(a);
    num_compare = 0;
    num_move = 0;
    HeapSort(a, MAX);
    cout<<"���ö������㷨����������£�"<<endl;
    //��ӡ����������
    printArray(a);
    printf("\n\n�������㷨��\nһ���Ƚ���%d�Σ��ƶ���%d��\n", num_compare, num_move);
    st[7].num_compare = num_compare;
    st[7].num_move = num_move;
    strcpy(st[7].name, "�������㷨");
}
void op9(int a[])
{
	GetRandArray(a);
    printf("�Ѿ�����1000���µ������\n");

    //��ӡ����ǰ������
    printArray(a);
    num_compare = 0;
    num_move = 0;
    MergeSort(a, 0, MAX);
    cout<<"���ù鲢�����㷨����������£�"<<endl;
    //��ӡ����������
    printArray(a);
    printf("\n\n�鲢�����㷨��\nһ���Ƚ���%d�Σ��ƶ���%d��\n", num_compare, num_move);
    st[8].num_compare = num_compare;
    st[8].num_move = num_move;
    strcpy(st[8].name, "�鲢�����㷨");
}
void op10(int a[])
{
    int i;
    printf("���������㷨�ıȽ����ƶ������ĶԱȣ�\n\n");
    printf("   ����          �Ƚϴ���          �ƶ�����\n");

    for (i = 0; i < 9; i++)
    {
        printf("%-18s%-18d %d\n", st[i].name, st[i].num_compare, st[i].num_move);
    }
}
int main()
{
    int a[MAX]; //�б�����
    int op;
    srand((unsigned)time(NULL)); //�������
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


