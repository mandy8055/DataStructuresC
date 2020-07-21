#include <stdio.h>
#include <stdlib.h>
#define FAIL 1

int main(void)
{
    int *piBuffer = NULL; //pointer to integer
    int nRow = 0;         //variable store number of Row
    int nColumn = 0;      //variable store number of Row
    int iRow = 0;         //Variable for looping Row
    int iCol = 0;         //Variable for looping column
    printf("\nEnter the number of Row = ");
    scanf("%d", &nRow); //Get input for number of Row
    printf("\nEnter the number of Column = ");
    scanf("%d", &nColumn); //Get input for number of Column
    //Allocate memory for row
    piBuffer = (int *)malloc(nRow * nColumn * sizeof(int));
    //Check memory validity
    if (piBuffer == NULL)
    {
        return FAIL;
    }
    //Copy 5 in 2d Array
    for (iRow = 0; iRow < nRow; iRow++)
    {
        for (iCol = 0; iCol < nColumn; iCol++)
        {
            scanf("%d", &piBuffer[iRow * nColumn + iCol]);
        }
    }
    //Print the content of 2D array
    for (iRow = 0; iRow < nRow; iRow++)
    {
        for (iCol = 0; iCol < nColumn; iCol++)
        {
            printf("\npiBuffer[%d][%d] = %d\n", iRow, iCol, piBuffer[iRow * nColumn + iCol]);
        }
    }

    //free the allocated memory
    free(piBuffer);

    return 0;
}