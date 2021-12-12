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
| rl_clear_history | clear the history list by deleting all of the entries |stdio.h <br> readline/readline.h <br> readline/history.h |
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

Following some tips from prof. Gustavo Rodrigues \[1\], to build this projct we need to implement a **Parser**, a **Executor** and **shell Subsystems**.

The Parser, is the software component that reads the command line, and puts it into a data structure that will store the commands that will be executed futher.

The Executor will take the command table generated by the parser and for every command in the array it will create a new process. It will also if necessary create pipes to communicate the output of one process to the input of the next one. Additionally, it will redirect the standard input, standard output, and standard error if there are any redirections.

Shell Subsystems is some more stuff that completes the shell, like environment variables: Expressions of the form ${VAR} are expanded with the corresponding environment variable. Also the shell should be able to set, expand and print environment vars; Wildcards: Arguments of the form "\*" are expanded to all the files that match them in the local directory and in multiple directories; Subshells: Arguments between `` (backticks) are executed and the output is sent as input to the shell.

## Tokens description

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
| \< | character \<, folowed by an filename | should redirect input | \< infile |
| \> | character \> , folowed by an filename | should redirect output | \> outfile |
| \<\< | characters \<, \<, folowed by an delimiter |read input from the current source until a line containing only the delimiter is seen | \<\< EOF |
| \>\> | characters \>, \>, folowed by an filename | should redirect output with append mode | \>\> outfile |
| \| | character \|, preceded and folowed by a command | output of each command in the pipeline is connected via a pipe to the input of the next command | ls \| wc |
| $? | characters $, ? | expand to the exit status | $? |
| id | letter followed by letters and digits | variable name, comand name, parameters of the command or namefiles | EDITOR, FT1, ARG, infile, outfile |
| number | any numeric constant | pid | 1, 34, 4223 |

##  The PARSER

  Responsible to separate the inline elements to right values. The structure used to keep this elements is showed below.

```c
typedef struct s_shell
{
	t_list	*cmds;
	char	**envp;
	int		status;
}	t_shell;

typedef struct s_cmd_tbl
{
	int		infile;
	int		outfile;
	long	pid;
	char	**full_cmd;
	char	*full_path;
}	t_cmd_tbl;
```

Description of the structures.

| parameter | Description |
|:-- | :--|
| cmds | Linked list containing a node with all commands |
| full_cmd | Array of arrays containing the command name and its parameters |
| full_path | If not a builtin, it has the comand with full path, get by envp PATH |
| pid | Process id of a child that runs a command |
| infile | 	File descriptor to read from. |
| outfile | File descriptor to write to.|
| envp | Up-to-date array of arrays containing keys and values for the shell environment |
| status | Exit status of a function |

## The EXECUTOR

Takes every command in cmd list and create a new process to it, if necessary create a pipe to process comunication, additionaly, it will redirect the standard input, output and error if there are any redirections.

**Shell Context Free Grammar (CFG) grammar:**

```
BLOCK		⟶	ε
		|	STMT
		|	(STMT)
		|	BLOCK CONCAT
		|	BLOCK WORD

STMT		⟶	CMD
		|	REDIR
		|	CMD [|] STMT
		|	REDIR STMT
		|	STMT REDIR
		|	CMD REDIR

CONCAT		⟶	[&&] BLOCK
		|	[||] BLOCK

REDIR		⟶	< filename
		|	> filename
		|	<< delimiter
		|	>> filename

WORD		⟶	'string'
		|	"string"

CMD		⟶	cmd
```
# References
1. [Writing Your Own Shell - book chapter](https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf) from [Prof. Gustavo Rodriguez-Rivera](https://www.cs.purdue.edu/homes/grr/)
2. [Tutorial to code a simple shell in C - by Ricardo Hincapie](https://medium.com/swlh/tutorial-to-code-a-simple-shell-in-c-9405b2d3533e)
3. [Tutorial - Write a Shell in C - by Stephen Brennan](https://brennan.io/2015/01/16/write-a-shell-in-c/)
4. [GNU Bash manual](https://www.gnu.org/savannah-checkouts/gnu/bash/manual/)
5. Compilers: Principles, Techniques, & Tools; Alfred V. Aho, Monica S. Lam, Ravi Sethi, Jeffrey D. Ullman, Pearson/Addison Wesley, 2007 - chaperts 2, 3, 4 and 5.
