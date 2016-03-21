//////////////////////////////////////////////////////////////////////////////////////
//Name 			:rabin_karp.c
//Copyright 	:Copyright Vivek Malik,2012
//Created on	:22-Apr-2012
//Author		:Vivek Malik
//Description 	:Finding a pattern from a text using Rabin Karp Algorithm
//////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<string.h>

#define d 256

void search(char pat[], char txt[], int q)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int i, j;
    int p = 0;  // hash value for pattern
    int t = 0; // hash value for txt
    int h = 1;

    // The value of h would be "pow(d, M-1)%q"
    for (i = 0; i < M-1; i++)
        h = (h*d)%q;

    // Calculate the hash value of pattern and first window of text
    for (i = 0; i < M; i++)
    {
        p = (d*p + pat[i])%q;
        t = (d*t + txt[i])%q;
    }

    // Slide the pattern over text one by one
    for (i = 0; i <= N - M; i++)
    {

        // Chaeck the hash values of current window of text and pattern
        // If the hash values match then only check for characters on by one
        if ( p == t )
        {
            /* Check for characters one by one */
            for (j = 0; j < M; j++)
            {
                if (txt[i+j] != pat[j])
                    break;
            }
            if (j == M)  // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]
            {
                printf("Pattern found at index %d \n", i);
            }
        }

        // Calulate hash value for next window of text: Remove leading digit,
        // add trailing digit
        if ( i < N-M )
        {
            t = (d*(t - txt[i]*h) + txt[i+M])%q;

            // We might get negative value of t, converting it to positive
            if(t < 0)
              t = (t + q);
        }
    }
}

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
    char txt[100];
    char pat[50];
    printf("Text		:");
    gets(txt);
    printf("Pattern		:");
    gets(pat);
    int q = 101;  // A prime number
    search(pat, txt, q);
    return 0;
}

/*  pat  -> pattern
    txt  -> text
    q    -> A prime number
*/


// d is the number of characters in input alphabet
