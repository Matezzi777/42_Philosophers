## Etapes:
### 1. Checker les inputs.										OK
Doit posséder 4 ou 5 arguments.
Tous les arguments doivent être des nombres positifs non-nuls.
### 2. Construire les structures.
Une structure pour les informations générales (= la table).
Une structure pour les philosophes.
Une structure pour les fourchettes.
### 3. Initialisation et allocations.
Remplir les structures.
Initialiser les mutexes.
Lancer les threads.
### 4. Créer les routines, superviseurs et le moniteur.
Routines : la code suivi par les philosophes.
Superviseurs : threads qui vérifient quand les philosophes meurent.
Moniteur (uniquement si meals_limit fourni) : vérifie si les philosophes ont mangé un nombre de fois suffisant.
### 5. Nettoyer la mémoire.
Join les threads.
Destroy les mutexes.
Free les mallocs.