# Pipes, Forks, and Dups

## Introduction
This guide covers the fundamental concepts behind inter-process communication (IPC) using pipes, process creation with `fork()`, and file descriptor duplication with `dup2()`. These concepts are essential for understanding how Unix-like operating systems manage processes and data flow between them.

## Concepts Covered
- **Pipes (`pipe()`)**: Used for unidirectional data communication between processes.
- **Forking (`fork()`)**: Creates child processes that execute independently.
- **File Descriptor Duplication (`dup()` and `dup2()`)**: Redirects standard input/output for better control over process execution.

## Understanding Pipes
A pipe is a unidirectional communication channel between two processes. It can be created using:
```c
int fd[2];
pipe(fd);
```
Where:
- `fd[0]` is the read end of the pipe.
- `fd[1]` is the write end of the pipe.

## Using Fork to Create Processes
The `fork()` system call creates a new child process that shares the same code as the parent process but executes separately.
```c
pid_t pid = fork();
if (pid == 0) {
    // Child process
} else {
    // Parent process
}
```

## Redirecting Input/Output with Dup2
The `dup2()` system call is used to duplicate file descriptors, allowing redirection of standard input/output.
```c
dup2(fd[1], STDOUT_FILENO);
```
This ensures that output is written into the pipe instead of the standard output.

## Example: Implementing a Simple Pipeline
To execute:
```sh
ls | wc -l
```
We can use:
```c
pipe(fd);
if (fork() == 0) {
    dup2(fd[1], STDOUT_FILENO);
    close(fd[0]);
    execlp("ls", "ls", NULL);
} else {
    dup2(fd[0], STDIN_FILENO);
    close(fd[1]);
    execlp("wc", "wc", "-l", NULL);
}
```

## Further Reading
- [Original Guide by Roz Michelle](https://www.rozmichelle.com/pipes-forks-dups/?source=post_page-----71984b3f2103--------------------------------#pipelines)
- [man pipe](https://man7.org/linux/man-pages/man2/pipe.2.html)
- [man fork](https://man7.org/linux/man-pages/man2/fork.2.html)
- [man dup2](https://man7.org/linux/man-pages/man2/dup.2.html)



