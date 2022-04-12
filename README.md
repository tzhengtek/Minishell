# Minishell
Reproduction d'un interpréteur de commande sous UNIX, qui vous permettra d'éxécuter certaines commandes.
Le modèle utilisé comme interpréteur est TCSH et vous pouvez vous naviguez dans cette reproduction d'un terminal de commande.

## BUILD
```
make
```
## USAGE
```
./mysh
```
- Vous promenez entre les dossiers grâce à la commande "cd" : (cd 'folder')
- Affichez le contenu du dossier dans lequel vous êtes avec la commande "ls"
- Quittez le programme avec "exit"
- Executer la redirection de la sortie standard du terminal dans un fichier comme par exemple l'affichage du contenu du dossier actuel : (ls > 'file')
