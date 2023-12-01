import java.util.Scanner;

class DFA_Transition {
    public DFA_State origin_state;
    public DFA_State destination_state;
    public char trigger_value;

    public DFA_Transition() {
    }


    public static void copyDFA_Transition(DFA_Transition []destination,DFA_Transition []origine){
        if (destination != origine) {
            for(int i=0; i < origine.length; i++) {
                destination[i] = origine[i];
                 /*destination[i] = new DFA_Transition(); // no need for this 
                 destination[i].origin_state= origine[i].origin_state;
                 destination[i].destination_state = origine[i].destination_state;
                 destination[i].trigger_value = origine[i].trigger_value;*/
            }
       }
    }

    public DFA_Transition create_transition(char trigger_value, DFA_State origin_state, DFA_State destination_state) {
        DFA_Transition transition = new DFA_Transition();
        transition.trigger_value = trigger_value;
        transition.origin_state = origin_state;
        transition.destination_state = destination_state;
        transition.set_transition_to_state(origin_state);
        return transition;
    }

    public void set_transition_to_state(DFA_State origin_State) {// fixed
        DFA_Transition [] temp = new DFA_Transition[origin_State.transitions.length + 1];
        copyDFA_Transition(temp,origin_State.transitions);
        temp[origin_State.transitions.length ] = new DFA_Transition();
        temp[origin_State.transitions.length ] = this;
        origin_State.transitions = temp;
        origin_state.transitions_count += 1;
    }

    public static void generate_transitions(String string, DFA_State origin_State, DFA_State destination_state) {// fixed
        int i;
        DFA_Transition tempTransition = new DFA_Transition();
        for (i = 0; i < string.length(); i++) {
            if (tempTransition.create_transition(string.charAt(i), origin_State, destination_state) == null) {
                return ;
            }
        }
    }

    public void describe_transition() {// fixed java
        System.out.println("------ Origin state: "+ origin_state);
        System.out.println("------ Destination state: "+ destination_state);
        System.out.println("------ Trigger value: "+ trigger_value);
    }

}

class DFA_State {
    public int state_identifier;
    public boolean accept_state;
    public int transitions_count;// we use length function in java , no needed
    DFA_Transition[] transitions;

    public DFA_State() {
    }

    public DFA_State(int state_identifier, boolean accept_state) {
        this.accept_state = accept_state;
        this.transitions_count = 0;
        this.state_identifier = state_identifier;
        // state.transitions = null;
        transitions = new DFA_Transition[0];
    }

    public static DFA_State create_state(int state_identifier, boolean accept_state, DFA automata) {
        DFA_State state = new DFA_State(state_identifier, accept_state);
        state.set_state_to_automata(automata);
        return state;
    }

    public static void copyDFA_States(DFA_State []destination,DFA_State []origine){
        if (destination != origine) {
            for(int i=0; i < origine.length; i++) {
                destination[i] = origine [i];
                /*destination[i] = new DFA_State(); // we get this automata states <> to the state in the main function;
                destination[i].accept_state= origine[i].accept_state;
                destination[i].state_identifier = origine[i].state_identifier;
                destination[i].transitions_count = origine[i].transitions_count;*/
            }
        }
    }

    public void set_state_to_automata(DFA automata) {
        DFA_State [] tempStates = new DFA_State[automata.states.length + 1 ];
        copyDFA_States(tempStates,automata.states);
        //noinspection ConstantConditions
        tempStates[automata.states.length ] = new DFA_State();
        tempStates[automata.states.length ] = this;
        automata.states = tempStates;
        automata.states_count += 1;// states_count must be = states.length;
        //return true; //use it if return type boolean but we don't need this return;
    }

    public void describe_state() {// fixed java
        int i;
        System.out.println("--- Accept state: "+ accept_state);
        if (transitions_count > 0) {
            System.out.printf("--:: Transitions dump (%d):\n", transitions_count);
            for (i = 0; i < transitions_count; i++) {
                System.out.printf("------ Transition %d\n", i);
                transitions[i].describe_transition();
            }
        } else {
            System.out.println("--:: State has no transitions to dump.");
        }
    }
}

class DFA {
    public int states_count; // we can use length function in java
    public DFA_State[] states;
    public DFA_State current_state;
    public DFA_State initial_state;

    public DFA() { // fixed java // replace create automata; or use static creat calling the constractor
        states_count = 0;
        initial_state = new DFA_State();
        current_state = new DFA_State();
        states = new DFA_State[0];
    }

    /*public DFA(int numberOfState) { // fixed java
        states_count = numberOfState; // no need for this attribute
        initial_state = new DFA_State();
        current_state = new DFA_State();
        states = new DFA_State[numberOfState];
        for (DFA_State item : states) {
            item = new DFA_State();
        }
    }*/

    public static DFA create_automata() {
         return new DFA();
    }

    public void init_automata() {
        if (initial_state == null) {
            System.out.println("[-] Error: Initial state of automata not set.");
            System.exit(-1);
        }
        current_state = initial_state;
    }

    public boolean update_automata(char ch) {// fixed java
        int j;
        //DFA_State state = new DFA_State();
        DFA_State state = current_state;
        boolean made_transition = false;
        for (j = 0; j < state.transitions_count; j++) {
            if (state.transitions[j].trigger_value == ch) {
                current_state = state.transitions[j].destination_state;
                made_transition = true;
                break; // Finite automata does not have 'choices'. If trigger_value matches, then the
                // automata must not have another transition with the same value.
            }
        }
        // Automata will always execute a transition if value is accepted.
        return made_transition; //return true or false
    }

    public boolean belongs_to_language(String string) {// fixed java
        if (string.length() == 0) {
            System.out.println("[-] Error: Empty string sent to analyse in belongs_to_language.");
            System.exit(-1);
        }
        int i;
        init_automata();
        for (i = 0; i < string.length(); i++) {
            if (!this.update_automata(string.charAt(i))) {
                return false;
            }
        }
        return current_state.accept_state;
    }

    public DFA free_automata() {// the old type is boolean // fixed java
        int i, j;
        for (i = 0; i < states.length; i++) {
            for (j = 0; j < states[i].transitions.length; j++) {
                states[i].transitions[j] = null;
            }
            states[i] = null;
        }
        // this = null;// we can't assigning in the function; use it out function after
        // return address;
        return this;// return true; the old
    }

    public void describe_automata() { // fixed java
        int i;
        System.out.println("Automata dump:");
        if (states_count > 0) {
            System.out.printf(":: States dump (%d):\n", states_count);
            for (i = 0; i < states_count; i++) {
                System.out.printf(":: State %d\n", i);
                states[i].describe_state();
            }
        } else {
            System.out.println("--- Automata has no states to dump.");
        }
    }

}

public class Dfa {
    public static void main(String[] args) {
       /* - we can use a menu like what i did in C looke if you want in main.c 
          - we can use the clases in a sperate file but in the same package if you want
          - to test the Dfa use this 4 expression:
               a-aaaa--0101%           ture
               a-aaa-aaaa----01010101% ture
               a-aaa-aa-aa----0101010+ ture
               100101011               fals
               100123801-011            fals */

        final int INITIAL_STATE = -1;
        final int ZERO_STATE = 10;
        final int ONE_STATE = 11;
        final int ACCEPT_STATE = 1;

        Scanner input = new Scanner(System.in);

        DFA automata = DFA.create_automata(); // or use the constructor

        DFA_State initial_state = DFA_State.create_state(INITIAL_STATE, false, automata);
        DFA_State zero_state = DFA_State.create_state(ZERO_STATE, false, automata);
        DFA_State one_state = DFA_State.create_state(ONE_STATE, false, automata);
        DFA_State accept_state = DFA_State.create_state(ACCEPT_STATE, true, automata);

        DFA_Transition.generate_transitions("a-", initial_state, initial_state);
        DFA_Transition.generate_transitions("0", initial_state, zero_state);
        DFA_Transition.generate_transitions("1", initial_state, one_state);
        DFA_Transition.generate_transitions("0", one_state, zero_state);
        DFA_Transition.generate_transitions("1", zero_state, one_state);
        DFA_Transition.generate_transitions("+", zero_state, accept_state);
        DFA_Transition.generate_transitions("%", one_state, accept_state);

        automata.initial_state = initial_state;

        System.out.println("enter the expression : ");
        String expression = input.nextLine();

        //if (automata.belongs_to_language(expression) == 1) { because can't compare bool to int;
        if (automata.belongs_to_language(expression)) { // must be true;
            System.out.println("the expression belong to the language  * true *");
        } else {
            System.out.println("the expression NOT belong to the language  * false *");
        }
        input.close();
    }
}

