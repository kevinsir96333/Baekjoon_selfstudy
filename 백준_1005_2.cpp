#include <iostream>
#include <stack>
#include <queue>


struct Cell {
    int buildNum = 0; 
    int buildingTime = 0;
    int priority = 1; 
    Cell* point = this;
    std::stack<Cell*> tracker;
/*
    ~Cell(){
        int i = tracker.size();
        for(int j = 0; j < i ; j++)
        {
            tracker.pop();
        }
        delete point;
    }
    */
};

struct BFS_G{

    void makeTree(int num, int ruleNum);
    int calTime(int win);

    int total = 0;
    Cell* start = nullptr;
    Cell* end = nullptr;
/*
    ~BFS_G(){
        delete start;
        delete end;
    }*/

};

void BFS_G::makeTree(int num = 0, int ruleNum = 0) {

    total = num;

    for(int i = 0; i < num ; i++)
    {
        if( i == 0)
        {
            start = new Cell;
            start->buildNum = i + 1;
            std::cin >> start->buildingTime;
            end = start;
            continue;
        }
        end->point = new Cell;
        end->point->buildNum = i + 1;
        std::cin >> end->point->buildingTime;
        end = end->point;
    }

    Cell* temp1 = start; 
    Cell* temp2 = start;

    for(int i = 0; i < ruleNum ; i++)
    {
        int pre = 0; 
        int post = 0;

        std::cin >> pre >> post;

        for(int i = 0; i < pre; i++)
        {
            temp1 = temp1->point;
        }

        for(int i = 0; i < post ; i++)
        {
            temp2 = temp2->point;
        }
        temp2->priority += temp1->priority;
        temp2->tracker.push(temp1);
    }
}

int BFS_G::calTime(int win)
{
    int temp_priority = 0;
    int tempBuildT = 0;
    int buildSum = 0; 
    Cell* opr1 = start; 



    for(int i = 0; i < win ; i++)
    {
        opr1 = opr1->point;
    }

    while(!opr1->tracker.empty())
    {
        if(temp_priority != opr1->tracker.top()->priority)
        {
            temp_priority = opr1->tracker.top()->priority;
            tempBuildT = opr1->tracker.top()->buildingTime;
            buildSum += tempBuildT;
            opr1->tracker.pop();
        }
        else
        {
            if(tempBuildT <= opr1->tracker.top()->buildingTime)
            {
                buildSum -=tempBuildT;
                tempBuildT = opr1->tracker.top()->buildingTime;
                buildSum +=tempBuildT;
                opr1->tracker.pop();
            }
            else
            {
                opr1->tracker.pop();
                continue;
            }
        }

    }

    buildSum += opr1->buildingTime;

    return buildSum;

}


int main()
{
    int testCase = 0;
    int buildNum, ruleNum = 0;
    int winning = 0;
    std::cin >> testCase;
    while(0 < testCase)
    {
        BFS_G G;
        std::cin >> buildNum >> ruleNum;
        G.makeTree(buildNum, ruleNum);
        std::cin >> winning;
        int result = G.calTime(winning);

        std::cout << result << std::endl;

        testCase--;
    }
    return 0;
}
