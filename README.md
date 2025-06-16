# Algo-cache

The goal of this project is to optimize an algorithm by reducing cache misses.

**➡️ French version below**

---

## 🇬🇧 English version

### Project: Optimization of the Edit Distance Algorithm

This project explores different strategies for implementing the edit distance algorithm between two sequences, with a focus on optimizing cache memory usage.

### Implemented Methods:

1. **Recursive with memoization**:
   - Classical recursive version with intermediate results stored.
   - Consumes O(N × M) memory – inefficient for large inputs.

2. **Iterative optimized for memory O(N + M)**:
   - Uses two one-dimensional arrays.
   - Drastically reduces memory usage.
   - Fewer cache misses than the recursive version.

3. **Cache-aware**:
   - Uses blocking with explicit cache size knowledge.
   - Enhances data locality and reuse.
   - More complex but highly efficient.

4. **Cache-oblivious**:
   - Recursive divide-and-conquer strategy without knowing cache size.
   - Enables automatic memory hierarchy optimization.
   - Switches to iterative when subproblems are small.

### Folder Structure:

- `src/`: Contains all source files, including implementations of recursive, iterative, cache-aware, and cache-oblivious versions of the edit distance algorithm.

### Experiments:
- Used `valgrind --tool=cachegrind` to analyze cache misses.
- Measured execution time, CPU time, and energy usage (via RAPL).
- Tested on sequence sizes up to M = 20M and N = 19M.
- Estimated resources needed for real-world genomic sequences.

### Results:
- **Cache-oblivious** is the most efficient method overall.
- Estimated CPU time for test 5: **~35 days**
- Estimated energy usage: **~23.41 kWh**

### Conclusion:
This project demonstrates the major impact of fine-grained cache optimization.  
Despite added complexity, cache-aware and cache-oblivious approaches show substantial performance gains on large-scale problems.

---

## 🇫🇷 Version française

### Projet : Optimisation de l'algorithme de distance d'édition

Ce projet explore différentes stratégies d'implémentation de l'algorithme de distance d'édition entre deux séquences, avec un accent particulier sur l'optimisation de l'utilisation du cache mémoire.

### Méthodes abordées :

1. **Récursif avec mémoïsation** :
   - Implémentation récursive classique avec stockage des sous-résultats.
   - Consomme O(N × M) mémoire, peu efficace pour de grandes entrées.

2. **Itératif optimisé en espace mémoire O(N + M)** :
   - Utilise deux tableaux unidimensionnels.
   - Réduction significative de l’espace mémoire.
   - Moins de défauts de cache comparé au récursif.

3. **Cache-aware** :
   - Utilise une stratégie de *blocking* avec connaissance de la taille du cache.
   - Meilleure réutilisation locale des données.
   - Implémentation plus complexe, mais très efficace.

4. **Cache-oblivious** :
   - Version récursive divisée en sous-problèmes sans connaissance du cache.
   - Accès mémoire hiérarchique optimisé.
   - Un seuil permet de basculer vers la version itérative.

### Structure du dépôt :

- `src/` : contient tous les fichiers sources, y compris les implémentations récursive, itérative, cache-aware et cache-oblivious de l'algorithme de distance d'édition.

### Expérimentations :
- Analyse via `valgrind --tool=cachegrind` pour observer les défauts de cache.
- Mesures de temps CPU, temps réel et énergie (via RAPL).
- Tests sur des tailles allant jusqu’à M = 20M et N = 19M.
- Estimation des ressources pour des données génomiques réelles.

### Résultats :
- **Cache-oblivious** est la méthode la plus performante globalement.
- Temps CPU estimé pour un grand test : **~35 jours**
- Énergie consommée estimée : **~23,41 kWh**

### Conclusion :
Ce projet montre l’impact considérable de la gestion fine du cache.  
Les approches *cache-aware* et *cache-oblivious* apportent des gains notables sur les grandes instances.
