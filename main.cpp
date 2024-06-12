#include <vector>
#include <map>
#include <string>
#include "compressors.h"
#include <iostream>
#include <filesystem>
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
    for (string str_path: paths){
        filesystem::path path(str_path);

        cout<<"\npath"<<path<<endl;
        string extension = path.extension().string();
        cout<<"file extension: "<<extension<<endl;

        if (!extension.compare(".txt")){
            compressText();
        }
        //images
        else if(!extension.compare(".jpg")){
            compressImage();
        }
        //videos
        else if(!extension.compare(".mp4")){
            compressVideo();
        }
        //audio
        else if(!extension.compare(".mp3")){
            compressSound();
        }
        //directory
        else{
            //open dir, get all paths in there
            //save as vector and pass recurently
            vector<string> newPaths;
            for (const auto& entry: filesystem::directory_iterator(path)){
                newPaths.push_back(entry.path().string());
            }
            string newOutputFolder = outputFolder+'\\'+path.filename().string();
            cout<<"new paths:"<<endl;
            for (string e:newPaths){
                cout<<"\t"<<e<<endl;
            }
            compressCore(newPaths, conversionTypes, newOutputFolder);
        }
    }

    return 0; 
}

    

int main() {
    cout << "Hello to SupaZippa!"<<endl;

    // Temp, for Petah to fill implement
    vector<string> paths{"C:\\Users\\tomas\\Desktop\\SupaZippa\\someFile.txt", "someFile2.txt", "C:\\Users\\tomas\\Desktop\\SupaZippa\\dirFolder"};
    string output = "SupaZipped";
    //file:method mapping
    map<string, string> conversionTypes;
    conversionTypes["Text"] = "Huffman";
    conversionTypes["Image"] = "Huffman";
    conversionTypes["Video"] = "Huffman";
    conversionTypes["Sound"] = "Huffman";


    compressCore(paths, conversionTypes, output);
    return 0;
}