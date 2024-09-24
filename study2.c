#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 함수: 문자열에서 숫자만 추출하여 자연수를 생성
unsigned long long extract_number(const char *str) {
    char num_str[51];  // 최대 50자리 숫자 문자열 + 널 종료 문자
    int index = 0;

    // 문자열에서 숫자만 추출
    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i])) {
            num_str[index++] = str[i];
        }
    }
    num_str[index] = '\0';  // 문자열 종료

    // 추출된 숫자 문자열을 정수로 변환
    if (index == 0) {
        return 0;  // 숫자가 없으면 0 반환
    }
    return strtoull(num_str, NULL, 10);
}

// 함수: 주어진 숫자의 약수 개수 계산
int count_divisors(unsigned long long number) {
    int count = 0;
    if (number == 0) return 0;

    for (unsigned long long i = 1; i * i <= number; i++) {
        if (number % i == 0) {
            if (i * i == number) {
                count++;  // 제곱수인 경우 약수 하나만 추가
            } else {
                count += 2;  // i와 number / i 두 약수 추가
            }
        }
    }
    return count;
}

int main() {
    char input[51];  // 최대 50자 + 널 종료 문자

    // 입력받기
    scanf("%50s", input);

    // 숫자만 추출하여 자연수 생성
    unsigned long long number = extract_number(input);

    // 약수 개수 계산
    int num_divisors = count_divisors(number);

    // 결과 출력
    printf("%llu\n", number);
    printf("%d\n", num_divisors);

    return 0;
}
