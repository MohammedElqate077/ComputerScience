#include "DFA.c"
#include "DFA.h"

#define INITIAL_STATE -1
#define ZERO_STATE 10
#define ONE_STATE 11
#define ACCEPT_STATE 1

int main() {
    char expression[50];
    int choi;
    int choi2;

    DFA *automata = create_automata();

    DFA_State *initial_state = create_state(INITIAL_STATE, false, automata);
    DFA_State *zero_state = create_state(ZERO_STATE, false, automata);
    DFA_State *one_state = create_state(ONE_STATE, false, automata);
    DFA_State *accept_state = create_state(ACCEPT_STATE, true, automata);

    generate_transitions("a-", initial_state, initial_state);
    generate_transitions("0", initial_state, zero_state);
    generate_transitions("1", initial_state, one_state);
    generate_transitions("0", one_state, zero_state);
    generate_transitions("1", zero_state, one_state);
    generate_transitions("+", zero_state, accept_state);
    generate_transitions("%", one_state, accept_state);
   automata->initial_state = initial_state;


    do{
    start:
      printf("1 - describe_automata\n")  ;
      printf("2 - describe_state\n")  ;
      printf("3 - describe_transition\n")  ;
      printf("4 - rest automata to initial_state\n")  ;
      printf("5 - is string belong to longuage\n")  ;
      printf("0 - quit\n")  ;
      scanf("%d",&choi);
      switch (choi) {
         case 1:
            describe_automata(automata);break;
         case 2:
            printf("which state init(-1),zero(0),one(1),accept(3)"); scanf("%d",&choi2);
            if(choi2 == -1)
               describe_state(initial_state);
            else if(choi2 == 0)
               describe_state(initial_state);
            else if(choi2 == 1)
               describe_state(initial_state);
            else if(choi2 == 3)
               describe_state(initial_state);
            break;
         case 3:
            break;
         case 4:
            automata->initial_state = initial_state;break;
         case 5:
             printf("enter the expression : "); scanf("%s", expression);
             if (belongs_to_language(expression, automata)) {
                 printf("the expression belong to the language  * true *\n");
             } else {
                 printf("the expression NOT belong to the language  * false *\n");
             }
             break;
         case 0:
             return 0;
         default : printf("error de choi\n");goto start;break;
      }
      printf("==========================================================\n");
    }while(choi);
}
