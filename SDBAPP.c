#include "SDB_APP.h"

void SDB_App()
{
    uint32 answer = 0;
    do{
        printf("======================================================================================================\n\n");
        printf("1.To add entry, enter 1\n");
        printf("2.To get used size in data base, enter 2\n");
        printf("3.To read student data, enter 3\n");
        printf("4.To get the list of all student iDs, enter 4\n");
        printf("5.To check is ID is existed, enter 5\n");
        printf("6.To delete student data, enter 6\n");
        printf("7.To check is database is full, enter 7\n");
        printf("8.To exit, enter 0\n");
        printf("======================================================================================================\n\n");
        printf("your choise is : ");
        scanf("%d", &answer);
        SDB_action( (uint8) answer);
    }while(answer != 0);
}

void SDB_action(uint8 choice)
{
    boolean cheak = false;
    uint32 kount = 0;
    uint32 ID = 0;

    switch(choice)
        {
            case 1:
            {
                cheak = SDB_AddEntry();
                if(cheak)
                    printf("successful add cheak now is %d \n", cheak);
                else
                    printf("sorry the memory cant allocated cheak now is %d \n", cheak);
                break;
            }


            case 2:
            {
                kount = SDB_GetUsedSize();
                printf("the count is %d \n",((uint8) kount);
                break;
            }


            case 3:
            {
                printf("enter the ID that you want to see the data of it : ");
                scanf("%u", &ID);
                cheak = SDB_ReadEntry(ID);
                if(cheak)
                    printf("Found the data cheak now is %d \n", cheak);
                else
                    printf("sorry cant find the data cheak now is %d \n", cheak);
                break;
            }

            case 4:
            {
                SORRT();
                SDB_GetList();
                break;
            }

            case 5:
            {
                printf("enter the ID that you want to see ID is exist or not : ");
                scanf("%u", &ID);
                cheak = SDB_isidExist(ID);
                if(cheak)
                    printf("successful the data is Exist cheak now is %d \n", cheak);
                else
                    printf("sorry the data not Exist cheak now is %d \n", cheak);
                break;
            }


            case 6:
            {
                printf("enter the ID that you want to delete data : ");
                scanf("%u", &ID);
                SDB_DeletEntry (ID);
                break;
            }


            case 7:
            {
                cheak = SDB_isFull();
                if(cheak)
                    printf("no speace cheak now is %d \n", cheak);
                else
                    printf("ther some speace cheak now is %d \n", cheak);
                break;
            }

            case 0: break;

            default:
                printf("choose again\n");
        }
}
