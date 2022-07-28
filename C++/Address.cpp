#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
//#include <getopt.h>

using namespace std;

string returns_upper_or_title_normal(string name, vector<bool> checkerArray){
    //to upper
    if(checkerArray[4]){
        transform(name.begin(), name.end(), name.begin(), ::toupper);
        return name;
    }
    //to lower
    else if(checkerArray[5]){
         transform(name.begin(), name.end(), name.begin(), ::tolower);
         transform(name.begin(), name.begin()+1, name.begin(), ::toupper);
         return name;
    }
    return name;
}

string returns_First_Name_or_Nickname(string line, vector<bool> checkerArray)
{
    string name;

    if (checkerArray[2])
    {
        for (int i = 45; i < 55; i++)
        {
            name.push_back(line[i]);
        }
        name.erase(std::remove_if(name.begin(), name.end(), ::isspace), name.end());
        return returns_upper_or_title_normal(name, checkerArray);
    }

    for (int i = 15; i < 30; i++)
    {
        name.push_back(line[i]);
    }
    name.erase(std::remove_if(name.begin(), name.end(), ::isspace), name.end());
    return returns_upper_or_title_normal(name, checkerArray);
}

string returns_Last_Name(string line, vector<bool> checkerArray)
{
    string name;
    for (int i = 0; i < 15; i++)
    {
        name.push_back(line[i]);
    }
    name.erase(std::remove_if(name.begin(), name.end(), ::isspace), name.end());
    return returns_upper_or_title_normal(name, checkerArray);
}

string returns_House_No(string line, vector<bool> checkerArray)
{
    string name;
    for (int i = 55; i < 60; i++)
    {
        name.push_back(line[i]);
    }
    name.erase(std::remove_if(name.begin(), name.end(), ::isspace), name.end());
    return name;
}

string returns_Street_Address(string line, vector<bool> checkerArray)
{
    string name;
    for (int i = 60; i < 80; i++)
    {
        name.push_back(line[i]);
    }
    name.erase(std::remove_if(name.begin(), name.end(), ::isspace), name.end());
    return returns_upper_or_title_normal(name, checkerArray);
}

string returns_City(string line, vector<bool> checkerArray)
{
    string name;
    for (int i = 80; i < 95; i++)
    {
        name.push_back(line[i]);
    }
    name.erase(std::remove_if(name.begin(), name.end(), ::isspace), name.end());
    return returns_upper_or_title_normal(name, checkerArray);
}

void returns_State(string line, vector<bool> checkerArray)
{
    for (int i = 95; i < 96; i++)
    {
        switch (line[i])
        {
        case 'm':
            cout << "MH";
            break;
        case 'K':
            cout << "KL";
            break;
        default:
            cout << "NA";
        }
        if (line[i] == ' ')
            break;
    }
}

string returns_Zip(string line, vector<bool> checkerArray)
{
    string name;
    for (int i = 110; i < 116; i++)
    {
        name.push_back(line[i]);
    }
    name.erase(std::remove_if(name.begin(), name.end(), ::isspace), name.end());
    return name;
}

string returns_keyLookup(string line, vector<bool> checkerArray){
    
    string name;
    //street address first letter
    for (int i = 60; i < 80; i++)
    {
        if (line[i] == ' ')
            continue;
        
        name.push_back(line[i]);
        break;
    }
    //first name first letter
    for (int i = 15; i < 30; i++)
    {
        if (line[i] == ' ')
            continue;
        
        name.push_back(line[i]);
        break;
    }
    //zip address appended
    name = name + returns_Zip(line, checkerArray);
    return returns_upper_or_title_normal(name, checkerArray);
}

void envelopeFormat(vector<bool> checkerArray, string input_file_path)
{
    string line;
    ifstream myfile(input_file_path);

    string word;

    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            // FirstName
            cout << returns_First_Name_or_Nickname(line, checkerArray);
            cout << " ";

            // LastName
            cout << returns_Last_Name(line, checkerArray);
            cout << "," << endl;
            // HouseNo
            cout << returns_House_No(line, checkerArray);
            cout << " ";

            // StreetAddress
            cout << returns_Street_Address(line, checkerArray);
            cout << "," << endl;

            // City
            cout << returns_City(line, checkerArray);
            cout << ", ";

            // State
            returns_State(line, checkerArray);
            cout << " ";
            // Zip
            cout << returns_Zip(line, checkerArray);
            cout << "\n\n";
        }
    }
    else
        cout << "Unable to open file";
}

void fixedFormat(vector<bool> checkerArray, string input_file_path)
{
    string line;
    ifstream myfile(input_file_path);

    string word;

    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            // FirstName
            cout << "\"";
                //keyLookUp
                if(checkerArray[3]){
                    cout << returns_keyLookup(line,checkerArray);
                    cout << " ";
                }
            cout << returns_First_Name_or_Nickname(line, checkerArray);
            cout << " ";

            // LastName
            cout << returns_Last_Name(line, checkerArray);
            cout << ", ";

            // HouseNo
            cout << returns_House_No(line, checkerArray);
            cout << " ";

            // StreetAddress
            cout << returns_Street_Address(line, checkerArray);
            cout << ", ";

            // City
            cout << returns_City(line, checkerArray);
            cout << ",";

            // State
            returns_State(line, checkerArray);
            cout << " ";

            // Zip
            cout << returns_Zip(line, checkerArray);
            cout << "\"\n\n";
        }
    }
    else
        cout << "Unable to open file";
}

void CSVFormat(vector<bool> checkerArray, string input_file_path)
{

    string line;
    ifstream myfile(input_file_path);

    string word;

    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            // FirstName
            cout << "\"";
            cout << returns_First_Name_or_Nickname(line, checkerArray);
            cout << " ";

            // LastName
            cout << returns_Last_Name(line, checkerArray);
            cout << "\",\"";

            // HouseNo
            cout << returns_House_No(line, checkerArray);
            cout << ",";

            // StreetAddress
            cout << returns_Street_Address(line, checkerArray);
            cout << "\",\"";

            // City
            cout << returns_City(line, checkerArray);
            cout << ", ";

            // State
            returns_State(line, checkerArray);
            cout << " ";

            // Zip
            cout << returns_Zip(line, checkerArray);
            cout << "\"\n\n";
        }
    }
    else
        cout << "Unable to open file";
}


int main()
{
    
    vector<bool> checkerArray(6,false);   
    string input_file_path = "./input/sample_input.in";

    cout<<"This menu is temperory...\nenter 1 for envelope\nenter 2 for fixed\nenter 3 for csv\n";
    int check;
    cin>>check;
    
    if(check==1){
        checkerArray[0] = true;
    }
    else if(check==2){
        checkerArray[1] = true;
    }
    
    if(checkerArray[0])
        envelopeFormat(checkerArray,input_file_path);
    else if(checkerArray[1])
        fixedFormat(checkerArray,input_file_path);
    else
        CSVFormat(checkerArray,input_file_path);

    for(auto i : checkerArray){
        cout<<i<<" ";
    }

    return 0;
}
