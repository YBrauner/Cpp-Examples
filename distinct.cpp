//input is an unsorted  array of numbers, the programm returns an acsendingly sorted array without erpating numbers, except 1, which any repetitions are at the end of the array
//Even though this was one of the Interview questions, its the best piece of code in C++ to show. Ive worked on it for maybe 3 hours.


#include<iostream>
#include<stdio.h>

int distinct(int Ar[], int size, int num,  int indstart){  //return the next index which  is not num,  ifthere isnone, return -1
    int index = indstart;
    for(int i =indstart; i<size; i++){
        if (Ar[i] ==num){
            index++;
        }
    }
    if(index < size){
        return index;
    }
    else{
        return -1;
    }
}

void sort(int Ar[], int size){  //sort array ascending
    for(int i=1; i<size; i++){  
    int x=Ar[i];
    int j = i-1;
    while ((j>=0) && (Ar[j]>x)){
        Ar[j+1] = Ar[j];
        j = j-1;
    }
    Ar[j+1] = x;
    }
}

int count_one(int Ar[],int size){   //liefert  die anzahl an 1s zurück
    int one = 0;
    for(int i=0; i<size; i++){
        if(Ar[i] == 1){
            one++;
        }
    }
    return one;
}

int main()
{
    int Ar[] = {3,3,1,1,9};
    int size = sizeof(Ar)/sizeof(int);
    int index, ind;

    sort(&Ar[0], size);

    int Arout[size];
    for(int i=0; i<size; i++){
        Arout[i] = 0;
    }

    Arout[0] = Ar[0];
    ind = 1;

    for(int i=0; i<size; i++){  
        index = distinct(&Ar[0], size, Ar[i], i);   //nächter index für Arout

        if((index != -1) && (Arout[ind-1] != Ar[index])){     //wennderr nächste freie nach dem jetzigen eistiert und letzter eingetragener ungleich dem nächsten ist
            
            Arout[ind] = Ar[index];
            ind++;
            i = index-1;
        }
    }

    int one = (count_one(&Ar[0], size)-1);
    if(one >= 1){
        for(int i=0; i<one; i++){
            Arout[ind] = 1;
            ind++;
        }
    }

    for(int i=0;  i<size; i++){
        if((i>0) && (Arout[i] == 0)){
            break;
        }
         printf("%i", Arout[i]);
    }
    std::cout<<"\n";

    return 0;
}