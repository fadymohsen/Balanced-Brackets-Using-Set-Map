// Libraries
#include <iostream>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;



// Start Solution Class
class solution{
public:
    bool isValid(string s){
        unordered_set <char> open_bracket = { '(' , '{' , '['};                             // Set For Open Brackets
        unordered_set <char> close_bracket = { ')' , '}' , ']'};                            // Set For Close Brackets
        unordered_map <char,char> bracket_pair = { {'[',']'} , {'{','}'} , {'(',')'} };     // Map with Key is open
        stack <char> bracket_stack;                                                         // Stack For Brackets

        for (char c : s){
            if (open_bracket.find(c) != open_bracket.end()){                    // if we found an open bracket item
                bracket_stack.push(c);                                          // add it in the stack

            }else if (close_bracket.find(c) != close_bracket.end()){            // in Case of close brackets ...

                // if there is a closed bracket only remain it will be false
                if (bracket_stack.empty())      return false;

                // if the last element in the stack (open bracket) is not suitable for the crossponding item in the map
                char top_bracket = bracket_stack.top();
                if (c != bracket_pair[top_bracket]) return false;

                // if the two conditions are false this mean that we can remove the last element in the stack
                bracket_stack.pop();
            }
        }
        // if the stack is empty this means that there is no open bracket without its crossponding bracket
        return bracket_stack.empty();
    }
};
// End Solution Class




int main(int argc, char **argv) {
    solution s = solution();
    string tests[] = {"()" , "(]" , "()[]{}" , "("};

    for (string test: tests){
        cout<<s.isValid(test);
    }
    cout<<endl<<endl;




    return 0;
}
