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

    vector<DocumentElement *> getelement()
    {
        vector<DocumentElement *> ElementVector;
        if (ElementVector.empty())
        {
            for (auto it : documentelement)
            {
                ElementVector.push_back(it);
            }
        }
        return ElementVector;
    }
};

class DocumentRender
{
private:
    Document *doc;
    string RederedDocument;

public:
    DocumentRender(Document *doc)
    {
        this->doc = doc;
    }
    string Documentrender()
    {
        vector<DocumentElement *> result = doc->getelement();
        for (auto it : result)
        {
            RederedDocument += it->render();
        }
        return RederedDocument;
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
    void save(string data)
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
    void save(string Data)
    {
        // save to DB logic..
    }
};

class DocumentEditor
{
private:
    Document *doc;

public:
    DocumentEditor(Document *doc)
    {
        this->doc = doc;
    }

    void Addtext(string Text)
    {
        doc->addelement(new TextElement(Text));
    }

    void AddImage(string imagePath)
    {
        doc->addelement(new ImageElement(imagePath));
    }
};

int main()
{
    Document *doc = new Document();
    persistance *per = new Savetofile();
    DocumentRender *dr = new DocumentRender(doc);
    DocumentEditor *de = new DocumentEditor(doc);

    de->Addtext("Hello I am Back.\n");
    de->AddImage("Image.img");
    string Text = dr->Documentrender();
    per->save(Text);
}
