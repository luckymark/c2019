//
// Created by admin on 2019/5/4.
//

// locate in file

#include <stdio.h>

long getStart(FILE*fp){
    fseek(fp, 0, SEEK_SET);
    long start = ftell(fp);
    return start;
}

long getCur(FILE *fp){
    long cur = ftell(fp);
    return cur;
}

long getEnd(FILE *fp){
    fseek(fp, 0L, SEEK_END);
    long end = ftell(fp);
    return end;
}
