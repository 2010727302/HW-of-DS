#include<iostream>
#include<string>
#define R 2
#define M 30
#define m 40
#define KeyType int
#define InfoType string
#define H(a) (a%39)
#define NULLKEY -1
#define MAX 100
using namespace std;
int hash_list[m];
int count=0;
typedef struct ht
{
    KeyType key;
    InfoType otherinfo;
}HashTable[m];
int To_Key(string t)
{
    int num=0;
    for(int i=0;i<t.length();++i)
    {
        num+=(int)t[i];
    }
    return num;
}
int SearchHash(HashTable HT,InfoType info)
{
    int H0=H(To_Key(info));
    count=1;   
    if(HT[H0].otherinfo==info)
    {  
        return H0;//查找成功
    }
    else
    {  
        for(int i=1;i<MAX;++i)
        {
            int Hi=(H0+i)%m;//线性探测法
            count++;   
            if(HT[Hi].otherinfo==info)
            {
                return Hi;
            }
            else if(HT[Hi].key==NULLKEY)
            {
                break;
            }
        }  
    }
    return -1;
}
 
void Create(HashTable HT,string name[])
{
    for(int i=0;i<m;++i) HT[i].key=NULLKEY;
    for(int i=0;i<M;++i)
    {
        int H0=H(To_Key(name[i]));
        if(HT[H0].key==NULLKEY)
        {  
            HT[H0].otherinfo=name[i];
            HT[H0].key=H0;
        }
        else
        {
            for(int j=1;j<MAX;++j)
            {
                int Hi=(H0+j)%m;//线性探测法
                if(HT[Hi].key==NULLKEY)
                {
                    HT[Hi].otherinfo=name[i];
                    HT[Hi].key=Hi;
                    break;
                }
            }
        }
    }
}
void PrintTable(HashTable HT)
{
    for(int i=0;i<50;++i)printf("*");
    cout<<endl;
    printf("[id号]%2c\t[哈希值]->[人名]\n",' ',' ');
    for(int i=0;i<m;++i)
    {
        printf("%-4d:\t%8d->\t",i,HT[i].key);
        cout<<HT[i].otherinfo<<endl;
    }
    for(int i=0;i<50;++i)printf("*");
    cout<<endl;
}
double ASL(HashTable HT,string name[])
{
    double re=0;
    for(int i=0;i<M;++i)
    {
         SearchHash(HT,name[i]);
//       cout<<name[i]<<" = "<<count<<endl;
         re+=count;     
    }
 
    return re/(double)M;
}
int main()
{
    string name[M]={
        "raoxinyu",     "chenbinxuan",
        "chenguangyang",        "chenluying",
        "chenshiyi",        "chenxin",
        "dengsiqi",     "heyuqi",
        "hejie",        "jiangshuyu",
        "jiangtianyu",      "jinguanghui",
        "kangxi",       "liyanxing",
        "limengyi",     "lirui",
        "liyanxin",     "lizongrui",   
        "liuqiang",     "meixuanqing",
        "qijie",        "qiuyisheng",
        "shenyihui",        "suimengyi",
        "taoli",        "wangdanna",
        "wangjingru",       "zhangluyao",
        "zhaolin",      "zhangyilun",  
    };
//  string exame[m];
//  for(int i=0;i<M;++i)
//  {
//      int temp=To_Key(name[i]);
//       cout<<name[i]<<"\t"<<temp<<"\t"<<H(temp)<<endl;
//  }  
    cout<<"\t\t\t\n线性探测再散列法处理冲突\n";
    HashTable HT;
    Create(HT,name);
    PrintTable(HT);
     
    cout<<"ASL[success]:"<<ASL(HT,name)<<"\t小于R:"<<R<<'\n';
    return 0;
}
