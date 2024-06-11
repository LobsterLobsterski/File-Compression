#include <vector>
#include <map>
#include <string>
#include "compressors.h"
#include <iostream>
using namespace std;

byte getFileType(string path){
    // file extension in the if-else-if will need to be
    // updated in due time

    size_t found = path.find_last_of(".");
    string fileExtension = path.substr(found+1);
    
    //text and documents
    if (!fileExtension.compare("txt")){
        return (byte)0;
    }
    //images
    else if(!fileExtension.compare("jpg")){
        return (byte)1;
    }
    //videos
    else if(!fileExtension.compare("jpg")){
        return (byte)2;
    }
    //audio
    else if(!fileExtension.compare("jpg")){
        return (byte)3;
    }
    //directory
    else{
        return (byte)4;
    }
}

int compressCore(vector<string>& paths, map<string, string>& conversionTypes, string& outputFolder){
    for (string path: paths){
        cout<<"full file path: "<<path<<endl;
        byte fileType = getFileType(path);
        cout<<"fileType: "<<(int)fileType<<endl;
        switch (fileType){
            case (byte)0:
                compressText();
                break;

            case (byte)1:
                compressImage();
                break;

            case (byte)2:
                compressVideo();
                break;

            case (byte)3:
                compressSound();
                break;

            default:
                cout<<"Direcotory compression not implemented yet!"<<endl;
                break;
        }
        
    }

    return 0;
}

int main() {
    cout << "Hello to SupaZippa!"<<endl;

    // Temp, for Petah to fill implement
    vector<string> paths{"C:\\Users\\tomas\\Desktop\\SupaZippa\\someFile.txt", "someFile2.txt", "dirFolder"};
    string output = "SupaZipped.zip";
    //file:method mapping
    map<string, string> conversionTypes;
    conversionTypes["Text"] = "Huffman";
    conversionTypes["Image"] = "Huffman";
    conversionTypes["Video"] = "Huffman";
    conversionTypes["Sound"] = "Huffman";


    compressCore(paths, conversionTypes, output);
    return 0;
}