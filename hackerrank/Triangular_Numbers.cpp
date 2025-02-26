#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    unsigned long long int n, k, triangular, kplus1;
    
    while(scanf("%llu", &n) && n != 0){
        k = (-1 + sqrt(1 + 8*(double)n))/2;
        kplus1 = k + 1;
        
        if(k % 2 == 0)
            k /= 2;
        else 
            kplus1 /= 2;
        triangular = k*kplus1;
        
        if(triangular == n)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}