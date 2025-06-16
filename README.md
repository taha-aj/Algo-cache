# Algo-cache
Le but du projet c'est d'optimiser en réduisant les défauts de cache.

# Détails:

English version below 
-----------------------------------------------------------------------------------------------

-----------------------------------------------------------------------------------------------
French version: 
-----------------------------------------------------------------------------------------------
Projet : Optimisation de l'algorithme de distance d'édition

Ce projet explore différentes stratégies d'implémentation de l'algorithme de distance d'édition entre deux séquences, 
avec un accent particulier sur l'optimisation de l'utilisation du cache mémoire.

Méthodes abordées :
-------------------

1. **Récursif avec mémoïsation** :
   - Implémentation classique récursive avec stockage des sous-résultats.
   - Problème : consomme O(N × M) mémoire, peu efficace sur de grandes entrées.

2. **Itératif optimisé en espace mémoire O(N + M)** :
   - Implémentation utilisant deux tableaux unidimensionnels.
   - Réduction drastique de l'espace mémoire nécessaire.
   - Moins de défauts de cache comparé au récursif.

3. **Cache-aware** :
   - Algorithme en blocs (blocking) avec connaissance explicite de la taille du cache.
   - Les blocs sont dimensionnés pour tenir dans le cache afin de maximiser la réutilisation locale des données.
   - Implémentation plus complexe, mais efficace en pratique sur les grandes tailles de données.

4. **Cache-oblivious** :
   - Version récursive de l’algorithme divisée en sous-problèmes sans connaissance préalable de la taille du cache.
   - Permet une hiérarchie naturelle d’accès mémoire optimisée.
   - Comporte une étape de seuil pour basculer vers l’itératif lorsque le sous-problème devient assez petit.

Expérimentations :
------------------
- Mesures faites avec `valgrind --tool=cachegrind` pour observer les défauts de cache (#Drefs, #D1miss).
- Comparaison des temps d'exécution, du CPU et de l’énergie consommée (via RAPL).
- Tests sur différentes tailles de séquences (jusqu’à M = 20M et N = 19M).
- Estimation des ressources pour l’alignement de séquences réelles.

Résultats :
-----------
- Le programme **cache-oblivious** est globalement le plus performant.
- Il réduit les transferts mémoire et les défauts de cache tout en gardant une bonne scalabilité.
- Temps CPU estimé pour le test 5 (séquences longues) : **~35 jours**.
- Énergie estimée : **~23,41 kWh**.

Conclusion :
------------
Ce projet met en évidence l’impact considérable de la gestion fine du cache sur les performances des algorithmes. 
Les versions cache-aware et cache-oblivious, bien que plus complexes, montrent des gains significatifs sur les grandes instances.



-----------------------------------------------------------------------------------------------
English version: 
-----------------------------------------------------------------------------------------------
Project: Optimization of the Edit Distance Algorithm

This project explores various strategies for implementing the edit distance algorithm between two sequences, 
with a particular focus on optimizing memory cache usage.

Implemented Methods:
--------------------

1. **Recursive with memoization**:
   - Classical recursive implementation with storage of intermediate results.
   - Issue: consumes O(N × M) memory, inefficient for large inputs.

2. **Iterative optimized for memory O(N + M)**:
   - Implementation using two one-dimensional arrays.
   - Drastically reduces the required memory space.
   - Fewer cache misses compared to the recursive approach.

3. **Cache-aware**:
   - Blocked algorithm using explicit knowledge of cache size.
   - Blocks are sized to fit in cache to maximize local data reuse.
   - More complex implementation, but very effective for large-scale data.

4. **Cache-oblivious**:
   - Recursive version of the algorithm divided into sub-problems without prior knowledge of the cache size.
   - Allows for a natural hierarchical memory access pattern.
   - Includes a threshold mechanism to switch to the iterative method when the subproblem is small enough.

Experiments:
------------
- Measurements taken with `valgrind --tool=cachegrind` to observe cache misses (#Drefs, #D1miss).
- Comparison of execution time, CPU time, and energy consumption (via RAPL).
- Tests run on different sequence sizes (up to M = 20M and N = 19M).
- Resource estimation for alignment of real biological sequences.

Results:
--------
- The **cache-oblivious** implementation is overall the most efficient.
- It reduces memory transfers and cache misses while maintaining good scalability.
- Estimated CPU time for test 5 (long sequences): **~35 days**.
- Estimated energy consumption: **~23.41 kWh**.

Conclusion:
-----------
This project highlights the significant impact of careful cache management on algorithm performance. 
Cache-aware and cache-oblivious versions, although more complex, provide substantial improvements on large problem instances.
