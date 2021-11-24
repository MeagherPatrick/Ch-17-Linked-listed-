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
nodeType* search(nodeType*);

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
  node= search(node);
  nextNode = node;
  while (nextNode != NULL) {
    cout << nextNode->someValue << " " << nextNode->someAmount << '\n';
    nextNode = nextNode->link;
  }
  return 0;

 

}
nodeType* search(nodeType* headNode)
{
              nodeType *p;
  p = headNode;
           // if (headNode == NULL)
             // cout << "empty";
            
              while (p != NULL) {
    if (p->someValue == 'S')
      cout << "S was found the amount is: " << p->someAmount << '\n';
    p = p->link;
              }
            
          return p;
}
        

nodeType* build_Forward(ifstream& fin)
{

  nodeType *headNode, *newNode, *tempNode;
  headNode = NULL;
  tempNode = NULL;
  newNode = NULL;

  while (fin.peek() != EOF)
  {
      newNode = new nodeType;
        fin >> newNode->someValue;
        fin >> newNode->someAmount;
        newNode->link = NULL;      
            if (headNode == NULL) 
            {
                 headNode = newNode;
                 tempNode = newNode;
                 
            }   
                else 
                {
                     tempNode->link = newNode; 
                     tempNode = newNode;
                }
    
           /* if (tempNode->someValue == 'D') 
            {
                  
                      cout << " D was found but was it deleted? : " << '\n';                       
            } */

           /*       
             if (newnode->somevalue == 's')
                {
                  cout << newnode->someamount << " "<<newnode->somevalue << '\n';
                  cout << "this is an s value:" << '\n';            
                }
   */
    }
    return headNode;
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

  // if (tempNode == NULL) {
  //  tempNode = newNode;
  //  last = newNode;
  //} else {
  //  last->link = newNode;
  //  last = newNode;
  //}
//struct node
//{
//  int data;
//  node* next;
//};
//int main()
//{
//  node* newNode;
//  node* tempNode;
//  node* headNode;
//  newNode = new node;
//  newNode->data = 1;
//  tempNode = newNode;
//  tempNode = newNode;
//  newNode = new node;
//  newNode->data = 1;
//  tempNode->next = newNode;
//  tempNode = tempNode->next;
//  newNode = new node;
//  newNode->data = 3;
//  tempNode->next = newNode;
//  tempNode = tempNode->next;
//  newNode = new node;
//  newNode->data = 4;
//  tempNode->next = newNode;
//  newNode->next = NULL;
//
//}