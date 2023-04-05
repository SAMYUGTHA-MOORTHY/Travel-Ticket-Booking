#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>

char matrix[3][3]; //TO FIX THE SIZE OF THE TIC TAC TOE MATRIX

//STRUCTURE DECLARATIONS
struct user
{
                char username[50];
                char password[50];
                char email[50];
                char fullName[50];
                char phNo[10];
                char pwd2[50];
};
typedef struct
{
                char name[25];
                char gender;
                int age;
                int busno;
                int seatno;
                char status[10];
                char destination[10];
                int dd,mm,y;
}bus;

typedef struct
{
                char name[25];
                char gender;
                int age;
                int seatno;
                char destination[50];
                int dd,mm,yyyy;
                char flightname[20];

}flight;
typedef struct
{
                int fnosa;//no of seats available in flight
                int fbsnasize;
                int fbsn[6];//flight booked seats array
                int date;
                char destination[20];


}seat_allocation;//f1_17={6,0},f1_23,f1_10,f1_15,f1_5,f1_30,f1_1,f1_13,f2_12,f2_22,f2_7,f2_25,f2_16,f2_20,f2_15,f2_28,f3_2,f3_13,f3_17,f3_21,f3_10,f3_30,f3_4,f3_24,f3_1,f3_26,f4_1,f4_8,f4_11,f4_18,f4_20,f4_24,f4_26,f4_30,f4_3,f4_13,f5_2,f5_9,f5_12,f5_15,f5_19,f5_23,f5_26,f5_30;

//USER DEFINED FUNCTIONS AND THEIR DEFINITIONS
//TO CREATE USERNAME FROM EMAIL ID
char  genUsername(char email[50],char username[50])
{
    int i;
    for(i=0;i<strlen(email);i++)
    {
        if(email[i]=='@')
            break;
        else
            username[i]=email[i];
    }
    username[i]='\0';

}

//TO CHECK IF ALL THE ELEMENTS IN THE STRING ARE ALPHABETS
int checkString(char str[])
{
    int i,x=0,p;
    p=strlen(str);
    for (i = 0; i < p ; i++)
    {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] == ' '))
        {
            continue;
        }
        else
        {
                return 0;
        }
    }
    return 1;
}

//TO CHECK IF THE ENTERED EMAIL ID IS A VALID
int checkEmail(char str[])
{
                int i;
                for(i=0;str[i]!='@';i++)
                {
                                if((str[i] >= 'A' && str[i] <= 'Z') || (str[i] == ' '))
                                {
                                                return 0;
                                }
                                else
                                {
                                                continue;
                                }

                }
                return 1;
}

//TO CHECK IF THE ENTERED PHONE NUMBER IS VALID
int checkPhno(char A[])
{
                int i,c=0,n;
                n=strlen(A);
                if(n!=10)
                {
                        return 0;
                }
                else
                {
                                for(i=0;i<10;i++)
                                {
                                                if(A[i]==0 || A[i]==1 || A[i]==2 || A[i]==3 || A[i]==4 || A[i]==5 || A[i]==6 || A[i]==7 || A[i]==8 || A[i]==9)
                                                {
                                                                c=1;
                                                }
                                                else
                                                {
                                                                c=0;
                                                }
                                }
                }
                if(c==1)
                {
                                return 1;
                }
}

//TO GET THE PASSWORD SECRETIVELY
char starPassword(char password[50])
{
                char ch;
                int i=0;
                A1 : ch=getch();
                if(ch!=13)
                {
                                printf("*");
                                password[i]=ch;
                                i++;
                                goto A1;
                }
                password[i]='\0';
}
//TO VERIFY IF THE ENTERED PASSWORD HAS FOLLOWED ALL THE CONSTRAINTS.
int checkPassword(char pwd[50])
{
                int n,i,c1=0,c2=0,c3=0;
                n=strlen(pwd);
                if(n!=8)
                {
                                return 0;
                }
                if(n==8)
                {
                                for(i=0;i<8;i++)
                                {
                                          if(islower(pwd[i]))
                                          {
                                                          c1++;
                                          }
                                          else if(isupper(pwd[i]))
                                          {
                                                          c2++;
                                          }
                                          else
                                          {
                                                          c3++;
                                          }
                                }
                                if(c1!=0 && c2!=0 && c3!=0)
                                {
                                                return 1;
                                }
                                else
                                {
                                                return 0;
                                }
                }
}

//TO VERIFY IF THE USER HAS GIVEN THE DESTINATION AVAILABLE IN THE WEBSITE
int checkDestination(char s[])
{
                if((strcmp(s,"Agra")==0)||(strcmp(s,"Varanasi")==0)||(strcmp(s,"Amritsar")==0)||(strcmp(s,"Jaisalmer")==0)||(strcmp(s,"New Delhi")==0)||(strcmp(s,"Mumbai")==0)||(strcmp(s,"Hyderabad")==0)||(strcmp(s,"Jaipur")==0)||(strcmp(s,"Goa")==0)||(strcmp(s,"Madurai")==0)||(strcmp(s,"Aurangabad")==0)||(strcmp(s,"Jodhpur")==0)||(strcmp(s,"Mysore")==0)||(strcmp(s,"Ladakh")==0)||(strcmp(s,"Srinagar")==0)||(strcmp(s,"Manali")==0)||(strcmp(s,"Shimla")==0)||(strcmp(s,"Udaipur")==0)||(strcmp(s,"Ooty")==0)||(strcmp(s,"Alappuzha")==0)||(strcmp(s,"Munnar")==0)||(strcmp(s,"Kodaikanal")==0))
                {
                                return 1;
                }
                else
                {
                                return 0;
                }
}

//TO VERIFY IF THE SELECTED BUS RAVELS TO THAT DESTINATION
int checkBusgoes(int n,char s[])
{
                switch(n)
                {
                                case 1 ://JOY TRAVEL
                                {
                                                if((strcmp(s,"Madurai")==0)||(strcmp(s,"Kodaikanal")==0)||(strcmp(s,"Ooty")==0)||(strcmp(s,"Munnar")==0)||(strcmp(s,"Alappuzha")==0)||(strcmp(s,"Mysore")==0))
                                                {
                                                                return 1;
                                                }
                                                else
                                                {
                                                                return 0;
                                                }
                                }
                                case 2 ://SIGMA TRAVEL
                                {
                                                if((strcmp(s,"Mysore")==0)||(strcmp(s,"Goa")==0)||(strcmp(s,"Mumbai")==0)||(strcmp(s,"Udaipur")==0)||(strcmp(s,"Jodhpur")==0)||(strcmp(s,"Jaisalmer")==0)||(strcmp(s,"Jaipur")==0))
                                                {
                                                                return 1;
                                                }
                                                else
                                                {
                                                                return 0;
                                                }
                                }
                                case 3  ://SKY TRAVEL
                                {
                                                if((strcmp(s,"Hyderabad")==0)||(strcmp(s,"Varanasi")==0)||(strcmp(s,"Agra")==0)||(strcmp(s,"New Delhi")==0)||(strcmp(s,"Mumbai")==0))
                                                {
                                                                return 1;
                                                }
                                                else
                                                {
                                                                return 0;
                                                }
                                }
                                case 4 ://JAVA TRAVEL
                                {
                                                if((strcmp(s,"Aurandabad")==0)||(strcmp(s,"New Delhi")==0)||(strcmp(s,"Amritsar")==0)||(strcmp(s,"Srinagar")==0)||(strcmp(s,"Ladakh")==0)||(strcmp(s,"Manali")==0)||(strcmp(s,"Shimla")==0))
                                                {
                                                                return 1;
                                                }
                                                else
                                                {
                                                                return 0;
                                                }
                                }
                                case 5 ://SWAN TRAVELS
                                {
                                                if((strcmp(s,"Goa")==0)||(strcmp(s,"Mumbai")==0)||(strcmp(s,"Udaipur")==0)||(strcmp(s,"Jodhpur")==0)||(strcmp(s,"Jaisalmer")==0)||(strcmp(s,"Jaipur")==0)||(strcmp(s,"Agra")==0)||(strcmp(s,"Varanasi")==0)||(strcmp(s,"Aurangabad")==0)||(strcmp(s,"Hyderabad")==0))
                                                {
                                                                return 1;
                                                }
                                                else
                                                {
                                                                return 0;
                                                }
                                }
                }
}

//TO CHECK IF THE BUS TRAVELS IN THE GIVEN DATE
int checkDate(int n,int m)
{
                if(n==1)
                {
                                if(m==10)
                                return 1;
                                else
                                return 0;
                }
                if(n==2)
                {
                                if(m==4)
                                return 1;
                                else
                                return 0;
                }
                if(n==3)
                {
                                if(m==17)
                                return 1;
                                else
                                return 0;
                }
                if(n==4)
                {
                                if(m==23)
                                return 1;
                                else
                                return 0;
                }
                if(n==5)
                {
                                if(m==8)
                                return 1;
                                else
                                return 0;
                }
}

//TO CHECKIF THE ENTERED SEAT NUMBER HAS ALREADY BEEN BOOKED
int checkSeat(int s[],int n)
{
                int i,j;
                j=strlen(s);
                for(i=0;i<j;i++)
                {
                                if(s[i]==n)
                                {
                                                return 1;
                                }
                }
                return 0;
}

//TO CHECK IF THE ENTERED GENDER VARIABLE IS VALID
int checkGender(char c)
{
                if(c=='M'||c=='m'||c=='F'||c=='f'||c=='T'||c=='t')
                {
                                return 1;
                }
                else
                {
                                return 0;
                }
}


//TO INITIALIZE THE TIC TAC TOE MATRIX TO EMPTY
void init_matrix(void)
{
    int i, j;
    for(i=0; i<3; i++)
    for(j=0; j<3; j++)
        matrix[i][j] = ' ';
}
// TO DISPLAY THE TIC TAC TOE MATRIX WITH LINES
void disp_matrix(void)
{
    int t;
    for(t=0; t<3; t++)
    {
        printf(" %c | %c | %c ",matrix[t][0],matrix[t][1], matrix [t][2]);
        if(t!=2)
        printf("\n---|---|---\n");
    }
    printf("\n");
}
//GETS THE MOVE FROM THE PLAYER

void get_player_move(void)
{
    int x, y;
    printf("Enter X,Y coordinates for your move: ");
    scanf("%d%*c%d", &x, &y);
    x--; y--;
    if(matrix[x][y]!= ' ')
    {
        printf("Invalid move, try again.\n");
        get_player_move();
    }
    else
        matrix[x][y] = 'X';
}
//TO SEE IF SOMEONE HAS WON
char check(void)
{
    int i;
    for(i=0; i<3; i++) /* check rows */
    if(matrix[i][0]==matrix[i][1] &&matrix[i][0]==matrix[i][2])
                return matrix[i][0];
    for(i=0; i<3; i++) /* check columns */
    if(matrix[0][i]==matrix[1][i] &&matrix[0][i]==matrix[2][i])
                return matrix[0][i];
    /* test diagonals */
    if(matrix[0][0]==matrix[1][1] &&matrix[1][1]==matrix[2][2])
                return matrix[0][0];
    if(matrix[0][2]==matrix[1][1] &&matrix[1][1]==matrix[2][0])
                return matrix[0][2];
    return ' ';
}
//GETS THE MOVE FROM THE COMPUTER
void get_computer_move(void)

{
    int i, j;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        if(matrix[i][j]==' ')
            break;
        if(matrix[i][j]==' ')
            break;

    }

    if(i*j==9)
    {
        printf("draw\n");
        exit(0);
    }
    else
    matrix[i][j] = 'O';
}

//TO THE HOTELS AROUND THE DESTINATION
void hotels_around(char s[])
{
                if(strcmp(s,"Agra")==0)
                                printf("Dasaprakash:VEG\nPinch of spice:NON-VEG\nLakshmi Vilas:VEG\nJahanpanah:NON-VEG");
                if(strcmp(s,"Varanasi")==0)
                                printf("Kashi Chaat Bhandar:VEG\nTandoor Villa:NON-VEG\nVegan & Raw Restaurent:NON-VEG\nSri Annapurna:VEG");
                if(strcmp(s,"Amritsar")==0)
                                printf("Bharawan Da Dhaba:VEG\nBeera Chicken Corner:NON-VEG\nKanha Sweets:VEG\nMama Meat Shop:NON-VEG");
                if(strcmp(s,"Jaisalmer")==0)
                                printf("Suryagarh:VEG\nAngaara Restaurent and Barbeque:NON-VEG\nShanti The Peace Restaurent:VEG\nGreen Park Restaurent:NON-VEG");
                if(strcmp(s,"New Delhi")==0)
                                printf("Le Cirque,The Leela Palace:NON-VEG\nITC Maurya:VEG\nPizzeria:NON-VEG\nBo Tai:VEG");
                if(strcmp(s,"Mumbai")==0)
                                printf("Khau Galli:VEG\nThe Table:NON-VEG\nLeopold Cafe:VEG\nSmoke House Deli:NON-VEG");
                if(strcmp(s,"Hyderabad")==0)
                                printf("Almond House:NON-VEG\nTatva:VEG\nParadise Biriyani:NON-VEG\nCafe Bahar:VEG");
                if(strcmp(s,"Jaipur")==0)
                                printf("Jaipur Adda:NON-VEG\nTaruveda:VEG\nZolocrust:NON-VEG\nHandi:VEG");
                if(strcmp(s,"Goa")==0)
                                printf("Tamarind Cafe:VEG\nBhatti Village:NON-VEG\nThalassa:VEG\nSpice Goa:NON-VEG");
                if(strcmp(s,"Madurai")==0)
                                printf("Konar Mess:NON-VEG\nAmma Mess:VEG\nSulthan Restaurent:NON-VEG\nFamous Jigarthanda");
                if(strcmp(s,"Aurangabad")==0)
                                printf("Bhoj:NON-VEG\nYalla Yalla:VEG\nChina Town:NON-VEG\nThaat Bhat:VEG");
                if(strcmp(s,"Jodhpur")==0)
                                printf("Indique:NON-VEG\nJhankar Choti Haveli:VEG\nNirvana:NON-VEG\nKalinga Restaurent:VEG");
                if(strcmp(s,"Mysore")==0)
                                printf("Vinayaka Mylari:VEG\nOyster Bay:NON-VEG\nHotel RRR:VEG\nTiger Trail:NON-VEG");
                if(strcmp(s,"Ladakh")==0)
                                printf("Lamayuru Restaurent:VEG\nGesmo Restaurent:NON-VEG\nLittle Italy Restaurent:NON-VEG\nHotel Sten Del:VEG");
                if(strcmp(s,"Srinagar")==0)
                                printf("Mughal Darbar:NON-VEG\nCafe de Linz:NON-VEG\nAhdoos:VEG");
                if(strcmp(s,"Manali")==0)
                                printf("Mount View Restaurent:VEG\nRooftop Restaurent:NON-VEG\nBasil Leaf Restaurent:VEG\nLa Plage:NON-VEG");
                if(strcmp(s,"Shimla")==0)
                                printf("Baljee's & Fascination:NON-VEG\nThe Devicos:NON-VEG\nQilaa:VEG");
                if(strcmp(s,"Udaipur")==0)
                                printf("Ambrai:VEG\nMillets of Mewar:VEG\nPalki Khana:NON-VEG\nRoyal Repast:NON-VEG");
                if(strcmp(s,"Ooty")==0)
                                printf("The Dining Hall:NON-VEG\nHyderabad Biriyani House:NON-VEG\nEarlac Secret:VEG\nAscot Multi-Cuisine:NON-VEG");
                if(strcmp(s,"Alappuzha")==0)
                                printf("Harbour Restaurent:NON-VEG\nIndian Coffee House:NON-VEG\nChakara:VEG\nKream Korner Art Cafe:VEG");
                if(strcmp(s,"Munnar")==0)
                                printf("Copper Castle:NON-VEG\nSree Mahaveer Bhojanalaya:VEG\nAli Baba & 41 Dishes:NON-VEG\nDTPC Food Court:VEG");
                if(strcmp(s,"Kodaikanal")==0)
                                printf("Atlaf's Cafe:NON-VEG\nRoyal Tibet:NON-VEG\nHilltop Towers:VEG\nCloud Street:VEG");
}

//FUNCTION TO DISPLAY THE FLIGHT DETAILS
void flightDetails(char sa[],FILE *s)
{
                char ff;
                system("cls");
                if(strcmp(sa,"Agra")==0)
                {
                                s=fopen("AGRA FLIGHT DETAILS.txt","r");
                                if(s==NULL)
                                {
                                                printf("Couldn't open file \n");
                                                exit(0);
                                }
                                while(!feof(s))
                                {
                                                ff = fgetc(s);
                                                printf("%c",ff);
                                }
                                fclose(s);
                                getch();
                }
                if(strcmp(sa,"Varanasi")==0)
                {
                                s=fopen("VARANASI FLIGHT DETAILS.txt","r");
                                if(s==NULL)
                                {
                                                printf("Couldn't open file \n");
                                                exit(0);
                                }
                                while(!feof(s))
                                {
                                                ff = fgetc(s);
                                                printf("%c",ff);
                                }
                                fclose(s);
                                getch();
                }
                if(strcmp(sa,"Amritsar")==0)
                {
                                s=fopen("AMRITSAR FLIGHT DETAILS.txt","r");
                                if(s==NULL)
                                {
                                                printf("Couldn't open file \n");
                                                exit(0);
                                }
                                while(!feof(s))
                                {
                                                ff = fgetc(s);
                                                printf("%c",ff);
                                }
                                fclose(s);
                                getch();
                }
                if(strcmp(sa,"Jaisalmer")==0)
                {
                                s=fopen("JAISALMER FLIGHT DETAILS.txt","r");
                                if(s==NULL)
                                {
                                                printf("Couldn't open file \n");
                                                exit(0);
                                }
                                while(!feof(s))
                                {
                                                ff = fgetc(s);
                                                printf("%c",ff);
                                }
                                fclose(s);
                                getch();
                }
                if(strcmp(sa,"New Delhi")==0)
                {
                                s=fopen("NEW DELHI FLIGHT DETAILS.txt","r");
                                if(s==NULL)
                                {
                                                printf("Couldn't open file \n");
                                                exit(0);
                                }
                                while(!feof(s))
                                {
                                                ff = fgetc(s);
                                                printf("%c",ff);
                                }
                                fclose(s);
                                getch();
                }
                if(strcmp(sa,"Mumbai")==0)
                {
                                s=fopen("MUMBAI FLIGHT DETAILS.txt","r");
                                if(s==NULL)
                                {
                                                printf("Couldn't open file \n");
                                                exit(0);
                                }
                                while(!feof(s))
                                {
                                                ff = fgetc(s);
                                                printf("%c",ff);
                                }
                                fclose(s);
                                getch();
                }
                if(strcmp(sa,"Hyderabad")==0)
                {
                                s=fopen("HYDERABAD FLIGHT DETAILS.txt","r");
                                if(s==NULL)
                                {
                                                printf("Couldn't open file \n");
                                                exit(0);
                                }
                                while(!feof(s))
                                {
                                                ff = fgetc(s);
                                                printf("%c",ff);
                                }
                                fclose(s);
                                getch();
                }
                if(strcmp(sa,"Jaipur")==0)
                {
                                s=fopen("JAIPUR FLIGHT DETAILS.txt","r");
                                if(s==NULL)
                                {
                                                printf("Couldn't open file \n");
                                                exit(0);
                                }
                                while(!feof(s))
                                {
                                                ff = fgetc(s);
                                                printf("%c",ff);
                                }
                                fclose(s);
                                getch();
                }
                if(strcmp(sa,"Goa")==0)
                {
                                s=fopen("GOA FLIGHT DETAILS.txt","r");
                                if(s==NULL)
                                {
                                                printf("Couldn't open file \n");
                                                exit(0);
                                }
                                while(!feof(s))
                                {
                                                ff = fgetc(s);
                                                printf("%c",ff);
                                }
                                fclose(s);
                                getch();
                }
                if(strcmp(sa,"Madurai")==0)
                {
                                s=fopen("MADURAI FLIGHT DETAILS.txt","r");
                                if(s==NULL)
                                {
                                                printf("Couldn't open file \n");
                                                exit(0);
                                }
                                while(!feof(s))
                                {
                                                ff = fgetc(s);
                                                printf("%c",ff);
                                }
                                fclose(s);
                                getch();
                }
                if(strcmp(sa,"Aurangabad")==0)
                {
                                s=fopen("AURANGABAD FLIGHT DETAILS.txt","r");
                                if(s==NULL)
                                {
                                                printf("Couldn't open file \n");
                                                exit(0);
                                }
                                while(!feof(s))
                                {
                                                ff = fgetc(s);
                                                printf("%c",ff);
                                }
                                fclose(s);
                                getch();
                }
                if(strcmp(sa,"Jodhpur")==0)
                {
                                s=fopen("JODHPUR FLIGHT DETAILS.txt","r");
                                if(s==NULL)
                                {
                                                printf("Couldn't open file \n");
                                                exit(0);
                                }
                                while(!feof(s))
                                {
                                                ff = fgetc(s);
                                                printf("%c",ff);
                                }
                                fclose(s);
                                getch();
                }
                if(strcmp(sa,"Mysore")==0)
                {
                                s=fopen("MYSORE FLIGHT DETAILS.txt","r");
                                if(s==NULL)
                                {
                                                printf("Couldn't open file \n");
                                                exit(0);
                                }
                                while(!feof(s))
                                {
                                                ff = fgetc(s);
                                                printf("%c",ff);
                                }
                                fclose(s);
                                getch();
                }
                if(strcmp(sa,"Ladakh")==0)
                {
                                s=fopen("LADAKH FLIGHT DETAILS.txt","r");
                                if(s==NULL)
                                {
                                                printf("Couldn't open file \n");
                                                exit(0);
                                }
                                while(!feof(s))
                                {
                                                ff = fgetc(s);
                                                printf("%c",ff);
                                }
                                fclose(s);
                                getch();
                }
                if(strcmp(sa,"Srinagar")==0)
                {
                                s=fopen("SRINAGAR FLIGHT DETAILS.txt","r");
                                if(s==NULL)
                                {
                                                printf("Couldn't open file \n");
                                                exit(0);
                                }
                                while(!feof(s))
                                {
                                                ff = fgetc(s);
                                                printf("%c",ff);
                                }
                                fclose(s);
                                getch();
                }
                if(strcmp(sa,"Manali")==0)
                {
                                s=fopen("MANALI FLIGHT DETAILS.txt","r");
                                if(s==NULL)
                                {
                                                printf("Couldn't open file \n");
                                                exit(0);
                                }
                                while(!feof(s))
                                {
                                                ff = fgetc(s);
                                                printf("%c",ff);
                                }
                                fclose(s);
                                getch();
                }
                if(strcmp(sa,"Shimla")==0)
                {
                                s=fopen("SHIMLA FLIGHT DETAILS.txt","r");
                                if(s==NULL)
                                {
                                                printf("Couldn't open file \n");
                                                exit(0);
                                }
                                while(!feof(s))
                                {
                                                ff = fgetc(s);
                                                printf("%c",ff);
                                }
                                fclose(s);
                                getch();
                }
                if(strcmp(sa,"Udaipur")==0)
                {
                                s=fopen("UDAIPUR FLIGHT DETAILS.txt","r");
                                if(s==NULL)
                                {
                                                printf("Couldn't open file \n");
                                                exit(0);
                                }
                                while(!feof(s))
                                {
                                                ff = fgetc(s);
                                                printf("%c",ff);
                                }
                                fclose(s);
                                getch();
                }
                if(strcmp(sa,"Ooty")==0)
                {
                                s=fopen("OOTY FLIGHT DETAILS.txt","r");
                                if(s==NULL)
                                {
                                                printf("Couldn't open file \n");
                                                exit(0);
                                }
                                while(!feof(s))
                                {
                                                ff = fgetc(s);
                                                printf("%c",ff);
                                }
                                fclose(s);
                                getch();
                }
                if(strcmp(sa,"Alappuzha")==0)
                {
                                s=fopen("ALAPPUZHA FLIGHT DETAILS.txt","r");
                                if(s==NULL)
                                {
                                                printf("Couldn't open file \n");
                                                exit(0);
                                }
                                while(!feof(s))
                                {
                                                ff = fgetc(s);
                                                printf("%c",ff);
                                }
                                fclose(s);
                                getch();
                }
                if(strcmp(sa,"Munnar")==0)
                {
                                s=fopen("MUNNAR FLIGHT DETAILS.txt","r");
                                if(s==NULL)
                                {
                                                printf("Couldn't open file \n");
                                                exit(0);
                                }
                                while(!feof(s))
                                {
                                                ff = fgetc(s);
                                                printf("%c",ff);
                                }
                                fclose(s);
                                getch();
                }
                if(strcmp(sa,"Kodaikanal")==0)
                {
                                s=fopen("KODAIKANAL FLIGHT DETAILS.txt","r");
                                if(s==NULL)
                                {
                                                printf("Couldn't open file \n");
                                                exit(0);
                                }
                                while(!feof(s))
                                {
                                                ff = fgetc(s);
                                                printf("%c",ff);
                                }
                                fclose(s);
                                getch();
                }
}

//TO GENERATE FLIGHT NAME FROM THE GIVEN DESTINATION
char genFlightName(char s[],char store[])
{
             if((strcmp(s,"Agra")==0)|| (strcmp(s,"Varanasi")==0) || (strcmp(s,"New Delhi")==0)||(strcmp(s,"Amritsar")==0))
             {
                             strcpy(store,"SPICEJET");
             }
             if((strcmp(s,"Jaisalmer")==0)|| (strcmp(s,"Jaipur")==0) || (strcmp(s,"Jodhpur")==0)||(strcmp(s,"Udaipur")==0))
             {
                             strcpy(store,"INDIGO");
             }
             if((strcmp(s,"Alappuzha")==0)|| (strcmp(s,"Ooty")==0) || (strcmp(s,"Madurai")==0)||(strcmp(s,"Kodaikanal")==0)||(strcmp(s,"Munnar")==0))
             {
                             strcpy(store,"KINGFISHER");
             }
             if((strcmp(s,"Hyderabad")==0)|| (strcmp(s,"Goa")==0) || (strcmp(s,"Mysore")==0)||(strcmp(s,"Mumbai")==0)||(strcmp(s,"Aurangabad")==0))
             {
                             strcpy(store,"ETIHAD");
             }
             if((strcmp(s,"Shimla")==0)|| (strcmp(s,"Srinagar")==0) || (strcmp(s,"Manali")==0)||(strcmp(s,"Ladakh")==0))
             {
                             strcpy(store,"AIRINDIA");
             }
}

//TO CHECK IF THE FLIGHT TAKES OFF ON THE ENTERED DATE
int flightDate(char s[],int d)
{
                if(strcmp(s,"Agra")==0)
                {
                                if(d==17 || d==23)
                                {
                                                return 0;
                                }
                                else
                                {
                                                return 1;
                                }
                }
                if(strcmp(s,"Varanasi")==0)
                {
                                if(d==10 || d==15)
                                {
                                                return 0;
                                }
                                else
                                {
                                                return 1;
                                }
                }
                if(strcmp(s,"Amritsar")==0)
                {
                                if(d==1 || d==13)
                                {
                                                return 0;
                                }
                                else
                                {
                                                return 1;
                                }
                }
                if(strcmp(s,"Jaisalmer")==0)
                {
                                if(d==12 || d==22)
                                {
                                                return 0;
                                }
                                else
                                {
                                                return 1;
                                }
                }
                if(strcmp(s,"New Delhi")==0)
                {
                                if(d==5 || d==30)
                                {
                                                return 0;
                                }
                                else
                                {
                                                return 1;
                                }
                }
                if(strcmp(s,"Mumbai")==0)
                {
                                if(d==26 || d==30)
                                {
                                                return 0;
                                }
                                else
                                {
                                                return 1;
                                }
                }
                if(strcmp(s,"Hyderabad")==0)
                {
                                if(d==1 || d==8)
                                {
                                                return 0;
                                }
                                else
                                {
                                                return 1;
                                }
                }
                if(strcmp(s,"Jaipur")==0)
                {
                                if(d==7 || d==25)
                                {
                                                return 0;
                                }
                                else
                                {
                                                return 1;
                                }
                }
                if(strcmp(s,"Goa")==0)
                {
                                if(d==11 || d==18)
                                {
                                                return 0;
                                }
                                else
                                {
                                                return 1;
                                }
                }
                if(strcmp(s,"Madurai")==0)
                {
                                if(d==10 || d==30)
                                {
                                                return 0;
                                }
                                else
                                {
                                                return 1;
                                }
                }
                if(strcmp(s,"Aurangabad")==0)
                {
                                if(d==3 || d==13)
                                {
                                                return 0;
                                }
                                else
                                {
                                                return 1;
                                }
                }
                if(strcmp(s,"Jodhpur")==0)
                {
                                if(d==16 || d==20)
                                {
                                                return 0;
                                }
                                else
                                {
                                                return 1;
                                }
                }
                if(strcmp(s,"Mysore")==0)
                {
                                if(d==20 || d==24)
                                {
                                                return 0;
                                }
                                else
                                {
                                                return 1;
                                }
                }
                if(strcmp(s,"Ladakh")==0)
                {
                                if(d==26 || d==30)
                                {
                                                return 0;
                                }
                                else
                                {
                                                return 1;
                                }
                }
                if(strcmp(s,"Srinagar")==0)
                {
                                if(d==12 || d==15)
                                {
                                                return 0;
                                }
                                else
                                {
                                                return 1;
                                }
                }
                if(strcmp(s,"Manali")==0)
                {
                                if(d==19 || d==23)
                                {
                                                return 0;
                                }
                                else
                                {
                                                return 1;
                                }
                }
                if(strcmp(s,"Shimla")==0)
                {
                                if(d==2 || d==9)
                                {
                                                return 0;
                                }
                                else
                                {
                                                return 1;
                                }
                }
                if(strcmp(s,"Udaipur")==0)
                {
                                if(d==15 || d==28)
                                {
                                                return 0;
                                }
                                else
                                {
                                                return 1;
                                }
                }
                if(strcmp(s,"Ooty")==0)
                {
                                if(d==17 || d==21)
                                {
                                                return 0;
                                }
                                else
                                {
                                                return 1;
                                }
                }
                if(strcmp(s,"Alappuzha")==0)
                {
                                if(d==2 || d==13)
                                {
                                                return 0;
                                }
                                else
                                {
                                                return 1;
                                }
                }
                if(strcmp(s,"Munnar")==0)
                {
                                if(d==1 || d==26)
                                {
                                                return 0;
                                }
                                else
                                {
                                                return 1;
                                }
                }
                if(strcmp(s,"Kodaikanal")==0)
                {
                                if(d==4 || d==24)
                                {
                                                return 0;
                                }
                                else
                                {
                                                return 1;
                                }
                }
}

//TO CHECK IF THE ENTERED FLIGTH SEAT HAS ALREADY BEEN BOOKED
int checkFSeat(int a[],int an,int c)
{
                int i;
                if(an==0 || an==1 || an==2 || an ==3 || an==4 )
                {
                                for(i=0;i<=an;i++)
                                {
                                                if(a[an]==c)
                                                return 0;
                                }
                                return 1;
                }
                else
                {
                                return 1;
                }
}

//DISPLAY THE BUS PASSENGER DETAILS
void display()
{
                system("cls");
                bus s1;
                FILE *fpp;
                int n,seat,i,flag =0;
                for(i=0;i<100;i++)
                {
                                printf("\xcd");
                }
                printf("\n");
                printf("\t\t\t\tVIEW PASSENGERS\n");
                for(i=0;i<100;i++)
                {
                                printf("\xcd");
                }
                printf("\n\nEnter your bus number : ");
                scanf("%d",&n);
                printf("Enter the seat number whose details you want to see : ");
                scanf("%d",&seat);
                switch(n)
                {
                                case 1 ://SEARCH A RECORD FROM BUS 1
                                {
                                                fpp=fopen("BUS 1 PASSENGER DETAILS.txt","r");
                                                if(fpp==NULL)
                                                {
                                                                printf("COULDN'T OPEN FILE");
                                                                exit(0);
                                                }
                                                while(fread(&s1,sizeof(bus),1,fpp))
                                                {
                                                                if(s1.busno ==1 && s1.seatno ==seat)
                                                                {
                                                                                for(i=0;i<100;i++)
                                                                                {
                                                                                                printf("\xcd");
                                                                                }
                                                                                printf("\n");
                                                                                printf("\t\t\t\tPASSENGER DETAILS\n");
                                                                                for(i=0;i<100;i++)
                                                                                {
                                                                                                printf("\xcd");
                                                                                }
                                                                                flag =1;
                                                                                printf("\n\tPASSENGER NAME : %s\n\tPASSENGER AGE : %d\n\tPASSENGER GENDER : %c\n\tPASSENGER SEAT NUMBER : %d\n\tPASSENGER SEAT STATUS : %s\n\tPASSENGER DROP DESTINATION : %s\n\n",s1.name,s1.age,s1.gender,s1.seatno,s1.status,s1.destination);

                                                                }

                                                }
                                                if(flag==0)
                                                {
                                                                printf("Enter the correct seat number orelse the seat is not booked yet");
                                                }
                                                fclose(fpp);
                                                getch();
                                                break;
                                }
                                case 2 ://SEARCH A RECORD FROM BUS 2
                                {
                                                fpp=fopen("BUS 2 PASSENGER DETAILS.txt","r");
                                                if(fpp==NULL)
                                                {
                                                                printf("COULDN'T OPEN FILE");
                                                                exit(0);
                                                }
                                                while(fread(&s1,sizeof(bus),1,fpp))
                                                {
                                                                if(s1.busno==2 && s1.seatno==seat)
                                                                {
                                                                                for(i=0;i<100;i++)
                                                                                {
                                                                                                printf("\xcd");
                                                                                }
                                                                                printf("\n");
                                                                                printf("\t\t\t\tPASSENGER DETAILS\n");
                                                                                for(i=0;i<100;i++)
                                                                                {
                                                                                                printf("\xcd");
                                                                                }
                                                                                flag =1;
                                                                                printf("\n\tPASSENGER NAME : %s\n\tPASSENGER AGE : %d\n\tPASSENGER GENDER : %c\n\tPASSENGER SEAT NUMBER : %d\n\tPASSENGER SEAT STATUS : %s\n\tPASSENGER DROP DESTINATION : %s\n\n",s1.name,s1.age,s1.gender,s1.seatno,s1.status,s1.destination);

                                                                }
                                                }
                                                if(flag==0)
                                                {
                                                                printf("Enter the correct seat number orelse the seat is not booked yet");
                                                }
                                                fclose(fpp);
                                                getch();
                                                break;
                                }
                                case 3 :
                                {
                                                fpp=fopen("BUS 3 PASSENGER DETAILS.txt","r");
                                                if(fpp==NULL)
                                                {
                                                                printf("COULDN'T OPEN FILE");
                                                                exit(0);
                                                }
                                                while(fread(&s1,sizeof(bus),1,fpp))
                                                {
                                                                if(s1.busno==3 && s1.seatno==seat)
                                                                {
                                                                                for(i=0;i<100;i++)
                                                                                {
                                                                                                printf("\xcd");
                                                                                }
                                                                                printf("\n");
                                                                                printf("\t\t\t\tPASSENGER DETAILS\n");
                                                                                for(i=0;i<100;i++)
                                                                                {
                                                                                                printf("\xcd");
                                                                                }
                                                                                flag =1;
                                                                                printf("\n\tPASSENGER NAME : %s\n\tPASSENGER AGE : %d\n\tPASSENGER GENDER : %c\n\tPASSENGER SEAT NUMBER : %d\n\tPASSENGER SEAT STATUS : %s\n\tPASSENGER DROP DESTINATION : %s\n\n",s1.name,s1.age,s1.gender,s1.seatno,s1.status,s1.destination);

                                                                }
                                                }
                                                if(flag==0)
                                                {
                                                                printf("Enter the correct seat number orelse the seat is not booked yet");
                                                }
                                                fclose(fpp);
                                                getch();
                                                break;
                                }
                                case 4 :
                                {
                                                fpp=fopen("BUS 4 PASSENGER DETAILS.txt","r");
                                                if(fpp==NULL)
                                                {
                                                                printf("COULDN'T OPEN FILE");
                                                                exit(0);
                                                }
                                                while(fread(&s1,sizeof(bus),1,fpp))
                                                {
                                                                if(s1.busno==4 && s1.seatno==seat)
                                                                {
                                                                                for(i=0;i<100;i++)
                                                                                {
                                                                                                printf("\xcd");
                                                                                }
                                                                                printf("\n");
                                                                                printf("\t\t\t\tPASSENGER DETAILS\n");
                                                                                for(i=0;i<100;i++)
                                                                                {
                                                                                                printf("\xcd");
                                                                                }
                                                                                flag =1;
                                                                                printf("\n\tPASSENGER NAME : %s\n\tPASSENGER AGE : %d\n\tPASSENGER GENDER : %c\n\tPASSENGER SEAT NUMBER : %d\n\tPASSENGER SEAT STATUS : %s\n\tPASSENGER DROP DESTINATION : %s\n\n",s1.name,s1.age,s1.gender,s1.seatno,s1.status,s1.destination);

                                                                }
                                                }
                                                if(flag==0)
                                                {
                                                                printf("Enter the correct seat number orelse the seat is not booked yet");
                                                }
                                                fclose(fpp);
                                                getch();
                                                break;
                                }
                                case 5 :
                                {
                                                fpp=fopen("BUS 5 PASSENGER DETAILS.txt","r");
                                                if(fpp==NULL)
                                                {
                                                                printf("COULDN'T OPEN FILE");
                                                                exit(0);
                                                }
                                                while(fread(&s1,sizeof(bus),1,fpp))
                                                {
                                                                if(s1.busno==5 && s1.seatno==seat)
                                                                {
                                                                                for(i=0;i<100;i++)
                                                                                {
                                                                                                printf("\xcd");
                                                                                }
                                                                                printf("\n");
                                                                                printf("\t\t\t\tPASSENGER DETAILS\n");
                                                                                for(i=0;i<100;i++)
                                                                                {
                                                                                                printf("\xcd");
                                                                                }
                                                                                flag =1;
                                                                                printf("\n\tPASSENGER NAME : %s\n\tPASSENGER AGE : %d\n\tPASSENGER GENDER : %c\n\tPASSENGER SEAT NUMBER : %d\n\tPASSENGER SEAT STATUS : %s\n\tPASSENGER DROP DESTINATION : %s\n\n",s1.name,s1.age,s1.gender,s1.seatno,s1.status,s1.destination);

                                                                }
                                                }
                                                if(flag==0)
                                                {
                                                                printf("Enter the correct seat number orelse the seat is not booked yet");
                                                }
                                                fclose(fpp);
                                                getch();
                                                break;
                                }
                }

}

//CANCELLING A BUS TICKET
void cancel(int n)
{
                system("cls");
                bus s1;
                FILE *fpp,*fp;
                int i,seat,found=0;
                fp =fopen("Temp.txt","w");
                for(i=0;i<100;i++)
                {
                                printf("\xcd");
                }
                printf("\n");
                printf("\t\t\t\tCANCEL TICKET\n");
                for(i=0;i<100;i++)
                {
                                printf("\xcd");
                }
                printf("Enter the seat number to delete : ");
                scanf("%d",&seat);
                switch(n)
                {
                                case 1 : //CANCEL TICKET FROM BUS 1
                                {
                                                fpp=fopen("BUS 1 PASSENGER DETAILS.txt","r");
                                                if(fpp==NULL)
                                                {
                                                                printf("COULDN'T OPEN FILE");
                                                                exit(0);
                                                }
                                                while(fread(&s1,sizeof(bus),1,fpp))
                                                {
                                                                if(s1.busno==1 && s1.seatno==seat)
                                                                {
                                                                                found=1;
                                                                }
                                                                else
                                                                {
                                                                                fwrite(&s1,sizeof(bus),1,fp);
                                                                }
                                                }
                                                fclose(fp);
                                                fclose(fpp);
                                                if(found)
                                                {
                                                                fp = fopen("Temp.txt","r");
                                                                fpp= fopen("BUS 1 PASSENGER DETAILS.txt","w");
                                                                while(fread(&s1,sizeof(bus),1,fp))
                                                                {
                                                                                fwrite(&s1,sizeof(bus),1,fpp);
                                                                }
                                                                fclose(fp);
                                                                fclose(fpp);
                                                }
                                                getch();
                                                break;
                                }
                                case 2 :
                                {
                                                fpp=fopen("BUS 2 PASSENGER DETAILS.txt","r");
                                                if(fpp==NULL)
                                                {
                                                                printf("COULDN'T OPEN FILE");
                                                                exit(0);
                                                }
                                                while(fread(&s1,sizeof(bus),1,fpp))
                                                {
                                                                if(s1.busno==2 && s1.seatno==seat)
                                                                {
                                                                                found=1;
                                                                }
                                                                else
                                                                {
                                                                                fwrite(&s1,sizeof(bus),1,fp);
                                                                }
                                                }
                                                fclose(fp);
                                                fclose(fpp);
                                                if(found)
                                                {
                                                                fp = fopen("Temp.txt","r");
                                                                fpp= fopen("BUS 2 PASSENGER DETAILS.txt","w");
                                                                while(fread(&s1,sizeof(bus),1,fp))
                                                                {
                                                                                fwrite(&s1,sizeof(bus),1,fpp);
                                                                }
                                                                fclose(fp);
                                                                fclose(fpp);
                                                }
                                                getch();
                                                break;
                                }
                                case 3 :
                                {
                                                fpp=fopen("BUS 3 PASSENGER DETAILS.txt","r");
                                                if(fpp==NULL)
                                                {
                                                                printf("COULDN'T OPEN FILE");
                                                                exit(0);
                                                }
                                                while(fread(&s1,sizeof(bus),1,fpp))
                                                {
                                                                if(s1.busno==3 && s1.seatno==seat)
                                                                {
                                                                                found=1;
                                                                }
                                                                else
                                                                {
                                                                                fwrite(&s1,sizeof(bus),1,fp);
                                                                }
                                                }
                                                fclose(fp);
                                                fclose(fpp);
                                                if(found)
                                                {
                                                                fp = fopen("Temp.txt","r");
                                                                fpp= fopen("BUS 3 PASSENGER DETAILS.txt","w");
                                                                while(fread(&s1,sizeof(bus),1,fp))
                                                                {
                                                                                fwrite(&s1,sizeof(bus),1,fpp);
                                                                }
                                                                fclose(fp);
                                                                fclose(fpp);
                                                }
                                                getch();
                                                break;
                                }
                                case 4 :
                                {
                                                fpp=fopen("BUS 4 PASSENGER DETAILS.txt","r");
                                                if(fpp==NULL)
                                                {
                                                                printf("COULDN'T OPEN FILE");
                                                                exit(0);
                                                }
                                                while(fread(&s1,sizeof(bus),1,fpp))
                                                {
                                                                if(s1.busno==4 && s1.seatno==seat)
                                                                {
                                                                                found=1;
                                                                }
                                                                else
                                                                {
                                                                                fwrite(&s1,sizeof(bus),1,fp);
                                                                }
                                                }
                                                fclose(fp);
                                                fclose(fpp);
                                                if(found)
                                                {
                                                                fp = fopen("Temp.txt","r");
                                                                fpp= fopen("BUS 4 PASSENGER DETAILS.txt","w");
                                                                while(fread(&s1,sizeof(bus),1,fp))
                                                                {
                                                                                fwrite(&s1,sizeof(bus),1,fpp);
                                                                }
                                                                fclose(fp);
                                                                fclose(fpp);
                                                }
                                                getch();
                                                break;
                                }
                                case 5 :
                                {
                                                fpp=fopen("BUS 5 PASSENGER DETAILS.txt","r");
                                                if(fpp==NULL)
                                                {
                                                                printf("COULDN'T OPEN FILE");
                                                                exit(0);
                                                }
                                                while(fread(&s1,sizeof(bus),1,fpp))
                                                {
                                                                if(s1.busno==5 && s1.seatno==seat)
                                                                {
                                                                                found=1;
                                                                }
                                                                else
                                                                {
                                                                                fwrite(&s1,sizeof(bus),1,fp);
                                                                }
                                                }
                                                fclose(fp);
                                                fclose(fpp);
                                                if(found)
                                                {
                                                                fp = fopen("Temp.txt","r");
                                                                fpp= fopen("BUS 5 PASSENGER DETAILS.txt","w");
                                                                while(fread(&s1,sizeof(bus),1,fp))
                                                                {
                                                                                fwrite(&s1,sizeof(bus),1,fpp);
                                                                }
                                                                fclose(fp);
                                                                fclose(fpp);
                                                }
                                                getch();
                                                break;
                                }
                }
}
//DELETING AN ELEMENT IN THE ARRAYS
void deleteArrayElement(int a[],int size,int n,int x)
{
                int j,y,k;
                for(j=0;j<size;j++)
                {
                                if(a[j]==n)
                                {
                                                y=j+1;
                                }
                }
                for(k=y;k<size;k++)
                {
                                a[k-1]=a[k];
                }
                size--;
                x++;
}

//DISPLAY THE DETAILS OF A FLIGHT TICKET
void displayFlight(void)
{
                system("cls");
                char place[20];
                int date;
                int seat,seatfound=0;
                FILE *view;
                flight s1;
                printf("================================================ VIEW PASSENGER DETAILS=============================");
                printf("Enter the name of the destination : ");
                scanf("%*c%[^\n]s",place);
                printf("Enter the date of the flight : ");
                scanf("%d",&date);
                printf("Enter the seat number whose details you want to see : ");
                scanf("%d",&seat);
                view = fopen("FLIGHT PASSENGER DETAILS.txt","r");
                while(fread(&s1,sizeof(flight),1,view))
                {
                                if(!strcmp(s1.destination,place))
                                {
                                                if(s1.dd ==date)
                                                {
                                                                if(s1.seatno==seat)
                                                                {
                                                                                system("cls");
                                                                                printf("==============================PASSENGER DETAILS================================\n\n");
                                                                                printf("PASSENGER NAME        : %s\n",s1.name);
                                                                                printf("PASSENGER AGE         : %d\n",s1.age);
                                                                                printf("PASSENGER GENDER      : %c\n",s1.gender);
                                                                                printf("PASSENGER SEAT NUMBER : %d\n",s1.seatno);
                                                                                printf("PASSENGER DESTINATION : %s\n",s1.destination);
                                                                                printf("FLIGHT NAME           : %s\n",s1.flightname);
                                                                                printf("DATE OF TRAVEL        : %d.%d.%d\n",s1.dd,s1.mm,s1.yyyy);
                                                                                seatfound=1;
                                                                }
                                                }
                                }
                }
                if(seatfound==0)
                {
                                printf("THIS SEAT HAS NOT BEEN BOOKED YET\n");
                }
                fclose(view);

}

//CANCEL THE FLIGHT TICKET
void cancelFlight(void)
{
                system("cls");
                flight s1;
                seat_allocation s2;
                FILE *fp,*fpp,*fppp;
                char place[20];
                int date,seat,plus=0,j,k,y,flag=0;
                printf("ENTER THE DESTINATION NAME : ");
                scanf("%*c%[^\n]",&place);
                printf("ENTER THE DATE OF TRAVEL : ");
                scanf("%d",&date);
                printf("ENTER THE SEAT NUMBER WHOSE BOOKING YOU WANT TO CANCEL : ");
                scanf("%d",&seat);
                fp=fopen("FLIGHT PASSENGER DETAILS.txt","r");
                fpp=fopen("TEMP4.txt","w");
                while(fread(&s1,sizeof(flight),1,fp))
                {
                                if(!strcmp(s1.destination,place))
                                {
                                                if(s1.dd==date)
                                                {
                                                                if(s1.seatno==seat)
                                                                {
                                                                                plus=1;
                                                                }
                                                                else
                                                                {
                                                                                fwrite(&s1,sizeof(flight),1,fpp);
                                                                }
                                                }
                                                else
                                                {
                                                                fwrite(&s1,sizeof(flight),1,fpp);
                                                }
                                }
                                else
                                {
                                                fwrite(&s1,sizeof(flight),1,fpp);
                                }
                }
                fclose(fp);
                fclose(fpp);
                if(plus==0)
                {
                          printf("THE SEAT HAS NOT BEEN BOOKED YET\n");
                }
                if(plus==1)
                {
                                fp=fopen("TEMP4.txt","r");
                                fpp=fopen("FLIGHT PASSENGER DETAILS.txt","w");
                                while(fread(&s1,sizeof(flight),1,fp))
                                {
                                                fwrite(&s1,sizeof(flight),1,fpp);
                                }
                                fclose(fpp);
                                fclose(fp);
                                fp=fopen("FLIGHT GENERAL DETAILS.txt","r");
                                fpp=fopen("TEMP5.txt","w");
                                fppp=fopen("TEMP6.txt","w");
                                if(fpp==NULL)
                                {
                                               printf("Couldn't open the file\n");
                                               exit(0);
                                }
                                if(fp==NULL)
                                {
                                                printf("Couldn't open the file\n");
                                                exit(0);
                                }
                                while(fread(&s2,sizeof(seat_allocation),1,fp))
                                {
                                                if(!strcmp(s2.destination,place))
                                                {
                                                                if(s2.date==date)
                                                                {
                                                                                flag=1;
                                                                                fwrite(&s2,sizeof(seat_allocation),1,fppp);
                                                                }
                                                                else
                                                                {
                                                                                fwrite(&s2,sizeof(seat_allocation),1,fpp);
                                                                }
                                                }
                                                else
                                                {
                                                                fwrite(&s2,sizeof(seat_allocation),1,fpp);
                                                }
                                }
                                fclose(fp);
                                fclose(fpp);
                                fclose(fppp);
                                if(flag==1)
                                {
                                                fp=fopen("TEMP5.txt","r");
                                                fpp=fopen("FLIGHT GENERAL DETAILS.txt","w");
                                                while(fread(&s2,sizeof(seat_allocation),1,fp))
                                                {
                                                                fwrite(&s2,sizeof(seat_allocation),1,fpp);
                                                }
                                                fclose(fp);
                                                fclose(fpp);
                                                fp=fopen("TEMP6.txt","a+");
                                                fpp=fopen("FLIGHT GENERAL DETAILS.txt","a+");
                                                fread(&s2,sizeof(seat_allocation),1,fp);
                                                s2.fnosa++;
                                                for(j=0;j<s2.fbsnasize;j++)
                                                {
                                                                if(s2.fbsn[j]==seat)
                                                                {
                                                                                y=j+1;
                                                                }
                                                }
                                                for(k=y;k<s2.fbsnasize;k++)
                                                {
                                                                s2.fbsn[k-1]=s2.fbsn[k];
                                                }
                                                s2.fbsnasize--;
                                                fwrite(&s2,sizeof(seat_allocation),1,fpp);
                                                fclose(fp);
                                                fclose(fpp);
                                }

                }
}

//MAIN FUNCTION
int main()
{

                //LOGIN PAGE VARIABLE DECLARATIONS
                struct user user;
                int opt,i;
                char a;
                FILE *fp;
                //VARIABLES TO CHOOSE THE DESTINATION
                FILE *travel_to_destinations;
                char b,destination[30];
                int lopt;
                //VARIABLES FOR TICKET BOOKING
                int mode;
                //VARIABLES FOR BUS TICKET BOOKING
                bus passenger;
                FILE *passenger_details;
                int bopt,busno,d,m,year,k,l,j,seatnumber;
                int no_ofseats=0;
                char ch,payment;
                float cost;
                FILE *bus_details;
                static int b1available_seats=35,b2available_seats=35,b3available_seats=35,b4available_seats=35,b5available_seats=35;
                static int b1booked_seatnos[35]={0},b2booked_seatnos[35]={0},b3booked_seatnos[35]={0},b4booked_seatnos[35]={0},b5booked_seatnos[35]={0},b1as=0,b2as=0,b3as=0,b4as=0,b5as=0;
                //VARIABLES FOR FLIGHT TICKET BOOKING
                int fopt;
                char ff;
                FILE *flight_details;
                flight customer;
                char flightname2[20];
                int date,month,y,p,q,flightfound=0,r,flag=0,flag2=0,flag3=0;
                seat_allocation jet;
                FILE *seat_reader,*temp,*temp2;
                FILE *customer_details;

                //VARIABLES FOR TIC TAC TOE
                char bored,done = ' ',e;
                int eopt;
                //VARIABLES FOR READING JOURNALS
                FILE *read_journals;
                int rjopt;
                char dtemp;
                //VARIABLES FOR AFTER REACHING DESTINATION
                char food;
                char destination_2[50];
                L0 : system("color b0");
                for(i=0;i<100;i++)
                {
                                printf("\xcd");
                }
                printf("\n");
                printf("\n\t\t\t\t     WELCOME TO SKY HIGH!!!!!!!!!!\n");
                for(i=0;i<100;i++)
                {
                                printf("\xcd");
                }
                printf("\n");
                printf("\n\t\t\t--------Welome to the authetication system-------\n");
                for(i=0;i<100;i++)
                {
                                printf("\xcd");
                }
                printf("\n");
                printf("\n\n\t\t\tEnter the corresponding number of the portal of your choice ");
                printf("\n\n\t\t\t        1.Sign Up.\t2.Login.\t3.Exit.\n\n\n \t\t\t\t\t  Your choice :");
                scanf("\t\t%d",&opt);
                printf("\n");
                switch(opt)
                {
                                case 1 ://SIGN UP WINDOW
                                {
                                                L7 : system("color b0");
                                                system("cls");
                                                for(i=0;i<100;i++)
                                                {
                                                                printf("\xcd");
                                                }
                                                printf("\n");
                                                printf("\t\t\t\t\t WELCOME TO SIGN UP PAGE\n");
                                                for(i=0;i<100;i++)
                                                {
                                                                printf("\xcd");
                                                }
                                                printf("\n");
                                                L1 : printf("\nEnter your full name : ");// NAME
                                                scanf("%*c%[^\n]s",&user.fullName);
                                                if(checkString(user.fullName)==0)
                                                {
                                                                printf("\tINVALID USER NAME\n\tPLEASE RE-ENTER\n");
                                                                goto L1;
                                                }
                                                L2 : printf("\nEnter your email : ");//EMAIL ID
                                                scanf("%*c%[^\n]s",&user.email);
                                                if(checkEmail(user.email)==0)
                                                {
                                                                printf("\tINVALID EMAIL ID\n\tPLEASE RE-ENTER\n");
                                                                goto L2;
                                                }
                                                L3 : printf("\nEnter your contact number: ");// PHONE NUMBER
                                                scanf("%*c%[^\n]s",&user.phNo);
                                                if(checkPhno(user.phNo)==0)
                                                {
                                                                printf("\tINVALID PHONE NUMBER\n\tPLEASE RE-ENTER\n");
                                                                goto L3;
                                                }
                                                L4 : printf("\n\n\t\t\tPASSWORD \n\tNOTE :A valid password must contain : \n\t ! Only 8 characters \n\t ! At least one lowercase letter\n\t ! At least one uppercase letter\n\t ! At least one non-letter character  \n\nEnter your Password : ");
                                                starPassword(user.password);//PASSWORD IN STAR FORM
                                                if(checkPassword(user.password)==0)
                                                {
                                                                printf("\n\tINVALID PASSWORD\n\tPLEASE RE-ENTER A VALID PASSWORD");
                                                                goto L4;
                                                }
                                                L5 : printf("\nConfirm your password :");//RE-CHECK PASSWORD
                                                starPassword(user.pwd2);
                                                if(strcmp(user.password,user.pwd2)!=0)
                                                {
                                                                printf("\n\tPASSWORD DOES NOT MATCH\n\tPLEASE RE-ENTER THE PASSWORD\n");
                                                                goto L5;
                                                }
                                                genUsername(user.email,user.username);
                                                printf("\n\nYour username is : %s\n",user.username);//DISPLAY AUTO-GENERATED USERNAME
                                                getch();
                                                fp = fopen("REGISTRATION.txt","a+");//OPENING FILE USING FILE POINTER TO STORE THE SIGN IN DETAILS
                                                if(fp==NULL)
                                                {
                                                                printf("Couldn't open file\n");
                                                                exit(0);
                                                }
                                                fwrite(&user,sizeof(struct user),1,fp);//WRITING THE DATA INTO THE FILE IN BLOCK FORM
                                                if(fwrite !=0)
                                                {
                                                                printf("\n\nUser registration success! :):)\n\n");
                                                                getch();
                                                }
                                                fclose(fp);//CLOSING FILE
                                                system("cls");
                                                printf("\n\n\n\t\tWould you like to continue to the login window ?\n\t\tNOTE : Enter y if YES  : ");//TO DIRECTLY GO TO THE LOGIN WINDOW
                                                scanf("%*c%c",&a);
                                                if(a=='y'||a=='Y')
                                                {
                                                                system("cls");
                                                                system("color 50");
                                                                goto L6;
                                                }
                                                break;
                                }
                                case 2 : // LOGIN PAGE
                                {
                                                system("cls");
                                                system("color e5");
                                                char username[50],pwd[50];
                                                struct user usr;
                                                int userFound=0;
                                                L6 : for(i=0;i<100;i++)
                                                {
                                                                printf("\xcd");
                                                }
                                                printf("\n");
                                                printf("\t\t\t\t\t WELCOME TO LOGIN PAGE\n");
                                                for(i=0;i<100;i++)
                                                {
                                                                printf("\xcd");
                                                }
                                                printf("\n");
                                                printf("Enter your USERNAME : ");//USERNAME
                                                scanf("%*c%[^\n]s",username);
                                                printf("Enter your password : ");
                                                starPassword(pwd);
                                                fp=fopen("REGISTRATION.txt","r");//OPENING FILE TO CHECK IF THE USER TRYING TO LOGIN HAS ALREADY SIGNED UP
                                                if(fp==NULL)
                                                {
                                                                printf("Couldn't open file\n");
                                                                exit(0);
                                                }
                                                while(fread(&usr,sizeof(struct user),1,fp))
                                                {
                                                                if(!strcmp(usr.username,username))//CHECKING IF THE ENTEREDD USERNAME IS AVAILABLE IN THE FILE
                                                                {
                                                                                if(!strcmp(usr.password,pwd))//CHECKING IF THE RECORDED PASSWORD OF THAT PARTICULAR USER MATCHES THE ENTERED PASSWORD
                                                                                {
                                                                                                L8 : system("cls");
                                                                                                system("color 0a");
                                                                                                printf("\n\n\n\t\t\t\t\tWELCOME %s\n",usr.fullName);//WELCOMES THE USER
                                                                                                getch();
                                                                                                //CODE TO CHOOSE THE DESTINATION OF TRAVEL
                                                                                                for(i=0;i<100;i++)
                                                                                                {
                                                                                                                printf("\xcd");
                                                                                                }
                                                                                                printf("\n");
                                                                                                printf("\t\t\t\tMAIN MENU\n");
                                                                                                for(i=0;i<100;i++)
                                                                                                {
                                                                                                                printf("\xcd");
                                                                                                }
                                                                                                printf("\n");
                                                                                                printf("\n\n\t[1]BOOK AND VIEW TICKETS\t[2]ENROUTE\t[3]REACHED DESTINATION\t[4]EXIT\n");
                                                                                                scanf("%d",&lopt);
                                                                                                switch(lopt)
                                                                                                {
                                                                                                                case 1 : //TO BOOK TICKETS
                                                                                                                {
                                                                                                                                //PRINTING THE DESTINATIONS AVAILABLE FOR TRAVELLING
                                                                                                                                system("cls");
                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                {
                                                                                                                                                printf("\xcd");
                                                                                                                                }
                                                                                                                                printf("\n");
                                                                                                                                printf("\n\n\t\t\tPLACES AVAILABLE FOR TRAVELLING\n\n");
                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                {
                                                                                                                                                printf("\xcd");
                                                                                                                                }
                                                                                                                                printf("\n\n\n");
                                                                                                                                travel_to_destinations=fopen("DESTINATIONS.txt","r");//OPENING THE FILE TO PRINT ALL THE DESTINATIONS WHERE SKY HIGH CAN TAKE THE CUSTOMER
                                                                                                                                while(!feof(travel_to_destinations))//READING THE FILE UNTIL THE FILE POINTER REACHES THE END OF THE FILE
                                                                                                                                {
                                                                                                                                                b=fgetc(travel_to_destinations);
                                                                                                                                                printf("%c",b);
                                                                                                                                }
                                                                                                                                fclose(travel_to_destinations);//CLOSING THE FILE
                                                                                                                                D0 : printf("\n\n\t\tEnter the place where you want to book the tickets : ");//GETTING INPUT TO KNOW THE DESTINATION
                                                                                                                                scanf("%*c%[^\n]s",destination);
                                                                                                                                if(checkDestination(destination)==0)//CHECKING IF CORRECT DESTINATION HAS BEEN GIVEN
                                                                                                                                {
                                                                                                                                                printf("\n\tENTER THE DESTINATION NAME FROM THE AVAILABLE LIST WITH CORRECT SPELLING\n\n");
                                                                                                                                                goto D0;
                                                                                                                                }
                                                                                                                                getch();
                                                                                                                                system("cls");
                                                                                                                                system("color 0b");
                                                                                                                                M0 : for(i=0;i<100;i++)
                                                                                                                                {
                                                                                                                                                printf("\xcd");
                                                                                                                                }
                                                                                                                                printf("\n");
                                                                                                                                printf("\n\n\t\tTHE MODE OF TRANSPORTATION AVAILABLE \n");//TO CHOOSE THE MODE OF TRANSPORT
                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                {
                                                                                                                                                printf("\xcd");
                                                                                                                                }
                                                                                                                                printf("\n");
                                                                                                                                printf("\n\n\t\t[1]BUS\t[2]FLIGHT\t[3]EXIT\n\n\t\tPlease enter your mode of transport : ");
                                                                                                                                scanf("%d",&mode);
                                                                                                                                switch(mode)
                                                                                                                                {
                                                                                                                                                case 1 ://BUS TICKET BOOKING PORTAL
                                                                                                                                                {
                                                                                                                                                                B0 : system("cls");
                                                                                                                                                                system("color d7");
                                                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                                                {
                                                                                                                                                                                printf("\xcd");
                                                                                                                                                                }
                                                                                                                                                                printf("\n");
                                                                                                                                                                printf("\t\t\tWELCOME TO BUS TICKET BOOKING PORTAL\n");
                                                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                                                {
                                                                                                                                                                printf("\xcd");
                                                                                                                                                                }
                                                                                                                                                                printf("\n");
                                                                                                                                                                printf("\t\t\tMAIN MENU\n");
                                                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                                                {
                                                                                                                                                                                printf("\xcd");
                                                                                                                                                                }
                                                                                                                                                                printf("\n");
                                                                                                                                                                printf("[1]VIEW BUS LIST\n[2]BUS DETAILS\n[3]BOOK TICKETS\n[4]CANCEL BOOKING\n[5]VIEW PASSENGER DETAILS\n[6]EXIT\n\n\t\tEnter your choice : ");
                                                                                                                                                                scanf("%d",&bopt);
                                                                                                                                                                switch(bopt)
                                                                                                                                                                {
                                                                                                                                                                                case 1 : //DISPLAYS BUS LIST ALONG WITH THE ROUTES THEY FOLLOW
                                                                                                                                                                                {
                                                                                                                                                                                                system("cls");
                                                                                                                                                                                                system("color a3");
                                                                                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                                                                                {
                                                                                                                                                                                                                printf("\xcd");
                                                                                                                                                                                                }
                                                                                                                                                                                                printf("\n");
                                                                                                                                                                                                printf("\t\t\t\t\t\tBUS LIST\n");
                                                                                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                                                                                {
                                                                                                                                                                                                                printf("\xcd");
                                                                                                                                                                                                }
                                                                                                                                                                                                printf("\n\n");
                                                                                                                                                                                                printf("[1] JOY TRAVELS\n\n\t\tCHENNAI--> MADURAI--> KODAIKANAL--> OOTY--> MUNNAR--> ALAPPUZHA--> MYSORE--> CHENNAI\n\n");
                                                                                                                                                                                                printf("[2] SIGMA TRAVELS\n\n\t\tCHENNAI--> MYSORE--> GOA--> MUMBAI--> UDHAIPUR--> JODHPUR--> JAISALMER--> JAIPUR--> CHENNAI\n\n");
                                                                                                                                                                                                printf("[3] SKY TRAVELS\n\n\t\tCHENNAI--> HYDERABAD--> VARANASI--> AGRA--> NEW DELHI--> MUMBAI--> CHENNAI\n\n");
                                                                                                                                                                                                printf("[4] JAVA TRAVELS\n\n\t\tCHENNAI--> AURANGABAD--> NEW DELHI--> AMRITSAR--> SRINAGAR--> LADAKH--> MANALI--> SHIMLA--> CHENNAI\n\n");
                                                                                                                                                                                                printf("[5] SWAN TRAVELS\n\n\t\tCHENNAI--> GOA--> MUMBAI--> UDHAIPUR --> JODHPUR--> JAISALMER--> JAIPUR--> AGRA--> VARANASI--> AURANGABD--> HYDERABAD--> CHENNAI\n\n");
                                                                                                                                                                                                getch();
                                                                                                                                                                                                break;
                                                                                                                                                                                }
                                                                                                                                                                                case 2 : //BUS DETAILS
                                                                                                                                                                                {
                                                                                                                                                                                                system("cls");
                                                                                                                                                                                                system("color b0");
                                                                                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                                                                                {
                                                                                                                                                                                                                printf("\xcd");
                                                                                                                                                                                                }
                                                                                                                                                                                                printf("\n");
                                                                                                                                                                                                printf("\t\t\t\t\t\tBUS LIST\n");
                                                                                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                                                                                {
                                                                                                                                                                                                                printf("\xcd");
                                                                                                                                                                                                }
                                                                                                                                                                                                printf("\n\n\t");
                                                                                                                                                                                                printf("[1] JOY TRAVELS\n\t[2] SIGMA TRAVELS\n\t[3] SKY TRAVELS\n\t[4] JAVA TRAVELS\n\t[5] SWAN TRAVELS\n");
                                                                                                                                                                                                printf("\n\tEnter the number of the bus whose's details you want to see : ");
                                                                                                                                                                                                scanf("%d",&busno);
                                                                                                                                                                                                switch(busno)
                                                                                                                                                                                                {
                                                                                                                                                                                                                case 1 : //JOY TRAVELS DETAILS
                                                                                                                                                                                                                {
                                                                                                                                                                                                                                bus_details=fopen("BUS 1 DETAILS.txt","r");
                                                                                                                                                                                                                                system("cls");
                                                                                                                                                                                                                                system("color 3f");
                                                                                                                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("\xcd");
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                printf("\n");
                                                                                                                                                                                                                                printf("\t\t\t\t\t\tBUS DETAILS\n");
                                                                                                                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("\xcd");
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                printf("\n\n");
                                                                                                                                                                                                                                if(bus_details==NULL)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("SORRY COULDN'T DISPLAY THE BUS DETAILS\n");
                                                                                                                                                                                                                                                break;
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                while(!feof(bus_details))//READING THE FILE UNTIL THE FILE POINTER REACHES THE END OF THE FILE
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                b=fgetc(bus_details);
                                                                                                                                                                                                                                                printf("%c",b);
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                fclose(bus_details);
                                                                                                                                                                                                                                getch();
                                                                                                                                                                                                                                break;
                                                                                                                                                                                                                }
                                                                                                                                                                                                                case 2 : //SIGMA TRAVELS DETAILS
                                                                                                                                                                                                                {
                                                                                                                                                                                                                                bus_details=fopen("BUS 2 DETAILS.txt","r");
                                                                                                                                                                                                                                system("cls");
                                                                                                                                                                                                                                system("color 3f");
                                                                                                                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("\xcd");
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                printf("\n");
                                                                                                                                                                                                                                printf("\t\t\t\t\t\tBUS DETAILS\n");
                                                                                                                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("\xcd");
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                printf("\n");
                                                                                                                                                                                                                                if(bus_details==NULL)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("SORRY COULDN'T DISPLAY THE BUS DETAILS\n");
                                                                                                                                                                                                                                                break;
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                while(!feof(bus_details))//READING THE FILE UNTIL THE FILE POINTER REACHES THE END OF THE FILE
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                b=fgetc(bus_details);
                                                                                                                                                                                                                                                printf("%c",b);
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                fclose(bus_details);
                                                                                                                                                                                                                                getch();
                                                                                                                                                                                                                                break;
                                                                                                                                                                                                                }
                                                                                                                                                                                                                case 3 : //SKY TRAVELS DETAILS
                                                                                                                                                                                                                {
                                                                                                                                                                                                                                bus_details=fopen("BUS 3 DETAILS.txt","r");
                                                                                                                                                                                                                                system("cls");
                                                                                                                                                                                                                                system("color 3f");
                                                                                                                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("\xcd");
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                printf("\n");
                                                                                                                                                                                                                                printf("\t\t\t\t\t\tBUS DETAILS\n");
                                                                                                                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("\xcd");
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                printf("\n");
                                                                                                                                                                                                                                if(bus_details==NULL)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("SORRY COULDN'T DISPLAY THE BUS DETAILS\n");
                                                                                                                                                                                                                                                break;
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                while(!feof(bus_details))//READING THE FILE UNTIL THE FILE POINTER REACHES THE END OF THE FILE
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                b=fgetc(bus_details);
                                                                                                                                                                                                                                                printf("%c",b);
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                fclose(bus_details);
                                                                                                                                                                                                                                getch();
                                                                                                                                                                                                                                break;
                                                                                                                                                                                                                }
                                                                                                                                                                                                                case 4 : //JAVA TRAVELS DETAILS
                                                                                                                                                                                                                {
                                                                                                                                                                                                                                bus_details=fopen("BUS 4 DETAILS.txt","r");
                                                                                                                                                                                                                                system("cls");
                                                                                                                                                                                                                                system("color 3f");
                                                                                                                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("\xcd");
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                printf("\n");
                                                                                                                                                                                                                                printf("\t\t\t\t\t\tBUS DETAILS\n");
                                                                                                                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("\xcd");
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                printf("\n");
                                                                                                                                                                                                                                if(bus_details==NULL)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("SORRY COULDN'T DISPLAY THE BUS DETAILS\n");
                                                                                                                                                                                                                                                break;
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                while(!feof(bus_details))//READING THE FILE UNTIL THE FILE POINTER REACHES THE END OF THE FILE
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                b=fgetc(bus_details);
                                                                                                                                                                                                                                                printf("%c",b);
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                fclose(bus_details);
                                                                                                                                                                                                                                getch();
                                                                                                                                                                                                                                break;
                                                                                                                                                                                                                }
                                                                                                                                                                                                                case 5 : //SWAN TRAVELS DETAILS
                                                                                                                                                                                                                {
                                                                                                                                                                                                                                bus_details=fopen("BUS 5 DETAILS.txt","r");
                                                                                                                                                                                                                                system("cls");
                                                                                                                                                                                                                                system("color 3f");
                                                                                                                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("\xcd");
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                printf("\n");
                                                                                                                                                                                                                                printf("\t\t\t\t\t\tBUS DETAILS\n");
                                                                                                                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("\xcd");
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                printf("\n");
                                                                                                                                                                                                                                if(bus_details==NULL)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("SORRY COULDN'T DISPLAY THE BUS DETAILS\n");
                                                                                                                                                                                                                                                break;
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                while(!feof(bus_details))//READING THE FILE UNTIL THE FILE POINTER REACHES THE END OF THE FILE
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                b=fgetc(bus_details);
                                                                                                                                                                                                                                                printf("%c",b);
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                fclose(bus_details);
                                                                                                                                                                                                                                getch();
                                                                                                                                                                                                                                break;
                                                                                                                                                                                                                }
                                                                                                                                                                                                }
                                                                                                                                                                                                break;

                                                                                                                                                                                }
                                                                                                                                                                                case 3 ://BOOK TICKETS
                                                                                                                                                                                {
                                                                                                                                                                                                B1 : system("cls");
                                                                                                                                                                                                system("color 80");
                                                                                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                                                                                {
                                                                                                                                                                                                                printf("\xcd");
                                                                                                                                                                                                }
                                                                                                                                                                                                printf("\n");
                                                                                                                                                                                                printf("\t\t\t\t\t\tBUS LIST\n");
                                                                                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                                                                                {
                                                                                                                                                                                                                printf("\xcd");
                                                                                                                                                                                                }
                                                                                                                                                                                                printf("\n\n\t");
                                                                                                                                                                                                printf("[1] JOY TRAVELS\n\t[2] SIGMA TRAVELS\n\t[3] SKY TRAVELS\n\t[4] JAVA TRAVELS\n\t[5] SWAN TRAVELS\n");
                                                                                                                                                                                                printf("\n\n\tEnter your bus number : ");
                                                                                                                                                                                                scanf("%d",&busno);
                                                                                                                                                                                                switch(busno)
                                                                                                                                                                                                {
                                                                                                                                                                                                                case 1 : //JOY TRAVELS
                                                                                                                                                                                                                {
                                                                                                                                                                                                                                if(checkBusgoes(busno,destination)==0)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("\nThis Bus does not go to that destination.Kindly select the correct bus number \n\n");
                                                                                                                                                                                                                                                goto B1;
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                B2 : printf("\n\n\tEnter the date of travel : ");
                                                                                                                                                                                                                                scanf("%d%d%d",&d,&m,&year);
                                                                                                                                                                                                                                if(checkDate(busno,d)!=1)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("\nPlease check the bus details and enter a date on which the bus is available\n");
                                                                                                                                                                                                                                                goto B2;
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                system("cls");
                                                                                                                                                                                                                                system("color ce");
                                                                                                                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("\xcd");
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                printf("\n");
                                                                                                                                                                                                                                printf("\t\t\t\tJOY TRAVELS\n");
                                                                                                                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("\xcd");
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                printf("\n\n");
                                                                                                                                                                                                                                for(k=1;k<=35;k++)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                if(b1as>0)
                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                int count=0;
                                                                                                                                                                                                                                                                for(l=0;l<b1as;l++)
                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                if(b1booked_seatnos[l]==k)
                                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                                if(k<10)
                                                                                                                                                                                                                                                                                                printf("\t0%d.Booked",k);
                                                                                                                                                                                                                                                                                                else
                                                                                                                                                                                                                                                                                                printf("\t%d.Booked",k);
                                                                                                                                                                                                                                                                                                count=1;
                                                                                                                                                                                                                                                                                }

                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                if(count==0)
                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                if(k<10)
                                                                                                                                                                                                                                                                                printf("\t0%d.Empty",k);
                                                                                                                                                                                                                                                                                else
                                                                                                                                                                                                                                                                                printf("\t%d.Empty",k);
                                                                                                                                                                                                                                                                }

                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                else
                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                if(k<10)
                                                                                                                                                                                                                                                                printf("\t0%d.Empty",k);
                                                                                                                                                                                                                                                                else
                                                                                                                                                                                                                                                                printf("\t%d.Empty",k);
                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                if(k%5==0)
                                                                                                                                                                                                                                                printf("\n");
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                printf("AVAILABLE SEATS : %d\n\n",b1available_seats);
                                                                                                                                                                                                                                printf("ENTER THE NUMBER OF SEATS TO BE BOOKED : ");
                                                                                                                                                                                                                                scanf("%d",&no_ofseats);
                                                                                                                                                                                                                                for(j=1;j<=no_ofseats;j++)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                passenger_details=fopen("BUS 1 PASSENGER DETAILS.txt","a+");
                                                                                                                                                                                                                                                if(passenger_details==NULL)
                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                printf("Sorry couldn't enter your details\n");
                                                                                                                                                                                                                                                                exit(0);
                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                printf("\n\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd Enter the Details for Ticket %d \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n",j);
                                                                                                                                                                                                                                                Z1 : printf("\nEnter the Seat Number to be booked :" );
                                                                                                                                                                                                                                                scanf("%d",&passenger.seatno);
                                                                                                                                                                                                                                                if(checkSeat(b1booked_seatnos,passenger.seatno)==1)//Check if that seat is already booked by someone else
                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                printf("\n\t\tSorry that seat has been booked already.Try booking some other seat\n");
                                                                                                                                                                                                                                                                goto Z1;
                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                b1booked_seatnos[b1as]=passenger.seatno;
                                                                                                                                                                                                                                                b1as++;
                                                                                                                                                                                                                                                printf("\nEnter the Name of the Passenger : ");
                                                                                                                                                                                                                                                scanf("%*c%[^\n]s",&passenger.name);
                                                                                                                                                                                                                                                Z2 : printf("\nEnter the Gender of the Passenger [Note:Press M/m or F/f or T/t] : ");
                                                                                                                                                                                                                                                scanf("%*c%c",&passenger.gender);
                                                                                                                                                                                                                                                printf("\nEnter the Age of the Passenger : ");
                                                                                                                                                                                                                                                scanf("%d",&passenger.age);
                                                                                                                                                                                                                                                passenger.busno=1;
                                                                                                                                                                                                                                                strcpy(passenger.status,"Booked");
                                                                                                                                                                                                                                                strcpy(passenger.destination,destination);
                                                                                                                                                                                                                                                passenger.dd=d;
                                                                                                                                                                                                                                                passenger.mm=m;
                                                                                                                                                                                                                                                passenger.y=year;
                                                                                                                                                                                                                                                fwrite(&passenger,sizeof(bus),1,passenger_details);
                                                                                                                                                                                                                                                if(fwrite!=0)
                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                printf("\nYour Details are Successfully stored\n");
                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                fclose(passenger_details);
                                                                                                                                                                                                                                                getch();
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                cost = 100.00*no_ofseats;
                                                                                                                                                                                                                                system("cls");
                                                                                                                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("\xcd");
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                printf("\n");
                                                                                                                                                                                                                                printf("\n\n PAYMENT PORTAL\n");
                                                                                                                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("\xcd");
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                printf("\n");
                                                                                                                                                                                                                                Z3 : printf("\n\n\n\t\t\tThe total cost of your booking is %f\n\tProceed to pay?  ",cost);
                                                                                                                                                                                                                                scanf("%*c%c",&payment);
                                                                                                                                                                                                                                if(payment=='y'|| payment=='Y')
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("\n\n\t\tPlease make your payment through any platform you are comfortable with : \n\n\t*PAYTM\n\n\t*NET BANKING\n");
                                                                                                                                                                                                                                                printf("\n\n\n\t\tPlease wait for payment confirmation from our side. ");
                                                                                                                                                                                                                                                scanf("%*c%c",&ch);
                                                                                                                                                                                                                                                if(ch=='p'||ch=='P')
                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                printf("\n\n\t\t\t\t\t\tPayment Succesful\n");
                                                                                                                                                                                                                                                                printf("YOUR SEAT HAS BEEN BOOKED.THANK YOU FOR BOOKING\n");
                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                else
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("Please make payment to confirm your seat.\n");
                                                                                                                                                                                                                                                goto Z3;
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                b1available_seats=b1available_seats-no_ofseats;
                                                                                                                                                                                                                                getch();
                                                                                                                                                                                                                                break;
                                                                                                                                                                                                                }
                                                                                                                                                                                                                case 2 : //SIGMA TRAVELS
                                                                                                                                                                                                                {
                                                                                                                                                                                                                                if(checkBusgoes(busno,destination)==0)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("\nThis Bus does not go to that destination.Kindly select the correct bus number \n\n");
                                                                                                                                                                                                                                                goto B1;
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                B3 : printf("Enter the date of travel : ");
                                                                                                                                                                                                                                scanf("%d%d%d",&d,&m,&year);
                                                                                                                                                                                                                                if(checkDate(busno,d)!=1)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("\nPlease check the bus details and enter a date on which the bus is available\n");
                                                                                                                                                                                                                                                goto B3;
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                system("cls");
                                                                                                                                                                                                                                system("color ce");
                                                                                                                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("\xcd");
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                printf("\n");
                                                                                                                                                                                                                                printf("\t\t\t\tSIGMA TRAVELS\n");
                                                                                                                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("\xcd");
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                printf("\n");
                                                                                                                                                                                                                                for(k=1;k<=35;k++)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                if(b2as>0)
                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                int count=0;
                                                                                                                                                                                                                                                                for(l=0;l<b2as;l++)
                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                if(b2booked_seatnos[l]==k)
                                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                                if(k<10)
                                                                                                                                                                                                                                                                                                printf("\t0%d.Booked",k);
                                                                                                                                                                                                                                                                                                else
                                                                                                                                                                                                                                                                                                printf("\t%d.Booked",k);
                                                                                                                                                                                                                                                                                                count=1;
                                                                                                                                                                                                                                                                                }

                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                if(count==0)
                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                if(k<10)
                                                                                                                                                                                                                                                                                printf("\t0%d.Empty",k);
                                                                                                                                                                                                                                                                                else
                                                                                                                                                                                                                                                                                printf("\t%d.Empty",k);
                                                                                                                                                                                                                                                                }

                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                else
                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                if(k<10)
                                                                                                                                                                                                                                                                printf("\t0%d.Empty",k);
                                                                                                                                                                                                                                                                else
                                                                                                                                                                                                                                                                printf("\t%d.Empty",k);
                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                if(k%5==0)
                                                                                                                                                                                                                                                printf("\n");
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                printf("AVAILABLE SEATS : %d\n\n",b2available_seats);
                                                                                                                                                                                                                                printf("ENTER THE NUMBER OF SEATS TO BE BOOKED : ");
                                                                                                                                                                                                                                scanf("%d",&no_ofseats);
                                                                                                                                                                                                                                for(j=1;j<=no_ofseats;j++)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                passenger_details=fopen("BUS 2 PASSENGER DETAILS.txt","a+");
                                                                                                                                                                                                                                                if(passenger_details==NULL)
                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                printf("Sorry couldn't enter your details\n");
                                                                                                                                                                                                                                                                exit(0);
                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                printf("\n\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd Enter the Details for Ticket %d \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n",j);
                                                                                                                                                                                                                                                Z4 : printf("\nEnter the Seat Number to be booked :" );
                                                                                                                                                                                                                                                scanf("%d",&passenger.seatno);
                                                                                                                                                                                                                                                if(checkSeat(b2booked_seatnos,passenger.seatno)==1)//Check if that seat is already booked by someone else
                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                printf("\n\t\tSorry that seat has been booked already.Try booking some other seat\n");
                                                                                                                                                                                                                                                                goto Z4;
                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                b2booked_seatnos[b2as]=passenger.seatno;
                                                                                                                                                                                                                                                b2as++;
                                                                                                                                                                                                                                                printf("\nEnter the Name of the Passenger : ");
                                                                                                                                                                                                                                                scanf("%*c%[^\n]s",&passenger.name);
                                                                                                                                                                                                                                                Z5 : printf("\nEnter the Gender of the Passenger [Note:Press M/m or F/f or T/t] : ");
                                                                                                                                                                                                                                                scanf("%*c%c",&passenger.gender);
                                                                                                                                                                                                                                                printf("\nEnter the Age of the Passenger : ");
                                                                                                                                                                                                                                                scanf("%d",&passenger.age);
                                                                                                                                                                                                                                                passenger.busno=2;
                                                                                                                                                                                                                                                strcpy(passenger.status,"Booked");
                                                                                                                                                                                                                                                strcpy(passenger.destination,destination);
                                                                                                                                                                                                                                                passenger.dd=d;
                                                                                                                                                                                                                                                passenger.mm=m;
                                                                                                                                                                                                                                                passenger.y=year;
                                                                                                                                                                                                                                                fwrite(&passenger,sizeof(bus),1,passenger_details);
                                                                                                                                                                                                                                                if(fwrite!=0)
                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                printf("\nYour Details are Successfully stored\n");
                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                fclose(passenger_details);
                                                                                                                                                                                                                                                getch();
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                cost = 100.00*no_ofseats;
                                                                                                                                                                                                                                system("cls");
                                                                                                                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("\xcd");
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                printf("\n");
                                                                                                                                                                                                                                printf("\n\n PAYMENT PORTAL\n");
                                                                                                                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("\xcd");
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                printf("\n");
                                                                                                                                                                                                                                Z6 : printf("\n\n\n\t\t\tThe total cost of your booking is %f\n\tProceed to pay?  ",cost);
                                                                                                                                                                                                                                scanf("%*c%c",&payment);
                                                                                                                                                                                                                                if(payment=='y'|| payment=='Y')
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("\n\n\t\tPlease make your payment through any platform you are comfortable with : \n\n\t*PAYTM\n\n\t*NET BANKING\n");
                                                                                                                                                                                                                                                printf("\n\n\n\t\tPlease wait for payment confirmation from our side.");
                                                                                                                                                                                                                                                scanf("%*c%c",&ch);
                                                                                                                                                                                                                                                if(ch=='p'||ch=='P')
                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                printf("\n\n\t\t\t\t\t\tPayment Succesful\n");
                                                                                                                                                                                                                                                                printf("YOUR SEAT HAS BEEN BOOKED.THANK YOU FOR BOOKING\n");
                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                else
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("Please make payment to confirm your seat.\n");
                                                                                                                                                                                                                                                goto Z6;
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                b2available_seats=b2available_seats-no_ofseats;
                                                                                                                                                                                                                                getch();
                                                                                                                                                                                                                                break;
                                                                                                                                                                                                                }
                                                                                                                                                                                                                case 3 : //SKY TRAVELS
                                                                                                                                                                                                                {
                                                                                                                                                                                                                                if(checkBusgoes(busno,destination)==0)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("\nThis Bus does not go to that destination.Kindly select the correct bus number \n\n");
                                                                                                                                                                                                                                                goto B1;
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                B4 : printf("Enter the date of travel : ");
                                                                                                                                                                                                                                scanf("%d%d%d",&d,&m,&year);
                                                                                                                                                                                                                                if(checkDate(busno,d)!=1)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("\nPlease check the bus details and enter a date on which the bus is available\n");
                                                                                                                                                                                                                                                goto B4;
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                system("cls");
                                                                                                                                                                                                                                system("color ce");
                                                                                                                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("\xcd");
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                printf("\n");
                                                                                                                                                                                                                                printf("\t\t\t\tSKY TRAVELS\n");
                                                                                                                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("\xcd");
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                printf("\n");
                                                                                                                                                                                                                                for(k=1;k<=35;k++)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                if(b3as>0)
                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                int count=0;
                                                                                                                                                                                                                                                                for(l=0;l<b3as;l++)
                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                if(b3booked_seatnos[l]==k)
                                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                                if(k<10)
                                                                                                                                                                                                                                                                                                printf("\t0%d.Booked",k);
                                                                                                                                                                                                                                                                                                else
                                                                                                                                                                                                                                                                                                printf("\t%d.Booked",k);
                                                                                                                                                                                                                                                                                                count=1;
                                                                                                                                                                                                                                                                                }

                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                if(count==0)
                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                if(k<10)
                                                                                                                                                                                                                                                                                printf("\t0%d.Empty",k);
                                                                                                                                                                                                                                                                                else
                                                                                                                                                                                                                                                                                printf("\t%d.Empty",k);
                                                                                                                                                                                                                                                                }

                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                else
                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                if(k<10)
                                                                                                                                                                                                                                                                printf("\t0%d.Empty",k);
                                                                                                                                                                                                                                                                else
                                                                                                                                                                                                                                                                printf("\t%d.Empty",k);
                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                if(k%5==0)
                                                                                                                                                                                                                                                printf("\n");
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                printf("AVAILABLE SEATS : %d\n\n",b3available_seats);
                                                                                                                                                                                                                                printf("ENTER THE NUMBER OF SEATS TO BE BOOKED : ");
                                                                                                                                                                                                                                scanf("%d",&no_ofseats);
                                                                                                                                                                                                                                for(j=1;j<=no_ofseats;j++)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                passenger_details=fopen("BUS 3 PASSENGER DETAILS.txt","a+");
                                                                                                                                                                                                                                                if(passenger_details==NULL)
                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                printf("Sorry couldn't enter your details\n");
                                                                                                                                                                                                                                                                exit(0);
                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                printf("\n\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd Enter the Details for Ticket %d \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n",j);
                                                                                                                                                                                                                                                Z7 : printf("\nEnter the Seat Number to be booked :" );
                                                                                                                                                                                                                                                scanf("%d",&passenger.seatno);
                                                                                                                                                                                                                                                if(checkSeat(b3booked_seatnos,passenger.seatno)==1)//Check if that seat is already booked by someone else
                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                printf("\n\t\tSorry that seat has been booked already.Try booking some other seat\n");
                                                                                                                                                                                                                                                                goto Z7;
                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                b3booked_seatnos[b3as]=passenger.seatno;
                                                                                                                                                                                                                                                b3as++;
                                                                                                                                                                                                                                                printf("\nEnter the Name of the Passenger : ");
                                                                                                                                                                                                                                                scanf("%*c%[^\n]s",&passenger.name);
                                                                                                                                                                                                                                                Z8 : printf("\nEnter the Gender of the Passenger [Note:Press M/m or F/f or T/t] : ");
                                                                                                                                                                                                                                                scanf("%*c%c",&passenger.gender);
                                                                                                                                                                                                                                                printf("\nEnter the Age of the Passenger : ");
                                                                                                                                                                                                                                                scanf("%d",&passenger.age);
                                                                                                                                                                                                                                                passenger.busno=3;
                                                                                                                                                                                                                                                strcpy(passenger.status,"Booked");
                                                                                                                                                                                                                                                strcpy(passenger.destination,destination);
                                                                                                                                                                                                                                                passenger.dd=d;
                                                                                                                                                                                                                                                passenger.mm=m;
                                                                                                                                                                                                                                                passenger.y=year;
                                                                                                                                                                                                                                                fwrite(&passenger,sizeof(bus),1,passenger_details);
                                                                                                                                                                                                                                                if(fwrite!=0)
                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                printf("\nYour Details are Successfully stored\n");
                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                fclose(passenger_details);
                                                                                                                                                                                                                                                getch();
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                cost = 100.00*no_ofseats;
                                                                                                                                                                                                                                system("cls");
                                                                                                                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("\xcd");
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                printf("\n");
                                                                                                                                                                                                                                printf("\n\n PAYMENT PORTAL\n");
                                                                                                                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("\xcd");
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                printf("\n");
                                                                                                                                                                                                                                Z9 : printf("\n\n\n\t\t\tThe total cost of your booking is %f\n\tProceed to pay?  ",cost);
                                                                                                                                                                                                                                scanf("%*c%c",&payment);
                                                                                                                                                                                                                                if(payment=='y'|| payment=='Y')
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("\n\n\t\tPlease make your payment through any platform you are comfortable with : \n\n\t*PAYTM\n\n\t*NET BANKING\n");
                                                                                                                                                                                                                                                printf("\n\n\n\t\tPlease wait for payment confirmation from our side.");
                                                                                                                                                                                                                                                scanf("%*c%c",&ch);
                                                                                                                                                                                                                                                if(ch=='p'||ch=='P')
                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                printf("\n\n\t\t\t\t\t\tPayment Succesful\n");
                                                                                                                                                                                                                                                                printf("YOUR SEAT HAS BEEN BOOKED.THANK YOU FOR BOOKING\n");
                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                else
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("Please make payment to confirm your seat.\n");
                                                                                                                                                                                                                                                goto Z9;
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                b3available_seats=b3available_seats-no_ofseats;
                                                                                                                                                                                                                                getch();
                                                                                                                                                                                                                                break;
                                                                                                                                                                                                                }
                                                                                                                                                                                                                case 4 : //JAVA TRAVELS
                                                                                                                                                                                                                {
                                                                                                                                                                                                                                if(checkBusgoes(busno,destination)==0)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("\nThis Bus does not go to that destination.Kindly select the correct bus number \n\n");
                                                                                                                                                                                                                                                goto B1;
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                B5 : printf("Enter the date of travel : ");
                                                                                                                                                                                                                                scanf("%d%d%d",&d,&m,&year);
                                                                                                                                                                                                                                if(checkDate(busno,d)!=1)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("\nPlease check the bus details and enter a date on which the bus is available\n");
                                                                                                                                                                                                                                                goto B5;
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                system("cls");
                                                                                                                                                                                                                                system("color ce");
                                                                                                                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("\xcd");
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                printf("\n");
                                                                                                                                                                                                                                printf("\t\t\t\tJAVA TRAVELS\n");
                                                                                                                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("\xcd");
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                printf("\n");
                                                                                                                                                                                                                                for(k=1;k<=35;k++)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                if(b4as>0)
                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                int count=0;
                                                                                                                                                                                                                                                                for(l=0;l<b4as;l++)
                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                if(b4booked_seatnos[l]==k)
                                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                                if(k<10)
                                                                                                                                                                                                                                                                                                printf("\t0%d.Booked",k);
                                                                                                                                                                                                                                                                                                else
                                                                                                                                                                                                                                                                                                printf("\t%d.Booked",k);
                                                                                                                                                                                                                                                                                                count=1;
                                                                                                                                                                                                                                                                                }

                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                if(count==0)
                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                if(k<10)
                                                                                                                                                                                                                                                                                printf("\t0%d.Empty",k);
                                                                                                                                                                                                                                                                                else
                                                                                                                                                                                                                                                                                printf("\t%d.Empty",k);
                                                                                                                                                                                                                                                                }

                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                else
                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                if(k<10)
                                                                                                                                                                                                                                                                printf("\t0%d.Empty",k);
                                                                                                                                                                                                                                                                else
                                                                                                                                                                                                                                                                printf("\t%d.Empty",k);
                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                if(k%5==0)
                                                                                                                                                                                                                                                printf("\n");
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                printf("AVAILABLE SEATS : %d\n\n",b4available_seats);
                                                                                                                                                                                                                                printf("ENTER THE NUMBER OF SEATS TO BE BOOKED : ");
                                                                                                                                                                                                                                scanf("%d",&no_ofseats);
                                                                                                                                                                                                                                for(j=1;j<=no_ofseats;j++)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                passenger_details=fopen("BUS 4 PASSENGER DETAILS.txt","a+");
                                                                                                                                                                                                                                                if(passenger_details==NULL)
                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                printf("Sorry couldn't enter your details\n");
                                                                                                                                                                                                                                                                exit(0);
                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                printf("\n\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd Enter the Details for Ticket %d \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n",j);
                                                                                                                                                                                                                                                Z10 : printf("\nEnter the Seat Number to be booked :" );
                                                                                                                                                                                                                                                scanf("%d",&passenger.seatno);
                                                                                                                                                                                                                                                if(checkSeat(b4booked_seatnos,passenger.seatno)==1)//Check if that seat is already booked by someone else
                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                printf("\n\t\tSorry that seat has been booked already.Try booking some other seat\n");
                                                                                                                                                                                                                                                                goto Z10;
                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                b4booked_seatnos[b4as]=passenger.seatno;
                                                                                                                                                                                                                                                b4as++;
                                                                                                                                                                                                                                                printf("\nEnter the Name of the Passenger : ");
                                                                                                                                                                                                                                                scanf("%*c%[^\n]s",&passenger.name);
                                                                                                                                                                                                                                                Z11 : printf("\nEnter the Gender of the Passenger [Note:Press M/m or F/f or T/t] : ");
                                                                                                                                                                                                                                                scanf("%*c%c",&passenger.gender);
                                                                                                                                                                                                                                                printf("\nEnter the Age of the Passenger : ");
                                                                                                                                                                                                                                                scanf("%d",&passenger.age);
                                                                                                                                                                                                                                                passenger.busno=4;
                                                                                                                                                                                                                                                strcpy(passenger.status,"Booked");
                                                                                                                                                                                                                                                strcpy(passenger.destination,destination);
                                                                                                                                                                                                                                                passenger.dd=d;
                                                                                                                                                                                                                                                passenger.mm=m;
                                                                                                                                                                                                                                                passenger.y=year;
                                                                                                                                                                                                                                                fwrite(&passenger,sizeof(bus),1,passenger_details);
                                                                                                                                                                                                                                                if(fwrite!=0)
                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                printf("\nYour Details are Successfully stored\n");
                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                fclose(passenger_details);
                                                                                                                                                                                                                                                getch();
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                cost = 100.00*no_ofseats;
                                                                                                                                                                                                                                system("cls");
                                                                                                                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("\xcd");
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                printf("\n");
                                                                                                                                                                                                                                printf("\n\n PAYMENT PORTAL\n");
                                                                                                                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("\xcd");
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                printf("\n");
                                                                                                                                                                                                                                Z12 : printf("\n\n\n\t\t\tThe total cost of your booking is %f\n\tProceed to pay?  ",cost);
                                                                                                                                                                                                                                scanf("%*c%c",&payment);
                                                                                                                                                                                                                                if(payment=='y'|| payment=='Y')
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("\n\n\t\tPlease make your payment through any platform you are comfortable with : \n\n\t*PAYTM\n\n\t*NET BANKING\n");
                                                                                                                                                                                                                                                printf("\n\n\n\t\tPlease wait for payment confirmation from our side.");
                                                                                                                                                                                                                                                scanf("%*c%c",&ch);
                                                                                                                                                                                                                                                if(ch=='p'||ch=='P')
                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                printf("\n\n\t\t\t\t\t\tPayment Succesful\n");
                                                                                                                                                                                                                                                                printf("YOUR SEAT HAS BEEN BOOKED.THANK YOU FOR BOOKING\n");
                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                else
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("Please make payment to confirm your seat.\n");
                                                                                                                                                                                                                                                goto Z12;
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                b4available_seats=b4available_seats-no_ofseats;
                                                                                                                                                                                                                                getch();
                                                                                                                                                                                                                                break;
                                                                                                                                                                                                                }
                                                                                                                                                                                                                case 5 : //SWAN TRAVELS
                                                                                                                                                                                                                {
                                                                                                                                                                                                                                if(checkBusgoes(busno,destination)==0)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("\nThis Bus does not go to that destination.Kindly select the correct bus number \n\n");
                                                                                                                                                                                                                                                goto B1;
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                B6 : printf("Enter the date of travel : ");
                                                                                                                                                                                                                                scanf("%d%d%d",&d,&m,&year);
                                                                                                                                                                                                                                if(checkDate(busno,d)!=1)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("\nPlease check the bus details and enter a date on which the bus is available\n");
                                                                                                                                                                                                                                                goto B6;
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                system("cls");
                                                                                                                                                                                                                                system("color ce");
                                                                                                                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("\xcd");
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                printf("\n");
                                                                                                                                                                                                                                printf("\t\t\t\tSWAN TRAVELS\n");
                                                                                                                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("\xcd");
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                printf("\n");
                                                                                                                                                                                                                                for(k=1;k<=35;k++)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                if(b5as>0)
                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                int count=0;
                                                                                                                                                                                                                                                                for(l=0;l<b5as;l++)
                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                if(b5booked_seatnos[l]==k)
                                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                                if(k<10)
                                                                                                                                                                                                                                                                                                printf("\t0%d.Booked",k);
                                                                                                                                                                                                                                                                                                else
                                                                                                                                                                                                                                                                                                printf("\t%d.Booked",k);
                                                                                                                                                                                                                                                                                                count=1;
                                                                                                                                                                                                                                                                                }

                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                if(count==0)
                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                if(k<10)
                                                                                                                                                                                                                                                                                printf("\t0%d.Empty",k);
                                                                                                                                                                                                                                                                                else
                                                                                                                                                                                                                                                                                printf("\t%d.Empty",k);
                                                                                                                                                                                                                                                                }

                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                else
                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                if(k<10)
                                                                                                                                                                                                                                                                printf("\t0%d.Empty",k);
                                                                                                                                                                                                                                                                else
                                                                                                                                                                                                                                                                printf("\t%d.Empty",k);
                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                if(k%5==0)
                                                                                                                                                                                                                                                printf("\n");
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                printf("AVAILABLE SEATS : %d\n\n",b5available_seats);
                                                                                                                                                                                                                                printf("ENTER THE NUMBER OF SEATS TO BE BOOKED : ");
                                                                                                                                                                                                                                scanf("%d",&no_ofseats);
                                                                                                                                                                                                                                for(j=1;j<=no_ofseats;j++)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                passenger_details=fopen("BUS 5 PASSENGER DETAILS.txt","a+");
                                                                                                                                                                                                                                                if(passenger_details==NULL)
                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                printf("Sorry couldn't enter your details\n");
                                                                                                                                                                                                                                                                exit(0);
                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                printf("\n\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd Enter the Details for Ticket %d \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n",j);
                                                                                                                                                                                                                                                Z13 : printf("\nEnter the Seat Number to be booked :" );
                                                                                                                                                                                                                                                scanf("%d",&passenger.seatno);
                                                                                                                                                                                                                                                if(checkSeat(b5booked_seatnos,passenger.seatno)==1)//Check if that seat is already booked by someone else
                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                printf("\n\t\tSorry that seat has been booked already.Try booking some other seat\n");
                                                                                                                                                                                                                                                                goto Z13;
                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                b5booked_seatnos[b5as]=passenger.seatno;
                                                                                                                                                                                                                                                b5as++;
                                                                                                                                                                                                                                                printf("\nEnter the Name of the Passenger : ");
                                                                                                                                                                                                                                                scanf("%*c%[^\n]s",&passenger.name);
                                                                                                                                                                                                                                                Z14 : printf("\nEnter the Gender of the Passenger [Note:Press M/m or F/f or T/t] : ");
                                                                                                                                                                                                                                                scanf("%*c%c",&passenger.gender);
                                                                                                                                                                                                                                                printf("\nEnter the Age of the Passenger : ");
                                                                                                                                                                                                                                                scanf("%d",&passenger.age);
                                                                                                                                                                                                                                                passenger.busno=5;
                                                                                                                                                                                                                                                strcpy(passenger.status,"Booked");
                                                                                                                                                                                                                                                strcpy(passenger.destination,destination);
                                                                                                                                                                                                                                                passenger.dd=d;
                                                                                                                                                                                                                                                passenger.mm=m;
                                                                                                                                                                                                                                                passenger.y=year;
                                                                                                                                                                                                                                                fwrite(&passenger,sizeof(bus),1,passenger_details);
                                                                                                                                                                                                                                                if(fwrite!=0)
                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                printf("\nYour Details are Successfully stored\n");
                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                fclose(passenger_details);
                                                                                                                                                                                                                                                getch();
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                cost = 100.00*no_ofseats;
                                                                                                                                                                                                                                system("cls");
                                                                                                                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("\xcd");
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                printf("\n");
                                                                                                                                                                                                                                printf("\n\n PAYMENT PORTAL\n");
                                                                                                                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("\xcd");
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                printf("\n");
                                                                                                                                                                                                                                Z15 : printf("\n\n\n\t\t\tThe total cost of your booking is %f\n\tProceed to pay?  ",cost);
                                                                                                                                                                                                                                scanf("%*c%c",&payment);
                                                                                                                                                                                                                                if(payment=='y'|| payment=='Y')
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("\n\n\t\tPlease make your payment through any platform you are comfortable with : \n\n\t*PAYTM\n\n\t*NET BANKING\n");
                                                                                                                                                                                                                                                printf("\n\n\n\t\tPlease wait for payment confirmation from our side.");
                                                                                                                                                                                                                                                scanf("%*c%c",&ch);
                                                                                                                                                                                                                                                if(ch=='p'||ch=='P')
                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                printf("\n\n\t\t\t\t\t\tPayment Succesful\n");
                                                                                                                                                                                                                                                                printf("YOUR SEAT HAS BEEN BOOKED.THANK YOU FOR BOOKING\n");
                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                else
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("Please make payment to confirm your seat.\n");
                                                                                                                                                                                                                                                goto Z15;
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                b5available_seats=b5available_seats-no_ofseats;
                                                                                                                                                                                                                                getch();
                                                                                                                                                                                                                                break;
                                                                                                                                                                                                                }

                                                                                                                                                                                                }
                                                                                                                                                                                                break;
                                                                                                                                                                                }
                                                                                                                                                                                case 4 ://CANCEL BOOKING
                                                                                                                                                                                {
                                                                                                                                                                                                printf("Enter the number of the bus : ");
                                                                                                                                                                                                scanf("%d",&busno);
                                                                                                                                                                                                printf("Enter the seat number you want to delete : ");
                                                                                                                                                                                                scanf("%d",&seatnumber);
                                                                                                                                                                                                switch(busno)
                                                                                                                                                                                                {
                                                                                                                                                                                                                case 1 ://CANCEL BUS 1 TICKETS
                                                                                                                                                                                                                {
                                                                                                                                                                                                                                cancel(busno);
                                                                                                                                                                                                                                deleteArrayElement(b1booked_seatnos,b1as,seatnumber,b1available_seats);
                                                                                                                                                                                                                                getch();
                                                                                                                                                                                                                                break;
                                                                                                                                                                                                                }
                                                                                                                                                                                                                case 2 ://CANCEL BUS 2 TICKETS
                                                                                                                                                                                                                {
                                                                                                                                                                                                                                cancel(busno);
                                                                                                                                                                                                                                deleteArrayElement(b2booked_seatnos,b2as,seatnumber,b2available_seats);
                                                                                                                                                                                                                                getch();
                                                                                                                                                                                                                                break;
                                                                                                                                                                                                                }
                                                                                                                                                                                                                case 3 ://CANCEL BUS 3 TICKETS
                                                                                                                                                                                                                {
                                                                                                                                                                                                                                cancel(busno);
                                                                                                                                                                                                                                deleteArrayElement(b3booked_seatnos,b3as,seatnumber,b3available_seats);
                                                                                                                                                                                                                                getch();
                                                                                                                                                                                                                                break;
                                                                                                                                                                                                                }
                                                                                                                                                                                                                case 4 ://CANCEL BUS 4 TICKETS
                                                                                                                                                                                                                {
                                                                                                                                                                                                                                cancel(busno);
                                                                                                                                                                                                                                deleteArrayElement(b4booked_seatnos,b4as,seatnumber,b4available_seats);
                                                                                                                                                                                                                                getch();
                                                                                                                                                                                                                                break;
                                                                                                                                                                                                                }
                                                                                                                                                                                                                case 5 ://CANCEL BUS 5 TICKETS
                                                                                                                                                                                                                {
                                                                                                                                                                                                                                cancel(busno);
                                                                                                                                                                                                                                deleteArrayElement(b5booked_seatnos,b5as,seatnumber,b5available_seats);
                                                                                                                                                                                                                                getch();
                                                                                                                                                                                                                                break;
                                                                                                                                                                                                                }
                                                                                                                                                                                                }
                                                                                                                                                                                                break;
                                                                                                                                                                                }
                                                                                                                                                                                case 5 ://VIEW PASSENGER DETAILS
                                                                                                                                                                                {
                                                                                                                                                                                                display();
                                                                                                                                                                                                getch();
                                                                                                                                                                                                break;
                                                                                                                                                                                }
                                                                                                                                                                                case 6 ://EXIT
                                                                                                                                                                                {
                                                                                                                                                                                                goto M0;
                                                                                                                                                                                }

                                                                                                                                                                }
                                                                                                                                                                goto B0;
                                                                                                                                                }
                                                                                                                                                case 2 ://FLIGHT TICKET BOOKING PORTAL
                                                                                                                                                {
                                                                                                                                                                F0 : system("cls");
                                                                                                                                                                system("color 71");
                                                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                                                {
                                                                                                                                                                                printf("\xcd");
                                                                                                                                                                }
                                                                                                                                                                printf("\n");
                                                                                                                                                                printf("\t\t\tWELCOME TO FLIGHT TICKET BOOKING PORTAL\n");
                                                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                                                {
                                                                                                                                                                printf("\xcd");
                                                                                                                                                                }
                                                                                                                                                                printf("\n");
                                                                                                                                                                printf("\t\t\tMAIN MENU\n");
                                                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                                                {
                                                                                                                                                                                printf("\xcd");
                                                                                                                                                                }
                                                                                                                                                                printf("\n");
                                                                                                                                                                printf("[1]AIRPLANE DETAILS\n[2]BOOK TICKETS\n[3]CANCEL BOOKING\n[4]VIEW PASSENGER DETAILS\n[5]EXIT\n\n\t\tEnter your choice : ");
                                                                                                                                                                scanf("%d",&fopt);
                                                                                                                                                                switch(fopt)
                                                                                                                                                                {
                                                                                                                                                                                case 1 ://FLIGHT DETAILS
                                                                                                                                                                                {
                                                                                                                                                                                                flightDetails(destination,flight_details);
                                                                                                                                                                                                getch();
                                                                                                                                                                                                break;
                                                                                                                                                                                }
                                                                                                                                                                                case 2 ://BOOK TICKETS
                                                                                                                                                                                {
                                                                                                                                                                                                system("cls");
                                                                                                                                                                                                system("color ec");
                                                                                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                                                                                {
                                                                                                                                                                                                                printf("\xcd");
                                                                                                                                                                                                }
                                                                                                                                                                                                printf("\n");
                                                                                                                                                                                                printf("\t\t\t\t\t\t WELCOME TO FLIGHT TICKET BOOKING PORTAL\n");
                                                                                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                                                                                {
                                                                                                                                                                                                                printf("\xcd");
                                                                                                                                                                                                }
                                                                                                                                                                                                printf("\n");
                                                                                                                                                                                                genFlightName(destination,flightname2);
                                                                                                                                                                                                printf("Enter the date of travel : ");
                                                                                                                                                                                                scanf("%d %d %d",&date,&month,&y);
                                                                                                                                                                                                if(flightDate(destination,date)!=0)
                                                                                                                                                                                                {
                                                                                                                                                                                                                printf("The flight is not available on that date.Please check the flight details and enter the correct date to proceed with your booking.\n");
                                                                                                                                                                                                                goto F0;
                                                                                                                                                                                                }
                                                                                                                                                                                                seat_reader=fopen("FLIGHT GENERAL DETAILS.txt","a+");
                                                                                                                                                                                                if(seat_reader==NULL)
                                                                                                                                                                                                {
                                                                                                                                                                                                                printf("Couldn't open the file\n");
                                                                                                                                                                                                                getch();
                                                                                                                                                                                                                exit(0);
                                                                                                                                                                                                }
                                                                                                                                                                                                while(fread(&jet,sizeof(seat_allocation),1,seat_reader))
                                                                                                                                                                                                {
                                                                                                                                                                                                                if(!strcmp(jet.destination,destination))
                                                                                                                                                                                                                {
                                                                                                                                                                                                                                if(jet.date == date)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                for(p=0;p<6;p++)
                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                int count=0;
                                                                                                                                                                                                                                                                for(q=0;q<jet.fbsnasize;q++)
                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                               if(jet.fbsn[q]==p+1)
                                                                                                                                                                                                                                                                               {
                                                                                                                                                                                                                                                                                               printf("%d.Booked\t\t",p+1);
                                                                                                                                                                                                                                                                                               count =1;
                                                                                                                                                                                                                                                                               }
                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                if(count==0)
                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                printf("%d.Empty\t\t",p+1);
                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                if(p%3==2)
                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                printf("\n\n");
                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                printf("\n AVAILABLE SEATS = %d\n",jet.fnosa);
                                                                                                                                                                                                                                                flightfound=1;
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                }
                                                                                                                                                                                                }
                                                                                                                                                                                                if(flightfound!=1)
                                                                                                                                                                                                {
                                                                                                                                                                                                                for(p=0;p<6;p++)
                                                                                                                                                                                                                {
                                                                                                                                                                                                                                printf("%d.Empty\t\t",p+1);
                                                                                                                                                                                                                                if(p%3==2)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("\n\n");
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                }
                                                                                                                                                                                                                printf("\nAVAILABLE SEATS = 6\n");
                                                                                                                                                                                                }
                                                                                                                                                                                                fclose(seat_reader);
                                                                                                                                                                                                printf("Enter the number of tickets you want to book : ");
                                                                                                                                                                                                scanf("%d",&no_ofseats);
                                                                                                                                                                                                for(r=0;r<no_ofseats;r++)
                                                                                                                                                                                                {
                                                                                                                                                                                                                printf("\n==========================Enter the details of the ticket %d=================\n",r+1);
                                                                                                                                                                                                                strcpy(customer.flightname,flightname2);
                                                                                                                                                                                                                customer.dd=date;
                                                                                                                                                                                                                customer.mm=month;
                                                                                                                                                                                                                customer.yyyy=y;
                                                                                                                                                                                                                strcpy(customer.destination,destination);
                                                                                                                                                                                                                customer_details=fopen("FLIGHT PASSENGER DETAILS.txt","a+");
                                                                                                                                                                                                                if(customer_details==NULL)
                                                                                                                                                                                                                {
                                                                                                                                                                                                                                printf("Couldn't open the file\n");
                                                                                                                                                                                                                                exit(0);
                                                                                                                                                                                                                }
                                                                                                                                                                                                                F1 : printf("Enter the seat number to be booked : ");
                                                                                                                                                                                                                scanf("%d",&customer.seatno);
                                                                                                                                                                                                                //HAVE TO CHECK IF THE SEAT HAS ALREADY BEEN BOOKED
                                                                                                                                                                                                                printf("Enter the name under which the seat is to be booked : ");
                                                                                                                                                                                                                scanf("%*c%[^\n]s",customer.name);
                                                                                                                                                                                                                printf("Enter your gender : ");
                                                                                                                                                                                                                scanf("%*c%c",&customer.gender);
                                                                                                                                                                                                                printf("Enter the age of the passenger : ");
                                                                                                                                                                                                                scanf("%d",&customer.age);
                                                                                                                                                                                                                fwrite(&customer,sizeof(flight),1,customer_details);
                                                                                                                                                                                                                if(fwrite!=0)
                                                                                                                                                                                                                {
                                                                                                                                                                                                                                printf("\n\nYour details are succesfully stored\n");
                                                                                                                                                                                                                }
                                                                                                                                                                                                                fclose(customer_details);
                                                                                                                                                                                                                seat_reader=fopen("FLIGHT GENERAL DETAILS.txt","a+");
                                                                                                                                                                                                                if(seat_reader==NULL)
                                                                                                                                                                                                                {
                                                                                                                                                                                                                                printf("Couldn't open the file\n");
                                                                                                                                                                                                                                exit(0);
                                                                                                                                                                                                                }
                                                                                                                                                                                                                temp=fopen("TEMP2.txt","w");
                                                                                                                                                                                                                if(temp==NULL)
                                                                                                                                                                                                                {
                                                                                                                                                                                                                                printf("Couldn't open the file\n");
                                                                                                                                                                                                                                exit(0);
                                                                                                                                                                                                                }
                                                                                                                                                                                                                while(fread(&jet,sizeof(seat_allocation),1,seat_reader))
                                                                                                                                                                                                                {
                                                                                                                                                                                                                                if(!strcmp(jet.destination,customer.destination))
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                if(jet.date==customer.dd)
                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                flag2=1;
                                                                                                                                                                                                                                                                temp2=fopen("TEMP3.txt","w");
                                                                                                                                                                                                                                                                fwrite(&jet,sizeof(seat_allocation),1,temp2);
                                                                                                                                                                                                                                                                fclose(temp2);
                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                else
                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                flag3=1;
                                                                                                                                                                                                                                                                fwrite(&jet,sizeof(seat_allocation),1,temp);
                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                else
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                flag3=1;
                                                                                                                                                                                                                                                fwrite(&jet,sizeof(seat_allocation),1,temp);
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                }
                                                                                                                                                                                                                fclose(temp);
                                                                                                                                                                                                                fclose(seat_reader);
                                                                                                                                                                                                                if(flag3==1)
                                                                                                                                                                                                                {
                                                                                                                                                                                                                                temp = fopen("TEMP2.txt","r");
                                                                                                                                                                                                                                seat_reader = fopen("FLIGHT GENERAL DETAILS.txt","w");
                                                                                                                                                                                                                                while(fread(&jet,sizeof(seat_allocation),1,temp))
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                fwrite(&jet,sizeof(seat_allocation),1,seat_reader);
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                fclose(temp);
                                                                                                                                                                                                                                fclose(seat_reader);
                                                                                                                                                                                                                }
                                                                                                                                                                                                                if(flag2==1)
                                                                                                                                                                                                                {
                                                                                                                                                                                                                                seat_reader=fopen("FLIGHT GENERAL DETAILS.txt","a+");
                                                                                                                                                                                                                                temp2=fopen("TEMP3.txt","r");
                                                                                                                                                                                                                                fread(&jet,sizeof(seat_allocation),1,temp2);
                                                                                                                                                                                                                                jet.fbsn[jet.fbsnasize]=customer.seatno;
                                                                                                                                                                                                                                jet.fbsnasize++;
                                                                                                                                                                                                                                jet.fnosa--;
                                                                                                                                                                                                                                flag= 1;
                                                                                                                                                                                                                                fwrite(&jet,sizeof(seat_allocation),1,seat_reader);
                                                                                                                                                                                                                                fclose(seat_reader);
                                                                                                                                                                                                                                fclose(temp2);

                                                                                                                                                                                                                }
                                                                                                                                                                                                                if(flag==0)
                                                                                                                                                                                                                {
                                                                                                                                                                                                                                seat_reader=fopen("FLIGHT GENERAL DETAILS.txt","a+");
                                                                                                                                                                                                                                strcpy(jet.destination,destination);
                                                                                                                                                                                                                                jet.date = customer.dd;
                                                                                                                                                                                                                                jet.fnosa = 5;
                                                                                                                                                                                                                                jet.fbsnasize=0;
                                                                                                                                                                                                                                jet.fbsn[jet.fbsnasize]=customer.seatno;
                                                                                                                                                                                                                                jet.fbsnasize++;
                                                                                                                                                                                                                                fwrite(&jet,sizeof(seat_allocation),1,seat_reader);
                                                                                                                                                                                                                                fclose(seat_reader);
                                                                                                                                                                                                                }
                                                                                                                                                                                                }

                                                                                                                                                                                                cost = 1000.00*no_ofseats;
                                                                                                                                                                                                system("cls");
                                                                                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                                                                                {
                                                                                                                                                                                                                printf("\xcd");
                                                                                                                                                                                                }
                                                                                                                                                                                                printf("\n");
                                                                                                                                                                                                printf("\n\n PAYMENT PORTAL\n");
                                                                                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                                                                                {
                                                                                                                                                                                                                printf("\xcd");
                                                                                                                                                                                                }
                                                                                                                                                                                                printf("\n");
                                                                                                                                                                                                F2 : printf("\n\n\n\t\t\tThe total cost of your booking is %f\n\n\t\t\tProceed to pay? ",cost);
                                                                                                                                                                                                scanf("%*c%c",&payment);
                                                                                                                                                                                                if(payment=='y'|| payment=='Y')
                                                                                                                                                                                                {
                                                                                                                                                                                                                printf("\n\n\t\tPlease make your payment through any platform you are comfortable with : \n\n\t\t\t*PAYTM\n\t\t\t*NET BANKING\n");
                                                                                                                                                                                                                printf("\n\n\n\t\tPlease wait for payment confirmation from our side.");
                                                                                                                                                                                                                scanf("%*c%c",&ch);
                                                                                                                                                                                                                if(ch=='p'||ch=='P')
                                                                                                                                                                                                                {
                                                                                                                                                                                                                                printf("\n\n\t\t\t\t\t\tPayment Succesful\n");
                                                                                                                                                                                                                                printf("YOUR SEAT HAS BEEN BOOKED.THANK YOU FOR BOOKING\n");
                                                                                                                                                                                                                }
                                                                                                                                                                                                }
                                                                                                                                                                                                else
                                                                                                                                                                                                {
                                                                                                                                                                                                                printf("Please make payment to confirm your seat.\n");
                                                                                                                                                                                                                goto F2;
                                                                                                                                                                                                }
                                                                                                                                                                                                getch();
                                                                                                                                                                                                break;


                                                                                                                                                                                }
                                                                                                                                                                                case 3 : //CANCEL TICKETS
                                                                                                                                                                                {
                                                                                                                                                                                                cancelFlight();
                                                                                                                                                                                                getch();
                                                                                                                                                                                                break;
                                                                                                                                                                                }
                                                                                                                                                                                case 4 : //VIEW PASSENGER
                                                                                                                                                                                {
                                                                                                                                                                                                displayFlight();
                                                                                                                                                                                                getch();
                                                                                                                                                                                                break;
                                                                                                                                                                                }
                                                                                                                                                                                case 5 : //EXIT
                                                                                                                                                                                {
                                                                                                                                                                                                goto M0;
                                                                                                                                                                                }
                                                                                                                                                                }
                                                                                                                                                                goto F0;

                                                                                                                                                }
                                                                                                                                                case 3 ://EXIT THE BOOKING PORTAL
                                                                                                                                                {
                                                                                                                                                                goto L8;
                                                                                                                                                }
                                                                                                                                }
                                                                                                                }
                                                                                                                case 2 ://ENTERTAINMENT WHILE TRAVELLING
                                                                                                                {
                                                                                                                                system("cls");
                                                                                                                                system("color e0");
                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                {
                                                                                                                                                printf("\xcd");
                                                                                                                                }
                                                                                                                                printf("\n");
                                                                                                                                printf("\n\nENTERTAINMENT SECTOR\n");
                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                {
                                                                                                                                                printf("\xcd");
                                                                                                                                }
                                                                                                                                printf("\n");
                                                                                                                                printf("\n\n \t\t Are you bored? ");
                                                                                                                                scanf("%*c%c",&bored);
                                                                                                                                if(bored =='y' || bored =='Y')
                                                                                                                                {
                                                                                                                                                T1 : system("cls");
                                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                                {
                                                                                                                                                                printf("\xcd");
                                                                                                                                                }
                                                                                                                                                printf("\n");
                                                                                                                                                printf("LET'S HAVE SOME FUN!!!!");
                                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                                {
                                                                                                                                                                printf("\xcd");
                                                                                                                                                }
                                                                                                                                                printf("\n");
                                                                                                                                                printf("\n\n\t[1] PLAY TIC TAC TOE WITH THE APP\n\n\t[2] READ JOURNALS\n\n\t[3] EXIT\n\nEnter your choice : ");//ASKING WHAT THE USER WANTS TO DO ?
                                                                                                                                                scanf("%d",&eopt);
                                                                                                                                                switch(eopt)
                                                                                                                                                {
                                                                                                                                                                case 1 : //TIC TAC TOE CODE
                                                                                                                                                                {
                                                                                                                                                                                T0 : system("cls");
                                                                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                                                                {
                                                                                                                                                                                                printf("\xcd");
                                                                                                                                                                                }
                                                                                                                                                                                printf("\n");
                                                                                                                                                                                printf("\n\nWELCOME TO THE GAME OF TIC TAC TOE.\n");
                                                                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                                                                {
                                                                                                                                                                                                printf("\xcd");
                                                                                                                                                                                }
                                                                                                                                                                                printf("\n");
                                                                                                                                                                                printf("\n\nNOTE : YOU WILL BE COMPETING AGAINST THE APP.\n\n");
                                                                                                                                                                                init_matrix();//TO INITIAL ALL THE ELEMENTS OF THE TIC TAC TOE MATRIX TO EMPTY
                                                                                                                                                                                do
                                                                                                                                                                                {
                                                                                                                                                                                                disp_matrix(); //TO DISPLAY THE LINES TO DIFFERENTIATE THE COLOUMS AND ROWS
                                                                                                                                                                                                get_player_move();//GETS THE COORDINATES OF THE PLACE WHERE THE USER WANTS TO PUT 'X'
                                                                                                                                                                                                done = check(); //CHECKS IF THE GAME IS OVER AND ANNOUNCE THE WINNER
                                                                                                                                                                                                if(done!= ' ')
                                                                                                                                                                                                                break; //GAME OVER SO IT BREAKS THE LOOP
                                                                                                                                                                                                get_computer_move();//GETS THE COMPUTER MOVE IF THE GAME HAS NOT ENDED
                                                                                                                                                                                                done = check(); //CHECKS IF THE GAME IS OVER
                                                                                                                                                                                }
                                                                                                                                                                                while(done== ' ');
                                                                                                                                                                                if(done=='X')
                                                                                                                                                                                                printf("\t\t\tYou won!\n\n");
                                                                                                                                                                                else
                                                                                                                                                                                                printf("\t\t\tI won!!!!\n\n");
                                                                                                                                                                                disp_matrix(); //DISPLAYS THE WINNING MATRIX
                                                                                                                                                                                getch();
                                                                                                                                                                                printf("\n\n\t\tDo you want to play again ? ");
                                                                                                                                                                                scanf("%*c%c",&e);
                                                                                                                                                                                if(e=='y'||e=='Y')
                                                                                                                                                                                {
                                                                                                                                                                                                goto T0;
                                                                                                                                                                                }
                                                                                                                                                                                else
                                                                                                                                                                                {
                                                                                                                                                                                                goto T1;
                                                                                                                                                                                }

                                                                                                                                                                }
                                                                                                                                                                case 2 : //TO READ JOUNALS
                                                                                                                                                                {
                                                                                                                                                                                T2 : system("cls");
                                                                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                                                                {
                                                                                                                                                                                                printf("\xcd");
                                                                                                                                                                                }
                                                                                                                                                                                printf("\n");
                                                                                                                                                                                printf("BOOKS AVAILABLE AVAILABLE\n\n\n");
                                                                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                                                                {
                                                                                                                                                                                                printf("\xcd");
                                                                                                                                                                                }
                                                                                                                                                                                printf("\n");
                                                                                                                                                                                printf("\n\n\t[1]WHEN THE SEA TAKES YOU, I WON'T COME WITH \n\t[2]SOUTHERN COMFORT AND THE KINDNESS OF STRANGERS\n\t[3]ON BOARD AN ANGEL FLIGHT\n\t[4]DREAM WEAVER\n\t[5]28 LETTERS\n\t[6]EXIT\n\t\t ENTER THE BOOK NUMBER YOU WANNA LEARN : ");
                                                                                                                                                                                scanf("%d",&rjopt);
                                                                                                                                                                                switch(rjopt)
                                                                                                                                                                                {
                                                                                                                                                                                                case 1 ://TO PRINT THE BOOK 1
                                                                                                                                                                                                {
                                                                                                                                                                                                                system("cls");
                                                                                                                                                                                                                read_journals=fopen("JOURNAL 1.txt","r");
                                                                                                                                                                                                                if(read_journals==NULL)
                                                                                                                                                                                                                {
                                                                                                                                                                                                                                printf("SORRY COULDN'T DISPLAY THE BUS DETAILS\n");
                                                                                                                                                                                                                                break;
                                                                                                                                                                                                                }
                                                                                                                                                                                                                while(!feof(read_journals))//READING THE FILE UNTIL THE FILE POINTER REACHES THE END OF THE FILE
                                                                                                                                                                                                                {
                                                                                                                                                                                                                                dtemp=fgetc(read_journals);
                                                                                                                                                                                                                                printf("%c",dtemp);
                                                                                                                                                                                                                }
                                                                                                                                                                                                                fclose(read_journals);
                                                                                                                                                                                                                getch();
                                                                                                                                                                                                                break;

                                                                                                                                                                                                }
                                                                                                                                                                                                case 2 ://TO PRINT THE BOOK 2
                                                                                                                                                                                                {
                                                                                                                                                                                                                system("cls");
                                                                                                                                                                                                                read_journals=fopen("JOURNAL 2.txt","r");
                                                                                                                                                                                                                if(read_journals==NULL)
                                                                                                                                                                                                                {
                                                                                                                                                                                                                                printf("SORRY COULDN'T DISPLAY THE BUS DETAILS\n");
                                                                                                                                                                                                                                break;
                                                                                                                                                                                                                }
                                                                                                                                                                                                                while(!feof(read_journals))//READING THE FILE UNTIL THE FILE POINTER REACHES THE END OF THE FILE
                                                                                                                                                                                                                {
                                                                                                                                                                                                                                dtemp=fgetc(read_journals);
                                                                                                                                                                                                                                printf("%c",dtemp);
                                                                                                                                                                                                                }
                                                                                                                                                                                                                fclose(read_journals);
                                                                                                                                                                                                                getch();
                                                                                                                                                                                                                break;

                                                                                                                                                                                                }
                                                                                                                                                                                                case 3 ://TO PRINT THE BOOK 3
                                                                                                                                                                                                {
                                                                                                                                                                                                                system("cls");
                                                                                                                                                                                                                read_journals=fopen("JOURNAL 3.txt","r");
                                                                                                                                                                                                                if(read_journals==NULL)
                                                                                                                                                                                                                {
                                                                                                                                                                                                                                printf("SORRY COULDN'T DISPLAY THE BUS DETAILS\n");
                                                                                                                                                                                                                                break;
                                                                                                                                                                                                                }
                                                                                                                                                                                                                while(!feof(read_journals))//READING THE FILE UNTIL THE FILE POINTER REACHES THE END OF THE FILE
                                                                                                                                                                                                                {
                                                                                                                                                                                                                                dtemp=fgetc(read_journals);
                                                                                                                                                                                                                                printf("%c",dtemp);
                                                                                                                                                                                                                }
                                                                                                                                                                                                                fclose(read_journals);
                                                                                                                                                                                                                getch();
                                                                                                                                                                                                                break;

                                                                                                                                                                                                }
                                                                                                                                                                                                case 4 ://TO PRINT THE BOOK 4
                                                                                                                                                                                                {
                                                                                                                                                                                                                system("cls");
                                                                                                                                                                                                                read_journals=fopen("JOURNAL 4.txt","r");
                                                                                                                                                                                                                if(read_journals==NULL)
                                                                                                                                                                                                                {
                                                                                                                                                                                                                                printf("SORRY COULDN'T DISPLAY THE BUS DETAILS\n");
                                                                                                                                                                                                                                break;
                                                                                                                                                                                                                }
                                                                                                                                                                                                                while(!feof(read_journals))//READING THE FILE UNTIL THE FILE POINTER REACHES THE END OF THE FILE
                                                                                                                                                                                                                {
                                                                                                                                                                                                                                dtemp =fgetc(read_journals);
                                                                                                                                                                                                                                printf("%c",dtemp);
                                                                                                                                                                                                                }
                                                                                                                                                                                                                fclose(read_journals);
                                                                                                                                                                                                                getch();
                                                                                                                                                                                                                break;

                                                                                                                                                                                                }
                                                                                                                                                                                                case 5 ://TO PRINT THE BOOK 5
                                                                                                                                                                                                {
                                                                                                                                                                                                                system("cls");
                                                                                                                                                                                                                read_journals=fopen("JOURNAL 5.txt","r");
                                                                                                                                                                                                                if(read_journals==NULL)
                                                                                                                                                                                                                {
                                                                                                                                                                                                                                printf("SORRY COULDN'T DISPLAY THE BUS DETAILS\n");
                                                                                                                                                                                                                                break;
                                                                                                                                                                                                                }
                                                                                                                                                                                                                while(!feof(read_journals))//READING THE FILE UNTIL THE FILE POINTER REACHES THE END OF THE FILE
                                                                                                                                                                                                                {
                                                                                                                                                                                                                                dtemp=fgetc(read_journals);
                                                                                                                                                                                                                                printf("%c",dtemp);
                                                                                                                                                                                                                }
                                                                                                                                                                                                                fclose(read_journals);
                                                                                                                                                                                                                getch();
                                                                                                                                                                                                                break;

                                                                                                                                                                                                }
                                                                                                                                                                                                case 6 : //TO EXIT THE PORTAL
                                                                                                                                                                                                {
                                                                                                                                                                                                                goto T1;
                                                                                                                                                                                                }
                                                                                                                                                                                }
                                                                                                                                                                                goto T2;
                                                                                                                                                                }
                                                                                                                                                                case 3 : //TO EXIT ENTERTAINMENT WINDOW
                                                                                                                                                                {
                                                                                                                                                                                goto L8;
                                                                                                                                                                }
                                                                                                                                                }

                                                                                                                                }
                                                                                                                                getch();
                                                                                                                                break;
                                                                                                                }
                                                                                                                case 3 ://REACHED THE DESTINATION
                                                                                                                {
                                                                                                                                system("cls");
                                                                                                                                system("color c6");
                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                {
                                                                                                                                                printf("\xcd");
                                                                                                                                }
                                                                                                                                printf("\n");
                                                                                                                                printf("LET'S FIND SOME FOOD!!!!");
                                                                                                                                for(i=0;i<100;i++)
                                                                                                                                {
                                                                                                                                                printf("\xcd");
                                                                                                                                }
                                                                                                                                printf("\n");
                                                                                                                                printf("\n\nWould you like to grab some food ? ");
                                                                                                                                scanf("%*c%c",&food);
                                                                                                                                if(food=='Y' || food=='y')
                                                                                                                                {
                                                                                                                                               printf("Enter your current location [NOTE : The first letter must be capital] : ");
                                                                                                                                               scanf("%*c%[^\n]s",destination_2);
                                                                                                                                               hotels_around(destination_2);
                                                                                                                                               getch();
                                                                                                                                }
                                                                                                                                else
                                                                                                                                {
                                                                                                                                                printf("\n\n THANK YOU FOR TRAVELLING WITH US.HOPE TO SEE YOU SOON!!\n");
                                                                                                                                                getch();
                                                                                                                                }
                                                                                                                                break;
                                                                                                                }
                                                                                                                case 4 : //EXIT
                                                                                                                {
                                                                                                                                goto L0;
                                                                                                                }
                                                                                                }
                                                                                                goto L8;


                                                                                }
                                                                                else
                                                                                {
                                                                                                printf("\n\nWrong password\n\n");
                                                                                                fclose(fp);
                                                                                                goto L6;
                                                                                }
                                                                                userFound=1;//FLAG VARIABLE WHICH CHECKS IF THE ENTERED USERNAME IS PRESENT IN THE FILE
                                                                }
                                                }
                                                if(!userFound)
                                                {
                                                                printf("\nUser is not registered\nWould you like to open an account ? ");//ASKING THE USER TO SIGN UP BEFORE LOGGING IN
                                                                scanf("%*c%c",&a);
                                                                if(a=='y'||a=='Y')
                                                                {
                                                                                fclose(fp);
                                                                                goto L7;
                                                                }
                                                }
                                                fclose(fp);//CLOSING FILE
                                                break;
                                }
                                case 3 : //EXIT THE PORTAL
                                {
                                                printf("\n\n\t\t\tBYE BYE.DO COME BACK TO FLY AGAIN :)\n\n\n");
                                                exit(0);
                                }
                }
                system("cls");
                goto L0;
}
