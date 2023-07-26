#include <stdio.h>
#define SIZE 5
//-1 the hien ban dau deu la rong thi deu gan la am 1 Queue
int items[SIZE], font = -1 , rear = -1;

//them gia tri
void enQueue(int value){
	
	if(rear == SIZE -1){
		
		printf("Ham doi day");
		
	}else{
		
		if(font == -1){
			 
			 font = 0;
			
		}
		
		rear++;
		items[rear] = value;
		printf("Them gia tri %d tai vi tri %d \n", value, rear);
		
	}
	
	
}
//ham xoa 
void deQueue(){
	
	//xoa thang cuoi cung 
	
	if(font==-1){
		
		printf("Hang doi dang rong !");
		
	}else{
		
		printf("Vi tri da xoa tai vi tri %d\n", font+1);
		font++;
		if(font> rear){
			
			font = -1;
			rear = -1;
			
		}
		
	}
	
}

//ham hien thi
void display(){
	//font là dau 
	//rear là cuoi
	
	if(rear == -1){
		
		printf("Hang doi rong !");
		
	}else{
		
		for(int i= font; i <= rear ; i++ ){
			
			printf("%d\t \n", items[i]);
			
		}
		
		
	}
	
	
}


int main(){
	
	enQueue(7);
	enQueue(5);
	enQueue(3);
	enQueue(4);
//	enQueue(3);
	
	//xoa phan tu vi tri cuoi cung
	display();
	deQueue();
	display();
	
   return 0;
	
}
