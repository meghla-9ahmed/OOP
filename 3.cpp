#include <bits/stdc++.h>
using namespace std;

class Person
{
private:
    string name;
    string DOB;
public:
    Person() {}
    Person(string name) { this->name = name; }
    Person(string name,string DOB)
    {
        this->name = name;
        this->DOB = DOB;
    }
    setName(string name) { this->name = name; }
    string getName() { return name; }
    string getDOB() { return DOB;}
};
class Teacher:public Person
{
public:
    Teacher() {}
    Teacher(string name):Person(name) {}
};

class Student : public Person
{
private:
    int idNo;
public:
    Student() {}
    Student(string name) : Person(name) {}
    Student(string name, int idNo) : Person(name) { this->idNo = idNo; }
    int getIdNo() {return idNo;}
    setId(int idNo) { this->idNo = idNo; }
};
class SocietyMember:public Student
{
private:
    int points = 0;
public:
    SocietyMember() {}
    SocietyMember(string name):Student(name) {}
    SocietyMember(string name,int idNo):Student(name,idNo) {}
    void operator+(int n) { points+=n;}
    int getPoints(){ return points; }
    int setPoints(int n){ points+=n; }
};
class CSEdepartment
{
public:
    vector<string> randSelect (SocietyMember* societyMember)
    {
        vector<string>name;
        vector<int> n = randNumGen(1, 10, 1);
       for(int i=0; i<5; i++)
        {
            societyMember+=(n[i]);
            name.push_back(societyMember->getName());
            societyMember-=(n[i]);
        }
        return name;
    }

    vector<int> randNumGen(int lower, int upper,int count)
    {
        vector<int> myVector;
        srand((unsigned)time(NULL));

        while(myVector.size() < 5)
        {
            int b = rand() % 10;
            if ( !(find(myVector.begin(), myVector.end(), b) != myVector.end()))
            {
                myVector.push_back(b);
            }
        }
        return myVector;
    }

    void survey(SocietyMember* societyMember)
    {
        string name, isFinished;
        int n,id;
        Student student;
        printf("Students will give their points. Then Teachers will give their points\n");
        while(true)
        {
            printf("Enter your name: ");
            cin>>name;
            student.setName(name);
            printf("Enter your ID: ");
            cin>>id;
            student.setId(id);

            cout<<"\nHello, "<<student.getName()<<endl;
            for(int i=0; i<5; i++,societyMember++)
            {
                cout<<"Give your point to "<<societyMember->getName()<<" (between 1 to 5): ";
                cin>>n;
                while(n<1 or n>5)
                {
                    printf("Invalid point.\nGive points between 1 to 5: ");
                    cin>>n;
                }
                cout<<n<<endl;

                societyMember->setPoints(n);
                cout<<"You have given "<<societyMember->getPoints()<<" points to "<<societyMember->getName()<<endl<<endl;
            }
            societyMember -=5;
            cout<<"\n\n"<<student.getName()<<", You've successfully completed survey"<<endl;
            cout<<"---------------------------------------------"<<endl<<endl;

            cout<<"If all the students have finished with their markings, type 's' and\nThen Teachers will give their points"<<endl;
            cout<<"Or type 'e' to continue (as a student)"<<endl;
            cin>>isFinished;
            if(isFinished == "e") cout<<"Now next student will give point."<<endl;
            else break;
        }

        Teacher teacher;
        cout<<"---------------------------------------------\n\n\nNow Teachers will give their points"<<endl;
        while(true)
        {
            printf("\nEnter your name: ");
            cin>>name;
            teacher.setName(name);

            cout<<"\nHello, dear "<<teacher.getName()<<" sir"<<endl;
            for(int i=0; i<5; i++,societyMember++)
            {
                cout<<"Give your points to "<<societyMember->getName()<<" (between 1 to 5): ";
                cin>>n;
                while(n<1 or n>5)
                {
                    cout<<"Invalid point. Please give points between 1 to 5: ";
                    cin>>n;
                }
                cout<<n<<endl;
                societyMember->setPoints(n);
                cout<<"You have given "<<societyMember->getPoints()<<" points to "<<societyMember->getName()<<endl<<endl;
            }
            societyMember -=5;
            cout<<"\n\nWell done, "<<student.getName() <<" sir"<<endl;
            cout<<"You're survey is completed"<<endl;
            cout<<"-------------------------------------------"<<endl<<endl;

            cout<<"If all Teachers have finished with their markings, Then please type 'e' "<<endl;
            cout<<"Otherwise type 'c' to continue"<<endl;
            cin>>isFinished;
            if(isFinished == "e")
                break;
            else continue;
        }

    }

    void showResult(SocietyMember* societyMember)
    {
        printf("\n\n--------------------------------------------\nHere is the result.\nName\t\t\tPoints\n");
        int max =-1,index = -1;
        for(int i=0; i<5; i++,societyMember++)
        {
            cout<<societyMember->getName()<<"\t\t\t"<<societyMember->getPoints()<<endl;
            if(max < societyMember->getPoints())
            {
                index = i;
                max = societyMember->getPoints();
            }
        }
        societyMember -=5;
        cout<<"--------------------------------------------"<<endl;
        if(max !=-1) societyMember += index;
        cout<<"\n\nThe best CSE Society Member is "<<societyMember->getName()<<endl;
    }

    void showMembers(SocietyMember* societyMember,int n)
    {
        for(int i = 0;i<n;i++)
        {
            cout<<"     "<<societyMember->getName()<<endl;
            societyMember++;
        }
    }
};

int main()
{
    SocietyMember allSocietyMember[10]={
        SocietyMember("jenny",11508023),  SocietyMember("meghla",11508019), SocietyMember("tonni",13508010),
        SocietyMember("farjana",11508035),  SocietyMember("nisha",11508038),  SocietyMember("evana",11508060),
        SocietyMember("fomey",13508035),   SocietyMember("mohib",11508021), SocietyMember("zubayer",11508020),
        SocietyMember("sumon",11508018)};

    CSEdepartment cseDepartment;
    printf("list of all society members:\n----------------------------\n");
    cseDepartment.showMembers(allSocietyMember,10);
    printf("----------------------------\n");
    vector<string> selectedStudentsWhoWillBeVoted = cseDepartment.randSelect(allSocietyMember);
    printf("\n\nFive Randomly selected student who will be voted:\n-------------------------------------------------\n");
    SocietyMember selectedMember[5];
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(allSocietyMember[j].getName() == selectedStudentsWhoWillBeVoted[i]){
                selectedMember[i] = allSocietyMember[j];
            }
        }
    }

    cseDepartment.showMembers(selectedMember,5);
    printf("-------------------------------------------------\n");
    printf("\n\n");
    cseDepartment.survey(selectedMember);
    cseDepartment.showResult(selectedMember);
    return 0;
}
