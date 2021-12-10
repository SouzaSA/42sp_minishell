# **minishell**

In this project the idea is dive a little deeper inside the linux world creating a simplified shell, a command line user interface, to interact with operating system.

## Mandatory

To achieve the goal the minishell must: (from minishell subject version 6)

- Not interpret unclosed quotes or unspecified special characters like **\\** or **;**.
- Not use more than one global variable, think about it and be ready to explain why you do it.
- Show a prompt when waiting for a new command.
- Have a working History.
- Search and launch the right executable (based on the PATH variable or by using relative or absolute path)
- It must implement the builtins:
	- **echo** with option -n
	- **cd** with only a relative or absolute path
	- **pwd** with no options
	- **export** with no options
	- **unset** with no options
	- **env** with no options or arguments
	- **exit** with no options
- **'** inhibit all interpretation of a sequence of characters.
- **"** inhibit all interpretation of a sequence of characters except for $.
- Redirections:
	- **<** should redirect input.
	- **>** should redirect output.
	- **<<** read input from the current source until a line containing only the delimiter is seen. it doesn’t need to update history!
	- **>>** should redirect output with append mode.
- Pipes **|** The output of each command in the pipeline is connected via a pipe to the input of the next command.
- Environment variables (**\$** followed by characters) should expand to their values.
- **$?** should expand to the exit status of the most recently executed foreground
pipeline.
- **ctrl-C** **ctrl-D** **ctrl-\\** should work like in bash.
- When interactive:
	- **ctrl-C** print a new prompt on a newline.
	- **ctrl-D** exit the shell.
	- **ctrl-\\** do nothing.

*obs.: **readline** function can produce some leak you don’t need to fix this.*

## Bonus

To achieve the bonus the minishell must: (from minishell subject version 6)

- **&&**, **||** with parenthesis for priorities.
- the wildcard *\** should work for the current working directory.


## External Allowed Functions

| function | description | header |
|----------|-------------|--------|
| readline | get a line from a user with editing | stdio.h <br> readline/readline.h <br> readline/history.h |
| rl_clear_history | clear the history list by deleting all of the entries |
| rl_on_new_line | tell the update functions that we have moved onto a new (empty) line | stdio.h <br> readline/readline.h <br> readline/history.h |
| rl_replace_line | replace the contents of rl_line_buffer with text | stdio.h <br> readline/readline.h <br> readline/history.h |
| rl_redisplay | if non-zero, Readline will call indirectly through this pointer to update the display with the current contents of the editing buffer | stdio.h <br> readline/readline.h <br> readline/history.h |
| add_history | Place string at the end of the history list | stdio.h <br> readline/readline.h <br> readline/history.h |
| printf | format and print data | stdlib.h |
| malloc | allocate dynamic memory | stdlib.h |
| free | free dynamic memory | stdlib.h |
| write | write to a file descriptor | unistd.h |
| access | check user's permissions for a file | unistd.h |
| open | open and possibly create a file | fcntl.h |
| read | read from a file descriptor | unistd.h |
| close | close a file descriptor | unistd.h |
| fork | create a child process | sys/types.h <br> unistd.h |
| wait <br> waitpid | wait for process to change state | sys/types.h <br> sys/wait.h |
| wait3 <br> wait4 | wait for process to change state, BSD style | sys/types.h <br> sys/time.h <br> sys/resource.h <br> sys/wait.h |
| signal | ANSI C signal handling | signal.h |
| sigaction | examine and change a signal action | signal.h |
| kill | send a signal to a process | signal.h |
| exit | cause normal process termination | stdlib.h |
| getcwd | get current working directory | unistd.h |
| chdir | change working directory | unistd.h |
| stat <br> lstat | get file status | sys/types.h <br> sys/stat.h  <br> unistd.h |
| get file status | fstat | get file status | sys/types.h <br> sys/stat.h  <br> unistd.h |
| unlink | call the unlink function to remove the specified file | unistd.h |
| execve | execute program | unistd.h |
| dup <br> dup2 | duplicate a file descriptor | unistd.h |
| pipe | create pipe | unistd.h |
| opendir | open a directory | sys/types.h <br> dirent.h |
| readdir | read a directory | dirent.h |
| closedir | close a directory | sys/types.h <br> dirent.h |
| strerror | return string describing error number | string.h |
| perror | print a system error message | stdio.h |
| isatty | test whether a file descriptor refers to a terminal | unistd.h |
| ttyname | return name of a terminal | unistd.h |
| ttyslot | find the slot of the current user's terminal in some file | unistd.h |
| ioctl | control device | sys/ioctl.h |
| getenv | get an environment variable | stdlib.h |
| tcsetattr | set the parameters associated with the terminal | termios.h |
| tcgetattr | get the parameters associated with the terminal | termios.h |
| tgetent <br> tgetflag <br> tgetnum <br> tgetstr <br> tgoto <br> tputs | curses emulation of termcap | curses.h <br> term.h |


# Project Development

|TOKEN | Description | Function | Sample Lexeme |
|------|-------------|----------|---------------|
| echo | characters e, c, h, o | echoes the command on terminal | echo "hello" |
| echo_flag   | characters -, n | remove the newline from echo   | echo -n "hello" |
| cd   | characters c, d | change woking directory        | cd / |
| pwd  | characters p, w, d | print working directory        | pwd  |
| export | characters e, x, p, o, r, t | Set export attribute for shell variables | export EDITOR=/usr/bin/vim |
| unset | characters u, n, s, e, t | Unset values and attributes of variables and functions | unset EDITOR |
| env | characters e, n, v | run a program in a modified environment | env |
| exit | characters e, x, i, t | cause normal process termination | exit |
| id | letter followed by letters and digits | variable name | EDITOR, FT1, ARG |
| number | any numeric constant | | 1, 34, 3.1415 |



# References
1. [Writing Your Own Shell - book chapter](https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf)
1. [Tutorial to code a simple shell in C - by Ricardo Hincapie](https://medium.com/swlh/tutorial-to-code-a-simple-shell-in-c-9405b2d3533e)
1. [Tutorial - Write a Shell in C - by Stephen Brennan](https://brennan.io/2015/01/16/write-a-shell-in-c/)
1. [GNU Bash manual](https://www.gnu.org/savannah-checkouts/gnu/bash/manual/)
1. Compilers: Principles, Techniques, & Tools; Alfred V. Aho, Monica S. Lam, Ravi Sethi, Jeffrey D. Ullman, Pearson/Addison Wesley, 2007 - chaperts 2, 3, 4 and 5.

