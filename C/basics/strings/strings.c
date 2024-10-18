#include <stdio.h>
#include <string.h>

int string_length(char *str){
    int offset = 0;
    while(str[offset] != 0){
        offset++;
    }
    return offset;
}
void copy(char *from, char *to){
    int offset = 0;
    while(from[offset] != 0){
        to[offset] = from[offset];
        offset++;
    }
    to[offset] = 0;
}

void using_pointers(char *str){
    char *end = str+strlen(str) - 1; //str pointer + sizeof(strlen(str) - 1) which points to the end of the array
    while(str < end){
        char temp = *str; // need temp variable to preserve str pointer
        *str = *end;
        *end = temp;
        str++;
        end--;
    }
}


char* xor_xor_xor_hack(char *str){ //no need for temp variables
    int offset = 0;
    int end = strlen(str) - 1;

    while (offset < end) {
        // XOR swap to reverse characters without temporary variables
        str[offset] ^= str[end];
        str[end] ^= str[offset];
        str[offset] ^= str[end];

        offset++;
        end--;
    }
    return str;
}
void string_reverse(char *str){
    int offset = 0;
    int end = strlen(str) - 1;
    char reversed_array[end + 2];
    while(end >= 0){
        reversed_array[offset] = str[end];
        offset++;
        end--;
    }
    reversed_array[offset] = 0;
    printf("%s", reversed_array);
}



int main(){
    char *str1 = "Hello World!"; //size of this string is 13 bytes the letters of "hello word!" plus a NULL terminating character
    char str2[] = "Hello World!\n";
    char newstring[50];
    printf("%s\n", str1);
    printf("%s\n", str1);
    //printf("%s is %d char long\n", str1, string_length(str1));
    printf("%s is %d char long\n", str1, strlen(str2));
    //copy(str1, newstring);
    strcpy(newstring, str1);
    printf("%s", newstring);

    //string_reverse(str1);
    //printf("%s", xor_xor_xor_hack(str2));
    using_pointers(str2);
    printf("%s", str2);
}
