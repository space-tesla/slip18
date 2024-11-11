/*Write a C program to create an unnamed pipe. The child process will write the following three messages to the pipe, and the parent process will display them.*/
/*Messages:

Message1 = "Hello World"
Message2 = "Hello SPPU"
Message3 = "Linux is Funny"*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pipe_fd[2];
    pid_t pid;
    char message[100];

    pipe(pipe_fd);
    pid = fork();

    if (pid == 0) {
        close(pipe_fd[0]);
        write(pipe_fd[1], "Hello World\n", 12);
        write(pipe_fd[1], "Hello SPPU\n", 11);
        write(pipe_fd[1], "Linux is Funny\n", 15);
        close(pipe_fd[1]);
        exit(0);
    } else {
        close(pipe_fd[1]);
        while (read(pipe_fd[0], message, sizeof(message)) > 0) {
            printf("%s", message);
        }
        close(pipe_fd[0]);
    }

    return 0;
}






/*Hello World
Hello SPPU
Linux is Funny
*/