#include <stdio.h>

void printArr(int arr[], int n) {
	for (int i = 0; i < n; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}

// 앞의 영역부터 오름차순에 맞게 정렬한다.
void AscendingInsertionSort1(int arr[], int n) {

	int i, j;

	// 1 ~ n-1 까지 왼쪽 정렬된 영역에 집어넣는다.
	for (i = 1; i < n; ++i) {
		// arr 속 내용이 계속 바뀌기 때문에 insData로 빼두어야 한다.
		int insData = arr[i];
		// i-1 ~ 0 까지 loop를 돌며 어디에 넣을 지를 찾는다.
		for (j = i - 1; j >= 0; --j) {
			// 만약 정렬된 특정 j부분 > insData 라면 : j를 j+1 부분으로 민다.
			if (arr[j] > insData)
				arr[j + 1] = arr[j];
			// 만약 정렬된 특정 j부분 < insData 라면 : 해당 j의 앞부분인 j+1 부분에 insData를 넣어야 한다.
			else
				break;
		}
		arr[j + 1] = insData;
	}
}

// 앞의 영역부터 내림차순에 맞게 정렬한다.
void DescendingInsertionSort1(int arr[], int n) {

	int i, j;

	// 1 ~ n-1까지 왼쪽 정렬된 영역에 집어넣는다.
	for (i = 1; i < n; ++i) {
		int insData = arr[i];
		// i-1 ~ 0 까지 loop를 돌며 어디에 넣을 지 찾는다.
		for (j = i - 1; j >= 0; --j) {
			// 만약 정렬된 특정 j 부분 < insData 라면 : j를 j+1 부분으로 민다.
			if (arr[j] < insData)
				arr[j + 1] = arr[j];
			// 만약 정렬된 특정 j 부분 > insData 라면 : 해당 j의 앞부분인 j+1 부분에 insData를 넣어야 한다.
			else
				break;
		}
		arr[j + 1] = insData;
	}

}

int main(void) {

	int arr[5] = { 2, 3, 1, 5, 4 };

	AscendingInsertionSort1(arr, 5);
	printArr(arr, 5);

	DescendingInsertionSort1(arr, 5);
	printArr(arr, 5);

	return 0;
}
