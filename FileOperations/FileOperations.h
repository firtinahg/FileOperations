
/*
 
  FileOperations.h
  Author : Firtina Huseyin GOKTAS [fhg971@gmail.com]

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  


*/




#ifndef FileOperations.h
#define FileOperations.h


#include "FS.h"
#include <LittleFS.h>

class FileOp{
public:
    FileOp() {
      LittleFS.begin();
      path = "";
    }
    FileOp(String _path){
        LittleFS.begin();
        path = _path ;
    }
String getCurrentPathName(){
    if(path == ""){
      return "Path is not exist" ;
    }
      return path;
}
void definePath(String _path){
     path = _path ;
     Serial.println("Name of the defined path is: " + path);
   }
String Read(){
    String retVal = "";
     char voidVal ;
 file = LittleFS.open(path , "r");
    if(!file|| file.isDirectory()){
        Serial.println("Failed to open file for reading!");
        return "0xerr";
    }
    while(file.available()){
        voidVal = file.read();
        retVal += voidVal ;
    }
     file.close();
    return retVal ;
}
void Append(String message ){
   file = LittleFS.open(path, "a");
    if(!file){
        Serial.println("There was an error opening the file for appending");
        return;
    }
    if(file.print(message)){
        Serial.println("File content was appended");
    } else {
        Serial.println("File append failed");
    }
    file.close();
}
void Delete(){
    if(LittleFS.remove(path)){
        Serial.println("File deleted");
    } else {
        Serial.println("Delete failed");
    }
}
void Write( String message ) {
file = LittleFS.open(path, "w+");
  if (!file) {
    Serial.println("There was an error opening the file for writing!");
    return;
  }

  if (file.print(message)) {
    Serial.println("File written successfully!");
  } else {
    Serial.println("File write error!");
  }
  file.close();
}
/*
*  If file hasn't any character in it , IsDirectory will be return false.It has to be have at least 1 character in the file to return true.  
*
*
*/                      
bool IsDirectory(){
  
 file = LittleFS.open(path , "r");
   if(!file){
        Serial.println("Path is not a directory");
        return false ;       
    }
    return true;
   
}
int GetSize(){
file = LittleFS.open(path , "r");
int file_size = file.size();
file.close();
return file_size ;
}
/********************************************************************************************************************
*                      
*  If file is empty , you can't rename the file name.It has to be include at least 1 character in the file.
*
*********************************************************************************************************************/
boolean Rename(String new_File_Name){
  Serial.println("Trying to change from " + path + " to " + new_File_Name);
if(LittleFS.rename(path , new_File_Name)){
 path = new_File_Name ;
  return true; 
}
 else{
  Serial.println("Renaming failed...");
  return false;
 }
}

private :
String path ; 
File file ;
};

#endif