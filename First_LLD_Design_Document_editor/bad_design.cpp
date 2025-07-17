#include <vector>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class DocumentEditor   // Breaking the Single Responsibility Principle and Open / Closed Principle
{
private:
    vector<string> DocumentElements;
    string RenderedDocument;

public:
    void addText(string text)
    {
        DocumentElements.push_back(text);
    }

    void addimage(string imagepath)
    {
        DocumentElements.push_back(imagepath);
    }

    string renderDocument()   // Business Logic.. 
    {
        if (RenderedDocument.empty())
        {
            string result;
            for (auto Element : DocumentElements)
            {
                if (Element.size() > 4 && (Element.substr(Element.size() - 4) == ".jpg" || Element.substr(Element.size() - 4) == ".png"))
                {
                    result += "[Image: " + Element + "]" + "\n";
                }
                else
                {
                    result += Element + "\n";
                }
            }
            RenderedDocument = result;
        }
        return RenderedDocument;
    }

    void saveToFile()  //Business Logic...
    {
        ofstream file("document.txt"); // Creating the file to write on..
        if (file.is_open())
        {
            file << renderDocument();
            file.close();
            cout << "Document has been rendered successfully" << endl;
        }
        else
        {
            cout << "Document has not been rendered successfully. Please try again..." << endl;
        }
    }
};

int main(){
    DocumentEditor * de=new DocumentEditor();
    de->addText("Hello welcome");
    de->addimage("Picture.jpg");

    de->renderDocument();
    
    de->saveToFile();
}