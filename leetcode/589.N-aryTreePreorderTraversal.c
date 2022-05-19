#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    int numChildren;
    struct Node **children;
} Node;


int* preorder(struct Node* root, int* returnSize);
void recursiveNode(struct Node* root, int **array, int* returnSize, int *arraySize, int *copy);
int* preorderYunus(struct Node* root, int* returnSize);
void recursive(struct Node* root, int *returnSize, int *array);



int main()
{
	Node *root= NULL, **cocuklar= NULL;
	//int *arrayroot= NULL;33 23 51 39,9, ,99, 100, 67
	
	//int arrayroot[]= {1,-1,3,2,4,-1,5,6};
	int arrayroot[]= {1,-1,2,3,4,5,-1,-1,6,7,-1,8,-1,9,10,-1,-1,11,-1,12,-1,13,-1,-1,14};
	// int arrayroot[]= {48,-1,79,0,94,-1,-1,44,64,-1,69,71,46,-1,-1,45,-1,2,9,22,-1,57,
	// 77,31,-1,8,56,1,-1,59,86,0,-1,-1,100,99,67,-1,69,79,24,-1,2,66,-1,11,76,-1,-1,
	// 95,58,78,-1,97,53,-1,100,-1,42,-1,38,99,54,-1,21,12,23,-1,34,39,-1,-1,-1,-1,
	// -1,100,82,-1,81,41,-1,-1,-1,21,59,-1,-1,-1,12,16,-1,-1,-1,57,99,-1,69,73,
	// 31,-1,30,66,50,-1,34,-1,5,11,60,-1,-1,32,97,16,-1,27,-1,-1,34,92,-1,66,39,85,
	// -1,6,-1,66,-1,62,-1,60,-1,-1,95,91,-1,32,-1,-1,5,-1,-1,9,27,-1,36,-1,
	// 98,10,-1,-1,-1,98,-1,68,4,-1,-1,1,-1,82,78,-1,-1,87,93,-1,70,73,69,-1,18,
	// 15,-1,19,-1,100,64,-1,40,52,-1,49,78,-1,35,-1,-1,38,1,-1,45,21,47,-1,-1,83,
	// -1,37,-1,8,65,8,-1,46,65,23,-1,47,87,-1,92,41,29,-1,-1,96,14,-1,79,41,-1,-1,
	// 90,32,-1,92,51,-1,96,80,98,-1,86,-1,-1,53,45,-1,78,57,3,-1,98,6,-1,-1,70,-1,
	// 27,14,42,-1,24,-1,37,91,-1,38,48,8,-1,-1,56,32,53,-1,33,-1,55,8,75,-1,17,39,92,
	// -1,-1,60,44,9,-1,-1,63,35,11,-1,19,52,61,-1,71,55,-1,53,95,0,-1,-1,27,67,-1,
	// -1,11,-1,-1,96,-1,29,-1,75,40,15,-1,93,-1,21,13,-1,-1,-1,83,59,59,-1,72,
	// -1,100,98,-1,-1,41,-1,-1,2,96,16,-1,40,66,-1,-1,-1,32,-1,99,2,54,-1,2,4,68,
	// -1,25,-1,-1,27,8,57,-1,42,-1,25,48,-1,28,17,99,-1,84,64,86,-1,22,-1,7,42,28,-1,
	// 40,59,14,-1,6,12,42,-1,-1,-1,-1,-1,75,-1,12,-1,78,10,61,-1,40,-1,52,-1,-1,
	// -1,54,56,-1,26,53,-1,82,-1,-1,68,59,4,-1,90,-1,78,87,-1,79,-1,85,-1,90,58,-1,
	// 10,-1,-1,87,-1,78,-1,76,-1,-1,86,-1,46,53,-1,20,21,51,-1,-1,79,50,69,-1,94,
	// -1,-1,20,3,-1,24,87,-1,52,81,33,-1,-1,-1,57,90,21,-1,56,-1,52,66,-1,76,94,-1,
	// 78,85,-1,65,91,-1,19,-1,71,-1,-1,84,36,-1,38,-1,-1,63,1,71,-1,38,93,-1,27,-1,
	// 50,-1,39,-1,80,24,-1,67,60,-1,41,19,87,-1,29,86,98,-1,79,33,57,-1,89,36,-1,30,-1,
	// 13,-1,17,93,-1,-1,-1,-1,-1,17,-1,79,-1,44,-1,34,-1,12,3,54,-1,-1,-1,71,33,
	// -1,9,0,-1,89,0,-1,0,-1,80,14,-1,52,-1,45,18,-1,89,-1,-1,13,-1,71,46,91,-1,-1,
	// 1,77,52,-1,5,-1,36,-1,47,65,69,-1,-1,83,91,-1,59,-1,75,90,-1,35,-1,22,55,-1,56,
	// 7,-1,77,100,34,-1,73,23,-1,7,-1,86,59,43,-1,75,98,58,-1,55,53,-1,76,-1,9,62,-1,71,
	// 43,-1,-1,67,-1,61,44,48,-1,69,69,-1,39,-1,41,65,52,-1,39,39,20,-1,-1,-1,-1,6,
	// 77,83,-1,11,97,-1,81,-1,-1,64,7,-1,50,9,0,-1,47,76,34,-1,-1,30,16,-1,-1,-1,3,
	// 94,53,-1,61,23,-1,100,12,-1,77,6,-1,32,5,-1,-1,82,50,47,-1,76,39,72,-1,-1,84,8,
	// -1,21,49,-1,17,12,16,-1,33,-1,-1,2,57,-1,60,24,-1,88,27,-1,-1,-1,48,88,55,-1,
	// 88,72,28,-1,24,64,41,-1,56,16,-1,45,13,16,-1,-1,64,19,35,-1,-1,45,81,-1,6,29,84,-1,
	// 66,-1,-1,-1,-1,65,-1,-1,19,61,-1,-1,-1,68,50,-1,14,-1,-1,11,-1,68,66,23,
	// -1,-1,33,79,-1,63,-1,-1,74,71,-1,49,-1,1,-1,18,7,58,-1,40,34,-1,37,44,-1,-1,
	// 89,-1,88,-1,-1,69,-1,80,64,-1,0,34,11,-1,69,40,81,-1,42,71,-1,42,10,-1,-1,98,49,
	// 17,-1,42,96,-1,16,64,-1,92,-1,39,41,-1,43,84,-1,-1,32,57,50,-1,68,-1,-1,-1,
	// 59,13,43,-1,-1,41,-1,5,-1,58,-1,84,16,-1,42,-1,42,37,40,-1,64,51,-1,34,-1,4,
	// -1,61,27,-1,21,-1,88,-1,71,-1,47,23,30,-1,-1,46,-1,13,-1,64,56,27,-1,43,39,95,
	// -1,99,74,-1,65,82,-1,-1,28,75,-1,15,0,75,-1,77,73,-1,45,93,-1,11,15,-1,-1,79,
	// 33,23,-1,8,17,76};

	int nodesayisi= 0, kokboyutu= 0, cocuksayisi= 0;
	int baba= 0, evlat= 2;

	if(arrayroot != NULL)
	{
		kokboyutu= sizeof(arrayroot) /sizeof(int);
		root= (Node *)calloc(kokboyutu, sizeof(Node));
	}
	printf("\nkokboyutu= %d sizeof(Node)= %d \n\n", kokboyutu, (int)sizeof(Node));

	for(int i= 0; i < kokboyutu; i++)
		root[i].val= arrayroot[i];

	printf("root[i].val= ");
	for(int i= 0; i < kokboyutu; i++)
		printf("%d, ", root[i].val);
	printf("\n");


	while(evlat < kokboyutu)
	{
		//printf("\nxd\n");
		//root[baba].children[cocuksayisi]= &root[evlat];
		printf("\n%d -> %d",root[baba].val, root[evlat].val);
		
		if(root[evlat].val == -1)
		{

			if(cocuksayisi > 0)
			{
				//printf("\nxd\n");
				//printf("\n%d ->",root[baba].val);
				printf("\nbaba %d -> cocuksayisi= %d\n", root[baba].val, cocuksayisi);

				cocuklar= (Node **)calloc(cocuksayisi+1, sizeof(Node *));
				//printf("\n&cocuklar= %p\n",cocuklar);
				
				for(int i= 0; i < cocuksayisi; i++)
				{
					cocuklar[i]= &root[evlat -cocuksayisi +i];
				}
				root[baba].children= cocuklar;
				for(int i= 0; i < cocuksayisi; i++)
				{
					printf("\t%d\n", root[baba].children[i]->val);
				}
			}	
			cocuksayisi= 0;
			baba++;
			while(root[baba].val == -1)	baba++;
		}
		
		else
		{
			root[baba].numChildren++;
			cocuksayisi++;
			
		}

		evlat++;

		if(evlat == kokboyutu)
		{
			printf("\nbaba %d -> cocuksayisi= %d\n", root[baba].val, cocuksayisi);
	
			cocuklar= (Node **)calloc(cocuksayisi+1, sizeof(Node *));

			for(int i= 0; i < cocuksayisi; i++)
			{
				cocuklar[i]= &root[evlat -cocuksayisi +i];
			}
			root[baba].children= cocuklar;
			for(int i= 0; i < cocuksayisi; i++)
			{
				printf("\t%d\n", root[baba].children[i]->val);
			}
		}

	}


	printf("\n");
	int *sayilar= NULL;
	sayilar= preorder(root, &kokboyutu);

	if(root != NULL && sayilar != NULL)
	{
		printf("\nsayilar= %d", sayilar[0]);
		for(int i= 1; i < kokboyutu; i++)
			printf(", %d", sayilar[i]);
		printf("\n");
	}


	return 0;
}





/* Given the root of an n-ary tree, return the preorder traversal of its nodes' values.

Note: The returned array must be malloced, assume caller calls free(). */
int* preorder(struct Node* root, int* returnSize)
{
	int arraySize= 20;
	int *array= (int *)calloc(arraySize, sizeof(int));
	int *copy= array;
	*returnSize= 0;

	//if(*returnSize > 0)
	//printf("ilk array= %d", array[0]);
	//for(int i= 1; i < *returnSize && array[i] != 0; i++)
	//	printf(", %d", array[i]);
	//printf("\n\n");
    
    if(root == NULL)
    {
        array= (int *)realloc(array, *returnSize *4);
        return array;
    }
	recursiveNode(root, &array, returnSize, &arraySize, copy);

	//copy= (int *)realloc(copy, *returnSize *4);

	//if(*returnSize > 0)
	//printf("\nson array= %d", array[0]);
	//for(int i= 1; i < *returnSize && array[i] != 0; i++)
	//	printf(", %d", array[i]);
	//printf("\n");

	return copy;
}

int tavuk= 0, tavuklar= -1;

void recursiveNode(struct Node* root, int **array, int* returnSize, int *arraySize, int *copy)
{
	//if(tavuk == tavuklar)	printf("\033[1;33m\n\nNaber! \033[0m");
	**array= root->val;
	
	//printf("\nroot->val= %d", root->val);
	//printf("\t**array= %d", **array);	
	
	(*array) += 1;
	(*returnSize) += 1;
	//if(tavuk == tavuklar)	printf("\033[1;33m\n\nGelmedi senden bi haber. \033[0m");
	if(*returnSize == *arraySize)
	{
		//printf("\n\nonce *returnSize= %d *arraySize= %d", *returnSize, *arraySize);
		
		//printf("\ncopy=\t%d", copy[0]);
		//for(int i= 1; i < *arraySize; i++)
		//	printf(", %d", copy[i]);
		//printf("\n");
		
		//printf("\n*array=\t%d", (*array)[0- *arraySize]);
		//for(int i= 1; i < *arraySize; i++)
		//	printf(", %d", (*array)[i -*arraySize]);
		//printf("\n");

		*arraySize += 100;
		copy= (int *)realloc(copy, *arraySize* sizeof(int));

		//printf("sonra *returnSize= %d *arraySize= %d \n\n", *returnSize, *arraySize);
	}
	//if(tavuk == tavuklar)	printf("\033[1;33m\n\nMerak ettik. \033[0m");

	for(int i= 0; i < root->numChildren; i++)
	{
		//if(tavuk == tavuklar)	printf("\033[1;33m\n\nOldun mu kaldin mi endiselendik. \033[0m");
		//if(tavuk == tavuklar)	printf("\n\n");
		//
		//printf("tavuk= %d  root-> %d  child[%d]-> %d\n", tavuk, root->val, i, root->children[i]->val);
		//
		//if(tavuk == tavuklar)	printf("\033[1;33mBu hayat cok zor malum, hele yanlizsan. \033[0m");
		//if(tavuk == tavuklar)	printf("\n\n");

		tavuk++;
		recursiveNode(root->children[i], array, returnSize, arraySize, copy);
	}

}

int* preorderYunus(struct Node* root, int* returnSize)
{
    int *array = (int *)malloc(10000*sizeof(int));
    *returnSize = 0;
    recursive(root,returnSize,array);
    return array;
    
}

void recursive(struct Node* root, int *returnSize, int *array)
{
    int i;
    if(root->numChildren == 0 )
    {
        array[*returnSize] = root->val;
        *returnSize += 1;
    }
    else
    {
        array[*returnSize] = root->val;
        *returnSize += 1;
        for(i = 0; i<root->numChildren; i++)
        {
            recursive(root->children[i],returnSize,array);
        }
    }
}
