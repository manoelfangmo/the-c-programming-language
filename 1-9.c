#include <stdio.h>
#include <stdbool.h>


 int  main()


    {
 
 
        int c;
        bool prevIsBlank = false; 
 
        while ((c = getchar()) != EOF)
            if(c == ' '){
                if(prevIsBlank)
                    continue;
                else
                    putchar(c);
                prevIsBlank = true;
            }else{
                putchar(c);
                prevIsBlank = false;
            }
 
    }
