#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int t, s, tcases, page, forgottenPage, totalPages, triangular;
    
    scanf("%d", &t);
    
    for(tcases = 1; tcases <= t; tcases++){
        scanf("%d", &s);
        page = (-1 + sqrt(1 + 8*s))/ 2;
        
        triangular = (page*(page + 1))/2;
        if (triangular == s){
            forgottenPage = page + 1;
            totalPages = page + 1;
        } else{
            page++;
            triangular = (page*(page + 1))/2;
            forgottenPage = triangular - s;
            totalPages = page;
        }
        
        printf("%d %d\n", forgottenPage, totalPages);
    }
    return 0;
}