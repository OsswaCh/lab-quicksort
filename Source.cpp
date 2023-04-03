#include <iostream>
using namespace std;

int median(int [], int, int);
int partition(int[], int, int);
void quicksort(int[], int, int);
void swap(int &, int &);


int main() {
	
	int arr[9] = { 5,4,8,3,2,11,42,15,32 };
	int size = 9;
	cout << "before sorting";
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
	quicksort(arr, 0, size - 1);
	cout << "after sorting";
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;

	return 0;
}

int median(int arr[], int left, int right) {

	int medn = (left + right) / 2;
	if (arr[left] > arr[right]) 
		swap(arr[left], arr[medn]);
	if (arr[left] > arr[right])
		swap(arr[left], arr[right]);
	if (arr[medn] > arr[right])
		swap(arr[medn], arr[right]);
	return medn;

}

int partition(int arr[], int left, int right) {
	int pivotPoint = median(arr, left, right);
	int pivot= arr[pivotPoint];
	swap(arr[pivotPoint], arr[right]);
	int j = left - 1;
	for (int k = left; k < right; k++) {
		if (arr[k] < pivot) {
			j++;
			swap(arr[j], arr[k]);
		}
	}
	swap(arr[j + 1], arr[right]);
	return j + 1;
}
void quicksort(int arr[], int left, int right) {

	if (left < right) {
		int pivotPoint = partition(arr, left, right);
		quicksort(arr, left, pivotPoint - 1);
		quicksort(arr, pivotPoint + 1, right);

	}

}

void swap(int &a, int &b) {
	int aux = a;
	a = b;
	b = aux;

}