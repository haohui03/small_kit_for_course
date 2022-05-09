#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<iostream>
using namespace std;
enum state{R,C};
#define TIME_MAX 32
class Pcb
{
    public:
        Pcb(char*,Pcb*,double,char);
        void Set_state(char);
        Pcb*& Get_next_pointer();
        void run();
        double Get_run_time();
        void Pcb_print();
        void set_pointer(Pcb*);
    private:
        char process_name[5];
        Pcb * pointer_pcb;
        time_t arrival_time;
        double run_time;
        state current_state;

};
Pcb::Pcb(char* pn,Pcb* p_Pcb=nullptr,double rt=0,char cs='R')
{
    strcpy_s(this->process_name,pn);
    pointer_pcb=p_Pcb;
    time(&arrival_time);
    run_time=rt;
    Set_state(cs);
    
    
}
void Pcb::set_pointer(Pcb* p_Pcb){
    pointer_pcb=p_Pcb;
}
void Pcb::Set_state(char cs)
{
    switch(cs){
    case 'R':
        current_state=R;
        break;
    case 'C':
        current_state=C;
        break;
    }
    
}
Pcb*& Pcb::Get_next_pointer()
{
    return pointer_pcb;
}

void Pcb::run(){
    run_time-=1;
    printf("%s is running\n",process_name);
}
double Pcb::Get_run_time(){
    return run_time;
}
void Pcb::Pcb_print()
{
    struct tm tmTmp;
    char stTmp[TIME_MAX];
    localtime_s(&tmTmp, &arrival_time);
    asctime_s(stTmp, &tmTmp);
    printf("process name:%s,%s",process_name,stTmp);
    printf("run_time:%f\n",run_time);
}
class Pcb_list
{
    public:
    Pcb_list(Pcb*);
    void new_Pcb(Pcb*);
    int run_current();
    void run_all();
    void delete_pcb(Pcb*,Pcb*);
    void point_to_next(Pcb*&);
    private:
    Pcb* head_pointer;
    Pcb* current_pointer;
    Pcb* tail_pointer;
};
Pcb_list::Pcb_list(Pcb* p_Pcb){
    head_pointer=p_Pcb;
    tail_pointer=p_Pcb;
    head_pointer->set_pointer(nullptr);
    tail_pointer->set_pointer(nullptr);
    current_pointer = head_pointer;
}
void Pcb_list::new_Pcb(Pcb* next_pointer){
    tail_pointer->set_pointer(next_pointer);
    tail_pointer=next_pointer;
}
int Pcb_list::run_current()
{
    
    if(current_pointer){
        printf("aaa");
        
        current_pointer->run();
        cout << current_pointer;
        printf("bbb");
        point_to_next(current_pointer);
        return 1;
    }
    else
    return 0;
}
void Pcb_list::point_to_next(Pcb*&cp)
{
    if(cp->Get_next_pointer()==nullptr)
    {
        if (cp == head_pointer)
        {
            delete_pcb(nullptr, head_pointer);
            return;
        }
        while(head_pointer&&head_pointer->Get_run_time()<=0)
            delete_pcb(nullptr,head_pointer);
            cp=head_pointer;
            printf("a loop\n");
            return;
    }
    if (cp->Get_next_pointer()->Get_run_time() <= 0)
    {
        if (cp->Get_next_pointer()->Get_next_pointer() == nullptr)
            tail_pointer = cp;
            delete_pcb(cp,cp->Get_next_pointer());
            point_to_next(cp);}
    else{
        cp=cp->Get_next_pointer();
        return;
    }
}
void Pcb_list::delete_pcb(Pcb*pre,Pcb*back)
{
    if (!pre)
    {

        if (back->Get_next_pointer() != nullptr)
        {
            head_pointer = back->Get_next_pointer();
            
            delete(back);
        }
        else
        {
            
            delete(back);
            back = nullptr;
            current_pointer = nullptr;
           
        }
    }
    else{
        pre->Get_next_pointer()=back->Get_next_pointer();
        delete(back);
    }
}
void Pcb_list::run_all(){
    while(run_current());

}