#include <stdio.h>
#include <stdlib.h>


struct Node {
		
		int data;
		struct node* next;
		
		
	};
	
int main(){
	
	/*
	
	Danh sach lien ket don :  la tap hop cac
	   
	   node dc phan bo dong 
	
	Moi phan tu trong lien ke don dc goi la node(nút)
	model (nút) gom
	   2 thanh phan 
	   node  = 1 gia tri (data)
	   1 con tro(next)
	   neu tro den null la tro den phan tu cuoi cung
	   
	   
	   +) Cac kieu danh sach lien ket : ds lien ket don, doi , 
	   
	   phan tu dau den cuoi goi la vong
	   
	
	*/
	
	
	//tao cau truc trong danh sach don
	
	//con tro va mang mot chieu giong nhau 
	
	struct Node* node;
	//su dung ham cap phat bo nho
	node = (struct Node*)malloc(sizeof(struct Node*));
	
	node->data = 11;
	node->next = NULL;//tro den phan tu ke tiep , null la phan tu cuoi cun
	
	printf("Gia tri %d\n", node->data);
	
	
	
	return 0;
	
}





























