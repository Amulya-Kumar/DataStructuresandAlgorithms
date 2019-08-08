#include<stdio.h>
#include<stdlib.h>

void main(){
	int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};
	int len;
	len = sizeof(arr)/sizeof(arr[0]);
	int lis[len];

	for(int i=0; i<len; i++){
		lis[i] = 1;	
	}
	
	for(int i=1; i<len; i++){
		for(int j=0; j<i; j++){
			if(arr[i] > arr[j] && lis[i] < lis[j] + 1){
				lis[i] = lis[j]+1; 
			}
		}
	} 
	
	int max = lis[0];
	for(int i=0; i<len; i++){
		if(lis[i] > max){
			max = lis[i];
		}
	}

	printf("The longest increasing subsequence is of size %d\n", max);
}
