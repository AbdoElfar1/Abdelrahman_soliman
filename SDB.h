#ifndef _SDB_
#define _SDB_

#include <stdio.h>
#include <stdlib.h>
#include "STD.h"
#define SIZE 10

typedef struct SimpleDb
{

    uint32 Student_ID;
    uint32 Student_year;
    uint32 Course1_ID;
    uint32 Course1_grade;
    uint32 Course2_ID;
    uint32 Course2_grade;
    uint32 Course3_ID;
    uint32 Course3_grade;

} student;



boolean SDB_isFull();
uint8 SDB_GetUsedSize();
boolean SDB_AddEntry();
void SDB_DeletEntry (uint32 id);
boolean SDB_ReadEntry(uint32 id);
boolean SDB_isidExist(uint32 id);
void SORRT();
void SDB_GetList();
void SDB_action(uint8 choice);

#endif // _SDB_
