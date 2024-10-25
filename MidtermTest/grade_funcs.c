// grade_funcs.c

#include "grade_funcs.h"

// 평균 계산 함수
void calculate_average(int scores[], int size, float* average) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += scores[i];
    }
    *average = (float)sum / size;
}

// 최댓값과 최솟값 찾기 함수
void find_min_max(int scores[], int size, int* min, int* max) {
    *min = scores[0];
    *max = scores[0];

    for (int i = 1; i < size; i++) {
        if (scores[i] < *min) {
            *min = scores[i];
        }
        if (scores[i] > *max) {
            *max = scores[i];
        }
    }
}

// 합격/불합격 학생 수를 세는 함수
void count_pass_fail(int scores[], int size, int* pass_count, int* fail_count) {
    *pass_count = 0;
    *fail_count = 0;

    for (int i = 0; i < size; i++) {
        if (scores[i] >= 60) {
            (*pass_count)++;
        }
        else {
            (*fail_count)++;
        }
    }
}

// main.c
#include <stdio.h>
#include "grade_funcs.h"

#define SIZE 10

int main() {
    // 학생 성적 배열
    int scores[SIZE] = { 85, 70, 55, 90, 45, 60, 78, 88, 92, 49 };

    float average;
    int min, max;
    int pass_count, fail_count;

    // 평균 계산
    calculate_average(scores, SIZE, &average);
    printf("평균 성적: %.2f\n", average);

    // 최댓값과 최솟값 찾기
    find_min_max(scores, SIZE, &min, &max);
    printf("최고 성적: %d, 최저 성적: %d\n", max, min);

    // 평균보다 높은 성적과 낮은 성적 출력
    printf("평균보다 높은 성적: ");
    for (int i = 0; i < SIZE; i++) {
        if (scores[i] > average) {
            printf("%d ", scores[i]);
        }
    }
    printf("\n");

    printf("평균보다 낮은 성적: ");
    for (int i = 0; i < SIZE; i++) {
        if (scores[i] < average) {
            printf("%d ", scores[i]);
        }
    }
    printf("\n");

    // 합격/불합격 학생 수 계산 및 출력
    count_pass_fail(scores, SIZE, &pass_count, &fail_count);
    printf("합격한 학생 수: %d명, 불합격한 학생 수: %d명\n", pass_count, fail_count);

    // 각 학생의 합격/불합격 여부 출력
    for (int i = 0; i < SIZE; i++) {
        if (scores[i] >= 60) {
            printf("학생 %d: 성적 %d - 합격\n", i + 1, scores[i]);
        }
        else {
            printf("학생 %d: 성적 %d - 불합격\n", i + 1, scores[i]);
        }
    }

    return 0;
}
