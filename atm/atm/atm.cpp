#include <stdio.h>

int main()
{
    FILE* fp;//ファイルポインタ
    errno_t error;

    error = fopen_s(&fp, "Results.txt", "w");
    if (error != 0) {
        //ファイルオープンエラー
        fprintf_s(stderr, "failed to open");
        return -1;
    }
}