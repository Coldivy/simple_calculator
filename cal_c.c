#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double calculate(const char *str) {
    double result = 0;
    double current_number = 0;
    char current_operator = '+';
    int i = 0;
    int length = strlen(str);
    
    while (i < length) {
        if (str[i] >= '0' && str[i] <= '9' || str[i] == '.') {
            current_number = atof(&str[i]);
            // 跳过当前数字部分
            while (i < length && (str[i] >= '0' && str[i] <= '9' || str[i] == '.')) {
                i++;
            }
            // 根据当前运算符执行计算
            switch (current_operator) {
                case '+':
                    result += current_number;
                    break;
                case '-':
                    result -= current_number;
                    break;
                case '*':
                    result *= current_number;
                    break;
                case '/':
                    if (current_number == 0) {
                        printf("除数不能为零\n");
                        return 0;
                    }
                    result /= current_number;
                    break;
            }
        } else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
            current_operator = str[i];
            i++;
        } else if (str[i] == '=') {
            break;
        } else {
            i++;
        }
    }
    return result;
}

int main() {
    char expression[] = "3+5*2-8/4=";
    double result = calculate(expression);
    printf("计算结果为: %.2f\n", result);
    return 0;
}

