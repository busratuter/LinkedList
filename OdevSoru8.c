// 2010206043 BÜÞRA TÜTER

/*
Bir bagli dogrusal listelerde listenin sonundaki dügüm ile basindaki dügümün yerini degistiren
changeFirstAndLast isimli bir fonksiyon yaziniz. Fonksiyon parametre olarak bir liste alip guncellenen
listeyi geri döndürecektir.
*/




#include <stdio.h>
#include <stdlib.h>


struct n{
	
	int x;
	struct n *next;
};

typedef struct n node;

node* changeFirstandLast(node *head){
	
	node*temp=head;
	node *temp2=temp->next;
	
	while(temp2->next!=NULL){
		temp=temp->next;
		temp2=temp2->next;
	}
	temp2->next=head->next;
	head->next=NULL; 
	temp->next=head;
	head=temp2;
	
	return head;
}


int main(){
	
	node *head,*temp;
	head=NULL;
	int number;
	
	while(1){
		
		printf("bir sayi giriniz");
		scanf("%d",&number);
		
		if(number==-1){
			
			head=changeFirstandLast(head);
			while(head!=NULL){
				
 				printf("%d ",head->x);
 				head=head->next;
 			}
 			break;
 			
		}
		
		if(head==NULL){
			
			head=(node*)malloc(sizeof(node));
			temp=head;
			
		}else{
			temp->next=(node*)malloc(sizeof(node));
			temp=temp->next;
		}
		
		temp->x=number;
		temp->next=NULL;
	}
}
