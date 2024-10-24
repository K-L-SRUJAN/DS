#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}
void infix_to_postfix(char* infix, char* postfix) {
    char stack[MAX];
    int top = -1, k = 0;
    
    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

  
        if (isalnum(ch)) {
            postfix[k++] = ch;
        }
  
        else if (ch == '(') {
            stack[++top] = ch;
        }
    
        else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[k++] = stack[top--];
            }
            top--;
        }
      
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(ch)) {
                postfix[k++] = stack[top--];
            }
            stack[++top] = ch;
        }
    }

  
    while (top != -1) {
        postfix[k++] = stack[top--];
    }
    
    postfix[k] = '\0';  
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    
    infix_to_postfix(infix, postfix);

    
    printf("Postfix Expression: %s\n", postfix);

    return 0;
}
