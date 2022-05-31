#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>
// bool, true, false

#include <iso646.h>
// and, or, not


size_t g_comparaciones = 0;
void heapify(int list[],size_t n,size_t k);
void build_max_heap(int list[],size_t num_elems);
void heap_sort(int list[],size_t num_elems);

void print( int* list, size_t tam, char* msg )
{
	printf("%s",msg);
	for( size_t i = 0; i < tam; ++i ){
		printf( "%d, ", list[ i ] );
	}
	printf( "\n" );
}

void swap( int* val1, int* val2 )
{
	int tmp=*val1;
	*val1=*val2;
	*val2=tmp;
}
size_t g_intercambios=0;

/**
 * @brief Mantiene el heap.
 *
 * @param list[] Una lista
 * @param n El número total de elementos en la lista
 * @param k El nivel del nodo raíz (0 para el primer nivel, 1, para el segundo
 * nivel, y así sucesivamente.)
 */
void heapify_desc( int list[], size_t n, size_t k )
{
	size_t left=2*k+1;  
	size_t right=2*k+2;
	size_t smaller=0;
	if((left<n) and (list[ left ]<list[ k ])){
		smaller= left;
	}else{
		smaller=k;
	}
	
	if((right<n) and (list[ right ] < list[smaller])){
		smaller = right;
	}
	if(smaller != k){
		++g_intercambios;
		swap( &list[k],&list[smaller]);
		heapify_desc( list,n, smaller);//recontruye el heap , crea el heap   
		print(list,n,"heapify():"); 
	} 
}

/**
 * @brief Convierte una lista de números en un montículo.
 *
 * @param list[] Una lista.
 * @param num_elems El número de elementos totales en la lista.
 *
 * @post El montículo se ve reflejado en la lista original.
 */
void build_max_heap( int list[], size_t num_elems )
{
	for(size_t k=(num_elems/2);k>0;--k){         
	heapify_desc( list,num_elems, k - 1 );    
	} 
}

/**
 * @brief Ordena una lista de números utilizando al algoritmo heap sort en forma
 * ascendente.
 *
 * @param list[] Una lista.
 * @param num_elems El número de elementos totales en la lista.
 */
void heap_sort( int list[], size_t num_elems )
{
	build_max_heap(list,num_elems); 
	//print(list,num_elems,"Heaped: ");    
	for(size_t i=num_elems;i>0;--i){
	++g_intercambios;      
	swap(&list[ 0 ],&list[i-1]);        
	heapify_desc(list,i-1,0);   
	} 
}

#define NUM_ELEMS 7

int main()
{
	int list[ NUM_ELEMS ] = {6,10,1,7,0,8,5};

	print( list, NUM_ELEMS, "  Antes: " );
	g_intercambios=0;
	heap_sort( list, NUM_ELEMS );

	print( list, NUM_ELEMS, "Despues: " );

    printf( "Se realizaron %ld intercambios.\n", g_intercambios );

}
