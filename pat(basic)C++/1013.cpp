#include<iostream>
#include<cmath>
using namespace std;
#define InitSize 1000
#define Add_size 1000
int IsPrime(int Prime,int *array,int PrimeCount);
int main(){
    int *array;
    int *index_array;
    array = (int*)malloc(InitSize*sizeof(int));
    int existsize = InitSize;
    int inputA;
    int inputB;
    cin>>inputA>>inputB;
    int index = 2;
    int PrimeCount = 0;
    int outputPrime = 0;
    while(1){
        if(IsPrime(index,array,PrimeCount)){
            PrimeCount++;
            if(PrimeCount%1000==0){
                for(int k = 0;k<100;k++){
                    index_array = (int *) realloc(array, (existsize + Add_size) * sizeof(int));
                    if(index_array != NULL){
                        array = index_array;
                        existsize += Add_size;
                        break;
                    }
                }
            }
            if(inputA<=PrimeCount && PrimeCount<=inputB){
                cout<<index;
                outputPrime++;
                if(outputPrime%10!=0&&PrimeCount<inputB){
                    cout<<' ';
                }
                else if(outputPrime%10==0&&PrimeCount<inputB){
                    cout<<endl;
                }
                else{
                    free(array);
                    system("pause");
                    return 0;
                }
            }
        }
        index++;
    }
}
int IsPrime(int Prime,int *array,int PrimeCount){
    // if(Prime==1){
    // 	return 0;
    // }
    if(Prime==2||Prime==3){
        *(array+PrimeCount) = Prime;
        return 1;
    }
    else{
        for(int i = 0;*(array+i)<=(int)sqrt(Prime);i++){
            if(Prime%(*(array+i))==0){
                return 0;
            }
        }
        *(array+PrimeCount) = Prime;
        return 1;
    }
}


