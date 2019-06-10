#include "Queue/LinkQueue.h"

int main(){
    LinkQueue<int> linkQueue;
    for (int i = 0; i < 5; ++i) {
        linkQueue.EnLinkQueue(i+1);
    }
    linkQueue.Print();
    for (int j = 0; j < 2; ++j) {
        int deValue;
        linkQueue.DeLinkQueue(deValue);
        std::cout<<"DeValue: "<<deValue<<std::endl;
    }
    linkQueue.Print();
    int frontValue;
    linkQueue.GetHead(frontValue);
    std::cout<<"Front Value: "<<frontValue<<std::endl;
}
