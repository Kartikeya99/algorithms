#include <iostream>

using namespace std;

void swap(int* x, int* y);
void quickSort(int arr[], int low, int high, int dimArr);
int partition (int arr[], int low, int high);

int main(){
	int array[] = {8676, 798, 5, 455, 222};
	int dim = 5;

	quickSort(array, 0, dim-1, dim);

	for(int i=0; i<dim; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;

	return 0;
}

void swap(int* x, int* y)
{
	int w = *x;
	*x = *y;
	*y = w;
}

void quickSort(int arr[], int low, int high, int dimArr)
{
	if(low<high)
	{
		int part = partition(arr, low, high);
		quickSort(arr, low, part - 1, dimArr); 
        quickSort(arr, part + 1, high, dimArr);
	}
}

int partition (int arr[], int low, int high) 
{ 
    int piv = arr[high];
    int i = (low - 1);  
  
    for (int j = low; j <= high- 1; j++) 
    {  
        if (arr[j] <= piv) 
        { 
            i++; 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
}