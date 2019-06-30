#include<iostream>
#include<fstream>
#include<algorithm>
#include<stdlib.h>
#include<ctime>
using namespace std;
void selectionSort(int a[],int size);
void HeapSort(int arr[], int len);
void QuickSort(int data[],int a,int n);
static int qsortCompare(const void *p1,const void *p2)	// use for qsort()
{// static: the function can only be used inside this file
	return *(int *)p1-*(int *)p2;
}
int main(){
	ifstream in;
	ofstream out;	
	int size;
	int* tempData;
	int* data;
	clock_t start_clock, stop_clock;


	in.open("input.txt");	
	if (in.fail()) {
		cout<<"input file not found"<<endl;
		return 0;
	}
	in>>size;
	tempData=new int[size];
	for (int i=0;i<size;i++)
		in>>tempData[i];
	in.close();
	data=new int[size];
	for(int i=0;i<size;i++)
		data[i]=tempData[i];
	start_clock=clock();
	selectionSort(data,size);
	stop_clock=clock();	
	printf("Selection Sort: %g\n", (stop_clock - start_clock) / (double)CLOCKS_PER_SEC);
	out.open("outputA.txt");
	out<<"Selection Sort\n";
	for(int i=0;i<size;i++)
			out<<data[i]<<endl;
	out.close();
	
	
	for(int i = 0; i < size; i++)
		data[i]=tempData[i];
	start_clock=clock();
	HeapSort(data,size);
	stop_clock=clock();
	printf("Heap Sort: %g\n",(stop_clock-start_clock)/(double)CLOCKS_PER_SEC);
	out.open("outputB.txt");
	out<<"Heap Sort\n";
	for(int i=0;i<size; i++)
		out<<data[i]<<endl;
	out.close();


	for(int i=0;i<size;i++)
		data[i]=tempData[i];
	start_clock = clock();
	QuickSort(data,0,size-1);
	stop_clock = clock();
	printf("Quick Sort: %g\n", (stop_clock - start_clock) / (double)CLOCKS_PER_SEC);
	out.open("outputC.txt");
	out<<"Quick Sort\n";
	for (int i=0;i<size;i++)
		out<<data[i]<<endl;
	out.close();


	for(int i=0;i<size;i++)
		data[i]=tempData[i];
	start_clock = clock();
	qsort(data,size,sizeof(int),qsortCompare);
	stop_clock = clock();
	printf("C qsort( ): %g\n", (stop_clock - start_clock)/(double)CLOCKS_PER_SEC);
	out.open("outputD.txt");
	out<<"C qsort( )\n";
	for (int i=0;i<size;i++)
		out<<data[i]<<endl;
	out.close();


	for(int i=0;i<size;i++)
		data[i]=tempData[i];
	start_clock = clock();
	sort(data,data+size);
	stop_clock=clock();
	printf("C++ sort(): %g\n", (stop_clock - start_clock)/(double)CLOCKS_PER_SEC);
	out.open("outputE.txt");
	out<<"C++ sort( )\n";
	for(int i= 0;i<size;i++)
		out<<data[i]<<endl;
	out.close();
	return 0;
}
void selectionSort(int a[],int size){
	int min;
	for(int i=0;i<size-1;i++){
		min=i;
		for (int j=i+1;j<size;j++) {
			if(a[j]<a[min])
				min=j;
		}
		swap(a[i],a[min]);
	}
}


void heapify(int arr[],int n,int i){
    int largest=i;
    int l=2*i+1;
    int r=2*i+2; 
    if (l<n&&arr[l]>arr[largest])
        largest=l;
    if (r<n&&arr[r]>arr[largest])
        largest=r;
    if (largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}
void HeapSort(int arr[],int n){
    for(int i=n/2-1;i>=0;i--)
        heapify(arr,n,i);
    for(int i=n-1; i>=0; i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}


void QuickSort(int arr[],int left,int right){
      int i=left,j=right;
      int pivot=arr[(left+right)/2];
      while(i<=j){
            while(arr[i]<pivot)
                  i++;
            while(arr[j]>pivot)
                  j--;
            if(i<=j){
                  swap(arr[i],arr[j]);
                  i++;
                  j--;
            }
      }
      if(left<j)
            QuickSort(arr,left,j);
      if(i<right)
            QuickSort(arr,i,right);
}
