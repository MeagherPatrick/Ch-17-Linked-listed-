#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <fstream>
#include <cstdio>


using namespace std;
struct nodeType
{
  
 
  char someValue;
  double someAmount;
  nodeType* link;
};
nodeType* build_Forward(ifstream&);
void file_Open(ifstream& fin);

int main()
{
  string test;
  nodeType* node, *nextNode;
  ifstream fin("input.txt");
  //file_Open(fin);
  node = build_Forward(fin);

 nextNode = node;
  while (nextNode != NULL ) {
   cout << nextNode->someValue << " " << nextNode->someAmount << '\n';
    nextNode = nextNode->link;
  }
  return 0;

}

nodeType* build_Forward(ifstream& fin)
{

  nodeType *first, *newNode, *last;
  first = NULL;
  last = NULL;


  string s;
  while (fin.peek() != EOF)
  {
   
      newNode = new nodeType;

        fin >> newNode->someValue;
        fin >> newNode->someAmount;
       
        newNode->link = NULL;

            if (first == NULL) 
            {
                 first = newNode;
                 last = newNode;
            }   
                else 
                {
                     last->link = newNode;
                     last = newNode;
                }
            if (newNode->someValue == 'D') 
            {
                  last->link = last->link->link;
                  delete newNode;

              cout << " HERE : " << '\n';                       
            } 
                else if (newNode->someValue == 'S')
                {
                  //cout << newNode->someAmount << " "<<newNode->someValue << '\n';
                  cout << "THIS IS AN S VALUE:" << '\n';            
                }
   
    }
  //search(first, 'S')? 

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
  // newNode = new nodeType;
  //
  // fin >> newNode->someValue;
  // fin >> newNode->someAmount;

  // newNode->link = NULL;

  // if (first == NULL) {
  //  first = newNode;
  //  last = newNode;
  //} else {
  //  last->link = newNode;
  //  last = newNode;
  //}