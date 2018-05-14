

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <time.h>

struct stat sb;


void printIt(char* name){
	lstat(name, &sb);
	switch (sb.st_mode & S_IFMT) {
		    case S_IFBLK:  
			printf("b");            
			break;
		    case S_IFCHR:  
			printf("c");        
			break;
		    case S_IFDIR:  
			printf("d");               
			break;
		    case S_IFIFO:  
			printf("f");               
			break;
		    case S_IFLNK:  
			printf("l");                 
			break;
		    case S_IFREG:  
			printf("-");            
			break;
		    case S_IFSOCK: 
			printf("s");                  
			break;
		    default:       
			printf("u");               
			break;
	    }

	(sb.st_mode & S_IRUSR) ? printf("r") : printf("-");
	(sb.st_mode & S_IWUSR) ? printf("w") : printf("-");	
	(sb.st_mode & S_IXUSR) ? printf("x") : printf("-");
	(sb.st_mode & S_IRGRP) ? printf("r") : printf("-");
	(sb.st_mode & S_IWGRP) ? printf("w") : printf("-");
	(sb.st_mode & S_IXGRP) ? printf("x") : printf("-");
	(sb.st_mode & S_IROTH) ? printf("r") : printf("-");
	(sb.st_mode & S_IWOTH) ? printf("w") : printf("-");
	(sb.st_mode & S_IXOTH) ? printf("x ") : printf("- ");

	printf("%5ld%5ld %9lld", (long)sb.st_uid, (long)sb.st_gid, (long long)sb.st_size);
	struct tm *dateTime;
	dateTime = gmtime(&sb.st_mtime);
	printf("%6d-%02d-%02d-%02d-%02d ", (dateTime->tm_year+1900), dateTime->tm_mon + 1, 
					dateTime->tm_mday, dateTime->tm_hour + 1, 
					dateTime->tm_min + 1);
	printf("%s\n", name);
	
}



int main(int argc, const char* argv[]){
	DIR *dir;
	struct dirent *file;

	char buf[512];
	if(argv[1] == NULL){
 		dir = opendir(".");
	}
	else{
		dir = opendir(argv[1]);
	}

	while((file = readdir(dir)) != NULL)
	{
		printIt(file->d_name);
	}
	closedir(dir);
}

