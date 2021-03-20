// Rabin Karp String Mathing Algorithm

/*

* Here we consider string of only characters 0, 1, ..., 9
* ie pattern and text only consists of digits.
* So constructing hash function becomes the decimal
* representation

*/

# include <stdio.h>
# include <string.h>


int main(){
    char text[] = "8730455980293750934869";
    char pattern[] = "98029";
    int n = strlen(text);
    int m = strlen(pattern);

    long patternHash = atol(pattern);

    long hash[n-m];

    













}
