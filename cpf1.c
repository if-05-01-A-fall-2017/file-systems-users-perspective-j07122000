#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, const char* argv[]){
	char data[4000];
	int file = open(argv[1], O_RDWR);
	int file1 = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
	int n = 1;
	while(n != 0){
		n = read(file, data, 4000);

		if(n == 0){
			printf("%s\n", "Copy done");
			close(file);
			close(file1);
		}
		else {
			write(file1, data, n);
		}
	}
	return 0;
}

