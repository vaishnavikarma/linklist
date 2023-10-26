#include<iostream>
#include<malloc.h>
using namespace std;
struct node{
	int data;
	struct node* add;
	}
*START=NULL,*PTR,*TEMP,*PREV;
void InsBeg(){
	int value;
	PTR = (struct node*)malloc(sizeof(struct node));
	cout<<"Enter the Number to be entered : ";
	cin>>value;
	if(PTR==NULL){
		cout<<"Linked list is full !"<<endl;
	}
	else{
		cout<<"\n"<<value<<" was pushed successfully !"<<endl;
		PTR->data = value;
		PTR->add = START;
		START = PTR;
	}
}
void InsEnd(){
	int value;
	PTR = (struct node*)malloc(sizeof(struct node));
	cout<<"Enter the value of the element : ";
	cin>>value;
	PTR->data = value;
	PTR->add = NULL;
	if(PTR==NULL){
		cout<<"Linked list is full !"<<endl;
	}
	cout<<"\n"<<value<<" was pushed successfully !"<<endl;
	if(START==NULL){
		START = PTR;
	}
	else
	{	TEMP = START;
		while(TEMP->add!=NULL){
			TEMP = TEMP->add;
		}
		TEMP->add = PTR;
	}
}
void InsSpec(){
	int pos,value,current_position;
	cout<<"Enter the value of the Element : ";
	cin>>value;
	PTR = (struct node*)malloc(sizeof(struct node));
	PTR->data = value;
	if(PTR==NULL){
		cout<<"\nLinked list is Full !"<<endl;
	}
	cout<<"Enter the desired position : ";
	cin>>pos;
	if(pos==1){
		PTR->add = START;
		START = PTR;
		cout<<"\n"<<START->data<<" was pushed at "<<pos<<" successfully !"<<endl;
	}
	else{
		current_position = 1;
		TEMP = START;
		while(current_position<1){
			TEMP = TEMP->add;
			current_position++;
		}
		PTR->add = TEMP->add;
		TEMP->add = PTR;
	}	
	
}
void DelBeg(){
	if(START==NULL){
		cout<<"\nLinked list is empty !"<<endl;
	}
	else{
		TEMP = START;
		START = START->add;
		cout<<TEMP->data<<" was deleted successfully !"<<endl;
		free(TEMP);
	}
}
void DelEnd(){
	if(START==NULL){
		cout<<"\nLinked list is empty !"<<endl;
	}
	TEMP = START;
	if(TEMP->add==NULL){
		cout<<"\n"<<TEMP->data<<" was deleted successfully !"<<endl;
	}
	else{
		while(TEMP->add!=NULL){
			PREV = TEMP;
			TEMP = TEMP->add;
		}
		cout<<"\n"<<TEMP->data<<" was deleted successfully !"<<endl;
		PREV->add = TEMP->add;
		free(TEMP);
	}
}
void DelSpec(){
	int pos,current_position;
	if(START==NULL){
		cout<<"\nLinked list is empty !\n";
	}
	else{
	cout<<"\nEnter the position of deletion : ";
	cin>>pos;
	current_position = 1;
	TEMP = START;
	if(pos==1){
		cout<<START->data<<" was deleted from "<<pos<<" successfully !";
		START = START->add;
		free(TEMP);
	}
	else{
	while(current_position<pos){
	PREV = TEMP;
	TEMP = TEMP->add;
	current_position++;
	}
	cout<<TEMP->data<<" was deleted from "<<pos<<" successfully !";
	PREV->add = TEMP->add;
	free(TEMP);
	}
	}
}
void Display(){
	if(START==NULL){
		cout<<"\nLinked list is empty !\n"<<endl;
	}
	else{
		TEMP = START;
		cout<<"\nLinked list : ";
		while(TEMP!=NULL){
		cout<<TEMP->data<<" ";
		TEMP = TEMP->add;
		}
	}
}
int main(){
	cout<<"vaishnavi karma"<<endl;
	cout<<"0832CS221216";
	cout<<"\n";
	int choice;
	do{
		cout<<"\n\nPress 1 for Insertion at Beginning\n";
		cout<<"\nPress 2 for Insertion at End\n";
		cout<<"\nPress 3 for Insertion at Specified Position\n";
		cout<<"\nPress 4 for Deletion at Beginning\n";
		cout<<"\nPress 5 for Deletion at End\n";
		cout<<"\nPress 6 for Deletion at Specified Position\n";
		cout<<"\nPress 7 to  Display the Elements\n";
		cout<<"\n\nPlease enter your choice : ";
		cin>>choice;
		switch(choice){
			case 1:
				InsBeg();
				break;
			case 2:
				InsEnd();
				break;
			case 3:
				InsSpec();
				break;
			case 4:
				DelBeg();
				break;
			case 5:
				DelEnd();
				break;
			case 6:
				DelSpec();
				break;
			case 7:
				Display();
				break;
			default:
				cout<<"\nInvalid choice !...\n\n";
		}
	}while(choice!=0);
}
