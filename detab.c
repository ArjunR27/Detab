#include <stdio.h>
#define TABSTOP 8
int main()
{
        int chr, spaceCalc, i;
        int pos = 0;

        /* gets each character and checks if it is the EOF character or not*/
        while((chr = getchar()) != EOF)
        {
                /* if character is tab */
                if(chr == '\t')
                {
                        /* calculate the number of spaces to add*/
                        spaceCalc = TABSTOP - (pos % TABSTOP);
                        for(i = 0; i < spaceCalc; i++)
                        {
                                /*print space character and increment pos*/
                                putchar(' ');
                                pos++;
                        }
                }
                /* if characters are newline or carriage return*/
                else if (chr == '\n' || chr == '\r')
                {
                        /* print specific character, reset pos to 0*/
                        putchar(chr);
                        pos = 0;
                }
                /* if character is backspace*/
                else if (chr == '\b')
                {
                        /* decrement pos, check if pos is on left margin
                           (if pos is before left margin, reset pos to 0),
                           print specific character. */
                        pos--;
                        if(pos < 0)
                        {
                                pos = 0;
                        }
                        putchar(chr);

                }
                /* any other character*/
                else
                {
                        putchar(chr);
                        pos++;
                }

        }
        /* return 0 on success*/
        return 0;
}
