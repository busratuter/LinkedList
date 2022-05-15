//2010206043 BÜŞRA TÜTER

/*
Bir bağlı doğrusal listelerde listenin ortasında yer alan elemanı silen (tuttuğu alanı belleğe geri iade eden)
bir fonksiyon yazınız (Liste 100 ya da 101 elemanlı ise 50. elamanı silecek şekilde). Fonksiyon parametre
olarak bir liste alıp güncellenen listeyi geri döndürecektir.
*/


#include <stdio.h>
#include <stdlib.h>


struct n{
	
	int x;
	struct n *next;
};

typedef struct n node;

node* ortadanSilme(node *head){
	
	node* temp=head;
	node *temp2=temp->next;
	int elemanSayisi=0;
	
	
	while(temp!=NULL){ 
		
		elemanSayisi++;
		temp=temp->next;
		
	}
	
	temp=head;
	
	for(int i=0;i<(elemanSayisi-1)/2;i++){
		
		temp=temp->next;
		temp2=temp2->next;
	}
	temp->next=temp2->next;
	free(temp2);
	
	return head;
}


int main(){
	
	node *head,*temp;
	head=NULL;
	int number,elemanSayisi=0;
	
	while(1){
		
		printf("bir sayi giriniz");
		scanf("%d",&number);
		
		if(number==-1){
			
			head=ortadanSilme(head);
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
		elemanSayisi++;
	}
}
