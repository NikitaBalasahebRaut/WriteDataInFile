// Application to create new file and write the data into the file

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include <string.h>

int main()
{
	char name[30] = {'\0'};
	char data[50] = {'\0'};
	int fd = 0;
	int length = 0;
	int iRet = 0;
	
	printf("Enter the file name \n");
	scanf("%s",name);
	
	fd = open(name,O_RDWR | O_CREAT , 0777);
	
	if(fd == -1)
	{
		 printf("Unable to create the file \n");
	}
	else
	{
		printf("file successfully created with fd : %d\n",fd);
	}
	
	printf("Enter the data to write into the file \n");
	scanf(" %[^'\n']s",data);
	
	length = strlen(data);
	
	iRet = write(fd,data,length);
	
	if(iRet == -1)
	{
		printf("Unable to write data into the file \n");
	}
	else
	{
		printf("data  successfully written in the file: %d ",iRet);
	}
	
	return 0;
}

/*

output

Enter the file name
MyData.txt
file successfully created with fd : 3
Enter the data to write into the file
my name is nikita i am from india
data  successfully written in the file
D:\ProgramTopicWise\LB\8File_Handling\WriteDataInFile>gcc Write.c -o myexe

D:\ProgramTopicWise\LB\8File_Handling\WriteDataInFile>myexe
Enter the file name
marvellous
file successfully created with fd : 3
Enter the data to write into the file
india is my country
data  successfully written in the file: 19

*/