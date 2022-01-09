#include <iostream>
#include <string>
#define MAXHASH 40
#define NUM 30 //哈希表记录30人的姓名 
#define M 39   //除数 
#define MAXINT 100 //数据冲突时使用的最大数值 

using namespace std ;

struct HashTable{
	int key ;
	int search ; //查找长度 
	string name ;
}; 

int GetKey(string s) {
	
	int num = 0 ;
	for (int i = 0 ; i < s.length() ; i ++) {
		num += (int)s[i] ;
	} 
	return num ;
}

void Create(HashTable ht[], string name[]) {
	
	//哈希表初始化 
	for (int i = 0 ; i < MAXHASH ; i++) { 
		ht[i].key = -1 ;
		ht[i].search = -1 ;
		ht[i].name = "NULL" ;
	}
	
	
	for (int j = 0 ; j < NUM ; j ++) { //确保哈希表的40个位置都有被遍历到的可能 
		
		/*新建一个index，是元素在哈希表中的位置 
		 *index即为每个元素的key值
		 *哈希函数用除留余数法构造 H（key） = key % 39
		 *因为哈希表长40，mod数取39  
		 */ 
		int index ;//得到index值 
		index = GetKey(name[j])% M ; //将字符串每个字符的值相加得key
		//cout << j <<" " <<name[j] << " " <<index << endl ; 
		
		if(ht[index].key == -1) { //如果此Index位置上没有其它的数，则赋值 
		  	
			ht[index].name = name[j] ;
		  	ht[index].key = index ;
		  	ht[index].search = 1 ;
		  	
		}
		else { //如果发生数据冲突，利用线性探测法 
			for (int k = 1 ; k < MAXINT ; k ++) {
				
				int index2 = (index + k) % M ; //在Index的基础上进一步求得新的Index2 
				int search = 1 ;
				search ++ ;
				
				if(ht[index2].key == -1) { //如果Index2上没有其它值 
					ht[index2].name = name[j] ;
					ht[index2].key = index2 ;
					ht[index2].search = search ;
					break ;
				} 
				
			}
		}
	}  
}

void ShowHashTablel(HashTable ht[]) {
	
	cout << "\t\t\t" << "[序号]" << "\t" << "[哈希值]"<< "\t" << "[人名]" << "\t\t" << "[搜索长度]" << endl ; 
	for (int i = 0 ; i < MAXHASH ; i ++) {
	cout << "\t\t\t" << i << "\t" <<ht[i].key<< "\t\t" << ht[i].name << "\t\t" << ht[i].search << endl ; 	
	}
	cout << endl ;
}

float GetASL(HashTable ht[]) {
	
	int sum = 0 ;
	
	for(int i = 0 ; i < MAXHASH ; i++) {
		
		if (ht[i].key != -1) {
		    sum += ht[i].search ;	
		}
		
	}
	
	return (sum / (float)30) ;
}

int Search(string s, HashTable ht[]) {
	
	//得到待查找值的index 
	int keyIndex = GetKey(s) % M;
	
	if(ht[keyIndex].name == s) {
		
		return keyIndex ; //找到值 
		
	}
	else { //如果发生数据冲突，进入线性探测 
		
		for (int j = 1 ; j < MAXINT ; j++) {
			//得到新的哈希值 
			int keyIndex2 = (keyIndex + j) % M ; 
			if(ht[keyIndex2].name == s) { 
			
		          return keyIndex2 ;  //如果找到，返回 
		          
            	}
           	else if(ht[keyIndex2].name == "NULL"){
           		
				   break ;
				   
			   }
		}
	}
	return -1 ;
}

int main() {
	string name[NUM] = {"xvzhenhua", "xinzebin",
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
						"zhangyvqian", "zhangzijian"} ;
	
	//新建一个哈希表 
	HashTable ht[MAXHASH];
	Create(ht, name) ; 
	
	//打印出哈希表 
	cout << endl ;
	cout << "\t\t\t\t\t\t" << "哈希表" << endl ;
	cout << endl ;
	
	ShowHashTablel(ht) ; 
	
	//求取此哈希表的ASL
	cout << "此表的ASL = "<< GetASL(ht) << endl ; 
	cout << endl ;
	
	//查找哈希表实例
	cout << "查找哈希表示例:" << endl 
	<< "[如返回值为-1，说明表中无此元素]" << endl ;
	cout << "key = zhaoran" << endl ;
	cout << "其哈希值为：" << Search("zhaoran", ht) << endl;
	cout << "key = waixingren" << endl ; 
	cout << "其哈希值为：" << Search("waixingren", ht) ;
	 
	return 0 ;
}

