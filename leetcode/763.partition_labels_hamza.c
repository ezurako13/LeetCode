#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int* partitionLabels(char * s, int* returnSize);

size_t openbsd_strlcpy(char *dst, const char *src, size_t dsize)
{
	const char *osrc = src;
	size_t nleft = dsize;

	/* Copy as many bytes as will fit. */
	if (nleft != 0) {
		while (--nleft != 0) {
			if ((*dst++ = *src++) == '\0')
				break;
		}
	}

	/* Not enough room in dst, add NUL and traverse rest of src. */
	if (nleft == 0) {
		if (dsize != 0)
			*dst = '\0';		/* NUL-terminate dst */
		while (*src++)
			;
	}

	return(src - osrc - 1);	/* count does not include NUL */
}

int main(){

    char *s=calloc(500,sizeof(char));
    scanf("%s",s);

    int count,*copy;
    copy=(partitionLabels(s,&count));
    for(int i=0;i<count;i++)
        printf("%d ",copy[i]);
    printf("\n%d",count);

    return 0;

}

int* partitionLabels(char * s, int* returnSize)
{
    int *count,*copy=NULL,counter=0;
    int i=0, b=strlen(s),j=0,o=0,control=0,control2=0,a=0;
    char array[27];

        while(i<=b)
        {
        
            control2=0;
            while(j<i)
            {
                control=0;
                
                while(s[control+i]!=0)
                {
                    if(s[j]==s[control+i])
                    {
                        control2++;
                    }
                    control++;
                    array[j]=s[j];
                }
                j++;
            }
            if(control2==0 )
            {
                openbsd_strlcpy (array,s+a,i-a+1);
                counter++;
                o++;
                printf("\no= %d s+a= %s\n", o, s+a);
                count=calloc(o,sizeof(int));
                count[o-1]=i-a;

                for(int xd=0;xd<o-1;xd++)
                   count[xd]=copy[xd];
                if(copy!=NULL)
                    free(copy);
                copy=count;
                a=i;
                j=i;
            }
            else
                j=0;
            i++;
        }
        for (int i=0;i<o-1;i++)
            copy[i]=copy[i+1];
        copy[i]=0;
        *returnSize=o-1;
    return copy;

}
