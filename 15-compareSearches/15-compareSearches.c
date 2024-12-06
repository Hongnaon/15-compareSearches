#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000  // 배열 크기 정의

// 전역 변수로 비교 횟수를 저장
int compareCount = 0;

// 임의의 숫자 1000개를 생성하여 배열에 저장하는 함수
void generateRandomArray(int* array) {
    for (int i = 0; i < SIZE; i++) {
        array[i] = rand() % 1000;  // 0부터 999 사이의 난수 생성
    }
}

// 순차 탐색을 수행하는 함수 (target을 찾을 때까지 비교횟수를 셈)
int linearSearch(int* array, int target) {
    int compare = 0;
    for (int i = 0; i < SIZE; i++) {
        compare++;  // 각 비교마다 횟수를 증가
        if (array[i] == target) {  // 타겟 값이 발견되면
            return compare;  // 비교 횟수를 반환
        }
    }
    return compare;  // 타겟 값이 없으면 마지막 비교 횟수 반환
}

// 100번의 랜덤 순차 탐색을 수행하고, 그 비교 횟수의 평균을 계산하는 함수
float getAverageLinearSearchCompareCount(int* array) {
    float totalCompare = 0;
    for (int i = 0; i < 100; i++) {
        int target = array[rand() % SIZE];  // 배열에서 랜덤한 target 값 선택
        totalCompare += linearSearch(array, target);  // 순차 탐색 후 비교 횟수 더함
    }
    return totalCompare / 100.0;  // 평균 비교 횟수 반환
}

// 퀵 정렬 함수 (재귀적으로 배열을 정렬하며 비교 횟수를 기록)
void quickSort(int* array, int low, int high) {
    if (low < high) {  // 배열의 크기가 1 이상일 때만 실행
        int pivot = array[high];  // 피벗 값 설정
        int i = (low - 1);

        for (int j = low; j < high; j++) {
            compareCount++;  // 각 비교마다 횟수를 증가
            if (array[j] <= pivot) {  // 현재 요소가 피벗보다 작으면
                i++;  // i를 증가시켜서 위치 변경
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }

        // 피벗을 적절한 위치에 놓음
        int temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;

        int pi = i + 1;  // 피벗의 최종 위치

        quickSort(array, low, pi - 1);  // 피벗 기준 왼쪽 부분 정렬
        quickSort(array, pi + 1, high);  // 피벗 기준 오른쪽 부분 정렬
    }
}

// 퀵 정렬을 실행하고, 비교 횟수를 계산하는 함수
void getQuickSortCompareCount(int* array) {
    compareCount = 0;  // 비교 횟수 초기화
    quickSort(array, 0, SIZE - 1);  // 배열 전체에 대해 퀵 정렬 실행
}

// 이진 탐색 함수 (정렬된 배열에서 target을 찾을 때까지 비교횟수를 셈)
int binarySearch(int* array, int target) {
    int low = 0, high = SIZE - 1, mid;
    int compare = 0;

    while (low <= high) {
        mid = low + (high - low) / 2;  // 중간 인덱스 계산
        compare++;  // 비교 횟수 증가

        if (array[mid] == target) {  // target이 중간값과 일치하면
            return compare;  // 비교 횟수 반환
        }
        else if (array[mid] < target) {  // 중간값이 타겟보다 작으면
            low = mid + 1;  // 오른쪽 절반 탐색
        }
        else {  // 중간값이 타겟보다 크면
            high = mid - 1;  // 왼쪽 절반 탐색
        }
    }
    return compare;  // 타겟 값을 찾지 못했을 경우 비교 횟수 반환
}

// 100번의 랜덤 이진 탐색을 수행하고, 그 비교 횟수의 평균을 계산하는 함수
float getAverageBinarySearchCompareCount(int* array) {
    float totalCompare = 0;
    for (int i = 0; i < 100; i++) {
        int target = array[rand() % SIZE];  // 배열에서 랜덤한 target 값 선택
        totalCompare += binarySearch(array, target);  // 이진 탐색 후 비교 횟수 더함
    }
    return totalCompare / 100.0;  // 평균 비교 횟수 반환
}

// 배열의 처음 20개와 마지막 20개의 값을 출력하는 함수
void printArray(int* array) {
    printf("Array Sorting Result:\n");
    for (int i = 0; i < 20; i++)  // 배열 앞부분 20개 출력
        printf("%3d ", array[i]);
    printf("\n");
    for (int i = SIZE - 20; i < SIZE; i++)  // 배열 뒷부분 20개 출력
        printf("%3d ", array[i]);
    printf("\n");
}

int main(int argc, char* argv[]) {
    srand(time(NULL));  // 랜덤 시드 설정
    int array[SIZE];
    generateRandomArray(array);  // 임의의 숫자 1000개를 배열에 저장

    // 순차 탐색 평균 비교 횟수 출력
    printf("Average Linear Search Compare Count: %.2f\n",
        getAverageLinearSearchCompareCount(array));

    // 퀵 정렬을 실행하고, 비교 횟수를 출력
    getQuickSortCompareCount(array);
    printf("Quick Sort Compare Count: %d\n", compareCount);

    // 정렬된 배열에 대해 100번의 이진 탐색 평균 비교 횟수 출력
    printf("Average Binary Search Compare Count: %.2f\n\n",
        getAverageBinarySearchCompareCount(array));

    printArray(array);  // 정렬된 배열의 앞 20개와 뒤 20개 출력

    return 0;  // 프로그램 종료
}
