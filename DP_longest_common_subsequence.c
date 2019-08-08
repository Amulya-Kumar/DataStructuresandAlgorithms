#include<stdio.h>
#include<stdlib.h>

void main(){
	char arr[] = {'A', 'G', 'G', 'T', 'A', 'B'};
	char arr2[] = {'G', 'X', 'T', 'X', 'A', 'Y', 'B'};

	int len, len2;
	len = sizeof(arr)/sizeof(arr[0]);
	len2 = sizeof(arr2)/sizeof(arr2[0]);

	int resarr[len2+1][len+1];

	for(int i=0; i<=len2; i++){
		for(int j=0; j<=len; j++){
			if( i==0 || j==0 ){
				resarr[i][j] = 0;
			}			
			else {
				if(arr2[i-1] == arr[j-1]){
					resarr[i][j] = resarr[i-1][j-1] + 1;		
				}
				else {
					if(resarr[i-1][j] > resarr[i][j-1]){
						resarr[i][j] = resarr[i-1][j];			
					}
					else {
						resarr[i][j] = resarr[i][j-1];
					}
				}
			}
		}
	}
	
	printf("The longest common subsequence is of size %d\n", resarr[len2][len]);
}
