#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;
struct nodeType
{
  int count;
 int info;
  string someValue;
  double someAmount;
  nodeType* link;
};
nodeType* build_Backward(ifstream&);
void file_Open(ifstream& fin);

int main()
{
  string test;
  nodeType* node, *nextNode;
  ifstream fin("input.txt");
  //file_Open(fin);
 node = build_Backward(fin);
  // output linked listed
 nextNode = node;
 while (nextNode != NULL)
   cout << nextNode->someValue << " " << nextNode->someAmount << '\n';
  return 0;

}

nodeType* build_Backward(ifstream& fin)
{
  int num;
  int howMany = 0;
  string eof;
  nodeType *first, *newNode, *last;
  first = NULL;
  last = NULL;
  num = 0;
  newNode = new nodeType;
  newNode->info = num;
  newNode->count = ++howMany;
  fin >> newNode->someValue;
  fin >> newNode->someAmount;
  newNode->link = NULL;
  first = newNode;
  if (first == NULL) {
    first = newNode;
    last = newNode;
  } else {
    last->link = newNode;
    last = newNode;
  }
  cout << "Enter a list of integer ending with -999." << endl;
  num++;
  //while (!fin.eof() )
  //  {
  while (!fin.eof())
      {

        newNode = new nodeType;
        newNode->info = num;
        newNode->count = ++howMany;
        fin >> newNode->someValue;
        fin >> newNode->someAmount;
        newNode->link = NULL;
        first = newNode;
        if (first == NULL) {
          first = newNode;
          last = newNode;
        } else {
           last->link = newNode;
          last = newNode;
        }
        cout << "Enter a list of integer ending with -999." << endl;
        num++;
      }
    //}

  return first;
}
void file_Open(ifstream& fin)
{
  string infile_Name;

  cout << " Please enter the file name to open : \n";
  cin >> infile_Name;
  cout << " You entered: " << infile_Name << '\n';

  fin.open(infile_Name);
  if (!fin.is_open()) 
	  cout << "error could not open file. \n program will now shut down. \n"; 
}