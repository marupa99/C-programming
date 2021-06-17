#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dos.h>
#include <windows.h>
typedef struct food
{
    int Serial_Num;
    char Food_Menu[30];
    int Price;
    struct food *link;
} node;

node *header=NULL;
node *get_node()
{
    return((node *)malloc(sizeof(node)));
}
void insert()
{
    int Serial_Num,Price,n,i,t;
    char Food_Menu[30];
    printf("How many food menu do you want to insert : ");
    scanf("%d",&t);
    for(i=0; i<t; i++)
    {
        if(header==NULL)
        {
            node *n;
            printf("Enter Serial Number, Food Menu and Price : ");
            scanf("%d %s %d",&Serial_Num,Food_Menu,&Price);
            n=get_node();
            n->Serial_Num=Serial_Num;
            n->Price=Price;
            strcpy(n->Food_Menu,Food_Menu);
            n->link=NULL;
            n->link = header;

            header = n;
            printf("DATA INSERTED SUCCESSFULLY\n");
        }
        else
        {
            node *newNode, *temp;
            printf("Enter Serial Number, Food Menu and Price : ");
            scanf("%d %s %d",&Serial_Num,Food_Menu,&Price);
            newNode=get_node();


            if(newNode == NULL)
            {
                printf("Unable to allocate memory.");
            }
            else
            {
                newNode->Serial_Num=Serial_Num;
                newNode->Price=Price;
                strcpy(newNode->Food_Menu,Food_Menu);
                newNode->link=NULL;

                temp = header;


                while(temp->link != NULL)
                    temp = temp->link;

                temp->link = newNode;

                printf("DATA INSERTED SUCCESSFULLY\n");
            }
        }
    }
}
void del()
{

    node *toDelete, *secondLastNode;

    if(header == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = header;
        secondLastNode = header;
        while(toDelete->link != NULL)
        {
            secondLastNode = toDelete;
            toDelete = toDelete->link;
        }

        if(toDelete == header)
        {
            header = NULL;
        }
        else
        {
            secondLastNode->link = NULL;
        }


        free(toDelete);

        printf("SUCCESSFULLY DELETED LAST NODE OF LIST\n");
    }
}

void display()
{
    node *temp;
    printf("Serial   Food Menu     Price\n");
    for(temp=header; temp!=NULL; temp=temp->link)
        printf("%-4d %9s %12d\n",temp->Serial_Num,temp->Food_Menu,temp->Price);
}

void search()
{
    int Serial_Num;
    node *temp;
    printf("Enter the Serial Number of food to be searched : ");
    scanf("%d",&Serial_Num);
    for(temp=header; temp!=NULL; temp=temp->link)
    {
        if(Serial_Num==temp->Serial_Num)
        {
            printf("Serial   Food Menu     Price\n");
            printf("%-4d %9s %12d\n",temp->Serial_Num,temp->Food_Menu,temp->Price);
            return;
        }
    }
    printf("Food Menu Not Found !!!\n");
}

void delivery()
{
    char fm[100],name[100],add[100],pn[100],p[100];
    int sn,n;
    int Serial_Num;
    node *temp;
    printf("Enter the unique Serial Number for food order : ");
    scanf("%d",&Serial_Num);
    for(temp=header; temp!=NULL; temp=temp->link)
    {
        if(Serial_Num==temp->Serial_Num)
        {
            printf("Food details...\n");
            printf("Food Menu is Founded\n");

            printf("For order...");

            printf("Enter Customer details...\n");
            printf("Customer Name : ");
            scanf("%s",name);
            printf("Phone Number : ");
            scanf("%s",pn);
            printf("Enter Address : ");
            scanf("%s",add);

            printf("Choose any payment option : \n");
            printf("1.Bikas\n2.Cash\n3.Card\n");
            scanf("%d",&n);
            if(n==1)
            {
                printf("This our Bikas Number\nPayment on this Number:\n018888888888\nThank You\n");
                printf("After payment we will confirm your order\n");
            }
            else if(n==2)
            {
                printf("Your order is confirm\n");
                printf("Thank You\n");

            }
            else if(n==3)
            {
                printf("Enter your Password : ");
                scanf("%s",p);
                printf("Your order is confirm\n");
                printf("Thank You\n");
            }
        }


        //else
        //{
            //printf("Food Menu Not Found !!!\n");
        //}
    }

}

void deleteFirstNode()
{
    node *toDelete;

    if(header == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = header;
        header = header->link;

        printf("The following record is deleted : %d %s %d\n",toDelete->Serial_Num,toDelete->Food_Menu,toDelete->Price);


        free(toDelete);

        printf("SUCCESSFULLY DELETED FIRST NODE FROM LIST\n");
    }
}
void deleteMiddleNode()
{
    int i,position;

    node *toDelete, *prevNode;
    printf("Enter position : ");
    scanf("%d",&position);
    if(header == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = header;
        prevNode = header;

        for(i=2; i<=position; i++)
        {
            prevNode = toDelete;
            toDelete = toDelete->link;

            if(toDelete == NULL)
                break;
        }

        if(toDelete != NULL)
        {
            if(toDelete == header)
                header = header->link;

            prevNode->link = toDelete->link;
            toDelete->link = NULL;


            free(toDelete);

            printf("SUCCESSFULLY DELETED NODE FROM MIDDLE OF LIST\n");
        }
        else
        {


            printf("Invalid position unable to delete.");

        }
    }
}
void Del_all()
{
    int c;
    printf("1.Delete first Menu\n");
    printf("2.Delete any middle Menu\n");
    printf("3.Delete last Menu\n");
    scanf("%d",&c);
    switch(c)
    {
    case 1 :
        deleteFirstNode();
        break;
    case 2 :
        deleteMiddleNode();
        break;
    case 3 :
        del();
        break;
    default :
        exit(0);
        break;
    }

}
void admin()
{
    int password;

    printf("Enter admin password : ");

    scanf("%d",&password);

    if(password==12345)
    {
        int c;

        printf("\nEnter any option...\n");
        printf("1.Insert Food Menu\n");
        printf("2.Delete Food Menu\n");
        scanf("%d",&c);
        switch(c)
        {
        case 1 :
            insert();
            break;
        case 2 :
            Del_all();
            break;
        default :
            exit(0);
            break;
        }
    }
    else
    {
        printf("Wrong Password");
    }

}
void menu()
{
    int choice;
    printf("\nEnter any option...\n");
    printf("1.Admin\n");
    printf("2.Display Food Menu\n");
    printf("3.Search Food Menu\n");
    printf("4.Food Order\n");
    printf("5.Exit()\n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1 :
        admin();
        break;
    case 2 :
        display();
        break;
    case 3 :
        search();
        break;
    case 4 :
        delivery();
        break;
    default :
        exit(0);
        break;
    }
}

int main()
{

        printf("                                            ******************************\n");

        printf("                                            ******************************\n");

        printf("                                            *****Food Order Simulation****\n");

        printf("                                            ******************************\n");

        printf("                                            ****************************");Sleep(3000);
        system("color 90");

    for(;;)
    {
        menu();
    }
    return 0;
}
