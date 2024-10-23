// upper case to lower case

#include <stdio.h>

void to_lower(char *str) {
    while (*str) {
        if (*str >= 'A' && *str <= 'Z') {
            *str += 32;
        }
        str++;
    }
}

int main() {
    char str[100] = "Hello, World!";
    printf("Original string: %s\n", str);

    to_lower(str);

    printf("Lower case string: %s\n", str);
    return 0;
}

/*
#include <string.h>
int main(){
    char s[]="",l[]="";
    printf("Enter a statement to convert from Upper to Lower case: ");
    scanf("%s",&s);
    int len=strlen(s);

    for (int i ; i<len ; i++){
        if (s[i]>="A" && s[i]<="Z"){
            l[i]=s[i]+32;
        }
    }
    printf("\n%c",l);
    return 0;
}*/