#include<stdio.h>
#include<Windows.h>

int int_compare(const void*key1,const void*key2){
	
	const int *ch1 = (const int*)key1;
	const int *ch2 = (const int *)key2;
	return (*ch1-*ch2);

}
int char_compare(const void*key1,const void*key2){
	
	const char *ch1 = (const char*)key1;
	const char *ch2 = (const char *)key2;
	return (*ch1-*ch2);

}


int serachelem(void *arr,int len,void *search,int typesize,int(*compare)(const void*key1,const void* key2)){
	
	int left =0;
	int right = len - 1;
	int mid = 0;

	while(left<=right){

		int ret = 0;
		
		
		mid = (left+right)/2;
		ret = compare((char *)arr+(mid*typesize),search);
		if(ret>0){
			
			right = mid - 1;
		
		}else if(ret==0){
			
			return mid;
		}else{
			
			left = mid +1;

		}
	
	
	}

	return -1;


}


int main(void){
	int arr[]={1, 3, 7, 9, 11};
	int search[]={11};
	int index = serachelem(arr,sizeof(arr)/sizeof(arr[0]),&search[0],sizeof(int),int_compare);

	printf("%d\n",index);

	char arr1[]={'a','b','c','d','f'};
	char search2[]={'0','a','d','c','f','j'};
	//char search2[] = {'0', 'a', 'e', 'j' , 'z'};
	printf("%d\n",sizeof(search2)/sizeof(search2[0]));

	for(int i =0;i<sizeof(search2)/sizeof(search2[0]);i++){
		
		index = serachelem(arr1,sizeof(arr1)/sizeof(arr1[0]),&search2[i],sizeof(char), char_compare);
		printf("serach[i:%c]:%d\n",search2[i],index);
	
	}
	
	system("pause");
	return 0;
}