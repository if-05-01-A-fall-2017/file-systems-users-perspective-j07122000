
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

int main(int argc, const char* argv[]){
	struct stat sb;
	lstat(argv[1], &sb);

	printf("File type:                ");
	switch (sb.st_mode & S_IFMT) {
		    case S_IFBLK:  
			printf("block device\n");            
			break;
		    case S_IFCHR:  
			printf("character device\n");        
			break;
		    case S_IFDIR:  
			printf("directory\n");               
			break;
		    case S_IFIFO:  
			printf("FIFO/pipe\n");               
			break;
		    case S_IFLNK:  
			printf("symlink\n");                 
			break;
		    case S_IFREG:  
			printf("regular file\n");            
			break;
		    case S_IFSOCK: 
			printf("socket\n");                  
			break;
		    default:       
			printf("unknown?\n");               
			break;
	    }

	
	printf("Access-privileges:        ");
	(sb.st_mode & S_IRUSR) ? printf("r") : printf("-");
	(sb.st_mode & S_IWUSR) ? printf("w") : printf("-");	
	(sb.st_mode & S_IXUSR) ? printf("x") : printf("-");
	(sb.st_mode & S_IRGRP) ? printf("r") : printf("-");
	(sb.st_mode & S_IWGRP) ? printf("w") : printf("-");
	(sb.st_mode & S_IXGRP) ? printf("x") : printf("-");
	(sb.st_mode & S_IROTH) ? printf("r") : printf("-");
	(sb.st_mode & S_IWOTH) ? printf("w") : printf("-");
	(sb.st_mode & S_IXOTH) ? printf("x\n") : printf("-\n");

	printf("inode-Number:             %ld\n", (long) sb.st_ino);
	printf("Device numbers:           dev=%ld; rdev=%ld\n", sb.st_dev, sb.st_rdev);
	printf("Links count:              %ld\n", (long) sb.st_nlink);
	printf("UID:                      %ld\n",(long) sb.st_uid);
	printf("GID:                      %ld\n",(long) sb.st_gid);
	printf("File size:                %lld bytes\n",(long long) sb.st_size);
	printf("Last access:              %s", ctime(&sb.st_atime));
	printf("Last modification:        %s", ctime(&sb.st_mtime));
        printf("Last inode change:        %s", ctime(&sb.st_ctime));

}