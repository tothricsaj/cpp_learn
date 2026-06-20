#include <iostream>
#include <fstream>
#include <thread>

using namespace std;

int main() {

  // ofstream MyFile("filename.txt");

  // MyFile << "subi dubi nah't!!!";

  // MyFile.close();

  string myText;

  ifstream MyReadFile("filename.txt");

  while(getline(MyReadFile, myText)) {
    cout << myText;
  }

  cout << endl;

  cout << "This is the main thread: " << this_thread::get_id() << endl;

  MyReadFile.close();

  return 0;
}