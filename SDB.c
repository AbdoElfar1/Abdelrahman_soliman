#include "SDB.h" // include the struct and the typedef

static uint32 k = 0;
static student Students[SIZE];

// this function will get the data are full or not in the data base.

boolean SDB_isFull()
{
    if(k < 3)      // min. size of data
        return false;
    uint32 i = 0;
    while(i < k)
    {
        if(i == SIZE-1)
            return true;
        i++;
    }
    return false;
}

// this function get how many data was add.

uint8 SDB_GetUsedSize()
{
    uint8 count = 0;
    while(count < k)
        count++;
    return count;
}

// this function will add data for student.

boolean SDB_AddEntry()
{
    if(k < SIZE)
    {
        printf("======================================================================================================\n\n");
        printf("enter student ID     : ");
        scanf("%u", &Students[k].Student_ID);

        printf("enter Student Year   : ");
        scanf("%u", &Students[k].Student_year);

        printf("enter Course_1 ID    : ");
        scanf("%u", &Students[k].Course1_ID);

        printf("enter Course_1 grade : ");
        scanf("%u", &Students[k].Course1_grade);

        printf("enter Course_2 ID    : ");
        scanf("%u", &Students[k].Course2_ID);

        printf("enter Course_2 grade : ");
        scanf("%u", &Students[k].Course2_grade);

        printf("enter Course_3 ID    : ");
        scanf("%u", &Students[k].Course3_ID);

        printf("enter Course_3 grade : ");
        scanf("%u", &Students[k].Course3_grade);
        printf("======================================================================================================\n\n");

        k++;
        return true;
    }
    else
        return false;
}

// delete student.

void SDB_DeletEntry (uint32 id)
{
    uint32 i = 0;
    uint32 j = 0;
    while(i < k)
    {
        if(Students[i].Student_ID == id)
        {
            j = i;
            while(j < k)
            {

                Students[j] = Students[j + 1];
                j++;
            }
            k--;
            break;
        }
        i++;
    }
}

// too read the data with student ID.

boolean SDB_ReadEntry(uint32 id)
{
    uint32 i = 0;
    while(i < k)
    {
        if(Students[i].Student_ID == id)
        {
            printf("======================================================================================================\n\n");
            printf("   student ID     : %u\n",Students[i].Student_ID);
            printf("   Student Year   : %u\n",Students[i].Student_year);
            printf("   Course_1 ID    : %u\n",Students[i].Course1_ID);
            printf("   Course_1 grade : %u\n",Students[i].Course1_grade);
            printf("   Course_2 ID    : %u\n",Students[i].Course2_ID);
            printf("   Course_2 grade : %u\n",Students[i].Course2_grade);
            printf("   Course_3 ID    : %u\n",Students[i].Course3_ID);
            printf("   Course_3 grade : %u\n",Students[i].Course3_grade);
            printf("======================================================================================================\n\n");
            return true;
        }
        i++;
    }
    return false;
}

// i don't know the description so i make it like too get the list of all add students.

void SDB_GetList()
{
    uint32 i = 0;
    printf("                                   the data base \n");
    printf("======================================================================================================\n\n");
    printf("|ID   |Year   |Corse1_ID   |Corse1_grade   |Corse2_ID   |Corse2_grade   |Corse3_ID   |Corse3_grade   |\n");
    while(i < k)
    {
    printf("|%-5d|%-7d|%-12d|%-15d|%-12d|%-15d|%-12d|%-15d|\n",Students[i].Student_ID\
               ,Students[i].Student_year\
               ,Students[i].Course1_ID\
               ,Students[i].Course1_grade\
               ,Students[i].Course2_ID\
               ,Students[i].Course2_grade\
               ,Students[i].Course3_ID\
               ,Students[i].Course3_grade);
        i++;
    }
    printf("======================================================================================================\n\n");
}

// check the id is in the data base or not.

boolean SDB_isidExist(uint32 id)
{
    uint32 i = 0;
    while(i < k)
    {
        if(Students[i].Student_ID == id)
            return true;
        i++;
    }
    return false;
}

// this function not in project i make it for just sort the data for the design output. :)

void SORRT()
{
    for(uint32 i = 0; i<k ;i++)
        for(uint32 j = 0 ; j<k-1 ;j++)
        {
            if(Students[j].Student_ID > Students[j+1].Student_ID)
            {
                student Temp;
                Temp = Students[j];
                Students[j] = Students[j + 1];
                Students[j + 1] = Temp;
            }

        }
}
