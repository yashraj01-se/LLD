#include <vector>
#include <fstream>
#include <iostream>
using namespace std;
class DocumentElement
{
public:
    virtual string render() = 0;
};

class TextElement : public DocumentElement
{
private:
    string text;

public:
    TextElement(string text)
    {
        this->text = text;
    }
    string render() override
    {
        return text;
    }
};

class ImageElement : public DocumentElement
{
private:
    string Imagepath;

public:
    ImageElement(string ImagePath)
    {
        this->Imagepath = ImagePath;
    }
    string render() override
    {
        return "[Image :" + Imagepath + "]";
    }
};

class Document
{
private:
    vector<DocumentElement *> documentelement;

public:
    void addelement(DocumentElement *element)
    {
        documentelement.push_back(element);
    }

    string render()
    {
        string result = "";
        for (auto ele : documentelement)
        {
            result += ele->render();
        }

        return result;
    }
};

class persistance
{
public:
    virtual void save(string data) = 0;
};

class Savetofile : public persistance
{
public:
    virtual void save(string data)
    {
        ofstream file("Document.txt");
        if (file.is_open())
        {
            file << data;
            file.close();
            cout << "Data is rendered successfully in Document.txt" << endl;
        }
        else
        {
            cout << "Data is not rendered successfully in Document.txt. Please try again..." << endl;
        }
    }
};

class SavetoDB : public persistance
{
public:
    virtual void save(string Data)
    {
        // save to DB logic..
    }
};

class DocumentEditor{
private:
    Document *doc;
    persistance *per;
    string RenderedDocument;
public:
    DocumentEditor(Document *doc,persistance *per){
        this->doc=doc;
        this->per=per;
    }
   
    void Addtext(string Text){
        doc->addelement(new TextElement(Text));
    }

    void AddImage(string imagePath){
        doc->addelement(new ImageElement(imagePath));
    }

    string renderdoc(){
         if(RenderedDocument.empty()){
             RenderedDocument=doc->render();
         }
         return RenderedDocument;
    }
    void save(){
        per->save(renderdoc());
    }
};

int main(){
    Document *document=new Document();
    persistance *Persistance=new Savetofile();

    DocumentEditor *de=new DocumentEditor(document,Persistance);

    de->Addtext("Hello I am back\n");
    de->AddImage("Image.jpg");
    de->renderdoc();
    de->save();
}