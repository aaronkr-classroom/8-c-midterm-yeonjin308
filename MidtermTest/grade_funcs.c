// grade_funcs.c

#include "grade_funcs.h"

// ��� ��� �Լ�
void calculate_average(int scores[], int size, float* average) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += scores[i];
    }
    *average = (float)sum / size;
}

// �ִ񰪰� �ּڰ� ã�� �Լ�
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

// �հ�/���հ� �л� ���� ���� �Լ�
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
    // �л� ���� �迭
    int scores[SIZE] = { 85, 70, 55, 90, 45, 60, 78, 88, 92, 49 };

    float average;
    int min, max;
    int pass_count, fail_count;

    // ��� ���
    calculate_average(scores, SIZE, &average);
    printf("��� ����: %.2f\n", average);

    // �ִ񰪰� �ּڰ� ã��
    find_min_max(scores, SIZE, &min, &max);
    printf("�ְ� ����: %d, ���� ����: %d\n", max, min);

    // ��պ��� ���� ������ ���� ���� ���
    printf("��պ��� ���� ����: ");
    for (int i = 0; i < SIZE; i++) {
        if (scores[i] > average) {
            printf("%d ", scores[i]);
        }
    }
    printf("\n");

    printf("��պ��� ���� ����: ");
    for (int i = 0; i < SIZE; i++) {
        if (scores[i] < average) {
            printf("%d ", scores[i]);
        }
    }
    printf("\n");

    // �հ�/���հ� �л� �� ��� �� ���
    count_pass_fail(scores, SIZE, &pass_count, &fail_count);
    printf("�հ��� �л� ��: %d��, ���հ��� �л� ��: %d��\n", pass_count, fail_count);

    // �� �л��� �հ�/���հ� ���� ���
    for (int i = 0; i < SIZE; i++) {
        if (scores[i] >= 60) {
            printf("�л� %d: ���� %d - �հ�\n", i + 1, scores[i]);
        }
        else {
            printf("�л� %d: ���� %d - ���հ�\n", i + 1, scores[i]);
        }
    }

    return 0;
}
