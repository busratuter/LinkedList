// 2010206043 BÜÞRA TÜTER

/*
Kendisine parametre olarak aktarýlan head isimli liste ve age yaþ parametresine göre iþlem yapan 
fonksiyon, listedeki age yaþ deðerine sahip ikinci düðümü bularak silmektedir (bu düðümü belleðe iade 
etmekte). Aþaðýda verilen prototipi kullanarak gerekli fonksiyonu yazýnýz
*/


#include <stdio.h>
#include <stdlib.h>


struct n{
	
	int age;
	char name[20];
	struct n *next;
};

typedef struct n node;

node* deleteNode(node*head,int yas){
	
	node*temp=head;
	node *temp2=temp->next;
	
	if(temp->age==yas){ // ilk elemani siliyor
		head=temp2;
		free(temp);
		
		return head;
	}
	
	while(temp2!=NULL){
		
		if(temp2->age==yas){
			
			temp->next=temp2->next;
			free(temp2);
			
			return head;
			
		}else{
			temp=temp->next;
			temp2=temp2->next;
		}

	}
}

int main(){
	
	node *head,*temp;
	head=NULL;
	int x,yas;
	
	while(1){
		
		printf("yas giriniz");
		scanf("%d",&x);
		
		if(x==-1) break;/*{
			while(head!=NULL){
				
 				printf("%d ",head->age);
 				head=head->next;
 			}
 			break;
 			
		} */
		
		if(head==NULL){
			
			head=(node*)malloc(sizeof(node));
			temp=head;
			
		}else{
			temp->next=(node*)malloc(sizeof(node));
			temp=temp->next;
		}
		
		temp->age=x;
		temp->next=NULL;
	}
	
	printf("bulup silmek istediginiz yasi giriniz");
	scanf("%d",&yas);
	
	head=deleteNode(head,yas);
	
	while(head!=NULL){
				
 		printf("%d ",head->age);
 		head=head->next;
 	}
	
	
	
}
