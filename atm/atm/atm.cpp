#include <stdio.h>

int main()
{
    FILE* fp

        error = fopen_s(&fp, "Results.txt", "w");
        if (error != 0) {
            fprintf_s(stderr, "failed to open");
            return -1;
        }
}