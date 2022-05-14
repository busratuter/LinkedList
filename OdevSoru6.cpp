// 2010206043 B��RA T�TER

/*
Klavyeden -1 girilene kadar verilen �ift say�lar� tek ba�l� do�rusal bir listenin ba��na
verilen tek say�lar� ise listenin sonuna ekleyen program� yaz�n�z.
*/


#include <stdio.h>
#include <stdlib.h>


struct n{
 int x;
 struct n * next;
};

typedef struct n node;

void yazdirma(node *r){
	
 while(r!=NULL){
 	
  printf("%d ",r->x);
  r=r->next;
  
 }
}


node * ekleSirali(node * r, int x){
	
 if(r==NULL){      //listeye ilk elemani ekliyoruz
 
  r=(node*)malloc(sizeof(node));
  r->next= NULL;
  r->x = x;
  return r;
  
 }
 
 
 if(x%2==0){ // sayi cift ise basa ekleme yapar
 
  node * temp = (node*)malloc(sizeof(node));
  temp -> x = x;
  temp -> next = r;
  return temp;
  
  
 }
 
 node * iter = r;
  
 while (x%2==1 && iter -> next != NULL){ // tek sayilari sona ekler
 	
  iter= iter -> next;
  
 }
 
 node * temp = (node*)malloc(sizeof(node));
 temp -> next = iter -> next;
 iter -> next = temp;
 temp -> x = x;
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
			printf("Listenin son hali:\n");
			yazdirma(root);
			break;
		}
		
		else{
			root = ekleSirali(root,x);
		}
	
}
 

}
