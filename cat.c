#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

int readFile(char name[]){
    int file = open(name, O_RDONLY);

    if (file == -1){
        perror("Error opening the file");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;

    while ((bytesRead = read(file, buffer, sizeof(buffer))) > 0){
        if (write(STDOUT_FILENO, buffer, bytesRead) != bytesRead) {
            perror("Error writing to stdout");
            close(file);
            return 1;
        }
    }

    if (bytesRead == -1) {
        perror("Error reading from file");
        close(file);
        return 1;
    }

    close(file);
    return 0;

}

int main(int argc, char *argv[]){

    if (argc == 2){
        readFile(argv[1]);
    }

    else if (argc > 2) {
        printf("Error: Please provide only one filename.\n");
        printf("Usage: %s <filename>\n", argv[0]);
        return -1;
    }

    else {
        printf("Error: Please provide a filename.\n");
        printf("Usage: %s <filename>\n", argv[0]);
        return -1;
    }
}
