#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>


int pwstatus[8] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; //white pawn first movement 
int pbstatus[8] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; //black pawn first movement

char board[8][8] = {
                    { 'R' , 'H' , 'C' , 'K' , 'Q' , 'C' , 'H' , 'R' },
                    { 'P' , 'P' , 'P' , 'P' , 'P' , 'P' , 'P' , 'P' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { 'p' , 'p' , 'p' , 'p' , 'p' , 'p' , 'p' , 'p' },
                    { 'r' , 'h' , 'c' , 'k' , 'q' , 'c' , 'h' , 'r' }
                    };

void display();
void change( int , int , int , int ) ;
void pawn(int , int ) ;
void rook(int , int ) ;
void horse(int , int ) ;
void camel( int , int ) ;
void king( int , int ) ;
void queen( int , int ) ;
void pawnb( int , int ) ;
//start of artmind
void mpawn(int , int ) ;
void mrook(int , int ) ;
void mhorse(int , int ) ;
void mcamel( int , int ) ;
void mking( int , int ) ;
void mqueen( int , int ) ;
void mpawnb( int , int ) ;
//end of artmind
void player1();
void player2();
void help();
int check(int , int ) ;
int check2(int , int ) ;
int check3(int , int ) ;
void menu(void);
void welcome(void);
void colorchanger();
void setting();
void difficulty();

void TheQueen();
void Theking();
void Thecshop();
void Thehours();
void TheRook();
void ThePawn();

void artmind();

int md=0;

int ctr=0;

int turn =0;

int killw=0; int killb=0;

int lim[100]={};

main()
{
	char ch;
	system ("color 06");
	//printf( "\n\tWELCOME TO CHESS GAME" ) ;
    //printf( "\n\n\t By Hosseini, Shaker " ) ;
    welcome();
	//printf("\n\n=================================\n\n");
	menu();
	
    //getch();
    //system( "cls" ) ;
    

 do
 {
 turn++ ;
 system( "cls" ) ;

 display();
 

 if( (turn%2) == 0 )
 {
          if(md == 1)
          {
          	  artmind();
          }
		if ( md == 0)
		{
			 player2();
		}
		   
            
 }
 else
 {
     player1();
 }

 printf( " \n\nPress Enter To Continue ! \n\n " ) ;

 ch = getch();
 }while( ch==13 ) ;

}

void welcome (void)
{
	printf("####################################\n");
	printf("#	WELCOME TO CHESS GAME  	   #\n");
	printf("#	   By Hosseini, Shaker     #\n");
	printf("####################################\n\n");
}

void setting()
{
	int num;
	system("cls");
	printf("=================================\n");
	printf ("\n 1.Change Color\n 0.Back\n ");
	scanf("%d",&num);
	switch (num)
	{
		case 1:
			colorchanger();
			break;
		case 0:
			system("cls");
			printf("=================================\n");
			menu();
	}	
}





void colorchanger()
{
	int user = '\0';
	char H;
	char x[15] = "color ";
	x[6] = '\0';
	x[7] = '\0';
	
	system("cls");
	
	printf("=================================\n");

	
	printf(" CHANGE COLOR AS YOU LIKE ... \n  1.Background .  \n  2.Text .   \n  3.Both of Them .	\n \
 0.Current color .\n  ");
	fflush(stdin);
    scanf("%d",&user);
    printf("\n=================================\n");
    switch(user)
    {
    case 1:
                help();
                printf(" \n\n Color code for background...  =  ");
                fflush(stdin);
          scanf("%c",&x[6]);
          	if (x[6] != '0'){
          		while(x[7] == '\0'){x[7] = '0';}
      		}
      		if (x[6] == '0') {
      			x[7]='6';
			  }
          system(x);
          break;

     case 2:
        		help();
           		printf(" \n\n Color code for text...  =  ");
      			while(x[6] == '\0'){ x[6] = '0';}
    			fflush(stdin);
    	scanf("%c",&x[7]);
    	system(x);
    	break;
     case 3:
        		help();
        		printf(" \n\n Color code for background...  =  ");
    	fflush(stdin);
    	scanf("%c",&x[6]);
    	printf(" \n\n Color code for text...  =  ");
    	fflush(stdin);
    	scanf("%c",&x[7]);
    	system(x);
        break;
        
      case 0:
      		
      		break;
      		
    }
	
	printf (" Do you like this color?(y/n) :	");
	fflush(stdin);
	scanf ("%c",&H);
	if(H=='Y' || H=='y'){
		system( "cls" );
		difficulty();
	}
	else {
		system( "cls" );
		colorchanger();
	}
	
	
}

//jaye kardare 

void difficulty()
{
	int b;
	int num;
	printf("\n=================================\n\n");
	       printf("1- single player \n\n 2- two player \n");
	       scanf("%d",&num);
	       switch(num)
	       {
	       	case 1 :
	       		md = 1;
	       		
	       		break;
	       		
	       	case 2 :
	       		md =0;
	       		
	       		break;
	       }
	       
			
			printf(" 1.easy \t 2.hard\n ");
       		scanf("%d",&b);
       			switch(b)
       			{
       				case 1 :
       					printf(" You choose easy We will show you \n the full movements\
 of each elemnts\n To choose the easiest for you \n Now ENTER TO START THE GAME ");
       					ctr = 1;
       					getch();
       					break;
       		
      
       
        			case 2 :
        				printf(" You choose hard  \n now ENTER TO START THE GAME ");
        				getch();
        				system( "cls" );
        				break;
       
    			}	
}

//end of difficulty

void help()
{
     printf("\n\n    0 = Black       8 = Gray\n\
    1 = Blue        9 = Light Blue\n\
    2 = Green       A = Light Green\n\
    3 = Aqua        B = Light Aqua\n\
    4 = Red         C = Light Red\n\
    5 = Purple      D = Light Purple\n\
    6 = Yellow      E = Light Yellow\n\
    7 = White       F = Bright White ");
}





void menu (void)
{
	
char ch , H;
int a;	
int rate=0;
	

	
    printf(" 1.Start Game\n 2.Setting\n 3.exit\n ");
	scanf ("%d",&a);
	switch (a)
	{
		case 1:
			difficulty();
			
			break;
		
		case 2:
			setting();
			break;
			
		case 3:
			system("cls");
			printf ("====================================\n\n");
			printf(" Thank you for choosing us...\n");
			printf(" Please rate us(1-5)\n ");
			rate:
			scanf("%d",&rate);
			if (rate>0 && rate<6)
			{
			switch(rate)
			{
				case 1:
					printf(" *\n");
					break;
				case 2:
					printf(" **\n");
					break;
				case 3:
					printf(" ***\n");
					break;
				case 4:
					printf(" ****\n");
					break;
				case 5:
					printf(" *****\n");
					break;	
			}
			}
			else {
				printf("it's out of range .try again...\n");
				goto rate;
			}
			printf("      Created by Hosseini , Shaker");
			exit(0);
			break;
	}
	
	
	
	
	
	
}








void display()
{
    int i , j , k ;

    printf( " " ) ;
    for( i=0 ; i<8 ; i++ ) printf( "    %d" , i ) ; printf( "\n" ) ;

    for( k=0 ; k<8 ; k++ )
    {
    printf( "  " ) ;
    for( i=0 ; i<42 ; i++ ) { printf( "-" ) ; } printf( "\n" ) ; printf( "%d " , k ) ;

    for( j=0 ; j<8 ; j++ ) { printf( "|| %c " , board[k][j] ) ; }
    printf( "|| \n" ) ;
    }

    printf( "  " ) ;
    for( i=0 ; i<42 ; i++ ) { printf( "-" ) ; } printf( "\n" ) ;
    
    

}


//az inja shoro mishe tabe ha 




void ThePawn()
{
	printf("                 \n");
    printf("         *       \n");
    printf("         *       \n");
    printf("        [P]      \n");
    printf("                 \n");
    printf("---------------------------------help----------------------------------\n");
    printf("1- In their first move, each pawn has the option to move forward one space or two spaces \n");
    printf("2- The Pawn can never move backwards.\n");
    printf("3- The Pawn also has a special move called <En Passant>\n");
    
    printf("---------------------------------help----------------------------------\n\n");
}
void TheRook()
{
	printf("         *       \n");
    printf("         *       \n");
    printf("         *       \n");
    printf("         *       \n");
    printf(" * * * *[R]* * * * \n");
    printf("         *       \n");
    printf("         *       \n");
    printf("         *       \n");
    printf("         *       \n");
    printf("------------------------------------help-----------------------------------\n");
    printf("These chess pieces move up and down the rank and file of the chessboard,\n"
	" and can move any number of spaces as long as\n they are not obstructed by another chess piece\n");
	printf("------------------------------------help-----------------------------------\n\n");
	
    
}

void TheQueen()
{
	printf(" *       *       \n");
    printf("   *     *     * \n");
    printf("     *   *   *   \n");
    printf("       * * *     \n");
    printf(" * * * *[q]* * * \n");
    printf("       * * *       \n");
    printf("     *   *   *    \n");
    printf("   *     *     *  \n");
     printf("----------------------help-----------------------\n");
     printf("Like the King, the Queen can move in any direction\n");
     printf("----------------------help-----------------------\n\n");
}

void Thecshop()
{
	printf(" *               \n");
    printf("   *           * \n");
    printf("     *       *   \n");
    printf("       *   *     \n");
    printf("        [C]      \n");
    printf("       *   *     \n");
    printf("     *       *   \n");
    printf("   *           * \n");
    printf("-----------------------------help----------------------------\n");
    printf("These chess pieces move along the diagonals of the chessboard\n");
    printf("-----------------------------help----------------------------\n\n");
}

void Theking()
{
	printf("                 \n");
    printf("                 \n");
    printf("                 \n");
    printf("       * * *     \n");
    printf("       *[k]*     \n");
    printf("       * * *     \n");
    printf("                 \n");
    printf("                 \n");
    printf("--------------------help--------------------\n");
    printf("The King can move one space in any direction\n");
    printf("--------------------help--------------------\n\n");
}

void Thehours()
{
  	//printf("                 \n");
    printf("                 \n");
    printf("       *   *     \n");
    printf("     *       *   \n");
    printf("        [H]      \n");
    printf("     *       *   \n");
    printf("        *  *       \n");
    printf("                 \n");
    printf("----------------------------------help----------------------------------\n");
    printf("These chess pieces have the unique trait of being able to 'leap' over other chess pieces.\n");
    printf("----------------------------------help----------------------------------\n\n");
}






//inja akhreshe


void change( int r1 , int c1 , int r2 , int c2 )
{
    char temp ;

    temp = board[r1][c1] ;
    board[r1][c1] = board[r2][c2] ;
    board[r2][c2] = temp ;

}

void pawn( int r1 , int c1 ) // paido
{
    int i;
    
	pwstatus[c1]++;
	
	
	for (i=0;i<100;++i){
		lim[i]=0;
	}
	
	i=0;
	
    printf( "Available are: \n" ) ;

   if( pwstatus[c1] == 1 )
    {
        if( board[r1+1][c1] == ' ' ){
        	printf( "%d%d , " , r1+1 , c1 ) ;
        	lim[i]=((r1+1)*10)+c1;
        	++i;
    	}

        if( board[r1+2][c1] == ' ' ){
        	printf( "%d%d , " , r1+2 , c1 ) ;
			lim[i]=((r1+2)*10)+c1;
        	++i;
		}
	
    }
    else
    {
        if(board[r1+1][c1] == ' ' ){
        	printf( "%d%d , " , r1+1 , c1 ) ;
        	lim[i]=((r1+1)*10)+c1;
        	++i;
		}
        if( check(r1+1 , c1+1) == 1 ){
        	printf( "%d%d* , " , r1+1 , c1+1 ) ;
        	lim[i]=((r1+1)*10)+(c1+1);
        	++i;
		}
        if( check(r1+1 , c1-1) == 1 ){
        	printf( "%d%d* , " , r1+1 , c1-1 ) ;
        	lim[i]=((r1+1)*10)+(c1-1);
        	++i;
		}
	
	
	}

}

void rook( int r1 , int c1 )
{
    int i , j , n , k=0;

    printf( "Available are: \n" ) ;

    n=c1;
	
    printf( "Horizontally: \n" ) ;

    while( board[r1][n-1] == ' ' || check3(r1,n-1) )
    {
        if( n == 0 ) { break ; }
        printf( "%d%d , " , r1 , n-1 ) ;
        lim[k]=(r1*10)+(n-1);
        ++k;
        n-- ;
    }

    n=c1 ;

    while( ( board[r1][n+1] == ' ' || check3(r1,n+1) ) && (n+1) <= 7 )
    {

        printf( "%d%d , " , r1 , n+1 ) ;
        lim[k]=(r1*10)+(n+1);
        ++k;
        ++n ;
    }

    printf( "\nVertically:\n" ) ;

    n = r1 ;

    while( ( board[n-1][c1] == ' ' || check3(n-1,c1) ) && n > -1 )
    {
        printf( "%d%d , " , n-1 , c1 ) ;
        lim[k]=((n-1)*10)+c1;
        ++k;
        --n ;
    }

    n = r1 ;

    while( (board[n+1][c1] == ' ' || check3(n+1,c1) ) && ( (n) <= 7 ) )
    {
        printf( "%d%d , " , n+1 , c1 ) ;
        lim[k]=((n+1)*10)+c1;
        ++k;
        ++n ;
    }

}

void horse( int r1 , int c1 )
{
	int i=0;
    printf( "Available are: " ) ;


    if( board[r1+2][c1+1] == ' ' || check3(r1+2,c1+1) ){
		printf( "%d%d, " , r1+2 ,c1+1) ;
		lim[i]=((r1+2)*10)+(c1+1);
		++i;
	}
    if( board[r1+2][c1-1] == ' ' || check3(r1+2,c1-1) ) { 
		if( (c1-1) > -1 ){
			printf( "%d%d, " , r1+2, c1-1 ) ; 
			lim[i]=((r1+2)*10)+(c1-1);
			++i;
		}
	}

    if( board[r1+1][c1+2] == ' ' || check3(r1+1,c1+2) ) {  
		if( (c1+2) != 8 ){
			printf( "%d%d, " , r1+1 , c1+2 ) ;
			lim[i]=((r1+1)*10)+(c1+2);
			++i;
		}
	}
    if( board[r1-1][c1+2] == ' ' || check3(r1-1,c1+2) ) {  
		printf( "%d%d, " , r1-1 , c1+2 ) ; 
		lim[i]=((r1-1)*10)+(c1+2);
		++i;
	}

    if( board[r1-2][c1-1] == ' ' || check3(r1-2,c1-1) )
    {
        if( (c1-1) != -1 ){
        	printf( "%d%d, " , r1-2 , c1-1 ) ;
        	lim[i]=((r1-2)*10)+(c1-1);
        	++i;
    	}
    }

    if( board[r1-2][c1+1] == ' ' || check3(r1-2,c1+1) ) {
		printf( "%d%d, " , r1-2 , c1+1 ) ;
		lim[i]=((r1-2)*10)+(c1+1);
		++i;
	}

    if( board[r1+1][c1-2] == ' ' || check3(r1+1,c1-2) ) {
		printf( "%d%d, " , r1+1 , c1-2 ) ;
		lim[i]=((r1+1)*10)+(c1-2);
		++i;
	}

    if( board[r1-1][c1-2] == ' ' || check3(r1-1,c1-2) )
    {
        if( (c1-2) != -1 ){
            printf( "%d%d, " , r1-1 , c1-2 ) ;
        	lim[i]=((r1-1)*10)+(c1-2);
			++i;  
        }
    }
}


void camel( int r1 , int c1 )
{
    int a , b , c , d , i=0;
    printf( "Available are: \n" ) ;


    a = 1 , b = 1 ;

    while( board[r1-a][c1+b] == ' ' || check3(r1-a,c1+b) )
    {
        if( (r1-a) == -1 || (c1+b) == 8 ) break ;
        printf( "%d%d , " , r1-a , c1+b ) ;
        lim[i]=((r1-a)*10)+(c1+b);
        ++i;
        a++ ;
        b++ ;
    }


    a = 1 , b = 1 ;

    while( board[r1+a][c1-b] == ' ' || check3(r1+a,c1-b) )
    {
        if( (r1+a) == 8 || (c1-b) == -1 ) break ;
        printf( "%d%d , " , r1+a , c1-b ) ;
        lim[i]=((r1+a)*10)+(c1-b);
        ++i;
        a++ ;
        b++ ;
    }

    a = 1 , b = 1 ;


    while( board[r1+a][c1+b] == ' ' || check3(r1+a,c1+b) )
    {
        if( (r1+a) == 8 || (c1+b) == 8 ) break ;
        printf( "%d%d , " , r1+a , c1+b ) ;
        lim[i]=((r1+a)*10)+(c1+b);
        ++i;
        a++ ;
        b++ ;
    }

    a = 1 ;
    b = 1 ;

    while( board[r1-a][c1-b] == ' ' || check3(r1-a,c1-b) )
    {
        if( (r1-a) == -1 || (c1-b) == -1 ) break ;
        printf( "%d%d , " , r1-a , c1-b ) ;
        lim[i]=((r1-a)*10)+(c1-b);
        ++i;
        a++ ;
        b++ ;
    }

}

void king( int r1 , int c1 )
{
	int i=0;
    printf( "Available are: " ) ;
								
    if( board[r1][c1+1] == ' ' || check3(r1,c1+1) ) {
		printf( "%d%d , " , r1 , c1+1 ) ;
		lim[i]=((r1)*10)+(c1+1);
		++i;
	}

    if( board[r1][c1-1] == ' ' || check3(r1,c1-1) ) {
		printf( "%d%d , " , r1 , c1-1 ) ;
		lim[i]=((r1)*10)+(c1-1);
		++i;
	}

    if( board[r1+1][c1] == ' ' || check3(r1+1,c1) ) {
		printf( "%d%d , " , r1+1 , c1 ) ;
		lim[i]=((r1+1)*10)+(c1);
		++i;
	}

    if( board[r1-1][c1] == ' ' || check3(r1-1,c1) ) {
		printf( "%d%d , " , r1-1 , c1 ) ;
		lim[i]=((r1-1)*10)+(c1);
		++i;
	}

    if( board[r1+1][c1+1] == ' ' || check3(r1+1,c1+1) ) {
		printf( "%d%d , " , r1+1 , c1+1 ) ;
		lim[i]=((r1+1)*10)+(c1+1);
		++i;
	}

    if( board[r1-1][c1-1] == ' ' || check3(r1-1,c1-1) ) {
		printf( "%d%d , " , r1-1 , c1-1 ) ;
		lim[i]=((r1-1)*10)+(c1-1);
		++i;
	}

    if( board[r1-1][c1+1] == ' ' || check3(r1-1,c1+1) ) {
		printf( "%d%d , " , r1-1 , c1+1 ) ;
		lim[i]=((r1-1)*10)+(c1+1);
		++i;
	}

    if( board[r1+1][c1-1] == ' ' || check3(r1+1,c1-1) ) {
		printf( "%d%d , " , r1+1 , c1-1 ) ;
		lim[i]=((r1+1)*10)+(c1-1);
		++i;
	}
    
    
}

void queen( int r1 , int c1 )
{
    int x=1 , y=1 , a , b , i=0;
    printf( "Available are: \n" ) ;

    printf( "Horizontal: " ) ;

    while( board[r1][c1-y] == ' ' || check3(r1,c1-y) )
    {
        if( (c1-y) == -1 ) break ;
        printf( "%d%d , " , r1 , c1-y ) ;
        lim[i]=((r1)*10)+(c1-y);
        ++i;
        y++ ;
    }

    y = 1 ;

    while( board[r1][c1+y] == ' ' || check3(r1,c1+y) )
    {
        if( (c1+y) == 8 ) break ;
        printf( "%d%d , " , r1 , c1+y ) ;
        lim[i]=((r1)*10)+(c1+y);
        ++i;
        y++ ;
    }
	printf("\n");
	
    printf( "Vertical: " ) ;

    x = 1 ;

    while( board[r1-x][c1] == ' ' || check3(r1-x,c1) )
    {
        if( (r1-x) == -1 ) break ;
        printf( "%d%d , " , r1-x , c1 ) ;
        lim[i]=((r1-x)*10)+(c1);
        ++i;
        x++ ;
    }

    x = 1 ;

    while( board[r1+x][c1] == ' ' || check3(r1+x,c1) )
    {
        if( (r1+x) == 8 ) break ;
        printf( "%d%d , " , r1+x , c1 ) ;
        lim[i]=((r1+x)*10)+(c1);
        ++i;
        x++ ;
    }
	printf("\n");

    printf( "Diagonally: " ) ;

    a = 1 , b = 1 ;

    while( board[r1-a][c1+b] == ' ' || check3(r1-a,c1+b) )
    {
        if( (r1-a) == -1 || (c1+b) == 8 ) break ;
        printf( "%d%d , " , r1-a , c1+b ) ;
        lim[i]=((r1-a)*10)+(c1+b);
        ++i;
        a++ ;
        b++ ;
    }


    a = 1 , b = 1 ;

    while( board[r1+a][c1-b] == ' ' || check3(r1+a,c1-b) )
    {
        if( (r1+a) == 8 || (c1-b) == -1 ) break ;
        printf( "%d%d , " , r1+a , c1-b ) ;
        lim[i]=((r1+a)*10)+(c1-b);
        ++i;
        a++ ;
        b++ ;
    }

    a = 1 , b = 1 ;


    while( board[r1+a][c1+b] == ' ' || check3(r1+a,c1+b) )
    {
        if( (r1+a) == 8 || (c1+b) == 8 ) break ;
        printf( "%d%d , " , r1+a , c1+b ) ;
        lim[i]=((r1+a)*10)+(c1+b);
        ++i;
        a++ ;
        b++ ;
    }

    a = 1 ;
    b = 1 ;

    while( board[r1-a][c1-b] == ' ' || check3(r1-a,c1-b) )
    {
        if( (r1-a) == -1 || (c1-b) == -1 ) break ;
        printf( "%d%d , " , r1-a , c1-b ) ;
        lim[i]=((r1-a)*10)+(c1-b);
        ++i;
        a++ ;
        b++ ;
    }

}

void pawnb( int r1 , int c1 ) // paido black
{
    pbstatus[c1]++;
    
    
    int i;
	
	
	for (i=0;i<100;++i){
		lim[i]=0;
	}
	
	i=0;
	

    printf( "Available are: \n" ) ;


    if( pbstatus[c1] == 1 )
    {
        if( board[r1-1][c1] == ' ' ){
        	printf( "%d%d , " , r1-1 , c1 ) ;
			lim[i]=((r1-1)*10)+c1;
        	++i;
		}
        if( board[r1-2][c1] == ' ' ){
        	printf( "%d%d , " , r1-2 , c1 ) ;
        	lim[i]=((r1-2)*10)+c1;
        	++i;
    	}
    	
    }
    else
    {
        if(board[r1-1][c1] == ' ' ){
        	printf( "%d%d , " , r1-1 , c1 ) ;
        	lim[i]=((r1-1)*10)+c1;
        	++i;
		}
        if( check2(r1-1 , c1-1) == 1 ){
        	printf( "%d%d* , " , r1-1 , c1-1 ) ;
			lim[i]=((r1-1)*10)+(c1-1);
        	++i;
		}
        if( check2(r1-1 , c1+1) == 1 ){
        	printf( "%d%d* , " , r1-1 , c1+1 ) ;
        	lim[i]=((r1-1)*10)+(c1+1);
        	++i;
    	}
    }

}


//start of artmind


void mpawn( int r1 , int c1 ) // paido
{
    int i;
    
	pwstatus[c1]++;
	
	
	for (i=0;i<100;++i){
		lim[i]=0;
	}
	
	i=0;
	

   if( pwstatus[c1] == 1 )
    {
        if( board[r1+1][c1] == ' ' ){
        	lim[i]=((r1+1)*10)+c1;
        	++i;
    	}

        if( board[r1+2][c1] == ' ' ){
			lim[i]=((r1+2)*10)+c1;
        	++i;
		}
	
    }
    else
    {
        if(board[r1+1][c1] == ' ' ){
        	lim[i]=((r1+1)*10)+c1;
        	++i;
		}
        if( check(r1+1 , c1+1) == 1 ){
        	lim[i]=((r1+1)*10)+(c1+1);
        	++i;
		}
        if( check(r1+1 , c1-1) == 1 ){
        	lim[i]=((r1+1)*10)+(c1-1);
        	++i;
		}
	
	
	}

}

void mrook( int r1 , int c1 )
{
    int i , j , n , k=0;


    n=c1;
	

    while( board[r1][n-1] == ' ' || check3(r1,n-1) )
    {
        if( n == 0 ) { break ; }
        lim[k]=(r1*10)+(n-1);
        ++k;
        n-- ;
    }

    n=c1 ;

    while( ( board[r1][n+1] == ' ' || check3(r1,n+1) ) && (n+1) <= 7 )
    {

        lim[k]=(r1*10)+(n+1);
        ++k;
        ++n ;
    }


    n = r1 ;

    while( ( board[n-1][c1] == ' ' || check3(n-1,c1) ) && n > -1 )
    {
        lim[k]=((n-1)*10)+c1;
        ++k;
        --n ;
    }

    n = r1 ;

    while( (board[n+1][c1] == ' ' || check3(n+1,c1) ) && ( (n) <= 7 ) )
    {
        lim[k]=((n+1)*10)+c1;
        ++k;
        ++n ;
    }

}

void mhorse( int r1 , int c1 )
{
	int i=0;


    if( board[r1+2][c1+1] == ' ' || check3(r1+2,c1+1) ){
		lim[i]=((r1+2)*10)+(c1+1);
		++i;
	}
    if( board[r1+2][c1-1] == ' ' || check3(r1+2,c1-1) ) { 
		if( (c1-1) > -1 ){
			lim[i]=((r1+2)*10)+(c1-1);
			++i;
		}
	}

    if( board[r1+1][c1+2] == ' ' || check3(r1+1,c1+2) ) {  
		if( (c1+2) != 8 ){
			lim[i]=((r1+1)*10)+(c1+2);
			++i;
		}
	}
    if( board[r1-1][c1+2] == ' ' || check3(r1-1,c1+2) ) {  
		lim[i]=((r1-1)*10)+(c1+2);
		++i;
	}

    if( board[r1-2][c1-1] == ' ' || check3(r1-2,c1-1) )
    {
        if( (c1-1) != -1 ){
        	lim[i]=((r1-2)*10)+(c1-1);
        	++i;
    	}
    }

    if( board[r1-2][c1+1] == ' ' || check3(r1-2,c1+1) ) {
		lim[i]=((r1-2)*10)+(c1+1);
		++i;
	}

    if( board[r1+1][c1-2] == ' ' || check3(r1+1,c1-2) ) {
		lim[i]=((r1+1)*10)+(c1-2);
		++i;
	}

    if( board[r1-1][c1-2] == ' ' || check3(r1-1,c1-2) )
    {
        if( (c1-2) != -1 ){
        	lim[i]=((r1-1)*10)+(c1-2);
			++i;  
        }
    }
}


void mcamel( int r1 , int c1 )
{
    int a , b , c , d , i=0;


    a = 1 , b = 1 ;

    while( board[r1-a][c1+b] == ' ' || check3(r1-a,c1+b) )
    {
        if( (r1-a) == -1 || (c1+b) == 8 ) break ;
        lim[i]=((r1-a)*10)+(c1+b);
        ++i;
        a++ ;
        b++ ;
    }


    a = 1 , b = 1 ;

    while( board[r1+a][c1-b] == ' ' || check3(r1+a,c1-b) )
    {
        if( (r1+a) == 8 || (c1-b) == -1 ) break ;
        lim[i]=((r1+a)*10)+(c1-b);
        ++i;
        a++ ;
        b++ ;
    }

    a = 1 , b = 1 ;


    while( board[r1+a][c1+b] == ' ' || check3(r1+a,c1+b) )
    {
        if( (r1+a) == 8 || (c1+b) == 8 ) break ;
        lim[i]=((r1+a)*10)+(c1+b);
        ++i;
        a++ ;
        b++ ;
    }

    a = 1 ;
    b = 1 ;

    while( board[r1-a][c1-b] == ' ' || check3(r1-a,c1-b) )
    {
        if( (r1-a) == -1 || (c1-b) == -1 ) break ;
        lim[i]=((r1-a)*10)+(c1-b);
        ++i;
        a++ ;
        b++ ;
    }

}

void mking( int r1 , int c1 )
{
	int i=0;
								
    if( board[r1][c1+1] == ' ' || check3(r1,c1+1) ) {
		lim[i]=((r1)*10)+(c1+1);
		++i;
	}

    if( board[r1][c1-1] == ' ' || check3(r1,c1-1) ) {
		lim[i]=((r1)*10)+(c1-1);
		++i;
	}

    if( board[r1+1][c1] == ' ' || check3(r1+1,c1) ) {
		lim[i]=((r1+1)*10)+(c1);
		++i;
	}

    if( board[r1-1][c1] == ' ' || check3(r1-1,c1) ) {
		lim[i]=((r1-1)*10)+(c1);
		++i;
	}

    if( board[r1+1][c1+1] == ' ' || check3(r1+1,c1+1) ) {
		lim[i]=((r1+1)*10)+(c1+1);
		++i;
	}

    if( board[r1-1][c1-1] == ' ' || check3(r1-1,c1-1) ) {
		lim[i]=((r1-1)*10)+(c1-1);
		++i;
	}

    if( board[r1-1][c1+1] == ' ' || check3(r1-1,c1+1) ) {
		lim[i]=((r1-1)*10)+(c1+1);
		++i;
	}

    if( board[r1+1][c1-1] == ' ' || check3(r1+1,c1-1) ) {
		lim[i]=((r1+1)*10)+(c1-1);
		++i;
	}
    
    
}

void mqueen( int r1 , int c1 )
{
    int x=1 , y=1 , a , b , i=0;


    while( board[r1][c1-y] == ' ' || check3(r1,c1-y) )
    {
        if( (c1-y) == -1 ) break ;
        lim[i]=((r1)*10)+(c1-y);
        ++i;
        y++ ;
    }

    y = 1 ;

    while( board[r1][c1+y] == ' ' || check3(r1,c1+y) )
    {
        if( (c1+y) == 8 ) break ;
        lim[i]=((r1)*10)+(c1+y);
        ++i;
        y++ ;
    }
	

    x = 1 ;

    while( board[r1-x][c1] == ' ' || check3(r1-x,c1) )
    {
        if( (r1-x) == -1 ) break ;
        lim[i]=((r1-x)*10)+(c1);
        ++i;
        x++ ;
    }

    x = 1 ;

    while( board[r1+x][c1] == ' ' || check3(r1+x,c1) )
    {
        if( (r1+x) == 8 ) break ;
        lim[i]=((r1+x)*10)+(c1);
        ++i;
        x++ ;
    }


    a = 1 , b = 1 ;

    while( board[r1-a][c1+b] == ' ' || check3(r1-a,c1+b) )
    {
        if( (r1-a) == -1 || (c1+b) == 8 ) break ;
        lim[i]=((r1-a)*10)+(c1+b);
        ++i;
        a++ ;
        b++ ;
    }


    a = 1 , b = 1 ;

    while( board[r1+a][c1-b] == ' ' || check3(r1+a,c1-b) )
    {
        if( (r1+a) == 8 || (c1-b) == -1 ) break ;
        lim[i]=((r1+a)*10)+(c1-b);
        ++i;
        a++ ;
        b++ ;
    }

    a = 1 , b = 1 ;


    while( board[r1+a][c1+b] == ' ' || check3(r1+a,c1+b) )
    {
        if( (r1+a) == 8 || (c1+b) == 8 ) break ;
        lim[i]=((r1+a)*10)+(c1+b);
        ++i;
        a++ ;
        b++ ;
    }

    a = 1 ;
    b = 1 ;

    while( board[r1-a][c1-b] == ' ' || check3(r1-a,c1-b) )
    {
        if( (r1-a) == -1 || (c1-b) == -1 ) break ;
        lim[i]=((r1-a)*10)+(c1-b);
        ++i;
        a++ ;
        b++ ;
    }

}

void mpawnb( int r1 , int c1 ) // paido black
{
    pbstatus[c1]++;
    
    
    int i;
	
	
	for (i=0;i<100;++i){
		lim[i]=0;
	}
	
	i=0;
	



    if( pbstatus[c1] == 1 )
    {
        if( board[r1-1][c1] == ' ' ){
			lim[i]=((r1-1)*10)+c1;
        	++i;
		}
        if( board[r1-2][c1] == ' ' ){
        	lim[i]=((r1-2)*10)+c1;
        	++i;
    	}
    	
    }
    else
    {
        if(board[r1-1][c1] == ' ' ){
        	lim[i]=((r1-1)*10)+c1;
        	++i;
		}
        if( check2(r1-1 , c1-1) == 1 ){
			lim[i]=((r1-1)*10)+(c1-1);
        	++i;
		}
        if( check2(r1-1 , c1+1) == 1 ){
        	lim[i]=((r1-1)*10)+(c1+1);
        	++i;
    	}
    }

}


//end of artmind





void player1()
{
    int p1 , p2 , c1 , r1 , c2 , r2 , i , j;

    printf( "\nPLAYER 1 - Big Case" ) ;
    printf("\tWHITE KILL: %d\tBLACK KILL: %d\n",killw,killb);
    again1:
    printf( "\nEnter Position of Element to change ( RC ): " ) ;
    scanf( "%d" , &p1 ) ;

    c1 = p1 % 10 ;
    r1 = p1 / 10 ;
    
    
    for (i=0 ; i<100 ; ++i) {
    	lim[i]=0;
	}
    

    switch( board[r1][c1] )
    {
        case 'P': if(ctr == 1)
        {
        	 ThePawn();
        }
		 pawn( r1 , c1 );
                  break ;
                  
        case 'R': if(ctr == 1)
        {
        	TheRook();
        }
		rook( r1 , c1 ) ;
                  break ;
                  
                  
        case 'H': if(ctr == 1) 
        {
        	Thehours();
        }
		horse( r1 , c1 );
                  break ;
                  
                  
        case 'C': if(ctr == 1)
        {
            Thecshop();
        }
		camel( r1 , c1 );
                  break ;
                  
                  
        case 'K':  if(ctr == 1)
		{
		Theking();
	}
		king( r1 , c1 ) ;
                  break ;
                  
                  
        case 'Q': if(ctr == 1)
        {
        	TheQueen();
        }
		queen( r1 , c1 ) ;
                  break ;
                  
        again3:
        default: printf("Invalid Position ! ") ; goto again1 ;
    }

	again5:
	
    printf( "\nEnter Position of Place to Send ( RC ): " ) ;
    scanf( "%d" , &p2 ) ;
	
	i=0;
	j=0;
	for(i=0; i<100 ;++i){
		if(lim[i]==p2){
			break;
		}
		else {
			++j;
		}	
	}
	
	if(j==100){
		printf("Invalid Position !!! Please choose another charcter .");
		goto again1;
	}
	
	
	
    c2 = p2 % 10 ;
    r2 = p2 / 10  ;


    
    if (c1==c2 && r1==r2) {
    	goto again3;
	}
	
	if (check2(r2,c2)==1) {
		printf ("You can not commite suicide !!!");
		goto again5;
	} 
    
    
    if (check(r2,c2)==1){
    	
    	board[r2][c2]=' ';
    	++killw;
    	change(r1,c1,r2,c2);
	}
	else {
		change(r1,c1,r2,c2);
	}
    
    
    
}

void player2()
{
    int p1 , p2 , c1 , r1 , c2 , r2 , i , j;

    printf( "\nPLAYER 2 - Small Case") ;
    printf("\tWHITE KILL: %d\tBLACK KILL: %d\n",killw,killb);
    again2:
    printf( "\nEnter Position of Element to change ( RC ): " ) ;
    scanf( "%d" , &p1 ) ;

    c1 = p1 % 10 ;
    r1 = p1 / 10 ;
    
    
    for (i=0 ; i<100 ; ++i) {
    	lim[i]=0;
	}
    

    switch( board[r1][c1] )
    {
        case 'p': if(ctr == 1)
        {
        	 ThePawn();
        }
		pawnb( r1 , c1 ) ;
                  break ;
        case 'r':if(ctr == 1)
        {
        	TheRook();
        } 
		rook( r1 , c1 ) ;
                  break ;
        case 'h':if(ctr == 1) 
        {
        	Thehours();
        }
		 horse( r1 , c1 ) ;
                  break ;
        case 'c': if(ctr == 1)
        {
            Thecshop();
        }
		camel( r1 , c1 ) ;
                  break ;
        case 'k': if(ctr == 1)
		{
		Theking();
	}
		king( r1 , c1 ) ;
                  break ;
        case 'q': if(ctr == 1)
        {
        	TheQueen();
        }
		queen( r1 , c1 ) ;
                  break ;
                  
        again4:
        default: printf( "Invalid Position ! " ) ; goto again2 ;
    }

	again6:
	
    printf( "\nEnter Position of Place to Send ( RC ): " ) ;
    scanf( "%d" , &p2 ) ;
    
    i=0;
	j=0;
	for(i=0; i<100 ;++i){
		if(lim[i]==p2){
			break;
		}
		else {
			++j;
		}	
	}
	
	if(j==100){
		printf("Invalid Position !!! Please choose another charcter .");
		goto again2;
	}
    
    c2 = p2 % 10 ;
    r2 = p2 / 10  ;


    
    if (c1==c2 && r1==r2) {
    	goto again4;
	}
    
    
    
    if (check(r2,c2)==1) {
    	printf ("You can not commite suicide !!!");
    	goto again6;
	} 
    
    
    if (check2(r2,c2)==1){
    	
    	board[r2][c2]=' ';
    	++killb;
    	change(r1,c1,r2,c2);
	}
	else {
		change(r1,c1,r2,c2);
	}
    
     
    
}



void artmind()
{
	int p1 , p2 , r1 , c1 , r2 , c2 , i , j;
	
	printf( "\nPC - Small Case") ;
    printf("\tWHITE KILL: %d\tBLACK KILL: %d\n",killw,killb);
	
	random:
		
	for (i=0;i<100;++i){
		lim[i]=0;
	}
		
	srand( time( NULL ) );
	
	r1=rand() % 8;
	c1=rand() % 8;
	
	p1=(r1*10)+c1;
	
	switch( board[r1][c1] )
    {
        case 'p':
		mpawnb( r1 , c1 ) ;
                  break ;
                  
        case 'r':
		mrook( r1 , c1 ) ;
                  break ;
                  
        case 'h':
		 mhorse( r1 , c1 ) ;
                  break ;
                  
        case 'c':
		mcamel( r1 , c1 ) ;
                  break ;
        case 'k':
		mking( r1 , c1 ) ;
                  break ;
                  
        case 'q': 
		mqueen( r1 , c1 ) ;
                  break ;
                  
        default: goto random ;
    }
    
    
  
    
    c2=lim[0] % 10;
    r2=lim[0] / 10;
    
    if (check2(r2,c2)==1){
    	
    	board[r2][c2]=' ';
    	++killb;
    	change(r1,c1,r2,c2);
	}
	else {
		change(r1,c1,r2,c2);
	}
    	
}





int check(int x , int y )
{
    switch( board[x][y] )
    {
    case 'p':
    case 'r':
    case 'h':
    case 'c':
    case 'k':
    case 'q': return 1 ; break ;
    default: return 0 ;
    }
}

int check2(int x , int y )
{
    switch( board[x][y] )
    {
    case 'P':
    case 'R':
    case 'H':
    case 'C':
    case 'K':
    case 'Q': return 1 ; break ;
    default: return 0 ;
    }
}

int check3(int x , int y)
{
	if (turn%2==0) {
		return check2(x,y);
	}
	else {
		return check(x,y);
	}
}

