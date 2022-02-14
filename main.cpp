#include <iostream>
#include <vector>
#include <map>
using namespace std;

//question 1
int fibonacci(int position){
    if (position ==0)return 0;
    if (position ==1)return 1;
    int res[position+1];
    res[0]=0;
    res[1]=1;
    for(int i = 2;i<=position;i++){
        res[i]=res[i-1]+res[i-2];
    }
    return res[position];
}
//question 2

class StackList;
class StackNode{
private:
    int val;
    StackNode *next;
public:
    StackNode():val(0){
        next = 0;
    }
    StackNode(int x):val(x){
        next = 0;
    }
    StackNode(int x,StackNode *nextNode):val(x),next(nextNode){};
    friend class StackList;
};
class StackList{
private:
    StackNode *top;
    int size ;
public:
    StackList():top(0),size(0){};
    bool IsEmpty();
    int Size();
    int Top();
    void Push(int x);
    void Pop();
};
void StackList::Push(int x){
    if (IsEmpty()){
        top = new StackNode(x);
        size++;
        return;
    }
    StackNode *newObj = new StackNode(x);
    newObj->next = top;
    top = newObj;
    size++;
}
void StackList::Pop(){
    if (IsEmpty()){
        return;
    }
    StackNode *deleteNode = top;
    top = top->next;
    delete deleteNode;
    deleteNode = 0;
    size--;
}
int StackList::Top(){
    if (IsEmpty()){
        return -1;
    }
    return top->val;
}
bool StackList::IsEmpty(){
    bool ans = false;
    if (size==0) ans = true;
    return ans;
}
int StackList::Size(){
    return size;
}
//question 3
class Order{
public:
    string Id;
    pair<string,float> Data;
};
class OrderDetail{
private:
    string Name;
    float Price;
};
class User{
public:
    string Id;
    string Name;
    vector<Order> Order;
    string Print();
};

string Print(vector<string> userIds,
vector<pair<string,string>>userData,
vector <string> orderIds,
vector<pair<string,pair<string,float>>> orderDatas,
vector<vector<pair<string,vector<string>>>> userOrders){
    map<string,string> user;
    for(auto v : userIds){
        for(auto d : userData){
            if (v==d.first){
                user[v]=d.second;
                break;
            }
        }
    }
    map<string,pair<string,float>>order;
    for(auto v : orderIds){
        for(auto d : orderDatas){
            if (v == d.first){
                order[v]=d.second;
            }
        }
    }
    for(int i = 0;i<userOrders.size();i++){
        for(int j = 0;j<userOrders[i].size();j++){
            cout<<userOrders[i][j].first<<endl;
            if (userOrders[i][j].first=="userId"){
                auto pos = user.find(userOrders[i][j].second[0]);
                cout<<pos->second<<endl;
            }else if(userOrders[i][j].first=="orderIds"){
                for(auto o : userOrders[i][j].second){
                    auto pos = order.find(o);
                    cout<< pos->second <<endl;
                }
            }
        }
    }
    /*vector<Order> orders;
    for(int i = 0;i<orderIds.size();i++){
        Order *order = new Order();
        order->Id = orderIds[i];
        for(int j =0;j<orderDatas.size();j++){
            if(orderDatas[j].first==orderIds[i]){
                order->Data = orderDatas[i].second;
            }
        }
    }
    vector<User> users;
    for(int i = 0;i<userIds.size();i++){
        User *user = new User();
        user->Id = userIds[i];
        for(int j = 0;j<userData.size();j++){
            if (userData[j].first==userIds[i]){
                user->Name = userData[i].second;
                for(int k = 0;k<userOrders.size();k++){
                    if(userOrders[k][0].first==userIds[i]){
                        for(int l = 0;k<userOrders[k][0].second.size();l++){
                            for(int m = 0; m<orders.size();m++){
                                if(userOrders[k][0].second[l]==orders[m].Id){
                                    user->Order.push_back(orders[m]);
                                }
                            }
                        }
                    }
                }
                break;
            }
        }
    }*/
}