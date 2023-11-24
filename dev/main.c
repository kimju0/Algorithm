#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define length 100000

int *makeArray(int n) {
    srand(time(NULL));
    int idx = 0;
    int i, j = 0;
    int *outArr = (int *) malloc(sizeof(int) * n);
    int *tmpArr = (int *) malloc(sizeof(int) * n * 100);

    for (i = 0; i < n * 100; i++) {
        tmpArr[i] = i;
    }

    idx = rand() % n;// 0 ~ n-1
    //range outArr[i+1] - outArr[i] = 1 ~ 10
    for (i = 0; i < idx; i++) {
        j += (rand() % 10) + 1;// 1 to 10
        outArr[i] = tmpArr[j];
    }

    j = 0;
    //same as above
    for (i = idx; i < n; i++) {
        j += (rand() % 10) + 1;
        outArr[i] = tmpArr[j];
    }

    //첫, 두 번째 생성기 각각 내부에서는 연속해서 같은 값이 저장되지 못함
    //첫 번째 생성기의 마지막 값과 두 번째 생성기의 첫 번째 값은 같을 수 있음
    free(tmpArr);
    return outArr;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int array[], int n) {
    int i, j, min_element;
    for (i = 0; i < n - 1; i++) {
        min_element = i;
        for (j = i + 1; j < n; j++)
            if (array[j] < array[min_element])
                min_element = j;
        swap(&array[min_element], &array[i]);
    }
}

void insertionSort(int array[], int n) {
    int i, element, j;
    for (i = 1; i < n; i++) {
        element = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > element) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = element;
    }
}

int isSorted(int array[], int n) {
    int i;
    for (i = 0; i < n - 1; i++)
        if (array[i] > array[i + 1])
            return 0;

    return 1;
}

long long arrSum(int array[], int n) {
    int i;
    long long sum = 0;
    for (i = 0; i < n; i++)
        sum += array[i];

    return sum;
}

// or MySort(int array[], int l, int r)
void MySort(int array[], int n) {
    // Implement your algorithm

    int *new_array = (int *) malloc(sizeof(int) * n);
    int s_first = 0, s_second = -1;//s_first가 없는 케이스 처리
    int e_first, e_second = n;
    for (int i = 0; i < n; i++)//maybe could be optimized by using binary search
        if (array[i] >= array[i + 1]) {
            s_second = i + 1;
            break;
        }
    if (s_second == -1) return;//should be handled
    //생각해보니 s_first가 없는 케이스는 이미 정렬이 되어있는거라 바로 리턴 ㄱㄴ
    e_first = s_second;
    int cur_first = s_first, cur_second = s_second, cur_new = 0;
    while (cur_first < e_first || cur_second < e_second) {
        if (cur_first >= e_first || cur_second >= e_second) {
            if (cur_first >= e_first) {
                while (cur_second < e_second) {
                    new_array[cur_new++] = array[cur_second];
                    cur_second++;
                }
            } else {
                while (cur_first < e_first) {
                    new_array[cur_new++] = array[cur_first];
                    cur_first++;
                }
            }
        } else {
            if (array[cur_first] <= array[cur_second]) {
                new_array[cur_new++] = array[cur_first];
                cur_first++;
            } else {
                new_array[cur_new++] = array[cur_second];
                cur_second++;
            }
        }
    }
    free(array);
    array = new_array;
}

int main() {
    int *Data;
    int Data_copy[length];
    int i;
    double time_taken;
    clock_t t;

    // Data generation
    Data = makeArray(length);
    for (i = 0; i < length; i++) {
        Data_copy[i] = Data[i];
    }
    printf("Original Data Descriptions");
    printf("Are Data Sorted?: %d \n", isSorted(Data_copy, length));
    printf("Data Sum: %lld \n\n", arrSum(Data_copy, length));


    // Insertion Sort
    t = clock();
    insertionSort(Data_copy, length);
    t = clock() - t;
    time_taken = ((double) t) / CLOCKS_PER_SEC;
    printf("Insertion Sort took %f seconds to execute \n", time_taken);
    printf("Are Data Sorted?: %d \n", isSorted(Data_copy, length));
    printf("Data Sum: %lld \n\n", arrSum(Data_copy, length));


    // Selection Sort
    for (i = 0; i < length; i++) {
        Data_copy[i] = Data[i];
    }
    t = clock();
    selectionSort(Data_copy, length);
    t = clock() - t;
    time_taken = ((double) t) / CLOCKS_PER_SEC;
    printf("Selection Sort took %f seconds to execute \n", time_taken);
    printf("Are Data Sorted?: %d \n", isSorted(Data_copy, length));
    printf("Data Sum: %lld \n\n", arrSum(Data_copy, length));


    // MySort
    for (i = 0; i < length; i++) {
        Data_copy[i] = Data[i];
    }
    t = clock();
    MySort(Data_copy, length);
    // or MySort(Data_copy, 0, length - 1);
    t = clock() - t;
    time_taken = ((double) t) / CLOCKS_PER_SEC;
    printf("My Sort took %f seconds to execute \n", time_taken);
    printf("Are Data Sorted?: %d \n", isSorted(Data_copy, length));
    printf("Data Sum: %lld \n\n", arrSum(Data_copy, length));

    return 0;
}