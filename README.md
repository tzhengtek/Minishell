# Minishell ![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
This is a program of a UNIX command interpreter and the reference shell is TCSH.

You can execute many commands like: cd, ls...

## BUILD
```
make
```
## USAGE
```
./mysh
```
## CD
Change the current repository by using the command CD
```
cd 'folder'
```
## LS
List directory contents of files and directories with the command LS
```
ls
``` 
## SIMPLE REDIRECTION OUTPUT
Redirect standard output into a file
```
ls > 'file'
```
## DOUBLE REDIRECTION OUTPUT
Redirect standard output and append into a file
```
ls >> 'file'
```
## SIMPLE REDIRECTION INPUT
Redirect content of file as input
```
cat < 'file'
```
## DOUBLE REDIRECTION INPUT
Make a infinite loop as long as you don't write the name after "<<", and then do the command
```
ls << 'name'
```
## PIPE REDIRECTION
Redirect a command executed output into a another command as input
```
ls | cat -e
```
## EXIT
Exit the program ( You can also use CTRL + D )
```
exit
```

