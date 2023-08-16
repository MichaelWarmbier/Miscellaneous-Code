/* Practice creating a multifurcating tree */

/*//// External Data ////*/
#include <iostream>
#include <vector>
using namespace std;

/*//// Internal Data ////*/

class file {

  private:
    vector<file> children;
    string name;
    string ext;
    bool isFile = true;

  public:
    /* Constructors */
    file() { name = ""; isFile = true; ext = ""; }
    file(string fn, string fe) { 
      name = fn;
      ext = fe;
      if (ext == "") isFile = false;
      else            isFile = true;
    }

    /* Setter Methods */
    void setName(string fn) { name = fn; }
    void setExt(string fe) { ext = fe; }

    void addFile(file newFile) {
      if (isFile) isFile = false;
      children.push_back(newFile);
    }

    bool removeFile(string fileName) {
      for (int fileI = 0; fileI < children.size(); fileI++)
        if (fileName == children[fileI].name) {
          children.erase(children.begin() + fileI);
          return true;
        }
      return false;
    }

    /* Getter Methods */
    bool isFolder() { return !isFile; }
    string getName() { return name; }

    string getExt() { 
      if (!isFile) return "";
      return ext;
    }

    int getSize() { 
      if (isFile) return 0;
      return children.size();
    }

    file getFile(string fileName) {
      file empty("con", "NULL");
      if (isFile) return empty;
      for (int fileI = 0; fileI < children.size(); fileI++) {
        if (fileName == children[fileI].name) {
          return children[fileI];
        }
      }
      return empty;
    }

};

class fs {

  private:
    file root;

};

/*//// Testing Code ////*/
int main() {
  
  file myFile("TestFile", "txt");
  cout << "New file created named " << myFile.getName() << '.' << myFile.getExt() << endl;
  file myFolder("File_Storage", "");
  cout << "New folder created named " << myFolder.getName() << endl;
  file mySecondFile("TestFile_2", "png");
  cout << "New file created named " << mySecondFile.getName() << '.' << mySecondFile.getExt() << endl;

  cout << endl;

  myFolder.addFile(myFile);
  myFolder.addFile(mySecondFile);
  cout << "Added two files to folder " << myFolder.getName() << endl;

  cout << "First file extension is ." << myFolder.getFile("TestFile").getExt() << endl;
  cout << "Second file extension is ." << myFolder.getFile("TestFile_2").getExt() << endl;

  cout << endl;

  bool fileStatus = (myFolder.getFile("TestFile").getName() == "TestFile");
  cout << boolalpha << "File 'TestFile.txt' exist: " << fileStatus << endl;
  cout << "Removing file 'TestFile.txt'" << endl;
  myFolder.removeFile("TestFile");
  fileStatus = (myFolder.getFile("TestFile").getName() == "TestFile");
  cout << boolalpha << "File 'TestFile.txt' exist: " << fileStatus << endl;
}
