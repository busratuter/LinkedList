
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
		
	node *p,*q;
	
	p=r;
	q=p->next;
	
	while(q->next!=NULL){
		
		q=q->next;
		p=p->next;
		
	}
	
	p->next=NULL;
	q->next=r;
	r=q; 
	
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
