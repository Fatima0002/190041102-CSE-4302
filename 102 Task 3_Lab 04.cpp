#include<bits/stdc++.h>
#include<string.h>
using namespace std;

class StudentResult
{

private:
    static int passingMark;
    int subjectMark[10];
    bool fail;

public:
    static int displayPassMark()
    {
        cout<<"Required pass mark for every course is: "<<passingMark<<endl;
    }
    void displayMarks()
    {
        for(int i=0; i<10; i++)
        {
            cout<<subjectMark[i]<<endl;
        }
    }
    void setMarks(int a,int b,int c,int d,int e,int f,int g, int h, int i, int j)
    {
        subjectMark[0]=a;
        subjectMark[1]=b;
        subjectMark[2]=c;
        subjectMark[3]=d;
        subjectMark[4]=e;
        subjectMark[5]=f;
        subjectMark[6]=g;
        subjectMark[7]=h;
        subjectMark[8]=i;
        subjectMark[9]=j;
    }
    void checkPassing()
    {
        for(int i=0; i<10; i++)
        {
            if(subjectMark[i]<passingMark)
            {
                fail=true;
            }
        }
        if(!fail)
        {
            cout<<"The student successfully PASSED the semester"<<endl;
        }
        else
        {
            cout<<"The student has failed in this semester"<<endl;
        }
    }
};

int StudentResult::passingMark = 60;

int main()
{
    StudentResult s1,s2,s3;

    s1.setMarks(80,53,79,91,35,19,60,45,84,25);
    s1.displayMarks();
    s1.displayPassMark();
    s1.checkPassing();

    s2.setMarks(92,88,86,90,82,89,86,85,98,93);
    s2.displayMarks();
    s2.displayPassMark();
    s2.checkPassing();

    s3.setMarks(50,64,27,89,96,98,250,65,78,96);
    s3.displayMarks();
    s3.displayPassMark();
    s3.checkPassing();

    return 0;
}
