#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  string username, password;
  bool login_success = false;
  
  cout << "Please enter your username: ";
  cin >> username;
  cout << "Please enter your password: ";
  cin >> password;
  
  ifstream infile;
  infile.open("user_data.txt");
  
  while (infile >> username >> password) {
    if (username == username && password == password) {
      login_success = true;
      break;
    }
  }
  
  if (login_success == true) {
    cout << "Login successful.\n";
  } else {
    cout << "Login unsuccessful.\n";
  }
  
  return 0;
}