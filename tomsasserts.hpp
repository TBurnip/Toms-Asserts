#include <stdio.h>
#include <cstring>
#include <stdlib.h>


#define RANGE(i,max) (int i = 0; i < max; i ++)
#define RANGE_FROM_TO(i,from,to) (int i = from; i <= to; i ++) // Take note start and end are inclusive.

void print_buf(void* buf,int len,int max) {
    if (len > max) {
        len = max;
    }
    char* bufForPrint = (char*) malloc(len*sizeof(char));
    memcpy(bufForPrint,buf,len);

    for RANGE(i,len) {
        printf("%X",(unsigned int)bufForPrint[i]);
    }
    free(bufForPrint);
    putchar('\n');
}

#define ASSERT(expression,FailReason) if ((expression)==false) { \
    printf("Test:\t\t%s\nFile:\t\t%s\nLine Number:\t%d\nExpression:\t%s\n",FailReason,__FILE__,__LINE__,#expression); \
    return -1; \
}

#define ASSERT_ARRAYS_EQUAL(arr1,arr2,len,FailReason) for RANGE(i,len) { \
    ASSERT(arr1[i]==arr2[i],FailReason); \
}

#define ASSERT_BYTES_EQUAL(buf1,buf2,len,FailReason) if (memcmp(buf1,buf2,len)!=0) { \
    printf("Test:\t\t%s\nFile:\t\t%s\nLine Number:\t%d\nBytesneq:\t%s\t%s\n",FailReason,__FILE__,__LINE__,#buf1,#buf2); \
    print_buf(buf1,len,16); \
    print_buf(buf2,len,16); \
    return -1; \
}

#define ASSERT_ARRAY_ZERO_FROM(arr,from,to,FailReason) for RANGE_FROM_TO(i,from,to) { \
    ASSERT(arr[i]==0,FailReason); \
} // from and to are inclusive.

#define ASSERT_ERROR(expression) if ((expression)!=true) { \
    printf("File:\t\t%s\nLine Number:\t%d\nExpression:\t%s\n",__FILE__,__LINE__,#expression); \
    return -1; \
}
