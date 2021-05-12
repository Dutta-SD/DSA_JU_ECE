# include <stdio.h>
# include <string.h>

main(){
    int i, n;
    char *x = "India";

    n = strlen(x);

    *x = x[n];

    for(i = 0; i < n; ++i){
        printf("%s\n", x);
        x++;
    }
}
