#include "Account.h" //includes in "" are different from <>, includes in "" means we are including a file thats inside our project, whereas includes in <> means we are including the language standard library

void Account::set_balance(double bal){ //Class_name::method_name, this way is quite handy, when the codebase is very large and it becomes harder to implement all the logic in the class declaration, best practice is to modularize it like this
  //this will make sure set_balance method is set for "Account" class only
  balance = bal;
}

double Account::get_balance(){
  return balance;
}

