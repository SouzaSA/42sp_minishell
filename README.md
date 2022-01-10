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

## Overview

```flow
st=>start: Login
op=>operation: Login operation
cond=>condition: Successful Yes or No?
e=>end: To admin

st->op->cond
cond(yes)->e
cond(no)->op
```

Following some tips from prof. Gustavo Rodrigues \[1\], to build this project we need to implement a **Parser**, a **Executor** and **shell Subsystems**.

The Parser, is the software component that reads the command line, and puts it into a data structure that will store the commands that will be executed futher.

The Executor will take the command table generated by the parser and for every command in the array it will create a new process. It will also if necessary create pipes to communicate the output of one process to the input of the next one. Additionally, it will redirect the standard input, standard output, and standard error if there are any redirections.

Shell Subsystems is some more stuff that completes the shell, like environment variables: Expressions of the form ${VAR} are expanded with the corresponding environment variable. Also the shell should be able to set, expand and print environment vars; Wildcards: Arguments of the form "\*" are expanded to all the files that match them in the local directory and in multiple directories; Subshells: Arguments between `` (backticks) are executed and the output is sent as input to the shell.

##  The LEXER

## Tokens description

|TOKEN | REGEX | TOKEN TYPE !
|------|-------------|----------|
| \| | [\|]\{1\} | pipe |
| \( | [\(]\{1\} | lbrace |
| \) | [\)]\{1\}  | rbrace |
| && | [&]\{2\} | and_if |
| \|\| | [\|]\{2\} | or_if |
| \< | [\<]\{1\} | less |
| \> | [\>]\{1\} | great |
| \<\< | [\<]\{2\} | dless |
| \<\> | [\<]\{1\}\>\{1\} | lessgreat |
| \>\> | [\>]\{2\} | dgreat |
| ASSIGNMENT | [A-Za-z_][0-9A-Za-z_]\*=((['][0-9A-Za-z_]\*['])\|(["][0-9A-Za-z_]\*["])\|([0-9A-Za-z_]\*))? | assignment |
| WORD | (['][0-9A-Za-z_]+['])\|(["][0-9A-Za-z_]+["])\|([0-9A-Za-z_]+) | word |
| NULL | NULL | tok_eof |

##  The PARSER

### **Shell Context Free Grammar (CFG) grammar, LL(1) type, defined with the BNF syntax:**

```
PROGRAM ::= AND_OR
AND_OR ::= PIPELINE AND_OR1
AND_OR1 ::= ''
AND_OR1 ::= AND_IF PIPELINE AND_OR1
AND_OR1 ::= OR_IF PIPELINE AND_OR1
PIPELINE ::= COMMAND PIPELINE1
PIPELINE1 ::= ''
PIPELINE1 ::= pipe COMMAND
COMMAND ::= SIMPLE_COMMAND
COMMAND ::= SUBSHELL COMMAND1
COMMAND1 ::= ''
COMMAND1 ::= REDIRECT_LIST
SUBSHELL ::= lbrace AND_OR rbrace
SIMPLE_COMMAND ::= CMD_PREFIX SIMPLE_COMMAND1
SIMPLE_COMMAND ::= CMD_WORD SIMPLE_COMMAND2
SIMPLE_COMMAND1 ::= ''
SIMPLE_COMMAND1 ::= CMD_WORD SIMPLE_COMMAND2
SIMPLE_COMMAND2 ::= ''
SIMPLE_COMMAND2 ::= CMD_SULFIX
CMD_WORD ::= WORD
ASSIGNMENT_WORD ::= assign_word
CMD_PREFIX ::= IO_REDIRECT CMD_PREFIX1
CMD_PREFIX ::= ASSIGNMENT_WORD CMD_PREFIX1
CMD_PREFIX1 ::= ''
CMD_PREFIX1 ::= IO_REDIRECT CMD_PREFIX1
CMD_PREFIX1 ::= ASSIGNMENT_WORD CMD_PREFIX1
CMD_SULFIX ::= IO_REDIRECT CMD_SULFIX1
CMD_SULFIX ::= WORD CMD_SULFIX1
CMD_SULFIX1 ::= ''
CMD_SULFIX1 ::= IO_REDIRECT CMD_SULFIX1
CMD_SULFIX1 ::= WORD CMD_SULFIX1
REDIRECT_LIST ::= IO_REDIRECT REDIRECT_LIST1
REDIRECT_LIST1 ::= ''
REDIRECT_LIST1 ::= IO_REDIRECT REDIRECT_LIST1
IO_REDIRECT ::= IO_FILE
IO_REDIRECT ::= IO_HERE
IO_FILE ::= less FILENAME
IO_FILE ::= great FILENAME
IO_FILE ::= dgreat FILENAME
IO_FILE ::= lessgreat FILENAME
FILENAME ::= WORD
IO_HERE ::= dless HERE_END
HERE_END ::= WORD
WORD ::= word
```

### **Nullable/First/Follow Table and Transition Table**

| Nonterminal | Nullable? | First | Follow |
| :-- | --- | --- | --- |
| S | ✖ | newline, lbrace, assign_word, word, less, great, dgreat, lessgreat, dless | |
| PROGRAM | ✖ | newline, lbrace, assign_word, word, less, great, dgreat, lessgreat, dless | $ |
| PROGRAM1 | ✖ | lbrace, assign_word, word, less, great, dgreat, lessgreat, dless | $ |
| AND_OR | ✖ | lbrace, assign_word, word, less, great, dgreat, lessgreat, dless | newline, rbrace, $ |
| AND_OR1 | ✔ | AND_IF, OR_IF | newline, rbrace, $ |
| PIPELINE | ✖	lbrace, assign_word, word, less, great, dgreat, lessgreat, dless | newline, AND_IF, OR_IF, rbrace, $ |
| PIPELINE1 | ✔ | pipe | newline, AND_IF, OR_IF, rbrace, $ |
| COMMAND | ✖ | lbrace, assign_word, word, less, great, dgreat, lessgreat, dless | newline, AND_IF, OR_IF, pipe, rbrace, $ |
| COMMAND1 | ✔ | less, great, dgreat, lessgreat, dless | newline, AND_IF, OR_IF, pipe, rbrace, $ |
| SUBSHELL | ✖ | lbrace | newline, AND_IF, OR_IF, pipe, less, great, dgreat, lessgreat, dless, rbrace, $ |
| SIMPLE_COMMAND | ✖ | assign_word, word, less, great, dgreat, lessgreat, dless | newline, AND_IF, OR_IF, pipe, rbrace, $ |
| SIMPLE_COMMAND1 | ✔ | word | newline, AND_IF, OR_IF, pipe, rbrace, $ |
| SIMPLE_COMMAND2 | ✔ | word, less, great, dgreat, lessgreat, dless | newline, AND_IF, OR_IF, pipe, rbrace, $ |
| CMD_WORD | ✖ | word | newline, AND_IF, OR_IF, pipe, word, less, great, dgreat, lessgreat, dless, rbrace, $ |
| ASSIGNMENT_WORD | ✖ | assign_word | newline, AND_IF, OR_IF, pipe, word, assign_word, less, great, dgreat, lessgreat, dless, rbrace, $ |
| CMD_PREFIX | ✖ | assign_word, less, great, dgreat, lessgreat, dless | newline, AND_IF, OR_IF, pipe, word, rbrace, $ |
| CMD_PREFIX1 | ✔ | assign_word, less, great, dgreat, lessgreat, dless | newline, AND_IF, OR_IF, pipe, word, rbrace, $ |
| CMD_SULFIX | ✖ | word, less, great, dgreat, lessgreat, dless | newline, AND_IF, OR_IF, pipe, rbrace, $ |
| CMD_SULFIX1 | ✔ | word, less, great, dgreat, lessgreat, dless | newline, AND_IF, OR_IF, pipe, rbrace, $ |
| REDIRECT_LIST | ✖ | less, great, dgreat, lessgreat, dless | newline, AND_IF, OR_IF, pipe, rbrace, $ |
| REDIRECT_LIST1 | ✔ | less, great, dgreat, lessgreat, dless | newline, AND_IF, OR_IF, pipe, rbrace, $ |
| IO_REDIRECT | ✖ | less, great, dgreat, lessgreat, dless | newline, AND_IF, OR_IF, pipe, word, assign_word, less, great, dgreat, lessgreat, dless, rbrace, $ |
| IO_FILE | ✖ | less, great, dgreat, lessgreat | newline, AND_IF, OR_IF, pipe, word, assign_word, less, great, dgreat, lessgreat, dless, rbrace, $ |
| FILENAME | ✖ | word | newline, AND_IF, OR_IF, pipe, word, assign_word, less, great, dgreat, lessgreat, dless, rbrace, $ |
| IO_HERE | ✖ | dless | newline, AND_IF, OR_IF, pipe, word, assign_word, less, great, dgreat, lessgreat, dless, rbrace, $ |
| HERE_END | ✖ | word | newline, AND_IF, OR_IF, pipe, word, assign_word, less, great, dgreat, lessgreat, dless, rbrace, $ |
| WORD | ✖ | word | newline, AND_IF, OR_IF, pipe, word, less, great, dgreat, lessgreat, dless, assign_word, rbrace, $ |
| NEWLINE_LIST | ✖ | newline | lbrace, assign_word, word, less, great, dgreat, lessgreat, dless, $ |
| NEWLINE_LIST1 | ✔ | newline | lbrace, assign_word, word, less, great, dgreat, lessgreat, dless, $ |
| LINEBREAK | ✔ | newline | lbrace, assign_word, word, less, great, dgreat, lessgreat, dless, $ |


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
| full_path | If not a builtin, it has the command with full path, get by envp PATH |
| pid | Process id of a child that runs a command |
| infile | 	File descriptor to read from. |
| outfile | File descriptor to write to.|
| envp | Up-to-date array of arrays containing keys and values for the shell environment |
| status | Exit status of a function |

## The EXECUTOR

Takes every command in cmd list and create a new process to it, if necessary create a pipe to process communication, additionally, it will redirect the standard input, output and error if there are any redirections.


# References
1. [Writing Your Own Shell - book chapter](https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf) from [Prof. Gustavo Rodriguez-Rivera](https://www.cs.purdue.edu/homes/grr/)
2. [Tutorial to code a simple shell in C - by Ricardo Hincapie](https://medium.com/swlh/tutorial-to-code-a-simple-shell-in-c-9405b2d3533e)
3. [Tutorial - Write a Shell in C - by Stephen Brennan](https://brennan.io/2015/01/16/write-a-shell-in-c/)
4. [GNU Bash manual](https://www.gnu.org/savannah-checkouts/gnu/bash/manual/)
5. Compilers: Principles, Techniques, & Tools; Alfred V. Aho, Monica S. Lam, Ravi Sethi, Jeffrey D. Ullman, Pearson/Addison Wesley, 2007 - chapters 2, 3, 4 and 5.
6. [Shell Command Language](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18_10)
7. [Adding Color to Your Output From C](https://www.theurbanpenguin.com/4184-2/)
8. [Standard Exit Status Codes in Linux](https://www.baeldung.com/linux/status-codes)
