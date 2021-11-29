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





