# Pour la liste chaînée
```time ./main_abr zebre  5 000 000```  
real    0m1,147s  
user    0m1,120s  
sys     0m0,026s  

```time ./main_abr vache  50 000 000```  
real    0m11,504s  
user    0m11,487s  
sys     0m0,016s

# Pour l'arbre lexicographique 
```time ./main_arbre zebre  5 000 000```  
real    0m1,210s  
user    0m1,200s  
sys     0m0,010s  

```time ./main_arbre vache  50 000 000```  
real    0m9,449s  
user    0m9,438s  
sys     0m0,010s  

# Pour l'arbre lexicographique *bis*  
```time ./main_arbre_tab.c zebre  5 000 000```  
real    0m0,274s  
user    0m0,209s  
sys     0m0,065s  

```time ./main_arbre_tab vache  50 000 000```     
real    0m1,129s  
user    0m1,062s  
sys     0m0,067s  