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

Following some tips from prof. Gustavo Rodrigues \[1\], to build this project we need to implement a **Parser**, a **Executor** and **shell Subsystems**.

The Parser, is the software component that reads the command line, and puts it into a data structure that will store the commands that will be executed futher.

The Executor will take the command table generated by the parser and for every command in the array it will create a new process. It will also if necessary create pipes to communicate the output of one process to the input of the next one. Additionally, it will redirect the standard input, standard output, and standard error if there are any redirections.

Shell Subsystems is some more stuff that completes the shell, like environment variables: Expressions of the form ${VAR} are expanded with the corresponding environment variable. Also the shell should be able to set, expand and print environment vars; Wildcards: Arguments of the form "\*" are expanded to all the files that match them in the local directory and in multiple directories; Subshells: Arguments between `` (backticks) are executed and the output is sent as input to the shell.

## Tokens description

|TOKEN | Description | Function | Sample Lexeme |
|------|-------------|----------|---------------|
| echo | characters e, c, h, o | echoes the command on terminal | echo "hello" |
| echo_flag   | characters -, n | remove the newline from echo   | echo -n "hello" |
| cd   | characters c, d | change working directory        | cd / |
| pwd  | characters p, w, d | print working directory        | pwd  |
| export | characters e, x, p, o, r, t | Set export attribute for shell variables | export EDITOR=/usr/bin/vim |
| unset | characters u, n, s, e, t | Unset values and attributes of variables and functions | unset EDITOR |
| env | characters e, n, v | run a program in a modified environment | env |
| exit | characters e, x, i, t | cause normal process termination | exit |
| \< | character \<, followed by an filename | should redirect input | \< infile |
| \> | character \> , followed by an filename | should redirect output | \> outfile |
| \<\< | characters \<, \<, followed by an delimiter |read input from the current source until a line containing only the delimiter is seen | \<\< EOF |
| \>\> | characters \>, \>, followed by an filename | should redirect output with append mode | \>\> outfile |
| \| | character \|, preceded and followed by a command | output of each command in the pipeline is connected via a pipe to the input of the next command | ls \| wc |
| $? | characters $, ? | expand to the exit status | $? |
| id | letter followed by letters and digits | variable name, command name, parameters of the command or namefiles | EDITOR, FT1, ARG, infile, outfile |
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
| full_path | If not a builtin, it has the command with full path, get by envp PATH |
| pid | Process id of a child that runs a command |
| infile | 	File descriptor to read from. |
| outfile | File descriptor to write to.|
| envp | Up-to-date array of arrays containing keys and values for the shell environment |
| status | Exit status of a function |

## The EXECUTOR

Takes every command in cmd list and create a new process to it, if necessary create a pipe to process communication, additionally, it will redirect the standard input, output and error if there are any redirections.

**Shell Context Free Grammar (CFG) grammar, defined with the BNF syntax:**

```

<ALPHA>			::=		'a'|'b'|'c'|'d'|'e'|'f'|'g'|'h'|'i'|'j'|'k'|'l'|'m'|'n'
						|'o'|'p'|'q'|'r'|'s'|'t'|'u'|'v'|'w'|'x'|'y'|'z'|'A'
						|'B'|'C'|'D'|'E'|'F'|'G'|'H'|'I'|'J'|'K'|'L'|'M'|'N'
						|'O'|'P'|'Q'|'R'|'S'|'T'|'U'|'V'|'W'|'X'|'Y'|'Z'
						|'_';

<DIGIT>         ::=     '0'|'1'|'2'|'3'|'4'|'5'|'6'|'7'|'8'|'9';

<SIGNAL>		::=		'' | '+' | '-';

<CHAR>			::=		<DIGIT> | <ALPHA>

<NUMBER>        ::=     <DIGIT>
                        | <NUMBER> <DIGIT>;

<WORD>          ::=     <ALPHA>
                        | <WORD> <CHAR>;

<VAR>			::=		'$' <WORD>;

<VAR-LIST>		::=		<VAR> <VAR-LIST>;

<WORD-LIST>     ::=     <WORD>
                        | <WORD-LIST> <WORD>

<ASSIGNMENT> 	::=		<WORD> '='
						| <WORD> '=' <WORD>
						| <WORD> '=' <SIGNAL> <NUMBER>
						| <WORD> '=' '$' <SUBSHELL>

<REDIRECTION>   ::=     '>' <WORD>
                        | '<' <WORD>
                        | <NUMBER> '>' <WORD>
                        | <NUMBER> '<' <WORD>
                        | '>>' <WORD>
                        | <NUMBER> '>>' <WORD>
                        | '<<' <WORD>
                        | <NUMBER> '<<' <WORD>;

<SIMPLE-COMMAND-ELEMENT>    ::= <WORD>
                                |  <ASSIGNMENT>
                                |  <REDIRECTION>

<REDIRECTION-LIST>  ::= <REDIRECTION>
                        | <REDIRECTION-LIST> <REDIRECTION>

<SIMPLE-COMMAND>    ::= <SIMPLE-COMMAND-ELEMENT>
                        |  <SIMPLE-COMMAND> <SIMPLE-COMMAND-ELEMENT>

<COMMAND>           ::=  <SHELL-COMMAND>
                        |  <SHELL-COMMAND> <REDIRECTION-LIST>
                        |  <REDIRECTION-LIST> <SHELL-COMMAND>
                        |  <REDIRECTION-LIST> <SHELL-COMMAND> <REDIRECTION-LIST>

<SHELL-COMMAND>     ::= <SIMPLE-COMMAND>
                        |  <SUBSHELL>

<SUBSHELL>          ::= '(' <COMPOUND-LIST> ')'

<LIST>              ::= <NEWLINE-LIST> <LIST0>

<COMPOUND-LIST>     ::= <LIST>
                        |  <NEWLINE-LIST> <LIST1>

<LIST0>             ::= <LIST1> '\n' <NEWLINE-LIST>

<LIST1>             ::= <LIST1> '&&' <NEWLINE-LIST> <LIST1>
                        |  <LIST1> '||' <NEWLINE-LIST> <LIST1>
                        |  <LIST1> '\n' <NEWLINE-LIST> <LIST1>
                        |  <PIPELINE>

<NEWLINE-LIST> ::= '' |  <NEWLINE-LIST> '\n'

<SIMPLE-LIST> ::=  <SIMPLE-LIST1>
                |  <SIMPLE-LIST1> '&'

<SIMPLE-LIST1> ::=  <SIMPLE-LIST1> '&&' <NEWLINE-LIST> <SIMPLE-LIST1>
                 |  <SIMPLE-LIST1> '||' <NEWLINE-LIST> <SIMPLE-LIST1>
                 |  <SIMPLE-LIST1> '&' <SIMPLE-LIST1>
                 |  <PIPELINE>

<PIPELINE>      ::= <PIPELINE> '|' <NEWLINE-LIST> <PIPELINE>
                    |  <COMMAND>
```

Shell Grammar Rules

1. [Command Name]

When the TOKEN is exactly a reserved word, the token identifier for that reserved word shall result.

2. [Redirection to or from filename]

The expansions specified in Redirection shall occur. As specified there, exactly one field can result (or the result is unspecified), and there are additional requirements on pathname expansion.

3. [Redirection from here-document]

Quote removal shall be applied to the word to determine the delimiter that is used to find the end of the here-document that begins after the next \<newline\>.

4. [Case statement termination]

When the TOKEN is exactly the reserved word esac, the token identifier for esac shall result. Otherwise, the token WORD shall be returned.

5. [ NAME in for]

When the TOKEN meets the requirements for a name (see XBD Name ), the token identifier NAME shall result. Otherwise, the token WORD shall be returned.

6. [Third word of for and case]

a. [ case only]

When the TOKEN is exactly the reserved word in, the token identifier for in shall result. Otherwise, the token WORD shall be returned.

b. [ for only]

When the TOKEN is exactly the reserved word in or do, the token identifier for in or do shall result, respectively. Otherwise, the token WORD shall be returned.

(For a. and b.: As indicated in the grammar, a linebreak precedes the tokens in and do. If <newline> characters are present at the indicated location, it is the token after them that is treated in this fashion.)

7. [Assignment preceding command name]

a. [When the first word]

If the TOKEN does not contain the character '=', rule 1 is applied. Otherwise, 7b shall be applied.

b. [Not the first word]

If the TOKEN contains an unquoted (as determined while applying rule 4 from Token Recognition) <equals-sign> character that is not part of an embedded parameter expansion, command substitution, or arithmetic expansion construct (as determined while applying rule 5 from Token Recognition):

If the TOKEN begins with '=', then rule 1 shall be applied.

If all the characters in the TOKEN preceding the first such <equals-sign> form a valid name (see XBD Name), the token ASSIGNMENT_WORD shall be returned.

Otherwise, it is unspecified whether rule 1 is applied or ASSIGNMENT_WORD is returned.

Otherwise, rule 1 shall be applied.

Assignment to the name within a returned ASSIGNMENT_WORD token shall occur as specified in Simple Commands.

8. [ NAME in function]

When the TOKEN is exactly a reserved word, the token identifier for that reserved word shall result. Otherwise, when the TOKEN meets the requirements for a name, the token identifier NAME shall result. Otherwise, rule 7 applies.

9. [Body of function]

Word expansion and assignment shall never occur, even when required by the rules above, when this rule is being parsed. Each TOKEN that might either be expanded or have assignment applied to it shall instead be returned as a single WORD consisting only of characters that are exactly the token described in Token Recognition.




```
/* -------------------------------------------------------
   The grammar symbols
   ------------------------------------------------------- */
%token  WORD
%token  ASSIGNMENT_WORD
%token  NAME
%token  NEWLINE
%token  IO_NUMBER

/* -------------------------------------------------------
   The Grammar
   ------------------------------------------------------- */
%start <PROGRAM>
%%
<PROGRAM>				::= <LINEBREAK> <COMPLETE-COMMANDS> <LINEBREAK>
						| <LINEBREAK>;

<COMPLETE-COMMANDS>	::= <COMPLETE-COMMANDS> <NEWLINE_LIST> <COMPLETE-COMMAND>
						| <COMPLETE-COMMAND>;

<COMPLETE-COMMAND>	::=  <AND_OR>;

<AND_OR>			::=	<PIPELINE>
						| <AND_OR> '&&' <LINEBREAK> <PIPELINE>
						| <AND_OR> '||'  <LINEBREAK> <PIPELINE>;

<PIPELINE>			::=	<PIPE_LIST>;

<PIPE_LIST>			::=	<COMMAND>
						| <PIPE_LIST> '|' <LINEBREAK> <COMMAND>;

<COMMAND>			::=	<SIMPLE_COMMAND>
						| <SUBSHELL>;

<SUBSHELL>			::=	'(' <COMPOUND_LIST> ')';

<COMPOUND_LIST>		::= <LINEBREAK> <TERM>
						| <LINEBREAK> <TERM> <SEPARATOR>;

<TERM>				::=	<TERM> <SEPARATOR> <AND_OR>
						| <AND_OR>;

<SIMPLE_COMMAND>	::=	<CMD_PREFIX> <CMD_WORD> <CMD_SULFFIX>
						| <CMD_PREFIX> <CMD_WORD>
						| <CMD_PREFIX>
						| <CMD_NAME> <CMD_SULFFIX>
						| <CMD_NAME>;

<CMD_NAME>         : WORD                   /* Apply rule 7a */
                 ;
<CMD_WORD>         : WORD                   /* Apply rule 7b */
                 ;

<CMD_PREFIX>	::=	<REDIRECT_LIST>
					| <CMD_PREFIX> <REDIRECT_LIST>
					| ASSIGNMENT_WORD
					| <CMD_PREFIX> ASSIGNMENT_WORD;

<CMD_SULFFIX>	::=	<REDIRECT_LIST>
					| <CMD_SULFFIX> <REDIRECT_LIST>
					| WORD
					| <CMD_SULFFIX> WORD;

<REDIRECT_LIST>	::=	<REDIRECT>
					| <REDIRECT_LIST> <REDIRECT>;

<REDIRECT>		::=	'<' filename
					| '>' filename
					| '<<' filename
					| '>>' filename;

filename         : WORD                      /* Apply rule 2 */
                 ;

<NEWLINE_LIST>	::=	'\n'
					| <NEWLINE_LIST> '\n';

<LINEBREAK>		::=	<NEWLINE_LIST>
					| /* empty */;

<SEPARATOR>        : <NEWLINE_LIST>;

<ALPHA>			::=		'a'|'b'|'c'|'d'|'e'|'f'|'g'|'h'|'i'|'j'|'k'|'l'|'m'|'n'
						|'o'|'p'|'q'|'r'|'s'|'t'|'u'|'v'|'w'|'x'|'y'|'z'|'A'
						|'B'|'C'|'D'|'E'|'F'|'G'|'H'|'I'|'J'|'K'|'L'|'M'|'N'
						|'O'|'P'|'Q'|'R'|'S'|'T'|'U'|'V'|'W'|'X'|'Y'|'Z';

						|'_';

<DIGIT>         ::=     '0'|'1'|'2'|'3'|'4'|'5'|'6'|'7'|'8'|'9';

<SIGNAL>		::=		'' | '+' | '-';

<CHAR>			::=		<DIGIT> | <ALPHA>

<NUMBER>        ::=     <DIGIT>
                        | <NUMBER> <DIGIT>;

<WORD>          ::=     <ALPHA>
                        | <WORD> <CHAR>;

```



```
LINE		⟶	ε
		|	BLOCK

BLOCK		⟶	STMT
		|	(BLOCK)
		|	CONCAT BLOCK
		|	BLOCK WORD

STMT		⟶	CMD
		|	REDIR
		|	REDIR STMT
		|	STMT REDIR
		|	CMD REDIR
		|	VAR

CONCAT		⟶	BLOCK [&&]
		|	BLOCK [||]

REDIR		⟶	< filename
		|	> filename
		|	<< delimiter
		|	>> filename

WORD		⟶	ε
		|	number
		|	word
		|	'WORD word'
		|	"WORD word"

CMD			⟶	cmd
		|	cmd | CMD
		|	cmd [*]

VAR			⟶	var=WORD
		|	var=$(BLOCK)
		|	$var
```
# References
1. [Writing Your Own Shell - book chapter](https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf) from [Prof. Gustavo Rodriguez-Rivera](https://www.cs.purdue.edu/homes/grr/)
2. [Tutorial to code a simple shell in C - by Ricardo Hincapie](https://medium.com/swlh/tutorial-to-code-a-simple-shell-in-c-9405b2d3533e)
3. [Tutorial - Write a Shell in C - by Stephen Brennan](https://brennan.io/2015/01/16/write-a-shell-in-c/)
4. [GNU Bash manual](https://www.gnu.org/savannah-checkouts/gnu/bash/manual/)
5. Compilers: Principles, Techniques, & Tools; Alfred V. Aho, Monica S. Lam, Ravi Sethi, Jeffrey D. Ullman, Pearson/Addison Wesley, 2007 - chapters 2, 3, 4 and 5.
6. [Shell Command Language](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18_10)
7. [Adding Color to Your Output From C](https://www.theurbanpenguin.com/4184-2/)
