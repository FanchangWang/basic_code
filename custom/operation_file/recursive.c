#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

void readFileList(char *basePath) {
	DIR *dir;
	struct dirent *ptr;

	if ((dir=opendir(basePath)) == NULL)
	{
		perror("Open dir error...");
		exit(1);
	}

	while ((ptr=readdir(dir)) != NULL)
	{
		if(strcmp(ptr->d_name,".")==0 || strcmp(ptr->d_name,"..")==0)    ///current dir OR parrent dir
			continue;
		else if(ptr->d_type == 8)    ///file
			printf("d_name:%s/%s\n",basePath,ptr->d_name);
		else if(ptr->d_type == 10)    ///link file
			printf("d_name:%s/%s\n",basePath,ptr->d_name);
		else if(ptr->d_type == 4)    ///dir
		{
			char base[256];
			memset(base,'\0',sizeof(base));
			strcpy(base,basePath);
			strcat(base,"/");
			strcat(base,ptr->d_name);
			readFileList(base);
		}
	}
	closedir(dir);
}

int main(void) {
	char * path = "/home/dio/Desktop/test";
	readFileList(path);
	//    DIR *dir;
	//    char basePath[1000];
	//
	//    ///get the current absoulte path
	//    memset(basePath,'\0',sizeof(basePath));
	//    getcwd(basePath, 999);
	//    printf("the current dir is : %s\n",basePath);
	//
	//    ///get the file list
	//    memset(basePath,'\0',sizeof(basePath));
	//    strcpy(basePath,"./XL");
	//    readFileList(basePath);
	return 0;
}
