*This project has been created as part of the 42 curriculum by aprivalo.*

# Pipex

## Description

Pipex is a project from the 42 school whose objective
is to reproduce the behavior of pipes in the Bash shell.

The program must execute two commands using a pipe between them,
redirecting the input from a file and the output to another file.

It reproduces the behavior of the following shell command:

```bash
< infile cmd1 | cmd2 > outfile
````

Which corresponds to the following execution:

```bash
./pipex infile "cmd1" "cmd2" outfile
```


## Instructions

The program must:

1. Open the input file (`infile`)
2. Create a pipe
3. Execute the first command (`cmd1`) with `infile` as input
4. Send the output of `cmd1` to the pipe
5. Execute the second command (`cmd2`) reading from the pipe
6. Redirect the final output to `outfile`


### Example

Equivalent command in the shell:

```bash
< infile cat -e | wc -l > outfile
```

Execution with pipex:

```bash
./pipex infile "cat -e" "wc -l" outfile
```


### Compilation

Compile with:

```bash
make
```

Available commands:

```bash
make
make clean
make fclean
make re
```


## Resources

The following resources were used to complete this project:

* manual pages (`man`)
* Unix documentation about pipes and file descriptors
* explanatory videos on YouTube about pipes and `execve`
* my personal *libft* library
* use of AI to deepen understanding of some complex concepts and
  to better understand certain shell behaviors during testing
