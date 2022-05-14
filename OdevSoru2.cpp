// 2010206043 BÜÞRA TÜTER

/*
Bir baðlý doðrusal listelerde listenin sonundaki düðümü keserek listenin baþýna ekleyen ve oluþan listenin
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

node* cutlastaddhead(node *r){
		
	node *temp,*temp2;
	
	temp=r;
	temp2=temp->next;
	
	while(temp2->next!=NULL){
		
		temp2=temp2->next;
		temp=temp->next;
		
	}
	
	temp->next=NULL;
	temp2->next=r;
	r=temp2; 
	
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
			
			root=cutlastaddhead(root);
			printf("Listenin son hali:\n");
			bastir(root);
			break;
		}
		
		else{
			root = listeolusturma(root,x);
		}
}
}
