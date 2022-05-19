#include <stdio.h>
#include <stdlib.h>


/* Definition for singly-linked list. */
typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;


void addNode(ListNode *list, int rakam);
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);



int main()
{
	//int list1[]= {1,2,3,4,5,6};
	//int list2[]= {7,8,9,4};
	//int list1[]= {9,9,9,9,9,9,9};
	//int list2[]= {9,9,9,9};
	//int list1[]= {0};
	//int list2[]= {0};
	//int list1[]= {1};
	//int list2[]= {1};
	int list1[]= {3,6,2,1,3,4,9,3,5,1};
	int list2[]= {0,6,9,9,1,4,4,0,5};

	int len1= (int)sizeof(list1)/sizeof(int);
	int len2= (int)sizeof(list2)/sizeof(int);

	ListNode *headpointer1= (ListNode *)calloc(1, sizeof(ListNode));
	ListNode *headpointer2= (ListNode *)calloc(1, sizeof(ListNode));
	headpointer1 ->val = *list1;
	headpointer2 ->val = *list2;

	printf("\n(main): len1= %d len2= %d\n", len1, len2);

	for(int i= 1; i < len1; i++)
	{
		//printf("\n(main): before headpointer1->val= %d list1[%d]= %d\n"
		//, headpointer1->val, i, list1[i]);

		addNode(headpointer1, list1[i]);

		//printf("\n(main): after headpointer1->val= %d list1[%d]= %d\n\n\n"
		//, headpointer1->val, i, list1[i]);
	}

	for(int i= 1; i < len2; i++)
	{
		addNode(headpointer2, list2[i]);
		//printf("\nheadpointer2->val= %d\n", headpointer2->val);
	}

	ListNode *copyx= headpointer1;
	ListNode *copy= headpointer2;
	//headpointer1= NULL;
	//headpointer2= NULL;
	
	ListNode *sonuc= addTwoNumbers(headpointer1, headpointer2);
	
	headpointer1= copyx;
	headpointer2= copy;

	//printf("\nxd\n");

	ListNode *prnt= headpointer1;
	printf("\nlist1= {%d", prnt->val);
	while(prnt->next != NULL)
	{
		prnt= prnt->next;
		printf(", %d", prnt->val);
		//printf("\nxd\n");
	}
	printf("}");
	
	prnt= headpointer2;
	printf("\nlist2= {%d", prnt->val);
	while(prnt->next != NULL)
	{
		prnt= prnt->next;
		printf(", %d", prnt->val);
	}
	printf("}\n");

	prnt= sonuc;
	printf("\nsonuc= {%d", prnt->val);
	while(prnt->next != NULL)
	{
		prnt= prnt->next;
		printf(", %d", prnt->val);
	}
	printf("}\n\n");


	return 0;
}
 


void addNode(ListNode *list, int rakam)
{

	while(list->next != NULL)
	{
		//printf("\n(addnd): once list->val= %d list->next= %p", list->val, list->next);
		list= list->next;
		//printf("\n(addnd): sonra list->val= %d list->next= %p", list->val, list->next);
	}

	//list->val= rakam;
	//printf("\n(addnd): PORNO\n");
	//printf("\n(addnd): Profiterol\n");

	ListNode *newNode= (ListNode *)calloc(1, sizeof(ListNode));
	newNode->val= rakam;
	//newNode->next =NULL;

	list->next= newNode;
	
	//printf("(addnd): list->val= %d list->next= %p rakam= %d\n", list->val, list->next, rakam);



}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{

	//printf("\nl1.val= %d l2.val= %d\n", l1->val, l2->val);

	if(l1 == NULL && l2 == NULL)	return NULL;

	int eldevar= 0, toplanan= 0, l1bitti= 0, l2bitti= 0;
	struct ListNode *toplamHead= (struct ListNode *)calloc(1,sizeof(struct ListNode));
	struct ListNode *tailNode= toplamHead, *nextNode= NULL;

	struct ListNode *bosNode= (struct ListNode *)malloc(sizeof(struct ListNode));
	bosNode->val= 0;
	bosNode->next= NULL;
	/* eger listelerin uzunluklari birbirinden farkliysa ve biri biterse 
	kalan dongulerde segmentation fault yememek icin ve kucuk olan listenin 
	kalan basamaklarini sifir varsayarak islem yapmak icin bu bos nodu kullancam */

	//if(l1->val == 0 && l2->val == 0)	return bosNode;

	if(l1 == NULL || (l1->val == 0 && l1->next == NULL))
	{
		l1bitti= 1;
		l1= bosNode;
	}
	if(l2 == NULL || (l2->val == 0 && l2->next == NULL))
	{
		l2bitti= 1;
		l2= bosNode;
	}

	/* burda yazanlari sadece head node icin uygulaniyo ama 
	geri kalani da sadece bunun donguye koyulmus hali */

	/* listelerdeki o basamaktaki rakamlari ve onceki basamaktan elde kalan basamagi toplar */
	toplanan= l1->val +l2->val +eldevar;

	/* sonraki basamaga ekledim ve artik elde bi sayi kalmadi o yuzden bunu siliyom 
	ve biliyorum daha ilk basamaktan bunu yapmama gerek yoktu*/
	if(eldevar == 1)	eldevar= 0;

	/* toplanan 10dan buyukse bunlari yapar */
	if(toplanan > 9)
	{
		eldevar= 1;
		toplamHead->val= toplanan %10;
	}
	/* degilse bunu yapar */
	else	toplamHead->val= toplanan;

	/* sonraki dongude sonraki basamagi hesaplayabilmek icin 
	liste pointerlarini bir sonraki noda esitler
	burdaki if leri daha net bir bicimde asagidaki dongunun sonunda acikladim */
	if(l1bitti == 0)
	{
		l1= l1->next;
		if(l1 == NULL)	
		{
			l1bitti= 1;
			l1= bosNode;
		}
	}
	if(l2bitti == 0)
	{
		l2= l2->next;
		if(l2 == NULL)	
		{
			l2bitti= 1;
			l2= bosNode;
		}
	}


	/* bu da geri kalani jhyvhjgjv
	 bu kisim donguyu olusturdugun kisim olcak demi
	 evet */
	while(l1bitti == 0 || l2bitti == 0 || eldevar == 1)
	{
		/* iki listeden en az birinde rakam kalmis onu toplam listeme yeni node olarak eklicem */
		nextNode= (struct ListNode *)malloc(sizeof(struct ListNode));
		nextNode->next= NULL;

		/* listelerdeki o basamaktaki rakamlari ve onceki basamaktan elde kalan basamagi toplar */
		toplanan= l1->val +l2->val +eldevar;

		/* sonraki basamaga ekledim ve artik elde bi sayi kalmadi o yuzden bunu siliyom */
		if(eldevar == 1)	eldevar= 0;

		//printf("\nl1->val= %d\n", l1->val);

		/* toplanan 10dan buyukse bnnlari yapar */
		if(toplanan > 9)
		{
			eldevar= 1;
			nextNode->val= toplanan %10;
		}
		/* degilse bunu yapar */
		else	nextNode->val= toplanan;

		/* burda da yeni olusturdugum node u listenin sonun ekleyip 
		tail nodu da son ekledigim eleman yapiyorum */
		tailNode->next= nextNode;
		tailNode= tailNode->next;

		
		/* burasi kod patlamasin diye ve yaptigi sey de su
		eger herhangi bir liste bitmisse o liste pointerina bos nodun adresini atiyo ve
		o listeyi artik nextine esitlemiyo ve ayrica o listenin bitme flag ini aciyo */
		if(l1bitti == 0)
		{
			l1= l1->next;
			if(l1 == NULL)	
			{
				l1bitti= 1;
				l1= bosNode;
			}
		}
		if(l2bitti == 0)
		{
			l2= l2->next;
			if(l2 == NULL)	
			{
				l2bitti= 1;
				l2= bosNode;
			}
		}
	}

	return toplamHead;
}

