# Xfix

- prefix, infix and postfix

## Precedence and Associativity



## Infix to Postfix

- scan tokens one by one
  - if token is operand then add to postfix expression
  - if token is open parenthesis, push to stack
  - if token is closing parenthesis, pop stack till open parenthesis not found. (discard parenthesis)
  - if token is operator
    - pop and add to postfix expression till (
              stack is not empty or
              top of stack has lower precedence than current token or
              top of stack is not opening parenthesis or
              top of stack is not left associative that has lower precedence than current token or
              top of stack is not right associative that has same precedence than current token)
    - push current token to stack
- till stack is not empty
  pop operator from stack and add to postfix expressions

## Infix to Prefix

## Prefix to Infix

## Prefix to Postfix

## Postfix to Prefix

## Postfix to Infix
