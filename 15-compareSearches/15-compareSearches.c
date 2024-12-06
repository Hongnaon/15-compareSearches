#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000  // �迭 ũ�� ����

// ���� ������ �� Ƚ���� ����
int compareCount = 0;

// ������ ���� 1000���� �����Ͽ� �迭�� �����ϴ� �Լ�
void generateRandomArray(int* array) {
    for (int i = 0; i < SIZE; i++) {
        array[i] = rand() % 1000;  // 0���� 999 ������ ���� ����
    }
}

// ���� Ž���� �����ϴ� �Լ� (target�� ã�� ������ ��Ƚ���� ��)
int linearSearch(int* array, int target) {
    int compare = 0;
    for (int i = 0; i < SIZE; i++) {
        compare++;  // �� �񱳸��� Ƚ���� ����
        if (array[i] == target) {  // Ÿ�� ���� �߰ߵǸ�
            return compare;  // �� Ƚ���� ��ȯ
        }
    }
    return compare;  // Ÿ�� ���� ������ ������ �� Ƚ�� ��ȯ
}

// 100���� ���� ���� Ž���� �����ϰ�, �� �� Ƚ���� ����� ����ϴ� �Լ�
float getAverageLinearSearchCompareCount(int* array) {
    float totalCompare = 0;
    for (int i = 0; i < 100; i++) {
        int target = array[rand() % SIZE];  // �迭���� ������ target �� ����
        totalCompare += linearSearch(array, target);  // ���� Ž�� �� �� Ƚ�� ����
    }
    return totalCompare / 100.0;  // ��� �� Ƚ�� ��ȯ
}

// �� ���� �Լ� (��������� �迭�� �����ϸ� �� Ƚ���� ���)
void quickSort(int* array, int low, int high) {
    if (low < high) {  // �迭�� ũ�Ⱑ 1 �̻��� ���� ����
        int pivot = array[high];  // �ǹ� �� ����
        int i = (low - 1);

        for (int j = low; j < high; j++) {
            compareCount++;  // �� �񱳸��� Ƚ���� ����
            if (array[j] <= pivot) {  // ���� ��Ұ� �ǹ����� ������
                i++;  // i�� �������Ѽ� ��ġ ����
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }

        // �ǹ��� ������ ��ġ�� ����
        int temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;

        int pi = i + 1;  // �ǹ��� ���� ��ġ

        quickSort(array, low, pi - 1);  // �ǹ� ���� ���� �κ� ����
        quickSort(array, pi + 1, high);  // �ǹ� ���� ������ �κ� ����
    }
}

// �� ������ �����ϰ�, �� Ƚ���� ����ϴ� �Լ�
void getQuickSortCompareCount(int* array) {
    compareCount = 0;  // �� Ƚ�� �ʱ�ȭ
    quickSort(array, 0, SIZE - 1);  // �迭 ��ü�� ���� �� ���� ����
}

// ���� Ž�� �Լ� (���ĵ� �迭���� target�� ã�� ������ ��Ƚ���� ��)
int binarySearch(int* array, int target) {
    int low = 0, high = SIZE - 1, mid;
    int compare = 0;

    while (low <= high) {
        mid = low + (high - low) / 2;  // �߰� �ε��� ���
        compare++;  // �� Ƚ�� ����

        if (array[mid] == target) {  // target�� �߰����� ��ġ�ϸ�
            return compare;  // �� Ƚ�� ��ȯ
        }
        else if (array[mid] < target) {  // �߰����� Ÿ�ٺ��� ������
            low = mid + 1;  // ������ ���� Ž��
        }
        else {  // �߰����� Ÿ�ٺ��� ũ��
            high = mid - 1;  // ���� ���� Ž��
        }
    }
    return compare;  // Ÿ�� ���� ã�� ������ ��� �� Ƚ�� ��ȯ
}

// 100���� ���� ���� Ž���� �����ϰ�, �� �� Ƚ���� ����� ����ϴ� �Լ�
float getAverageBinarySearchCompareCount(int* array) {
    float totalCompare = 0;
    for (int i = 0; i < 100; i++) {
        int target = array[rand() % SIZE];  // �迭���� ������ target �� ����
        totalCompare += binarySearch(array, target);  // ���� Ž�� �� �� Ƚ�� ����
    }
    return totalCompare / 100.0;  // ��� �� Ƚ�� ��ȯ
}

// �迭�� ó�� 20���� ������ 20���� ���� ����ϴ� �Լ�
void printArray(int* array) {
    printf("Array Sorting Result:\n");
    for (int i = 0; i < 20; i++)  // �迭 �պκ� 20�� ���
        printf("%3d ", array[i]);
    printf("\n");
    for (int i = SIZE - 20; i < SIZE; i++)  // �迭 �޺κ� 20�� ���
        printf("%3d ", array[i]);
    printf("\n");
}

int main(int argc, char* argv[]) {
    srand(time(NULL));  // ���� �õ� ����
    int array[SIZE];
    generateRandomArray(array);  // ������ ���� 1000���� �迭�� ����

    // ���� Ž�� ��� �� Ƚ�� ���
    printf("Average Linear Search Compare Count: %.2f\n",
        getAverageLinearSearchCompareCount(array));

    // �� ������ �����ϰ�, �� Ƚ���� ���
    getQuickSortCompareCount(array);
    printf("Quick Sort Compare Count: %d\n", compareCount);

    // ���ĵ� �迭�� ���� 100���� ���� Ž�� ��� �� Ƚ�� ���
    printf("Average Binary Search Compare Count: %.2f\n\n",
        getAverageBinarySearchCompareCount(array));

    printArray(array);  // ���ĵ� �迭�� �� 20���� �� 20�� ���

    return 0;  // ���α׷� ����
}
