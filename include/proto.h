/*
** EPITECH PROJECT, 2021
** proto.h
** File description:
** proto
*/

#ifndef PROTO_H_
    #define PROTO_H_

    #define BLUE "\033[0;34m"
    #define RESET "\033[0m"
    #define CYAN "\e[1;36m"
    #define ABS(value) ((value < 0) ? (-value) : (value))

typedef struct stock {
    char **new_env;
    char **arg;
    int id_arg;
    int id_cd;
    char **path;
    char *prompt;
    char *home;
    char *pwd;
    char *buff;
} stock_t;

char **str_to_array(char *str, char *separator);
void create_path_array(char **array, char *str, char c);
int count_path_str(char *str, char c);
char **path_to_array(char *str, char c);
int check_env(char **arg, char **env);
void change_pwd(char **new_env, char *pwd);
char *get_prompt(void);
char **copy_array(char **env);
void free_array(char **array);
char **get_path(char **env);
char *get_home(char **new_env);
int strcmp_start(char *env, char *str);
int no_arg(char *buff, int n);
int return_index(char *str, char c);
int my_arrlen(char **array);
void print_env(char **env);
int check_key(char **env, char *key);
void add_key_array(stock_t *stock, char *key, char *value);
int check_oldpwd(char **new_env);
void change_oldpwd(stock_t *stock, char *save);
int index_key(char **new_env, char *key);
int check_cd(stock_t *stock, char **arg);
int execute(stock_t *stock);
int check_exit(stock_t *stock, char **arg);
char **create_key(stock_t *stock, char **arg);
char **modify_key(stock_t *stock, char **arg);
int check_setenv(stock_t *stock, char **arg);
int check_unsetenv(stock_t *stock, char **arg);
int count_key_cond(char **new_env, char *arg, int count);
int count_key(stock_t *stock, char **arg);
int check_same_key(char *env, int index, char **new_env, char **arg);
void check_memset(char *buff);
int minishell(char **env);
int index_character(char *str, char c, int nb);
int is_alpha(char c);
int is_alphanumeric(char c);
int check_alaphanumeric(char *str);
void print_coredump(int status);
int check_error(int status);
stock_t *create_stock(char **env);
void free_all_arg(char ***array);
void free_all(stock_t *stock);
int redirection_cmd(char **file, char **arg);
int check_redirection(char **arg);
char *get_filename(char **arg, int index, int *state);
int condition_redirection(char *arg);
int check_double_redirection(char **arg, int index, int pos);
char *get_redirection_file(char **arg, int *state);
char **create_env(void);
char ***check_multiple_arg(char *buff);
char **remove_index_array(char **arg, int index, int size);
int redirection_stdout(int state, char *file);
int redirection_stdin(char *file);
int double_redirection_stdin(char *file);
void execute_cmd_path(char **arg, char **new_env, char **path);
int check_pipe_redirection(char **path, char **new_env, char *buff);

#endif
