#include<time.h>
#include<stdio.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
/*creating structure for the backup time*/
struct time
{
        int hh;
        int mm;
        int ss;
}backup_given_time;


/*creating daemon process function*/
int daemon_backup(int nochdir,int noclose)
{
        pid_t pid;
        pid=fork();
        if(pid<0)
        {
                exit(EXIT_FAILURE);
        }
        if(pid>0)
        {
                exit(EXIT_SUCCESS);
        }
        return 0;
}


/*main function*/
int main(int argc, char *argv[])
{
	/*calling daemon process function*/
	daemon_backup(0,0);                                      
	
	
	struct tm *ptr;
        int flag=0;
        time_t backup_time;
        backup_time=time(NULL);
        ptr=localtime(&backup_time);
	
	
	/*set backup time to variable*/
        backup_given_time.hh=20;
        backup_given_time.mm=00;
        backup_given_time.ss=00;
        while(1)
        {
        	if(2 != argc)
        	{
               		printf("\n Please pass in the directory name \n");
               		return 1;
        	}

        	DIR *source_dp = NULL;
        	struct dirent *dptr = NULL;

        	
        	/*Open the directory stream*/
        	if(NULL == (source_dp = opendir(argv[1])))
        	{
             		printf("\n Cannot open Input directory [%s]\n",argv[1]);
         		exit(0);
                	
        	}
        	else
        	{
        		/*compare backup time with system time*/
        		if(backup_given_time.hh<=ptr->tm_hour )
        		{
                		char linebuffer[400];
                		printf("\n The contents of directory [%s] are as follows \n",argv[1]);
               			
               			
               			/*read the directory contents*/
				while(NULL != (dptr = readdir(source_dp)))
		        	{
		                	printf(" %s ",dptr->d_name);
		                	char target[200];
		                	
		                	
		                	/*copy and concatenate the files in target*/
		                	strcpy(target, "/home/daksh/Desktop/backup/");
		                	strcat(target, dptr->d_name);

		                	if( dptr-> d_type == DT_REG)
		                	{
		                		
		                		
		                		/*open and read the contents of current source file and write in source file*/ 
		                        	FILE* fp_source_file = fopen (dptr->d_name, "r");
		                        	FILE* fp_target_file = fopen(target, "w");

		                        	while(fgets(linebuffer, 400, fp_target_file) != NULL )
		                        	{
		                               		fputs(linebuffer, fp_target_file);
		                        	}
		                        	
		                        	
		                        	/*close source file and target file*/
				                fclose(fp_source_file);
				                fclose(fp_target_file);
				                flag=1;
				        	if(flag==1)
			 			{
			       				printf("\n backup Success");
				       		}
			       		}	
                 		}
                 	}              	   
                	else
			{
			printf("\n backup Failure");
			}
			
			
			/*Close the directory stream*/
			closedir(source_dp);
                	
                	
                	/*Remove the new directory created by us*/
                	printf("\n");
                	break;             		
                }
	}
        
        
        /*sleep daemon process for 60 min*/      
        sleep(3600);
}
