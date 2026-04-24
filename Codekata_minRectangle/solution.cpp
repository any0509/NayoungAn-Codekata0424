#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// sizes_rows는 2차원 배열 sizes의 행 길이, sizes_cols는 2차원 배열 sizes의 열 길이입니다.
int solution(int** sizes, size_t sizes_rows, size_t sizes_cols) {
    int answer = 0;
    int maxLong = 0;
    int maxShort = 0;

    int temp = 0;
    for (int i = 0; i < sizes_rows; ++i)
    {
        if (!sizes[i]) return -1;

        int w = sizes[i][0];
        int h = sizes[i][1];
        int longSide = w > h ? w : h;
        if (longSide > maxLong)
        {
            maxLong = longSide;
        }
    }

    for (int i = 0; i < (int)sizes_rows; ++i)
    {
        int w = sizes[i][0];
        int h = sizes[i][1];

        if (w > h)
        {
            if (h > maxShort) maxShort = h;
        }
        else {
            if (w > maxShort)
            {
                maxShort = w;
            }
        }
    }
   
    answer = maxLong * maxShort;

    return answer;
}