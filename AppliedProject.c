#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<ctype.h>
#include<direct.h>
int seats[5][5];
int price=200;
int count=1; 
struct details
{
    char name[50];
    int phone;
    char seatletter;
    int seatnumber;
    int movie;

};
struct details info[100];

int bookticket()
{
    int movie;
    printf(" ==================================================================\n");
    printf("||Please Choose The Movie:                                        ||\n");
    printf("|| <1>. Spiderman No Way Home                                     ||\n");
    printf("|| <2>. The Matrix                                                ||\n");
    printf("|| <3>. Avengers Endgame                                          ||\n");
    printf("|| ===============================================================||\n");
    scanf("%d",&movie);
    return movie;

}
void printcinema()
{
    printf("\n                                SCREEN\n\n\n");
    printf("\t 1\t\t 2\t\t 3\t\t 4\t\t 5\n");

    for (int i = 0; i < 5; i++)
    {
        printf(" %c ",'A'+ i );
        for (int j = 0; j < 5; j++) {
            if (seats[i][j] == 1) {
                printf("\t[X]\t");

            } else {
                printf("\t[ ]\t");

            }
        }
        printf("\n\n");
        

    }
}
void printfilmname(int m)
{
switch(m)
{
    case 1:
        printf("Spider Man No Way Home ");
        break;
    case 2:
        printf("The Matrix");
        break;
    case 3: 
        printf("Avengers Endgame");
        break;
             

} 
}   

int converttonumber(char letter)
{
    //add limit to letter E
    int sn=1;
    char crlow = 'a';
    char crup = 'A';
    while (!(letter==crup || letter==crlow))
    {
        crlow++;
        crup++;
        sn++;

    }
    return sn;
}

void printticket(int movie,int price,int columnumber,char letter)
    {
        
       // system("cls");
        printf("\n\n");
        printf(" ------------------- BUDGET BOOKING TICKET---------------\n");
        printf(" =======================================================\n");
        printf("|| Booking ID : %d  Movie Name : ");printfilmname(movie); printf("||\n");
        printf(" Customer  : %s\n",info[count].name);
        printf("\t\t\t                              Date      : 06-09-2022\n");
        printf("\t                                              Time      : 4:20pm\n");
        printf("\t                                              Room      : 07\n");
        printf("\t                                              Seat      : %c%d  \n",toupper(letter),columnumber);
        printf("\t                                              Price     : %d  \n\n",price);
        printf(" =======================================================\n");

    
       return;
    } 

void storeinfile()
{   
    FILE * file= fopen("output.txt", "a");
    fprintf(file,"User: %d  Name:  %s  --> Phone:%d-->Movie: %d\n  ",count,info[count].name,info[count].phone,info[count].movie);
    fclose(file);

}
void reserve(int s,int p)
{
    
    int movie=s;
    info[count].movie=movie;
    int NoOfSeats;
    int i;
    char letter;
    int rownumber=0;
    int columnumber=0;
    printf("How many seats do you want to reserve?\n");
    scanf("%d",&NoOfSeats);
    system("cls");
    printcinema();
    printf("Please enter your name:\n");// ADD NAME AS A STRING GETS
    //getch(g[c].name);
    scanf("%s",&info[count].name);
    printf("Please enter your phone number:\n");
    scanf("%d",&info[count].phone);
    printf("Please select the %d seats you want\n",NoOfSeats);
    int totalSeats = NoOfSeats;
    for( i=0; i < totalSeats ; i++ )
    {
        printf("Please choose row  (A-E)\n");
        scanf("%s",&letter);
        rownumber=converttonumber(letter);
        printf("Please choose seat in row (1-5)\n");
        scanf(" %d",&columnumber);
        if(seats[rownumber-1][columnumber-1]!=0)
        {
        printf("Ticket is already reserved please select another seat\n\n\n");
        reserve(s,p);
        
        }
        else
        {
        seats[rownumber-1][columnumber-1]=1;
        printf("\n");
        printticket(movie,p,columnumber,letter);

        
        }
        
                
    }
    storeinfile();
      count++;

    printcinema();
     

    char ch;
   printf("Press Any Key to Continue\n");    
   scanf("%s",&ch);
return;
    
        

     




}
void cancelticket()
{
    char letter;
    char ch;
    int columnumber;
    printf("Please enter Seat Letter");
    scanf("%s",&letter);
    printf("Please enter the Seat Number");
    scanf("%d",&columnumber);
    int rownumber;
    rownumber=converttonumber(letter);
    if(seats[rownumber-1][columnumber-1]!=1)
        {
        printf("Sorry this seat already has no reservation to it\n");
       
        printf("Press Any Key to Continue\n");    
        scanf("%s",&ch);
        return;
        }
        else
        {
        seats[rownumber-1][columnumber-1]=0;
        printf("Your Seat has been cancelled!\n");
        printf("Press Any Key to Continue\n");    
        scanf("%s",&ch);
        return;
        
        }
    
}
int inadmin(int p)
{
    int choiceA;
    char g;
    system("cls");
    printf("                 Welcome To The Admin Section\n");
    printf("==================================================================\n");
    printf("||            <1>- Change Ticket Price                            ||\n");
    printf("||            <2>- View Records                                   ||\n");
    printf("||            <3>- Return To Main Screen                          ||\n");
    printf("===================================================================\n");
    scanf("%d",&choiceA);
    
    switch (choiceA)
    {
    case 1 :
        printf("Enter new price for cinema ticket: ");
        scanf("%d",&p);
        return p;
        
    case 2 :
        printf("a7a test ");
        scanf("%c",&g);
        break;
    
    default:
        break;
    }
   
}
int adminscreen()
{
    char password[32];
    int c1;
    int c2;
    system("cls");
    printf("Please Enter Admin Password...\n    ");
    scanf("%s",password);
    if (strcmp(password,"abc")==0)
    {

        printf("Correct Password\n");
         return 2;

    }

    else
    {
        system("cls");
        printf("Incorrect Password\n");
        printf("<1>Retry\n");
        printf("<2>Exit\n");



        scanf("%d",&c1);
        if (c1==1)
            adminscreen();
        else if (c1==2)
            return 1;
        else
            printf("Wrong Choice");
    }
}
int guestscreen()
{

    int choiceG;
    int select;
    system("cls");
    printf("                 Welcome To The Booking System\n");
    printf("==================================================================\n");
    printf("||            <1>- To Book A Ticket                               ||\n");
    printf("||            <2>- To cancel An Exisiting Ticket                  ||\n");
    printf("||            <3>- Return To Main Screen                          ||\n");
    printf("||                                                                ||\n");
    printf("===================================================================\n");

    scanf("%d",&choiceG);
    system("cls");
    return choiceG;


}
int TheMainScreen()
{
    int choice;

    printf(            "Welcome To Budget Cinema!\n");
    printf("=======================================================\n");
    printf("|| This is Budget Cinema's Booking System            ||\n");
    printf("|| Please Select Your Choice                         ||\n");
    printf("||                                                   ||\n");
    printf("||         <1>                      <2>              ||\n");
    printf("||     ==========            ===================     ||\n");
    printf("||    ||  Guest ||          || Admin(password) ||    ||\n");
    printf("||     ==========            ===================     ||\n");
    printf("||                                                   ||\n");
    printf("||                                                   ||\n");
    printf("=======================================================\n");
    printf("Enter your choice:\n");
    
    scanf("%d",&choice);
    return choice;

}
int main()
{
   system("cls");
    struct details guest[100];
    int c=0; int gc; 
    int select; int ac=0;
    int pc;
    int count=0;
    c=TheMainScreen();


    if(c==1)
    {

        gc=guestscreen();
        switch (gc)
        {
            case 1 :
            Beep(750, 200);
                select=bookticket();
                reserve(select,price);
                main();

                break;
            case 2:
            cancelticket();
            main();

                break;
            case 3:
                main();
                break;
            default:
                printf("Wrong Input\n");
                system("cls");
                main();
                break;

        }
    }
    else if(c==2)
    {

        ac=adminscreen();
    if (ac==1)
    {
        system("cls");
        main();
    }
    else if (ac=2)
    {
    price=inadmin(price);   
     main();
    }
    }


    else
     {
     printf("\nINCORRECT CHOICE,PLEASE CHOOSE 1 OR 2\n");
     main();

     }


}

