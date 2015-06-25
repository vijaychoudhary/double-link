#include<stdio.h.>
#include<stdlib.h>
struct dnode {
	int value;
	struct dnode *next;
    struct dnode *previous;
};

typedef struct dnode dNode;

dNode *head;
dNode *tail;
dNode *pointer;
dNode *temp;



void insert(int);
int fetch(int);
void display();
int search(int);
int find;
void main()
{
    int choice;
	int value;
	int index;
    int srch;
	while(1) {
		printf("What do you want to do in doubly linklist?\n\n");
		printf("1. Insert \n2. Fetch \n3. display \n4. Search \n5.Exit \n");
		scanf("%d", &choice);
		
		switch(choice) {
			case 1:
				printf("\nEnter the value you want to insert!\n");
				scanf("%d", &value);
				insert(value);
				printf("\nInserted the value %d into linkedList\n", value); 
				break;
			case 2:
				printf("\nValue at what index you want to fetch\n");
				scanf("%d", &index);
				value = fetch(index);
				printf("\nValue at index %d is %d\n", index, value);
             
				break;
			case 3:
				
				display();
                break;
         case 4:
               printf("\nEnter the value U want to search\n");
				 scanf("%d", &srch);
               find=search(srch);
               printf("%d\n", find);
               break;
           case 5:
                   printf("\nExiting...\n"); 
                  exit(0);   
			default:
				break;
		}
	}
}
void insert(int value) {
     dNode *var;
     var=( dNode *)malloc(sizeof(dNode));
     var->value=value;
     if(head==NULL)
        {
          head=var;
          head->previous=NULL;
          head->next=NULL;
          tail=head;
        }
     else
        {
         temp=tail;
         tail=tail->next;
         tail=var;
         temp->next=tail;
         tail->previous=temp;
         tail->next=NULL;
         }

}
int fetch(int index)
 {
    int i;
   
    
	if(head == NULL) 
        {
		printf("linklist is empty");
        }
    if(index<0)
    {
    pointer = tail;
	for ( i = -1; i > index; i--) 
        {
		if(pointer->previous == NULL) 
            {
			printf("Double Linklist is emty");
            return -1;
		     }
		pointer = pointer->previous;
	    }
	
	return pointer->value;
   }
 
if(index>=0)
    {
    pointer=head;
    for ( i = 0; i < index; i++) 
        {
		if(pointer->next == NULL) 
            {
			return -1;
            }
		pointer = pointer->next;
        }
	
	return pointer->value;
    }   
 }
void display()
{
    
     
     dNode *im;
     
    im=head;
    if (head==NULL)
    {
        printf("Linklist is empty\n");
    }
   
    else
    {
        printf ("\n The status of the link list is \n");
       
        
            while(im->next!=NULL)
            {
           
                
                printf ("%d\n",(im->value));
                im=im->next;
                
        
            }
            printf ("%d\n",(im->value));
            return;
        
    }
}
int search(srch)
{
    dNode *sr;
    sr=head;
    if (head==NULL)
    {
        printf("Linklist is empty\n");
    }
    while(sr->next!=NULL)   
    {
        if(sr->value==srch)
        {
        return(srch);
        }

        else
        { 
        return 0;

        } 
    sr=sr->next;
    }

    
}

    