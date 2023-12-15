#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"


extern char **environ;


/**
 * struct data - Represents a structure for shell data
 * @av: Array of strings representing command-line arguments
 * @input: String containing user input
 * @args: Array of strings representing parsed arguments
 * @status: Integer representing the status of the shell
 * @counter: Integer representing a counter (purpose may need clarification)
 * @_environ: Array of strings representing the environment variables
 * @pid: String representing the process ID
 * Description: This structure holds various pieces of data
 * related to the shell,
 * providing a convenient way to organize and
 * access relevant information.
 */
typedef struct data
{
	char **av;
	char *input;
	char **args;
	int status;
	int counter;
	char **_environ;
	char *pid;
} data_shell;

/**
 * struct sep_list_s - Represents a structure for a list of separators
 * @separator: Character representing the separator (;, |, or &)
 * @next: Pointer to the next node in the list
 * Description: This structure is used to create a linked list of separators,
 * allowing for the representation of command separators in the shell.
 * - 'separator': Holds the character representing the separator (;, |, or &)
 * - 'next': Points to the next node in the linked list,
 *creating a chain of separators.
 * If NULL, it indicates the end of the list.
 */
typedef struct sep_list_s
{
	char separator;
	struct sep_list_s *next;
} sep_list;

/**
 * struct line_list_s - Represents a structure for a linked list of lines
 * @line: String containing a line of text
 * @next: Pointer to the next node in the list
 * Description: This structure is used to create a linked list of lines,
 * allowing for the representation of lines of text in the shell.
 * - 'line': Holds a dynamically allocated string representing a line of text.
 * - 'next': Points to the next node in the linked list,
 * creating a chain of lines.
 * If NULL, it indicates the end of the list.
 */
typedef struct line_list_s
{
	char *line;
	struct line_list_s *next;
} line_list;

/**
 * struct r_var_list - Represents a structure for a list of runtime variables
 * @len_var: Integer representing the length of the variable name
 * @val: String containing the value of the runtime variable
 * @len_val: Integer representing the length of the variable value
 * @next: Pointer to the next node in the list
 * Description: This structure is used to create
 * a linked list of runtime variables,
 * allowing for the representation of variables
 * with associated values during runtime.
 * - 'len_var': Represents the length of the variable name.
 * - 'val': Holds a dynamically allocated string
 * representing the value of the variable.
 * - 'len_val': Represents the length of the variable value.
 * - 'next': Points to the next node in the linked list,
 * creating a chain of runtime variables.
 * If NULL, it indicates the end of the list.
 */
typedef struct r_var_list
{
	int len_var;
	char *val;
	int len_val;
	struct r_var_list *next;
} r_var;

/**
 * struct builtin_s - Represents a structure for shell built-in commands
 * @name: String containing the name of the built-in command
 * @f: Pointer to a function that handles the execution of the built-in command
 * Description: structure used to define built-in commands in the shell
 * - 'name': Holds a dynamically allocated string
 * The function is responsible for executing
 * the behavior of the built-in command.
 */
typedef struct builtin_s
{
	char *name;
	int (*f)(data_shell *datash);
} builtin_t;
/* section A */
sep_list *add_sep_node_end(sep_list **head, char sep);
void free_sep_list(sep_list **head);
line_list *add_line_node_end(line_list **head, char *line);
void free_line_list(line_list **head);

/* section B */
r_var *add_rvar_node(r_var **head, int lvar, char *var, int lval);
void free_rvar_list(r_var **head);

/* scetion C */
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);

/* scetion D */
void _memcpy(void *newptr, const void *ptr, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);

/* section E */
char *_strdup(const char *s);
int _strlen(const char *s);
int cmp_chars(char str[], const char *delim);
char *_strtok(char str[], const char *delim);
int _isdigit(const char *s);

/* scetiion F */
void rev_string(char *s);

/* section G */
int repeated_char(char *input, int i);
int error_sep_op(char *input, int i, char last);
int first_char(char *input, int *i);
void print_syntax_error(data_shell *datash, char *input, int i, int bool);
int check_syntax_error(data_shell *datash, char *input);

/* scetion J */
char *without_comment(char *in);
void shell_loop(data_shell *datash);

/* section K */
char *read_line(int *i_eof);

/* section L */
char *swap_char(char *input, int bool);
void add_nodes(sep_list **head_s, line_list **head_l, char *input);
void go_next(sep_list **list_s, line_list **list_l, data_shell *datash);
int split_commands(data_shell *datash, char *input);
char **split_line(char *input);

/* section M */
void check_env(r_var **h, char *in, data_shell *data);
int check_vars(r_var **h, char *in, char *st, data_shell *data);
char *replaced_input(r_var **head, char *input, char *new_input, int nlen);
char *rep_var(char *input, data_shell *datash);

/* section N */
void bring_line(char **lineptr, size_t *n, char *buffer, size_t j);
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);

/* scetion O */
int exec_line(data_shell *datash);

/* section P */
int is_cdir(char *path, int *i);
char *_which(char *cmd, char **_environ);
int is_executable(data_shell *datash);
int check_error_cmd(char *dir, data_shell *datash);
int cmd_exec(data_shell *datash);

/* scetion Q */
char *_getenv(const char *name, char **_environ);
int _env(data_shell *datash);

/* scetion R */
char *copy_info(char *name, char *value);
void set_env(char *name, char *value, data_shell *datash);
int _setenv(data_shell *datash);
int _unsetenv(data_shell *datash);

/* section S */
void cd_dot(data_shell *datash);
void cd_to(data_shell *datash);
void cd_previous(data_shell *datash);
void cd_to_home(data_shell *datash);

/* scetion T */
int cd_shell(data_shell *datash);

/* scetion U */
int (*get_builtin(char *cmd))(data_shell *datash);

/* scetion V */
int exit_shell(data_shell *datash);

/* scetion X */
int get_len(int n);
char *aux_itoa(int n);
int _atoi(char *s);

/* Section A1 */
char *strcat_cd(data_shell *, char *, char *, char *);
char *error_get_cd(data_shell *datash);
char *error_not_found(data_shell *datash);
char *error_exit_shell(data_shell *datash);

/* section A2 */
char *error_get_alias(char **args);
char *error_env(data_shell *datash);
char *error_syntax(char **args);
char *error_permission(char **args);
char *error_path_126(data_shell *datash);


/* scetion Y */
int get_error(data_shell *datash, int eval);

/* block */
void get_sigint(int sig);

/* section A3 */
void aux_help_env(void);
void aux_help_setenv(void);
void aux_help_unsetenv(void);
void aux_help_general(void);
void aux_help_exit(void);

/* scetion A3 */
void aux_help(void);
void aux_help_alias(void);
void aux_help_cd(void);

/* block */
int get_help(data_shell *datash);

#endif
