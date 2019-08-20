#include <iostream>
//#include <conio.h>
#include <cstdlib>
#include <fstream>
#include <vector>

using namespace std;

struct Person
{
    string name;
    string surname;
    string age;
    string telephone;
};
short peopleInDataBase;
Person people[20];

//void requireEnter();

void addPerson();
void showPeople();
void savePeopleToFile();
void loadPeopleFromFile();
void searchDatabase();
void removePersonFromDatabase();

int main()
{
    char test;
    loadPeopleFromFile();

    do
    {
        cout << "Number of People in Database: " << peopleInDataBase << endl;
        cout << "MENU: " << endl;

        cout << "1. Add Person" << endl;
        cout << "2. Show All People" << endl;
        cout << "3. Save People to File" << endl;
        cout << "4. Load People from File" << endl;
        cout << "5. Search for a Person" << endl;
        cout << "6. Remove Person from DataBase" << endl;

        cout << endl;

        test = cin.get();

        switch(test)
        {
            case '1':
                addPerson();
                break;
            case '2':
                showPeople();
                break;
            case '3':
                savePeopleToFile();
                break;
            case '4':
                loadPeopleFromFile();
                break;
            case '5':
                searchDatabase();
                break;
            case '6':
                removePersonFromDatabase();
                break;
        }


    }while(test != 27);


    return 0;
}
/*void requireEnter()
{
    cout << "Click Enter to continue... " << endl;
    while(getch() != 13);
}*/
void addPerson()
{
    cout << "Type name: ";
    cin >> people[peopleInDataBase].name;

    cout << "Type surname: ";
    cin >> people[peopleInDataBase].surname;

    cout << "Type age: ";
    cin >> people[peopleInDataBase].age;

    cout << "Type telephone: ";
    cin >> people[peopleInDataBase].telephone;

    peopleInDataBase++;
}
void showPeople()
{
    if(peopleInDataBase > 0)
    {
        for (int i = 0; i < peopleInDataBase; i++)
        {
            cout << "Person index: " << (i+1) << endl;
            cout << "Name: " << people[i].name << endl;
            cout << "Surname: " << people[i].surname << endl;
            cout << "Age: " << people[i].age << endl;
            cout << "Telephone: " << people[i].telephone << endl << endl;
        }
    }
    else
        cout << "There is nobody in database."  << endl;
}
void savePeopleToFile()
{
    ofstream file("database.txt");

    if (file.is_open())
    {
        file << peopleInDataBase;

        for (int i = 0; i < peopleInDataBase; i++)
        {
            file << ","<< people[i].name;
            file <<","<< people[i].surname;
            file <<","<< people[i].age ;
            file <<","<< people[i].telephone;
        }

        file.close();
    }
    else
        cout << "I couldnt save to database" << endl;

}
void loadPeopleFromFile()
{
  vector<string> words;
  string word;
  ifstream file("database.txt");
  file >> peopleInDataBase;
  cout << peopleInDataBase << endl;
  if (peopleInDataBase > 0)
  {
          while(getline(file,word,',')){
               words.push_back(word);
          }

      vector<string>::iterator it;
      int i  = 0;
      int j = 1;
      for (it = words.begin(); it != words.end(); it++) {
         string word = *it;
        // cout << i << " "<<j << " " << word << endl;
         if(j > 5) {
             j = 2;
             i++;
          }
         //cout << j << endl;
         if (j == 2) {
             people[i].name = word;

           }
         else if(j == 3) {
             people[i].surname = word;
           }
         else if(j == 4) {
             people[i].age = word;
           }
           if (j == 5){
             people[i].telephone = word;
           }
          j = j + 1;
}
}
}
void searchDatabase()
{
    if (peopleInDataBase > 0)
    {
        string name;
        cout << "Type a name of person you want to look for: ";
        cin >> name;

        for (int i = 0; i < peopleInDataBase; i++)
        {
            if (name == people[i].name)
            {
                cout << "Person index: " << (i+1) << endl;
                cout << "Name: " << people[i].name << endl;
                cout << "Surname: " << people[i].surname << endl;
                cout << "Age: " << people[i].age << endl;
                cout << "Telephone: " << people[i].telephone << endl << endl;
            }
        }
    }
    else
        cout << "There is nobody in database what do you want to look for?" << endl;


}
void removePersonFromDatabase()
{
    if (peopleInDataBase > 0)
    {
        short index;
        cout << "Who do you want to remove? Type index: " << endl;
        cin >> index;

        if (peopleInDataBase >= index)
        {
            for (short k = index; k < peopleInDataBase; k++)
            {
                people[k-1].name = people[k].name;
                people[k-1].surname = people[k].surname;
                people[k-1].age = people[k].age;
                people[k-1].telephone = people[k].telephone;
            }

            peopleInDataBase--;
            savePeopleToFile();
        }
        else
            cout << "There is nobody like that" << endl;
    }
    else
        cout << "There is nothing to remove" << endl;
}
