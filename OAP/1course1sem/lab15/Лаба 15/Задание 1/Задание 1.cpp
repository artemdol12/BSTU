#include <stdio.h>	
#include <stdlib.h>
#include <iostream>
void main()
{ 	
     int *ptr, i, n, max = 0; 
	 using namespace std;
	 setlocale(LC_CTYPE, "RUSSIAN");
	printf("Input size of massiv, n<30 \n");
	cin >> n;

	if(!(ptr = (int*)malloc(n*sizeof(int))))   //выделение памяти и проверка, 
{	                                      //достаточно ли для нее места
     puts("Not enough memory");           		
	return;                                        
}                   
	for (i = 0;  i < n;  i++)
	{	
           printf("Input element [%d]\n" , i + 1);
		cin >> *(ptr + i);
	}
	printf("\nMassiv: \n", i + 1);
	for (i = 0;  i < n;  i++)
		printf("%d ", *(ptr + i));
	for (i = 0; i < n; i++) {
		if ( max < *(ptr + i))
			max = *(ptr + i);
	}
	printf("\n Максимальный элемент = ");
	printf("%d", max);
           free(ptr);     //освобождение динамической памяти

}
