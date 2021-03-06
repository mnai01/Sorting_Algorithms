#include <iostream>
void swap(int* lhs, int* rhs);
void BubbleSort(int arr[], int length);
void SelectionSort(int arr[], int length);
void InsertionSort(int arr[], int length);
using namespace std;

int main() {
	int x = 20;
	int y = 19;
	int testarr[] = { 9,8,7,6,5,4,3,2,1 };
	int testArrLength = 9;

	for (int i = 0; i < 9; i++) {
		cout << testarr[i] << " ";
	}

	cout << endl << endl;

	// BubbleSort(testarr, testArrLength);
	// SelectionSort(testarr, testArrLength);
	InsertionSort(testarr, testArrLength);

	for (int i = 0; i < 9; i++) {
		cout << testarr[i] << " ";
	}
	cout << endl;
	return 0;
}

void swap(int* lhs, int* rhs) {
	// temp equals te value in the rhs
	int temp = *rhs;

	// rhs now equals the value that was stored in the lhs
	*rhs = *lhs;

	// lhs now equals the value stored in temp(the old rhs variable)
	*lhs = temp;
}

void BubbleSort(int arr[], int length) {

	// Swaps by sending the greatest to the right
	// Iterates n times of length, this makes sure the nested forloop/if will go through the loop at most 9 times
	// each time this places 1 value in the right spot. So after iterating through as many times as the list time, the list should be sorted
		// nested forloop/nested-if iterates throught the list, and finds the location where a greater variables is on the left and a smaller variable is on the right. EX. 6, 5
		// if true then variables will switch and the next iteration the forloop goes through will start at where the higher variables was switched. EX. 5, 6 (next iteration the list starts at 6)
		// This is because if arr[j] is greater then arr[j+1](the index on the right side if arr[j]) then the higher variables goes to arr[j + 1].
		// Then the IF is finished and the forloop iterates j which means the (arr[j + 1]) from the last interation is now the normal arr[j] for this iteration
		// for j = 0; j < length - 1 -i; j++
		// IF arr[0] is greater then arr[0 + 1](which is arr[1]) then swap them
		// so now arr[0] is the lessen value and arr[0 + 1](which is arr[1]) is the greater value. Now that the if condition is done, go back to the forloop
		// which says to iterate for j (for j = 0; j < length - 1 -i; j++) therefor since this is our second pass j++ adds +1 to j which means
		// the if statement is now comparing arr[1](which is our higher value from the last iteration) and arr[1 + 1](which is arr[2])
		// This will sort the list by bringing the larger numbers to the right side first.
		// we minus i in the forloop too because after we pass through the whole loop once, atleast 1 value will be in its correct stop. In this case
		// The largest value will be in its correct spot so we just minus whatever I is so we dont waste time iterating through the sorted values
		// The Minus -1 is in the forloop because once the max of arr[j] is reach its going to compare arr[j](8 being the max index) with arr[j+1] (index 9 which doesnt exist)
		// So minusing one always makes sure it says in the list and minusing i makes sure we dont iterate throught the already sorted items at the end of this list
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length -1 - i; j++) {

			// Check if left side is greater then right side
			if (arr[j] > arr[j + 1]) {
				cout << arr[j] << " " << arr[j + 1] << endl;

				// Swap the greater variable to the right and the smaller variable to the left EX. 4, 3 is not 3 , 4
				swap(&arr[j], &arr[j + 1]);
				cout << arr[j] << " " << arr[j + 1] << " swapped " << endl;

				cout << endl << endl;
			}
		}
	}
	
	//// Swaps by sending the least to the lest
	//// Iterates n times of length
	//for (int i = 1; i < length; i++) {
	//	for (int j = length - 1; j > 1; j--) {
	//		if (arr[j] < arr[j - 1]) {
	//			cout << arr[j] << " " << arr[j - 1] << endl;
	//			swap(&arr[j], &arr[j - 1]);
	//			cout << arr[j] << " " << arr[j - 1] << " swapped " << endl;
	//			for (int i = 0; i < 9; i++) {
	//				cout << arr[i] << " ";
	//			}
	//			cout << endl << endl;
	//		}
	//	}
	//}
}

void SelectionSort(int arr[], int length) {
	// used to hold the most min value
	int marker;

	// iterates through each index 
	for (int i = 0; i < length - 1; i++) {
		// sets marker to whichever index it is at
		marker = i;
		// checks to see if marker is greater then j. this forloop also iterates through the list. This allowed every value to be compared with each other in the array
		// EX. i = 1
		// j will compare 2-8 while int i equals 1 (this compares 2-8 with 1 seeing if its less them). Then i increments to 2 and the same thing happens.
		
		// j will equal i + 1 because everytime the forloop finishes that means the most left index is sorted with the smallest value.
		// so we do not want to check that specific index anymore, so instead of making j = 0 (which after the first pass will hold the smallest value)
		// we do j = i + 1 which is always gonna be 1 value infront of the most left or the most recent smallest value swapped at that time.
		for (int j = i + 1 ; j < length; j++) {
			// is marker greater then j
			if (arr[marker] > arr[j]) {
				// make marker equal the smaller value J
				marker = j;
			}
			// once j iterates through the whole list, allowing us to compare each member with marker, marker will now
			// hold the smallest value therefore we swap marker with i which at this point will be at the most left unsorted index
			swap(&arr[marker], &arr[i]);
		}
	}
}

void InsertionSort(int arr[], int length) {
	int value, currentIndex;
	// interate through each index of the array
	for (int i = 1; i < length; i++) {
		// key is equal to the the value of the specific index we are at
		value = arr[i];
		
		// hole is the index # at which i is at
		currentIndex = i;
	
		// while currentIndex is greater then 0 and arr[currentIndex - 1] (the value before the currentIndex) is greater than value (represents value of currentIndex)
		while (currentIndex > 0 && arr[currentIndex - 1] > value) {
			// then current index (which is the the lesser value at this point) set equal to current index -1 (the value before current which is greater)
			arr[currentIndex] = arr[currentIndex - 1];
			// set current index back 1 index
			currentIndex--;
		}
		// set current index to value
		arr[currentIndex] = value;
	}
}