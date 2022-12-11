#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  string name, username, email, password, user_type;
  bool username_taken = false;
  
  cout << "Please enter your name: ";
  cin >> name;
  cout << "Please enter a unique username: ";
  cin >> username;
  cout << "Please enter your email: ";
  cin >> email;
  cout << "Please enter a password: ";
  cin >> password;
  cout << "Please enter your user type: ";
  cin >> user_type;
  
  ifstream infile;
  infile.open("user_data.txt");
  
  while (infile >> username) {
    if (username == username) {
      username_taken = true;
      break;
    }
  }
  
  if (username_taken == true) {
    cout << "Username is already taken.\n";
  }/*  else { */
}