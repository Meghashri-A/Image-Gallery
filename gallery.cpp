#include <iostream>
#include <stdio.h>
using namespace std;
//DLL
class Gallery {
public:
    string data;
    Gallery* next;
    Gallery* prev;
};
int count=0;
Gallery* head = NULL;
void imagev();
void push(Gallery** head_ref, string new_data);
void print_img(Gallery* node);
void deletepos(class Gallery** head_ref);
void deletee(class Gallery** head_ref, class Gallery* del);
int traversal(class Gallery* head_ref);  
//void fave_add(class Gallery* node);
//QUEUE
string queue[5];
string nod;
int r=0,f=0,q_count=0;
void dellist();
void del_pass(string nod);
//array
string fav[5];
int ind=0;
void favlist();
void fav_add(class Gallery** head_ref);
int main()
{
	int ch,opt;
	cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"\t\t\t\t\t\tGALLERY\t"<<endl;
	cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
	do
	{
	cout<<"\t\t\t\t\t\t  MENU"<<endl;
	cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"1.IMAGE OPERATIONS   2.DELETED IMAGES   3.FAVOURITES    4.EXIT"<<endl;
	cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"Enter your choice : ";
	cin>>opt;
	switch(opt)
	{
		case 1:
			imagev();
			break;
		case 2:
		    dellist();
			break;
		case 3:
		    fav_add(&head);
			break;						
	}
   }while(opt!=4);
}
//LINKED LIST MODULE
void imagev()
{
  int ch,val;
  string img_name;
  do
  {
  cout<<"\n-----------------------------------------------------------------------------------------------------------------------"<<endl;
  cout<<"1.TAKE AN IMAGE 2.DELETE AN IMAGE  3.VIEW IMAGES  4.FAVOURITES 5.EXIT\n";
  cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
  cout<<"\nEnter a choice: ";
  cin>>ch;
  if(ch==1)
  {
  	if(count==5)
  	{
  		cout<<"Memory full,Delete the images to free memeory!";
  		cout<<"Press 1 for deletion";
  		cin>>val;
  		if(val==1)
  		{
  			deletepos(&head);
		  }
		  else
		  {
		  	exit;
		  }
	  }
	  else
	  {
  	cout<<"Enter image: ";
  cin>>img_name;	
  push(&head,img_name);
  print_img(head);
     }
  }
  if(ch==2)
  {
  	if(count==0)
  	{
  		cout<<"EMPTY GALLERY\n";
  		exit;
	  }
	  else
	  {
  	deletepos(&head);
  	print_img(head);
  	del_pass(nod);
  }
  }
  if(ch==3)
  {
    traversal(head);
}
if(ch==4)
{
	fav_add(&head);
}
  if(ch!=1&&ch!=2&&ch!=3&&ch!=4&&ch!=5)
  {
  	cout<<"Enter proper option!";
  }
}while(ch!=5);
}

void push(Gallery** head_ref, string new_data)
{
    Gallery* new_node = new Gallery();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    new_node->prev = NULL;
    if ((*head_ref) != NULL)
	  (*head_ref)->prev = new_node;
    (*head_ref) = new_node;
     count++;
}

void print_img(Gallery* node)
{
    Gallery* last;
    cout<<"******************************************************"<<endl;
    cout << "\tIMAGE LIST"<<endl;
    cout<<  "\t----------"<<endl;
    if(count ==0)
    {
    	cout<<"EMPTY GALLERY\n";
    	exit;
	}
	else
	{
	while (node != NULL) 
	{
        cout<<"\t    "<< node->data << "\n";
        last = node;
        node = node->next;
    }
}
    cout<<"******************************************************"<<endl;
}

void deletepos(class Gallery** head_ref)
{

    class Gallery* current = *head_ref,*node,*last;
    int i;   
	cout<<"Image name: ";
  	cin>>nod;
    for (int i = 1; current != NULL && (current->data!=nod); i++)
    {
        current = current->next;
    }    
    if (current == NULL)
    {
    	cout<<"Image doesnt exist\n";
        return;
    }
    deletee(head_ref, current);
}
void deletee(class Gallery** head_ref, class Gallery* del)
{
    if (*head_ref == NULL || del == NULL)
        return;
    if (*head_ref == del)
        *head_ref = del->next;
    if (del->next != NULL)
        del->next->prev = del->prev;
    if (del->prev != NULL)
        del->prev->next = del->next;
    delete del;
    count--;
    q_count++;
}


int traversal(class Gallery* node)  
{  
Gallery* last;
int ch,chc=0;
if(node==NULL)
{
	cout<<"EMPTY GALLERY";
	exit;
}
else
{
do
{
cout<<"1.FORWARD 2.BACKWARD 3.EXIT: "; cin>>ch;
if(ch==1)
{
	   
        cout << "**************** " << endl<<"\t"<<node->data <<endl<< " ***************"<<endl;
        last = node;
        node = node->next;
        if(node==NULL) {
		cout<<"End of image list!!";
	     ch=3;
		}
        
}
 if(ch==2)
 {
 /*	if(chc=count)
	 {
	 	cout<<"You have reached the beginning of the list"<<endl;
	 	ch=3;
	 }
	 else
	 {*/
        cout << "**************** " << endl<<"\t"<<last->data <<endl<< " ***************"<<endl;
        last = last->prev;
        if(last==NULL) {
		cout<<"Begining of image list!!"<<endl;
		exit;
		}
        chc++;
    //}
    }
}while(ch!=3);
}
}

//QUEUE MODULE
void del_pass(string nod)
{
	int op;
	if(q_count==5)
	{
		cout<<"Memory full! PLease clear the recently deleted folder!\n";
		cout<<"Press 1 to clear memory";
		cin>>op;
		if(op==1)
		{
			r=f=0;
		}
		else
		  exit;
	}
	else
	queue[r++]=nod;
	
}
void dellist()
{
	int opt;
   cout<<"LIST OF DELETED IMAGES: "<<endl;
   cout<<"******************************"<<endl;
   if(r==0||f>0)
   {
   	cout<<"No Images are deleted\n";
   	exit;
   }
   else
   {
   for(int i=f;i<r;i++)
   {
   	cout<<queue[i]<<endl;
	}	
	cout<<"******************************"<<endl;
   cout<<"Enter 1 if you want to permanently delete the first image / 2 to exit: ";
   cin>>opt;
   if(opt==1)
   {
   	f=f+1; //0->1
   	for(int i=f+1;i<r;i++) //2-----5
   {
   	cout<<queue[i]<<endl;
	}
   }
}
}

//array module
void fav_add(class Gallery** head_ref)
{
	//cout<<"hi";
	int i,opt;   
    string favi;
	do
	{
		cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"1.ADD TO FAVOURITES 2.REMOVE FROM FAVOURITES  3.VIEW FAVOURITES  4.EXIT\n";
	cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"Enter an option: ";
	cin>>opt;
	if(opt==1)
	{
	if(count==0)//on push() count+1
	{
		cout<<"No images available in the gallery!"<<endl;
		opt=4;
	}
	else
	{
	
	class Gallery* current = *head_ref,*node,*last;
	cout<<"Image name: ";
  	cin>>nod;
    for (int i = 1; current != NULL && (current->data!=nod); i++)
    {
        current = current->next;
    }    
    if (current == NULL)
    {
    	cout<<"Image doesnt exist\n";
    }
    fav[ind]=nod;
    ind++;
    }
   }
    
   if(opt==2)
   {
   	if(ind==0)
   	{
   		cout<<"FAVOURITES EMPTY!"<<endl;
	   }
	   else
	   {
   	cout<<"Image name: ";
  	cin>>favi;
  	string fav_check;
  	for(int j=0;j<ind;j++)
  	{
  		fav_check=fav[j];
  		if(fav_check==favi)
  		{
  			fav[j]=fav[j+1];
  			ind=ind-1;
  			cout<<"Image: "<<fav_check<<" Removed"<<endl;
		}
	  }
    }
   }
   if(opt==3)
   {
   	favlist();
   }
}while(opt!=4);
}
void  favlist()
{
	if(ind==0)
	{
		cout<<"FAVOURITES EMPTY!"<<endl;
	}
	if(ind>0)
	{
	cout<<"**********************"<<endl;
	cout<<"      FAVOURITES      "<<endl;
	for(int i=0;i<ind;i++)
	{
		cout<<"\t"<<fav[i]<<endl;
	}
	cout<<"**********************"<<endl;
   }
}

