// 2010206043 BÜÞRA TÜTER

/*
Bir baðlý doðrusal listelerde listenin baþýndaki düðümü keserek listenin sonuna ekleyen ve oluþan listenin
son halini geri döndüren prototipi aþaðýda verilmiþ fonksiyonu yazýnýz.
*/   


#include <stdio.h>
#include <stdlib.h>

struct n{
 int x;
 struct n * next;
};

typedef struct n node;

void bastir(node *r){
	
 while(r!=NULL){
  printf("%d ",r->x);
  r=r->next;
 }
 
}


node * listeolusturma(node * r, int x){
	
 if(r==NULL){		//dugume ilk elemani ekliyorum
  					
  r=(node*)malloc(sizeof(node));
  r->next= NULL;
  r->x = x;
  return r;
  
 }
 
 node * p = r;
 
 while (p-> next != NULL ){
  p= p -> next;
  
 }
 
 node * temp = (node*)malloc(sizeof(node));
 temp -> next = p -> next;
 p -> next = temp;
 temp -> x = x;
 return r;
 
}

node* cutheadaddlast(node *r){
		
	node *temp,*temp2;
	
	temp=r;
	temp2=r;
	
	while(temp->next!=NULL){

		temp=temp->next; 
		
	}
	
	temp->next=temp2;
	r=temp2->next;
	temp2->next=NULL; 
	
	return r;
		
}

int main(){
	
 node * root;
 root = NULL;
 int x;

 while(1){
		
		printf("Bir sayi giriniz:");
		scanf("%d",&x);
		
		if(x == -1) {
			
			root=cutheadaddlast(root);
			printf("Listenin son hali:\n");
			bastir(root);
			break;
		}
		
		else{
			root = listeolusturma(root,x);
		}
}
}
