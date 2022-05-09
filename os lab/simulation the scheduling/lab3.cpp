#include<iostream>
#include"pcb.h"
using namespace std;
// difftime(t1,t2)
int main()
{
    Pcb* pcb1=new Pcb("p1",nullptr,6,'R');
    Pcb* pcb2=new Pcb("p2",nullptr,3,'R');
    Pcb* pcb3=new Pcb("p3",nullptr,8,'R');
    Pcb* pcb4=new Pcb("p4",nullptr,2,'R');
    Pcb* pcb5=new Pcb("p5",nullptr,10,'R');
    Pcb_list* l_pcb=new Pcb_list(pcb1);
    l_pcb->new_Pcb(pcb2);
    l_pcb->new_Pcb(pcb3);
    l_pcb->new_Pcb(pcb4);
    l_pcb->new_Pcb(pcb5);
    l_pcb->run_all();
}