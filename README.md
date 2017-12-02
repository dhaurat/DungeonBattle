# Dungeon Battle (Numkinch)

Projet de Programmation Orientée Objet Avancée, dans le cadre d'un semestre académique en informatique à l'UQAC.

## Description générale

Dungeon Battle (ou Numkinch) est un jeu de rôle / jeu de cartes 2D multi-joueurs en local s'inspirant librement du jeu de société Munchkin créé par Steve Jackson.


## Processus de développement

### Équipe

Chloé Belguermi & Damien Haurat.

#### Spécifications

Nous avons rédigé les scénarios / cas d'utilisation du programme en amont du développement.

Le diagramme de cas d'utilisation est disponible dans le dossier `doc`.

#### Développement

Nous avons travaillé en ***pair-programming*** avec l'IDE CLion, sous environnements Linux et Mac.

#### Documentation

Une documentation Doxygen (http://www.stack.nl/~dimitri/doxygen/) a été générée à partir des commentaires présents dans le code. Elle recense toutes les classes avec leur hiérarchie.

Sous forme de pages HTML, la documentation permet de visualiser les membres et méthodes de chaque classe, ainsi que son diagramme de dépendances.

Pour la consulter, aller dans le dossier `doc/html`, trouver et ouvrir le fichier `index.html` (oui, il y a effectivement beaucoup de fichiers...).

**Visualisation du diagramme de classes :** ouvrir `index.html`, aller à l'onglet *Classes* puis cliquer sur *Class hierarchy*.

## Compilation des sources

### Prérequis

* Bibliothèque graphique SDL2 (voir section suivante pour l'installation).
* Moteur de production CMake.
* Outil Make.

### Installation de la SDL et de ses extensions

#### Sous macOS

Télécharger les images-disques de `SDL2`, `SDL2_image` et `SDL2_ttf` aux adresses suivantes :

https://www.libsdl.org/download-2.0.php \
https://www.libsdl.org/projects/SDL_image/ \
https://www.libsdl.org/projects/SDL_ttf/

Ces images-disques contiennent chacune un fichier `.framework` qu'il suffit de déplacer dans le dossier `/Library/Frameworks`.

#### Sous Linux Ubuntu

Installer les paquetages `SDL2`, `SDL2_image` et `SDL2_ttf` suivants :

`sudo apt install libsdl2-dev`

`sudo apt install libsdl2-image-dev`

`sudo apt install libsdl2-ttf-dev`

(attention à bien choisir la version finissant par `dev`).

### Construction du projet (Linux et macOS)

Le dossier racine contient un fichier `CMakeLists.txt` pour construire le projet. Dans le dossier racine, lancer la commande suivante :

`cmake .`

Un `Makefile` est alors généré. Pour produire l'exécutable, lancer la commande suivante, toujours dans le dossier racine :

`make`

Un exécutable nommé `Numkinch` sera généré. Pour le lancer, saisir simplement la commande suivante :

`./Numkinch`

### Remarques et bugs connus

* En cliquant sur « Nouvelle Partie », il se peut que le programme mette quelques secondes à répondre. Il est inutile de re-cliquer plusieurs fois sur le bouton, il suffit d'attendre un peu.
* Il peut être également possible que le programme plante après avoir cliqué sur « Jouer ». C'est rare mais ça arrive. Dans ce cas, relancer simplement le programme et ré-essayer, le plantage ne devrait pas arriver de nouveau.

### Résolution d'écran

Le programme a été testé avec une résolution d'écran de 1 920 x 1 080.

Si vous possédez un Mac avec écran Retina, il peut être nécessaire de modifier la résolution pour que le jeu s'affiche correctement : \
Allez dans *Préférences Système > Moniteurs*, cochez l'option « Résolution à l'échelle » et choisir l'option « Plus d'espace ». Le texte devrait apparaître plus petit.

## Déroulement d'une partie

### Principe général

Dungeon Battle se joue à 4 sur le même ordinateur. Chacun leur tour, les joueurs vont choisir une pièce du donjon à ouvrir (c'est-à-dire une carte à retourner).
Une pièce pourra contenir un trésor, un piège, ou un monstre à combattre (dont des boss). En progressant ainsi au sein du donjon, les joueurs verront les capacités de leur personnage augmenter. 
Le but du jeu est d'être le premier à tuer un des boss du donjon.

### Partie rapide

Avant de commencer un nouvelle partie, choisissez tout d'abord un ordre de jeu, pour savoir qui jouera en premier et qui seront les suivants (le plus jeune joue en premier par exemple ...).
Pour lancer une nouvelle partie, cliquez simplement sur le bouton « Nouvelle partie » sur l'écran titre. Quatre personnages sont alors générés aléatoirement.
Chaque personnage généré correspond ainsi à un joueur (le personnage à gauche de l'écran correspond au joueur jouant en premier, et ainsi de suite). 
Vous pouvez remarquer que chacun des personnages possède une Race et une Classe (ainsi qu'un nom). Pour en savoir plus, référez-vous au chapitre « Races et Classes ».
Vous pouvez à présent lancer la partie en cliquant sur « Jouer ». 
Apparaissent alors face à vous les cartes correspondant aux différentes pièces du donjon. Elles sont retournées face cachée pour l'instant car vous n'avez pas encore visité de pièce. 
A droite de l'écran se trouvent les cartes de vos personnages. Elles affichent notamment les points de vie, l'attaque, la défense, et l'agilité de chaque personnage (voir chapitre « Attributs des personnages »).
Le premier joueur peut cliquer sur la carte de son choix pour la retourner. Elle apparait alors en grand entre les cartes Donjon et les cartes Personnages. Quatre types de cartes existent : les monstres, les pièges, les trésors, et les boss.
Si vous tombez sur un monstre ou un boss, vous pouvez décider de le combattre ou de le fuir (voir chapitre « Déroulement des combats »). Vous gagnerez des points de compétence si vous parvenez à le tuer mais votre personnage meurt si c'est le monstre qui vous vainc (voir chapitre « Mort d'un personnage »).
Si vous tombez sur un piège, vous perdrez des points de compétence ou des points de vie, comme indiqué sur la carte. Au contraire, si vous récupérez un trésor, vous gagnerez des points de compétence ou des points de vie, comme indiqué sur la carte.
Votre tour se termine ainsi. Si vous n'êtes pas mort, vous regagnez automatiquement 5 points de vie après chaque tour, quelque soit la carte sur laquelle vous êtes tombé.
La main passe au joueur suivant, qui peut lui aussi à présent retourner une carte du donjon. La partie se termine dès qu'un joueur parvient à tuer un des boss du donjon (voir « Fin de partie »). 
Il n'est pas possible de visiter à nouveau une pièce déja visitée. Si toutes les pièces ont déjà été visitées, un nouveau donjon est généré mais les personnages conservent leurs points de vie et de compétences.

### Attributs des personnages

Les personnages possédent trois compétences :
- L'attaque : elle détermine les dégâts que vous faites à votre adversaire lorsque vous l'attaquez.
- La défense : elle détermine les dégâts que vous êtes capable d'absorber sans perdre de points de vie lorsqu'un adversaire vous attaque.
- L'agilité : elle détermine votre capacité à esquiver les attaques d'un adversaire. Une attaque esquivée ne vous fera aucun dégât.

En plus de ces trois compétences, les joueurs possèdent des points de vie :
- Points de vie : ils déterminent votre état de santé actuel. S'ils tombent à 0, votre personnage meurt.

Les compétences et les points de vie possèdent une valeur courante, qui représentent les points que vous possédez réellement. Ceux-ci changeront tout au long de votre aventure. 
Ils sont indiqués sur votre carte de personnage, juste après le nom de la compétence. \
Les compétences et les points de vie possèdent également une valeur maximale, qui représent le maximum de points que votre personnage peut acquérir dans une compétence. 
Ceux-ci sont fixes et ne changeront jamais durant votre aventure. Ils dépendent de votre classe et de votre race. Ils sont indiqués sur votre carte de personnage, juste après la valeur courante de chaque compétence.

### Races et Classes

Le jeu présente quatre races de personages ainsi que quatre classes. Ces races et ces classes vont vous donnez droit à des bonus au début de votre aventure.
Les quatre races présentes sont :
- Humain : Points de vie +20 et Points de vie Max +100
- Nordique : Attaque +10 et Attaque Max +40
- Nain : Défense +5 et Défense Max +30
- Elf : Agilité +10 et Agilité Max +40

Les quatre classes présentes sont :

- Prêtre : Points de vie +20 et Points de vie Max +100
- Assassin : Attaque +10 et Attaque Max +40
- Paladin : Défense +5 et Défense Max +30
- Voleur : Agilité +10 et Agilité Max +40

### Déroulement des combats

#### Combat

Tout comme vos personnages, les monstres possédent une attaque, une défense, et des points de vie.
Il est à noter qu'ils ne possèdent pas de points d'agilité. En effet, ils sont incapables, contrairement à vous, d'esquiver les attaques. \
Quand vous lancez un combat, vous attaquez en premier. Le combat se joue en plusieurs tours (que vous ne voyez pas à l'écran). A chaque tour, vous infligerez à votre ennemi des dégâts correspondant à vos points d'attaque moins ses points de défense.
Si votre adversaire est encore en vie, il riposte. De le même façon que vous, il vous inflige des dégâts correspondant à ses points d'attaque moins vos points de défense. Cependant, votre personnage va tenter d'esquiver les coups de votre ennemi. 
La réussite d'une esquive dépend de vos points d'agilité. Par exemple, si vous possédez 15 points d'agilité, vous avez 15% de chances d'esquiver le coup de votre adversaire. 
Si votre personnage et votre ennemi possèdent tous les deux encore des points de vie après le premier tour, un deuxième tour se lance sur le même principe. Puis un troisième, un quatrième, ... et ainsi de suite jusqu'à ce qu'un des deux personnages (votre personnage ou le monstre) voit ses points de vie tomber à 0.
Comme dit précédemment, ces tours ne sont pas montrés à l'écran et vous aurez l'impression que les combats sont instantanés, mais c'est en réalité ainsi qu'ils se déroulent. \
Si le monstre a eu raison de vous, votre personnage meurt (voir chapitre « Mort d'un personnage »). \
Si vous parvenez à tuer le monstre, vous gagnez des points de compétence. Une des vos trois compétences tirée au hasard va être augmentée. Elle est augmentée d'un nombre de points égal au niveau du monstre, qui est visible sur la carte du monstre, après les points de vie 
(tuer un monstre niveau 3 par exemple vous offrira trois points de plus dans un de vos trois compétences).
Plus un monstre est difficile à tuer, plus il est de haut niveau, et donc plus il rapporte de points si vous parvenez à le tuer.
Attention cependant, car même si vous sortez vainqueur du combat, vous ne regagnerez pas les points de vie perdus lors du combat. Soyez donc prudent et gardez toujours un oeil sur vos points de vie avant de vous lancer dans un combat.

Remarque : Si le défense de votre personnage est plus forte que l'attaque du monstre et que la défense du monstre est plus forte que votre attaque, le combat ne se fait pas. Vous ne gagnez pas de points de compétence mais ne perdez pas de points de vie.

#### Fuite

Si vous choisissez de fuir un combat, votre personnage à une chance sur quatre (quelques soit vos compétences) de se prendre un coup dans le dos qui lui fera immédiatement perdre la moitié de sa vie. 
Si vous possédez un nombre de points de vie impair, le résultat sera arrondi en votre faveur. Vous ne pouvez ainsi pas mourir lorsque vous choisissez de fuir (mais vous pouvez perdre beaucoup de points de vie).

### Mort d'un personnage

Quand les points de vie d'un personnage atteignent 0, il meurt. Cela n'est pas définitif, et le joueur concerné va pouvoir continuer de jouer au tour suivant.
Cependant, son personnage aura retrouvé toutes ses statistiques de base (comme au début du jeu), perdant ainsi tous les bonus qu'il aurait pu récupérer au cours de son aventure. 

### Fin de partie

Au cours de votre aventure, vous croiserez de nombreux monstres, dont certains bien plus puissants appelés boss. Le premier d'entre vous qui parvient en éliminer un gagne la partie.
Les combats de boss se déroulent comme des combats classiques, mais les ennemis boss sont très forts et il vous sera absolument impossible de les vaincre si vous n'avez pas auparavant augmenté les compétences de votre personnage en trouvant des trésors et en battant des monstres plus faibles.
(À noter que si le jeu indique votre victoire, il ne s'arrête pas pour autant. Cela peut notamment permettre aux autres joueurs de continuer la partie s'ils le désirent).