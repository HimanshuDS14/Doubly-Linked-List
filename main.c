#include<stdio.h>

struct node
{
    int data;
    struct node*prev,*next;
};

struct node*start=NULL;

void insert_first()
{
    struct node*temp;
    temp = (struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("Memory Not Allocated");
    }
    int item;
    printf("Enter a data : ");
    scanf("%d" , &item);
    temp->data = item;
    temp->next = NULL;
    temp->prev = NULL;

    if(start==NULL)
    {
        start = temp;
    }
    else
    {
        struct node*t;
        t = start;
        temp->next = t;
        t->prev = temp->next;
        start = temp;

    }
}


void insert_last()
{
    struct node*temp;
    temp = (struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
        printf("Memory Not Allocated");

    int item;
    printf("Enter a data : ");
    scanf("%d" , &item);
    temp->next = NULL;
    temp->prev = NULL;
    temp->data = item;

    if(start==NULL)
    {
        start = temp;
    }
    else
    {
        struct node*t;
        t = start;

        while(t->next!=NULL)
        {
            t = t->next;
        }
        t->next = temp;
        temp->prev = t->next;

    }
}


void display()
{

    struct node*temp;
    if(start==NULL)
    {
        printf("List is Empty");
        return;
    }
    else
    {
        temp = start;
        printf("List is : ");
        while(temp!=NULL)
        {
            printf("%d " , temp->data);
            temp = temp->next;
        }
    }

}

void insert_at_location()
{
    struct node*temp;
    temp = (struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
        printf("Memory Not allocated");
    else
    {
        int item;
        printf("Enter a data : ");
        scanf("%d" , &item);

        temp->next = NULL;
        temp->prev = NULL;
        temp->data = item;
    }

    int loc;
    printf("Enter a location : ");
    scanf("%d" , &loc);

    struct node*t;
    t = start;
    for(int i=0;i<loc;i++)
    {
        t = t->next;

        if(t==NULL)
        {
            printf("Insertion Not Possible");
        }

    }


     temp->next = t->next;
     temp->prev = t;
     t->next = temp;
     t->next->prev = temp;


}

void delete_first()
{
    struct node*temp;

    if(start==NULL)
    {
        printf("List is Empty");
        return;
    }

    temp = start;
    start = start->next;
    free(temp);

}

void delete_last()
{
    struct node*temp , *temp1;
    if(start==NULL)
    {
        printf("List is Empty");
        return;
    }

    temp = start;

    if(start->next==NULL)
    {
        start = NULL;
        free(start);
    }
    else
    {


    while(temp->next!=NULL)
    {
        temp1 = temp;
        temp = temp->next;
    }

    free(temp);
    temp1->next = NULL;
    }

}

void delete_at_position()
{
    struct node*temp;
    if(start==NULL)
    {
        printf("List is Empty");
        return;
    }
    temp = start;
    int loc;
    printf("Enter a location : ");
    scanf("%d" ,&loc);
    for(int i=0;i<loc;i++)
    {

        temp = temp->next;

        if(temp==NULL)
        {
            printf("Deletion Not Possible\n");
            return;
        }
    }

    if(temp->next==NULL)
    {
        printf("Can't delete");
        return;
    }
    else
    {
        temp->next  = NULL;
    }

}

void search()
{
    int item , flag=0;
    printf("Enter a data which you want a search : ");
    scanf("%d" , &item);

    struct node*temp;
    temp = start;
    while(temp!=NULL)
    {
        if(temp->data == item)
        {
            flag=1;
        }
        temp = temp->next;
    }
    if(flag==1)
    {
        printf("Item present in list\n");
    }
    else
    {
        printf("Item not present into the list\n");
    }
}



int main()
{
    int ch;
    while(1)
    {
        printf("1 Insert first\n");
        printf("2 Insert last\n");
        printf("3 insert at location\n");
        printf("4 Delete First\n");
        printf("5 Delete Last\n");
        printf("6 Delete at location\n");
        printf("7 Search\n");
        printf("8 Exit\n");

        printf("Enter a choice : ");
        scanf("%d" , &ch);

        switch(ch)
        {

        case 1:
            insert_first();
            display();
            printf("\n");
            break;
        case 2:
            insert_last();
            display();
            printf("\n");
            break;
        case 3:
            insert_at_location();
            display();
            printf("\n");
            break;
        case 4:
            delete_first();
            display();
            printf("\n");
            break;
        case 5:
            delete_last();
            display();
            printf("\n");
            break;
        case 6:
            delete_at_position();
            display();
            printf("\n");
            break;
        case 7:
            search();
            break;
        case 8:
            exit(0);

        }

    }
}
