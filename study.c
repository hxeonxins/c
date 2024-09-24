#include <stdio.h>
#include <ctype.h>  // tolower() 함수 사용을 위해 필요

int main() {
    char infected_word[101];  // 입력된 문자열을 저장할 배열
    char cleaned_word[101];   // 결과 문자열을 저장할 배열
    int j = 0;  // cleaned_word의 인덱스

    // 바이러스에 걸린 영어단어 입력 받기
    fgets(infected_word, 101, stdin);

    // 문자열 처리
    for (int i = 0; infected_word[i] != '\0'; i++) {
        if (infected_word[i] != ' ') {  // 공백이 아닌 경우
            cleaned_word[j++] = tolower(infected_word[i]);  // 소문자로 변환하여 저장
        }
    }

    cleaned_word[j] = '\0';  // 문자열의 끝에 NULL 문자 추가

    // 결과 출력
    printf("%s\n", cleaned_word);

    return 0;
}
