 /*
 ============================================================================
 Name        : ACS126 C Programming Assignment-006
 Author      : Gary Yee Siew Wah
 Copyright   : 2016
 Reg. No.    : 150144216
 Date        : 20th April 2016
 Description : Input matrice, transpose the matrice and delete the row and column
               of submatrice.
 ============================================================================
 */
 
 /*Libraries*/
#include<stdio.h>
#include<stdlib.h>

/*List of functions*/
struct matrix
{
   char name;            // hold 1 char of the matrix
   int mValues[10][10];  // hold values of 2d array
   int nrows;            // hold number of rows in mvalues
   int ncols;            // hold number of columns in mvalues
};
void matrixinput(struct matrix *mat);                                           // to input the size of the matrice, the name of the array and values in 2d array
void matrixDisplay(struct matrix mat);                                          // to display the name of the array and the values of 2d array
void matrixTranspose(struct matrix m1, struct matrix *m2);                      // to transpose matrix m1 and store new matrix m2
void subMatrix(struct matrix m1, struct matrix *m2);                            // to input one or more row numbers and more column numbers 

////////////////////////////////////////////////////////////////////////////////


/*The main function*/
int main()
{ 
    /* Set initial integer for try again*/
    int tryagain;
    
      /* This loop help the user wish to try again or exit the loop*/
	do{
      
      /* Initialise the struct prototypes*/
      struct matrix m1,m2;
      struct matrix mat;
      
      /* Initialise the matrice functions*/
      matrixinput(&mat);
      matrixDisplay(mat);
      matrixTranspose(mat,&m2);
      matrixDisplay(m2);
      subMatrix(mat,&m2);
      matrixDisplay(m2);
      
        /* print the description*/
      puts("would you like to input another matrix?( type 1 for yes or type 0 for no):");
      scanf("%d",&tryagain);                                                    // input the integer for try again 
      puts("\n");                                                               // print new line
     }while(tryagain!=0);                                                       // while use to check if the user does want or not to cntinue 
     system("pause");                                                           // pause the program
}

////////////////////////////////////////////////////////////////////////////////


/* void matrix input function*/
void matrixinput(struct matrix *mat)
{ 
 /* Set initial integer values*/
    int i,j;

  /* Prompt the user to input value if out of range it allow user to re-input value*/
         do{
         puts("Please enter the number of rows in matrix (>0 and <= 10):");     // print the description 
         scanf("%d" ,&mat->nrows);                                              // input the value for nrows as input mat matrice
         }while(mat->nrows<=0 || mat->nrows > 10);                              // check  the range of the nrows value
  
  /* Prompt the user to input value if out of range it allow user to re-input value*/
         do{
         puts("Please enter the number of columns in matrix (>0 and <= 10):");  // print the description 
         scanf("%d",&mat->ncols);                                               // input the value for nrows as input mat matrice
         }while(mat->ncols<=0 || mat->ncols > 10);                              // check  the range of the nrows value

  /* Prompt the user to input char if out of range it allow user to re-input value*/
         printf("Please enter a one character name for the matrix, e.g. A,B,etc: ");  // print description
         scanf(" %c",&mat->name);                                                     // input char 
         printf("\nPlease enter the contents of matrix ");                            // print the description
         printf("%c",mat->name);                                                      // print the char 
         printf(" one row at the time\n");                                            // continue print the description from previous 
   
   /* This loop helps to input the value for matrix*/
        for(i = 0; i < mat->nrows; i++)                                         // increment the row until the user input the row
        { 
        printf("Row %d:  ",i);                                                  // print the increment row in ascending order
        for(j = 0; j < mat->ncols ; j++)                                        // increment the column until the user input the column
        {
        scanf("%d",&mat->mValues[i][j]);                                        // input the values into the new matrice
       }
       }
       printf("you entered this matrix %c: \n", mat->name);                     // print the description with char
}

////////////////////////////////////////////////////////////////////////////////

/* void matrix display function*/
void matrixDisplay(struct matrix mat)
{   /* set initial integer values*/
    int i,j;

  
    for(i=0; i< mat.nrows; i++)                                                 // increment the value i for loop
   {
    printf("Row %d: ",i);                                                       // print the row in ascending order
    for(j=0; j< mat.ncols; j++)                                                 // increment the value j for loop
{
    printf("\t%d ",mat.mValues[i][j]);                                          // print the 2d array also known as matrice
}
    printf("\n");                                                               // put new line
}
}

////////////////////////////////////////////////////////////////////////////////

/* void matrix transpose function*/
void matrixTranspose(struct matrix m1, struct matrix *m2)
{
/* set initial integer values*/
    int i,j;
    int nwi,nwj;
    
     /* print the description */
    printf(" Transposing matrix \n");                                                         // print the description
    printf(" please enter a one character name for the transposed matrix, e.g. A,B, etc: ");  // print the description
    scanf("%s",&m2->name);                                                                    // input the char 
    printf(" Matrice %c is:\n",m2->name);                                                     // print the matrice and 
    
 // remodel the matrice such as changing the shape or dimension of matrice such as 3 x 4 into 4 x 3
    m2->nrows=m1.ncols;      
    m2->ncols=m1.nrows;
    
    /* print the description */
    for(i=0,nwi=0;i<m1.nrows,nwi<m1.nrows; i++,nwi++)                           // set the initial values for i and nwi then increment until the input
    for(j=0,nwj=0;j<m1.ncols,nwj<m1.ncols; j++,nwj++)                           // set the initial values for j and nwj then increment until the input
    {
    m2->mValues[nwj][nwi]= m1.mValues[i][j];                                    // create new transpose matrice from the input matrice
    }
    return;                                                                     // return the matrice to the main fucntion
    
}

////////////////////////////////////////////////////////////////////////////////

// delete the rows and columns from input matrix not transpose matrix
void subMatrix(struct matrix m1, struct matrix *m2)
{    
      /* set initial values for integer */
     int rows[10]={0},delrows;                                                  // rows[10] push the value from first to second so it can look for next value
     int cols[10]={0},delcols;                                                  // cols[10] push the value from first to second so it can look for next value
     int x,y;
     int i,j;
     int nwi=0,nwj;	
     printf(" Forming a submatrix of matrix %c \n",m1.name);                    // print the description
     
     /* Prompt the user to input value if out of range it allow user to re-input value*/
     do{
        printf(" how many rows do you want to delete? (must be between 1 and %d):",m1.nrows);   // print the description
        scanf("%d",&delrows);                                                                   // input the value
        }while(delrows< 1 || delrows > m1.nrows);                                               // check the condition if it is out of range
             
    printf("\nplease enter one per row, the number(s) of the %d rows you wish to delete ",delrows); // print the description
     
     /* Prompt the user to input value but does not re-input the value again*/
	 for(i=0;i < delrows;i++)
	{ 
        printf("\nenter row number to delete( must be between 0 and %d):",(m1.nrows-1));      // print the description
        scanf("%d",&x);                                                                       // input the value
        rows[x]=1;          // eliminate one of rows
    }
     
     /* Prompt the user to input value if out of range it allow user to re-input value*/         
    do{
       printf(" how many columns do you want to delete? (must be between 1 and %d):",m1.ncols); // print the description
       scanf("%d",&delcols);                                                                    // input the value
       }while(delcols< 1 || delcols > m1.ncols);                                                // check the condition if it is out of range
		  
	printf("\nplease enter one per columns, the number(s) of the %d columns you wish to delete ",delcols);    // print the description
	   
    /* Prompt the user to input value but does not re-input the value again*/
	   for(i=0;i<delcols;i++) 
	   {
              printf("\nenter column number to delete( must be between 0 and %d):",(m1.ncols-1)); // print the description
              scanf("%d",&y);                                                                     // input the value
              cols[y]=1;    // eliminate one of columns
       }
    	
    	printf(" please enter a one character name for the submatrix, e.g. A,B, etc: ");         // print the description 
        scanf(" %c",&m2->name);                                                                  // input the char
        printf(" Matrice %c is:\n",m2->name);                                                    // print the description with char
				  
		
    m2->ncols = m1.ncols -delcols;     // this will create new column such as initial column is 5 then delete by 2 gives 3 column
	m2->nrows = m1.nrows -delrows;     // this will create new row such as inital row is 5 then delete by 2 gives 3 rows
	    
	for(i=0; i< m1.nrows;i++)          // increment the rows
 {  nwj=0;                             // set the integer nwj to 0
    
    for(j=0; j< m1.ncols; j++)         // increment the columns 
    {  
    if (cols[j]) continue;            // continue used to skip the process inside the loop and return back to the initial for loop 
     m2->mValues[nwi][nwj]=m1.mValues[i][j];nwj++;  // this set the new matrice from the input matrice and increment the nwj
    }  
    
    if (rows[i]) continue;  // continue used to skip the process inside the loop and return to the for loop
           nwi++;           // increment the nwi integer    
 }
	 puts("");             // put new line
	 return;               // return the new matrix to main function
}

////////////////////////////////////////////////////////////////////////////////
