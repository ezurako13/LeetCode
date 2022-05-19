#include <stdio.h>
#include <stdlib.h>

int* partitionLabels(char * s, int* returnSize);


int main()
{
	char s[]= "ababcbacadefegdehijhklij";
	//char s[]= "caedbdedda";
	//char s[]= "jybmxfgseq";

	//int i= 0, o= 0, var= 0, boyut= sizeof(s);
	//int harfsayaci= 0, arraysayisi= 0;
	
	//if(boyut > 26)	boyut= 26;
	//char *arrayler[boyut];
	//arrayler[0]= s;
	//arraysayisi++;

	//printf("\n(main:) sizeof(s)= %lu", sizeof(s));
	//printf("\n(main:) s= %s\n", s);

	//char harf[128]= {0};
/*
	i =0;
	while(s[i] != '\0')
	{
		o= i +1;
		var= 0;
		while(var == 0 && s[o] != '\0')
		{
			if(s[o] == s[i])
			{
				var= 1;
			}
			o++;
		}

		if(var == 1)
		{
			if(harf[ s[i] ] == 0)
				harfsayaci++;
			harf[ s[i] ]= 1;
		}
		
		else
		{
			if(harf[ s[i] ] == 1)
				harfsayaci--;
			harf[ s[i] ]= 0;
		}

		if(harfsayaci == 0)
		{
			arrayler[arraysayisi]= s +i +1;
			arraysayisi++;
		}

		i++;
	}

	for(int a= 0; a < arraysayisi -1; a++)
	{
		printf("\nar[%d= %lu", a, arrayler[a]);
		printf("\nar[%d= %s\n", a, arrayler[a]);
	}
*/
	int *sonuc; //= (int *)maloc( (arraysayisi -1) *sizeof(int) );
	
	
	int returnSize= 0;
	sonuc= partitionLabels(s, &returnSize);

	printf("\n\n(main:) returnSize= %d\n", returnSize);

	printf("\n[");
	for(int a= 0; a < returnSize; a++)
	{
		//sonuc[a]= (int)(arrayler[a+1] -arrayler[a]);
		if(a == 0)	printf("%d", sonuc[a]);
		else	printf(",%d", sonuc[a]);
	}
	printf("]\n");



	return 0;
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* partitionLabels(char * s, int* returnSize)
{
	int i= 0, o= 0, var= 0;
	int harfsayaci= 0, arraysayisi= 0;
	
	char *arrayler[27]= {};
	arrayler[0]= s;
	arraysayisi++;

	//printf("\n(partitionLabels:) sizeof(s)= %lu", sizeof(s));
	//printf("\n(partitionLabels:) s= %s\n", s);

	char harf[128]= {0};

	i =0;
	while(s[i] != '\0')
	{
		o= i +1;
		var= 0;
		while(var == 0 && s[o] != '\0')
		{
			if(s[o] == s[i])
			{
				var= 1;
			}
			o++;
		}

		if(var == 1)
		{
			if(harf[ s[i] ] == 0)
				harfsayaci++;
			harf[ s[i] ]= 1;
		}
		
		else
		{
			if(harf[ s[i] ] == 1)
				harfsayaci--;
			harf[ s[i] ]= 0;
		}

		if(harfsayaci == 0)
		{
			arrayler[arraysayisi]= s +i +1;
			arraysayisi++;
		}

		i++;
	}

	//for(int a= 0; a < arraysayisi -1; a++)
	//{
	//	printf("\n(partitionLabels:) ar[%d= %lu", a, (long unsigned int)arrayler[a]);
	//	printf("\n(partitionLabels:) ar[%d= %s\n", a, arrayler[a]);
	//}
	
	//printf("\n[");

	//printf("\n(partitionLabels:) arraysayisi= %d", arraysayisi);

	int *sonuc= (int *)malloc( (arraysayisi -1) *sizeof(int) );
	for(int a= 0; a < arraysayisi -1; a++)
	{
		//printf("%d,", (int)(arrayler[a+1] -arrayler[a]));
		sonuc[a]= (int)(arrayler[a+1] -arrayler[a]);
	}
	//printf("]\n");

	*returnSize= arraysayisi -1;

	return sonuc;
}
