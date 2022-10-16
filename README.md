<h1>L2 Computer Science & Mathematics</h1>
<h2>Algorithmique avancée et programmation C++</h2>
<h3>Exercice: Notation-polonaise</h3>
On considère ici des expressions numériques qui ne contiennent que les opérateurs '+',  '-', '*' ,/', et des chiffres (opérandes) entre 1 et 9.Une telle expression est dite en notation polonaise postfixée si les opérateurs sont toujours après les deux opérandes sur lesquelles elles s'appliquent.

Voici par exemple une expression numérique en notation postfixée :
254-+2+

Elle s'interpète comme suit. On lit de gauche à droite. On rencontre donc d'abord 2, puis 5, puis 4, puis '-'.

L'opérateur '-'' s'applique aux deux opérandes précédentes : 5 et 4. Ca fait 5 - 4 = 1 .

Puis on rencontre l'opérateur '+'.

Il s'applique aux deux opérandes précédentes. : 2 et 1 (calculé précédemment). Ca fait 2 + 1 = 3.

On rencontre ensuite 2, puis '+'. '+' s'appliquera à ses deux opérandes précédentes : 3 et 2.

Le résultat final de l'expression est 3 + 2 = 5.

En mettant artificiellement (car elles ne sont pas nécessaires) des parenthèses, on peut mieux suivre ce qui se passe. Ainsi ce qu'on vient de calculer c'est :

((2(54-)+)2+)

Chaque groupe du type (...) siginifie "résultat de ce qui se trouve dans la parenthèse".
Par exemple  (54-) a donné 1. Puis (2(54-)+) a donné 3, et ainsi de suite,...

L'objectif est de faire un algorithme qui lit des fichiers d'entrée contenant des expressions de ce type, calcule la valeur de l'expression en affichant tous les calculs intermédaires. Cet algorithme sera codé dans un classe "expression" fourni dans les fichiers. Cette classe comporte deux méthodes :

lecture : qui doit lire l'expression numérique se trouvant dans un fichier donné en argument et insérer chacun des caractères dans une file (nommée "file").
calcul : qui utilise ce qui se trouve dans "file" et, grâce à une pile, calcule (et retourne) la valeur de l'expression en affichant tous les calculs intermédiaires.
Pour reprendre l'exemple précédent, le fichier d'entrée contiendra les caractères suivants:

254-+2+f

'f' est un caractère qui indiquera seulement la fin de l'expression (il ne fait pas partie de l'expression).

"lecture" doit lire chacun des caractères (sauf 'f') et les mettre dans "file".

"calcul" doit retourner la valeur de l'expression (5) et afficher les calculs intermédiaires. Elle devra afficher pour cet exemple :

5-4=1
1+2=3
2+3=5 (saut de ligne ici aussi)

Attention, si dans la suite des opérations il arrive au moment où une division par '0' est effectué votre algorithme doit le détecter en affichant : "impossible".

Plus précisement, pour l'exemple suivant : 522+4-/,

L'affichage devrait être :

2+2=4
4-4=0
5/0=impossible (saut de ligne ici aussi)

Vous ne devez pas changer "expression.h".
Pour tester vos méthodes, un fichier "main" vous est fourni. Celui-ci lit un fichier d'entrée "entree1.txt" (ou entree2.txt"),  et exécute vos méthodes. Vos sorties sont comparées avec celle de la solution sur deux fichiers décrit ci-dessous.
L'évaluation fait la même chose avec des expressions générées aléatoirement.
Pour avoir 100 TOUTES les méthodes doivent être codées et passer TOUS les tests.
Il est conseillé de tester avec "run" ou en local avant d'appuyer sur "evaluate".

Voici les contenus des deux fichiers utilisés par "run".

entree1.txt:

149/+752-4*-/f

entree2.txt:

329*-345/4+*+f

Concernant les classe C++ stack et queue.

Pour rappel, "stack" représente une pile et "queue" une file.

Dans les deux cas, on insère (empiler, enfiler) avec push(.).

Pour dépiler une pile nommée p, on fait : x = p.top(); p.pop().

Pour "défiler" une file nommée f, on fait : x = f.front(); f.pop().
