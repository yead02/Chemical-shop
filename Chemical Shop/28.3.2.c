#include<stdio.h>
#include<string.h>

typedef struct info
{
    int serial_no;
    char name[20];
    float ATM;
    char inni[6];
    float TA;
    float RPU;
};

FILE *fp;


struct info CN[10];
int count;
int tmp;




int first_user();
int first_admin();
int opening();
int prnt_user();
int search_user();
int one();
int two();
int three();
int four();
int prnt();
int adds();
int deletes();
int edit();
int search();
int write_to_file_for_add();
int write_to_file_for_delete();
int scan_from_file();





main()
{
    opening();
}




int opening()
{
    system("cls");
    int i,j,len,ddf,x,y;
    char s[500]={"\n\n\n\t\t\t\t\t\t\t\t\tWelcome To The Chemistry Lab\n\n\n\n\t\t\t\t\t\t\t\t\tEnter \n\t\t\t\t\t\t\t\t\t\t1 to go to Admin page\n\t\t\t\t\t\t\t\t\t\t2 to go to User page\n\t\t\t\t\t\t\t\t\t\t0 to exit...\n"};
    system("color B");
    len=strlen(s);
    for(i=0;i<len;i++)
        {
            putchar(s[i]);
            for(j=0;j<7000000;j++)
            ddf++;
        }
    scanf("%d",&x);
    if(x==1)
    {
        printf("Please enter the password: \n");
        f:
        scanf("%d",&y);
        if(y==753951)
        {
            first_admin();
        }
        else
        {
            printf("You have entered a wrong password.Try again:\n");
            goto f;
        }
    }
    else if(x==2)
        first_user();

    else
        return 0;
}




int first_user()
{
    system("cls");
    int z;
    printf("\n\n\n\t\t\t\t\t\t\t\t\t\tUSER PAGE\n\n\n\t\t\t\t\t\t\t\t\tPress \n\t\t\t\t\t\t\t\t\t\t1 to show all items \n\t\t\t\t\t\t\t\t\t\t2 to search by letter\n\t\t\t\t\t\t\t\t\t\t9 to logout\n\t\t\t\t\t\t\t\t\t\t0 to exit...\n");
    scanf("%d",&z);
    switch(z)
    {
    case 1:
        prnt_user();
        break;
    case 2:
        search_user();
        break;
    case 9:
        opening();
        break;
    default:
        return 0;
    }
}





int prnt_user()
{
    int i;
    system("cls");

    fp = fopen("count.txt","r");
    fscanf(fp,"%d",&count);
    fclose(fp);

    fp=fopen("info.txt","r");

    for(i=0;i<count;i++)
    {

        fscanf(fp,"%d",&CN[i].serial_no);
        printf("\n%d.\n",CN[i].serial_no);
        fscanf(fp,"%s",&CN[i].name);
        printf("\n%s",CN[i].name);
        fscanf(fp,"%f",&CN[i].ATM);
        printf("\n%.2f",CN[i].ATM);
        fscanf(fp,"%s",&CN[i].inni);
        printf("\n%s",CN[i].inni);
        fscanf(fp,"%f",&CN[i].TA);
        printf("\n%.2f",CN[i].TA);
        fscanf(fp,"%f",&CN[i].RPU);
        printf("\n%.2f",CN[i].RPU);
        printf("\n\n");
    }

    fclose(fp);


    printf("\n\npress\n\t1 to back\n\t0 to exit...\n");
    int x;
    scanf("%d",&x);
    if(x==1)
        first_user();
    else
        return 0;
}




int search_user()
{
    int i;
    system("cls");
    fp = fopen("count.txt","r");
    fscanf(fp,"%d",&count);
    fclose(fp);
    fp=fopen("info.txt","r");
    for(i=0;i<count;i++)
        {
            fscanf(fp,"%d",&CN[i].serial_no);
            fscanf(fp,"%s",&CN[i].name);
            fscanf(fp,"%f",&CN[i].ATM);
            fscanf(fp,"%s",&CN[i].inni);
            fscanf(fp,"%f",&CN[i].TA);
            fscanf(fp,"%f",&CN[i].RPU);
        }
    fclose(fp);
    printf("\nEnter the first letter\n");
    char c[5];
    scanf("%s",&c);


    for(i=0;i<count;i++)
    {
        if(CN[i].name[0]==c[0])
        {
            printf("\n%d.\n",CN[i].serial_no);
            printf("\n%s",CN[i].name);
            printf("\n%.2f",CN[i].ATM);
            printf("\n%s",CN[i].inni);
            printf("\n%.2f",CN[i].TA);
            printf("\n%.2f",CN[i].RPU);
            printf("\n\n");
        }
        else
            continue;
    }

    printf("\n\npress\n\t1 to back\n\t0 to exit...\n");
    int x;
    scanf("%d",&x);
    if(x==1)
        first_user();
    else
        return 0;
}





int first_admin()
{
    int z,i,j,len,ddf=0;
    char s[500]={"\n\n\n\t\t\t\t\t\t\t\t\t\t\tADMIN PAGE\n\n\n\n\t\t\t\t\t\t\t\t\tEnter \n\t\t\t\t\t\t\t\t\t\t1 to see items\n\t\t\t\t\t\t\t\t\t\t2 to add another item\n\t\t\t\t\t\t\t\t\t\t3 to delete an item\n\t\t\t\t\t\t\t\t\t\t4 to edit an item\n\t\t\t\t\t\t\t\t\t\t9 to log out\n\t\t\t\t\t\t\t\t\t\t0 to exit...\n"};
    system("cls");
    len=strlen(s);
    for(i=0;i<len;i++)
        {
            putchar(s[i]);
            for(j=0;j<7000000;j++)
            ddf++;
        }
    scanf("%d",&z);

    switch(z)
    {
        case 1:
            one();
            break;

        case 2:
            two();
            break;

        case 3:
            three();
            break;

        case 4:
            four();
            break;

        case 9:
            opening();
            break;

        case 0:
            return 0;
    }

}




int one()
{
    int z;
    printf("\n\n\n\t\t\t\t\t\t\t\t\tPress \n\n\n\t\t\t\t\t\t\t\t\t\t1 to show all items \n\t\t\t\t\t\t\t\t\t\t2 to search by letter\n");
    scanf("%d",&z);
    switch(z)
    {
    case 1:
        prnt();
        break;
    case 2:
        search();
        break;
    }
    printf("\n\npress\n\t1 to back\n\t0 to exit...\n");
    int x;
    scanf("%d",&x);
    if(x==1)
        first_admin();
    else return 0;
}




int two()
{
    adds();
    prnt();
    printf("\n\npress\n\t1 to back\n\t0 to exit...\n");
    int x;
    scanf("%d",&x);
    if(x==1)
        first_admin();
    else
        return 0;
}





int three()
{
    prnt();
    deletes();
    prnt();
    printf("\n\npress\n\t1 to back\n\t0 to exit...\n");
    int x;
    scanf("%d",&x);
    if(x==1)
        first_admin();
    else
        return 0;
}





int four()
{
    prnt();
    edit();
    prnt();
    printf("\n\npress\n\t1 to back\n\t0 to exit...\n");
    int x;
    scanf("%d",&x);
    if(x==1)
        first_admin();
    else
        return 0;
}




int prnt()
{
    int i;
    system("cls");

    fp = fopen("count.txt","r");
    fscanf(fp,"%d",&count);
    fclose(fp);

    fp=fopen("info.txt","r");

    for(i=0;i<count;i++)
    {

        fscanf(fp,"%d",&CN[i].serial_no);
        printf("\n%d.\n",CN[i].serial_no);
        fscanf(fp,"%s",&CN[i].name);
        printf("\n%s",CN[i].name);
        fscanf(fp,"%f",&CN[i].ATM);
        printf("\n%.2f",CN[i].ATM);
        fscanf(fp,"%s",&CN[i].inni);
        printf("\n%s",CN[i].inni);
        fscanf(fp,"%f",&CN[i].TA);
        printf("\n%.2f",CN[i].TA);
        fscanf(fp,"%f",&CN[i].RPU);
        printf("\n%.2f",CN[i].RPU);
        printf("\n\n");
    }

    fclose(fp);
}




int search()
{
    int i;
    system("cls");
    fp = fopen("count.txt","r");
    fscanf(fp,"%d",&count);
    fclose(fp);
    fp=fopen("info.txt","r");
    for(i=0;i<count;i++)
        {
            fscanf(fp,"%d",&CN[i].serial_no);
            fscanf(fp,"%s",&CN[i].name);
            fscanf(fp,"%f",&CN[i].ATM);
            fscanf(fp,"%s",&CN[i].inni);
            fscanf(fp,"%f",&CN[i].TA);
            fscanf(fp,"%f",&CN[i].RPU);
        }
    fclose(fp);
    //scan_from_file();
    printf("\nEnter the first letter\n");
    char c[5];
    scanf("%s",&c);


    for(i=0;i<count;i++)
    {
        if(CN[i].name[0]==c[0])
        {
            printf("\n%d.\n",CN[i].serial_no);
            printf("\n%s",CN[i].name);
            printf("\n%.2f",CN[i].ATM);
            printf("\n%s",CN[i].inni);
            printf("\n%.2f",CN[i].TA);
            printf("\n%.2f",CN[i].RPU);
            printf("\n\n");
        }
        else
            continue;
    }
}




int adds()
{
    int i,j;
    system("cls");
    printf("\nHow many new Items you want to add? \n");
    scanf("%d",&j);

    fp = fopen("count.txt","r");
    fscanf(fp,"%d",&count);
    if(fp==NULL)
        count=0;
    fclose(fp);

    tmp=j+count;

    for(i=count;i<tmp;i++)
        {
            CN[i].serial_no=i+1;
            printf("\nEnter the name of the chemical\n");
            scanf("%s",&CN[i].name);
            printf("Enter the atomic mass\n");
            scanf("%f",&CN[i].ATM);
            printf("Enter the initial of the chemical\n");
            scanf("%s",&CN[i].inni);
            printf("Enter the total available mass\n");
            scanf("%f",&CN[i].TA);
            printf("Enter the rate per unit\n");
            scanf("%f",&CN[i].RPU);
            printf("\n");
        }
    write_to_file_for_add();
}




int deletes()
{
    printf("\n\nEnter the number you want to delete:\n");
    int i,j;
    scanf("%d",&j);

    fp = fopen("count.txt","r");
    fscanf(fp,"%d",&count);
    fclose(fp);

    scan_from_file();

    for(i=j-1;i<count;i++)
        {
            CN[i]=CN[i+1];
            CN[i].serial_no=(CN[i].serial_no-1);
        }

    count--;

    write_to_file_for_delete();
}




int edit()
{
    printf("\n\nEnter the number you want to edit:\n");
    int i,j;
    scanf("%d",&j);

    fp = fopen("count.txt","r");
    fscanf(fp,"%d",&count);
    fclose(fp);

    scan_from_file();

    system("cls");

    printf("%d\n",CN[j-1].serial_no);
    printf("%s",CN[j-1].name);
    printf("\n%f",CN[j-1].ATM);
    printf("\n%s",CN[j-1].inni);
    printf("\n%f",CN[j-1].TA);
    printf("\n%f",CN[j-1].RPU);
    printf("\n\n\n");

    printf("Press\n\t1 to edit name of the chemical\n\t2 to edit the atomic mass\n\t3 to edit the initial of the chemical");
    printf("\n\t4 to edit the total available mass\n\t5 to edit the rate per unit\n");
    int x;
    scanf("%d",&x);
    printf("\n\n");

    if(x==1)
    {
        printf("\nEnter the name of the chemical\n");
        scanf("%s",&CN[j-1].name);
    }
    else if(x==2)
    {
        printf("Enter the atomic mass\n");
        scanf("%f",&CN[j-1].ATM);
    }
    else if(x==3)
    {
        printf("Enter the initial of the chemical\n");
        scanf("%s",&CN[j-1].inni);
    }
    else if(x==4)
    {
        printf("Enter the total available mass\n");
        scanf("%f",&CN[j-1].TA);
    }
    else
    {
        printf("Enter the rate per unit\n");
        scanf("%f",&CN[j-1].RPU);
    }

    write_to_file_for_delete();
}




int write_to_file_for_add()
{
    int i;
    fp = fopen("info.txt", "a+");
    for(i=count;i<tmp;i++)
        {
            fprintf(fp,"%d\n",CN[i].serial_no);
            fprintf(fp,"%s",CN[i].name);
            fprintf(fp,"\n%f",CN[i].ATM);
            fprintf(fp,"\n%s",CN[i].inni);
            fprintf(fp,"\n%f",CN[i].TA);
            fprintf(fp,"\n%f",CN[i].RPU);
            fprintf(fp,"\n");
        }

    fclose(fp);

    fp = fopen("count.txt","wt+");
    fprintf(fp,"%d",tmp);
    fclose(fp);
}





int write_to_file_for_delete()
{
    int i;
    fp = fopen("info.txt", "wt+");
    for(i=0;i<count;i++)
        {
            fprintf(fp,"%d\n",CN[i].serial_no);
            fprintf(fp,"%s",CN[i].name);
            fprintf(fp,"\n%f",CN[i].ATM);
            fprintf(fp,"\n%s",CN[i].inni);
            fprintf(fp,"\n%f",CN[i].TA);
            fprintf(fp,"\n%f",CN[i].RPU);
            fprintf(fp,"\n");
        }

    fclose(fp);

    fp = fopen("count.txt","wt+");
    fprintf(fp,"%d",count);
    fclose(fp);
}




int scan_from_file()
{
    int i;
    for(i=0;i<count;i++)
        {
            fscanf(fp,"%d",&CN[i].serial_no);
            fscanf(fp,"%s",&CN[i].name);
            fscanf(fp,"%f",&CN[i].ATM);
            fscanf(fp,"%s",&CN[i].inni);
            fscanf(fp,"%f",&CN[i].TA);
            fscanf(fp,"%f",&CN[i].RPU);
        }

}

