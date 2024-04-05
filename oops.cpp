#include <iostream>
using namespace std;
class img_member{
    public:
    string name;
    string vertical;
    string branch;
    int year;
    int sub_count;
    void login(){
        cout<<"Enter name "<<endl;
        cin>>name;
        cout<<"Enter vertical "<<endl;
        cin>>vertical;
        cout<<"Enter branch "<<endl;
        cin>>branch;
        cout<<"Enter year "<<endl;
        cin>>year;
    }
    // void get_profile(){
    //     cout<<"Name: "<<name<<endl;
    //     cout<<"Vertical: "<<vertical<<endl;
    //     cout<<"Branch: "<<branch<<endl;
    //     cout<<"Year: "<<year<<endl;
    // }


};
class student : public img_member{
    public:
    int sub_count=0;
    bool ass_sub_status[5];
    bool ass_rev_status[5];
    bool it_status[5];
    student(){
        for (int i = 0; i < 5; i++) {
            ass_sub_status[i] = false;
            ass_rev_status[i]= false;
            it_status[i]=false;
        }
    }
    void submit(int ass_num){
        cout<<"Assignment number "<<ass_num<<endl;
        ass_sub_status[ass_num-1]=true;
        sub_count+=1;
        cout<<"submitted successfully"<<endl;
    }
    void recheck_submit(int ass_num){
        cout<<"Assignment number "<<ass_num<<endl;
        cout<<"re-submitted successfully"<<endl;
        it_status[ass_num-1]=false;
    }
    void sub_status(){
        cout<<"num of assignments submitted "<<sub_count<<endl;
        for(int i=0;i<5;i++){
            if(ass_sub_status[i]){
                cout<<"assignment "<<i+1<<" submission done"<<endl;
            }
            else{
                cout<<"assignment "<<i+1<<" submission NOT done"<<endl;
            }
        }
    }
    void ass_status(int ass_num){
        cout<<"assignment status of assignment number"<<ass_num;
        if(ass_sub_status[ass_num-1]){
            cout<<" STATUS: SUBMITTED under deadline"<<endl;
        }
        else if(!ass_sub_status[ass_num-1]){
            cout<<"STATUS: NOT SUBMITTED"<<endl;
        }
        if(ass_rev_status[ass_num-1]){
            cout<<" STATUS: FINAL REVIEW DONE"<<endl;
        }
        else if(it_status[ass_num-1]){
            cout<<"STATUS: to be iterated"<<endl;
        }
        else if(!it_status[ass_num-1]){
            cout<<"STATUS: SUBMITTED for recheck"<<endl;
        }
    }
    void get_profile(){
        cout<<"Name: "<<name<<endl;
        cout<<"Vertical: "<<vertical<<endl;
        cout<<"Branch: "<<branch<<endl;
        cout<<"Year: "<<year<<endl;
        for(int i=0;i<5;i++){
            ass_status(i+1);
        }
    }
 
};
class reviewer : public img_member {
    public:
    int rev=0;
    
    void review(student &student, int ass_num,bool passed,string feedback=""){
        cout<<"REVIEW of assignment"<<ass_num<<endl;
        if(passed){
            student.ass_rev_status[ass_num-1]=true;
            cout<<"final review done , passed"<<endl;
        }
        else{
            student.it_status[ass_num-1]=true;
            cout<<"please do iteration "<<endl;
            cout<<"feedback "<<feedback<<endl;
        }
    }
    void get_profile(){
        cout<<"Name: "<<name<<endl;
        cout<<"Vertical: "<<vertical<<endl;
        cout<<"Branch: "<<branch<<endl;
        cout<<"Year: "<<year<<endl;
    }
};

int main(){
    student stu1;
    // stu1.login();
    stu1.submit(1);
    stu1.submit(2);
    stu1.submit(4);
    reviewer rev1;
    rev1.review(stu1,1,false,"div missing");
    rev1.review(stu1,2,false,"nav missing");
    rev1.review(stu1,4,true,"final done");
    stu1.recheck_submit(1);
    stu1.ass_status(1);
    stu1.ass_status(2);
    stu1.ass_status(3);
    stu1.ass_status(4);
}