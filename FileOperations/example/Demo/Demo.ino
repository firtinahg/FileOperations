/*****************************************************************************************************************************
 * Author : Firtina Huseyin GOKTAS , fhg971@gmail.com
 * Testing the FileOperations library.
 * 
 * 
  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 * 
 * 
 * 
 ******************************************************************************************************************************/
#include <FileOperations.h>
FileOp FileExample;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);


Serial.println(FileExample.getCurrentPathName());
FileExample.definePath("/try.txt");
Serial.println("Is it directory? 1--> Yes , 0--> No");
Serial.println(FileExample.IsDirectory());
Serial.print("Get current path : ");
Serial.println(FileExample.getCurrentPathName());
FileExample.Write("Hello World!");
FileExample.Rename("/IRenamedTheFile.txt");
Serial.print("Get current path : ");
Serial.println(FileExample.getCurrentPathName());
Serial.println("Read the renamed file");
Serial.println(FileExample.Read());
Serial.println("File size : ");
Serial.println(FileExample.GetSize());
Serial.println("Is the file directory? 1--> Yes , 0--> No");
Serial.println(FileExample.IsDirectory());
FileExample.Write("I'm writing new things... ");
FileExample.Append("I'm also append some new things...");
Serial.println("Read the file content : ");
Serial.println(FileExample.Read());
FileExample.Delete();
Serial.println("Again read the file content...");
Serial.println(FileExample.Read());

}

void loop() {
  // put your main code here, to run repeatedly:

}
