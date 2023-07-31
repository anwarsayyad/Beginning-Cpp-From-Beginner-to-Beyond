#ifndef _ACCOUNT_H_ //these headers are called "include guards",sometimes called as "macro guards, header guards or file guards" and are used to avoid the problem of double inclusion when dealing with the include directive.
//Learn about it more when necessary
//many compilers also support #pragma once directive (learn about it later)
#define _ACCOUNT_H_

class Account {
private:
  double balance;

public:
  void set_balance(double bal);//declared method prototypes, now write the actual implementation in its corresponding .cpp file
  double get_balance();
};

//as the code gets complex, not all the methods can be implemented directly in the class implementation, we need modularize our declaration/implementation 

#endif
