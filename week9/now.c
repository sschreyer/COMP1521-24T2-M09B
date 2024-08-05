#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <spawn.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

// extern means the variable is defined somewhere else.
// In this case, the variable is defined by the system environment.
extern char **environ;

// Spawns a process and waits for it to die.
// Input is the argv array of the process function.
void spawn_and_wait(char **args)
{
    pid_t pid;
    int spawn_status = posix_spawn(&pid, args[0], NULL, NULL, args, environ);
    if (spawn_status != 0) {
        errno = spawn_status;
        perror("posix_spawn");
        exit(EXIT_FAILURE);
    }

    int spawned_process_exit_status;
    if (waitpid(pid, &spawned_process_exit_status, 0) == -1) {
        fprintf(stderr, "%s: ", args[0]);
        perror("Failed to wait for process");
        exit(EXIT_FAILURE);
    }

    printf("Exited with status %d\n", WEXITSTATUS(spawn_exit_status));
}

int main(int argc, char *argv[])
{
    // Creates an array of strings for the input argv of each function.
    // NULL terminated to mark the end of the argument list.
    char *date_argv[] = {"/bin/date", "+%d-%m-%Y", NULL};
    // Run the date program with the argument "+%d-%m-%Y".
    spawn_and_wait(date_argv);

    char *time_argv[] = {"/bin/date", "+%T", NULL};
    // Run the time program with argument "+%T".
    spawn_and_wait(time_argv);

    char *user_argv[] = {"/usr/bin/whoami", NULL};
    spawn_and_wait(user_argv);

    // The -f flag is short for 'full': print full output, not shortened.
    char *hostname_argv[] = {"/bin/hostname", "-f", NULL};
    spawn_and_wait(hostname_argv);

    char *working_dir_argv[] = {"/usr/bin/realpath", ".", NULL};
    spawn_and_wait(working_dir_argv);
}