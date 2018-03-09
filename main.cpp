#include <iostream>
#include <cstring>
using namespace std;

void removeSpace(char* p_userInputEdited)
{
    char* p_editCopy = p_userInputEdited;
    do {
        if (*p_editCopy != ' ')
            *p_userInputEdited++ = *p_editCopy;
    } while (*p_editCopy++);
}

void cleanChar(char *p_userInputEdited, const char *p_userInput)
{
  int i = 0;
  while (p_userInput[i])
  {
    if(ispunct(p_userInputEdited[i]))
    {
      p_userInputEdited[i] = ' ';
      i++;
      continue;
    }
    p_userInputEdited[i] = tolower(p_userInput[i]);
    i++;
  }
  removeSpace(p_userInputEdited);
}

bool equalCStrings(const char *p_userInput, const char *p_key) 
{
  bool equal = false;
  if (strcmp(p_userInput, p_key) == 0){equal = true;}
  return equal;
}
  
int main() {
  //declaring variables, key and ui + copies for edits
  char key[100]     = "B. m";
  char keyCopy[100];
  char userInput[100];
  char userInputEdited[100];
  //getting the users string
  puts ("input user char");
  cin.getline (userInput,100,'\n');
  //making copies of the key and UI
  strcpy(userInputEdited, userInput);
  strcpy(keyCopy, key);
  //cleaning the original key and the user input 
  cleanChar(userInputEdited, userInput);
  cleanChar(keyCopy, key);
  //checking for equality
  if(equalCStrings(userInputEdited, keyCopy)){
    cout << "match\n"; 
  }
  else cout << "not match\n";
  
  return 0;
  }
