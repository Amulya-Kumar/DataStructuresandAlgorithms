/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
int longestPalindrome(char * s){
    int length = sizeof(s)/sizeof(s[0]);
    int arr[length][length];
    
    for(int i=0; i<length; i++){
        arr[i][i] = 1;
    }
    
    for(int cl=2; cl<=length; cl++){
        for(int i=0; i<length-cl+1; i++){
            int j = i+cl-1;
            if(s[i] == s[j] && cl==2){
                arr[i][j] = 2;
            }
            else{
                if(s[i] == s[j]){
                   arr[i][j] = arr[i+1][j-1] + 2;
                }
                else{
                    if(arr[i][j-1] > arr[i+1][j]){
                        arr[i][j] = arr[i][j-1];
                    }
                    else{
                        arr[i][j] = arr[i+1][j];
                    }
                }
            }
        }
    }    
    return arr[0][length-1];
}

void main(){
    char s[10] = "babcbab";
    int m = longestPalindrome(s);
    printf("%d", m);
}
