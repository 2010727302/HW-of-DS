#include <iostream>
#include <string>
#define MAXHASH 40
#define NUM 30 //��ϣ���¼30�˵����� 
#define M 39   //���� 
#define MAXINT 100 //���ݳ�ͻʱʹ�õ������ֵ 

using namespace std ;

struct HashTable{
	int key ;
	int search ; //���ҳ��� 
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
	
	//��ϣ���ʼ�� 
	for (int i = 0 ; i < MAXHASH ; i++) { 
		ht[i].key = -1 ;
		ht[i].search = -1 ;
		ht[i].name = "NULL" ;
	}
	
	
	for (int j = 0 ; j < NUM ; j ++) { //ȷ����ϣ���40��λ�ö��б��������Ŀ��� 
		
		/*�½�һ��index����Ԫ���ڹ�ϣ���е�λ�� 
		 *index��Ϊÿ��Ԫ�ص�keyֵ
		 *��ϣ�����ó������������� H��key�� = key % 39
		 *��Ϊ��ϣ��40��mod��ȡ39  
		 */ 
		int index ;//�õ�indexֵ 
		index = GetKey(name[j])% M ; //���ַ���ÿ���ַ���ֵ��ӵ�key
		//cout << j <<" " <<name[j] << " " <<index << endl ; 
		
		if(ht[index].key == -1) { //�����Indexλ����û��������������ֵ 
		  	
			ht[index].name = name[j] ;
		  	ht[index].key = index ;
		  	ht[index].search = 1 ;
		  	
		}
		else { //����������ݳ�ͻ����������̽�ⷨ 
			for (int k = 1 ; k < MAXINT ; k ++) {
				
				int index2 = (index + k) % M ; //��Index�Ļ����Ͻ�һ������µ�Index2 
				int search = 1 ;
				search ++ ;
				
				if(ht[index2].key == -1) { //���Index2��û������ֵ 
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
	
	cout << "\t\t\t" << "[���]" << "\t" << "[��ϣֵ]"<< "\t" << "[����]" << "\t\t" << "[��������]" << endl ; 
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
	
	//�õ�������ֵ��index 
	int keyIndex = GetKey(s) % M;
	
	if(ht[keyIndex].name == s) {
		
		return keyIndex ; //�ҵ�ֵ 
		
	}
	else { //����������ݳ�ͻ����������̽�� 
		
		for (int j = 1 ; j < MAXINT ; j++) {
			//�õ��µĹ�ϣֵ 
			int keyIndex2 = (keyIndex + j) % M ; 
			if(ht[keyIndex2].name == s) { 
			
		          return keyIndex2 ;  //����ҵ������� 
		          
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
	
	//�½�һ����ϣ�� 
	HashTable ht[MAXHASH];
	Create(ht, name) ; 
	
	//��ӡ����ϣ�� 
	cout << endl ;
	cout << "\t\t\t\t\t\t" << "��ϣ��" << endl ;
	cout << endl ;
	
	ShowHashTablel(ht) ; 
	
	//��ȡ�˹�ϣ���ASL
	cout << "�˱��ASL = "<< GetASL(ht) << endl ; 
	cout << endl ;
	
	//���ҹ�ϣ��ʵ��
	cout << "���ҹ�ϣ��ʾ��:" << endl 
	<< "[�緵��ֵΪ-1��˵�������޴�Ԫ��]" << endl ;
	cout << "key = zhaoran" << endl ;
	cout << "���ϣֵΪ��" << Search("zhaoran", ht) << endl;
	cout << "key = waixingren" << endl ; 
	cout << "���ϣֵΪ��" << Search("waixingren", ht) ;
	 
	return 0 ;
}

