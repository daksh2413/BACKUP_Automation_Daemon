/****************************************************************************************************
**      FILENAME      :       struct.h
**
**    DESCRIPTION     :       This File contains the description of struct like time
**                    
**
** Revision History   :
** DATE                NAME                   REASON
**---------------------------------------------------------------------------------------------------
**27 OCT 2022        cguser20           Creation of File , Writing struct..
**
*******************************************************************************************************/

#include<stdio.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>

/*********************************************************************************************************
**
**    STRUCT NAME      :   time
**    DESCRIPTION     :    This struct contains all the data members and member functions for struct time.
**
*********************************************************************************************************/

struct time
{
	int hh;
	int mm;
	int ss;
}backup_given_time;

#endif
