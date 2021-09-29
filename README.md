## README

README est un manuel d'instruction pour bien faire fonctionner le projet
Mis à jour le 29 septembre 2021
## Compiler

Utiliser la ligne de code ci dessous afin de compiler en premier

```
catkin_make
```

Ensuite lancer le code pour chaque ouverture d'un nouveau terminal sur Linux

```
source devel/setup.bash 
```

Il faudra d'abord lancer le coeur du ROS en premier pour que les nodes du projet puissent fonctionner entre eux

```
roscore
```

Ensuite, il faudra d'abord lancer le deuxième node (qui est le serveur) avant de lancer le premier node (qui est le client)

```
rosrun projet_baptiste second_node

rosrun projet_baptiste first_node X1 Y1 Z1 X2 Y2 Z2 X3 Y3 Z3
```

où les paramètres des trois points (X,Y,Z) sont à remplacer par les chiffres choisis par le client avant de lancer le code.

### Exemple

`rosrun projet_baptiste first_node 0 0 0 10 10 10 10 0 0`

`[ INFO] [1632283550.666092797]: Premier point A (0.000000,0.000000,0.000000)`
`[ INFO] [1632283550.667137308]: Deuxième point B (10.000000,10.000000,10.000000)`
`[ INFO] [1632283550.667179346]: Troisième point C (10.000000,0.000000,0.000000)`
`[ INFO] [1632283550.668636686]: RESULTAT Aire triangle: 70.710701`



